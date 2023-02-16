#include <iostream>

class Shape
{
protected:
	struct BoundingBoxDimension
	{
		double width;
		double length;
	};
	std::string typeShape;
	
public:
	
	virtual double square() = 0;
	virtual BoundingBoxDimension dimensions() = 0;
	virtual std::string type() = 0;
	void printParams(Shape* shape)
	{
		std::cout << "Type: " << shape->type() << std::endl;

	}
};
class Circle : virtual public Shape
{
private:
	double radius;
public:
	Circle(double inRadius):radius(inRadius)
	{
		typeShape = "Circle";
	}
	virtual std::string type()
	{
		return typeShape;
	}
	virtual BoundingBoxDimension dimensions()
	{
		
	}
};
class Rectangle :public Shape
{

};
class Triangle :public Shape
{

};

int main()
{
	
	return 0;
}
