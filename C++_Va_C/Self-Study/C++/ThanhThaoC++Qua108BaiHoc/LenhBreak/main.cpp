#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n, i, sum=0;
int main(int argc, char** argv) {
	cout<< "Nhap so nguyen duong n: ";
	cin>> n;
	for (i=1; i<=n; i++){
		sum+=i;
		if (sum>=9){
			break;
		}
	}
	cout<< sum;
	return 0;
}
