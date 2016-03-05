import simpy
import matplotlib.pyplot as plt

def color_for_name(name):
    if name.startswith('T'): return 'blue'
    if name.startswith('cpu'): return 'silver'
    if name.startswith('coproc'): return 'green'
    return 'red'

def show_trace(trace):
    fig, ax = plt.subplots()
    yoffset = 1
    for key in sorted(trace.keys(), reverse=True):
        color = color_for_name(key)
        ax.broken_barh(trace[key], (yoffset * 5, 4), facecolors=color)
        yoffset += 1

    num_bars = len(trace)
    ax.set_xlabel('clock cycles')
    ax.set_yticks([(x*5)+7 for x in range(num_bars)])
    ax.set_yticklabels(sorted(trace.keys(), reverse=True))
    ax.grid(True)

    plt.show()

trace = {}

def cpu_thread(env, name, cpu, coproc, profile):
    for work in profile:
        if work[0] == 'c':
            compute = work[1]
            with cpu.request() as req:
                yield req
                trace[name].append((env.now, compute))
                trace['cpu'].append((env.now, compute))
                yield env.timeout(compute)
        elif work[0] == 's':
            compute = work[1]
            with coproc.request() as req:
                yield req
                trace['coproc'].append((env.now, compute))
                yield env.timeout(compute)
        elif work[0] == 'i':
            iotime = work[1]
            trace['io'].append((env.now, compute))
            yield env.timeout(iotime)

env = simpy.Environment()
cpu = simpy.Resource(env, capacity=1)
coproc = simpy.Resource(env, capacity=1)

trace['cpu'] = []
trace['coproc'] = []
trace['io'] = []

for thread_num in range(8):
    name = "T%d" % thread_num
    trace[name] = []
    env.process(cpu_thread(env, name, cpu, coproc,
        [('c',20), ('i',15), ('c',32), ('s',45), ('c',18)]))

env.run(until=800)

show_trace(trace)

