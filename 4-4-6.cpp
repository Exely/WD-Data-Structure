#include<iostream>
#define ELEMTYPE int
#define MAXSIZE 50
#define END 9999
#define NOP -1
using namespace std;
typedef struct TreeNode{
    ELEMTYPE data;
    struct TreeNode *firstchild,*nextsibling;
}TreeNode,*Tree;
typedef struct ListNode{
    int firstchild;
    int nextsibling;
    ELEMTYPE data;
}List;
int fun(Tree T){
    if(T){
        int tmp1,tmp2;
        if(T->firstchild)tmp1=1+fun(T->firstchild);
        else tmp1=0;
        tmp2=fun(T->nextsibling);
        return max(tmp1,tmp2);
    }
    return 1;
}
void InitTreeWithList(Tree &T,List L[],int index);
void PrintTree(Tree T,int x);
void InitList(List L[]);
int main(){
    Tree T;
    //以下是一个预置的初始化数组
    //不使用第一项
    List L0[13]={{0,0,0},{2,NOP,11},{NOP,3,12},{6,4,13},{8,5,14},{NOP,NOP,15},{NOP,7,16},{9,NOP,17},{NOP,NOP,18},{NOP,10,19},{12,11,20},{NOP,NOP,21},{NOP,NOP,22}};
    List L[MAXSIZE];
    //InitList(L);
    InitTreeWithList(T,L0,1);
    cout<<"count:"<<fun(T)<<endl;
    PrintTree(T,1);
    cout<<endl;
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
        L[i].firstchild=x;
        L[i].nextsibling=y;
        L[i].data=d;
    }
}
void InitTreeWithList(Tree &T,List L[],int index){
    if(index!=NOP){
        Tree nd=(Tree)malloc(sizeof(TreeNode));
        nd->data=L[index].data;
        T=nd;
        InitTreeWithList(T->firstchild,L,L[index].firstchild);
        InitTreeWithList(T->nextsibling,L,L[index].nextsibling);
    }else{
        T=NULL;
    }
}
// 1 for PreOrder,2 for InOrder,3 for PostOrder
void PrintTree(Tree T,int x){
    if(T){
        if(x==1){
            cout<<T->data<<" ";
        }
        PrintTree(T->firstchild,x);
        if(x==2){
            cout<<T->data<<" ";
        }
        PrintTree(T->nextsibling,x);
        if(x==3){
            cout<<T->data<<" ";
        }
        free(T);
    }
}

