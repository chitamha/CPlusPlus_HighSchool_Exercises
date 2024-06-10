#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int x, n, i;
int tong=0;
int main(int argc, char** argv) {
	cin>> x>> n;
	for (i=1; i<=n; i++){
		tong+=i;
	}
	cout<< tong<< "\t"<< "i = "<< i;
	return 0;
}
