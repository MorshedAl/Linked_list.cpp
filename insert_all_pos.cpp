#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class node
{
public:

    int data;
    node *next;

}*head=0,*newnode,*temp;

void create(int A[],int n)
{
    for(int i=0; i<n; i++)
    {
        // memory allocation
        newnode=new node;

        // নতুন স্পেইস initialize
        newnode->data=A[i];
        newnode->next=NULL;

        // এখন কানেকশন লাগাতে হবে

        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
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


/*

count()
insert_at_beg()
insert_at_end()

insert_at_beg & after any position

create LL by insert(),insert(),insert()
*/



int count(node*temp)
{   int l=0;
    while(temp!=0)
    {
        l++;
        temp=temp->next;

    }
    return l;
}


void insert_at_beg(node*temp,int val)
{
    newnode=new node; // memory allocation

    newnode->data=val;    // initialize
    newnode->next=0;

    newnode->next=head; // link
    head=newnode;

cout<<endl;

}


void insert_at_end(node*temp,int val)
{
    while(temp->next!=0)
    {
        temp=temp->next;

    }

    newnode=new node;

    newnode->data=val;
    newnode->next=0;


    temp->next=newnode;

cout<<endl;
}


void insert_any_pos(node*temp,int pos,int val)
{

    if(pos<0 || pos>count(head))
    {
      cout<<"\ninvalid position!\n";
      return;
    }

    newnode=new node;
    newnode->data=val;
    newnode->next=0;


    if(pos==0)
    {
        newnode->next=head;
        head=newnode;
       
         cout<<endl;
    }
    else
    {
        for(int i=0; i<pos-1; i++)
        {
            temp=temp->next;
        }

        newnode->next=temp->next;
        temp->next=newnode;
    }

cout<<endl;
}



int main()
{
    int A[]= {10,15,20};

    create(A,3);

    display(head);
    
    count(head);

    insert_at_beg(head,5);// শুরুতে 
    display(head);

    insert_at_end(head,25);//শেষে
    display(head);

    insert_any_pos(head,0,3); //শুরুতে 
    display(head);
     
    insert_any_pos(head,2,55);//any_pos 
    display(head);
    
    insert_any_pos(head,7,30);// শেষে
    display(head);
    
    insert_any_pos(head,15,22);// pos বাইরে
    
    
    
    return 0;
}


