#include "Shape.h"

Shape::~Shape()
{
	delete[] _lenghtSides;
	delete[] _cords;
}

int Shape::GetCountCords() const
{
	return _countCords;
}


Point& Shape::GetPoint(const int index) const
{
	if (index < _countCords && index >= 0)
	{
		return _cords[index];
	}
	else
	{
		throw std::out_of_range("OUT_OF_RANGE");
	}
}

void Shape::CalculateSides()
{
	for (int i = 0; i < _countCords; i++)
	{
		double x1 = _cords[i % _countCords].x;
		double x2 = _cords[(i + 1) % _countCords].x;
		double y1 = _cords[i % _countCords].y;
		double y2 = _cords[(i + 1) % _countCords].y;
		_lenghtSides[i] = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	}
}

void Shape::Move(const char direction, const double count)
{
	switch (direction)
	{
	case 'u':
		for (int i = 0; i < _countCords; i++)
		{
			_cords[i].y += count;
		}
		break;
	case 'd':
		for (int i = 0; i < _countCords; i++)
		{
			_cords[i].y -= count;
		}
		break;
	case 'l':
		for (int i = 0; i < _countCords; i++)
		{
			_cords[i].x -= count;
		}
		break;
	case 'r':
		for (int i = 0; i < _countCords; i++)
		{
			_cords[i].x += count;
		}
		break;
	default:
		break;
	}
}
void Shape::Rotate(const int angle)
{
	Point center = GetCenter();
	double sinA = sin((double)angle * PI / 180);
	double cosA = cos((double)angle * PI / 180);

	for (int i = 0; i < _countCords; i++)
	{
		_cords[i].x -= center.x;
		_cords[i].y -= center.y;

		double newx = _cords[i].x * cosA - _cords[i].y * sinA;
		double newy = _cords[i].x * sinA + _cords[i].y * cosA;

		_cords[i].x = newx + center.x;
		_cords[i].y = newy + center.y;
	}
}

double Shape::GetSide(const int index) const
{
	if (index < _countCords && index >= 0)
	{
		return _lenghtSides[index];
	}
	else
	{
		throw std::out_of_range("OUT_OF_RANGE");
	}
}

std::string Shape::ToString() const
{
	std::string result = "";
	for (int i = 0; i < _countCords; i++)
	{
		result += std::to_string(i) + ") - x: " + std::to_string(_cords[i].x) + " y: " + std::to_string(_cords[i].y) + "\n";
	}
	return result;
}

bool Shape::IsParallelSides(const Point& a1, const Point& a2, const Point& b1, const Point& b2) const
{
	double k1 = (a2.y - a1.y) / (a2.x - a1.x);
	double k2 = (b2.y - b1.y) / (b2.x - b1.x);

	if (k1 == k2 || !(a2.x - a1.x) && !(b2.x - b1.x))
	{
		return true;
	}
	return false;
}