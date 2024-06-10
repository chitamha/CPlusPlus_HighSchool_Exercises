#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int cot, dong;
int main(){
    srand(time(NULL));
    cout<<"Moi ban nhap lan luot so dong va cot: "; cin>>dong>>cot;
    int arr[dong][cot];
    for(int i=0; i<=dong-1; i++){
        for(int j=0; j<=cot-1; j++){
            arr[i][j]=rand()%100;
        }
    }
    cout<< "Ma tran la: "<< endl;
    for(int i=0; i<=dong-1; i++){
        for(int j=0; j<=cot-1; j++){
            cout<<arr[i][j]<< "\t";
        }
        cout<< endl;
    }
    int a, b;
    cout<< endl<< "Nhap dong thu ma ban muon xuat"<< endl; cin>>a;
    for (int j=0; j<=cot-1; j++)
        cout<< arr[a-1][j]<< "\t";
    cout<< endl<< "Nhap cot thu ma ban muon xuat"<< endl; cin>>b;
    for (int i=0; i<=dong-1; i++)
        cout<< arr[i][b-1]<< "\t";
    cout<< endl;
    if (dong==cot){
        for(int i=0; i<=dong-1; i++){
            for(int j=0; j<=cot-1; j++){
                if (j==i){
                    cout<<arr[i][j]<< "\t";
                }
                else if (j+i==cot-1){
                    cout<< arr[i][j]<< "\t";
                }
                else{
                    cout<<"\t";
                }
            }
            cout<< endl;
        }
    }
}
