#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BFS(int v, map<int,set<int>> adj){
    map<int,bool> visit;
    vector<int> ans;
     
    for(int i=0;i<v;i++){
        if(!visit[i]){
            queue<int> q;
            q.push(i);
            visit[i]=1;
            while(!q.empty()){
                int frontend=q.front();
                q.pop();
                ans.push_back(frontend);
                for(int it: adj[frontend]){
                    if(!visit[it]){
                        ans.push_back(it);
                        visit[it]=1;
                    }
                }
            }
        }
    }
    for(auto i: ans){
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
    
    BFS(n, adj);
    return 0;
}