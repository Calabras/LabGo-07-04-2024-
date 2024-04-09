class Exceptions {
public:
	virtual void show() = 0;
};
class WallExceptions : public Exceptions {
public :
	void show() {
		cout << "Wall!" << endl;
	}
};
class MonstersExceptions : public Exceptions {
public:
	void show() {
		cout << "Monsters!" << endl;
	}
};
class HeroHealthExceptions : public Exceptions {
public:
	void show() {
		cout << "Hero health`s is zero!" << endl;
	}
};
class HeroWin : public Exceptions {
public: 
	void show() {
		cout << "You collected all coins! You win!" << endl;
	}
};