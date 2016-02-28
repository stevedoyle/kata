#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>

// Binary search using custom algorithm.

bool
binary_search_recursive(const std::vector<int>::iterator begin,
                 const std::vector<int>::iterator end,
                 int target)
{
    if(begin == end)
        return false;
    
    // A recursive algorithm
    std::vector<int>::iterator mid = begin + std::distance(begin, end)/2;
    if(*mid == target) {
        return true;
    } else if(target < *mid) {
        return binary_search_recursive(begin, mid, target);
    } else {
        return binary_search_recursive(mid, end, target);
    }
    
    return false;
}

int main()
{
    const int data_size = 100;
    
    // Fill a vector with some random values
    std::vector<int> data(data_size);
    std::generate(data.begin(), data.end(), std::rand);
    
    // Remember the last element in the data set.
    // This will be the target value to search for.
    int val = data.back();
    
    // Sort the vector
    std::sort(data.begin(), data.end());
    
    // Search for the target value
    bool found = binary_search_recursive(data.begin(), data.end(), val);
    
    std::cout << val << (found ? " " : " not ") << "found" << std::endl;
    
    return 0;
}
