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
#define vecin(v,n) for(int i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define setin(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define caseout(i) cout<<"Case "<<i<<":\n"

const ll inf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
//....................... "Peace Be Upon You" ......................................

int find_min_cost(int k, int x, vi &dp, vi &v, int &n){
    if(k==x){
        return 0;
    }
    int tmp=(k+v[k])%n, ans;
    if(x<tmp){
        ans=(x+n)-tmp;
    }else{
        ans=x-tmp+1;
    }
    dp[k]=min(ans, 1+find_min_cost(tmp, x, dp, v, n));
    return dp[k];
}

void solve(){
    int n, x;
    cin>>n>>x;
    vi v, dp(n+1);
    vecin(v, n);

    for(int i=0; i<1; i++){
        int tmp=(i+v[i])%n, ans;
        if(x<tmp){
            ans=(x+n)-tmp;
        }else{
            ans=x-tmp+1;
        }
        if(x<tmp){
            tmp-=n;
        }
        dp[i]=min(ans, 1+find_min_cost(tmp, x, dp, v, n));
    }

    cout<<dp[x];
}

signed main(){
    IOS;
    int t=1;
    // cin>>t;
    for(int i=1; i<=t; i++){
        solve();
        ln;
    }
    return 0;
}