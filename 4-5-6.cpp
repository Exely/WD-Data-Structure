#include<iostream>
#define ELEMTYPE int
#define MAXSIZE 50
#define END 9999
#define NOP -1
#define LEFT 3
#define RIGHT 1
using namespace std;
typedef struct BiNode{
    ELEMTYPE data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
typedef struct ListNode{
    int lchild;
    int rchild;
    ELEMTYPE data;
}List;
void fun_start(BiTree &T);
bool flag=true;
int fun(BiTree T,int tag){
    if(T&&flag){
        int minval,maxval;
        if(T->lchild)maxval=fun(T->lchild,LEFT);
        else maxval=T->data;
        if(T->rchild)minval=fun(T->rchild,RIGHT);
        else minval=T->data;
        //cout<<T->data<<":"<<maxval<<" "<<minval<<endl;
        if(!T->lchild&&!T->rchild)return T->data;
        else if(!T->lchild&&T->rchild){
            if(T->data>=minval)flag=false;
        }else if(T->rchild&&!T->lchild){
            if(T->data<=maxval)flag=false;
        }else if(T->lchild&&T->rchild){
            if(T->data>=minval||T->data<=maxval)flag=false;
        }
        if(tag==LEFT)return maxval;
        if(tag==RIGHT)return minval;
    }
    return 0;
}
//不使用第一项
void InitList(List L[]){
    int x=0,y=0,n=0;
    ELEMTYPE d;
    L[0]={0,0,0};
    cout<<"input numbers of tree node:"<<endl;
    cin>>n;
    for(int i=1;n<MAXSIZE&&i<=n;i++){
        cin>>x>>y>>d;
        L[i].lchild=x;
        L[i].rchild=y;
        L[i].data=d;
    }
}
void InitTreeWithList(BiTree &T,List L[],int index){
    if(index!=NOP){
        BiTree nd=(BiTree)malloc(sizeof(BiNode));
        nd->data=L[index].data;
        T=nd;
        InitTreeWithList(T->lchild,L,L[index].lchild);
        InitTreeWithList(T->rchild,L,L[index].rchild);
    }else{
        T=NULL;
    }
}
// 1 for PreOrder,2 for InOrder,3 for PostOrder
void PrintTree(BiTree T,int x){
    if(T){
        if(x==1){
            cout<<T->data<<" ";
        }
        PrintTree(T->lchild,x);
        if(x==2){
            cout<<T->data<<" ";
        }
        PrintTree(T->rchild,x);
        if(x==3){
            cout<<T->data<<" ";
        }
        free(T);
    }
}
void fun_start(BiTree &T){
    //以下是一个预置的初始化数组
    //不使用第一项
    // List L0[10]={{0,0,0},{2,3,11},{4,5,12},{6,NOP,13},{NOP,7,14},{NOP,8,15},{NOP,NOP,16},{9,NOP,17},{NOP,NOP,18},{NOP,NOP,19}};
    List L[MAXSIZE];
    InitList(L);
    InitTreeWithList(T,L,1);
    int minval=1,maxval=1;
    maxval=fun(T,LEFT);
    //cout<<minval<<" "<<maxval<<endl;
    cout<<(flag?"true":"false")<<endl;
    PrintTree(T,1);
}
int main(){
    BiTree T;
    fun_start(T);
    cout<<endl;
    return 0;
}
