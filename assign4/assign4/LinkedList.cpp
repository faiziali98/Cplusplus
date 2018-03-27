#ifndef __LINKEDLIST_CPP
#define __LINKEDLIST_CPP

#include <cstdlib>
#include "LinkedList.h"
#include<iostream>
using namespace std;

LinkedList::LinkedList()
{
    head=NULL;
}


LinkedList::LinkedList(const LinkedList& otherLinkedList)
{
    Node *a=NULL;
    Node *b=NULL;

    if (otherLinkedList.head==NULL)
        head=NULL;
    else
       {
           head=new Node;
           head->data=otherLinkedList.head->data;
           head->next=new Node;
           b=otherLinkedList.head->next;
           a=head->next;
           while (b->next!=NULL)
           {
               (*a).data=(*b).data;
               (*a).next=new Node;
               a=(*a).next;
               b=(*b).next;
           }
           a->data=b->data;
            a->next=NULL;
       }
}


LinkedList::~LinkedList()
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head->next;
        delete(head);
        head=NULL;

        while (a!=NULL)
        {
            Node *temp;
            temp=new Node;
            temp=a->next;
            delete(a);
            a=temp;
        }

    }
}


void LinkedList::insertAtHead(int item)
{
    if (head!=NULL)
    {
        Node *temp=NULL;
        temp=new Node;
        temp->data=item;
        temp->next=head;
        head=temp;
    }
    else
    {
        Node *temp=NULL;
        temp=new Node;
        temp->data=item;
        temp->next=NULL;
        head=temp;
    }
}


void LinkedList::insertAtintail(int item)
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head;
        while (a->next!=NULL)
        {
            a=a->next;
        }
        Node *temp=NULL;
        temp=new Node;
        temp->data=item;
        temp->next=NULL;
        a->next=temp;
    }
}


void LinkedList::insertAfter(int toInsert, int afterWhat)
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head;
        int b=a->data;
        while (b!=afterWhat)
        {
            if (a->next!=NULL)
                {a=a->next;
                b=a->data;
                cout<<a->data<<"Hello"<<endl;}
            else
                break;
        }
        if (b==afterWhat)
        {
            Node *temp=NULL;
            temp=new Node;
            temp->next=a->next;
            temp->data=toInsert;
            a->next=temp;}
        }
    else
        cout<<"Cant do head is null"<<endl;
}


void LinkedList::insertSorted(int item)
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head;
        Node *c=NULL;
        c=new Node;
        int b=a->data;

        while (b<=item)
        {
            if (a->next!=NULL)
            {
                c=a;
                a=a->next;
                b=a->data;
            }
            else
                break;
        }
        if (a==head && b>item)
        {
            Node *temp=NULL;
            temp=new Node;
            temp->next=head;
            temp->data=item;
            head=temp;
        }
        else if (b>item)
        {
            Node *temp=NULL;
            temp=new Node;
            temp->next=c->next;
            temp->data=item;
            c->next=temp;
        }
        else
        {
            Node *temp=NULL;
            temp=new Node;
            temp->next=NULL;
            temp->data=item;
            a->next=temp;
        }
    }
    else
    {
        Node *temp=NULL;
        temp=new Node;
        temp->next=NULL;
        temp->data=item;
        head=temp;
    }

}


Node* LinkedList::getHead()
{
    return head;
}


Node* LinkedList::getintail()
{
    if (head==NULL)
        return NULL;
    else
    {
        Node *a=NULL;
        a=new Node;
        a=head;
        while (a->next!=NULL)
        {
            a=a->next;
        }
        return a;
    }
}


Node *LinkedList::searchFor(int item)
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head;
        int b=a->data;
        int g=1;
        while (b!=item)
        {
            if (a->next!=NULL)
            {
                g++;
                a=a->next;
                b=a->data;
            }
            else
                break;
        }
        if (b==item)
        {
            return a;
        }
        else
        {
            cout<<"No data found"<<endl;
            //return NULL;
        }
    }
    else
        cout<<"No data Yet"<<endl;
}


void LinkedList::deleteElement(int item)
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head;
        Node *c=new Node;
        int b=a->data;

        while (b!=item)
        {
            if (a->next!=NULL)
            {
                c=a;
                a=a->next;
                b=a->data;
            }
            else
                break;
        }
        if (a==head && b==item)
        {
            Node *temp=NULL;
            temp=new Node;
            temp=head->next;
            delete(head);
            head=temp;
        }
        else if (b==item)
            {
                c->next=a->next;
                delete(a);
                a=NULL;
            }
        else
            cout<<"No data found"<<endl;
    }
    else
        cout<<"No data Yet"<<endl;
}


void LinkedList::deleteHead()
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head->next;
        delete(head);
        head=a;
    }
    else
        cout<<"No data Yet"<<endl;
}


void LinkedList::deleteintail()
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head;
        Node *b=new Node;
        while (a->next!=NULL)
        {
            b=a;
            a=a->next;
        }
        delete(b->next);
        b->next=NULL;
    }
    else
        cout<<"No data Yet"<<endl;
}


int LinkedList::length()
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head;
        int b=1;

        while (a->next!=NULL)
        {
            b++;
            a=a->next;
        }
        return b;
     }
    else
        return 0;
}

void LinkedList::print()
{
    if (head!=NULL)
    {
        Node *a=NULL;
        a=new Node;
        a=head;
        cout<<"Data Is "<<a->data<<endl;
        while (a->next!=NULL)
        {
            a=a->next;
            cout<<"Data Is ";
            cout<<a->data<<endl;

        }
    }
}

#endif
