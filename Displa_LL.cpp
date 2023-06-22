#include<iostream>
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

//iterative way
void display(node*temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";

        temp=temp->next;

    }
    cout<<endl;
}

// recursive way
void Rdisplay(node*temp)
{
    if(temp!=0)
    {
        cout<<temp->data<<" ";
        Rdisplay(temp->next);

    }
    
}

// reverse print
void r_display(node*temp)
{
    if(temp!=0)
    {
        r_display(temp->next);
        cout<<temp->data<<" ";
    }
}


int main()
{
    int A[]= {5,10,15,20,25,30};

    create(A,6);
    cout<<"iterative way:\n";
    display(head);

    cout<<"recursive way:\n";
    Rdisplay(head);

    cout<<"\nreverse print:\n";
        r_display(head);

    return 0;
}