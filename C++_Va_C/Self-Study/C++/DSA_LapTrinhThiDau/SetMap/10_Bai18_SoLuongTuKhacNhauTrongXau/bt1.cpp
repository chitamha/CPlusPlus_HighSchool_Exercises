#include <bits/stdc++.h>
using namespace std;
set<string> st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (cin>> s){
        st.insert(s);
    }
    cout<< st.size()<< endl;
    cout<< *(st.begin())<< " "<< *(st.rbegin());
    return 0;
}
