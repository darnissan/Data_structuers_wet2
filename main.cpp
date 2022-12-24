#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

using namespace std;

int main()
{
    HashTable<int> ht;
    ht.Insert(21,2);
    ht.Insert(11,1);
    ht.Insert(111,11);
    ht.Insert(121,12);
    int x = ht.Find(1);
    std::cout<<x<<std::endl;
    return 0;
}