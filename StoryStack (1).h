//Specification file for Story class
#ifndef STORYSTACK_H
#define STORYSTACK_H
#include <iostream>
#include <string>
using namespace std;


class StoryStack 
{
    private:
        //Structure for stack nodes
        struct LibNode
         {
             string value; //value in node
             LibNode *next;  //pointer to next node
         };
    
         LibNode *top;  //pointer to stack top
    
    
    public:
        //Constructor
        StoryStack()
             {top=nullptr;}
        
        //Destructor
        ~StoryStack();
        
        //stack operations
        void push(string);
        void pop(string &);
        bool isEmpty();
        int validate();
        void displayStack();
    
};
#endif