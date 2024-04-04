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
const ll md = 1000000007;
//................ "Peace Be Upon You" ......................................

ll isvalid(int i, int j, vector<vll>& dp){
    if(j>=0){
        return dp[i][j];
    }else{
        return -inf;
    }
}

void solve(){
	int n, k;
    cin>>n>>k;
    vector<vll> dp(n+1, vector<ll>(k+1, 0));
    vip it(n+1);
    rep(i, 0, n){
        cin>>it[i].F>>it[i].S;
    }
    rep(i, 0, n){
        rep(j, 1, k+1){
            dp[i+1][j]=max(dp[i][j], isvalid(i, j-it[i].F, dp)+it[i].S);
        }
    }
    cout<<dp[n][k];
}

signed main(){
    IOS;
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}