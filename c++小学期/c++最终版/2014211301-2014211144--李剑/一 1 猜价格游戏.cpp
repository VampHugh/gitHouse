/*�¼۸���Ϸ*/
#include<iostream>
#include<stdlib.h>
#include<ctime>
//#include<stdio.h>

using namespace std;

int main(void)
{
	char input[4]={0};//��������� 
	int price,hypos;
	int isleap=0,i=0;
	
	srand(time(NULL));
	price=(rand()%1000)+1;//�������һ���۸�1-1000�� 
	cout<<"������ԣ�������ȷ��"<<price<<endl;
    //��ʾ���� 
	cout << "Now there is a merchandise,it's price is between 1 and 1000.please guess the price of it." << endl;
	cout << "Price:";
	cin >> input;
	
	while(1)
	{
		isleap=0;
		while(input[i]!='\0')
		{
			//��������Ƿ�Ϸ� 
			if(input[i]<'0' || input[i]>'9' || atoi(input)>1000)
			{
				isleap=1;
				break;
			}
			i++;
		}
		i=0;
		if(isleap==0)//����Ϸ�
		{
			hypos=atoi(input);
			//�ж��û��µ��Ƿ���ȷ 
			if(hypos==price)//�¶��� 
			{
				cout << "God damn it,you are right now!"<<endl;
				break;
			}
			else
			{
				//���µĲ��Ե�ʱ�������ʵ�����ʾ 
				if(hypos<price)//�µĹ�С 
				{
					cout << "You should give a bigger number.\n";
					cout << "Price:";
					cin >> input;
				}
				else//�µĹ��� 
				{
					cout << "You should give a smaller number.\n";
					cout << "Price:";
					cin >> input;
				}
			}
		}
		else//���벻�Ϸ� 
		{
			cout << "Please input from 1 to 1000.\nPlease input again:";
			cin >> input;
		}
	}
	system("pause");
	return 0;
}
