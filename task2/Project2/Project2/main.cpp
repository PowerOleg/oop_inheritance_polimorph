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
	Triangle(int side_a, int side_b, int side_c, int angle_a, int angle_b, int angle_c)
	{
		this->sides = 3;
		this->name = "Треугольник";
		this->side_a = side_a;
		this->side_b = side_b;
		this->side_c = side_c;
		this->angle_a = angle_a;
		this->angle_b = angle_b;
		this->angle_c = angle_c;
		
	}

	virtual void print_side_values()
	{
		std::cout << "Стороны: " << "a=" << this->side_a << " b=" << this->side_b << " c=" << this->side_c << std::endl;
	}
	virtual void print_angle_values()
	{
		std::cout << "Углы: " << "A=" << this->angle_a << " B=" << this->angle_b << " C=" << this->angle_c << std::endl;
	}
};

class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle(int side_a, int side_b, int angle_a, int angle_b) : Triangle(side_a, side_b, side_a, angle_a, angle_b, angle_a)
	{
	}
};

/*class Quadrangle : public Triangle
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

	void print_side_values() override
	{
		std::cout << "Стороны: " << "a=" << side_a << "b=" << side_b << "c=" << side_c << "d=" << side_d << std::endl;
	}
	void print_angle_values() override
	{
		std::cout << "Углы: " << "A=" << angle_a << "B=" << angle_b << "C=" << angle_c << "D=" << angle_d << std::endl;
	}
};*/













void print_info(Triangle* figure)
{
	std::cout << figure->getName() << ": " << std::endl;
	figure->print_side_values();
	figure->print_angle_values();
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	Triangle* tri = new Triangle(10, 20, 30, 50, 60, 70);
	//Quadrangle* quad = new Quadrangle();
	Equilateral_triangle* eq_tri = new Equilateral_triangle(10, 20, 50, 60);
	print_info(tri);
	std::cout << std::endl;
	print_info(eq_tri);
	std::cout << std::endl;

	delete tri;
	delete eq_tri;
	return 0;
}