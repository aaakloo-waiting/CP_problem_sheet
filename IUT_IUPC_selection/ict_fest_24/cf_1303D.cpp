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
#define rev(i,a,b) for (int i=a; i>b; --i)
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
    ll n, m, sum=0, ans=0, k;
    cin>>n>>m;    
    vi num, cnt(65, 0);
    vecin(num, m);
    rep(i, 0, m){
        sum+=num[i];
        cnt[log2(num[i])]++;
    }
    if(sum<n){
        cout<<"-1";
        return;
    }
    string s=bitset<64>(n).to_string();
    reverse(all(s));
    rep(i, 0, 61){
        if(s[i]=='1'){
            if(cnt[i]){
                cnt[i]--;
            }else{
                k=i+1;
                while(cnt[k]==0){
                    k++;
                }
                ans+=(k-i);
                cnt[i]+=(1<<(k-i));
                // cout<<k;spc;
                cnt[k]--;
                cnt[i]--;
            }
        }
        cnt[i+1]+=(cnt[i]/2);
    }
    cout<<ans;
}
 
signed main(){
    fastio;
    int t=1;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        //cout<<"Case "<<cs<<": ";
        solve();
        if(cs<t){
            ln;
        }
    }
    return 0;
}


