#include "Trapezoid.h"
#include <stdexcept>

using std::logic_error;

Trapezoid::Trapezoid(Point* cords)
{
	_countCords = 4;

	if (!RightShape(cords))
	{
		throw logic_error("WRONG_SHAPE");
	}

	_cords = new Point[_countCords];
	_lenghtSides = new double[_countCords];
	memcpy(_cords, cords, sizeof(Point) * _countCords);

	CalculateSides();
}

double Trapezoid::GetArea() const
{
	double h = GetH();
	return (_lenghtSides[1] + _lenghtSides[3]) / 2 * h;
}

Point Trapezoid::GetCenter() const
{

	double centerTriangleX1 = (_cords[0].x + _cords[1].x + _cords[2].x) / 3;
	double centerTriangleY1 = (_cords[0].y + _cords[1].y + _cords[2].y) / 3;
	double centerTriangleX2 = (_cords[2].x + _cords[3].x + _cords[0].x) / 3;
	double centerTriangleY2 = (_cords[2].y + _cords[3].y + _cords[0].y) / 3;

	double areaTriangle1 = GetAreaTriangle(_cords[0], _cords[1], _cords[2]);
	double areaTriangle2 = GetAreaTriangle(_cords[2], _cords[3], _cords[0]);

	Point center;
	center.x = (areaTriangle1 * centerTriangleX1 + areaTriangle2 * centerTriangleX2) / (areaTriangle1 + areaTriangle2);
	center.y = (areaTriangle1 * centerTriangleY1 + areaTriangle2 * centerTriangleY2) / (areaTriangle1 + areaTriangle2);

	return center;
}

double Trapezoid::GetH() const
{
	double c = _lenghtSides[0];
	double a = _lenghtSides[1];
	double d = _lenghtSides[2];
	double b = _lenghtSides[3];
	return sqrt(c * c - ((pow(b - a, 2) + c * c - d * d) / (2 * (b - a))));
}

bool Trapezoid::RightShape(Point* cords) const
{
	bool IsParallel1 = IsParallelSides(cords[0], cords[1], cords[2], cords[3]);
	bool IsParallel2 = IsParallelSides(cords[1], cords[2], cords[3], cords[0]);

	if (IsParallel1 && !IsParallel2 || !IsParallel1 && IsParallel2)
	{
		return true;
	}
	return false;
}

double Trapezoid::GetAreaTriangle(const Point& dot1, const Point& dot2, const Point& dot3) const
{
	return abs(0.5 * ((dot1.x - dot3.x) * (dot2.y - dot3.y) - (dot1.y - dot3.y) * (dot2.x - dot3.x)));
}