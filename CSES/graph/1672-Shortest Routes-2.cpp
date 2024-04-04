#include <iostream>
#include<string>
#include<stack>
#define nl "\n"
#define ll long long
#define spc " "
using namespace std;
signed main(){
    ll n, m, q, u, v, w;
    cin>>n>>m>>q;
    ll ar[n+1][n+1];
    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<n+1; j++){
            if(i==j)
                ar[i][j]=0;
            else
                ar[i][j]=1e15;
        }
    }
    while(m--){
        cin>>u>>v>>w;
        if(w<ar[u][v]){
        ar[u][v]=w;
        ar[v][u]=w;
        }
    }
    for (int k = 1; k < n+1; ++k) {
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]); 
        }
    }
    }
    while(q--){
        cin>>u>>v;
        (ar[u][v]==1e15)? cout<<-1 : cout<<ar[u][v];
        cout<<nl;
    }
    return 0;
}
/*
https://cses.fi/problemset/task/1672/
*/