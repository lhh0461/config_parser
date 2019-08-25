#include <string>
#include <vector>
#include <regex>

std::string& Strim(std::string &s, const std::string & del)
{
    if (s.empty()) 
    {
        return s;
    }

    s.erase(0,s.find_first_not_of(del));
    s.erase(s.find_last_not_of(del) + 1);
    return s;
}

std::vector<std::string> Split(const std::string & input, const std::string& regex)
{
    // passing -1 as the submatch index parameter performs splitting
    std::regex re(regex);
    std::sregex_token_iterator
        first{input.begin(), input.end(), re, -1},
        last;
    return {first, last};
}

