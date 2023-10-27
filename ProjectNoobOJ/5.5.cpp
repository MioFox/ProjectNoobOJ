#include<iostream>
#include<cmath>
using namespace std;

class Point {
public:
	double x, y;
	void getX(double xx)
	{
		x = xx;
	}
	void getY(double yy)
	{
		y = yy;
	}
	void getXY(double xx, double yy)
	{
		x = xx;
		y = yy;
	}
};

int main()
{
	Point vector[5];
	double sum = 0;
	cout << "please enter the five point";
	for (int i = 0; i < 5; i++)
	{
		double x, y;
		cin >> x >> y;
		vector[i].getXY(x, y);
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 5 - i; j++)
		{
			sum += sqrt(pow((vector[i].x - vector[j].x) , 2 )+ pow((vector[i].y - vector[j].y) ,2));
		}
	}
	cout << sum << endl;
	return 0;
}