/*
https://lightoj.com/problem/road-construction
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

class Edge{
public:
    string u, v;
    int w;
    void getinfo(string u, string v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator < (Edge const& other){
        return this->w < other.w;
    }
};

void solve(){
    int m, w;
    ll res=0;
    string u, v;
    cin>>m;
    vector<Edge> roads(m+1);
    set<string> city, chk;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> vis;
    unordered_map<string, string> par;
    rep(i,0,m){
        cin>>u>>v>>w;
        roads[i].getinfo(u, v, w);
        adj[u].pb(v);
        adj[v].pb(u);
        city.insert(u);
        city.insert(v);
        par[u]=u;
        par[v]=v;
    }
    // BFS to detcet connected cities
    queue<string> Q;
    Q.push(u);
    vis[u]=1;
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
    if(chk.size()!=city.size()){
        cout<<"Impossible";
        return;
    }
    // Kruskal's Algo for taking Minimum in Connected Components
    sort(all(roads));
    for(Edge e:roads){
        if(par[e.u]!=par[e.v]){
            res+=e.w;
            string u_p=par[e.u], v_p=par[e.v];
            for(auto c:city){
                if(par[c]==u_p){
                    par[c]=v_p;
                }
            } 
        }
    }
    cout<<res;
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