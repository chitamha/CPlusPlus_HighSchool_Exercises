#include <iostream>
#include <math.h>
using namespace std;
int n, dem, demsnt=0, dem2=0;
int main(){
    dem=0;
    cout<< "Moi ban nhap n: "; cin>> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            if (i%j==0) dem+=1;
            }
        if (dem==2) {
            cout<< i<< " ";
            demsnt+=1;
        }
        dem=0;
    }
    cout<< endl<< "Co "<< demsnt<< " so nguyen to"<< endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            if (pow(j, 2)==i){
                cout<<i<< " ";
                dem2+=1;
            }
        }
    }
    cout<< endl<< "Co "<< dem2<< " so chinh phuong";
}
