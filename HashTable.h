#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#define INIT_SIZE  10
#include "BiDirectionList.h"
#include <cmath>
template <class T>
class HashTable
{
private:
    LinkedList<T> **HTarray;
    int size;
    int moduluNum;
    int HashFunction(int value)
    {
        int returnedVal = (value % size);
        return returnedVal;
    }

public:
    HashTable()
    {
        HTarray = new LinkedList<T>*[INIT_SIZE];
        size = INIT_SIZE;
       
        for (int i = 0; i < size; i++)
        {
            HTarray[i]=new LinkedList<T>;
            HTarray[i]->SetHead(nullptr);
        }
    }
    HashTable(int initSize)
    {
        HTarray = new LinkedList<T>[initSize];
        size = initSize;
      
        for (int i=0;i<size;i++)
        {
             HTarray[i]->SetHead(nullptr);
        }
    }
    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            HTarray[i]->Clear();
            HTarray[i]=nullptr;
        }
    }
    void Insert(const T &value, int serial)
    {
        int indexToInsert = HashFunction(serial);
    
        HTarray[indexToInsert]->Insert(value);
    }
};
#endif //HASH_TABLE_H