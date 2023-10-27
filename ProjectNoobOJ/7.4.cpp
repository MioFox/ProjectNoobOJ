#include<iostream>
#include<cmath>
constexpr auto M_PI = 3.14159265;
using namespace std;

class Shape {
public:
	Shape(){}
	~Shape(){}
	virtual double getArea() const = 0;
	virtual double getPerim() const = 0;
private:
};

class Rectangle :public Shape {
public:
	Rectangle(double _length,double _width):length(_length),width(_width){}
	~Rectangle(){}
	double getArea()const { return length * width; }
	double getPerim()const { return 2 * (length + width); }
private:
	double length;
	double width;
};

class Circle :public Shape {
public:
	Circle(double _radius):radius(_radius){}
	~Circle(){}
	double getArea()const { return radius * radius * M_PI; }
	double getPerim()const { return 2 * M_PI * radius; }
private:
	double radius;
};

int main()
{
	Rectangle* rec = new Rectangle(2, 3);
	Circle* cir = new Circle(3);
	cout << rec->getArea() << endl;
	cout << rec->getPerim() << endl;
	cout << cir->getArea() << endl;
	cout << cir->getPerim() << endl;
	return 0;
}