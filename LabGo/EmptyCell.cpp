#include "EmptyCell.h"
#include "HeroCell.h"
Cell* EmptyCell::operator+(Hero& hero) {
    return new HeroCell;
}
//�������� -
Cell* EmptyCell::operator-(Hero& hero) {
    return this;
}
//����� ������ �� ������
void EmptyCell::print(ostream& out) const {
    out << " ";
}
//����������� �������
Cell* EmptyCell::copy() {
    return new EmptyCell(*this);
}