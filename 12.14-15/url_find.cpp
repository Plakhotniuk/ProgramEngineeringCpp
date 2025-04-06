/*
12.16 [25]
Напишите программу, которая принимает на вход строку с URL и извлекает из него отдельные компоненты,
такие как протокол, домен, порт и путь. Используйте группы в круглых скобках внутри регулярного выражения
*/

#include <cassert>
#include <iostream>
#include "regex_find.hpp"

using namespace std::literals;


int main() {
    std::string url = "https://example.com:8080/path/to/resource";
    
    std::regex url_regex(
        R"((https?)://([^:/?#]+)(?::(\d+))?([^?#]*))"
    );
    
    std::smatch matches;
    if (std::regex_match(url, matches, url_regex)) {
        std::cout << "Протокол: " << matches[1] << "\n"
                  << "Домен: " << matches[2] << "\n"
                  << "Порт: " << matches[3] << "\n"
                  << "Путь: " << matches[4] << "\n";
    }
    
    assert(matches[1] == "https");
    assert(matches[2] == "example.com");
    assert(matches[3] == "8080");
    assert(matches[4] == "/path/to/resource");
}