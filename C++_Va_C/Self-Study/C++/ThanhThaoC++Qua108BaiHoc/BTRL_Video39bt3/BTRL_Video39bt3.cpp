#include <iostream>
#include <math.h>
using namespace std;
int n;
double x, sum=0, gt;
int main(){
    cout<< "Moi ban nhap lan luot x va n: "; cin>> x>> n;
    for (int i=0; i<=n; i++){
        gt=1;
        for (int j=1; j<=2*i+1; j++){
            gt*=j;
        }
        sum+=pow(x, 2*i+1)/gt;
    }
    cout<< "Ket qua la: "<< sum;
}
