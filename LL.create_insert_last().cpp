#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node*next;
}*head=0,*newnode,*tail;


void insert_last(int val)
{
    newnode=new node;
    newnode->data=val;
    newnode->next=0;

    if(head==0)
    {
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }


}

void display(node*temp)
{
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main()
{   insert_last(5);

    insert_last(15);
    insert_last(50);
    insert_last(25);
    insert_last(75);

    display(head);
    return 0;
}