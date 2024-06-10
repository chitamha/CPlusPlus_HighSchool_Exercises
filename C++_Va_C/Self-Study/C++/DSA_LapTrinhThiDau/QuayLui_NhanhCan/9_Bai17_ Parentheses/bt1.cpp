#include <bits/stdc++.h>
using namespace std;

int n, ok=0, cntright=0;
string dn="()[]{}";
string s="";
int cnt=0;

bool check(){
    stack<char> st;
    for (char c:s){
        if (c=='(' || c=='[' || c=='{')
            st.push(c);
        else{
            if (st.empty()) return false;
            char top=st.top();
            if (!((top=='(' && c==')') || (top=='[' && c==']') || (top=='{' && c=='}')))
                return false;
            st.pop();
        }
    }
    if (st.empty()) return true;
    return false;
}

void xuli(){
    if (check()){
        cout<< s<< " ";
        cntright++;
        ok=1;
    }
}

void Ql(int i){
    cnt++;
    if (i>=1 && (s[0]==')' || s[0]=='}' || s[0]==']'))
        return;
    for (int j=0; j<6; j++){
        s+=dn[j];
        if (s.size()==n) xuli();
        else Ql(i+1);
        s.pop_back();
    }
}

int main(){
    cin>> n;
    if (n%2==1){
        cout<< "NOT FOUND"<< endl;
        return 0;
    }
    Ql(1);
    if (ok==0) cout<< "NOT FOUND"<< endl;
    cout<< endl;
    cout<< cntright<< endl;
    cout<< cnt<< endl;
    return 0;
}
