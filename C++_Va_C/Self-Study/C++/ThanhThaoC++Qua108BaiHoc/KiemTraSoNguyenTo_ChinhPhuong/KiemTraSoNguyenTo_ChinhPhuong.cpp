#include <iostream>
#include <math.h>
using namespace std;
int n, dem;
int main(){
    bool c=false ;
    cout<< "Moi ban nhap 1 so bat ki: "; cin>> n;
    double cb2=double(sqrt(n));
    for (int i=1; i<=n; i++){
        if (n%i==0) dem+=1;
        if (cb2==i) {cout<< "La so chinh phuong"<< endl;
        c = true;
        }
    }
    if (c==false) cout<< "Khong phai la so chinh phuong"<< endl;
    if (dem==2) cout<< "So "<< n<< " la so nguyen to"; else
        cout<< "Khong phai la so nguyen to";
}
