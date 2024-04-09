#include "Moneta.h"
#include "EmptyCell.h"
#include "HeroCell.h"

Moneta::Moneta() {}

Moneta::~Moneta() {}

//�������� +
Cell* Moneta::operator+(Hero& hero) {
    hero.addcoins(); 
    cout << "Total Coins: " << hero.getcoins() << endl;
    return new HeroCell;
}


//�������� -
Cell* Moneta::operator-(Hero& hero) {
    return new EmptyCell;
}
//����� ������ �� ������
void Moneta::print(ostream& out) const {
    out << "$"; 
}
 int Moneta::getcoinscount() { 
    cout << "Total Coins: " << coinscount << endl;
    return coinscount; 
 }

 //����������� �������
Cell* Moneta::copy() {
     return new Moneta(*this);
 }