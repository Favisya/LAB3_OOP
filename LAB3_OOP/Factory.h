#include "Triangle.h"
#include "Trapezoid.h"

class Factory
{
public:
    virtual Shape* createShape(Point* cords,int choose)
    {
        if (choose == 1)
        {
            return new Triangle(cords);
        }
        else if (choose == 2)
        {
            return new Trapezoid(cords);
        }
    }

    ~Factory() {}
};

   


