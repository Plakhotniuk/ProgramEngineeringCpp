/*
12.14 [25]
Напишите программу, которая принимает на вход текст и извлекает из него все российские автомобильные
номера. В демонстрационном тестовом тексте для избежания проблем с кириллицей допускается использовать
латиницу. Текст подготовьте самостоятельно и внедрите его в исходный код с помощью сырых строк. В тексте
должны присутствовать как корректные, так и некорректные автомобильные номера, а также мусорный текст
*/
#include <cassert>
#include <iostream>
#include "regex_find.hpp"

using namespace std::literals;

// А, В, Е, К, М, Н, О, Р, С, Т, Y, Х - разрешенные буквы (верхний регистр, английские буквы).

// формат: LNNNLLN(NN), где L - разрешенная буква, N любая цифра, (N) - цифра может быть или нет.


int main() {
    auto input_string = "afwrvwer918hf A123BC45 984nvs0wffa0 X999YY7 uy432YY2 "s;

    std::regex pattern(R"([ABEKMHOPCTYX][0-9]{3}[ABEKMHOPCTYX]{2}[0-9]{1,3})");

    std::vector < std::string > result = findAllRegexPatterns(pattern, input_string);

    assert(result == std::vector < std::string > ({ "A123BC45", "X999YY7" }));
}
