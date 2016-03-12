/*二.1矩形*/ 
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

//定义一个Point类，其属性包括点的坐标，提供计算两点之间距离的方法； 
class Point{
	public:
		double dis(const Point & p) const{
			 return sqrt((xVal-p.xVal)*(xVal-p.xVal)+(yVal-p.yVal)*(yVal-p.yVal));
		}
		double getX(){ return xVal; };		//得到x坐标 
		double getY(){ return yVal; };		//得到y坐标 
		Point(double x,double y);			//构造函数 
		~Point();							//析构函数 
	private:
		double xVal;
		double yVal;	
}; 
Point::~Point(){}
Point::Point(double x=0,double y=0)//构造函数 默认为零 
{
	xVal=x;
	yVal=y;
}
//定义一个矩形类，其属性包括左上角和右下角两个点，提供计算面积的方法
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
	int islegal(0);//检查输入是否合法
	while(islegal==0)
	{
		cout<<"请输入左上角的坐标(用空格隔开)：";
		cin>>x>>y;
		cout<<"请输入右下角的坐标(用空格隔开)："; 
		cin>>s>>t;
		if(x<s && y>t)//判断用户输入合法 
			islegal=1;
		else
			cout<<"输入不合法请重新输入\n";
	}
	
	Point l(x,y),r(s,t);
	cout<<"这两点之间的距离是："<<l.dis(r)<<endl;

	recTangle rec(l,r);

	cout<<"矩形的面积是:"<<rec.calArea()<<endl;
	system("pause");
	return 0;
} 
