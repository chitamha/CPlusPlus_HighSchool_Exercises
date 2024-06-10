#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int A[1000];
int m;

void nhapA(int m, int A[]){
    srand(time(NULL));
    for (int i=0; i<m; i++){
        A[i]=rand()%100;
    }
}

void xuatA(int m, int A[]){
    for (int i=0; i<m; i++){
        cout<< A[i]<< " ";
    }
}

void sapXep(int m, int A[]){
    for (int i=0; i<=m-2; i++){
        for (int j=i+1; j<=m-1; j++){
            if (A[i]>A[j]){
                int tam;
                tam=A[i]; A[i]=A[j]; A[j]=tam;
            }
        }
    }
}

int main(){
    cin>> m;
    nhapA(m, A);
    xuatA(m, A);
    sapXep(m, A);
    cout<< endl<< A[1];

}
