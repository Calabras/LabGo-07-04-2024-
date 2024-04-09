#include "Cell.h"

class HeroCell : public Cell {
public:
    virtual ~HeroCell() {}

    virtual Cell* operator+(Hero& hero);
    virtual Cell* operator-(Hero& hero);
    virtual void print(ostream& out) const;
    virtual Cell* copy();
};
