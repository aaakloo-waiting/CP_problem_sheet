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

void solve(){
	// Thinking about the constraint of values
    // sometimes leads to the solution;
    // not doing operation over n or the number of inputs
    int n, x, mx=-1;
    unordered_map<ll, ll> freq;
    cin>>n;
    rep(i, 0, n){
        cin>>x;
        mx=max(mx, x);
        freq[x]++;
    }
    vll dp(mx+1);
    // DP thinking: Considering among all numbers the maximum value is x
    // what will be the solution then, is the key smallest sub-problem
    dp[0]=0; // no points
    dp[1]=freq[1];
    rep(i, 2, mx+1){
        dp[i]=max(dp[i-1], dp[i-2]+i*freq[i]); // At one op. either take it or dont. If x not taken, x-1 is already taken surely; If x taken then x-2 must be taken 
    }
    cout<<dp[mx];
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