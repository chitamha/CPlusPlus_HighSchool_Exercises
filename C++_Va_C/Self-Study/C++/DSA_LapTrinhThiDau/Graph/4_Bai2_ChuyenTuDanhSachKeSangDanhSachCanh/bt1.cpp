#include <bits/stdc++.h>
using namespace std;

set<int> A[1005];

int main(){
    int n;
    cin>> n;
    cin.ignore();
    for (int i=1; i<=n; i++){
        string x;
        getline(cin, x);
        stringstream ss(x);
        string strso;
        while (ss>> strso){
            int so=stoi(strso);
            A[i].insert(so);
            A[so].insert(i);
        }

    }
    cout<< endl;
    for (int i=1; i<=n; i++){
        for (int x:A[i]){
            if (i<x)
                cout<< i<< " "<< x<< endl;
        }
    }
    return 0;
}
