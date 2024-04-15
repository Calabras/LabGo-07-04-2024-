#include "Header.h"
#include "Game.h"
#include <fstream>
#include "Exceptions.h"
#include "IOBserver.h"
using namespace std;

int main() {
    Game g;
    //считывание лабиринта из файла и обработка ошибки
    //g.readfromfile("labirint.txt"); //считывание лабиринта из строки  (файл)
    g.readfromfile2("labirint2.txt"); //считывание лабиринта из многострочного файла
    g.TotalCoins();
    //начальная позиция
    g.setHeroPose(1, 1);

    Hero& hero = g.getHero();

    //все наблюдатели
    ViewHealth healthView(cout);
    ViewPosition positionView(cout);
    ViewCoins coinsView(cout);
    ViewTotalSteps stepsView(cout);
    ViewLabirint labirintView(g, cout);

    
    hero.addObserver(&healthView);
    hero.addObserver(&positionView);
    hero.addObserver(&coinsView);
    hero.addObserver(&stepsView);
    g.addObserver(&labirintView);
    

    Controller heroController(hero, g);
    try {
        int val = _getch();
        while (val != 27) {
            system("cls");
            heroController.changepose(val);
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
