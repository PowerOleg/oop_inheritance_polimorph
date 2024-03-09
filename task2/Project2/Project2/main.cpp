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

class Isosceles_triangle: public Triangle
{
public:
	Isosceles_triangle(int side_a, int side_b, int angle_a, int angle_b) : Triangle(side_a, side_b, side_a, angle_a, angle_b, angle_a)
	{
		this->name = "Равнобедренный треугольник";
	}
};

class Right_triangle: public Triangle
{
public:
	Right_triangle(int side_a, int side_b, int side_c, int angle_a, int angle_b) : Triangle(side_a, side_b, side_c, angle_a, angle_b, 90)
	{
		this->name = "Прямоугольный треугольник";
	}
};

class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle(int side_a, int angle_a) : Triangle(side_a, side_a, side_a, angle_a, angle_a, angle_a)
	{
		this->name = "Равносторонний треугольник";
	}
};

class Quadrangle: public Triangle
{
protected:
	int side_d;
	int angle_d;
public:
	Quadrangle(int side_a, int side_b, int side_c, int side_d, int angle_a, int angle_b, int angle_c, int angle_d) : Triangle(side_a, side_b, side_c, angle_a, angle_b, angle_c)
	{
		this->sides = 4;
		this->name = "Четырехугольник";
		this->side_d = side_d;
		this->angle_d = angle_d;
	}

	void print_side_values() override
	{
		std::cout << "Стороны: " << "a=" << side_a << " b=" << side_b << " c=" << side_c << " d=" << side_d << std::endl;
	}
	void print_angle_values() override
	{
		std::cout << "Углы: " << "A=" << angle_a << " B=" << angle_b << " C=" << angle_c << " D=" << angle_d << std::endl;
	}
};


class Rectangle: public Quadrangle
{
public:
	Rectangle(int side_a, int side_b) : Quadrangle(side_a, side_b, side_a, side_b, 90, 90, 90, 90)
	{
		this->name = "Прямоугольник";
	}
};












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
	Right_triangle* right_tri = new Right_triangle(10, 20, 30, 30, 60);
	Isosceles_triangle* iso_tri = new Isosceles_triangle(10, 20, 50, 80);
	Equilateral_triangle* eq_tri = new Equilateral_triangle(30, 60);

	print_info(tri);
	std::cout << std::endl;
	print_info(right_tri);
	std::cout << std::endl;
	print_info(iso_tri);
	std::cout << std::endl;
	print_info(eq_tri);
	std::cout << std::endl;


	Quadrangle* quad = new Quadrangle(10, 20, 30, 40, 50, 60, 125, 125);
	Rectangle* rectangle = new Rectangle(10, 20);

	print_info(quad);
	std::cout << std::endl;
	print_info(rectangle);
	std::cout << std::endl;


	delete tri;
	delete right_tri;
	delete iso_tri;
	delete eq_tri;
	delete quad;
	delete rectangle;
	return 0;
}