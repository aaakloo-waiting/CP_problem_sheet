/*
n int; What is the smallest sum that cannot be created? (No repeated int)
5
2 9 1 2 7
*/
#include<bits/stdc++.h>
 
using namespace std;
 
#define nl "\n"
#define pb push_back
#define M 1000000007
#define llMax 9223372036854775807
#define llMin -9223372036854775808
#define E 1e-9
// #define sp_var 

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
 

typedef unsigned long long ull ;
typedef long long ll;
 
typedef vector<int> vi;
typedef vector<long long> vll;
    
void solve(){
    int n, in;
    ll ans=1; // sum of all test cases might overflow int limit
    cin>>n;
    vi a(n);
    for(auto &c:a){
        cin>>c;
    }
    //Assuming 1 is the smallest sum that cannot be achieved
    //It will be true no other int is less than or equal 1, otherwise 1 is ans
    // If an int less than or equal is found, it will make the ans satisfied; 
    // Adding the int to ans (1 in base case), repeat the same process
    //Sort numbers to search greedily.
    sort(a.begin(), a.end());
    for(auto c:a){
        if(c>ans){
            break;
        }else{
            ans+=c;
        }
    }
    cout<<ans;
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        if(t)cout<<"\n";
    }
    return 0;
} 
