#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    //Using LIST in Map.
    int n,m;
    cin>>n>>m;
    map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto it: adj[i]){
            cout<<it<<",";
        }
        cout<<endl;
    }
    

    //Using SET in Map.
    int n,m;
    cin>>n>>m;
    map<int, set<int>> adj;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto it: adj[i]){
            cout<<it<<",";
        }
        cout<<endl;
    }

    
    return 0;
}