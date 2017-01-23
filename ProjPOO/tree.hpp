#ifndef TREE_H
#define TREE_H

#include <vector>
#include <QString>
#include <QDebug>
#include <iostream>
#include <typeinfo>
#include "administrator.hpp"

class Administrator;
typedef struct Node
{
    std::vector<Node*> children;
    User user;
    Node *father;
} Node;
typedef struct Node1
{
    std::vector<Node*> children;
    Administrator* user;
    Node *father;
} Node1;

class Tree {
private:
    Node *boss;
    Node1 *boss1;
    int marker;
public:
    Tree(){
        boss = new Node;
        boss= NULL;
    }

    Tree( Node* b){
        boss = new Node ;
        boss->user = b->user;
        boss->father = NULL;
        marker = 1;
    }

    Tree (Node1* b){
        boss1 = new Node1;
        boss1->user = (b->user);
        marker = 2;
    }

    Node* getNode(){
        return boss;
    }

    void traverse();
    Node* traverse(QString);
    Node* find(QString);
    void traverse(Node* n);
    Node* traverse(Node* n , QString name,int * ceva);
    void internAdd(Node* n,Node* father,QString boss);
    void add(Node* n , QString boss);
    bool check (Node* n , QString name , int * ceva);
    bool check ( QString );
    void setBoss(Node *n);
    void setBoss(Node1 *n);
    std::vector<Node*> getChildren();

};
#endif
