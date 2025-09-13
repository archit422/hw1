/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split_helper(Node*& odd_head,Node*& odd_tail , Node*& even_head, Node*& even_tail,Node*& in);



void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */

  //initialize the pointers

  Node* odd_tail = NULL; 
  Node* even_tail = NULL;
  odds = NULL;
  evens = NULL;
  // calling helper function
  
  split_helper(odds, odd_tail, evens, even_tail, in);


  in = NULL;
}

/* If you needed a helper function, write it here */


void split_helper(Node*& odd_head,Node*& odd_tail , Node*& even_head, Node*& even_tail,Node*& in){

   if (in == NULL)
    {
      return;
    }  
 
   // detach each element from in 

    Node* head = NULL;
    head = in ;
    in = in->next ;
    head->next = NULL;


    if(head->value% 2 == 0)
      {
        if(even_head == NULL)
          {
            even_head = head;
            even_tail = head;
          }
        else
          {
            even_tail->next = head;
            even_tail = head;
          }
      }
      else
      {

        if(odd_head == NULL)
          {
            odd_head = head;
            odd_tail = head;
          }
        else
          {
            odd_tail->next = head;
            odd_tail = head;
          }
      }
      // recursive call 
      
      split_helper(odd_head,odd_tail, even_head, even_tail, in);

}

