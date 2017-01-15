#include "tree.hpp"

void Tree::internAdd(Node* n,Node* fathe,QString sef){

    if( fathe->user.getUserName() == sef){
		n->father = fathe;
		fathe->children.push_back(n);
	}
	else{

        for( std::vector<Node*>::iterator it = fathe->children.begin(); it != fathe->children.end(); ++it){
        //for (Node* it : children) {
            Tree::internAdd(n, *it, sef);
            //qDebug () << (*it)->user.getUserName()<<"AICI\n";
        }



	}
}
void Tree::traverse(){
    //Node *b  = boss ;
	traverse(boss);
	qDebug() <<"\n";
}
void Tree::traverse(Node *n){
    Node *b = n ;

    for( std::vector<Node*>::iterator it = n->children.begin(); it != n->children.end(); ++it){
        //for (Node* it : children) {
            Tree::traverse(*it );
        }
    qDebug() << n->user.getUserName() << " " ;
	
}
void Tree::add(Node* n , QString sef){

	if( boss == NULL){
		boss = n ;
		boss->father = NULL;
	}
	else
		this->Tree::internAdd(n,boss,sef);
}
