/*
https://lightoj.com/problem/country-roads*/
#include<bits/stdc++.h>
using namespace std;
// template<typename... T>
// void see(T&... args) { ((cin >> args), ...);}
// #define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define ip pair<int,int>
#define vi vector<int>
#define viv vector<vector<int>>
#define vll vector<long long>
#define vip vector<ip>
#define gip greater<ip>
#define vb vector<bool>
#define vs vector<string>
#define ln cout<<'\n'
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define filein freopen("input.txt", "r" , stdin);freopen("output.txt", "w", stdout)
#define setpr(x) cout<<setprecision(x)<<fixed
#define arrin(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define vecin(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define setin(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define caseout(i) cout<<"Case "<<i<<":\n"

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
//....................... "Peace Be Upon You" ......................................

void solve(){
    int n, m, u, v, w, src;
    cin>>n>>m;
	vector<vip> adj(n+1);
    vb vis(n, 0);
    vll dist(n, inf);
    int wt[n+1][n+1];
    rep(i, 0, n+1){
        rep(j, 0, n+1){
            wt[i][j]=2e9;
        }
    }    

    priority_queue<ip, vip, gip> Q;
    rep(i, 0, m){
        cin>>u>>v>>w;
        if(w<wt[u][v]){
            wt[u][v]=w;
        }
        adj[u].pb({wt[u][v], v});
        adj[v].pb({wt[u][v], u});
    }
    cin>>src;
    dist[src]=0;
    Q.push({dist[src], src});

    while(!Q.empty()){
        auto p=Q.top();
        ll cur_d=p.F, cur_nd=p.S;
        Q.pop();
        if(vis[cur_nd])continue;
        vis[cur_nd]=1;
        for(auto c:adj[cur_nd]){
            ll nxt_d=c.F, nxt_nd=c.S;
            if(!vis[nxt_nd]){
                ll new_d=max(nxt_d,cur_d);
                if(new_d<dist[nxt_nd]){
                    dist[nxt_nd]=new_d;
                    Q.push({dist[nxt_nd], nxt_nd});
                }
            }
        }
    }

    for(auto c:dist){
        (c==inf)? cout<<"Impossible":cout<<c;
        ln;
    }
}

signed main(){
    IOS;
    int t=1, n;
    cin>>t;
    for(int i=1; i<=t; i++){
        caseout(i);
        solve();
    }
    return 0;
}