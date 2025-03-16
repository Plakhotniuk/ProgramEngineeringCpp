/**
* Доработайте пример 02.13 так, чтобы пользователь мог задавать критерий сортировки через функцию, пере-
даваемую в алгоритм сортировки как дополнительный аргумент, тип которого является указателем на функ-
цию. Продемонстрируйте использование собственных критериев сортировки по возрастанию и по убыванию.

Доработайте тот же пример так, чтобы пользователь мог задавать критерий сортировки через функциональ-
ный объект с перегруженным оператором вызова, передаваемый в алгоритм сортировки как дополнительный
аргумент, тип которого задается дополнительным параметром шаблона. 

Продемонстрируйте использование 
собственных критериев сортировки по возрастанию и по убыванию, а также функциональных объектов из
стандартной библиотеки std::less и std::greater. Доработайте тот же пример так, чтобы пользователь
мог задавать критерий сортировки через лямбда-выражение, передаваемое в алгоритм сортировки как до-
полнительный аргумент, тип которого задается дополнительным параметром шаблона. Продемонстрируйте
использование собственных критериев сортировки по возрастанию и по убыванию. Сдавайте 3 файла решений
*/

/////////////////////////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <cstddef>

#include "sort.algorithm.hpp"

namespace {

bool compare_greater(int a, int b) {
    return a > b;
}

bool compare_less(int a, int b) {
    return a < b;
}

struct FunctorLess {
	bool operator()(int a, int b) const { return a < b; };
};

struct FunctorGreater {
	bool operator()(int a, int b) const { return a > b; };
};

}


int main()
{
	auto size = 1'000uz;

	std::vector < int > vector(size, 0);

	for (auto i = 0uz; i < size; ++i)
	{
		vector[i] = size - i;
	}

    {
        bool (*comp_func)(int, int);  // определение указателя на функцию сравнения двух int-ов
        // передаем указатели (имена функций) критериев сортировки
        comp_func = compare_greater;
        sort::timsort(vector, comp_func);
        assert(std::ranges::is_sorted(vector, comp_func));

        comp_func = compare_less;
        sort::timsort(vector, comp_func);
        assert(std::ranges::is_sorted(vector, comp_func));
    }

    {
        /// критерии сравнения через лямбды
        auto comp_less_l = [](int a, int b) { return a < b; };
        auto comp_great_l = [](int a, int b) { return a > b; };

        sort::timsort(vector, comp_great_l);
        assert(std::ranges::is_sorted(vector, comp_great_l));

        sort::timsort(vector, comp_less_l);
        assert(std::ranges::is_sorted(vector, comp_less_l));
    }

    {
        // использование std::greater, less
        sort::timsort(vector, std::greater());
        assert(std::ranges::is_sorted(vector, std::ranges::greater()));

        sort::timsort(vector, std::ranges::less());
        assert(std::ranges::is_sorted(vector, std::ranges::less()));
    }

    {
        // использование функционального объекта
        sort::timsort(vector, FunctorGreater{});
        assert(std::ranges::is_sorted(vector, FunctorGreater{}));

        sort::timsort(vector, FunctorLess{});
        assert(std::ranges::is_sorted(vector, FunctorLess{}));
    }
}