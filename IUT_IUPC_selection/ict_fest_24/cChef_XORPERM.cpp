
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define pb push_back
#define pf push_front
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
const long double ep = 0.0000001;
const long double pi = acos(-1.0);
const ll md = 1000000007;
//................ "Peace Be Upon You" ......................................

void solve(){
	int n; cin>>n;
	stack<int> ans;
	if(n<=3){
		cout<<"-1";
	}else{
		rev(i, n, 4){
			cout<<i<<" ";
		}
		cout<<"1 2 4 3";
	}
}

signed main(){
    int t=1;
   	cin>>t;
    rep(i, 1, t+1){
        solve();
        if(i<t){
        	ln;
        }
    }
    return 0;
}