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
#define spc " "
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
    string a, res;
    vector<int> fnd(26, 0);
    int k=0, b=0, l=0;
    cin>>a;
    res.insert(res.begin(), a[0]);
    fnd[a[0]-'a']=1;
    rep(i, 1, a.sz){
        if(k>=1 && res[k-1]==a[i]){
            k--;
        }else if(k<l && res[k+1]==a[i]){
            k++;
        }else if(k==l and !fnd[a[i]-'a']){
            res.insert(res.begin()+k+1, a[i]);
            fnd[a[i]-'a']=1;
            k++;
            l++;
        }else if(k==b and !fnd[a[i]-'a']){
            res.insert(res.begin(), a[i]);
            fnd[a[i]-'a']=1;
            l++;
        }else{
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";ln;cout<<res;
    rep(i, 0, 26){
        if(!fnd[i]){
            cout<<static_cast<char>('a'+i);
        }
    }
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


