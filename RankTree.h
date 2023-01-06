#ifndef RANKTREE_H
#define RANKTREE_H
#include <iostream>
#include <string>
#define LL 1
#define RR 2


template <class T>
class RankNode
{
public:
    RankNode(const T &value) : data(value), left(NULL), right(NULL), SumOfSubTreeNodes(1) {}
    ~RankNode() {}
    void SetValue(const T &value) { data = value; }
    const T &GetValue() const { return data; }
    T &GetValue() { return data; }
    void SetLeft(RankNode *node) { left = node; }
    RankNode *GetLeft() const { return left; }
    void SetRight(RankNode *node) { right = node; }
    RankNode *GetRight() const { return right; }

    void Print() const { std::cout << data << std::endl; }
    RankNode() = default;
    int GetSumOfSubTreeNodes() const
    {
        
        return SumOfSubTreeNodes;
    }
    void SetSumOfSubTreeNodes(int sum)
    {

        SumOfSubTreeNodes = sum;
    }
    void IncreaseSumOfSubTreeNodes()
    {

        SumOfSubTreeNodes++;
    }
    void DecreaseSumOfSubTreeNodes()
    {

        SumOfSubTreeNodes--;
    }

private:
    T data;
    RankNode *left;
    RankNode *right;
    int height;
    int SumOfSubTreeNodes;
};

template <class T>
class RankTree
{
public:
    RankNode<T> *root;
    RankTree() : root(NULL) {}
    ~RankTree();

    RankNode<T> *GetRoot() const { return root; }
    RankNode<T> *find(RankNode<T> *root, const T &value) const;
    int height(RankNode<T> *root) const;
    int GetBF(RankNode<T> *root) const;
    RankNode<T> *RotateLL(RankNode<T> *root);
    RankNode<T> *RotateRR(RankNode<T> *root);
    RankNode<T> *RotateLR(RankNode<T> *root);
    RankNode<T> *RotateRL(RankNode<T> *root);
    bool isItInTree(RankNode<T> *root, const T &value) const;
    RankNode<T> *Insert(RankNode<T> *root, const T &value);
    RankNode<T> *Remove(RankNode<T> *node, const T &value);
    void PrintInOrder(RankNode<T> *root) const;
    void DeleteTree(RankNode<T> *root);
    void Clear();
    RankNode<T> *Clear(RankNode<T> *root);
    T &Select(RankNode<T> *root, int index) const;
    void FixSumOfSubTreeNodesAfterRotation(RankNode<T> *a, RankNode<T> *b, int RotationTypeNum);

private:
    void DeleteRankNode(RankNode<T> *nodeToRemove); // function used by the destructor
};
template <class T>
void RankTree<T>::DeleteTree(RankNode<T> *node)
{
    if (node == NULL)
    {
        return;
    }
    node->SetLeft(this->Clear(node->GetLeft()));
    node->SetRight(this->Clear(node->GetRight()));
    delete node;
    node = NULL;
    return;
}
template <class T>
RankTree<T>::~RankTree()
{
    this->Clear();
}
template <class T>
void RankTree<T>::Clear()
{

    this->root = this->Clear(this->root);
    this->root = NULL;
}

