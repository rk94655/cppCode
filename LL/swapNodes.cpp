#include<iostream>
using namespace std;

class node{
public:
	int data; node*next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};
void insertAtHead(node*&head, int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node*temp = new node(data);
	temp->next=head;
	head=temp;
}
int size(node*head)
{
	int len=0;
	while(head!=NULL)
	{
		len++;
		head=head->next;
	}
	return len;
}
void insertAtTail(node*&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node*temp = head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next = new node(data);
	
}
void insertInMiddle(node*&head, int data, int p)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	if(p>size(head))
	{
		insertAtTail(head,data);
		return;
	}
	node*temp = head;
	node*temp2 = new node(data);
	while(p-2!=0)
	{
		temp=temp->next;
		p--;
	}
	temp2->next = temp->next;
	temp->next = temp2;

}

void print(node *head)
{
	while(head!=NULL)
	{
		cout << head->data << "->";
		head=head->next;
	}
	cout <<endl;
}
void buildll(node*&head)
{
	int data;
	cin>>data;

	while(data!=-1)
	{
		insertAtTail(head,data);
		cin>>data;
	}
}

istream& operator>>(istream &is,node*&head)
{
	buildll(head);
	return is;
}

ostream& operator<<(ostream &os, node*head)
{
	print(head);
	return os;
}
void swapNodes(node*&head, int key1, int key2)
{
	node*temp=head,*prev1=NULL,*prev2=NULL,*node1=head,*node2=head,*prev=NULL;
	if(key1 == key2)
		return;
	while(node1 and node1->data!=key1)
	{
		prev1 = node1;
		node1 = node1->next;
	}

	while(node2 and node2->data!=key2)
	{
		prev2 = node2;
		node2 = node2->next;
	}
	if(node1==NULL || node2 == NULL)
		return;

	if(node1==head)
		head = node2;
	else
		prev1->next = node2;

	if(node2==head)
		head = node1;
	else
		prev2->next = node1;

	node *temp3= node1->next;
	node1->next = node2->next;
	node2->next = temp3;

}
int main()
{
	node* head=NULL;
	insertAtHead(head,3);
	insertAtHead(head,4);
	insertAtHead(head,5);
	insertAtHead(head,6);
	insertAtHead(head,7);
	insertAtHead(head,8);
	insertAtHead(head,9);
	print(head);
	swapNodes(head,3,9);
	print(head);
	return 0;
}