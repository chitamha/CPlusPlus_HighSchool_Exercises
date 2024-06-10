#include <iostream>
using namespace std;
int i, j, t, n;
int main(){
    cout<< "Moi ban nhap so phan tu cho mang: "; cin>>n;
    int arr[n];
    for(int i=0; i<=n-1; i++){
        cout<<"arr["<< i<<"] = "; cin>> arr[i];
    }
    for(int i=0; i<=n-2; i++){
        for(int j=i+1; j<=n-1; j++){
            if(arr[i]>arr[j]){ // dau ">" de sap xep tang dan, dau "<" de sap xep giam dan
                t=arr[i]; arr[i]=arr[j]; arr[j]=t;
            }
        }
    }
    for(int i=0; i<=n-1; i++){
        cout<< arr[i]<< "\t";
    }
}