template <class T>
RankNode<T> *RankTree<T>::Clear(RankNode<T> *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    node->SetLeft(this->Clear(node->GetLeft()));
    node->SetRight(this->Clear(node->GetRight()));
    delete node;
    node = NULL;
    return NULL;
}
template <class T>
void RankTree<T>::DeleteRankNode(RankNode<T> *nodeToRemove)
{
    if (nodeToRemove)
    {
        if (nodeToRemove->GetLeft())
        {
            DeleteRankNode(nodeToRemove->GetLeft());
        }
        if (nodeToRemove->GetRight())
        {
            DeleteRankNode(nodeToRemove->GetRight());
        }

        delete nodeToRemove;
    }
}
template <class T>
RankNode<T> *RankTree<T>::find(RankNode<T> *node, const T &value) const
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->GetValue() == value)
    {
        return node;
    }
    if (node->GetValue() > value)
    {
        return find(node->GetLeft(), value);
    }
    else
    {
        return find(node->GetRight(), value);
    }
}
template <class T>
int RankTree<T>::height(RankNode<T> *node) const
{
    int Ownheight = 0;
    if (node == NULL)
    {
        return 0;
    }
    int leftHeight = height(node->GetLeft());
    int rightHeight = height(node->GetRight());
    Ownheight = 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    return Ownheight;
}
template <class T>
int RankTree<T>::GetBF(RankNode<T> *node) const
{
    int leftHeight = height(node->GetLeft());
    int rightHeight = height(node->GetRight());
    int balanceFactor = leftHeight - rightHeight;
    return balanceFactor;
}
template <class T>
RankNode<T> *RankTree<T>::RotateLL(RankNode<T> *node)
{
    RankNode<T> *temp = node->GetLeft();
    FixSumOfSubTreeNodesAfterRotation(temp, node, 1);
    node->SetLeft(temp->GetRight());
    temp->SetRight(node);
    node = temp;
    return node;
}
template <class T>
RankNode<T> *RankTree<T>::RotateRR(RankNode<T> *node)
{
    RankNode<T> *temp = node->GetRight();
    FixSumOfSubTreeNodesAfterRotation(temp, node, 2);
    node->SetRight(temp->GetLeft());
    temp->SetLeft(node);
    node = temp;
    return node;
}
template <class T>
RankNode<T> *RankTree<T>::RotateLR(RankNode<T> *node)
{
    RankNode<T> *temp = RotateRR(node->GetLeft());
    FixSumOfSubTreeNodesAfterRotation(temp, node, 1);
    node->SetLeft(temp->GetRight());
    temp->SetRight(node);
    node = temp;
    return node;
}
template <class T>
RankNode<T> *RankTree<T>::RotateRL(RankNode<T> *node)
{
    RankNode<T> *temp = RotateLL(node->GetRight());
    FixSumOfSubTreeNodesAfterRotation(temp, node, 2);
    node->SetRight(temp->GetLeft());
    temp->SetLeft(node);
    node = temp;
    return node;
}
template <class T>
RankNode<T> *RankTree<T>::Insert(RankNode<T> *node, const T &value)
{
    if (this->root == NULL)
    {
        this->root = new RankNode<T>(value);
        return this->root;
    }
    if (node == NULL) // meaning we've reached a leaf and we can insert the new node
    {
        node = new RankNode<T>(value);
        node->SetSumOfSubTreeNodes( 1);
        return node;
    }
    if (node->GetValue() > value)
    {
        node->SetLeft(Insert(node->GetLeft(), value));
    }
    else if (node->GetValue() < value)
    {
        node->SetRight(Insert(node->GetRight(), value));
    }
    else
    {
        return node;
    }
    int balanceFactor = GetBF(node);
    if (balanceFactor == 2 && GetBF(node->GetLeft()) >= 0)
    {
        node = RotateLL(node);
        
    }
    else if (balanceFactor == 2 && GetBF(node->GetLeft()) == -1)
    {
        node = RotateLR(node);
        
    }
    else if (balanceFactor == -2 && GetBF(node->GetRight()) <= 0)
    {
        node = RotateRR(node);
        
    }
    else if (balanceFactor == -2 && GetBF(node->GetRight()) == 1)
    {
        node = RotateRL(node);
    }
    int leftSubTreeNodes = 0;
    int rightSubTreeNodes = 0;
    if (node->GetLeft())
    {
        leftSubTreeNodes = node->GetLeft()->GetSumOfSubTreeNodes();
    }
    if (node->GetRight())
    {
        rightSubTreeNodes = node->GetRight()->GetSumOfSubTreeNodes();
    }
    node->SetSumOfSubTreeNodes(leftSubTreeNodes+ rightSubTreeNodes+ 1);
    return node;
}
template <class T>
RankNode<T> *RankTree<T>::Remove(RankNode<T> *node, const T &value)
{
    if (node == NULL) // meaning we've reached a Null
    {
        return NULL;
    }
    if (value < node->GetValue()) // Meaning value to remove is in the left Subtree
    {
        node->SetLeft(this->Remove(node->GetLeft(), value));
    }
    else if (value > node->GetValue())
    {
        node->SetRight(this->Remove(node->GetRight(), value));
    }
    else if (value == node->GetValue())
    {
        if (node->GetLeft() == NULL && node->GetRight() == NULL)
        {
            if (node == this->root)
            {
                this->root = NULL;
            }
            delete node;
            node = NULL;
            return NULL;
        }
        else if (node->GetLeft() == NULL)
        {
            RankNode<T> *temp = node->GetRight();
            delete node;
            node = NULL;
            return temp;
        }
        else if (node->GetRight() == NULL)
        {
            RankNode<T> *temp = node->GetLeft();
            delete node;
            node = NULL;
            return temp;
        }
        else
        {
            RankNode<T> *temp = node->GetRight();
            while (temp->GetLeft() != NULL)
            {
                temp = temp->GetLeft();
            }
            node->SetValue(temp->GetValue());
            node->SetRight(Remove(node->GetRight(), temp->GetValue()));
        }
    }
    int balanceFactor = GetBF(node);
    if (balanceFactor == 2 && GetBF(node->GetLeft()) >= 0)
    {
        node = RotateLL(node);
       
    }
    else if (balanceFactor == 2 && GetBF(node->GetLeft()) == -1)
    {
        node = RotateLR(node);
       
    }
    else if (balanceFactor == -2 && GetBF(node->GetRight()) <= 0)
    {
        node = RotateRR(node);
        
    }
    else if (balanceFactor == -2 && GetBF(node->GetRight()) == 1)
    {
        node = RotateRL(node);
        
    }
    int leftSubTreeNodes = 0;
    int rightSubTreeNodes = 0;
    if (node->GetLeft())
    {
        leftSubTreeNodes = node->GetLeft()->GetSumOfSubTreeNodes();
    }
    if (node->GetRight())
    {
        rightSubTreeNodes = node->GetRight()->GetSumOfSubTreeNodes();
    }
    node->SetSumOfSubTreeNodes(leftSubTreeNodes + rightSubTreeNodes + 1);
    return node;
}
template <class T>
void RankTree<T>::PrintInOrder(RankNode<T> *root) const
{
    if (root == NULL)
    {
        return;
    }
    PrintInOrder(root->GetLeft());
    std::cout << root->GetValue() << " "<<std::endl;
    PrintInOrder(root->GetRight());
}
template <class T>
bool RankTree<T>::isItInTree(RankNode<T> *node, const T &value) const
{
    if (node == NULL)
    {
        return false;
    }
    if (node->GetValue() == value)
    {
        return true;
    }
    if (node->GetValue() > value)
    {
        return isItInTree(node->GetLeft(), value);
    }
    else
    {
        return isItInTree(node->GetRight(), value);
    }
    return false;
}

