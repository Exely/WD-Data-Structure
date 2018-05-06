#include<iostream>
#define ELEMTYPE int
#define MAXSIZE 50
#define END 9999
#define NOP -1
using namespace std;
typedef struct BiNode{
    ELEMTYPE data;
    struct BiNode *lchild,*rchild;
    int ltag,rtag;
}BiNode,*BiTree;
typedef struct ListNode{
    int lchild;
    int rchild;
    ELEMTYPE data;
}List;
//中序线索化
void InThread(BiTree &p,BiTree &pre){
    if(p){
        if(p->lchild)InThread(p->lchild,pre);
        else{
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre&&!pre->rchild){
            pre->rtag=1;
            pre->rchild=p;
        }
        pre=p;
        if(p->rchild)InThread(p->rchild,pre);
    }
}
BiTree FirstNode(BiTree T){
    if(T){
        while(!T->ltag)T=T->lchild;
    }
    return T;
}
BiTree NextNode(BiTree T){
    if(T){
        if(!T->rtag)return FirstNode(T->rchild);
        else return T->rchild;
    }
    return NULL;
}
void InOrder(BiTree T){
    BiTree p;
    for(p=FirstNode(T);p;p=NextNode(p)){
        cout<<p->data<<" ";
    }
    cout<<endl;
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
        nd->ltag=0;
        nd->rtag=0;
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
        if(!T->ltag)PrintTree(T->lchild,x);
        if(x==2){
            cout<<T->data<<" ";
        }
        if(!T->rtag)PrintTree(T->rchild,x);
        if(x==3){
            cout<<T->data<<" ";
        }
        free(T);
    }
}
BiTree FindPointer(BiTree T,ELEMTYPE x){
    if(T){
        if(T->data==x)return T;
        BiTree p1=NULL,p2=NULL;
        if(!T->ltag)p1=FindPointer(T->lchild,x);
        if(p1)return p1;
        if(!T->rtag)p2=FindPointer(T->rchild,x);
        if(p2)return p2;
    }
    return NULL;
}
BiTree fun(BiTree &T,BiTree p){
    if(p){
        if(!p->rtag)return p->rchild;
        else if(!p->ltag){
            p=p->lchild;
        }else{
            while(p&&p->ltag){
                p=p->lchild;
            }
            if(p)return p->lchild;
        }
    }
    return p;
}
void fun_start(BiTree &T){
    //以下是一个预置的初始化数组
    //不使用第一项
    List L0[10]={{0,0,0},{2,3,11},{4,5,12},{6,NOP,13},{NOP,7,14},{NOP,8,15},{NOP,NOP,16},{9,NOP,17},{NOP,NOP,18},{NOP,NOP,19}};
    //List L[MAXSIZE];
    //InitList(L);
    InitTreeWithList(T,L0,1);
    cout<<"InOrder:"<<endl;
    BiTree p=NULL,q;
    InThread(T,p);
    if(p){
        p->rtag=1;
        p->rchild=NULL;
    }
    InOrder(T);
    int x;
    cout<<"fun:input x"<<endl;
    cin>>x;
    p=FindPointer(T,x);
    q=fun(T,p);
    if(p&&q)cout<<"previous,present:"<<q->data<<" "<<p->data<<endl;
    else cout<<"Not Found"<<endl;
    cout<<"PrintTree:"<<endl;
    PrintTree(T,3);
}
int main(){
    BiTree T;
    fun_start(T);
    return 0;
}
