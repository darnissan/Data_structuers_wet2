#ifndef DISJOINT_SET_H
#define DISJOINT_SETE_H
#include "ReversedTree.h"
#include "Player.h"
#include "HashTable.h"



template <class T>
class DisjointSet
{

public:
    DisjointSet() {}
    ~DisjointSet() {}

    Set<T> *GetSet(int idOfSet) { return TeamsHashTable->Find(idOfSet); }
    ReversedTreeNode<T> *GetElement(int value) { AllplayersTable->Find(value)->getPlayerReversedTreeNode(); }

    void SetSet(int idOfSet, Set<T> *s) { TeamsHashTable->FindPointer(idOfSet)->SetValue(s); }
    void SetElement(int value, ReversedTreeNode<T> *elem) { AllplayersTable->FindPointer(value)->setPlayerReversedTreeNode(elem); }

    void MakeSet(int idOfSet, int firstValue)
    {
        ReversedTreeNode<T> *root = new ReversedTreeNode<T>(firstValue);
        Set<T> *s = new Set<T>(idOfSet, root);
        root->SetSetOfTree(s);
        SetSet(idOfSet, s);
        SetElement(firstValue, root);
    }

    Set<T>* Union(int idOfSet1, int idOfSet2)
    {
        Set<T>* set1 = GetSet(idOfSet1);
        Set<T>* set2 = GetSet(idOfSet2);
        int sizeSet1 = set1->GetSizeOfSet();
        int sizeSet2 = set2->GetSizeOfSet();
        int smaller_size = (sizeSet1 < sizeSet2) ? sizeSet1 : sizeSet2;
        Set<T>* larger_set = (sizeSet1 >= sizeSet2) ? set1 : set2;
        Set<T>* smaller_set = (sizeSet1 < sizeSet2) ? set1 : set2;

        larger_set->IncreaseSizeOfSetBy(smaller_size);
        smaller_set->GetRootOfSet()->SetParent(larger_set->GetRootOfSet());
        smaller_set->GetRootOfSet()->SetSetOfTree(NULL);
        SetSet(smaller_set->GetIdOfSet(),NULL);
        delete smaller_set;

        return larger_set;
    }

    Set<T>* Find(int value)
    {
        ReversedTreeNode<T> *current_element = GetElement(value);
        ReversedTreeNode<T> *next_element;
        ReversedTreeNode<T> *root = GetElement(value);
        
        while(root->GetParent() != NULL)
        {
            root = root->GetParent();
        }

        while(current_element->GetValue() != root->GetValue())
        {
            next_element = current_element->GetParent();
            current_element->SetParent(root);
            current_element = next_element;
        }

        return root->GetSetOfTree();
    }

    void Print() 
    { 
        ;

        /*
        for(int i=0; i<MAX_NUM_OF_ELEMENTS; i++)
            if(GetElement(i)!= NULL)
            {
                std::cout << "Element " << i << " belongs to ";
                Find(i)->Print(); 
            }
        std::cout << "------------------------------" << std::endl;
        
        
        for(int i=0; i<MAX_NUM_OF_ELEMENTS; i++)
            if(GetElement(i)!= NULL)
            {
                if(GetElement(i)->GetParent()!=NULL)
                    std::cout << i << " -> " << GetElement(i)->GetParent()->GetValue() << std::endl;
                else
                    std::cout << i << " -> " << "NULL" << std::endl;
            }
            
        */
        
    }

};
#endif // DISJOINT_SETE_H



