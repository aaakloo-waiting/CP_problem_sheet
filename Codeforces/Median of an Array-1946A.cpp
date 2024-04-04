#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
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
const long double ep = 0.0000001;
const long double pi = acos(-1.0);
const ll md = 1000000007;
//................ "Peace Be Upon You" ......................................

ll maxSubArraySum(vi &a, int size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void solve(){
	ll n, k, sum=0, ans=2;
	cin>>n>>k;
	vi a(n+1);
	rep(i, 0, n){
		cin>>a[i];
		sum+=a[i];

	}
	ll mx_s_sum=maxSubArraySum(a, n);
	if(mx_s_sum<0){
		mx_s_sum=0;
	}
	rep(i, 1, k){
		ans*=2;
		ans%=md;
	}
	ans=((ans)*(mx_s_sum%md))%md;
	ans=((ans)-(mx_s_sum%md)+(sum%md))%md;
	if(ans<0){
		ans+=2*md;
		ans%=md;
	}
	cout<<ans<<endl;
}

signed main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}