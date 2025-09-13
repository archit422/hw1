/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main() {
  // Make input list: 1 -> 2 -> 3 -> 4 -> 5
  Node* in = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}};

  Node* odds = NULL;
  Node* evens = NULL;

  // Split into odds and evens
  split(in, odds, evens);

  // Print results
  std::cout << "odds:  ";
  for (Node* cur = odds; cur != NULL; cur = cur->next) {
    std::cout << cur->value << " ";
  }
  std::cout << "\nevens: ";
  for (Node* cur = evens; cur != NULL; cur = cur->next) {
    std::cout << cur->value << " ";
  }
  std::cout << std::endl;

  // Clean up
  while (odds)  { Node* nxt = odds->next;  delete odds;  odds  = nxt; }
  while (evens) { Node* nxt = evens->next; delete evens; evens = nxt; }

  return 0;
}

