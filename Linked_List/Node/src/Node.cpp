#include "../header/Node.h"

Node::Node(int value, Node *next, Node *prev)
{
    this->value = value;
    this->next = next;
    this->prev = prev;
}

int Node::getValue() const
{
    return this->value;
}

Node *Node::getNext() const
{
    return this->next;
}

Node *Node::getPrev() const
{
    return this->prev;
}

void Node::putValue(int value)
{
    this->value = value;
}

void Node::putNext(Node *next)
{
    this->next = next;
}

void Node::putPrev(Node *prev)
{
    this->prev = prev;
}