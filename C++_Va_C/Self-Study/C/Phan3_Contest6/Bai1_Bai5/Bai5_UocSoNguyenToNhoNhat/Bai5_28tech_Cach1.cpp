#include <iostream>
#include <math.h>
using namespace std;
int UNTNN(int k){
    if (k==1) return 1;
    if (k%2==0) return 2;
    for (int i=3; i<=sqrt(k); i+=2){
        if (k%i==0)
            return i;
    }
    return k;
}
int main()
{
    int n;
    cin>> n;
    for (int i=1; i<n+1; i++){
        cout<< UNTNN(i)<< endl;
    }
}
