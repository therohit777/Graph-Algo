#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void topo(int node,map<int,set<pair<int,int>>> adj,map<int,bool>& visit, stack<int>& s){
  visit[node]=1;
  for(auto it: adj[node]){
      if(!visit[it.first]){
         topo(it.first,adj,visit,s);
      }
  }
  s.push(node);
}


void DFS(int v, map<int,set<pair<int,int>>> adj){
    map<int,bool> visit;
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!visit[i]){
            topo(i,adj,visit,s);
        }
    }  

    int source=1;
    vector<int> dist(v);
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
    }
    dist[source]=0;
    while(!s.empty()){
        int top = s.top();
        s.pop();

        if(dist[top]!=INT_MAX){
            for(auto i: adj[top]){
                if(dist[top]+i.second < dist[i.first]){
                    dist[i.first]=dist[top]+i.second;
                }
            }
        }
    }

    for(int i=0;i<v;i++){
        cout<<dist[i]<<",";
    }



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
    
    DFS(n, adj);
    return 0;
}