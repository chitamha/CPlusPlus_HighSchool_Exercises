#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int cow, col;
int main(){
    srand(time(NULL));
    cout<< "Moi ban nhap so hang va so cot: "; cin>> cow>> col;
    int arr[cow][col];
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            arr[i][j]=rand()%100;
        }
    }
    cout<< endl<< "Mang la: "<< endl;
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            cout<< arr[i][j]<< "\t";
        }
        cout<< endl;
    }
    int k=0;
    double tam;
    double a[cow*col];
    for (int i=0; i<cow; i++){
        for (int j=0; j<col; j++){
            a[k]=arr[i][j];
            k++;
        }
    }
    for (int i=0; i<=cow*col-2; i++){
        for (int j=i+1; j<=cow*col-2; j++){
            if (a[i]>a[j]){
                tam=a[i]; a[i]=a[j]; a[j]=tam;
            }
        }
    }
    int h=0;
    cout<< endl<< "Sau khi sap xep: "<< endl;
    for(int k=0; k<cow*col; k++){
        cout<< a[k]<< "\t";
        h++;
        if (h==col){
            cout<< endl;
            h=0;
        }
    }
}
