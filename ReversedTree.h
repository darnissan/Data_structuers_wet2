#ifndef REVERSED_TREE_H
#define REVERSED_TREE_H
#include "iostream"

template <class T>
class ReversedTreeNode;

template <class T>
class Set
{
    public:
    Set(int idOfSet) : idOfSet(idOfSet), rootOfSet(NULL) {}
    Set(int idOfSet, ReversedTreeNode<T> *rootOfSet) : idOfSet(idOfSet), rootOfSet(rootOfSet) {}
    ~Set() {}
    void setRootOfSet(ReversedTreeNode<T> *newRootOfSet) { rootOfSet = newRootOfSet; }
    ReversedTreeNode<T> *GetRootOfSet() { return rootOfSet; }
    int GetSizeOfSet() { return sizeOfSet; }
    void SetSizeOfSet(int newSizeOfSet) { sizeOfSet = newSizeOfSet; }
    void IncreaseSizeOfSetByOne() { sizeOfSet++; }
    void IncreaseSizeOfSetBy(int num) { sizeOfSet += num; }
    void Print() const { std::cout << "Set with ID " << idOfSet << " and size " << sizeOfSet << std::endl; }

    private:
    int idOfSet;
    int sizeOfSet = 0;
    ReversedTreeNode<T> *rootOfSet;
};

template <class T>
class ReversedTreeNode
{
    public:
    ReversedTreeNode(const T &value) : value(value), setOfTree(NULL), parent(NULL)  {}
    ReversedTreeNode(const T &value, Set<T> *setOfTree) : value(value), setOfTree(setOfTree), parent(NULL) {}
    ReversedTreeNode(const T &value, Set<T> *setOfTree, ReversedTreeNode *parent) : value(value), setOfTree(setOfTree), parent(parent) {}
    ~ReversedTreeNode() {}
    void SetValue(const T &newValue) { value = newValue; }
    void SetParent(ReversedTreeNode *newParent) { parent = newParent; }
    void SetSetOfTree(Set<T> *newSetOfTree) { setOfTree = newSetOfTree; }
    
    T &GetValue() { return value; }
    ReversedTreeNode *GetParent() { return parent; }
    void Print() const { std::cout << "ReversedTreeNode with value " << value << std::endl; }

    private:
    T value;
    Set<T> *setOfTree;
    ReversedTreeNode *parent;
};



template <class T>
class ReversedTree
{
public:
    ReversedTreeNode<T> *root;
    ReversedTree() : root(NULL) {}
    ReversedTree(ReversedTreeNode<T> *root) : root(root) {}
    ~ReversedTree() {};
    ReversedTreeNode<T> *GetRoot() const { return root; }
    void SetRoot(ReversedTreeNode<T> *newRoot) { root = newRoot; }
    void Print() const { std::cout << "Root has value " << root->GetValue() << std::endl; }
};



#endif //  REVERSED_TREE_H