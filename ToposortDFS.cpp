#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void topo(int node,map<int,set<int>> adj,map<int,bool>& visit, stack<int>& s){
  visit[node]=1;
  for(int it: adj[node]){
      if(!visit[it]){
         topo(it,adj,visit,s);
      }
  }
  s.push(node);
}


void DFS(int v, map<int,set<int>> adj){
    map<int,bool> visit;
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!visit[i]){
            topo(i,adj,visit,s);
        }
    }   

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    for(auto i:ans){
        cout<<i<<",";
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    map<int, set<int>> adj;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
    }
    
    DFS(n, adj);
    return 0;
}