#ifndef DISJOINT_SET_H
#define DISJOINT_SETE_H
#define MAX_NUM_OF_SETS 100
#define MAX_NUM_OF_ELEMENTS 100
#include "ReversedTree.h"

template <class T>
class DisjointSet
{
private:
    ReversedTree<T> *tree;
    Set<T>* sets[MAX_NUM_OF_SETS] = {NULL};
    ReversedTreeNode<T>* elements[MAX_NUM_OF_ELEMENTS] = {NULL};

public:
    DisjointSet() {}
    ~DisjointSet() {}
    void AddSet(int idOfSet, int firstValue)
    {
        Set<int> *s = new Set<int>(idOfSet);
        sets[idOfSet] = s;
        ReversedTreeNode<T> *root = new ReversedTreeNode<T>(firstValue, s);
        ReversedTree<T> tree(root);
        sets[idOfSet]->setRootOfSet(root);
    }
};
#endif // DISJOINT_SETE_H