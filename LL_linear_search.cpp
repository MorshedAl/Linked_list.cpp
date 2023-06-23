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
//iterative way
node* search(node*temp,int key)
{
    while(temp!=0)
    {   if(temp->data==key)
            return temp;

        temp=temp->next;

    }
    return NULL;
}


// recursive way
node* R_search(node*temp,int key)
{   if(temp==0)
        return NULL;

    if(temp->data==key)
        return temp;

    return R_search(temp->next,key);


}
*/

// iterative linear search

node* linear_search(node*temp,int key)
{

    while(temp!=0)
    {
        if(key==temp->data)
            return temp;

        temp=temp->next;
    }

    return NULL;
}

// recursive linear search

node* R_search(node*temp,int key)
{
    if(temp==0)
        return NULL;

    if(temp->data==key)
        return temp;

    return R_search(temp->next,key);
}

// move_to_front

void  move_to_front(node*temp,int key)
{   node*back;
    while(temp!=0)
    {
        if(key==temp->data)
        {   back->next=temp->next;
            temp->next=head;
            head=temp;

        }

        back=temp;
        temp=temp->next;
    }

}




int main()
{
    int A[]= {45,10,99,15,20,25,30,2};

    create(A,8);

    display(head);
    cout<<endl;

    cout<< linear_search(head,25)<<endl;

    cout<< linear_search(head,7)<<endl;

    cout<<R_search(head,25)<<endl;

    cout<<R_search(head,7)<<endl;
    move_to_front(head,25);
    display(head);

    return 0;
}


