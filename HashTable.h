#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#define INIT_SIZE 7
#include "BiDirectionList.h"
#include <cmath>
template <class T>
class HashTable
{
private:
    LinkedList<T> **HTarray;
    int size;
    int moduluNum;
    int numOfElements = 0;
    int numOfSlotsTaken = 0;
    bool everResized = false;
    int HashFunction(int const toModulu, int const value) const
    {
        int returnedVal = (value % toModulu);
        return returnedVal;
    }
    int HashFunction(int const value) const
    {
        int returnedVal = (value % size);
        return returnedVal;
    }

public:
    HashTable()
    {
        HTarray = new LinkedList<T> *[INIT_SIZE];
        size = INIT_SIZE;

        for (int i = 0; i < size; i++)
        {
            HTarray[i] = new LinkedList<T>;
            HTarray[i]->SetHead(nullptr);
        }
    }
    HashTable(int initSize)
    {
        HTarray = new LinkedList<T>[initSize];
        size = initSize;

        for (int i = 0; i < size; i++)
        {
            HTarray[i]->SetHead(nullptr);
        }
    }
    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            HTarray[i]->Clear();
            HTarray[i] = nullptr;
        }
    }
    void Insert(const T &value, int serial)
    {
        if (isIn(value, serial) == false)
        {
            int indexToInsert = HashFunction(serial);
            if (HTarray[indexToInsert]->GetHead() == nullptr)
            {
                numOfSlotsTaken++;
            }
            HTarray[indexToInsert]->Insert(value, serial);

            numOfElements++;
        }
        if (numOfSlotsTaken == size - 1)
        {
            resize(size * 2);
        }
        else if (numOfSlotsTaken == size / 2 && everResized == true)
        {
            resize(size / 2);
        }
    }
    bool isIn(const T &value, int serial) 
    {
        int indexToCheck = HashFunction(serial);
        return HTarray[indexToCheck]->isInList(value);
    }

    T  &Find(int serial) 
    {
        int indexToCheck = HashFunction(serial);
        return HTarray[indexToCheck]->GetBySerial(serial)->GetValue();
    }
   ListNode<T> *FindPointer(int serial) const
    {
        int indexToCheck = HashFunction(serial);
        
        return HTarray[indexToCheck]->GetBySerial(serial);
    }

    void resize(int newSize)
    {
        // I need to copy the values to a new array
        // then I need to clear the old array
        // then I need to delete the old array
        // then I need to update the pointers and size and number of elements
        LinkedList<T> **newArray = new LinkedList<T> *[newSize];
        for (int i = 0; i < newSize; i++)
        {
            newArray[i] = new LinkedList<T>;
            newArray[i]->SetHead(nullptr);
        }
        numOfSlotsTaken = 0;
        ListNode<T> *temp = nullptr;
        for (int i = 0; i < size; i++)
        {
            temp = HTarray[i]->GetHead();
            while (temp != nullptr)
            {
                int indexToInsert = HashFunction(newSize, temp->GetSerial());
                if (newArray[indexToInsert]->GetHead() == nullptr)
                {
                    numOfSlotsTaken++;
                }
                newArray[indexToInsert]->Insert(temp->GetValue(), temp->GetSerial());
                temp = temp->GetNext();
            }
        }
        for (int i = 0; i < size; i++)
        {
            HTarray[i]->Clear();
            HTarray[i] = nullptr;
        }
        delete[] HTarray;
        HTarray = newArray;
        size = newSize;
        everResized = true;
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "index " << i << ": ";
            HTarray[i]->Print();
        }
    }
};
#endif // HASH_TABLE_H