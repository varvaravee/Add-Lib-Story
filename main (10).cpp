/* Varvara Vorobieva
* Chapter 19 Assignment
*CISC 187
* 4/21/2022
*/
 
#include <iostream>
#include <iomanip>
#include <string>
#include "StoryStack.h"
using namespace std;

//Function prototypes

void DisplayMenu(StoryStack &);
void InsertWord(StoryStack &);
void DeleteLast(StoryStack &);
void AddWords(StoryStack &);
void AddAnS(StoryStack &);
void DisplayStack(StoryStack &);
void DisplayStory(StoryStack&);
void Leave();

int main()
{
   StoryStack Story;
   DisplayMenu(Story);
   
    return 0;
}


//Menu displaying function 
void DisplayMenu(StoryStack &Stack)
{
    //While testvar is not 7, display menu
    int menuOption=0;
    string option="";
    while (menuOption!=7)
    {
      cout<<"Welcome to StoryStack AddLibs!\n";
      cout<<"1. Add a word to the story. \n" ;
      cout<<"2. Delete the last word from the story. \n";
      cout<<"3. Concatenate two words into one. \n";
      cout<<"4. Add an 's' to the end of the last word.\n";
      cout<<"5. Display list of inputted words. \n";
      cout<<"6. Display the story with user-provided words.\n";
      cout<<"7. Exit the program. \n";
      cout<<"Please choose your menu option.\n";
      
      getline(cin,option);
      menuOption=stoi(option);
      
      if (menuOption==1)
      {
         InsertWord(Stack);
      }
      else if (menuOption==2)
      {
         DeleteLast(Stack);
      }  
      else if (menuOption==3)
      {
         AddWords(Stack);
      }
      else if (menuOption==4)
      {
         AddAnS(Stack);
      }
      else if (menuOption==5)
      {
         DisplayStack(Stack);
      }
      else if (menuOption==6)
      {
         DisplayStory(Stack);
      }
      else if (menuOption==7)
      {
          Leave();
      }
      else
      {
          cout<<"Error: That number is not a valid menu selection.\n";
          cout<<"Please enter a valid integer, 1-7.\n";
      }
    
    
    }
}


//Function inserts word into addlib stack
void InsertWord(StoryStack &Stack)
{
    string newword;
    cout<<"Please enter the word you wish to add to the story.\n";
    getline(cin, newword);
    
    //If input is blank or longer than 10 letters, prompt for other input
    while(newword.size()<1 || newword.size()>10)
    {
        cout<<"Error: " << newword<< " is not between 1 and 10 letters.\n";
        cout<<"Please enter a different word to add to the story.\n\n";
        getline(cin, newword);
    }
    
    //Call class method
    Stack.push(newword);
    
    cout<<newword<< " has been added to the story. \n";
}

//Function deletes a word from the stack
void DeleteLast(StoryStack &Stack)
{
    cout<<"Removing the last value inputted.\n";
    string catchVar;
    Stack.pop(catchVar);
}


//Function concatenates the last inputted words together.
void AddWords(StoryStack &Stack)
{
    string word; //Holds word to be popped from the Stack
    
    //Validates stack 
    if (Stack.validate()<2)
    {
        cout<<"\n The stack does not contain a minimum of 2 words to pop.\n"<< "Returning to main menu.\n";
    }
    
    else
    {
        //Concatenate 2 top words on stack
        string twoWords="";
        string word="";
    
        Stack.pop(word);
        twoWords=word;
        
        Stack.pop(word);
        twoWords+=word;
        
        //Push new word onto stack 
        Stack.push(twoWords);
        
    }
    
}

//Function adds an s to the end of first word on Stack

void AddAnS(StoryStack &Stack)
{
    if (Stack.isEmpty())
    {
        cout<<"There are no words on the stack.\n\n";
    }

   
    else
    {
        string word="";
        
        Stack.pop(word);
        word+="s";
        Stack.push(word);
        
    }
    
}


//Function displays the Stack
void DisplayStack(StoryStack &Stack)
{
    if (Stack.isEmpty())
    {
        cout<<"There are no words on the stack to display.\n\n";
    }
    else
    {
        Stack.displayStack();
    }
}

//Function displays Story 
void DisplayStory(StoryStack &Stack)
{
   //If stack contains 5 or more elements
    if (Stack.validate()>4)
    {
        //Declare variables that will hold the addlibs
        string word1="";
        string word2="";
        string word3="";
        string word4="";
        string word5="";
        
        //Begin poping words off the stack and saving them in string variables
        string word="";
        Stack.pop(word);
        word1=word;
        
        Stack.pop(word);
        word2=word;
        
        Stack.pop(word);
        word3=word;
        
        Stack.pop(word);
        word4=word;
        
        Stack.pop(word);
        word5=word;
        
        //Encorporate the words that were popped off the stack into the story
        cout<<"The stinky " << word1 << " showed the " << word2<< " how to " << word3 <<" that." <<endl;
        cout<<"The " << word4 << " could not believe the incredible size of " << word5 << " that they found.\n";
    }
    
    //If stack contains less than 5 elements
    else 
    {
        cout<< "There are not enough words on the stack.\n";
        exit(EXIT_FAILURE);
    }
    
}

void Leave()
{
    cout<<"Goodbye, thanks for using StoryStack AddLibs!\n";
}
