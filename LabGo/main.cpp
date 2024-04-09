#include "Header.h"
#include "Game.h"
#include <fstream>
#include "Exceptions.h"
using namespace std;

int main() {
    Game g;
    //считывание лабиринта из файла и обработка ошибки
    //g.readfromfile("labirint.txt"); //считывание лабиринта из строки  (файл)
    g.readfromfile2("labirint2.txt"); //считывание лабиринта из многострочного файла
    g.TotalCoins();
    //начальная позиция
    g.setHeroPose(1, 1);
    unsigned int val = 0;
    cout << g;
    cout << "Total Coins:  " << g.getHero().getcoins() << endl;
    cout << "Total Health: " << g.getHero().gethealth() << " hp" << endl;
    try {
        val = _getch();
        while (val != 27) {
            system("cls");

            if (val == 224) {
                val = _getch();
            }
            switch (val) {
            case 80:
                g.move(DOWN);
                break;
            case 72:
                g.move(UP);
                break;
            case 75:
                g.move(LEFT);
                break;
            case 77:
                g.move(RIGHT);
                break;
            }
            cout << g;
            cout << "Total Coins:  " << g.getHero().getcoins() << endl;
            cout << "Total Health: " << g.getHero().gethealth() << " hp" << endl;
            val = _getch();
        }
    }
    catch (HeroHealthExceptions& exceptions) {
        exceptions.show();
    }
    catch (HeroWin& exceptions) {
        exceptions.show();
    }
    cout << "Game over!" << endl;
    g.writeinfile("labirintend.txt"); //сохранили лабиринт в конце программы
    return 0;
}
