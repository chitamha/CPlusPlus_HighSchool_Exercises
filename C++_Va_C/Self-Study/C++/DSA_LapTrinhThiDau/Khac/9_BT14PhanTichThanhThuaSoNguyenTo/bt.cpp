#include <bits/stdc++.h>
using namespace std;

void pt1(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            while (n%i==0){
                cout<< i<< " ";
                n/=i;
            }
        }
    }
    if (n!=1) cout<< n;
}

void pt2(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            cout<< i<< " ";
            while (n%i==0){
                n/=i;
            }
        }
    }
    if (n!=1) cout<< n;
}

void pt3(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            int dem=0;
            while (n%i==0){
                dem++;
                n/=i;
            }
            cout<< i<< "("<< dem<< ")"<< " ";
        }
    }
    if (n!=1) cout<< n<< "(1)";

}

void pt4(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            while (n%i==0){
                cout<< i;
                n/=i;
                if (n!=1) cout<< "x";
            }
        }
    }
    if (n!=1) cout<< n;
}

void pt5(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            int dem=0;
            while (n%i==0){
                dem++;
                n/=i;
            }
            cout<< i<< "^"<< dem;
            if (n!=1) cout<< "x";
        }
    }
    if (n!=1) cout<< n<< "^1";
}
int main(){
    int t;
    cin>> t;
    while (t--){
        int n;
        cin>> n;
        pt1(n);
        cout<< endl;
        pt2(n);
        cout<< endl;
        pt3(n);
        cout<< endl;
        pt4(n);
        cout<< endl;
        pt5(n);
        cout<< endl;
    }
}
