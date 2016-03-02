#!/usr/bin/python

import re
import unittest

def isEmailAddrValid(addr):
    email_regex = "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$"
    return re.match(email_regex, addr) is not None

class TestEmailAddrChecker(unittest.TestCase):

    def test_simple_addr(self):
        self.assertTrue(isEmailAddrValid("user@example.com"))

    def test_uppercase(self):
        self.assertTrue(isEmailAddrValid("USER@EXAMPLE.COM"))

    def test_subdomains(self):
        self.assertTrue(isEmailAddrValid("user@sub.example.com"))

    def test_dots_in_username(self):
        self.assertTrue(isEmailAddrValid("some.user@example.com"))

    def test_underscores_in_username(self):
        self.assertTrue(isEmailAddrValid("some_user@example.com"))

    def test_space_in_username(self):
        self.assertFalse(isEmailAddrValid("some user@example.com"))

    def test_dash_in_username(self):
        self.assertTrue(isEmailAddrValid("some-user@example.com"))

    def test_underscores_in_domain(self):
        self.assertFalse(isEmailAddrValid("user@some_example.com"))

    def test_space_in_domain(self):
        self.assertFalse(isEmailAddrValid("user@some example.com"))

    def test_dash_in_domain(self):
        self.assertTrue(isEmailAddrValid("user@some-example.com"))

if __name__ == "__main__":
    unittest.main()

