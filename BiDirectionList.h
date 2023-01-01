#ifndef LIST_H_
#define LIST_H_
#include <iostream>

template <class T>
class ListNode
{
public:
    // Constructor to initialize the node with a given value
    ListNode(const T &value) : value(value), next(nullptr) {}

    // Getter and setter methods for the value and next pointer of the node
    const T &GetValue() const { return value; }
     T &GetValue()  { return value; }
    void SetValue(const T &value) { this->value = value; }

    ListNode *GetNext() const { return next; }
    void SetNext(ListNode *next) { this->next = next; }
    ListNode *GetPrev() const { return prev; }
    void SetPrev(ListNode otherPrev) { this->prev = otherPrev; }
    void Setserial(int otherserial) { this->serial = otherserial; }
    int GetSerial() const { return serial; }

private:
    // The value and next pointer of the node
    T value;
    int serial;
    ListNode *next;
    ListNode *prev;
};

// Define a template class for the linked list
template <class T>
class LinkedList
{
public:
    // Default constructor to initialize the head and tail pointers of the list
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free the memory used by the nodes in the list

    ~LinkedList()
    {
        // Iterate through the list and delete each node
        ListNode<T> *node = head;
        while (node != nullptr)
        {
            ListNode<T> *next = node->GetNext();
            delete node;
            node = next;
        }
    }
    void Clear()
    {
        ListNode<T> *node = head;
        while (node != nullptr)
        {
            ListNode<T> *next = node->GetNext();
            delete node;
            node = next;
        }
    }

    // Getter and setter methods for the head and tail pointers of the list
    ListNode<T> *GetHead() const
    {
        return head;
    }
    void SetHead(ListNode<T> *head) { this->head = head; }

    ListNode<T> *GetTail() const { return tail; }
    void SetTail(ListNode<T> *tail) { this->tail = tail; }

    // Method to insert a new node with a given value at the end of the list
    void Insert(const T &value)
    {
        // Create a new node with the given value
        ListNode<T> *node = new ListNode<T>(value);

        // If the list is empty, set the new node as the head and tail of the list
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        // Otherwise, add the new node to the end of the list and update the tail pointer
        else
        {
            tail->SetNext(node);
            tail = node;
        }
    }
    void Insert(const T &value, const int &serial)
    {
        // Create a new node with the given value
        ListNode<T> *node = new ListNode<T>(value);
        node->Setserial(serial);
        // If the list is empty, set the new node as the head and tail of the list
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        // Otherwise, add the new node to the end of the list and update the tail pointer
        else
        {
            tail->SetNext(node);
            tail = node;
        }
    }
    // Method to remove a node with a given value from the list
    void Remove(const T &value)
    {
        // Keep track of the previous and current nodes as we iterate through the list
        ListNode<T> *Removeprev = nullptr;
        ListNode<T> *node = head;

        // Iterate through the list until we find a node with the given value
        while (node != nullptr && node->GetValue() != value)
        {
            Removeprev = node;
            node = node->GetNext();
        }

        // If we found a node with the given value, remove it from the list
        if (node != nullptr)
        {
            // If the node is the head of the list, update the head pointer
            if (node == head && node == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else if (node == head)
            {
                head = node->GetNext();
            }
              
            // If the node is the tail of the list, update the tail pointer
            else if (node == tail)
                tail = Removeprev;

            // If the previous node is not null, update its next pointer
            // to point to the node after the one that we're removing
            if (Removeprev != nullptr)
                Removeprev->SetNext(node->GetNext());

            // Delete the node that we're removing
            delete node;
        }
    }
    //get by serial
    ListNode<T> *GetBySerial(const int &serial)
    {
        // Keep track of the previous and current nodes as we iterate through the list
        ListNode<T> *node = this->head;

        // Iterate through the list until we find a node with the given value
        while (node != nullptr && node->GetSerial() != serial)
        {
            node = node->GetNext();
        }

 
        if (node != nullptr)
        {
            return node;
        }
        return nullptr;
    }




    
    bool IsEmpty() const
    {
        return head == nullptr;
    }

    // Method to append the values from another linked list to the end of this list
    void Append(const LinkedList<T> &other)
    {
        // Check if the other list is empty. If it is, there is nothing to append,
        // so we can return immediately.
        if (other.IsEmpty())
            return;

        // If this list is empty, we can simply set the head and tail pointers
        // to point to the head and tail of the other list.
        if (IsEmpty())
        {
            head = other.head;
            tail = other.tail;
        }
        // If this list is not empty, we need to iterate through the list
        // to find the last node, and then update its next pointer to point
        // to the head of the other list.
        else
        {
            ListNode<T> *node = head;
            while (node->GetNext() != nullptr)
                node = node->GetNext();
            node->SetNext(other.head);
            tail = other.tail;
        }
    }
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list)
    {
        ListNode<T> *node = list.head;
        while (node != nullptr)
        {
            os << node->GetValue() << " ";
            node = node->GetNext();
        }
        return os;
    }
    bool isInList(const T &value)
    {
        ListNode<T> *temp;
        temp = this->head;
        while (temp != nullptr)
        {
            if (temp->GetValue() == value)
                return true;
        }

        return false;
    }
    bool isInList(const int &serial)
    {
        ListNode<T> *temp;
        temp = this->head;
        while (temp != nullptr)
        {
            if (temp->GetSerial() == serial)
                return true;
        }

        return false;
    }

private:
    // The head and tail pointers of the linked list
    ListNode<T> *head;
    ListNode<T> *tail;
};
#endif // LIST_H_