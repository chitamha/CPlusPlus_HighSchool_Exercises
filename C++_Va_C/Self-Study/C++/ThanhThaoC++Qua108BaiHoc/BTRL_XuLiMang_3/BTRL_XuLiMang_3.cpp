#include <iostream>
using namespace std;
int n;
int main(){
    cout<< "Moi ban nhap n: "; cin>> n;
    double a[n];
    cout<< "Moi ban nhap phan tu thu 0 = "; cin>> a[0];
    for (int i=1; i<n; i++){
        cout<< "Moi ban nhap phan tu thu "<< i<< " = "; cin>> a[i];
        while(a[i]<=a[i-1]){
            cout<< "Ban nhap sai, moi ban nhap lai: ";
            cin>> a[i];
        }
    }
    cout<< endl<< "Mang ban nhap la: "<< endl;
    for (int i=0; i<n; i++){
        cout<< a[i]<< "\t";
    }
}
