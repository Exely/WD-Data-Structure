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
BST fun(BST T,int k){
    if(k<1||T->count<k)return NULL;
    else if(!T->lchild){
        if(k==1)return T;
        else return fun(T->rchild,k-1);
    }else {
        if(T->lchild->count>k-1)return fun(T->lchild,k); //bug:注意是k-1，count为该子树结点数！
        else if(T->lchild->count==k-1)return T;
        else return fun(T->rchild,k-(1+T->lchild->count));
    }
    return NULL;
}
bool BST_Insert(BST &T,ELEMTYPE x);
void InitBST(BST &T,ELEMTYPE L[]);
void Print_BST(BST T,int tag);
BST BST_search(BST T,ELEMTYPE value);
int BST_count(BST &T);
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
    BST_count(T);
    cin>>c;
    BST p;
    p=fun(T,c);
    if(p)cout<<"p:"<<p->key<<endl;
    Print_BST(T,2);
    cout<<endl;
    return 0;
}
int BST_count(BST &T){
    if(T){
        int count;
        count=BST_count(T->lchild);
        count+=BST_count(T->rchild);
        T->count=count+1;
        return count+1;
    }
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
    if(tag==1)cout<<T->key<<":"<<T->count<<" ";
    Print_BST(T->lchild,tag);
    if(tag==2)cout<<T->key<<":"<<T->count<<" ";
    Print_BST(T->rchild,tag);
    if(tag==3)cout<<T->key<<":"<<T->count<<" ";
    free(T);
}
