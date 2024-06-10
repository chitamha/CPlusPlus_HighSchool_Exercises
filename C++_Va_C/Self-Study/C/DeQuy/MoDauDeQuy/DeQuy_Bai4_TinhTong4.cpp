#include <iostream>
#include <math.h>
using namespace std;
void chuyen(int n){
    if (n<2){
        cout<< n%2;
    }
    else
    {
        chuyen(n/2);
        cout<< n%2;
    }
}
int kqua(int n){
    if (n==1){
        return -1;
    }
    else
    {
        /*if (n%2==0){
            return n+kqua(n-1);
        }
        else return -n+kqua(n-1);*/
        return pow(-1, n)*n+kqua(n-1);
    }
}
int main(){
    int n=1;
    while(n>=1){
        cout<< kqua(n)<< endl;
        cin>> n;
    }
}
