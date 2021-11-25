#include "Shape.h"

class Operators
{
public:
	int Compare(Shape& shape1, Shape& shape2) const;
	bool Intersect(Shape& shape1, Shape& shape2) const;
	bool Include(Shape& shape1, Shape& shape2) const;

	double Length(Point& point1, Point& point2) const;
	double GetRadius(Shape& shape) const;
};