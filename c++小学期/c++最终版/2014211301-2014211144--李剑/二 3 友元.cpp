/*二 3友元*/
#include<iostream>
#include<cstdlib>
using namespace std;

//定义一个Boat和Car两个类，他们都具有私用属性--重量
class Car;//因为要在Boat类里用，先声明 
class Boat
{
	friend double 
	TotalWeight(Boat& b, Car& c);
	public:
		Boat(double wet);
	private:
		double weight;
};
class Car
{
	friend double 
	TotalWeight(Boat& b, Car& c);
	public:
		Car(double wet);
	private:
		double weight;
}; 
//构造函数 
Boat::Boat(double wet)
{
	weight=wet;
}
Car::Car(double wet)
{
	weight=wet;
}
//用友元函数计算总重 
double TotalWeight(Boat& b, Car& c)
{
	return (b.weight+c.weight);
}
int main (void)
{
	double car,boat;//车重和船重 
	double sum;
	
	cout << "Please input the weight of car and boat(** **):";
	cin >> car >> boat;
	
	Car m(car);
	Boat n(boat);

	sum=TotalWeight(n,m);
	cout << "The totle weight is " << sum << "." << endl;

	system("pause");
	return 0;
}
