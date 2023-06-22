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

void display(node*temp)
{
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


// iterative way:
int count(node *temp)
{
    int l=0;

    while(temp)
    {
        l++;
        temp=temp->next;

    }
    return l;
}


// recursive way-1:
int R_count_1(node*temp)
{
    if(temp==0)
        return 0;
    else
        return R_count_1(temp->next)+1;
    //return 1+R_count(temp->next);

}



//recursive way-2:
int R_count_2(node*temp)
{   if(temp!=0)
        return R_count_2(temp->next)+1;
    else
        return 0;

}

// recursive way-3:
int R_count_3(node*temp)
{
    int x=0;

    if(temp==0)
        return 0;
    else
    {   x=R_count_3(temp->next);
        return x+1;
    }

}

int add(node*temp)
{   int sum=0;
    while(temp!=0)
    {
        sum=sum+temp->data;
        temp=temp->next;

    }
    return sum;
}

int R_add(node*temp)
{
    if(temp==0)
        return 0;
    else
        return R_add(temp->next)+temp->data;


}




int main()
{
    int A[]= {5,10,15,20,25,30};

    create(A,6);

    display(head);

    cout<<"\niterative:count="<<count(head)<<endl;


    cout<<"\nRecursive:count_1="<<R_count_1(head)<<endl;
    cout<<"Recursive:count_2="<<R_count_2(head)<<endl;
    cout<<"Recursive:count_3="<<R_count_3(head)<<endl;


    cout<<"iterative:sum="<<add(head)<<endl;
    cout<<"recursive:sum="<<R_add(head)<<endl;

    return 0;
}