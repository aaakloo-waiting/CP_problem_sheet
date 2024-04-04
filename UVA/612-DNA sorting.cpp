#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vip vector<pair<int, int>>
#define M 1000000007
#define pb push_back 
#define ll long long
using namespace std;

void solve(){
    int n, m, cntA, cntC, cntT, cntG, res;
    vector<string> vs;
    string s;
    vector<pair<int, int>> ans;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>s;
        vs.push_back(s);
        cntA=cntC=cntT=cntG=res=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='T'){
                res+=(cntA+cntC+cntG);
                cntT++;
            }else if(s[i]=='G'){
                res+=(cntA+cntC);  
                cntG++;              
            }else if(s[i]=='C'){
                res+=(cntA);
                cntC++;
            }else{
                cntA++;
            }
        }
        ans.pb({res, i});
    }
    sort(ans.begin(), ans.end());
    for(auto c:ans){
        cout<<vs[c.second]<<endl;
    }
}

int main(){
    int tc;
    string s;
    cin>>tc;
    while(tc--){
        solve();
        if(tc)
            cout<<endl;
    }
    return 0;
}
