/*
https://lightoj.com/problem/not-the-best
*/
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
#define caseout(i) cout<<"Case "<<i<<": "

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
//.......................... "Peace Be Upon You" ...................................... 
ll m, n;
void Dijkstra(ll src, vb& vis, vll& dist, vector<vector<pair<ll, ll>>>& adj){
    priority_queue<ip, vip, gip> Q;
    Q.push({dist[src], src});
    while(!Q.empty()){
        auto p=Q.top();
        ll w=p.first;
        ll dest=p.second;
        Q.pop();
        if(vis[dest])continue;
        vis[dest]=true;
        for(auto c:adj[dest]){
            ll nxt_w=c.first;
            ll nxt_dest=c.second;
            if(!vis[nxt_dest]){
                int temp=w+nxt_w;
                if(temp<dist[nxt_dest]){
                    dist[nxt_dest]=temp;
                    Q.push({temp, nxt_dest});
                }
            }
        }
    }
}

void solve(){
    int a, b, c;
    cin>>n>>m;
    ll ans=inf, temp;
    vll dist1, distn;
    vb vis1(n+1, 0), visn(n+1,0);
    for(int i=0; i<=n;i++){
        dist1.pb(inf);
        distn.pb(inf);
    }
    vector<vector<pair<ll, ll>>> adj(n+1);
    for(int i=1;i<=m; i++){
        cin>>a>>b>>c;
        adj[a].pb({c, b});
        adj[b].pb({c, a});
    }
    dist1[1]=0;
    Dijkstra(1, vis1, dist1, adj);
    distn[n]=0;
    Dijkstra(n, visn, distn, adj);    
    for(int i=1; i<=n; i++){
        for(auto c:adj[i]){
            temp=dist1[c.S]+distn[i]+c.F;
            if(temp>dist1[n]){
                ans = min(temp, ans);
            }
        }
    }
    cout<<ans;
}

signed main(){
    IOS;
    int t=1;
   cin>>t;
    for(int i=1; i<=t; i++){
        caseout(i);
        solve();
        ln;
    }
    return 0;
}

