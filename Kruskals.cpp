#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void make_set(vector<int>& parent,vector<int>& rank,int v){
    for(int i=0;i<v+1;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(vector<int>& parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]= findParent(parent,parent[node]); //Path compression
}

void unionSet(int u,int v,vector<int>& parent,vector<int>& rank){
    u=findParent(parent,u);
    v=findParent(parent,v);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}


void kruskals(int v,  vector<pair<int,pair<int,int>>>adj){
    vector<int> parent(v);
    vector<int> rank(v);
    make_set(parent,rank,v);

    int minweight = 0;

    for(auto i: adj){
            int u= findParent(parent, i.second.first);
            int v= findParent(parent, i.second.second);
            int wt= i.first;
            if(u!=v){
                cout<<"Rohit"<<wt<<endl;
                minweight+=wt;
                unionSet(u,v,parent,rank);
            }
    }
    cout<<minweight;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>adj;  
     for(int i=0;i<m;i++){
        int wt;
        int u,v;
        cin>>wt>>u>>v;
        adj.push_back({wt,{u,v}});
    }

    sort(adj.begin(),adj.end());    
    kruskals(n, adj);
    return 0;
}