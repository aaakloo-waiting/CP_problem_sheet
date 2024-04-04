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

void solve(){
	ll n, a, b, c;
    cin>>n;
    ll dp[n+1][4], val[n+1][4];
    rep(i, 1, n+1){
        cin>>val[i][1]>>val[i][2]>>val[i][3];
    }
    // Initialising base values of dp table
    dp[1][3]=val[1][3];
    dp[1][1]=val[1][1];
    dp[1][2]=val[1][2];
    rep(i, 2, n+1){
        dp[i][1]=val[i][1] + max(dp[i-1][3], dp[i-1][2]);
        dp[i][2]=val[i][2] + max(dp[i-1][1], dp[i-1][3]);
        dp[i][3]=val[i][3] + max(dp[i-1][1], dp[i-1][2]);
    }
    cout<<max({dp[n][3], dp[n][1], dp[n][2]});
    // rep(i, 1, n+1){
    //     rep(j, 1, n+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    // }
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