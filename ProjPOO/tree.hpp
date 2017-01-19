#ifndef TREE_H
#define TREE_H
#include <vector>
#include <QString>
#include <QDebug>
#include <iostream>
#include "user.h"
typedef struct Node
{
    std::vector<Node*> children;
    User user;
    Node *father;
}Node;

class Tree {
private:
	Node *boss;
public:
	Tree(){
		boss = new Node;
		boss= NULL;

	}
	Tree( Node* b){
        //qDebug () << "AICI\n";
		boss = new Node ;
		boss->user = b->user;
		boss->father = NULL;

	}
	Node* getNode(){
		return boss;
	}
	void traverse();
    Node* traverse(QString);
    void find(QString);
	void traverse(Node* n);
    Node* traverse(Node* n , QString name,int * ceva);
    void internAdd(Node* n,Node* father,QString boss);
    void add(Node* n , QString boss);
    std::vector<Node*> getChildren();
};
#endif
