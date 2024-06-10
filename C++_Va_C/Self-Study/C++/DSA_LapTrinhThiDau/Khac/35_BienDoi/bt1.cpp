#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> F(100001);
int sobuoc(int n){
    if (F[n]!=n) return F[n];
    if (n%2==0){
        F[n]=min(F[n], sobuoc(n/2)+1);
    }
    if (n%3==0){
        F[n]=min(F[n], sobuoc(n/3)+1);
    }
    F[n]=min(F[n], sobuoc(n-1)+1);
    return F[n];
}

int main()
{
    cin>> t;
    for (int i=0; i<100001; i++){
        F[i]=i;
    }
    F[0]=0;
    F[1]=0;
    for (int i=0; i<t; i++){
        cin>> n;
        cout<< sobuoc(n)<< endl;
    }
}
