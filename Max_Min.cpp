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


int maxi(node *temp)
{
  int maxx=INT_MIN;
    while(temp!=0)
    {
        if(temp->data>maxx)
        {
            maxx=temp->data;
        }

        temp=temp->next;
    }
    return maxx;
}


int R_maxi(node*temp)
{   int x=0;
    if(temp==0)
        return INT_MIN;

    else
    {   x=R_maxi(temp->next);
        if(x>temp->data)
            return x;
        else
            return temp->data;
    }

}


int R_maxi_2(node*temp)
{
    int x=0;

    if(temp==0)
        return INT_MIN;

    x=R_maxi(temp->next);
    return x>temp->data?x:temp->data;


}


int mini(node*temp)
{   int x=INT_MAX;
    while(temp!=0)
    {   if(x>temp->data)
            x=temp->data;
        temp=temp->next;
    }
    return x;
}


int R_mini(node*temp)
{
    int x=0;
    if(temp==0)
        return INT_MAX;

    else
    {   x=R_mini(temp->next);
        if(temp->data>x)
            return x;
        else
            return temp->data;
    }



}


int main()
{
    int A[]= {45,10,99,15,20,25,30,2};

    create(A,8);

    display(head);
    cout<<endl;
  cout<<"max="<<maxi(head)<<endl;

    cout<<"R_max="<<R_maxi(head)<<endl;

    cout<<"R_max2="<<R_maxi_2(head)<<endl;


    cout<<"min="<<mini(head)<<endl;
    cout<<"R_min="<<R_mini(head)<<endl;


    return 0;
}
