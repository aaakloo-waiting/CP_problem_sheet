#include<iostream>
#include<stack>
#include<string>

// TC: O(N)    ;   SC: O(N)

using namespace std;

bool isEndOfWord(char x){
    switch (x){
    case ' ':
        return true;
    }
    return false;
}

void solve(){
    string in, a="";
    stack<char> st;
    getline(cin, in, '\n');
    for(auto c:in){
        if(isEndOfWord(c)){
            while(!st.empty()){
                a+=st.top();
                st.pop();
            }
            a+=c;
        }else{
            st.push(c);
        }
    }
    while(!st.empty()){
        a+=st.top();
        st.pop();
    }
    cout<<a;
}

signed main(){
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
        solve();
        if(tc)
            cout<<"\n";
    }
    return 0;
}
/*
2
Geeks For Geeks
dog si laer
*/