/*
11.12
Продемонстрируйте использование алгоритмов std::count, std::mismatch, std::equal, std::search,
std::replace, std::remove, std::unique, std::rotate, std::partition и std::nth_element из стандарт-
ной библиотеки на простейших тестовых примерах. Не используйте в данной задаче диапазоны и представления

11.15
Доработайте Ваше предыдущее решение задачи 11.12 так, чтобы использовались алгоритмы на диапазонах
*/
#include <algorithm>
#include <array>
#include <vector>
#include <cassert>
#include <complex>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <ranges>


int main() {

    constexpr std::array v{1, 2, 3, 4, 4, 3, 7, 8, 9, 10};

    {
        // std::count 
        int target = 4;
        int num_items = std::count(v.begin(), v.end(), target);
        assert(num_items == 2);

        num_items = std::ranges::count(v, target);
        assert(num_items == 2);
    }

    {
        // std::mismatch
        std::array v2 = v;
        v2[0] = 10;
        auto [iter1, iter2] = std::mismatch(v.begin(), v.end(), v2.begin());
        assert(*iter1 == 1);
        assert(*iter2 == 10);

        auto [iter3, iter4] = std::ranges::mismatch(v, v2);
        assert(*iter3 == 1);
        assert(*iter4 == 10);
    }

    {
        // std::equal
        std::array v2 = v;
        v2[0] = 10;
        bool result = std::equal(v.begin(), v.end(), v2.begin());
        assert(!result);

        result = std::ranges::equal(v, v2);
        assert(!result);
    }

    {
        // std::search
        std::vector<int> v2;
        v2.reserve(v.size());
        const size_t shift = 5;
        std::copy(v.begin() + shift, v.end(), std::back_inserter(v2));
        auto result = std::search(v.begin(), v.end(), v2.begin(), v2.end());
        assert(result == v.begin() + shift);

        auto result_r = std::ranges::search(v, v2);
        assert(result_r.begin() == v.begin() + shift);

        std::vector v3 = {100};
        auto result2 = std::search(v.begin(), v.end(), v3.begin(), v3.end());
        assert(result2 == v.end());

        auto result2_r = std::ranges::search(v, v3);
        assert(result2_r.begin() == v.end());
    }

    {
        // std::replace
        std::array v2 = v;

        int old_val = 4;
        int new_val = 44;
        std::replace(v2.begin(), v2.end(), old_val, new_val);
        assert(std::count(v2.begin(), v2.end(), new_val) == 2);

        std::array v3 = v;
        std::ranges::replace(v3, old_val, new_val);
        assert(std::count(v3.begin(), v3.end(), new_val) == 2);
    }

    {
        // std::remove
        std::array v2 = v;

        int rm_val = 4;
        const auto result = std::remove(v2.begin(), v2.end(), rm_val);
        assert(std::distance(v2.begin(), result) == 8);

        v2 = v;
        
        const auto result_r = std::ranges::remove(v2, rm_val);
        assert(std::distance(v2.begin(), result_r.begin()) == 8);
    }

    {
        // std::unique
        std::vector v2(v.begin(), v.end());

        const auto last = std::unique(v2.begin(), v2.end());
        v2.erase(last, v2.end());
        assert(v2.size() == v.size() - 1);

        std::vector v2_r(v.begin(), v.end());

        const auto ret = std::ranges::unique(v2_r);
        v2_r.erase(ret.begin(), ret.end());
        assert(v2_r.size() == v.size() - 1);
    }

    {
        // std::rotate
        std::vector<int> v2 = {1, 2, 3};
        int first = v2[0];
        int last = v2[2];
        std::rotate(v2.rbegin(), v2.rbegin() + 1, v2.rend());

        assert(*(v2.begin()) == last);
        assert(*(v2.begin() + 1) == first);

        std::ranges::rotate(v2, v2.begin() + 1);

        assert(*(v2.begin()) == first);
        assert(*(v2.end() - 1) == last);
    }

    {
        // std::partition
        std::vector<int> v2;
        v2.resize(10);

        std::iota(v2.begin(), v2.end(), 1);

        auto it = std::partition(v2.begin(), v2.end(), [](int i) {return i % 2 == 0;}); // even * odd partition

        std::cout << "Even * odd partitioned vector: \n";
    
        std::copy(std::begin(v2), it, std::ostream_iterator<int>(std::cout, " "));
        std::cout << "* ";
        std::copy(it, std::end(v2), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        auto it_r = std::ranges::partition(v2, [](int i) {return i % 2 == 1;}); // odd * even partition

        std::cout << "Odd * even partitioned vector with ranges: \n";
        std::ranges::copy(std::begin(v2), it_r.begin(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "* ";
        std::ranges::copy(it_r, std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

    }

    {
        // std::nth_element
        std::cout << "Nth_element vector: \n";
        std::vector<int> v2 = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
        auto m = v2.begin() + v2.size() / 2;
        std::nth_element(v2.begin(), m, v2.end());
        std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::cout << "Nth_element vector ranges: \n";
        auto m_r = v2.begin() + v2.size() / 2 + 1;
        std::ranges::nth_element(v2.begin(), m_r, v2.end());
        std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;


    }
}