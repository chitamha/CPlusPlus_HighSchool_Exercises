#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> v;
vector<vector<string>> container;

bool ispalindrome(string s){
    string tam=s;
    reverse(s.begin(), s.end());
    if (tam==s) return true;
    return false;
}

void Try(int st){
    if (st>=s.size()) container.push_back(v);
    for (int en=st; en<s.size(); en++){
        if (ispalindrome(s.substr(st, en-st+1))){
            v.push_back(s.substr(st, en-st+1));
            Try(en+1);
            v.pop_back();
        }
    }
}

int main(){
    cin>> s;
    Try(0);
    for (auto it:container){
        for (string str:it)
            cout<< str<< " ";
        cout<< endl;
    }
    return 0;
}
