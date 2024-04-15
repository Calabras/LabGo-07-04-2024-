#pragma once
class Game;
class Hero;
class IOBserver {
public:
	virtual void evnt(Hero& hero) = 0; //событие
};

class ViewHealth : public IOBserver {
	ostream& out;
public:
	ViewHealth(ostream& _out) : out(_out) {};
	void evnt(Hero& hero);
};

class ViewPosition : public IOBserver {
	ostream& out;
public:
	ViewPosition(ostream& _out) : out(_out) {};
	void evnt(Hero& hero);
};

class ViewCoins : public IOBserver {
	ostream& out;
public:
	ViewCoins(ostream& _out) : out(_out) {};
	void evnt(Hero& hero);
};

class ViewTotalSteps : public IOBserver {
	ostream& out;
public:
	ViewTotalSteps(ostream& _out) : out(_out) {};
	void evnt(Hero& hero);
};

class ViewLabirint : public IOBserver {
	Game& g;
	ostream& out;
public:
	ViewLabirint(Game& g, ostream& o): g(g), out(o) {};
	void evnt(Hero& hero);
};

class Controller {
	Hero& hero;
	Game& g;
public:
	Controller(Hero& _hero, Game& _g) : hero(_hero), g(_g) {}
	void changepose(int val);
};
