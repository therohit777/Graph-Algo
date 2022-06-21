#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void bellmanford(int v, vector<pair<int,pair<int,int>>> adj){
    vector<int>dist(v+1,INT_MAX);
    dist[1]=0;
    for(int i=1;i<=v;i++){
        for(auto it:adj){
            int source = it.first;
            int destination = it.second.first;
            int weight = it.second.second;
            if(dist[source]!=INT_MAX && (dist[source] + weight <dist[destination])){
                dist[destination]=dist[source]+weight;
            }
        }
    }

    bool flag=0;
    for(auto it:adj){
        int source = it.first;
        int destination = it.second.first;
        int weight = it.second.second;
        if(dist[source]!=INT_MAX && (dist[source] + weight <dist[destination])){
            flag=1;
        }
    }

    if(flag==0){
        int c=1;
        for(auto i:dist){
            cout<<"Vertex"<<c<<"=>";
            c++;
            cout<<i<<endl;
        }
        cout<<"No negative cycle";
    }
    else{
        cout<<"Negative cycle found.";
    }   
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj.push_back({u,{v,wt}});
    }
    bellmanford(n, adj);
    return 0;
}