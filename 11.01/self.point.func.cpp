/**
 * Реализуйте функцию, которая возвращает указатель на саму себя. 
 * Используйте дополнительного посредника.
 */
#include <iostream>
#include <typeinfo>

class FuncPtr_;
typedef FuncPtr_ (*FuncPtr)();

class FuncPtr_ {
public:
    FuncPtr_(FuncPtr ptr): ptr_(ptr) {};

    FuncPtr operator()() { return ptr_; };

private:
    FuncPtr ptr_;
};

FuncPtr_ f () { return f; }

int main() {

    FuncPtr_ p = f();

    p();

}