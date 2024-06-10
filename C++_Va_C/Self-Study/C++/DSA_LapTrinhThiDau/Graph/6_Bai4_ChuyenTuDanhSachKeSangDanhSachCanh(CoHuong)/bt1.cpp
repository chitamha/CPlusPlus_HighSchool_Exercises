#include <bits/stdc++.h>
using namespace std;

set<int> A[1005];

int main(){
    int n;
    cin>> n;
    cin.ignore();
    for (int i=1; i<=n; i++){
        string str;
        getline(cin, str);
        stringstream ss(str);
        string strso;
        while (ss>> strso){
            int so=stoi(strso);
            A[i].insert(so);
        }
    }
    for (int i=1; i<=n; i++){
        for (int x:A[i]){
            cout<< i<< " "<< x<< endl;
        }
    }
    return 0;
}
