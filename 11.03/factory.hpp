/*
Реализуйте паттерн Factory в виде класса, содержащего ассоциативный контейнер, связывающий тип или код
создаваемого объекта и пакет инструкций для создания этого объекта. Пакет инструкций следует оформить
в виде лямбда-выражения. Необходимо реализовать способ хранения лямбда выражений по аналогии с при-
мером 11.03. Разместите ассоциативный контейнер в приватной секции, инициализируйте его и реализуйте
необходимый публичный интерфейс. Продемонстрируйте несколько способов использования Вашей фабрики
*/
#pragma once
#include <array>
#include <functional>
#include <iostream>


namespace factory {

class Entity {
public:
    virtual ~Entity() = default;

    virtual void test() const = 0;
};

class Client: public Entity {
public:

    Client(size_t data): data_(data) {};

    void test() const override {
        std::cout << "Test passed! Client data: " << data_ << std::endl;
    }

private:
    size_t data_;

};

class Factory {
public:
    virtual ~Factory() = default;

    virtual Entity* make(size_t id) const = 0;
};

class FactoryClient: public Factory {
public:
    Entity* make(size_t id) const override {
        if (id < 4)
            return create_methods[id]();
        else
            return nullptr;
    }

private:
    const std::array<std::function<Entity*()>, 4> create_methods = {
        [](){ return new Client{0}; },
        [](){ return new Client{1}; },
        [](){ return new Client{2}; },
        [](){ return new Client{3}; },
    };
};
    
} // namespace factory
