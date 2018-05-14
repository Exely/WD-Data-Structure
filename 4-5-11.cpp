#include<iostream>
using namespace std;
#define MAXSIZE 50
#define END 9999
typedef struct HNode{
    struct HNode* lchild;
    struct HNode* rchild;
    int data;
    int count;
}HNode,*HTree;
typedef struct forestNode{
    HTree data;
    struct forestNode* next;
}forestNode,*forest;
int HTree_WPL(HTree T,int level){
    static int WPL=0;
    if(T){
        if(T->lchild)HTree_WPL(T->lchild,level+1);
        if(T->rchild)HTree_WPL(T->rchild,level+1);
        if(!T->lchild&&!T->rchild)WPL+=level*T->data;
    }
    return WPL;
}
void InitForest(forest &F,int L[]);
void InitHTree(HTree &T,forest &F);
void Print_HTree(HTree T,int tag);
void QSort(int L[],int low,int high);
int main(){
    int L[MAXSIZE];
    int c;
    cin>>c;
    int i=0;
    for(i=0;i<MAXSIZE&&c!=END;i++){
        L[i]=c;
        cin>>c;
    }
    if(i==0)return 0;
    L[i]=c;
    HTree T=NULL;
    forest F=NULL;
    //forest p=NULL;
    QSort(L,0,i-1);
    //带头结点
    InitForest(F,L);
    InitHTree(T,F);
    /*p=F->next;
      while(p)
      {
      cout<<p->data->data<<" ";
      p=p->next;
      }*/
    cout<<"WPL:"<<HTree_WPL(T,0)<<endl;
    Print_HTree(T,1);
    cout<<endl;
    return 0;
}
void QSort(int L[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        int tmp=L[low];
        L[low]=L[mid];
        L[mid]=tmp;
        tmp=L[low];
        int i=low,j=high;
        while(i<j){
            for(;i<j&&L[j]>=tmp;j--);
            L[i]=L[j];
            for(;i<j&&L[i]<tmp;i++);
            L[j]=L[i];
        }
        L[i]=tmp;
        QSort(L,low,i-1);
        QSort(L,i+1,high);
    }
}
void ForestInsert(forest &f,forest &F){
    forest pre=F,p=F->next;
    for(;p&&p->data->data<=f->data->data;pre=pre->next,p=p->next);
    f->next=pre->next;
    pre->next=f;
}
void InitHTree(HTree &T,forest &F){
    forest p=F;
    HTree tmp;
    while(F->next&&F->next->next){
        p=F->next;
        tmp=(HTree)malloc(sizeof(HNode));
        tmp->data=p->data->data+p->next->data->data;
        tmp->lchild=p->data;
        tmp->rchild=p->next->data;
        p->next->data=tmp;
        F->next=p->next->next;
        ForestInsert(p->next,F);
        free(p);
    }
    T=F->next->data;
    free(F->next);
    free(F);
}
void InitForest(forest &F,int L[]){
    forest p,s;
    F=(forest)malloc(sizeof(forestNode));
    F->next=NULL;
    p=F;
    for(int i=0;L[i]!=END;i++){
        s=(forest)malloc(sizeof(forestNode));
        s->data=(HTree)malloc(sizeof(HNode));
        s->data->lchild=NULL;
        s->data->rchild=NULL;
        s->data->data=L[i];
        s->next=p->next;
        p->next=s;
        p=p->next;
    }
}
void Print_HTree(HTree T,int tag){
    if(!T)return ;
    if(tag==1)cout<<T->data<<" ";
    Print_HTree(T->lchild,tag);
    if(tag==2)cout<<T->data<<" ";
    Print_HTree(T->rchild,tag);
    if(tag==3)cout<<T->data<<" ";
    free(T);
}
