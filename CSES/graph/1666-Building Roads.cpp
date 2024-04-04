#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vip vector<pair<int, int>>
#define pb push_back
#define vs vector<string>
#define ll long long
using namespace std;
 
int BFS(int p, vb &vis, vector<vi>&adj){
    queue<int> Q;
    Q.push(p);
    vis[p]=1;
    while(Q.size()){
        p=Q.front();
        Q.pop();
        for(auto u:adj[p]){
            if(!vis[u]){
                vis[u]=1;
                Q.push(u);
            }
        }
    }
    return p;
}
void solve(){
    int n, m, x, y, cnt=-1;
    cin>>n>>m;
    vector<vi> city(n+1);
    for(int i=0; i<m; i++){
        cin>>x>>y;
        city[x].pb(y);
        city[y].pb(x);
    }
        vb vis(n+1, 0);
    vi res;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cnt++;
            int q=BFS(i, vis, city);
            res.pb(q);
        }
    }
    cout<<cnt<<endl;
    if(cnt==1){
        for(auto c:res)
        cout<<c<<" ";
    }else{
        cout<<res[0]<<" ";
        for(int i=1;i<res.size()-1; i++){
            cout<<res[i]<<endl<<res[i]<<" ";
        }
        cout<<res[res.size()-1];
    }
}
 
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
https://cses.fi/problemset/task/1666/
*/