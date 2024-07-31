#pragma once

#include "../Node/header/Node.h"

#include <iostream>
#include <stdexcept>

using namespace std;

class DLL
{
private:
    int size = 0;
    Node *head = NULL;
    Node *tail = NULL;

public:
    // Constructor: Initializes the data structure
    // Time Complexity: O(1)
    DLL() {}

    // Inserts a value at the front of the Doubly-Linked-List
    // Time Complexity: O(1)
    void insertFront(int value);

    // Inserts a value at the back of the Doubly-Linked-List
    // Time Complexity: O(1)
    void insertBack(int value);

    // Inserts a value at a specified position (index) of the Doubly-Linked-List
    // Time Complexity: O(n)
    void insertAt(int value, int index);

    // Removes a value from the front of the Doubly-Linked-List
    // Time Complexity: O(1)
    void popFront();

    // Removes a value from the back of the Doubly-Linked-List
    // Time Complexity: O(1)
    void popBack();

    // Removes a value from a specified position (index) of the Doubly-Linked-List
    // Time Complexity: O(n)
    void popAt(int index);

    // Remove the first occurance of the value from the Doubly-Linked-List
    // Time Complexity: O(n)
    void remove(int value);

    // Returns the current size of the Doubly-Linked-List
    // Time Complexity: O(1)
    int getSize() const;

    // Checks if the Doubly-Linked-List is empty
    // Time Complexity: O(1)
    bool isEmpty() const;

    // Returns the value at the front of the Doubly-Linked-List without removing it
    // Time Complexity: O(1)
    int front() const;

    // Returns the value at the back of the Doubly-Linked-List without removing it
    // Time Complexity: O(1)
    int back() const;

    // Returns the value at a specified position (index) of the Doubly-Linked-List
    // Time Complexity: O(n)
    int at(int index) const;

    // Clears all elements from the Doubly-Linked-List
    // Time Complexity: O(n)
    void clear();

    // Checks if a value exists in the Doubly-Linked-List
    // Time Complexity: O(n)
    bool contains(int value) const;

    // Reverses the Doubly-Linked-List
    // Time Complexity: O(n)
    void reverse();

    // Prints all the elements of the Doubly-Linked-List
    // Time Complexity: O(n)
    void printList() const;
};