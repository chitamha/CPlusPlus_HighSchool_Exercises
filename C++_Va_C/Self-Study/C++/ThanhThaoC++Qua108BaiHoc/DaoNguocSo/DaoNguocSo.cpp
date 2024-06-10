#include <iostream>
using namespace std;
int n, socu, somoi=0, hang;
int main(){
    cout<< "Moi ban nhap 1 so nguyen duong: "; cin>> n;
    socu=n;
    while(n>0){
        hang=n%10;
        n=n/10;
        somoi=somoi*10+hang;
    }
    cout<< somoi;
}
