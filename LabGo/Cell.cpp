#include "Header.h"
#include "Cell.h"
#include "Wall.h"
#include "Moneta.h"
#include "Monsters.h"
#include "EmptyCell.h"

// Перегрузка оператора вывода для класса Cell
ostream& operator<<(ostream& out, const Cell& cell) {
    cell.print(out);
    return out;
}

//ввод клеток
istream& operator>>(istream& in, Cell*& cell) {
    char symbol;
    in >>noskipws>>symbol; // Читаем символ

    switch (symbol) {
    case '#':
        cell = new Wall();
        break;
    case '$':
        cell = new Moneta();
        break;
    case '^':
        cell = new Monsters();
        break;
    default:
        cell = new EmptyCell(); 
        break;
    }
    return in;
}
