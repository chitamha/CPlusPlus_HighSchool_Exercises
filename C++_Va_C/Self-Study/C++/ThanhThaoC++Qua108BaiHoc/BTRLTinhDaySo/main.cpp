/*#include <iostream>
#include <math.h>
using namespace std;
int n;
double sum=0, x, gt;
int main(int argc, char** argv) {
	cout<< "Moi ban nhap lan luot x va n: ";
	cin>> x>> n;
	for (int i=1; i<=n; i++){
		gt=1;
		for (int j=1; j<=i; j++){
			gt*=j;
		}
		sum+=pow(x, i)/gt;
	}
	cout<<"Ket qua la: "<< sum;
	return 0;
}*/
/*
#include <iostream>
#include <math.h>
using namespace std;
int n;
double sum=0, x, gt;
int main(int argc, char** argv) {
	cout<< "Moi ban nhap lan luot x va n: ";
	cin>> x>> n;
	gt=1;
	for (int i=1; i<=n; i++){
		gt=gt*i;
		sum+=pow(x, i)/gt;
	}
	cout<<"Ket qua la: "<< sum;
	return 0;
}
*/
#include <iostream>
#include <math.h>
using namespace std;
double x, sum=0, gt;
int n;
int main(){
	cout<< "Moi ban nhap x: "; cin>>x;
	cout<< "Moi ban nhap n: "; cin>>n;
	/*
	gt=1;
	int i=1;
	while(i<=n){
		gt*=i;
		sum+=pow(x, i)/gt;
		i++;
	}
	*/
	/*
	int i=1;
	while(i<=n){
		gt=1;
		int j=1;
		while(j<=i){
			gt*=j;
			j++;
		}
		sum+=pow(x, i)/gt;
		i++;
	}
	cout<< "Ket qua la: "<< sum;
	*/
	gt=1;
	int i=1;
	do{
		gt*=i;
		sum+=pow(x, i)/gt;
		i++;
	}while(i<=n);
	cout<<"Ket qua = "<< sum;
}
