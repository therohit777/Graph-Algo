#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void BFS(int v, map<int,set<int>> adj){
    map<int,bool> visit;
    map<int,int> parent;
    int s=1;
    int t=8;

    queue<int> q;
    q.push(s);
    visit[s]=1;
    parent[s]=-1;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        for(auto it: adj[frontnode]){
            if(!visit[it]){
                visit[it]=1;
                parent[it]=frontnode;
                q.push(it);
            }
        }
    }

    vector<int> ans;
    int currentnode = t;
    ans.push_back(t);
    while(currentnode!=s){
        currentnode = parent[currentnode];
        ans.push_back(currentnode);
    }
    reverse(ans.begin(),ans.end());
    for(int i:ans){
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
        adj[v].insert(u);
    }
    
    BFS(n, adj);
    return 0;
}