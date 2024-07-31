#include "../header/SLL.h"

void SLL::insertFront(int value)
{
    Node *newNode = new Node(value, NULL);

    if (this->isEmpty())
    {
        this->tail = newNode;
    }
    else
    {
        newNode->putNext(this->head);
    }
    this->head = newNode;

    this->size++;
}

void SLL::insertBack(int value)
{
    Node *newNode = new Node(value, NULL);

    if (this->isEmpty())
    {
        this->head = newNode;
    }
    else
    {
        this->tail->putNext(newNode);
    }
    this->tail = newNode;

    this->size++;
}

void SLL::insertAt(int value, int index)
{
    if (index < 0 || index > this->size)
    {
        return;
    }
    if (index == 0)
    {
        return this->insertFront(value);
    }
    if (index == this->size)
    {
        return this->insertBack(value);
    }

    Node *newNode = new Node(value, NULL);

    Node *ptr = this->head;
    for (int i = 1; i < index; i++)
    {
        ptr = ptr->getNext();
    }

    newNode->putNext(ptr->getNext());
    ptr->putNext(newNode);

    this->size++;
}

void SLL::popFront()
{
    if (this->isEmpty())
    {
        return;
    }

    Node *nodeToRemove = this->head;

    this->head = this->head->getNext();
    delete nodeToRemove;

    this->size--;
    if (this->isEmpty())
    {
        this->tail = NULL;
    }
}

void SLL::popBack()
{
    if (this->size <= 1)
    {
        return this->popFront();
    }

    Node *nodeToRemove = this->tail;

    Node *ptr = this->head;
    while (ptr->getNext() != this->tail)
    {
        ptr = ptr->getNext();
    }

    ptr->putNext(NULL);
    this->tail = ptr;
    delete nodeToRemove;

    this->size--;
}

void SLL::popAt(int index)
{
    if (index < 0 || index >= this->size)
    {
        return;
    }
    if (index == 0)
    {
        return this->popFront();
    }
    if (index == (this->size - 1))
    {
        return this->popBack();
    }

    Node *ptr = this->head;
    for (int i = 1; i < index; i++)
    {
        ptr = ptr->getNext();
    }

    Node *nodeToRemove = ptr->getNext();
    ptr->putNext(nodeToRemove->getNext());
    delete nodeToRemove;

    this->size--;
}

void SLL::remove(int value)
{
    if (this->isEmpty())
    {
        return;
    }

    Node *ptr = this->head;
    Node *prevPtr = this->head;
    int index = 0;
    while (ptr != NULL && ptr->getValue() != value)
    {
        prevPtr = ptr;
        ptr = ptr->getNext();
        index++;
    }

    if (index >= this->size)
    {
        return;
    }
    if (index == 0)
    {
        return this->popFront();
    }
    if (index == (this->size - 1))
    {
        return this->popBack();
    }

    prevPtr->putNext(ptr->getNext());
    delete ptr;

    this->size--;
}

int SLL::getSize() const
{
    return this->size;
}

bool SLL::isEmpty() const
{
    return (this->size == 0);
}

int SLL::front() const
{
    if (this->isEmpty())
    {
        throw out_of_range("List is empty");
    }
    return this->head->getValue();
}

int SLL::back() const
{
    if (this->isEmpty())
    {
        throw out_of_range("List is empty");
    }
    return this->tail->getValue();
}

int SLL::at(int index) const
{
    if (index < 0 || index >= this->size)
    {
        throw out_of_range("Index out of range");
    }
    if (index == 0)
    {
        return this->front();
    }
    if (index == (this->size - 1))
    {
        return this->back();
    }

    Node *ptr = this->head;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->getNext();
    }

    return ptr->getValue();
}

void SLL::clear()
{
    while (!this->isEmpty())
    {
        this->popFront();
    }
}

bool SLL::contains(int value) const
{
    Node *ptr = this->head;
    while (ptr != NULL)
    {
        if (ptr->getValue() == value)
        {
            return true;
        }
        ptr = ptr->getNext();
    }
    return false;
}

void SLL::reverse()
{
    Node *ptr1 = NULL;
    Node *ptr2 = this->head;

    this->head = this->tail;
    this->tail = ptr2;

    while (ptr2 != NULL)
    {
        Node *temp = ptr2->getNext();
        ptr2->putNext(ptr1);
        ptr1 = ptr2;
        ptr2 = temp;
    }
}

void SLL::printList() const
{
    Node *ptr = this->head;
    while (ptr != NULL)
    {
        cout << ptr->getValue() << "->";
        ptr = ptr->getNext();
    }
    cout << endl;
}