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
		this->name = "������";
		
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
		this->name = "�����������";
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
		this->name = "���������������";
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
	std::cout << "���������� ������: " << std::endl << fig.getName() << ": " << fig.getSides() << std::endl;
	std::cout << tri.getName() << ": " << tri.getSides() << std::endl;
	std::cout << quad.getName() << ": " << quad.getSides() << std::endl;
	return 0;
}