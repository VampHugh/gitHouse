/*�� 3��Ԫ*/
#include<iostream>
#include<cstdlib>
using namespace std;

//����һ��Boat��Car�����࣬���Ƕ�����˽������--����
class Car;//��ΪҪ��Boat�����ã������� 
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
//���캯�� 
Boat::Boat(double wet)
{
	weight=wet;
}
Car::Car(double wet)
{
	weight=wet;
}
//����Ԫ������������ 
double TotalWeight(Boat& b, Car& c)
{
	return (b.weight+c.weight);
}
int main (void)
{
	double car,boat;//���غʹ��� 
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
