/**
 * Приведите пример программной задачи, в решении которой будет уместно использование идиомы RAII.

Пример:
    Допустим мы хотим в многопоточной программе избежать гонки данных при работе с контейнером из стандартной библиотеки.
    Тогда для безопасной работы можно спроектировать шаблонный RAII класс прозрачной мьютекс-обертки,
     который в конструкторе захватывает ресур: мьютекс, и в деструкторе его отпускает.
 */

#pragma once
#include <mutex>

namespace mutexed {

template <typename T, class Mutex = std::mutex>
class Owner {
public:
     explicit Owner(T& object, Mutex& mutex)
         : object_(object),
           lock_(mutex) {
     }
 
     // Delete copy constructor and assignment
     Owner(const Owner&) = delete;
     Owner& operator=(const Owner&) = delete;
 
     // Allow move semantics
     Owner(Owner&&) = default;
     Owner& operator=(Owner&&) = default;
 
     T* operator->() {
       return &object_;
     }
 
     T& operator*() {
       return object_;
     }
 
private:
     T& object_;
     std::lock_guard<Mutex> lock_;
};
}