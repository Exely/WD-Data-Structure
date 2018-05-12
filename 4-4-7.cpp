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
typedef struct DegreeList{
    int degree;
    ELEMTYPE data;
}DegNode;
void fun(List L[],DegNode tl[]){
    L[1].data=tl[1].data;
    L[1].nextsibling=NOP;
    int pre=1,last=2,next=2;//各层次起始
    while(pre<next){
        last=next;//保存下层next
        for(;pre<last;pre++){//扫描前一层 从pre开始至下层next
            L[pre].firstchild=NOP;
            L[pre].data=tl[pre].data;
            if(tl[pre].degree){
                L[pre].firstchild=next;
                for(int j=0;j<tl[pre].degree-1;j++){
                    L[next].nextsibling=next+1;
                    next++;
                }
                L[next].nextsibling=NOP;
                next++;
            } 
        }
    }
}
void InitTreeWithList(Tree &T,List L[],int index);
void PrintTree(Tree T,int x);
void InitList(List L[]);
int main(){
    Tree T1;
    Tree T2;
    //以下是一个预置的初始化数组
    //不使用第一项
    List L0[12]={{0,0,0},{2,NOP,11},{NOP,3,12},{6,4,13},{8,5,14},{NOP,NOP,15},{NOP,7,16},{9,NOP,17},{NOP,11,18},{NOP,10,19},{NOP,NOP,20},{NOP,NOP,21}};
    List L[MAXSIZE];
    DegNode tl[12]={{0,0},{4,11},{0,12},{2,13},{1,14},{0,15},{0,16},{2,17},{1,18},{0,19},{0,20},{0,21}};
    //InitList(L);
    InitTreeWithList(T1,L0,1);
    fun(L,tl);
    InitTreeWithList(T2,L,1);
    for(int i=1;i<12;i++)
    {
        cout<<"{"<<L[i].firstchild<<","<<L[i].nextsibling<<","<<L[i].data<<"},";
    }
    cout<<endl<<"T2:"<<endl;
    PrintTree(T2,1);
    cout<<endl<<"T1:"<<endl;
    PrintTree(T1,1);
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
