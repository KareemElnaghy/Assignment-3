//
// Created by Kareem Elnaghy on 10/21/23.
//
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Stackt.h"
#include "KeyAndData.h"
#include "Queuet.h"
#include <cmath>
using namespace std;
#ifndef ADS_ASSIGNMENT_3_BINARYTREE_H
#define ADS_ASSIGNMENT_3_BINARYTREE_H



template <class keyType, class dataType>

class binaryTree
{

public:

    // Public Member functions ...
    // CREATE AN EMPTY TREE
    binaryTree();

    // INSERT AN ELEMENT INTO THE TREE
    bool insert (const keyType &, const dataType &);

    // CHECK IF THE TREE IS EMPTY
    bool empty() const;

    // SEARCH FOR A KEY IN THE TREE
    bool search (const keyType &) const;

    // RETRIEVE DATA FOR A GIVEN KEY
    bool retrieve (const keyType &, dataType &) const;

    // TRAVERSE A TREE
    void traverse() const;

    // Iterative Pre-order Traversal
    void preorder () const;

    // Iterative Level-order Traversal
    void levelorder () const;

    // GRAPHIC OUTPUT
    void graph() const;

    // REMOVE AN ELEMENT FROM THE TREE
    void remove (const keyType &);

    void saveFile2(string );


private:
    // Node Class
    class treeNode
    {
    public:
        keyType key; 		// key
        dataType data;		// Data
        treeNode *left;		// left subtree
        treeNode *right;	// right subtree
    }; // end of class treeNode declaration

    typedef treeNode * NodePointer;
    // Data member ....
    NodePointer root;

    // Private Member functions ...

    // Searches a subtree for a key
    bool search2 (NodePointer , const keyType &) const;

    // Searches a subtree for a key and retrieves data
    bool retrieve2 (NodePointer , const keyType & , dataType &) const;

    // Inserts an item in a subtree
    bool insert2 (NodePointer &, const keyType &, const dataType &);

    // Traverses a subtree
    void traverse2 (NodePointer ) const;

    // Graphic output of a subtree
    void graph2 (int ,NodePointer ) const;

    // LOCATE A NODE CONTAINING ELEMENT AND ITS PARENT
    void parentSearch ( const keyType &k, bool &found,
                        NodePointer &locptr, NodePointer &parent) const;


    void saveFile(ofstream&, NodePointer);

};






#endif //ADS_ASSIGNMENT_3_BINARYTREE_H
