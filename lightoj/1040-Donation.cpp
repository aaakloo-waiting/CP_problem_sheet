/*
https://lightoj.com/problem/donation
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
//....................... "Peace Be Upon You" ......................................

struct Edge{
    int u, v, w;
    bool operator < (Edge const& other){
        return this->w < other.w;
    }
};

int Find(int u, vi &par){
    if (u == par[u]) return u;
    return par[u] = Find(par[u], par);
}

void solve(){
    int m, w;
    ll res=0, total=0;
    cin>>m;
    vector<Edge> cables;
    set<int> cableNo, chk;
    viv adj(1e6);
    vb vis(1e6, 0);
    vi par(1e6);
    rep(i,0,m){
        rep(j, 0, m){
            cin>>w;
            total+=w;
            if(w and i!=j){
                cables.pb({i, j, w});
                adj[i].pb(j);
                adj[j].pb(i);
            }
            cableNo.insert(i);
            cableNo.insert(j);
            par[i]=i;
            par[j]=j;
        }
    }
    // BFS to detcet connected cities
    queue<int> Q;
    Q.push(0);
    vis[0]=1;
    while(!Q.empty()){
        auto p=Q.front();
        chk.insert(p);
        Q.pop();
        for(auto c:adj[p]){
            if(!vis[c]){
                Q.push(c);
                vis[c]=1;
            }
        }
    }
    if(chk.size()!=cableNo.size()){
        cout<<"-1";
        return;
    }
    // Kruskal's Algo for taking Minimum in Connected Components
    sort(all(cables));
    for(Edge e:cables){
        int p=Find(e.u, par), q=Find(e.v, par);
        if(p!=q){
            res+=e.w;
            par[q]=p; 
        }
    }
    // cout<<total<<" "<<res;
    cout<<total-res;
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