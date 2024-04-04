#include<iostream>
#include<stack>

// TC: O(N)    ;   SC: O(N)

using namespace std;

bool isOperator(char x){
    switch (x){
    case '+':
    case '-':
    case '/':
    case '*':
    case '%':
        return true;
    }
    return false;
}

void solve(){
    string n, bot="", top="", a, open="(", close=")";
    cin>>n;
    stack<string> s;
    for(auto c:n){
        a="";
        if(isOperator(c)){
            top=s.top();
            s.pop();
            bot=s.top();
            s.pop();
            a+=(open+bot+c+top+close);
            s.push(a);
        }else{
            a+=c;
            s.push(a);
        }
    }
    cout<<s.top();
}

signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        solve();
        if(tc)
            cout<<"\n";
    }
    return 0;
}
/*
2
ABC/-AK/L-*
AB+CD-*
*/