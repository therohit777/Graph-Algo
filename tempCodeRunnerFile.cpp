  bool flag=0;
    for(auto it:adj){
        int u=it.first;
        int v=it.second.first;
        int wt=it.second.second;
        if(dist[u]!=INT_MAX && ((dist[u]+wt)<dist[v])){
            flag=1;
        }
    }