#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void Prims(int v, map<int,set<pair<int,int>>> adj){
    int source=0;
    vector<int> key(v,INT_MAX);
    vector<bool> mst(v,false);
    vector<int> parent(v,-1);

    key[source]=0;
    parent[source]=-1;

    for(int i=0;i<v;i++){
        int minnode=INT_MAX;
        int parentnode;
        for(int j=1;j<v;j++){
            if(mst[j]==false && key[j]<minnode){
                parentnode=j;
                minnode=key[j];
            }
        }

        mst[parentnode]=true;

        for(auto it:adj[parentnode]){
            int nextnode = it.first;
            int nextweight =it.second;
            if(mst[nextnode]==false && nextweight<key[nextnode]){
                parent[nextnode]=parentnode;
                key[nextnode]=nextweight;
            }
        }
    }

    int mincost=0;
    for(auto i: key){
        mincost+=i;
    }
    cout<<mincost<<endl;



}

int main(){
    int n,m;
    cin>>n>>m;
    map<int, set<pair<int,int>>>adj;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].insert({v,wt});
    }
    
    Prims(n, adj);
    return 0;
}