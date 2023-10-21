//
// Created by Kareem Elnaghy on 10/21/23.
//

#include "BinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

template<class Key, class Data>
void BT<Key, Data>::remove(const Key &) {

}

template<class Key, class Data>             //retrieve data function
Data *BT<Key, Data>::retrieve(Node<Key,Data>* currentRoot,const Key &k) {
    Data* d = search(currentRoot,k)->data;
    return d;
}

template<class Key, class Data>             //Search function
Node<Key,Data> *BT<Key, Data>::search(Node<Key,Data>* currentRoot,const Key &k) {
    if(currentRoot == NULL)
        return nullptr;
    else if(k == currentRoot->key)
        return currentRoot;
    else if(k<currentRoot->left)
        return search(currentRoot->left,k);
    else
        return search(currentRoot->right,k);
}

template<class Key, class Data>             //checks if tree is empty
bool BT<Key, Data>::isEmpty() const {
    if(root == NULL)
        return true;
    return false;
}

template<class Key, class Data>
void BT<Key, Data>::insert(Node<Key,Data>* currentRoot, const Key& k, const Data& d) {  //insert fuction
    if (!currentRoot) {
        currentRoot = new Node<Key, Data>(k, d);
    }
    else if(k < currentRoot->key)
        return insert(currentRoot->left, k , d);
    else
        return insert(currentRoot->left, k , d);
}

template<class Key, class Data>
BT<Key, Data>::~BT() {      //destructor

}

template<class Key, class Data>
BT<Key, Data>::BT() { root = nullptr;
} //constructor