#pragma once

#include "../Node/header/Node.h"

#include <iostream>
#include <stdexcept>

using namespace std;

class SLL
{
private:
    int size = 0;
    Node *head = NULL;
    Node *tail = NULL;

public:
    // Constructor: Initializes the data structure
    // Time Complexity: O(1)
    SLL() {}

    // Inserts a value at the front of the Singly-Linked-List
    // Time Complexity: O(1)
    void insertFront(int value);

    // Inserts a value at the back of the Singly-Linked-List
    // Time Complexity: O(1)
    void insertBack(int value);

    // Inserts a value at a specified position (index) of the Singly-Linked-List
    // Time Complexity: O(n)
    void insertAt(int value, int index);

    // Removes a value from the front of the Singly-Linked-List
    // Time Complexity: O(1)
    void popFront();

    // Removes a value from the back of the Singly-Linked-List
    // Time Complexity: O(n)
    void popBack();

    // Removes a value from a specified position (index) of the Singly-Linked-List
    // Time Complexity: O(n)
    void popAt(int index);

    // Remove the first occurance of the value from the Singly-Linked-List
    // Time Complexity: O(n)
    void remove(int value);

    // Returns the current size of the Singly-Linked-List
    // Time Complexity: O(1)
    int getSize() const;

    // Checks if the Singly-Linked-List is empty
    // Time Complexity: O(1)
    bool isEmpty() const;

    // Returns the value at the front of the Singly-Linked-List without removing it
    // Time Complexity: O(1)
    int front() const;

    // Returns the value at the back of the Singly-Linked-List without removing it
    // Time Complexity: O(1)
    int back() const;

    // Returns the value at a specified position (index) of the Singly-Linked-List
    // Time Complexity: O(n)
    int at(int index) const;

    // Clears all elements from the Singly-Linked-List
    // Time Complexity: O(n)
    void clear();

    // Checks if a value exists in the Singly-Linked-List
    // Time Complexity: O(n)
    bool contains(int value) const;

    // Reverses the Singly-Linked-List
    // Time Complexity: O(n)
    void reverse();

    // Prints all the elements of the Singly-Linked-List
    // Time Complexity: O(n)
    void printList() const;
};