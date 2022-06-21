#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool check_cycle(int node,map<int,set<int>> adj,map<int,bool> visit,map<int,bool> dfsvisit){
    visit[node]=1;
    dfsvisit[node]=1;
    for(int it: adj[node]){
        if(!visit[it]){
            if(check_cycle(it,adj,visit,dfsvisit)){
                return true;
            }
        }
        else if(dfsvisit[it]==1){
            return true;
        }
    }
    dfsvisit[node]=0;
    return false;
}


void DFS(int v, map<int,set<int>> adj){
    map<int,bool> visit;
    map<int,bool> dfsvisit;
    int flag=0;

    for(int i=0;i<v;i++){
        if(!visit[i]){
            if(check_cycle(i,adj,visit,dfsvisit)){
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
    }
    
    DFS(n, adj);
    return 0;
}