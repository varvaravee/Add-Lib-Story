#include"StoryStack.h"
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

//Destructor, deletes every node in the list 

StoryStack::~StoryStack()
{
    LibNode * nodePtr=nullptr, *nextNode=nullptr;
    //Position nodePtr at top of stack 
    nodePtr=top;
    
    //Traverse list deleting each node 
    while(nodePtr != nullptr)
    {
        nextNode=nodePtr->next;
        delete nodePtr;
        nodePtr=nextNode;
    }
}

//Method pushes an user-inputted string onto stack on nodes

void StoryStack::push(string word)
{
   //Second level validation
   if (word.size()>0 || word.size()<11)
   {
          
    LibNode *newNode=nullptr; //pointer to new node 
    
    //Allocate new node and store num there
    newNode=new LibNode;
    newNode->value=word;
    
    //If there are no nodes in the list make newNode the first node.
    if (isEmpty())
    {
        top=newNode;
        newNode->next=nullptr;
    }
    
    else //Otherwise, insert NewNode before top.
    {
        newNode->next=top;
        top=newNode;
    }
    
   }
   
   else
   {
        cout <<"A word with an invalid length was entered.\n";
        exit(EXIT_FAILURE);
   }
   
}


//Method pops string at the top of the stack off, and copies it into variable passed as argument

void StoryStack::pop(string &holder)
{
    LibNode *temp=nullptr; //Temporary pointer
    
    //First make sure the stack isn't empty.
    if(isEmpty())
    {
        cout<<"There are no words to remove.\n\n";
        exit(EXIT_FAILURE);
    }
    
    else //pop value off top of stack
    {
        holder=top->value;
        temp=top->next;
        delete top;
        top=temp;
    }
    
}

//Member function isEmpty returns true if stack is empty, or false otherwise
bool StoryStack::isEmpty()
{
    bool status;
    
    if(!top)
        status=true;
    else 
        status=false;
    return status;
        
}

//Return number of members in stack 
int StoryStack::validate()
{
    //While the stack is not empty, count the number of nodes
    int i=0;
    LibNode *temp=top;
    
    while (temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    
    return i;
    
}

//Method displays stack
void StoryStack::displayStack()
{
    //If there are no words on the stack
    if (isEmpty())
    {
        cout<<"There are no words to display.\n\n";
        exit(EXIT_FAILURE);
        
    }
    
    else
    {
        LibNode *temp;
        temp=top;
    
        while (temp)
        {
            cout << temp->value<<endl;
        
            temp=temp->next;
    }
    }
}
