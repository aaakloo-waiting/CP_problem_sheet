#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vpii vector<pii>
#define vb vector<bool>
#define vs vector<string>
#define ln cout<<'\n'
#define spc cout<<" "
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a-1; i>=b; i--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define filein freopen("input.txt", "r" , stdin);freopen("output.txt", "w", stdout);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define arrin(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define vecin(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define setin(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const ll inf = LLONG_MAX;
const long double ep = 0.0000001;
const long double pi = acos(-1.0);
const ll md = 1000000007;
//................ "Peace Be Upon You" ......................................


void solve(){
    int n, q, qt, x, idx=0; cin>>n>>q;
    set<int> unrd_q;
    vector<vi> app(n+1); // # unread queries in x app 
    vi unrd_tilln;
    rep(i, 0, q){
        cin>>qt>>x;
        if(qt==1){
            unrd_q.insert(i);
            app[x].pb(i);
            unrd_tilln.pb(i);
        }else if(qt==2){
            rep(k, 0, app[x].sz){
                unrd_q.erase(app[x][k]);
            }
            app[x].clear();
        }else{
            rep(j, idx, x){
                unrd_q.erase(unrd_tilln[j]);
            }
            idx=max(idx, x); // already 1st x unread processed
        }
        cout<<unrd_q.sz;ln;
    }

}
 
signed main(){
    fastio;
    int t=1;
    // cin>>t;
    for(int cs=1;cs<=t;cs++){
        //cout<<"Case "<<cs<<": ";
        solve();
        if(cs<t){
            ln;
        }
    }
    return 0;
}
