#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool check_cycle(int node,int parent,map<int,set<int>> adj,map<int,bool> visit){
    visit[node]=1;
    for(int it: adj[node]){
        if(!visit[it]){
            if(check_cycle(it,node,adj,visit)){
                return true;
            }
        }
        else if(visit[it]==true && parent!=it){
            return true;
        }
    }
  
    return false;
}


void DFS(int v, map<int,set<int>> adj){
    map<int,bool> visit;
    int flag=0;

    for(int i=0;i<v;i++){
        if(!visit[i]){
            if(check_cycle(i,-1,adj,visit)){
                cout<<"true";
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
       cout<<"false";
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
        adj[v].insert(u);
    }
    
    DFS(n, adj);
    return 0;
}