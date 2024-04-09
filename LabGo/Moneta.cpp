#include "Moneta.h"
#include "EmptyCell.h"
#include "HeroCell.h"

Moneta::Moneta() {}

Moneta::~Moneta() {}

//операция +
Cell* Moneta::operator+(Hero& hero) {
    hero.addcoins(); 
    cout << "Total Coins: " << hero.getcoins() << endl;
    return new HeroCell;
}


//операция -
Cell* Moneta::operator-(Hero& hero) {
    return new EmptyCell;
}
//вывод монеты на печать
void Moneta::print(ostream& out) const {
    out << "$"; 
}
 int Moneta::getcoinscount() { 
    cout << "Total Coins: " << coinscount << endl;
    return coinscount; 
 }

 //копирование объекта
Cell* Moneta::copy() {
     return new Moneta(*this);
 }