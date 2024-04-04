#include<bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vip vector<pair<int, int>>
#define pb push_back
#define vs vector<string>
#define ll long long
using namespace std;

const int INF=numeric_limits<int>::max();


void caseout(int i){
    cout<<"Case "<<i<<": ";
}

int dirX[4]={0, 0, 1, -1}, diry[4]={1, -1, 0, 0};
char grid[1000][1000];
bool vis[1000][1000];
int dist[1000][1000];
int n, m;

bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && !vis[i][j] && grid[i][j]!='T');
}

void init(){
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            vis[i][j]=0;
            dist[i][j]=INF;
        }
    }
}

void BFS_MikemonMaster(int x, int y){
    queue<pair<int, int>> Q;
    bool fnd=0;
    Q.push({x, y});
    vis[x][y]=1;
    dist[x][y]=0;
    while(!Q.empty()){
        auto p=Q.front();
        Q.pop();
        for(int k=0; k<4; k++){
            int a=p.first+dirX[k], b=p.second+diry[k];
            if(isValid(a, b)){
                vis[a][b]=1;
                dist[a][b]=dist[p.first][p.second]+1;
                Q.push({a, b});            }
        }
    }
}

void solve(){
    int sx, sy, ans=0, x, y;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='E'){
                sx=i;sy=j;
            }else if(grid[i][j]=='S'){
                x=i;y=j;
            }
        }
    }
    init();
    BFS_MikemonMaster(sx, sy);
    int lim=dist[x][y];
    dist[sx][sy]=dist[x][y]=INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<m; j++){
            if(dist[i][j]<=lim){
                ans+=(grid[i][j]-'0');
            }
        }
    }
    cout<<ans;
}

int main(){
    int t=1;
    // cin>>t;
    for(int i=1; i<=t; i++){
        solve();
    }
    return 0;
}
