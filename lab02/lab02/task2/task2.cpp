#include "pch.h"
#include <iostream>
using namespace std;
float boo(float);
int main()
{
	cout << "Enter five numbers \n";
	float f1, f2, f3, f4, f5;
	cin >> f1 >> f2 >> f3 >> f4 >> f5;
	f1 = boo(f1);
	f2 = boo(f2);
	f3 = boo(f3);
	f4 = boo(f4);
	f5 = boo(f5);
	f1 = f1 * f3 - f2 / f4 + f4 * (f5 - f1) - f2;
	cout << f1;
}
float boo(float a)
{
	float y = (a * 2 - a + a * (a / 2)) / a / 5 ;
	return y;
}