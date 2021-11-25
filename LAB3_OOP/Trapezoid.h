#include "Shape.h"

class Trapezoid : public Shape
{
public:
	Trapezoid(Point* cords);

	double GetArea() const override;
	Point GetCenter() const override;
private:
	bool RightShape(Point* cords) const;
	double GetH() const;
	double GetAreaTriangle(const Point& dot1, const Point& dot2, const Point& dot3) const;
};