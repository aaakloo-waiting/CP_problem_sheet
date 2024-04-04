#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vip vector<pair<int, int>>
#define pb push_back
#define vs vector<string>
#define ll long long
using namespace std;
 
int dirX[4]={0, 0, 1, -1}, diry[4]={1, -1, 0, 0};
char grid[1001][1001];
bool vis[1001][1001];
int n, m, rooms=0;
 
bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && !vis[i][j] && grid[i][j]!='#');
}
 
void init(){
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            vis[i][j]=0;
        }
    }
}
 
void BFS(int x, int y){
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y]=1;
 
    while(!Q.empty()){
        auto p=Q.front();
        Q.pop();
        for(int k=0; k<4; k++){
            int a=p.first+dirX[k], b=p.second+diry[k];
            if(isValid(a, b)){
                vis[a][b]=1;
                Q.push({a, b});
            }
        }
    }
}
 
void solve(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    init();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(isValid(i, j)){
                BFS(i, j);
                rooms++;
            }
        }
    }
    cout<<rooms<<endl;
}
 
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
https://cses.fi/problemset/task/1192/
*/