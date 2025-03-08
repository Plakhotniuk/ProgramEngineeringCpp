#pragma once
#include <string>
#include <random>
#include <vector>
#include <set>

namespace generators {

    
std::string generateRandomString(size_t length) 
{

    const std::string charset = "abcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, charset.size() - 1);

    // Generate the random string
    std::string random_string;
    random_string.reserve(length);
    for (size_t i = 0; i < length; ++i) {
        random_string += charset[dis(gen)];
    }

    return random_string;
}

std::vector<std::string> genUniqueStrVec(size_t str_len, size_t str_count) 
{
    std::set<std::string> result;

    for (size_t i = 0; i < str_count; ++i) 
    {
        result.insert(generateRandomString(str_len));
    }

    return {result.begin(), result.end()};
}

} // namespace generators
