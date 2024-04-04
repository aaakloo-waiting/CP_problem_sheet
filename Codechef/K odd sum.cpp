#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vip vector<pair<int, int>>
#define pb push_back
#define vs vector<string>
#define ll long long
#define fir(x)                for(ll i=1; i<=x; i++)
#define fjr(x)                for(ll j=0; j<x; j++)
#define fkr(x)                for(ll k=0; k<x; k++)
using namespace std;

const int INF=numeric_limits<int>::max();


void caseout(int i){
    cout<<"Case "<<i<<": ";
}

void solve(){
    int n, k, i;
    cin>>n>>k;
    // Making k-1 odd sum pair
    for(int i=1; i<=k; i++){
        cout<<i<<" ";
    }
    i=k+2;
    while(i<=n){
        cout<<i<<" ";
        i+=2;
    }
    i=k+1;
    while(i<=n){
        cout<<i<<" ";
        i+=2;
    }
}

int main(){
    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++){
        solve();
        cout<<endl;
    }
    return 0;
}
