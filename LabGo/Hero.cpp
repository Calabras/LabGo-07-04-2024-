#include "Header.h"
#include "IOBserver.h"
#include "Hero.h"
#include "Exceptions.h"
//���������� i
int Hero::geti() const { return i; }
//���������� j
int Hero::getj() const { return j; }
//����� ��������� �� ������
ostream& operator<<(ostream& out, const Hero& h) {
	out << "R";
    return out;
}
//����������� ����� �����
void Hero::addcoins() {
	coins++; 
}
//���������� ����� �����
int Hero::getcoins() const {
	return coins;
}
//���������� ����� ����� �����
int Hero::getsteps() const {
	return steps;
}
//��������� ����� �����
void Hero::addsteps() {
	steps++;
}
//������ �����
void Hero::removehealth() {
	health--;
	if (health == 0) throw HeroHealthExceptions();
}
//������� ����� ��
int Hero::gethealth() const {
	return health;
}
//c������
void Hero::evnt() {
	for (IOBserver* o : allObserver)
	{
		o->evnt(*this);
	}
}
//push back
void Hero::addObserver(IOBserver* o) {
	allObserver.push_back(o);
}
