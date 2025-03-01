/**
 * Исследуйте систему выделения памяти внутри вектора. 
 * Для этого определите с помощью вызовов функции члена capacity, 
 * во сколько раз изменяется емкость вектора при нехватке памяти для размещения новых элементов. 
 * Также определите, как увеличивается емкость вектора, если задать ее начальное значение вручную 
 * с помощью вызова функции-члена reserve. 
 * Дополнительно определите, как осуществляется выделение памяти в предельном случае, 
 * когда вектор уже запросил большой объем памяти и на выполнение следуещего запроса у ОС может не хватить ресурсов. 
 * В комментариях в коде подробно опишите полученные наблюдения.
 */
#include <vector>
#include <iostream>
#include <fstream> 

void simplePushback() {

    std::vector<int> data;

    size_t stopSz = 100;

    std::ofstream vectorSizeCapacityFile("vectorSizeCapacity.txt");

    for (size_t i = 0; i < stopSz; ++i) {
        data.push_back(1);
        vectorSizeCapacityFile << data.size() << " " << data.capacity() <<std::endl;
    }
    vectorSizeCapacityFile.close();
    // Из графика видно, что capacity увеличивается в 2 раза при нехватке места в векторе
}

void setManualCapacity() {
    std::vector<int> data;

    size_t stopSz = 100;

    data.reserve(20);

    std::ofstream vectorSizeCapacityFile("setManualCapacity.txt");

    for (size_t i = 0; i < stopSz; ++i) {
        data.push_back(1);
        vectorSizeCapacityFile << data.size() << " " << data.capacity() <<std::endl;
    }
    vectorSizeCapacityFile.close();
    // Из графика видно, что capacity увеличивается опять же увеличивается в 2 раза при нехватке места в векторе
}

void setTooMuchCapacity() {
    std::vector<int> data;

    size_t stopSz = 100;

    data.reserve(100'000'000);

    std::ofstream vectorSizeCapacityFile("setTooMuchCapacity.txt");

    for (size_t i = 0; i < stopSz; ++i) {
        data.push_back(1);
        vectorSizeCapacityFile << data.size() << " " << data.capacity() <<std::endl;
    }
    vectorSizeCapacityFile.close();
    // Из полученных данных видно, что capacity увеличивается до доступного в памяти значения 
}


int main() {
    simplePushback();
    setManualCapacity();
    setTooMuchCapacity();
}