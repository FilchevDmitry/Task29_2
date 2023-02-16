#include <iostream>

class Shape
{
protected:
	struct BoundingBoxDimension
	{
		double width = 0;
		double length = 0;
	};
		
public:
	
	
	virtual double square() = 0;
	virtual BoundingBoxDimension dimensions() = 0;

};
class Circle : public Shape
{

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
