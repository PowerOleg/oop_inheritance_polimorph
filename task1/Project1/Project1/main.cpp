#include <iostream>

class Figure
{
protected:
	int sides;
public:
	Figure()
	{
		sides = 0;
	}

	int getSides()
	{
		return this->sides;
	}
};

class Triangle: public Figure
{
public:
	Triangle()
	{
		sides = 3;
	}
};

class Quadrangle: public Figure
{
public:
	Quadrangle()
	{
		sides = 4;
	}
};


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	Figure fig;
	Triangle tri;
	Quadrangle quad;
	std::cout << "Количество сторон: " << std::endl << "Фигура: " << fig.getSides() << std::endl;
	std::cout << "Треугольник: " << tri.getSides() << std::endl;
	std::cout << "Четырёхугольник: " << quad.getSides() << std::endl;
	return 0;
}