//
// Created by Kareem Elnaghy on 10/21/23.
//
#include <string>
#include "KeyAndData.h"
using namespace std;
#ifndef ADS_ASSIGNMENT_3_BINARYTREE_H
#define ADS_ASSIGNMENT_3_BINARYTREE_H


template<class Key, class Data>
class Node          //template class for nodes of the BT
{
public:
    Key key;
    Data data;
    Node* left;
    Node* right;
    Node():left(NULL), right(NULL){};
    Node(Key k, Data d):key(k), data(d), left(NULL), right(NULL){}
};

template<class Key, class Data>
class BT
{
private:
    Node<Key, Data>* root;

public:

    BT();
    ~BT();
    void insert(Node<Key,Data>* root, const Key&, const Data&);
    bool isEmpty() const;
    Node<Key,Data>* search (Node<Key,Data>*, const Key&);
    Data* retrieve(Node<Key,Data>*,const Key&);
    // void Traverse();
    // void preorder();
    // void levelorder();
    void remove(const Key&);
};




#endif //ADS_ASSIGNMENT_3_BINARYTREE_H
