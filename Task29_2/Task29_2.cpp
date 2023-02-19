#include <iostream>
#include<cmath>
class Shape
{
protected:
	struct BoundingBoxDimension
	{
		double Width;
		double Length;
	};
	std::string typeShape;
	BoundingBoxDimension dim;
public:
	Shape()
	{

	}
	virtual double square() = 0;
	virtual BoundingBoxDimension dimensions() = 0;
	virtual std::string type() = 0;
	void printParams(Shape* shape)
	{
		std::cout << "Type: " << shape->type() << std::endl;
		std::cout << "Square: " << shape->square() << std::endl;
		dim=shape->dimensions();
		std::cout << "Width : " << dim.Width << std::endl;
		std::cout << "Length : " << dim.Length << std::endl;
	}
};
class Circle : public Shape
{
private:
	double radius;
	double Pi = 3.14;
public:
	
	Circle(double inRadius):radius(inRadius)
	{
		typeShape = "Circle";
	}
	std::string type()
	{
		return typeShape;
	}
	double square()
	{
		return Pi * (radius * radius);
	}
	BoundingBoxDimension dimensions()
	{
		dim.Length = 2 * radius;
		dim.Width = dim.Length;
		return dim;
	}
	
};
class Rectangle :public Shape
{
private:
	double width = 0;
	double length = 0;
public:
	Rectangle(double inWidth, double inLength) :width(inWidth), length(inLength)
	{
		typeShape = "Rectangle";
	}
	std::string type()
	{
		return typeShape;
	}
	double square()
	{
		return width*length;
	}
	BoundingBoxDimension dimensions()
	{
		dim.Length = 1+length;
		dim.Width = 1+width;
		return dim;
	}
};
class Triangle :public Shape
{
private:
	double sideA = 0;
	double sideB = 0;
	double sideC = 0;
public:
	Triangle(double inA, double inB, double inC) :sideA(inA), sideB(inB), sideC(inC)
	{
		typeShape = "Triangle";
	}
	std::string type()
	{
		return typeShape;
	}
	double square()
	{
		double p = (sideA + sideB + sideC) / 2;
		double squareTriangle = std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
		return squareTriangle;
	}
	
	BoundingBoxDimension dimensions()
	{
		double p = (sideA + sideB + sideC) / 2;
		dim.Width=2*((sideA * sideB * sideC) / (4 * std::sqrt(p * (p - sideA) * (p - sideB) * (p - sideC))));
		dim.Length = dim.Width;
		return dim;
	}
};

int main()
{
	Circle c(5);
	c.printParams(&c);
	Rectangle r(10, 10);
	r.printParams(&r);
	Triangle t(3, 4, 5);
	t.printParams(&t);
	return 0;
}
