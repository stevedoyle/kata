#!/usr/bin/python

import unittest

def bin_search_recursive(data, val):

    if len(data) == 0: return False

    mid = len(data)/2
    if data[mid] == val:
        return True

    if data[mid] > val:
        return bin_search_recursive(data[:mid], val)

    return bin_search_recursive(data[mid+1:-1], val)

def bin_search_iterative(data, val):
    low = 0
    high = len(data)-1

    while low < high:
        mid = (low + high)/2
        if data[mid] < val:
            low = mid + 1
        else:
            high = mid

    return data[low] == val

class TestBinSearchAlgos(unittest.TestCase):

    def setUp(self):
        self.data = range(100)

    def test_recursive_found(self):
        self.assertTrue(bin_search_recursive(self.data, 25))

    def test_recursive_not_found(self):
        self.assertFalse(bin_search_recursive(self.data, -1))

    def test_iterative_found(self):
        self.assertTrue(bin_search_iterative(self.data, 25))

    def test_iterative_not_found(self):
        self.assertFalse(bin_search_iterative(self.data, -1))

if __name__ == "__main__":
    unittest.main()

