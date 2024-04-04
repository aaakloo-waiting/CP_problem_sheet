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
    ll n, m, u, v, w, e_in_cycle, tmp=0;
    cin>>n>>m;
    vector<pair<ll, pair<ll, ll>>> edge;
    vll dist(n+1), par(n+1); // Initialise all dist to zero
    rep(i, 0, m){
        cin>>u>>v>>w;
        edge.pb({w, {u, v}});
    }
    rep(i, 0, n){
        for(auto e:edge){
            u=e.S.F;
            v=e.S.S;
            w=e.F;
            if(dist[v]>(dist[u]+w)){
                dist[v]=dist[u]+w;
                par[v]=u;
                tmp=v;
            }
        }
    }

            if(tmp){
                // Finding negative cycle
                stack<ll> st;
                rep(i, 0, n){
                    tmp=par[tmp]; // Guaranteed to be in the negative cycle
                }
                for(e_in_cycle=tmp; ;e_in_cycle=par[e_in_cycle]){
                    if(e_in_cycle==tmp and st.size()){
                        break;
                    }
                    if(e_in_cycle==0){
                        cout<<"NO";
                        return;
                    }
                    st.push(e_in_cycle);
                }
                st.push(e_in_cycle);
                while(e_in_cycle!=tmp){
                    st.push(e_in_cycle);
                    e_in_cycle=par[tmp];                
                }
                cout<<"YES\n";
                while(!st.empty()){
                    cout<<st.top()<<" ";
                    st.pop();
                }
                return;
            }
    cout<<"NO";
}

signed main(){
    IOS;
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        ln;
    }
    return 0;
}