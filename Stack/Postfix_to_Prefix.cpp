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
    string in;
    stack<string> st;
    cin>>in;
    for(auto c:in){
        string a="";
        if(isOperator(c)){
            a+=st.top();
            st.pop();
            a=c+st.top()+a;
            st.pop();
            st.push(a);
        }else{
            a+=c;
            st.push(a);
        }
    }
    cout<<st.top();
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