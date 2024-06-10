#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    double sum=0;
    cout<< "Moi ban nhap vao n: "; cin>> n;
    for (int i=n; i>=2; i--){
        if (i==n) sum=sqrt(i);
        sum=sqrt(i-1+sum);
    }
    cout<< "Ket qua la: "<< sum;
}
