#pragma once
#include "DynamicLab.h"
#include <iostream>
#include "IOBserver.h"
using namespace std;

enum ACTION //������������ define ���������� - ��������� ����
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
class Game {
	DynamicLab labirint; //�������� ������������� ������� ��� ���������
	Hero hero; //�������� ���������
	vector<IOBserver*> allObservers;
	int lab_w, lab_h; //������� ���������
	int lab_health; //�������� �����
	int coins;
public:
	Game(); //����������� �� ��������� ��� �������� ����
	//void readfromfile(const string& filename); //���������� ���� �� �����
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
	void writeinfile(const string& filename); //������ ���� � ����
	void move(ACTION act); //������ ������������ ���������
	void setHeroPose(int i, int j); //������������ ������� ���������

	friend ostream& operator<<(ostream& out, const Game& g); //������ ���� � �������

	Game(const Hero& hero) : hero(hero) {} // ����������� � �������������� �����
	Hero& getHero() { return hero; } //���������� ����� �����
	void TotalCoins();
	void displayLab(ostream& out) const;
};