#include <iostream>
using namespace std;
int n;
double tam;
int main(){
    cout<< "Moi ban nhap n: "; cin>> n;
    double arr[n];
    for (int i=0; i<=n-1; i++){
        cin>> arr[i];
    }
    cout<< "Mang chua sap xep"<< endl;
    for (int i=0; i<=n-1; i++){
        cout<< arr[i]<< "\t";
    }
    cout<< endl<< "Mang sap xep roi"<< endl;
    int i=0, j;
    do{
        j=i+1;
        do{
            if (arr[i]<arr[j]){
                tam=arr[i]; arr[i]=arr[j]; arr[j]=tam;
            }
            j++;
        }while(j<=n-1);
        i++;
    }while(i<=n-2);
    for (int k=0; k<=n-1; k++){
        cout<< arr[k]<< "\t";
    }
}
