#include <iostream>
using namespace std;

const int V=4, INF=99999;

int main() {
    int g[V][V]={
        {0,10,6,5},
        {10,0,INF,15},
        {6,INF,0,4},
        {5,15,4,0}
    };

    int parent[V],key[V];
    bool used[V];

    for(int i=0;i<V;i++) {
        key[i]=INF;
        used[i]=false;
    }

    key[0]=0;
    parent[0]=-1;

    for(int c=0;c<V-1;c++) {
        int best=INF,u=-1;

        for(int v=0;v<V;v++)
            if(!used[v] && key[v]<best) {
                best=key[v];
                u=v;
            }

        if(u==-1) break;

        used[u]=true;

        for(int v=0;v<V;v++)
            if(g[u][v]!=0 && g[u][v]!=INF && !used[v] && g[u][v]<key[v]) {
                parent[v]=u;
                key[v]=g[u][v];
            }
    }

    int total=0;

    cout<<"Roads selected:\n";

    for(int i=1;i<V;i++) {
        cout<<parent[i]+1<<" - "<<i+1<<" : "<<key[i]<<endl;
        total+=key[i];
    }

    cout<<"Minimum total cost: "<<total<<endl;

    return 0;
}
