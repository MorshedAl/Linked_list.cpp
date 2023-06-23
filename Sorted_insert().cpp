#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node*next;
}*head=0,*newnode,*temp;


void create(int A[],int n)
{
    for(int i=0; i<n; i++)
    {
        newnode=new node;
        newnode->data=A[i];
        newnode->next=0;


        if(head==0)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

}






void sorted_insert(node*temp,int val)
{
    node*back=NULL; // extra pointet

    newnode=new node;
    newnode->data=val;
    newnode->next=0;





    if(head==0) // যদি লিস্টে কোন element না থাকে।
    {   head=newnode;
        return;
    }
    else
    {

        while(temp && val>temp->data)
        {
            back=temp;
            temp=temp->next;
        }
        if(temp==head) //নতুন val<প্রথম val
        {
            newnode->next=head;
            head=newnode;

        }
        else
        {
            newnode->next=back->next;
            back->next=newnode;
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
    cout<<endl;
}


int main()
{  // int A[]= {5,10,15,20,25};//না থাকলে ও কাজ করবে
  //  create(A,5);// না থাকলে ও কাজ করবে
 //   display(head);
    
    sorted_insert(head,18);
    display(head);
    
    
    sorted_insert(head,3);
    display(head);
    
    
    sorted_insert(head,30);
    display(head);
    
    
    
    
    return 0;
}