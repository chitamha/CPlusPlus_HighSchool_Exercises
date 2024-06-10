#include <iostream>
using namespace std;
int n, k;
int main(){
    cin>> n>> k;
    int m=n;
    int newnum=0;
    while(n>0){
        newnum=newnum*10+n%10;
        n/=10;
    }

    cout<< newnum<< endl;

    for (int i=0; i<k-1; i++){
        m/=10;
    }
    cout<< m%10<< endl;
    for (int i=0; i<k-1; i++){
        newnum/=10;
    }
    cout<< newnum%10;
    return 0;
}
