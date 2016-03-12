/*��.1����*/ 
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

//����һ��Point�࣬�����԰���������꣬�ṩ��������֮�����ķ����� 
class Point{
	public:
		double dis(const Point & p) const{
			 return sqrt((xVal-p.xVal)*(xVal-p.xVal)+(yVal-p.yVal)*(yVal-p.yVal));
		}
		double getX(){ return xVal; };		//�õ�x���� 
		double getY(){ return yVal; };		//�õ�y���� 
		Point(double x,double y);			//���캯�� 
		~Point();							//�������� 
	private:
		double xVal;
		double yVal;	
}; 
Point::~Point(){}
Point::Point(double x=0,double y=0)//���캯�� Ĭ��Ϊ�� 
{
	xVal=x;
	yVal=y;
}
//����һ�������࣬�����԰������ϽǺ����½������㣬�ṩ��������ķ���
class recTangle{
	public:
		double calArea();
		recTangle(Point l,Point r);
		~recTangle();
	private:
		Point leftUpper;
		Point rightLow;	
};
double recTangle::calArea()
{
	double dx,dy;
	double area;
	
	dy=leftUpper.getY()-rightLow.getY();
	dx=rightLow.getX()-leftUpper.getX();
	area=dx*dy;
	
	return area;
}
recTangle::recTangle(Point l,Point r)
{
	leftUpper=l;
	rightLow=r;
}
recTangle::~recTangle(){
}
int main(void)
{
	double x,y,s,t;
	int islegal(0);//��������Ƿ�Ϸ�
	while(islegal==0)
	{
		cout<<"���������Ͻǵ�����(�ÿո����)��";
		cin>>x>>y;
		cout<<"���������½ǵ�����(�ÿո����)��"; 
		cin>>s>>t;
		if(x<s && y>t)//�ж��û�����Ϸ� 
			islegal=1;
		else
			cout<<"���벻�Ϸ�����������\n";
	}
	
	Point l(x,y),r(s,t);
	cout<<"������֮��ľ����ǣ�"<<l.dis(r)<<endl;

	recTangle rec(l,r);

	cout<<"���ε������:"<<rec.calArea()<<endl;
	system("pause");
	return 0;
} 
