/*
Исследуйте оптимизацию малых строк, реализованную для класса std::basic_string в стандартной библио-
теке Вашей версии компилятора. Определите размер буфера N, использующегося для хранения малых строк
без динамического выделения памяти. Сравните среднее время создания строк длины N и строк длины N+1
*/

#include <bit>
#include <cassert>
#include <string>
#include <iostream>

using namespace std::literals;

///////////////////////////////////////////////////////////////////

template < typename T1, typename T2 > auto distance(T1 * x, T2 * y)
{
    return 
    (
        std::bit_cast < std::byte * > (x) - 
        
        std::bit_cast < std::byte * > (y)
    );
}

///////////////////////////////////////////////////////////////////


int main() {

    /// Определение размера буффера:

    std::string string_1(22, 'a');
    
    std::string string_2(23, 'a');

    assert(distance(&string_1.front(), &string_1) == 0);
    assert(distance(&string_2.front(), &string_2) != 0);

    // Размер буфера N = 22
}