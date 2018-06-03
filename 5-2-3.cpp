#include<iostream>
using namespace std;
#define MAXSIZE 50
#define DATATYPE int
#define NOP -1
//邻接表表示的图 无向图arcnum等于2×边数
typedef struct ArcNode{
    int value;
    int adjvex;
    struct ArcNode *next;
}ArcNode,*Arc;
typedef struct VNode{
    ArcNode *next;
    DATATYPE data;
}VNode,AdjList[MAXSIZE];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}Graph;
void AddArc(Graph &G,int x,int y,int value){
    Arc p,pre=NULL,s;
    for(p=G.vertices[x].next;p;pre=p,p=p->next){
        if(p->adjvex==y)return;
    }
    s=(Arc)malloc(sizeof(ArcNode));
    s->adjvex=y;
    s->value=value;
    s->next=NULL;
    if(pre)pre->next=s;
    else{
        G.vertices[x].next=s;
    }
}
void InitGraph(Graph &g){
    int vn,an,x=0,num1,num2,value;
    cin>>vn;
    cin>>an;
    g.vexnum=vn;
    g.arcnum=an;
    for(int i=0;i<g.vexnum;i++){
        g.vertices[i].next=NULL;
    }
    for(x=0;x<an;x++){
        cin>>num1;
        cin>>num2;
        cin>>value;
        AddArc(g,num1,num2,value);
    }
}
void PrintAdjList(Graph g){
    Arc p,tmp;
    for(int i=0;i<g.vexnum;i++){
        p=g.vertices[i].next;
        while(p){
            cout<<i<<"-"<<p->adjvex<<":"<<p->value<<" ";
            tmp=p->next;
            free(p);
            p=tmp;
        }
        cout<<endl;
    }
}
void InitEdge(Graph &g,int Edge[][MAXSIZE]){
    Arc p;
    for(int i=0;i<g.vexnum;i++){
        for(int j=0;j<g.vexnum;j++)
            if(i==j)Edge[i][j]=0;
            else Edge[i][j]=NOP;
    }
    for(int i=0;i<g.vexnum;i++){
        for(p=g.vertices[i].next;p;p=p->next)Edge[i][p->adjvex]=p->value;
    }
}
void PrintEdge(Graph &g,int Edge[][MAXSIZE]){
    for(int i=0;i<g.vexnum;i++){
        for(int j=0;j<g.vexnum;j++)cout<<Edge[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    Graph G;
    InitGraph(G);
    //PrintAdjList(G);
    int Edge[MAXSIZE][MAXSIZE];
    InitEdge(G,Edge);
    PrintEdge(G,Edge);
    PrintAdjList(G);
    return 0;
}
