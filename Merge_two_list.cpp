#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int data1,data2,data;
	struct Node *next1,*next2,*next;
};
typedef struct Node node;
node *start1=NULL;
node *start2=NULL;
node *start3=NULL;

int count1=0,count2=0;


node *createnode1();

node *createnode2();

void printmenu();
void insertstart1();
void insertend1();
void traverse1();
void insertstart2();
void insertend2();
void traverse2();
void merge();

int main()
{
	
	int choice;
	while(1)
	{	
	
	printmenu();
	cout<<"enter your choice=";
	cin>>choice;
	cout<<endl<<endl;
	
	switch(choice)
	{
		case 1: insertstart1();
		break;
		
		case 2: insertend1();
		break;
		
		case 3: insertstart2();
		break;
		
		case 4 : insertend2();
		break;
		
		case 5 : traverse1();
		break;
		
		case 6: traverse2();
		break;
		
		case 7: merge();
		break;
		
		case 8: cout<<".......end....."<<endl;
		 return 0;
	}
}
return 0;
}

void printmenu()
{
	cout<<endl<<"1 for insert at start in first list"<<endl;
	cout<<"2 for insert at end in first list"<<endl;
	cout<<"3 for insert at start in second list"<<endl;
	cout<<"4 for insert at end in second list"<<endl;
	cout<<"5 display element of first list"<<endl;
	cout<<"6 for display element of second list"<<endl;
	cout<<"7 merge list"<<endl;
	cout<<"8 for end..."<<endl<<endl;
}


node *createnode1()
{
	int temp;
	cout<<"enter the element=";
	cin>>temp;
	node *newnode= (node *)malloc(sizeof (node));
	newnode->data1=temp;
	newnode->next1=NULL;
	 
return newnode;
}

node *createnode2()
{
	int temp;
	cout<<"enter the element=";
	cin>>temp;
	node *newnode= (node *)malloc(sizeof (node));
	newnode->data2=temp;
	newnode->next2=NULL;
	 
return newnode;
}


void insertstart1()
{
	count1++;
   node	*newnode=createnode1();
   newnode->next1=start1;
   start1=newnode;
   cout<<"node is inserted"<<endl;
}

void insertend1()
{
	count1++;
	node *newnode=createnode1();
	node *p=start1;
	if(start1==NULL)
	{
		start1=newnode;
	}
	else
	{
		while(p->next1!=NULL)
		{
			p=p->next1;
		}
		p->next1=newnode;
	}
	cout<<"node is inserted"<<endl;
}

void traverse1()
{
	if(start1==NULL)
	{
		cout<<"list 1 is empty"<<endl;
	}
	else
	{
		cout<<"list==";
		node *temp=start1;
		do
		{
			cout<<temp->data1<<"  ";
			temp=temp->next1;
		}while(temp!=NULL);
		cout<<endl;
	}
}


void insertstart2()
{
	count2++;
   node	*newnode=createnode2();
   newnode->next2=start2;
   start2=newnode;
   cout<<"node is inserted"<<endl;
}

void insertend2()
{
	count2++;
	node *newnode=createnode2();
	node *p=start2;
	if(start2==NULL)
	{
		start2=newnode;
	}
	else
	{
		while(p->next2!=NULL)
		{
			p=p->next2;
		}
		p->next2=newnode;
	}
	cout<<"node is inserted"<<endl;
}

void traverse2()
{
	if(start2==NULL)
	{
		cout<<"list 2 is empty"<<endl;
	}
	else
	{
		cout<<"list==";
		node *temp=start2;
		do
		{
			cout<<temp->data2<<"  ";
			temp=temp->next2;
		}while(temp!=NULL);
		cout<<endl;
	}
}

void merge()
{
	if(start1==NULL)
	{
	traverse2();	
	}
	else if(start2==NULL)
	{
		traverse1();
	}
	else
	{
		start3=start1;
		node *temp1=start1;
		node *temp2=start2;
		node *temp1n,*temp2n;
		while(temp1!=NULL&&temp2!=NULL)
		{
		temp1n=temp1->next1;
		temp2n=temp2->next2;
		temp2->next2=temp1n;
		temp1->next1=temp2;
		temp1=temp1n;
		temp2=temp2n;
			
		}
		start2=temp2;
	}
	node *a=start1;
	while(a!=NULL)
	{
		cout<<" "<<a->data<<"  ";
		a=a->next;
			}
	
}
