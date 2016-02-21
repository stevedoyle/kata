#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>

// Binary search using custom algorithm.

bool
binary_search_v1(const std::vector<int>::iterator begin,
    const std::vector<int>::iterator end,
    int target)
{
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
  bool found = binary_search_v1(data.begin(), data.end(), val);

  std::cout << val << (found ? " " : " not ") << "found" << std::endl;

  return 0;
}

