#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void Dijastra(int v, map<int,set<pair<int,int>>> adj){
  int src =0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  vector<int> distTo(v,INT_MAX);


  distTo[src]=0;
  pq.push(make_pair(0,src));



  while(!pq.empty()){
    int frontdist = pq.top().first;
    int frontnode = pq.top().second;
    pq.pop();
    vector<pair<int,int>>::iterator it;

    for(auto it: adj[frontnode]){
        int nextnode=it.first;
        int nextdist=it.second;
        if(distTo[nextnode]>frontdist+nextdist){
            distTo[nextnode] = distTo[frontnode]+nextdist;
            pq.push(make_pair(distTo[nextnode],nextnode));
        }
    }
  }

  for(auto i:distTo){
    cout<<i<<",";
  }
}

int main(){
    int n,m;
    cin>>n>>m;
    map<int, set<pair<int,int>>>adj;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].insert({v,wt});
    }
    
    Dijastra(n, adj);
    return 0;
}