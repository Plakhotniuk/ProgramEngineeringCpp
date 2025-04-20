/*
Реализуйте алгоритм преобразования коллекции 8-битных целых чисел в строку шестнадцатиричных цифр.
Например, коллекция 0xBA, 0xAD должна быть преобразована в строку "BAAD". Для хранения коллекции
можно использовать контейнер std::vector. Используйте строковый поток вывода и манипуляторы потоков

Вход: { 0xBA, 0xAD, 0xF0, 0x0D }, выход: "BAADF00D" или "baadf00d"
Вход: { 1,2,3,4,5,6 }, выход: "010203040506"

*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cassert>


template <typename Iter>
std::string bytes_to_hexstr(Iter begin, Iter end, const bool upper_case = false) {
    std::ostringstream oss;
    if (upper_case)
        oss.setf(std::ios_base::uppercase);

    for (; begin != end; ++begin) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(*begin);
    }

    return oss.str();
}

int main() {
    std::vector<unsigned char> input{0xBA, 0xAD, 0xF0, 0x0D};

    std::string result_lower = bytes_to_hexstr(input.begin(), input.end());
    assert(result_lower == "baadf00d");

    std::string result_upper = bytes_to_hexstr(input.begin(), input.end(), true);
    assert(result_upper == "BAADF00D");

    std::vector<unsigned char> input_n{1,2,3,4,5,6};

    std::string result_n = bytes_to_hexstr(input_n.begin(), input_n.end());
    assert(result_n == "010203040506");
}

