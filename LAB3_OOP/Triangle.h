	#include "Shape.h"
#include <stdexcept>

class Triangle : public Shape
{
public:
	Triangle(Point* cords);

	double GetArea() const override;
	Point GetCenter() const override;
private:
	bool RightShape(Point* cords) const;
};