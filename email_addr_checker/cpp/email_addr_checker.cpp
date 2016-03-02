// regex_match example
#include <iostream>
#include <string>
#include <regex>


bool is_email_addr_valid(const std::string& addr)
{
    const std::string email_regex =
      "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$";

    return std::regex_match(addr, std::regex(email_regex));
}

int main ()
{
    const std::string testStr = "user@example.com";

    if(is_email_addr_valid(testStr))
    {
        std::cout << testStr << " is valid" << std::endl;
    }
    else
    {
        std::cout << testStr << " is not valid" << std::endl;
    }

    return 0;
}

