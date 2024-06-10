#include <bits/stdc++.h>
using namespace std;
int Mindigit(long long n){
    if (n<10) return n;
    else return fmin(Mindigit(n/10), n%10);
}
int Maxdigit(long long n){
    if (n<10) return n;
    else return fmax(Maxdigit(n/10), n%10);
}
int main(){
    long long n;
    cin>> n;
    cout<< Mindigit(n)<< " "<< Maxdigit(n);
}
