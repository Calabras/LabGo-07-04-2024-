#include "Header.h"
#include "Cell.h"
#include "Wall.h"
#include "Moneta.h"
#include "Monsters.h"
#include "EmptyCell.h"

//������ ��������� ������� ������
//bool Cell::cansethero() {
//    return true;
//}
// ���������� ��������� ������ ��� ������ Cell
ostream& operator<<(ostream& out, const Cell& cell) {
    cell.print(out);
    return out;
}

//���� ������
istream& operator>>(istream& in, Cell*& cell) {
    char symbol;
    in >>noskipws>>symbol; // ������ ������

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
