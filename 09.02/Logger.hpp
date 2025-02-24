/**
 * Реализуйте класс Logger для трассировки, используя идиому RAII и информацию из std::source_location. 
 * Предполагается, что пользователь данного класса в начале каждой функции будет создавать экземпляр логгера, 
 * конструктор которого выведет в консоль сообщение о начале выполнения функции с указанием всей необходимой информации. 
 * Деструктор совершит аналогичное действие после завершения работы данной функции. 
 * Оформите инструкции вывода трассировочных сообщений в отдельной функции, доступной для пользователя.
 */
#pragma once
#include <source_location>
#include <iostream>

namespace logger {

class Logger 
{
public:
    static void log(const std::string_view message, const std::source_location& location = std::source_location::current())
    {
        std::clog << "file: "
                << location.file_name() << '('
                << location.line() << ':'
                << location.column() << ") `"
                << location.function_name() << "`: "
                << message << '\n';
    }

    Logger(const std::source_location& location = std::source_location::current()): location_(location) 
    { 
        log("Function entry", location_); 
    }

    ~Logger() 
    {
        log("Function exit", location_); 
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

private:
    std::source_location location_;
};

}