#pragma once

#include <cstdlib>

class Node
{
private:
    int value = 0;
    Node *next = NULL;
    Node *prev = NULL;

public:
    Node() {}
    Node(int value, Node *next, Node *prev = NULL);

    int getValue() const;
    Node *getNext() const;
    Node *getPrev() const;

    void putValue(int value);
    void putNext(Node *next);
    void putPrev(Node *prev);
};