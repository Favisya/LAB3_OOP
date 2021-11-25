#pragma once
#include <cmath>
#include <stdexcept>  
#include <string>

struct Point
{
	double x;
	double y;
};

class Shape
{
public:
	Shape() : 
		_cords(nullptr), _countCords(0), _lenghtSides(nullptr), PI(3.14159265358979323846) {}
	~Shape();


	void Move(const char direction, const double count);
	void Rotate(const int angle);
	int GetCountCords() const;
	double GetSide(const int index) const;
	std::string ToString() const;

	Point& GetPoint(const int index) const;


	virtual double GetArea() const = 0;
	virtual Point GetCenter() const = 0;


protected:

	Point* _cords;
	int _countCords;
	double* _lenghtSides;

	const double PI;

	void CalculateSides();

	bool IsParallelSides(const Point& a1, const Point& a2, const Point& b1, const Point& b2) const;
};