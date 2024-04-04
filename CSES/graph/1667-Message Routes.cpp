#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vip vector<pair<int, int>>
#define pb push_back
#define vs vector<string>
#define ll long long
using namespace std;
 
 
bool BFS(int x, vb &vis, vector<vi> &adj, vi &par, int n){
    bool isPossible=0;
    queue<int> Q;
    Q.push(x);
    vis[x]=1;
    while(!Q.empty()){
        int p=Q.front();
        Q.pop();
        for(auto c:adj[p]){
            if(!vis[c]){
                vis[c]=1;
                if(c==n){
                    isPossible=1;
                }
                Q.push(c);
                par[c]=p;
            }
        }
    }
    return isPossible;
}
 
void solve(){
    int n, m, x, y;
    bool pos;
    cin>>n>>m;
    vector<vi> adj(n+1);
    vb vis(n+1);
    vi par(n+1);
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i=1; i<=n; i++){ 
        vis[i]=0;
    }
 
    pos=BFS(1, vis, adj, par, n);
    if(pos){
    stack<int> ans;
    int cur=n, cnt=1;
    while(cur!=1){
        ans.push(cur);
        cur=par[cur];
        cnt++;
    }
    cout<<cnt<<endl<<"1 ";
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
 
int main(){
    int t=1;
    // cin>>t;
    for(int i=1; i<=t; i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}
/*
https://cses.fi/problemset/task/1667/
*/