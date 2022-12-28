#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
#include "RankTree.h"
using namespace std;

int main()
{
    HashTable<int> ht;
    ht.Insert(21,2);
    ht.Insert(11,1);
    ht.Insert(111,11);
    ht.Insert(121,12);
    int x = ht.Find(1);
    RankTree<int> rt;
    rt.root=rt.Insert(rt.root, 1);
    rt.root=rt.Insert(rt.root, 3);
    rt.root=rt.Insert(rt.root, 4);
    rt.root=rt.Insert(rt.root, 5);
    rt.root=rt.Insert(rt.root, 7);
    rt.root=rt.Insert(rt.root, 10);
    rt.root=rt.Insert(rt.root, 18);
    rt.root=rt.Insert(rt.root, 20);
    rt.root=rt.Insert(rt.root, 21);
    rt.root=rt.Insert(rt.root, 22);
    rt.root=rt.Insert(rt.root, 6);
    rt.root=rt.Insert(rt.root, -7);
    rt.root=rt.Insert(rt.root, 0);
    rt.root=rt.Insert(rt.root, 5132);
    rt.root=rt.Insert(rt.root, -798);
    rt.root=rt.Insert(rt.root, -31);
    rt.root=rt.Remove(rt.root,21);
    rt.root=rt.Remove(rt.root,3);
    rt.root=rt.Remove(rt.root,5132);
    rt.root=rt.Remove(rt.root,0);
    rt.root=rt.Remove(rt.root,-31);
    rt.root = rt.Insert(rt.root, 15);
    for (int i = 1; i < 13; i++)
    {
        std::cout << rt.Select(rt.root, i) << std::endl;
    }
   
    std::cout<<x<<std::endl;
    return 0;
}
