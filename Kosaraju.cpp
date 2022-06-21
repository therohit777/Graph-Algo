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


void revdfs(int node,map<int,set<int>> adj,map<int,bool>& visit){
    visit[node]=1;
    cout<<node;
    for(auto it: adj[node]){
        if(!visit[it]){
            revdfs(it,adj,visit);
        }
    }
}


void DFS(int v, map<int,set<int>> adj){
    map<int,bool> visit;
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!visit[i]){
            topo(i,adj,visit,s);
        }
    }   

    map<int,set<int>> transposeadj;
    for(int i=0;i<=v;i++){
        visit[i]=0;
        for(auto it: adj[i]){
            transposeadj[it].insert(i);
        }
    }

    int count=0;
    while(!s.empty()){
        int topnode=s.top();
        s.pop();
        if(!visit[topnode]){
            count++;
            revdfs(topnode,transposeadj,visit);
        }
        cout<<endl;
    }
    cout<<count;
}3



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