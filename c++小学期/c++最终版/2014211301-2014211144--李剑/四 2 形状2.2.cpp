/*�� 2 ��2����״2.2*/
#include<iostream>
#include<stdlib.h>
#define PI 3.14159
using namespace std;

//����һ���������Shape�����а���һ���������������
class Shape{
	public:
		virtual double Area()=0; 
		Shape(double m,double n);
		~Shape(){
			cout<<endl<<"���ǻ������������\n";
		};
	protected:
		double x,y;	
};
Shape::Shape(double m,double n)
{
	x=m;
	y=n;
	cout<<endl<<"���ǻ���Ĺ��캯��\n";
}
class Rec:public Shape{
	public:
		double Area(){
			return x*y;
		}
		Rec(double m,double n):Shape(m,n){
			cout<<endl<<"���Ǿ��εĹ��캯��\n";
		};
		~Rec(){
			cout<<endl<<"���Ǿ��ε���������"<<endl; 
		};
}; 
class Circle:public Shape{
	public:
		double Area(){
			return x*x*PI;
		};
		Circle(double m,double n):Shape(m,n){
			cout<<endl<<"����Բ�εĹ��캯��\n";
		};
		~Circle(){
			cout<<endl<<"����Բ����������"<<endl; 
		};
};

class Square:public Rec{
	public:
		Square(double ch,double ku):Rec(ch,ku){
			cout<<endl<<"���������εĹ��캯��"<<endl; 
		};
		~Square();
		double Area(){
			return x*x;
		}
};
Square::~Square(){
	cout<<endl<<"���������ε���������"<<endl; 
}
int main(void)
{
	double chang,kuan;
	cout<<"��������εĳ��Ϳ�";
	cin>>chang>>kuan; 
	Rec a(chang,kuan);
	cout<<"���ε�����ǣ�"<<a.Area()<<endl;
	cout<<"������Բ�İ뾶�������εı߳���";
	cin>>chang>>kuan;//��chang��ʾԲ�İ뾶  kuan��ʾ�����εı߳� 
	Circle b(chang,chang);
	Square c(kuan,kuan);
	cout<<"Բ������ǣ�"<<b.Area()<<endl; 
	cout<<"�����ε�����ǣ�"<<c.Area()<<endl; 
	
	system("pause");
	return 0;
}
