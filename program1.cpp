
#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
#include <inttypes.h>  
using namespace std; 
class Node  
{  
    public: 
    int data;  
    Node* npx; 
};  
  
Node* XOR (Node *a, Node *b)  
{  
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
}  
  
void insert(Node **head_ref, int data)  
{  
    Node *new_node = new Node();  
    new_node->data = data;  
  
    new_node->npx = *head_ref;  
  
    if (*head_ref != NULL)  
    {   
        (*head_ref)->npx = XOR(new_node, (*head_ref)->npx);  
    }  
    *head_ref = new_node;  
}  
void insert_end(Node **head_ref, int data)  
{  
    Node *new_node = new Node();  
    new_node->data = data;  
  
    new_node->npx = *head_ref;  
  
    if (*head_ref != NULL)  
    {   
        (*head_ref)->npx = XOR(new_node, (*head_ref)->npx);  
    }  
    *head_ref = new_node;  
}  
  
void print(Node *head)  
{  
    Node *curr = head;  
    Node *prev = NULL;  
    Node *next;  
    while (curr != NULL)  
    {  
        
        cout<<curr->data<<" ";  
        next = XOR (prev, curr->npx);  
  
        prev = curr;  
        curr = next;  
    }  
}  
  
int main()
{
    Node* head=NULL;
    int ch,num;
    while(1)
    {
        cout<<"Enter 1 to insert a value at the beginning , 2 to print ,3 to insert a value at the end 4 to exit"<<endl;
        cin>>ch;
        if(ch==3) break;
        switch(ch)
        {
        case 1: cout<<"Enter the value to be inserted at the beginning"<<endl;
                cin>>num;
                insert(&head,num);
                break;
                
        case 2: print(head);
                break;
                
        case 3: break;
        }
    }

    return 0;
}
