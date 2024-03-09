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
protected:
	int side_a;
	int side_b;
	int side_c;
	int angle_a;
	int angle_b;
	int angle_c;
public:
	Triangle()
	{
		this->sides = 3;
		this->name = "Треугольник";
	}
};

class Quadrangle: public Figure
{
protected:
	int side_d;
	int angle_d;
public:
	Quadrangle()
	{
		this->sides = 4;
		this->name = "Четырехугольник";
	}
};

void print_info(Figure* figure)
{

}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	Figure fig;
	Triangle tri;
	Quadrangle quad;
	std::cout << "Количество сторон: " << std::endl << fig.getName() << ": " << fig.getSides() << std::endl;
	std::cout << tri.getName() << ": " << tri.getSides() << std::endl;
	std::cout << quad.getName() << ": " << quad.getSides() << std::endl;
	return 0;
}