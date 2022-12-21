#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

using namespace std;

int main()
{
    HashTable<int> ht;
    ht.Insert(2,2);
    ht.Insert(1,1);
    ht.Insert(11,11);
    return 0;
}