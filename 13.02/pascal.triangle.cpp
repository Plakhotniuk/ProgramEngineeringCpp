/*
Напишите программу, которая выведет корректно отформатированные первые 10 строк треугольника Паскаля
*/

/*
Чтобы вывести треугольник, мы должны:
- сдвинуть позицию вывода вправо на соответствующее количество про
белов, чтобы вершина треугольника оказалась точно над серединой его
основания;
- вычислить каждое значение как сумму чисел слева и справа в строке
выше: самая простая формула: значение x в строке i и столбце j равно
предыдущему значению x, умноженному на (i – j) / (j + 1), где x начина
ется с 1.
*/
#include <string>
#include <iostream>


unsigned int number_of_digits(unsigned int const i) {
    return i > 0 ? (int)log10((double)i) + 1 : 1;
}


void print_pascal_triangle(const int n) {
    for (int i = 0; i < n; i++) {
        auto x = 1;
        std::cout << std::string((n - i - 1)*(n / 2), ' ');
        for (int j = 0; j <= i; j++) {
            auto y = x;
            x = x * (i - j) / (j + 1);
            auto maxlen = number_of_digits(x) - 1;
            std::cout << y << std::string(n - 1 - maxlen - n%2, ' ');
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    print_pascal_triangle(n);
}