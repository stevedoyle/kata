#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>

static int testsPassed = 0;
static int testsFailed = 0;

void assertTrue(bool actual)
{
    actual ? testsPassed++ : testsFailed++;
}

void assertFalse(bool actual)
{
    (!actual) ? testsPassed++ : testsFailed++;
}

void printTestResultSummary()
{
    std::cout << testsPassed << " Tests Passed. " <<
        testsFailed << " Tests Failed." << std::endl;
}

class IncrementingSequence
{
public:
    // Constructor
    IncrementingSequence(): i_(0) {}
    // Return an incrementing counter
    int operator() () { return i_++; }
private:
    int i_;
};


// Binary search using a recursive algorithm.
bool
binary_search_recursive(const std::vector<int>::const_iterator begin,
                 const std::vector<int>::const_iterator end,
                 int target)
{
    if(begin == end)
        return false;
    
    std::vector<int>::const_iterator mid = begin + std::distance(begin, end)/2;
    if(*mid == target) {
        return true;
    } else if(target < *mid) {
        return binary_search_recursive(begin, mid, target);
    } else {
        return binary_search_recursive(mid, end, target);
    }
    
    return false;
}


// Binary search using an iterative algorithm.
bool
binary_search_iterative(const std::vector<int>::const_iterator begin,
                        const std::vector<int>::const_iterator end,
                        int target)
{
    std::vector<int>::const_iterator sub_range_begin = begin;
    std::vector<int>::const_iterator sub_range_end = end;
    
    while(sub_range_begin != sub_range_end)
    {
        std::vector<int>::const_iterator mid = sub_range_begin +
        std::distance(sub_range_begin, sub_range_end)/2;
        
        if(*mid == target) {
            return true;
        } else if(target < *mid) {
            sub_range_end = mid;
        } else {
            sub_range_begin = mid;
        }
    }
    
    return false;
}

class BinarySearchAlgo
{
public:
    virtual bool search(std::vector<int>::const_iterator begin,
                        std::vector<int>::const_iterator end,
                        int val) const = 0;
};

class STLBinarySearchAlgo : public BinarySearchAlgo
{
public:
    virtual bool search(std::vector<int>::const_iterator begin,
                        std::vector<int>::const_iterator end,
                        int val) const
    {
        return std::binary_search(begin, end, val);
    }
};

class RecursiveBinarySearchAlgo : public BinarySearchAlgo
{
public:
    virtual bool search(std::vector<int>::const_iterator begin,
                        std::vector<int>::const_iterator end,
                        int val) const
    {
        return binary_search_recursive(begin, end, val);
    }
};

class IterativeBinarySearchAlgo : public BinarySearchAlgo
{
public:
    virtual bool search(std::vector<int>::const_iterator begin,
                        std::vector<int>::const_iterator end,
                        int val) const
    {
        return binary_search_iterative(begin, end, val);
    }
};

void testBinarySearchAlgo(const std::vector<int>& data, const BinarySearchAlgo& algo)
{
    assertTrue(algo.search(data.begin(), data.end(), 25));
    assertFalse(algo.search(data.begin(), data.end(), -1));
}

int main()
{
    const int data_size = 100;
    
    // Fill a vector with some values
    std::vector<int> data(data_size);
    std::generate(data.begin(), data.end(), IncrementingSequence());
    
    // Search for values in each algorithm implementation
    assertTrue(std::binary_search(data.begin(), data.end(), 25));
    assertFalse(std::binary_search(data.begin(), data.end(), -1));
    
    assertTrue(binary_search_recursive(data.begin(), data.end(), 25));
    assertFalse(binary_search_recursive(data.begin(), data.end(), -1));

    assertTrue(binary_search_iterative(data.begin(), data.end(), 25));
    assertFalse(binary_search_iterative(data.begin(), data.end(), -1));
    
    // Using the strategy pattern
    STLBinarySearchAlgo stlAlgo;
    testBinarySearchAlgo(data, stlAlgo);

    RecursiveBinarySearchAlgo recAlgo;
    testBinarySearchAlgo(data, recAlgo);
    
    IterativeBinarySearchAlgo iterAlgo;
    testBinarySearchAlgo(data, iterAlgo);
    
    printTestResultSummary();
    
    return 0;
}

