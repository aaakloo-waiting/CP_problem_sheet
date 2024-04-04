#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<long long>
#define vip vector<pii>
#define vb vector<bool>
#define vs vector<string>
#define ln cout<<'\n'
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define filein freopen("input.txt", "r" , stdin);freopen("output.txt", "w", stdout);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define arrin(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define vecin(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define setin(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000000;
//................ "Peace Be Upon You" ......................................

class DisjointSet {
    vector<int> rank, parent, size;
public:
    ll ans=0;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v, int w) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        ans+=((size[ulp_u]*size[ulp_v])%md)*(w%md);
        ans%=md;
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool cmp(const pair<ll, pair<ll, ll>>& a, const pair<ll, pair<ll, ll>>& b){
    return (a.F>b.F);
}

void solve(){
    ll n, m, u, v, w, nd1, nd2, mx=0, t_w=0;
    cin>>n>>m;
	vector<pair<ll, pair<ll, ll>>> edges;
    DisjointSet ds(n+1); // takes node number as parameter
    rep(i, 0, m){
        cin>>u>>v>>w;
        t_w+=w;
        edges.pb({w, {u, v}});
    }
    sort(edges.begin(), edges.end(), cmp);
    // for(auto e:edges){
    //     cout<<e.F<<" ";
    // }
    for(auto e:edges){
        nd1=e.S.S;
        nd2=e.S.F;
        w=e.F;
        if(ds.findUPar(nd1)!=ds.findUPar(nd2)){
            ds.unionBySize(nd1, nd2, t_w);
            mx+=w;
        }
        t_w-=w;
    }
    cout<<ds.ans;
}

signed main(){
    IOS;
    int t=1;
    while(t--){
        solve();
        ln;
    }
    return 0;
}