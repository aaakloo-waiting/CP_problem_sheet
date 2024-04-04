/*
https://onlinejudge.org/external/100/10004.pdf
*/
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
#define viv vector<vector<int>>
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
const ll md = 1000000007;
//....................... "Peace Be Upon You" ......................................

void solve(int n){
    int l, u, v;
    viv adj(n+1);
    vb vis(n, 0);
    vi col(n, -1);
    queue<int> Q;
    cin>>l;
    rep(i, 0, l){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    Q.push(0);
    col[0]=0;
    while(!Q.empty()){
        auto p=Q.front();
        Q.pop();
        vis[p]=1;
        for(auto c:adj[p]){
            if(!vis[c]){
                if(col[c]==col[p]){
                    cout<<"NOT BICOLORABLE.";
                    return;
                }
                col[c]=(col[p]+1)%2;
                Q.push(c);
            }
        }

    }
    cout<<"BICOLORABLE.";
}

signed main(){
    IOS;
    int t=1, n;
   // cin>>t;
    while(1){
        cin>>n;
        if(n==0){
            break;
        }
        solve(n);
        ln;
    }
    return 0;
}