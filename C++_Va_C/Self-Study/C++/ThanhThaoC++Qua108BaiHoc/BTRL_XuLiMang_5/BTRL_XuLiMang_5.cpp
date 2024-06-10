#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int n, demchan=0, demle=0, demsnt=0;
int main (){
    srand(time(NULL));
    cout<< "Nhap n: "; cin>> n;
    int a[n];
    for (int i=0; i<n; i++){
        a[i]=rand()%100;
    }
    cout<< endl<< "Mang sau khi nhap la:"<< endl;
    for (int i=0; i<n; i++){
        cout<< a[i]<< "\t";
    }
    cout<< endl;
    for (int i=0; i<n; i++){
        if (a[i]%2==0){
            cout<< a[i]<< "\t";
            demchan+=1;
        }
    }
    cout<< endl<< "Co "<< demchan<< " so chan"<< endl;
    for (int i=0; i<n; i++){
        if (a[i]%2!=0){
            cout<< a[i]<< "\t";
            demle+=1;
        }
    }
    cout<< endl<< "Co "<< demle<< " so le"<< endl;
    int demuoc=0;
    for (int i=0; i<n; i++){
        for (int j=1; j<=a[i]; j++){
            if (a[i]%j==0){
                demuoc+=1;
            }
        }
        if (demuoc==2){
            cout<< a[i]<< "\t";
            demsnt+=1;
        }
        demuoc=0;
    }
    cout<< endl<< "Co "<< demsnt<< " so nguyen to"<< endl;
}
