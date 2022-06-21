#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void dfs(int node,int parent,int& timer,vector<int>&disc,vector<int>&low,map<int,set<int>> adj,map<int,bool>& visit){
        
    visit[node]=1;
    disc[node]=low[node]=timer++;

    for(int it: adj[node]){
        if(it==parent){
            continue;
        }

        if(!visit[it]){
          dfs(it,node,timer,disc,low,adj,visit);
          low[node]=min(low[node],low[it]);   

          if(low[it] > disc[node]){
            cout<<node<<","<<it<<endl;
          }  
          
        }
        else{
            //node already visited but not a parent called as Backedge
            low[node]=min(low[node],disc[it]);
        }
    }

}


void DFS(int v, map<int,set<int>> adj){
    int timer=0;
    int parent = -1;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    map<int,bool> visit;

    for(int i=0;i<v;i++){
        if(!visit[i]){
          dfs(i,parent,timer,disc,low,adj,visit);     
        }
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