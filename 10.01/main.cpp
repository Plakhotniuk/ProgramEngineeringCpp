#include <cstdint>
#include <forward_list>
#include <iostream>
#include <cassert>

// Сформулируйте способ хранения полухода шахматной партии с минимально возможными затратами памяти.

// Для хранения полухода партии воспользуемся forward_list,
// для хранения хода в партии используем структуру с двумя полями: откуда фигуру берем и куда ее ставим на текущем ходу.
// Каждой клетке присвоим номер от 0 до 63.

// Затраты по памяти минимальны потому что аллоцируем для каждого хода лишь:
// sizeof(HalfWay) + sizeof(void*) bytes = 2 + 8 = 10 байт
namespace {

struct HalfWay {
    uint8_t prev_: 6;
    uint8_t current_: 6;
};

}

int main() {

    std::forward_list<HalfWay> game;

    game.push_front({13, 27});
    game.push_front({48, 34});

    assert(2 == sizeof(HalfWay));
    assert(10 == sizeof(game.front()) + sizeof(void*));
}