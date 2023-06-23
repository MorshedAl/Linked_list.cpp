#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class node
{
public:

    int data;
    node *next;

}*head=0,*newnode,*temp;

/*
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

*/
void display(node*temp)
{
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



int count(node*temp)
{   int l=0;
    while(temp!=0)
    {
        l++;
        temp=temp->next;

    }
    return l;
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
}



int main()
{
    // int A[]= {10,15,20};
    // create(A,3);


    insert_any_pos(head,0,5);

    insert_any_pos(head,1,10);
    insert_any_pos(head,2,15);
    insert_any_pos(head,0,3);
    insert_any_pos(head,4,20);
    insert_any_pos(head,3,20);
    display(head);
  
     insert_any_pos(head,15,35);
     display(head);







    return 0;
}


