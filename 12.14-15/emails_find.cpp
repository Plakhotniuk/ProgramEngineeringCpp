/* 
12.15 [25]
Напишите программу, которая принимает на вход текст и извлекает из него все адреса электронных почт.
Допускается использовать публичные регулярные выражения из интернета, но, желательно, некоторые упро-
щенные варианты, чтобы не получилось спагетти-кода и чтобы Вы понимали все составляющие их компоненты
и логику. Текст подготовьте самостоятельно и внедрите его в исходный код с помощью сырых строк. В тексте
должны присутствовать как корректные, так и некорректные адреса электроных почт, а также мусорный текст
*/

#include <cassert>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "regex_find.hpp"

using namespace std::literals;

std::string readFileToString(const std::string& filePath) {
    std::ifstream file(filePath); // Open file
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filePath << "'" << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // Read entire file into buffer
    return buffer.str();    // Return as string
}

int main() {
    std::string filePath = "data/input.txt"; 
    auto input_string = readFileToString(filePath);

    std::regex email_pattern(
        R"([a-zA-Z0-9._%+-]+)"                // Локальная часть (без ограничений)
        R"(@)"                                // разделитель
        R"((?!.*\.\.)(?!.*-\.)(?!.*\.-))"     // Исключение запрещенных паттернов вначале (нет последовательных точек, без дефиса перед точкой и наоборот)
        R"([a-zA-Z0-9-]+(\.[a-zA-Z0-9-]+)*)"  // домен + запрет на запрещенные паттерны в конце (Никаких начальных / завершающих точек / дефисов)
        R"(\.[a-zA-Z]{2,})"                   // точка + более 2х букв
    );

    std::vector < std::string > result = findAllRegexPatterns(email_pattern, input_string);

    assert(
        result == std::vector < std::string > ({
            "user@example.com",
            "firstname.lastname@domain.co",
            "email+filter@sub.domain.com",
            "123456@mail-archive.com",
            "UPPER_CASE@Domain.Com",
            "user@subdomain.example.com",
            "user@xn--d1acjlb.xn"
        })
    );
    
} 