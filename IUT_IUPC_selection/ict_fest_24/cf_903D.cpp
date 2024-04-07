#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
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
#define setpr_out(pos, val) cout<<setprecision(pos)<<fixed<<val
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
    int n, ek_kom, ek_beshi, soman; cin>>n;
    vi num, l(n+1), r(n+1); 
    unordered_map<int, int> cnt;
    vecin(num, n);
    rep(i, 0, n){
        ek_kom=cnt[num[i]-1];
        ek_beshi=cnt[num[i]+1];
        soman=cnt[num[i]];
        l[i]=(ek_kom+ek_beshi+soman);
        cnt[num[i]]++;
    }
    cnt.clear();
    rev(i, n, 0){
        ek_kom=cnt[num[i]-1];
        ek_beshi=cnt[num[i]+1];
        soman=cnt[num[i]];
        r[i]=(ek_kom+ek_beshi+soman);
        cnt[num[i]]++;
    }
    ld ans=0;
    rep(i, 0, n){
        ans+=(ld)num[i]*(i-l[i]);
        ans-=(ld)num[i]*(n-1-i-r[i]);
    }
    setpr_out(0, ans);
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
