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

int count(node*temp)
{
    int l=0;
    while(temp!=0)
    {   l++;

        temp=temp->next;
    }
    return l;
}




int Delete(node*temp,int pos)
{   int x=-1;
    node *back=NULL;
  
    //invalid position
    if(pos<1 || pos>count(head))
    {
        cout<<"invalid position!\n";
        return -1;
    }
    // first node delete করলে
    if(pos==1)
    {
        temp=head;
        head=head->next;
      
        x=temp->data;
        delete temp;
        return x;
    }
    else // অন্য যেকোন pos এর  node delete করলে
    {

        for(int i=0; i<pos-1; i++)
        {
            back=temp;
            temp=temp->next;
        }
        
        back->next=temp->next;
        x=temp->data;
        delete temp;
        return x;


    }



}




void display(node*temp)
{

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}






int main()
{
    int A[]= {5,10,15,15,20,25,25};

    create(A,7);

    display(head);

    Delete(head,0); // invalid position 
    display(head);
    
    Delete(head,1); // delete first node
    display(head);
    
    Delete(head,5); // delete any pos node
    display(head);
    
    
    

    return 0;
}