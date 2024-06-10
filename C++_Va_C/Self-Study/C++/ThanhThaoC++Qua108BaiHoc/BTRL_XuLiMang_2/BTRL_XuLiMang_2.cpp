#include <iostream>
using namespace std;
int n, sum=0;
int main(){
    cout<< "Moi ban nhap n: "; cin>> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cout<< "Nhap gia tri cho phan tu thu "<< i<< endl;
        cin>> arr[i];
        sum+=arr[i];
    }
    cout<< endl;
    int max=arr[0];
    for (int i=0; i<n; i++){
        if (arr[i]>=max) max=arr[i];
    }
    int min=arr[0];
    for (int i=0; i<n; i++){
        if (arr[i]<=min) min=arr[i];
    }
    cout<< max<< "\t"<< min;
    cout<< endl<< "Tong la: "<< sum;
}
