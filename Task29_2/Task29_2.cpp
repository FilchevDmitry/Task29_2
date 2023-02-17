#include <iostream>

class Rectangle;
class Shape
{
protected:
	struct BoundingBoxDimension
	{
		double Width;
		double Length;
	};
	std::string typeShape;
	
public:
	
	virtual double square() = 0;
	virtual BoundingBoxDimension dimensions() = 0;
	virtual std::string type() = 0;
	virtual void getRectangle() = 0;
	void printParams(Shape* shape)
	{
		std::cout << "Type: " << shape->type() << std::endl;
		std::cout << "Square: " << shape->square() << std::endl;
		std::cout << shape->getRectangle() << std::endl;
	}
};
class Circle : virtual public Shape
{
private:
	double radius;
	double Pi = 3.14;
public:
    BoundingBoxDimension dimensions;
	Circle(double inRadius):radius(inRadius)
	{
		typeShape = "Circle";
	}
	virtual std::string type()
	{
		return typeShape;
	}
	virtual double square()
	{
		return Pi * (radius * radius);
	}
	virtual void getRectangle()
	{
	
	}
};
class Rectangle :public Shape
{
private:

public:
	BoundingBoxDimension dimensions;
	Rectangle() {}
	Rectangle(double& inWidth, double& inHeight)
	{
		dimensions.Width = inWidth;
		dimensions.Length = inHeight;
	}

};
class Triangle :public Shape
{

};

int main()
{
	
	return 0;
}
