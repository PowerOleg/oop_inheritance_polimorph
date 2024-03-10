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

	virtual void print_info()
	{
		std::cout << this->getName() << ": " << std::endl;
		if (this->check())
		{
			std::cout << "Правильная" << std::endl; 
		}
		else
		{
			std::cout << "Неправильная" << std::endl;
		}
		
		std::cout << "Количество сторон: " << this->getSides() << std::endl;
	}

	virtual bool check()
	{
		return this->sides == 0;
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

	bool check() override
	{
		return this->getSides() == 3 && this->getSides() * 60 == this->angle_a + this->angle_b + this->angle_c;
	}

	void print_info() override
	{
		Figure::print_info();
		print_side_values();
		print_angle_values();
	}
};

class Right_triangle : public Triangle
{
public:
	Right_triangle(int side_a, int side_b, int side_c, int angle_a, int angle_b) : Triangle(side_a, side_b, side_c, angle_a, angle_b, 90)
	{
		this->name = "Прямоугольный треугольник";
	}

	bool check() override
	{
		return Triangle::check() && this->angle_c == 90;
	}
};

class Isosceles_triangle : public Triangle
{
public:
	Isosceles_triangle(int side_a, int side_b, int angle_a, int angle_b) : Triangle(side_a, side_b, side_a, angle_a, angle_b, angle_a)
	{
		this->name = "Равнобедренный треугольник";
	}

	bool check() override
	{
		return Triangle::check() && this->side_a == this->side_c && this->angle_a == this->angle_c;
	}
};

class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle(int side_a, int angle_a) : Triangle(side_a, side_a, side_a, angle_a, angle_a, angle_a)
	{
		this->name = "Равносторонний треугольник";
	}

	bool check() override
	{
		return Triangle::check() && this->side_a == this->side_b && this->side_a == this->side_c && this->angle_a == this->angle_b && this->angle_a == this->angle_c;
	}
};

class Quadrangle : public Triangle
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

	bool check() override
	{
		return this->getSides() == 4 && this->getSides() * 90 == this->angle_a + this->angle_b + this->angle_c + this->angle_d;
	}

};

class Rectangle : public Quadrangle
{
public:
	Rectangle(int side_a, int side_b) : Quadrangle(side_a, side_b, side_a, side_b, 90, 90, 90, 90)
	{
		this->name = "Прямоугольник";
	}

	bool check() override
	{
		return Quadrangle::check() && this->side_a == this->side_c && this->side_b == this->side_d && this->angle_a == this->angle_c && this->angle_b == this->angle_d;
	}
};

class Square : public Quadrangle
{
public:
	Square(int side_a) : Quadrangle(side_a, side_a, side_a, side_a, 90, 90, 90, 90)
	{
		this->name = "Квадрат";
	}

	bool check() override
	{
		return Quadrangle::check() && this->side_a == this->side_b && this->side_a == this->side_c && this->angle_a == this->angle_b && this->angle_a == this->angle_c;
	}
};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int side_a, int side_b, int angle_a, int angle_b) : Quadrangle(side_a, side_b, side_a, side_b, angle_a, angle_b, angle_a, angle_b)
	{
		this->name = "Параллелограмм";
	}

	bool check() override
	{
		return Quadrangle::check() && this->side_a == this->side_c && this->side_b == this->side_d && this->angle_a == this->angle_c && this->angle_b == this->angle_d;
	}
};

class Rhombus : public Quadrangle
{
public:
	Rhombus(int side_a, int angle_a, int angle_b) : Quadrangle(side_a, side_a, side_a, side_a, angle_a, angle_b, angle_a, angle_b)
	{
		this->name = "Ромб";
	}

	bool check() override
	{
		return Quadrangle::check() && this->side_a == this->side_b && this->side_a == this->side_c && this->angle_a == this->angle_c && this->angle_b == this->angle_d;
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	Figure* fig = new Figure();
	Triangle* tri = new Triangle(10, 20, 30, 50, 60, 70);
	Right_triangle* right_tri = new Right_triangle(10, 20, 30, 30, 60);
	Isosceles_triangle* iso_tri = new Isosceles_triangle(10, 20, 50, 80);
	Equilateral_triangle* eq_tri = new Equilateral_triangle(30, 60);
	Quadrangle* quad = new Quadrangle(10, 20, 30, 40, 50, 60, 125, 125);
	Rectangle* rectangle = new Rectangle(10, 20);
	Square* square = new Square(10);
	Parallelogram* parallelogram = new Parallelogram(10, 30, 150, 30);
	Rhombus* rhombus = new Rhombus(20, 20, 160);

	fig->print_info();
	std::cout << std::endl;
	tri->print_info();
	std::cout << std::endl;
	right_tri->print_info();
	std::cout << std::endl;
	iso_tri->print_info(); 
	std::cout << std::endl;
	eq_tri->print_info();
	std::cout << std::endl;
	quad->print_info();
	std::cout << std::endl;
	rectangle->print_info();
	std::cout << std::endl;
	square->print_info();
	std::cout << std::endl;
	parallelogram->print_info();
	std::cout << std::endl;
	rhombus->print_info();

	delete fig;
	delete tri;
	delete right_tri;
	delete iso_tri;
	delete eq_tri;
	delete quad;
	delete rectangle;
	delete square;
	delete parallelogram;
	delete rhombus;
	return 0;
}