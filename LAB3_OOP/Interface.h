#include <iostream>
#include "Operators.h"
#include "Factory.h"

using std::string;

class Interface
{
public:
	Interface();
	~Interface();

	void Init() const;
private:
	int GetIndex(const string& name) const;
	void Help() const;
	void CreateShape() const;
	void DeleteShape(const string& name) const;
	void PrintShape() const;
	void DelShape() const;
	void Compare() const;
	void IsIntersect() const;
	void IsInclude() const;
	void GetArea() const;
	void GetCenter() const;
	void Move() const;
	void Rotate() const;

	Shape** _cases = nullptr;
	string* _names = nullptr;
	int _count = 0;
	const int COUNT_POINTS = 4;

};