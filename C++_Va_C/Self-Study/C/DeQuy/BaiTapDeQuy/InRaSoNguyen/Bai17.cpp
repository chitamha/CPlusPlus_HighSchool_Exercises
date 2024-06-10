#include <bits/stdc++.h>
using namespace std;
void InXuoi(long long n){
    if (n<10){
        cout<< n<< " ";
    }
    else
    {
        InXuoi(n/10);
        cout<< n%10<< " ";
    }
}
void InNguoc(long long n){
    if (n<10) cout<< n;
    else{
    cout<< n%10<< " ";
    InNguoc(n/10);
    }
}
int main(){
    long long n;
    cin>> n;
    InXuoi(n);
    cout<< endl;
    InNguoc(n);
}
