#include <bits/stdc++.h>
using namespace std;

string s;
bool check(string a){
    string t=a;
    reverse(t.begin(), t.end());
    return t==a;
}

int main(){
    int t; cin>> t;
    cin.ignore();
    while (t--){
        int cnt=0;
        cin>> s;
        int n=s.size();
        for (int i=0; i<n; i++){
            string tmp=s;
            tmp.insert(i, " ");
            for (char c='a'; c<='z'; c++){
                tmp[i]=c;
                if (check(tmp)){
                    cnt++;
                    break;
                }
            }
        }
        for (char c='a'; c<='z'; c++){
            string tmp=s;
            string ins=""; ins+=c;
            tmp=tmp+ins;
            if (check(tmp)){
                cnt++;
                break;
            }
        }
        cout<< cnt<< endl;
    }
    return 0;
}
