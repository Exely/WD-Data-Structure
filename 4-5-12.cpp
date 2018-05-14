#include<iostream>
using namespace std;
#define ELEMTYPE int
#define MAXSIZE 50
#define END 9999
typedef struct BNode{
    struct BNode* lchild;
    struct BNode* rchild;
    ELEMTYPE key;
    int count;
}BNode,*BST;
int count=0;
BST fun(BST T,int k){
    if(T){
        BST t;
        if(t=fun(T->lchild,k))return t;
        count++;
        if(k==count)return T;
        if(t=fun(T->rchild,k))return t;
    }
    return NULL;
}
bool BST_Insert(BST &T,ELEMTYPE x);
void InitBST(BST &T,ELEMTYPE L[]);
void Print_BST(BST T,int tag);
BST BST_search(BST T,ELEMTYPE value);
int main(){
    ELEMTYPE L[MAXSIZE];
    ELEMTYPE c;
    cin>>c;
    int i=0;
    for(i=0;i<MAXSIZE&&c!=END;i++){
        L[i]=c;
        cin>>c;
    }
    L[i]=c;
    BST T=NULL;
    InitBST(T,L);
    cin>>c;
    BST p;
    p=fun(T,c);
    if(p)cout<<"find:"<<p->key<<endl;
    Print_BST(T,2);
    cout<<endl;
    return 0;
}
BST BST_search(BST T,ELEMTYPE value){
    if(!T)return NULL;
    if(T->key>value)return BST_search(T->lchild,value);
    else if(T->key<value)return BST_search(T->rchild,value);
    else return T;
    return NULL;
}
bool BST_Insert(BST &T,ELEMTYPE x){
    if(T){
        if(x<T->key)return BST_Insert(T->lchild,x);
        else if(x>T->key)return BST_Insert(T->rchild,x);
        else return false;
    }else{
        T=(BST)malloc(sizeof(BNode));
        T->key=x;
        T->lchild=NULL;
        T->rchild=NULL;
        return true;
    }
}
void InitBST(BST &T,ELEMTYPE L[]){
    for(int i=0;L[i]!=END;i++){
        BST_Insert(T,L[i]);
    }
}
void Print_BST(BST T,int tag){
    if(!T)return ;
    if(tag==1)cout<<T->key<<" ";
    Print_BST(T->lchild,tag);
    if(tag==2)cout<<T->key<<" ";
    Print_BST(T->rchild,tag);
    if(tag==3)cout<<T->key<<" ";
    free(T);
}
