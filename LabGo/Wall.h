#include "Cell.h"
#include "Hero.h"
class Wall : public Cell {
public:
    virtual Cell* operator+(Hero& hero);
    virtual Cell* operator-(Hero& hero);
    //������ ������
    virtual void print(ostream& out) const;
    //����������� �����
    virtual Cell* copy();
    //����� �� ��������� �����
    /*virtual bool cansethero();*/
};
