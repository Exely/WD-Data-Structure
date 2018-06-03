#include<iostream>
#include<stack>
using namespace std;
#define MAXSIZE 50
#define DATATYPE int
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
int FirstNeighbor(Graph &G,int v){
    if(G.vertices[v].next)return G.vertices[v].next->adjvex;
    else return -1;
}
int NextNeighbor(Graph &G,int v,int w){
    Arc p;
    for(p=G.vertices[v].next;p;p=p->next){
        if(p->adjvex==w){
            if(p->next){
                return p->next->adjvex;
            }else return -1;
        }
    }
    return -1;
}
bool visted[MAXSIZE];
void DFS(Graph &G,int v){
    int p;
    cout<<v<<" ";
    visted[v]=true;
    for(p=FirstNeighbor(G,v);p!=-1;p=NextNeighbor(G,v,p)){
        if(!visted[p])
            DFS(G,p);
    }
}
void fun(Graph &G,int v){
    stack<int> s;
    int p,w;
    s.push(v);
    visted[v]=true;
    while(!s.empty()){
        w=s.top();
        s.pop();
        cout<<w<<" ";
        for(p=FirstNeighbor(G,w);p!=-1;p=NextNeighbor(G,w,p)){
            if(!visted[p]){
                s.push(p);//在此令visted为true 避免重复入栈
                visted[p]=true;
            }
        }
    }
}
int main(){
    for(int i=0;i<MAXSIZE;i++)visted[i]=false;
    Graph G;
    InitGraph(G);
    DFS(G,0);
    cout<<endl;
    for(int i=0;i<G.vexnum;i++)visted[i]=false;
    fun(G,0);
    cout<<endl;
    PrintAdjList(G);
    return 0;
}
