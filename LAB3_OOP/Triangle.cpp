#include "triangle.h"
#include <cmath>
using std::logic_error;

Triangle::Triangle(Point* cords)
{
	_countCords = 3;

	if (!RightShape(cords))
	{
		throw logic_error("WRONG_SHAPE");
	}

	_cords = new Point[_countCords];
	_lenghtSides = new double[_countCords];
	memcpy(_cords, cords, sizeof(Point) * _countCords);

	CalculateSides();
}

double Triangle::GetArea() const
{
	double halfP = (_lenghtSides[0] + _lenghtSides[1] + _lenghtSides[2]) / 2;
	return sqrt(((halfP - _lenghtSides[0]) * (halfP - _lenghtSides[1])*(halfP- _lenghtSides[2]))*halfP);
}

Point Triangle::GetCenter() const
{
	Point center;
	center.y = (_cords[0].y + _cords[1].y + _cords[2].y) / _countCords;
	center.x = (_cords[0].x + _cords[1].x + _cords[2].x) / _countCords;
	return center;
}

bool Triangle::RightShape(Point* cords) const
{
	//_lenghtSides[i] = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	double aSide = sqrt(pow(cords[1].x - cords[0].x,2) + pow(cords[1].y - cords[0].y,2));
	double bSide = sqrt(pow(cords[2].x - cords[1].x,2) + pow(cords[2].y - cords[1].y,2));
	double cSide = sqrt(pow(cords[2].x - cords[0].x,2) + pow(cords[2].y - cords[0].y,2));

	if (aSide+bSide>cSide && aSide + cSide > bSide && cSide + bSide > aSide)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}	