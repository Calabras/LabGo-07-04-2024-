#include "Game.h"
#include "IOBserver.h"

void ViewHealth::evnt(Hero& hero) {
		out << "Total Health: " << hero.gethealth() << " hp" << endl;
}

void ViewPosition::evnt(Hero& hero) {
		out << "Current Position: (" << hero.geti() << ";" << hero.getj() << ")" << endl;
}

void ViewCoins::evnt(Hero& hero) {
		out << "Total Coins: " << hero.getcoins() << endl;
}

void ViewTotalSteps::evnt(Hero& hero) {
    out << "Total Steps: " << hero.getsteps() << endl;
}

void ViewLabirint::evnt(Hero& hero) {
	g.displayLab(out);
}


//контроллер передвижения героя
void Controller::changepose(int val) {
    int ip = hero.geti(), jp = hero.getj();
    switch (val) {
    case 80: // down
        g.setHeroPose(ip + 1, jp);
        hero.addsteps();
        break;
    case 72: //up
        g.setHeroPose(ip - 1, jp);
        hero.addsteps();
        break;
    case 75: //left
        g.setHeroPose(ip, jp - 1);
        hero.addsteps();
        break;
    case 77: //right
        g.setHeroPose(ip, jp + 1);
        hero.addsteps();
        break;
    }
}
