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
    int n, c1=0, c2=0, x;
    cin>>n;
    unordered_map<int, int> dl, dr;
    vi l(n+1), r(n+1);
    rep(i, 0, n){
        cin>>l[n-1-i];
        (l[n-1-i]==1)? c1++:c2++;
    }
    rep(i, 0, n){
        cin>>r[i];
        (r[i]==1)? c1++:c2++;
    }
    if(c1==c2){
        cout<<0;
        return;
    }
    int dif_t=c1-c2;
    int cnt=0;
    rep(i, 0, n){
        if(l[i]==1){
            cnt++;
        }else{
            cnt--;
        }
        if(dl[cnt]==0)
            dl[cnt]=(i+1);
        else
            dl[cnt]=min(dl[cnt], i+1);
    }
    cnt=0;
    rep(i, 0, n){
        if(r[i]==1){
            cnt++;
        }else{
            cnt--;
        }
        if(dr[cnt]==0)
            dr[cnt]=(i+1);
        else
            dr[cnt]=min(dr[cnt], i+1);
    }
    cnt=1e9;
    dr[0]=1;
    for(auto c:dl){
        if(dr[dif_t-c.F]){
            if(c.F==dif_t){
                dr[0]=0;
            }
            cnt=min(cnt, (c.S+dr[dif_t-c.F]));

        }
    }
    if(dr[dif_t]){
        cnt=min(cnt, dr[dif_t]);
    }
    cout<<cnt;
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
