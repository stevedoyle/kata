#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

// Binary search using STL algorithms.

int main()
{
  const int data_size = 100;

  // Fill a vector with some random values
  vector<int> data(data_size);
  generate(data.begin(), data.end(), rand);

  // Remember the last element in the data set.
  // This will be the target value to search for.
  int val = data.back();

  // Sort the vector
  sort(data.begin(), data.end());

  // Search for the target value
  bool found = binary_search(data.begin(), data.end(), val);

  cout << val << (found ? " " : " not ") << "found" << endl;

  return 0;
}

