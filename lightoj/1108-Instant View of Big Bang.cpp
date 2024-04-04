#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
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
#define caseout(i) cout<<"Case "<<i<<": ";
const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
//................ "Peace Be Upon You" ......................................

void dfs(ll src, vb &path_neg_cycle, vector<vector<pair<ll, ll>>> &adj){
    path_neg_cycle[src]=true;
    for(auto c:adj[src]){
        ll dest=c.S;
        if(!path_neg_cycle[dest]){
            dfs(dest, path_neg_cycle, adj);
        }
    }
}

void solve(int tc){
    ll n, m, u, v, w;
    cin>>n>>m;
    vector<vll> dist(n, vll(n, -1));

    vector<vector<pair<ll, ll>>> adj(n+1);
    bool neg_cycle=false;
    vb path_neg_cycle(n+1, 0);
    rep(i, 0, m){
        cin>>u>>v>>w;
        dist[u][v]=w;
    }

    rep(i, 0, n){
        rep(j, 0, n){
            if(dist[i][j]==-1){
                dist[i][j]=inf;
            }
            if(i==j){
                dist[i][j]=0; // No self loop
            }
        }
    }

    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }  

    rep(i, 0, n){
        rep(j, 0, n){
            if(dist[i][j]==inf){
                dist[i][j]=-1;
            }
        }
    } 

    rep(i, 0, n){
        if(dist[i][i]<0){
            if(!path_neg_cycle[i]){
                dfs(i, path_neg_cycle, adj);
            }
            neg_cycle=1;
        }
    }

    if(neg_cycle){
        caseout(tc);
        rep(i, 0, n){
            if(path_neg_cycle[i]){
                cout<<i<<" ";
            }
        }
    }else{
        caseout(tc);
        cout<<"impossible";
    }
}

signed main(){
    IOS;
    int t=1;
    cin>>t;
    rep(i, 1, t+1){
        solve(i);
        ln;
    }
    return 0;
}