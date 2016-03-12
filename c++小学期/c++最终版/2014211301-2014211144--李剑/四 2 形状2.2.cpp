/*四 2 （2）形状2.2*/
#include<iostream>
#include<stdlib.h>
#define PI 3.14159
using namespace std;

//声明一个抽象基类Shape，其中包含一个方法来计算面积
class Shape{
	public:
		virtual double Area()=0; 
		Shape(double m,double n);
		~Shape(){
			cout<<endl<<"这是基类的析构函数\n";
		};
	protected:
		double x,y;	
};
Shape::Shape(double m,double n)
{
	x=m;
	y=n;
	cout<<endl<<"这是基类的构造函数\n";
}
class Rec:public Shape{
	public:
		double Area(){
			return x*y;
		}
		Rec(double m,double n):Shape(m,n){
			cout<<endl<<"这是矩形的构造函数\n";
		};
		~Rec(){
			cout<<endl<<"这是矩形的析构函数"<<endl; 
		};
}; 
class Circle:public Shape{
	public:
		double Area(){
			return x*x*PI;
		};
		Circle(double m,double n):Shape(m,n){
			cout<<endl<<"这是圆形的构造函数\n";
		};
		~Circle(){
			cout<<endl<<"这是圆的析构函数"<<endl; 
		};
};

class Square:public Rec{
	public:
		Square(double ch,double ku):Rec(ch,ku){
			cout<<endl<<"这是正方形的构造函数"<<endl; 
		};
		~Square();
		double Area(){
			return x*x;
		}
};
Square::~Square(){
	cout<<endl<<"这是正方形的析构函数"<<endl; 
}
int main(void)
{
	double chang,kuan;
	cout<<"请输入矩形的长和宽：";
	cin>>chang>>kuan; 
	Rec a(chang,kuan);
	cout<<"矩形的面积是："<<a.Area()<<endl;
	cout<<"请输入圆的半径和正方形的边长：";
	cin>>chang>>kuan;//用chang表示圆的半径  kuan表示正方形的边长 
	Circle b(chang,chang);
	Square c(kuan,kuan);
	cout<<"圆的面积是："<<b.Area()<<endl; 
	cout<<"正方形的面积是："<<c.Area()<<endl; 
	
	system("pause");
	return 0;
}
