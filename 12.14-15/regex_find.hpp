#pragma once
#include <algorithm>
#include <iterator>
#include <regex>
#include <string>
#include <vector>

inline std::vector < std::string > findAllRegexPatterns(const std::regex pattern, std::string input_string) {
    auto begin = std::cbegin(input_string);

    std::vector < std::string > result;

    auto lambda = [&result](const auto & matches){ result.push_back(matches[0]); };

//  ---------------------------------------------------------------------------------

    std::ranges::for_each
    (
        std::sregex_iterator(begin, std::cend(input_string), pattern), 

        std::sregex_iterator(), lambda
    );

    return result;
}