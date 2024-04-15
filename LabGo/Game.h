#pragma once
#include "DynamicLab.h"
#include <iostream>
#include "IOBserver.h"
using namespace std;

enum ACTION //перечисление define переменных - возможные ходы
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class Game {
	DynamicLab labirint; //создание динамического массива для лабиринта
	Hero hero; //создание персонажа
	vector<IOBserver*> allObservers;
	int lab_w, lab_h; //размеры лабиринта
	int lab_health; //здоровье героя
	int coins;
public:
	Game(); //конструктор по умолчанию для создания игры
	//void readfromfile(const string& filename); //считывание игры из файла
	void addObserver(IOBserver* o) {
		allObservers.push_back(o);
	}
	void evnt() {
		for (IOBserver* o : allObservers)
		{
			o->evnt(hero);
		}
	}
	void readfromfile2(const string& filename);
	void writeinfile(const string& filename); //запись игры в файл
	void move(ACTION act); //задать передвижение персонажа
	void setHeroPose(int i, int j); //установление позиции персонажа

	friend ostream& operator<<(ostream& out, const Game& g); //печать игры в консоль

	Game(const Hero& hero) : hero(hero) {} // конструктор с инициализацией героя
	Hero& getHero() { return hero; } //возвращать адрес героя
	void TotalCoins();
	void displayLab(ostream& out) const;
};