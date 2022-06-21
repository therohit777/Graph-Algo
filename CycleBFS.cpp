#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool check_cycle(int node,map<int,set<int>> adj,map<int,bool> visit, map<int,int> parent){
    visit[node]=1;
    parent[node]=-1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        for(auto it: adj[frontnode]){
            if(!visit[it]){
                q.push(it);
                visit[it]=1;
                parent[it]=frontnode;
            }
            else if(visit[it]==1 && parent[frontnode]!= it){
                return true;
            }
        }
    }
    return false;
}


void BFS(int v, map<int,set<int>> adj){
    map<int,bool> visit;
    map<int,int> parent;

    int flag=0;

    for(int i=0;i<v;i++){
        if(!visit[i]){
            if(check_cycle(i,adj,visit,parent)){
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
    
    BFS(n, adj);
    return 0;
}