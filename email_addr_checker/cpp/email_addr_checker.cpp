// regex_match example
#include <iostream>
#include <string>
#include <regex>

static int testsPassed = 0;
static int testsFailed = 0;

void printTestResultSummary()
{
    std::cout << testsPassed << " Tests Passed. " <<
        testsFailed << " Tests Failed." << std::endl;
}

bool is_email_addr_valid(const std::string& addr)
{
    const std::string email_regex =
      "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$";

    return std::regex_match(addr, std::regex(email_regex));
}

void testEmailAddr(const std::string& addr, bool expected)
{
    if(is_email_addr_valid(addr) != expected)
    {
        std::cout << "Fail: " << addr << std::endl;
        testsFailed++;
    }
    else
    {
        testsPassed++;
    }
}

int main ()
{
    testEmailAddr("user@example.com", true);
    testEmailAddr("sample.user@example.com", true);
    testEmailAddr("sample_user@example.com", true);
    testEmailAddr("user@sub.example.com", true);
    testEmailAddr("userexample.com", false);
    testEmailAddr("sample user@example.com", false);
    testEmailAddr("user@an_example.com", false);

    printTestResultSummary();

    return 0;
}

