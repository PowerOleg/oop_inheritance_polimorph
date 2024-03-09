#include <iostream>

class Figure
{
protected:
	int sides;
	std::string name;
public:
	Figure()
	{
		this->sides = 0;
		this->name = "Фигура";
	}

	int getSides()
	{
		return this->sides;
	}

	std::string getName()
	{
		return this->name;
	}
};

class Triangle: public Figure
{
public:
	Triangle()
	{
		this->sides = 3;
		this->name = "Треугольник";
	}
};

class Quadrangle: public Figure
{
public:
	Quadrangle()
	{
		this->sides = 4;
		this->name = "Четырехугольник";
	}
};


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	Figure fig;
	Triangle tri;
	Quadrangle quad;
	std::cout << "Количество сторон: " << std::endl << fig.getName() <<": " << fig.getSides() << std::endl;
	std::cout << tri.getName() << ": " << tri.getSides() << std::endl;
	std::cout << quad.getName() << ": " << quad.getSides() << std::endl;
	return 0;
}