import simpy
import matplotlib.pyplot as plt

def show_trace(trace):
    fig, ax = plt.subplots()
    colors=['blue', 'red', 'green', 'yellow']
    yoffset = 1
    for key, values in trace.items():
        ax.broken_barh(values, (yoffset * 5, 4), 
                facecolors=colors[(yoffset-1) % len(colors)])
        yoffset += 1

    num_bars = len(trace)
    ax.set_xlabel('clock cycles')
    ax.set_yticks([(x*5)+7 for x in range(num_bars)])
    ax.set_yticklabels(trace.keys())
    ax.grid(True)

    plt.show()

trace = { 'parking' : [],
        'driving' : [],
        'waiting' : [] }

def car(env):
    while True:
        parking_duration = 5
        trace['parking'].append((env.now, parking_duration))
        yield env.timeout(parking_duration)

        trip_duration = 2
        trace['driving'].append((env.now, trip_duration))
        yield env.timeout(trip_duration)

        wait_duration = 1
        trace['waiting'].append((env.now, wait_duration))
        yield env.timeout(trip_duration)

env = simpy.Environment()
env.process(car(env))
env.run(until=250)

show_trace(trace)

