#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float sum1=0, sum2=0, sum3=0;
int n;
int main(int argc, char** argv) {
	int i=1;
	cin>> n;
	do {
		sum1+=i;
		i++;
	} while (i<=n);
	int k=1;
	while (k<=n){
		sum2+=k;
		k++;
	}
	int j;
	for (j=1; j<=n; j++) {
		sum3+=j;
		cout<< j<< endl;
	}
	cout<< sum1<<"\t"<< sum2<<"\t"<< sum3<< endl;
	cout<< i<< "\t"<< j<< "\t"<< k;
	return 0;
}
