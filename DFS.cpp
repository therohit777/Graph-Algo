#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void dfs(int node ,  map<int,set<int>> adj ,   vector<int>& ans  , map<int,bool>& visit){
    visit[node]=1;
    ans.push_back(node);
    for(int it: adj[node]){
        if(!visit[it]){
            dfs(it,adj,ans,visit);
        }
    }

}
void DFS(int v, map<int,set<int>> adj){
    map<int,bool> visit;
    vector<int> ans;
    for(int i=0;i<v;i++){
        if(!visit[i]){
          dfs(i,adj,ans,visit);     
        }
    }


    for(auto it:ans){
        cout<<it<<",";
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