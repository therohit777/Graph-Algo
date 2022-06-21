#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void BFS(int v, map<int,set<int>> adj){
    
    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i=1;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }


    vector<int> ans;
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for(int it:adj[frontnode]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
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