template <class T>
T &RankTree<T>::Select(RankNode<T> *node, int k_index) const
{

    int leftSubTreeSize = 0;
    if (node == NULL)
    {
        throw std::out_of_range("Index out of range");
    }
    if (node->GetLeft()==NULL)
    {
        leftSubTreeSize = 0;
    }
    else
    {
        leftSubTreeSize = node->GetLeft()->GetSumOfSubTreeNodes();
    }
    if (leftSubTreeSize== k_index - 1)
    {
        return node->GetValue();
    }
    if (leftSubTreeSize > k_index - 1)
    {
        return Select(node->GetLeft(), k_index);
    }
    else if (node->GetRight())
    {
        return Select(node->GetRight(), k_index - leftSubTreeSize - 1);
    }
    else
    {
        throw std::out_of_range("Index out of range");
    }
    return node->GetValue();
}
template <class T>
void RankTree<T>::FixSumOfSubTreeNodesAfterRotation(RankNode<T> *a, RankNode<T> *b, int RotationTypeNum)
{
    if (a == NULL || b == NULL)
    {
        return;
    }
    int aRightSum = 0;
    int aLeftSum = 0;
    int bRightSum = 0;
    int bLeftSum = 0;
    if (a->GetRight() != NULL)
    {
        aRightSum = a->GetRight()->GetSumOfSubTreeNodes();
    }
    if (a->GetLeft() != NULL)
    {
        aLeftSum = a->GetLeft()->GetSumOfSubTreeNodes();
    }
    if (b->GetRight() != NULL)
    {
        bRightSum = b->GetRight()->GetSumOfSubTreeNodes();
    }
    if (b->GetLeft() != NULL)
    {
        bLeftSum = b->GetLeft()->GetSumOfSubTreeNodes();
    }
    switch (RotationTypeNum)
    {
    case 1:
        b->SetSumOfSubTreeNodes(aRightSum + bRightSum + 1);
        a->SetSumOfSubTreeNodes(b->GetSumOfSubTreeNodes() + aLeftSum  + 1);
        break;
    case 2:
        b->SetSumOfSubTreeNodes(aLeftSum + bLeftSum + 1);
        a->SetSumOfSubTreeNodes(b->GetSumOfSubTreeNodes() + aRightSum + 1);
        break;
    default:
        break;
    }
}

#endif // AVL_TREE_H