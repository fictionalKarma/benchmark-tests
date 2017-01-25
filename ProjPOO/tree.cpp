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
    if(marker == 2){
        Node *b = new Node;
        b->children = boss1->children ;
        b->user.setUserName(boss1->user->getUserName());
        traverse(b);
    }
    else
        traverse(boss);
	qDebug() <<"\n";
}
void Tree::traverse(int& count){
    //Node *b  = boss ;
    if(marker == 2){
        Node *b = new Node;
        b->children = boss1->children ;
        b->user.setUserName(boss1->user->getUserName());
        traverse(count,b);
    }
    else
        traverse(count,boss);
    qDebug() <<"\n";
}
void Tree::traverse(int& count,Node *n){

    Node *b = n ;

    for( std::vector<Node*>::iterator it = n->children.begin(); it != n->children.end(); ++it){
        //for (Node* it : children) {
            Tree::traverse(count,*it );
        }
    count++;
}
Node* Tree::traverse(QString name){
    int i = 0;

    if(marker == 2){

        Node *b = new Node;
        b->children = boss1->children ;
        b->user.setUserName(boss1->user->getUserName());
        //traverse(b);
        if( b->user.getUserName()==name){
            //qDebug ()<< boss->user.getUserName() ;
            return b;
        }

        else{

            Node *b1;
            b1 = traverse(b,name,&i);
            return b1;
        }
    }
    else{
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
        qDebug()<< n->user.getUserName();
        return n;
    }
    for( std::vector<Node*>::iterator it = n->children.begin(); it != n->children.end(); ++it){
        for (Node* it : n->children) {
            //qDebug() <<"COPIL :"<< it->user.getUserName();
            b = Tree::traverse(it,name , i );
            if( *i == 1){
                //qDebug() << b->user.getUserName()<<" GASIT !!!";
                return b;
            }
            //else if (b == NULL)
                //return NULL;
        }
    if(boss->children.at(boss->children.size()-1) == n)
        return NULL;
    }
}
void Tree::add(Node* n , QString sef){
    if( marker == 1){
        if( boss == NULL){
		boss = n ;
		boss->father = NULL;
        }
        else
            this->Tree::internAdd(n,boss,sef);
    }
    else if ( marker == 2){
        Node* b = new Node;
        b->children = boss1->children ;
        b->user.setUserName(boss1->user->getUserName());
        //qDebug () << b->user.getUserName();
        internAdd(n,b,sef);
        boss1->children  = b->children ;
    }
}

Node* Tree::find(QString name){


     Node *b = traverse(name);

     if(b == NULL) qDebug()<<"NULL POINTER";
     return b ;
}

bool Tree::check(QString name){
    int i = 0;
    if( marker == 2){
        Node *b1 = new Node;
        b1->children = boss1->children;
        b1->user.setUserName(boss1->user->getUserName());
        if( b1->user.getUserName()==name){
            //qDebug ()<< boss->user.getUserName() ;
            return true ;
        }
        else{
            //qDebug() << "AICI";
            bool b;
            b= check(b1,name,&i);
            return b;
           // qDebug ()<< b->user.getUserName();

        }
    }
    else{
        if( boss->user.getUserName()==name){
            //qDebug ()<< boss->user.getUserName() ;
            return true ;
        }
        else{
            bool b ;
            b = check(boss,name,&i);
           // qDebug ()<< b->user.getUserName();
            return b;
        }
    }

}

bool Tree::check(Node *n,QString name , int* i){
    bool b;
    if(n->user.getUserName() == name){
        *i = 1;
        //qDebug()<< n->user.getUserName();
        return true;
    }
    for( std::vector<Node*>::iterator it = n->children.begin(); it != n->children.end(); ++it){
        //for (Node* it : children) {
            b = Tree::check(*it,name , i );
            if( *i == 1){
                //qDebug() << b->user.getUserName();
                return b;
            }
            else if (b == false)
                return b;
        }
    if(boss->children.at(boss->children.size()-1) == n)
        return false;

}
void Tree::setBoss(Node* n){
    boss = n ;
    marker = 1;
}
void Tree::setBoss(Node1* n){
    boss1 = n;
    marker = 2;
}
