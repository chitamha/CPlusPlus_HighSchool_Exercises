/*#include <iostream>
#include <math.h>
using namespace std;
int cow1, col1;
int arr1[1000][1000];
int main(){
    cin>> cow1>> col1;
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            cin>> arr1[i][j];
        }
    }
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            cout<< arr1[i][j]<< "\t";
        }
        cout<< endl;
    }
    int sum=0;
    for (int i=0; i<cow1; i++){
        for (int j=0; j<col1; j++){
            int k=int(sqrt(arr1[i][j]));
            if (pow(k, 2) == arr1[i][j]){
                sum+=arr1[i][j];
            }
        }
    }
    cout<< "Tong cac so chinh phuong la: "<< sum;
}*/
#include<bits/stdc++.h>

using namespace std;

int a[100][100];
int n,m,kq;

void nhapMang(int a[][100], int n, int m)
{
    for(int i=0 ; i<n; i++){
        for(int j=0; j<m; j++){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j] ;
        }
   }
}
void xuatMang(int a[][100], int n, int m)
{
    for(int i=0 ; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
   }
}
// Kiem tra so chinh phuong
int chinhPhuong(int x)
{
    int k=sqrt(x);
    if(x == powf(k,2))
        return 1;
    if(x!= powf(k,2))
        return 0;
    return 1;
}
// Tinh tong cac so chinh phuong
int TongsoCP(int a[][100], int n, int m)
{
    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(chinhPhuong(a[i][j])){
                sum=sum + a[i][j];
            }
        }
    }
    return sum;
}
int main()
{
   cout<<"Nhap so dong: "; cin>>n;
   cout<<"Nhap so cot: "; cin>>m;
   nhapMang(a,n,m);
   cout<<"Mang vua nhap la: "<<endl;
   xuatMang(a,n,m);
   kq = TongsoCP(a,n,m);
   cout<<"Tong cac so chinh phuong la: "<<kq<<endl;
   return 0;
}
