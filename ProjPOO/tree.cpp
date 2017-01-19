#include "tree.hpp"


std::vector<Node*> Tree::getChildren(){
    return boss->children;
}

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
Node* Tree::traverse(QString name){

    int i = 0;
    if( boss->user.getUserName()==name){
        qDebug ()<< boss->user.getUserName() ;
        return boss ;
    }
    else{
        Node *b;
        b = traverse(boss,name,&i);
       // qDebug ()<< b->user.getUserName();
        return b;
    }

}
void Tree::traverse(Node *n){
    Node *b = n ;

    for( std::vector<Node*>::iterator it = n->children.begin(); it != n->children.end(); ++it){
        //for (Node* it : children) {
            Tree::traverse(*it );
        }
    qDebug() << n->user.getUserName() << " " ;
	
}
Node* Tree::traverse(Node *n,QString name , int* i){
    Node *b ;
    if(n->user.getUserName() == name){
        *i = 1;
        //qDebug()<< n->user.getUserName();
        return n;
    }
    for( std::vector<Node*>::iterator it = n->children.begin(); it != n->children.end(); ++it){
        //for (Node* it : children) {
            b = Tree::traverse(*it,name , i );
            if( *i == 1){
                //qDebug() << b->user.getUserName();
                return b;
            }
        }
    if(boss->children.at(boss->children.size()-1) == n)
        return NULL;

}
void Tree::add(Node* n , QString sef){

	if( boss == NULL){
		boss = n ;
		boss->father = NULL;
	}
	else
		this->Tree::internAdd(n,boss,sef);
}

void Tree::find(QString name){
     traverse(name);
}
