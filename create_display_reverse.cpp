#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node*next;
}*head,*temp,*newnode;

void create(int A[],int n)
{   head=0;

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


void display(node*temp)
{
    while(temp!=0)
    {
        cout<<temp->data<<" ";

        temp=temp->next;
    }
    cout<<endl;
}

// reverse print
void R_display(node*temp)
{
   if(temp!=0)
   {
     R_display(temp->next);
     cout<<temp->data<<" ";
    }


}



int main()
{  
  int A[]= {4,7,2,9,10,6,8};

    create(A,7);

    display(head);

    R_display(head);

    return 0;
}