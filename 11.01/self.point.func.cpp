/**
 * Реализуйте функцию, которая возвращает указатель на саму себя. 
 * Используйте дополнительного посредника.
 */
#include <iostream>
#include <typeinfo>


class Functor {
public:
    Functor* operator()() {
        return this;
    }

    void test1() const {
        std::cout << "test1 run" << std::endl;
    }
};

int main() {
    Functor functor; // наш посредник - функтор

    Functor* ptr = functor(); // получили указатель на себя

    functor.test1(); // обычный вызов

    ptr->test1(); // вызов через указатель на себя
}