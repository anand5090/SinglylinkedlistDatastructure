#include<iostream>
#include<conio.h>
using namespace std;
class SLL
{
    private:
    struct node
    {
        int item;
        node *next;
    };
    node *start;
    public:
    SLL(){ start=NULL;}
    void insertAtLast(int data);
    void insertAtFirst(int data);
    void insertAfter(int value,int data);
    void deleteNode(int value);
    void deleteFirst();
    void deleteLast();
    void viewList();


};

void SLL ::deleteNode(int value)
{
    node *t1,*t2;
    t1=start;
    t2=NULL;
    while(t1)
    {
     if(t1->item==value)
     break;
     t2=t1;
     t1=t1->next;

    }
    if(t1==NULL)
    {
        cout<<"NO item with Vlaue"<<value<<"in the list";
    }
    else{
        if(t2==NULL)
        start=t1->next;
        else
        t2->next=t1->next;
        delete t1;
    }
}
void SLL ::insertAfter(int value,int data)
{
    node *t,*n;
    t=start;
    while(t)
    {
       if(t->item==value)
       break;
       t=t->next;
    }
    if(t!=NULL)//NODE FOUND
    {
        n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
    else{
        cout<<"No Item with value"<<value<<"in List";
    }
}
void SLL ::viewList()
{
    if(start==NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
    node *t;
    t=start;
    while(t!=NULL)
    {
        cout<<t->item<<" ";
        t=t->next;
    }
    }
}
void SLL ::deleteLast()
{
    node *t1,*t2;
    if(start==NULL)
    {
        cout<<"\n UNDERFLOW";
    }
    else
    {
        t1=start;
        t2=NULL;
        while(t1->next!=NULL)
        {
            t2=t1;
            t1=t1->next;
        }
        if(t2==NULL)
        start=NULL;
        else
        t2->next=NULL;
        delete t1;

    }
}  
void  SLL ::deleteFirst()
{
    node *r;
if(start==NULL)
{
    cout<<"\nUNDERFLOW";
}
else{
     r=start;
     start=r->next;
     delete r;
}
}
void SLL ::insertAtFirst(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
void SLL :: insertAtLast(int data)
{
    node *t;
    node *n = new node;
    n->item=data;
    n->next=NULL;
      if(start==NULL)
      {
        start=n;
      }
else
{
    t=start;
    while(t->next!=NULL)
    t=t->next;
    t->next=n;

}
}
int main()
{
cout<<"\n1 InsertAtFirst";
cout<<"\n2 InsertAtLast";
cout<<"\n3 deletAtFirst";
cout<<"\n4 deleteAtlast";
cout<<"\n5 InsertAfter";
cout<<"\n6 deleteNode";
cout<<"\n7 viewList";
cout<<"\n0 Exit";
int choice,item,data,value;
SLL list1;
do{
    cout<<"\nEnter Your choice";
    cin>>choice;
    switch (choice)
    {
    case 1: 
    cout<<"Enter Element";
    cin>>item;
    list1.insertAtFirst(item);
     break;
     case 2: 
    cout<<"Enter Element";
    cin>>item;
    list1.insertAtLast(item);
     break;
     case 3:
     list1.deleteFirst();
     break;
     case 4:
     list1.deleteLast();
     break;
     case 5: 
    cout<<"Enter  the  'Value'   After which    'data' is insert";
    cin>>value>>data;
    list1.insertAfter(value,data);
     break;
     case 6:
     cout<<"Enter the value to delete";
     cin>>value;
     list1.deleteNode(value);
     break;
     case 7:
     list1.viewList();
     break;
    }

}while(choice !=0);
}


