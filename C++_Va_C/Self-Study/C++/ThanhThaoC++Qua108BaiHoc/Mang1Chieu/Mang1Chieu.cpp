#include <iostream>
using namespace std;
int n;
int k, dem=0;
int main(){
    cout<< "Moi ban nhap so luong phan tu cho mang a: "; cin>> n;
    int a[n];
    int i=0;
    cout<< "Moi ban gan gia tri cho cac phan tu"<< endl;
    do{
        cin>> a[i];
        i++;
    } while(i<=n-1);
    cout<< "Gia tri ban muon tim kiem la: "; cin>> k;
    for (int i=0; i<n; i++){
        if (a[i]==k) {
            dem+=1;
        }
    }
    if (dem>0) {cout<< "Gia tri "<< k<< " co xuat hien va xuat hien "<< dem<< " lan"<< endl;} else{
        cout<< "Khong xuat hien";
    }
}
