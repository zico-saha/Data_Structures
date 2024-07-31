#include "../header/DLL.h"

void DLL::insertFront(int value)
{
    Node *newNode = new Node(value, NULL, NULL);

    if (this->isEmpty())
    {
        this->tail = newNode;
    }
    else
    {
        newNode->putNext(this->head);
        this->head->putPrev(newNode);
    }
    this->head = newNode;

    this->size++;
}

void DLL::insertBack(int value)
{
    Node *newNode = new Node(value, NULL, NULL);

    if (this->isEmpty())
    {
        this->head = newNode;
    }
    else
    {
        newNode->putPrev(this->tail);
        this->tail->putNext(newNode);
    }
    this->tail = newNode;

    this->size++;
}

void DLL::insertAt(int value, int index)
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

    Node *newNode = new Node(value, NULL, NULL);

    Node *ptr = NULL;
    if (index <= (this->size / 2))
    {
        ptr = this->head;
        for (int i = 1; i < index; i++)
        {
            ptr = ptr->getNext();
        }
    }
    else
    {
        ptr = this->tail;
        for (int i = this->size; i > index; i--)
        {
            ptr = ptr->getPrev();
        }
    }

    newNode->putNext(ptr->getNext());
    newNode->putPrev(ptr);
    ptr->getNext()->putPrev(newNode);
    ptr->putNext(newNode);

    this->size++;
}

void DLL::popFront()
{
    if (this->isEmpty())
    {
        return;
    }

    Node *nodeToRemove = this->head;

    this->head = nodeToRemove->getNext();
    this->head->putPrev(NULL);
    delete nodeToRemove;

    this->size--;

    if (this->size == 0)
    {
        this->tail = NULL;
    }
}

void DLL::popBack()
{
    if (this->isEmpty())
    {
        return;
    }

    Node *nodeToRemove = this->tail;
    this->tail = nodeToRemove->getPrev();
    this->tail->putNext(NULL);
    delete nodeToRemove;

    this->size--;

    if (this->size == 0)
    {
        this->head = NULL;
    }
}

void DLL::popAt(int index)
{
    if (index < 0 || index >= this->size)
    {
        return;
    }
    else if (index == 0)
    {
        return this->popFront();
    }
    else if (index == (this->size - 1))
    {
        return this->popBack();
    }

    Node *ptr = NULL;
    if (index <= (this->size / 2))
    {
        ptr = this->head;
        for (int i = 1; i < index; i++)
        {
            ptr = ptr->getNext();
        }
    }
    else
    {
        ptr = this->tail;
        for (int i = this->size; i > index; i--)
        {
            ptr = ptr->getPrev();
        }
    }

    Node *nodeToRemove = ptr->getNext();
    ptr->putNext(nodeToRemove->getNext());
    nodeToRemove->getNext()->putPrev(nodeToRemove->getPrev());
    delete nodeToRemove;

    this->size--;
}

void DLL::remove(int value)
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

int DLL::getSize() const
{
    return this->size;
}

bool DLL::isEmpty() const
{
    return (this->size == 0);
}

int DLL::front() const
{
    if (this->isEmpty())
    {
        throw out_of_range("List is empty");
    }
    return this->head->getValue();
}

int DLL::back() const
{
    if (this->isEmpty())
    {
        throw out_of_range("List is empty");
    }
    return this->tail->getValue();
}

int DLL::at(int index) const
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

    Node *ptr = NULL;
    if (index < (this->size / 2))
    {
        ptr = this->head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->getNext();
        }
    }
    else
    {
        ptr = this->tail;
        for (int i = (this->size - 1); i > index; i--)
        {
            ptr = ptr->getPrev();
        }
    }
    return ptr->getValue();
}

void DLL::clear()
{
    while (!this->isEmpty())
    {
        this->popFront();
    }
}

bool DLL::contains(int value) const
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

void DLL::reverse()
{
    Node *ptr1 = NULL;
    Node *ptr2 = this->head;

    this->head = this->tail;
    this->tail = ptr2;

    while (ptr2 != NULL)
    {
        Node *temp = ptr2->getNext();
        ptr2->putNext(ptr1);
        ptr2->putPrev(temp);
        ptr1 = ptr2;
        ptr2 = temp;
    }
}

void DLL::printList() const
{
    Node *ptr = this->head;
    while (ptr != NULL)
    {
        cout << ptr->getValue() << "->";
        ptr = ptr->getNext();
    }
    cout << endl;
}