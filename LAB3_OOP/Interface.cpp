#include <iostream>
#include "Interface.h"

using std::cin;
using std::cout;

Interface::~Interface()
{
	for (int i = 0; i < _count; i++)
	{
		if (_names[i] != "")
		{
			delete _cases[i];
		}
	}
	delete[] _names;
	delete[] _cases;
}

Interface::Interface()
{
	cout << "Enter space for Shapes\n>> ";
	cin >> _count;
	_names = new string[_count];
	_cases = new Shape * [_count];
}

int Interface::GetIndex(const string& name) const
{
	for (int i = 0; i < _count; i++)
	{
		if (name == _names[i])
		{
			return i;
		}
	}
	return -1;
}

void Interface::Move() const
{
	string name;
	char side;
	double count;
	cout << "Enter name of shape\n>> ";
	cin >> name;
	int indexName1 = GetIndex(name);
	if (indexName1 != -1)
	{
		cout << "Which side?(u-up, l-left, r-right, d-down)\n>> ";
		cin >> side;
		cout << "How much\n>> ";
		cin >> count;
		_cases[indexName1]->Move(side, count);
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void Interface::Rotate() const
{
	string name;
	int angle;
	cout << "Enter name of shape\n>> ";
	cin >> name;
	int indexName1 = GetIndex(name);
	if (indexName1 != -1)
	{
		cout << "Enter angle\n>> ";
		cin >> angle;
		_cases[indexName1]->Rotate(angle);
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void Interface::Help() const
{
	cout << "\"1\" - Create new Shape\n\"2\" - Delete Shape\n\"3\" - Help\n\"4\" - Compare \n\"5\" - IsIntersect\n\
\"6\" - IsInclude\n\"7\" - Print Shape\n\"8\" - Get Area\n\"9\" - Get Center\n\"0\" - Exit\n\"-\" - Rotate\n\"=\" - Move\n";
}

void Interface::CreateShape() const
{
	Factory fact;

	cout << "Enter name of Shape: >> ";
	string name;
	cin >> name;

	int type;
	cout << "Is it Triangle or Trapezoid (1 or 2): >> ";
	cin >> type;

	


	if (type == 1)
	{
		Point* points = new Point[COUNT_POINTS - 1];
		cout << "Enter points:\n";
		for (int i = 0; i < COUNT_POINTS-1; i++)
		{
			cout << i + 1 << ") x: >> ";
			cin >> points[i].x;
			cout << i + 1 << ") y: >> ";
			cin >> points[i].y;
			cout << '\n';
		}

		bool isEnoughtSpace = false;
		int index;
		for (int i = 0; i < _count && !isEnoughtSpace; i++)
		{
			if (_names[i].empty())
			{
				isEnoughtSpace = true;
				index = i;
			}
		}

		if (isEnoughtSpace)
		{
			Shape* newElement = nullptr;

			try
			{
				newElement = fact.createShape(points,type);
				_names[index] = name;
				_cases[index] = newElement;
				cout << "Complete!\n";
			}
			catch (const std::logic_error& src)
			{
				cout << src.what() << "\n";
			}
		}
		else
		{
			cout << "You don't have enought space, delete something\n";
		}
		delete[] points;
	}
	
	if (type == 2)
	{
		Point* points = new Point[COUNT_POINTS];
		cout << "Enter points:\n";
		for (int i = 0; i < COUNT_POINTS; i++)
		{
			cout << i + 1 << ") x: >> ";
			cin >> points[i].x;
			cout << i + 1 << ") y: >> ";
			cin >> points[i].y;
			cout << '\n';
		}

		bool isEnoughtSpace = false;
		int index;
		for (int i = 0; i < _count && !isEnoughtSpace; i++)
		{
			if (_names[i].empty())
			{
				isEnoughtSpace = true;
				index = i;
			}
		}

		if (isEnoughtSpace)
		{
			Shape* newElement = nullptr;

			try
			{
				newElement = fact.createShape(points, type);
				_names[index] = name;
				_cases[index] = newElement;
				cout << "Complete!\n";
			}
			catch (const std::logic_error& src)
			{
				cout << src.what() << "\n";
			}
		}
		else
		{
			cout << "You don't have enought space, delete something\n";
		}
		delete[] points;
	}
	if(type != 1 && type!= 2)
	{
		cout << "Wrong command!\n";
	}

}

void Interface::DeleteShape(const string& name) const
{
	int index = GetIndex(name);

	if (index == -1)
	{
		cout << "Can't find pair with this name\n";
	}
	else
	{
		_names[index] = "";
		delete _cases[index];
		_cases[index] = nullptr;
	}
}

void Interface::PrintShape() const
{
	string name;
	cout << "Enter name of pair to print\n>> ";
	cin >> name;
	int index = GetIndex(name);
	if (index != -1)
	{
		cout << _cases[index]->ToString() << "\n";
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void Interface::DelShape() const
{
	string name;
	cout << "Enter name of pair to delete\n>> ";
	cin >> name;
	DeleteShape(name);
	cout << "Complete\n";
}

void Interface::Compare() const
{
	Operators operators;
	string name, name2;
	cout << "Enter name of first shape\n>> ";
	cin >> name;
	cout << "Enter name of second shape\n>> ";
	cin >> name2;
	int indexName1 = GetIndex(name);
	int indexName2 = GetIndex(name2);
	if (indexName1 != -1 && indexName2 != -1)
	{
		switch (operators.Compare(*_cases[indexName1], *_cases[indexName2]))
		{
		case 1:
			cout << "First shape larger than second\n";
			break;
		case -1:
			cout << "Second shape larger than first\n";
			break;
		case 0:
			cout << "Shapes have the same area\n";
			break;
		}
	}
	else
	{
		cout << "Wrong name\n";
	}
}


void Interface::GetArea() const
{
	string name;
	cout << "Enter name of shape\n>> ";
	cin >> name;
	int indexName1 = GetIndex(name);
	if (indexName1 != -1)
	{
		cout << "Area of this shape is " << _cases[indexName1]->GetArea() << "\n";
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void Interface::GetCenter() const
{
	string name;
	cout << "Enter name of shape\n>> ";
	cin >> name;
	int indexName1 = GetIndex(name);
	if (indexName1 != -1)
	{
		Point center = _cases[indexName1]->GetCenter();
		cout << "Center of this shape: x = " << center.x << " y = " << center.y << "\n";
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void Interface::IsIntersect() const
{
	Operators operators;
	string name, name2;
	cout << "Enter name of first shape\n>> ";
	cin >> name;
	cout << "Enter name of second shape\n>> ";
	cin >> name2;
	int indexName1 = GetIndex(name);
	int indexName2 = GetIndex(name2);
	if (indexName1 != -1 && indexName2 != -1)
	{
		if (operators.Intersect(*_cases[indexName1], *_cases[indexName2]))
		{
			cout << "Shapes intersect\n";
		}
		else
		{
			cout << "Shapes don't intersect\n";
		}
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void Interface::IsInclude() const
{
	Operators operators;
	string name, name2;
	cout << "Enter name of first shape\n>> ";
	cin >> name;
	cout << "Enter name of second shape\n>> ";
	cin >> name2;
	int indexName1 = GetIndex(name);
	int indexName2 = GetIndex(name2);
	if (indexName1 != -1 && indexName2 != -1)
	{
		if (operators.Include(*_cases[indexName1], *_cases[indexName2]))
		{
			cout << "Shapes is Include\n";
		}
		else
		{
			cout << "Shapes doesn`t include\n";
		}
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void Interface::Init() const
{
	bool flag = true;
	while (flag)
	{
		char code;
		cout << "Enter \"3\" - Help\n";
		cout << ">> ";
		cin >> code;

		switch (code)
		{
		case '1':
			CreateShape();
			break;
		case '2':
			DelShape();
			break;
		case '3':
			Help();
			break;
		case '4':
			Compare();
			break;
		case '5':
			IsIntersect();
			break;
		case '6':
			IsInclude();
			break;
		case '7':
			PrintShape();
			break;
		case '8':
			GetArea();
			break;
		case '9':
			GetCenter();
			break;
		case '-' :
			Rotate();
			break;
		case '=' :
			Move();
			break;
		default:
			cout << "Wrong command!\n";
			break;
		case '0':
			flag = false;
			break;
		}
	}
}