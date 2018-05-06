#include<iostream>
#define ELEMTYPE int
#define MAXSIZE 50
#define END 9999
#define NOP -1
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
void fun(BiTree &T){
    struct SNode{BiTree node;bool rvisited;}stk[MAXSIZE];
    int top=0;
    BiTree p;
    struct SNode sn;
    for(p=T;p;p=p->lchild){
        stk[top].node=p;
        stk[top].rvisited=false;
        top++;
    }
   // int count=0;
    while(top){
        sn=stk[top-1];
//        count++;
//        if(count==8)break;
//        cout<<top-1<<":"<<sn.node->data<<"|"<<(sn.rvisited?"true":"false")<<" "<<endl;
        if((sn.node->rchild==NULL)||sn.rvisited){ //注意右子树为空
            p=stk[--top].node;
            cout<<p->data<<" ";
        }else{
//bug笔记：stk[top-1]不能写成sn，因为这是sn是表示结构的变量，不是指针
            stk[top-1].rvisited=true;
            for(p=sn.node->rchild;p;p=p->lchild){
                stk[top].node=p;
                stk[top].rvisited=false;
//                cout<<p->data<<":"<<sn.rvisited<<endl;
                top++;
            }
        }
    }
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
    List L0[10]={{0,0,0},{2,3,11},{4,5,12},{6,NOP,13},{NOP,7,14},{NOP,8,15},{NOP,NOP,16},{9,NOP,17},{NOP,NOP,18},{NOP,NOP,19}};
//    List L[MAXSIZE];
//    InitList(L);
    InitTreeWithList(T,L0,1);
    cout<<"fun:"<<endl;
    fun(T);
    cout<<endl;
    cout<<"BiTree:"<<endl;
    PrintTree(T,3);
}



int main(){
    BiTree T;
    fun_start(T);
    cout<<endl;
    return 0;
}
