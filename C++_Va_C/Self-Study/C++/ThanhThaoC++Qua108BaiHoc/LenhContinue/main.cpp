#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n, i=0, sum=0;
int main(int argc, char** argv) {
	cout<< "Nhap so nguyen duong n: ";
	cin>> n;
	do {
		i++;
		if (i==2 || i==4) {
			continue;
		}
		sum+=i;
		
	} while(i<n);
	cout<< sum; // tinh tong tu 1 den n sao cho khong cong tong cua 2 va 4
	return 0;
}
