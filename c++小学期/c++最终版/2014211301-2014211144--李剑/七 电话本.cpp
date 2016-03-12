/*�绰��*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#define SIZE 100
using namespace std;

struct Contact{
	char name[10];//���� 
	char num[12];//�绰 
};
typedef struct Contact CON;

void WelcomeInterface(void);//���� 
void addNumber(void);//���Ӻ��� 
int seekNum(string na,int ifp);//���� 
void Showall(void);//��ӡ���е� 
int deleteNum();//ɾ����ϵ��
void GuanLi(void);//�绰�����Ա�����ָ���ļ��У��绰�ɱ���ָ���ļ��ж��뵽�ڴ� 

int main(void)
{
	char choice;//�����û���ѡ�� 
	string na;//���û���Ҫ���ҵ����� 
	
	while(1)
	{
		system("cls");
		WelcomeInterface();
		cin>>choice;
		if(choice=='0')//"0"��ʱ���˳����� 
			break;
		switch(choice)
		{
			//���� 
			case '1':
				system("cls");
				cout<<"Please input the name:";
				cin>>na;
				if(seekNum(na,1)!=1)
					cout<<"There is no such a person.\n";	
				
				break;
			//��� 
			case '2':
				addNumber();
				cout<<"Added successfully.\n";
				
				break;
			case '3'://ɾ�� 
				if(deleteNum()==1)
					cout<<"It has been done.\n";
				else
					cout<<"There may not exists the person.\n";	
				
				break;
			case '4'://��ӡ���д��ڵ� 
					Showall();
					break;
			case '5'://������м�¼ 
				{
					fstream file;
					file.open("data.dat",ios::binary | ios::out );
					file.close(); 
					if(file.fail())
						cout<<"�ļ���ʧ�ܡ�\n";
				}
				break;
			case '6'://�绰�����Ա�����ָ���ļ��У��绰�ɱ���ָ���ļ��ж��뵽�ڴ� 
				GuanLi();
				break;
			default:
		 		cout<<"Error input.Please choose from 0-6.\n";	
		 	fflush(stdin); 
		}
		system("pause");
	}
	system("cls");
	cout<<"Hope to serve you next time.\n";
	
	system("pause");
	return 0;
}
int deleteNum()
{
	fstream file;
	CON person,blankP={"",""};
	string na;
	CON people[SIZE];
	int i=0,j=0;
	
	system("cls");
	cout<<"Please input the person you want to delete:";
	cin>>na;
	if(seekNum(na,0)==0)//�Ȳ���һ�� 
		return 0;
	file.open("data.dat",ios::binary | ios::in);
	if(file.fail())
		cout<<"�ļ���ʧ�ܡ�\n";
	else
	{
		while(file.peek()!=EOF)
		{
			file.read((char*)&person,sizeof(CON));
			if(string(na)!=string(person.name))
			{
				strcpy(people[i].name,person.name);
				strcpy(people[i++].num,person.num);
			}	
		}
		file.close();
		file.open("data.dat",ios::binary | ios::out);
		if(file.fail())
						cout<<"�ļ���ʧ�ܡ�\n";
		else
		{
			while(j<i)
				file.write((char*)&people[j++],sizeof(CON));
		
			file.close();
			return 1;	
		} 
		return 0;
	}
	return 0;
}
int seekNum(string na,int ifp)
{
	CON person;
	ifstream file;

	file.open("data.dat",ios::binary);
	if(file.fail())
		cout<<"�ļ���ʧ�ܡ�\n";
	else
	{
		if(file)
		{
			while(file.peek()!=EOF)
			{
				file.read((char*)&person,sizeof(CON));
				if(string(na)==string(person.name))
				{
					if(ifp==1)
						cout<<"The phone number is "<<person.num<<endl;
					file.close();
					return 1;
				}	
			}
		}
	}
	fflush(stdin);
	return 0;
}
void addNumber(void)
{
	CON person={"",""},temp;
	fstream file;
	int n;//������ӵ����� 
	
	system("cls");
	file.open("data.dat",ios::binary | ios::out | ios::app);
	if(file.fail())
		cout<<"�ļ���ʧ�ܡ�\n";
	else
	{
		cout<<"How many people you want to add:";
		cin>>n;
		while(n)
		{
			cout<<"Please input the name:";
			cin>>person.name;
			if(seekNum(person.name,0)!=1)//�Ȳ���������������� 
			{
				n--;
				cout<<"Please input the number:";
				cin>>person.num;
				file.write((char*)&person,sizeof(CON));
			}
			else//��ʾ�Ѵ��� 
				cout<<"The people already exists!\n";
		}
		file.close();
	}
}
void WelcomeInterface(void)
{
	cout<<"		    Welcome to our phone book system~\n";
	cout<<"        ---------------------------------------------\n";
	cout<<"        |            1.Look up a number             |\n";
	cout<<"        |            2.Add a number                 |\n";	
	cout<<"        |            3.Delete a number              |\n";
	cout<<"        |            4.Print all the number         |\n";
	cout<<"        |            5.Empty the file(Carefully)    |\n";
	cout<<"        |            6.Management                   |\n";
	cout<<"        |            0.Exit                         |\n";
	cout<<"        ---------------------------------------------\n";
	cout<<"Please input your choice:";
} 
void Showall(void)//��ӡ��ǰ���е���Ϣ 
{	
	CON person;
	ifstream file;
	system("cls");
	
	file.open("data.dat",ios::binary);//���ļ� 
	if(file.fail())
						cout<<"�ļ���ʧ�ܡ�\n";
	else
	{
		cout<<setw(6)<<"name"<<setw(15)<<"number"<<endl;
		//������м�¼
		while(file.peek()!=EOF)
		{
			file.read((char*)&person,sizeof(CON));
			cout<<setw(6)<<person.name<<setw(15)<<person.num<<endl;
		}
		file.close();
	}
}
void GuanLi(void)
{
	ofstream f;
	fstream file;
	CON people[SIZE];
	char filename[SIZE];
	int i=0,j=0;
	
	system("cls");
	//���ļ���ļ�¼�����ڴ��� 
	file.open("data.dat",ios::binary | ios::in);
	if(file.fail())
		cout<<"�ļ���ʧ�ܡ�\n";
	else
	{
		while(file.peek()!=EOF)
			file.read((char*)&people[i++],sizeof(CON));
		file.close();
		//����¼�����ָ���ļ� 
		cout<<"Now the information is saved in the internal storage memory.\n";
		cout<<"Input the destination file's name:";
		cin>> filename;		strcat(filename,".txt");//������ָ������ 
		fflush(stdin);
		f.open(filename);
		while(j<i)
		{
			f.write((char*)&people[j],sizeof(CON));
			f.write("\n",1);
			j++;
		}
		f.close();
		cout<<"Now the file is saved.\n";
	}	
}
