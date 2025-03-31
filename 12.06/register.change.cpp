/*
Реализуйте алгоритм преобразования начальных символов слов некоторого текста в верхний регистр, а осталь-
ных символов в нижний регистр. Например, текст "heLLo, woRLD" должен превратиться в "Hello, World".
*/

#include <cctype>
#include <string>
#include <sstream>
#include <iostream>
#include <cassert>

std::string correctRegister(const std::string& text) {
    std::string result;
    bool newWord = true;  // Флаг начала нового слова

    for (char ch : text) {
        if (std::isalpha(ch)) {  // Если символ — буква
            if (newWord) {
                result += std::toupper(ch);  // Первая буква слова — в верхний регистр
                newWord = false;
            } else {
                result += std::tolower(ch);  // Остальные буквы — в нижний
            }
        } else {  // Если символ не буква
            result += ch;
            newWord = !std::isalnum(ch);  // Новое слово начинается после не-буквенно-цифрового символа
        }
    }

    return result;
}


int main() {
    std::string text = "heLLo, woRLD!";
    std::string result = correctRegister(text);
    assert(result == "Hello, World!");
}

