#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>

// Binary search using an iterative algorithm.
bool
binary_search_iterative(const std::vector<int>::iterator begin,
                 const std::vector<int>::iterator end,
                 int target)
{
    std::vector<int>::iterator sub_range_begin = begin;
    std::vector<int>::iterator sub_range_end = end;
    
    while(sub_range_begin != sub_range_end)
    {
        std::vector<int>::iterator mid = sub_range_begin +
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
    bool found = binary_search_iterative(data.begin(), data.end(), val);
    
    std::cout << val << (found ? " " : " not ") << "found" << std::endl;
    
    return 0;
}

