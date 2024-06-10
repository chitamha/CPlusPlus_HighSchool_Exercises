#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double a, b, c;
int main(int argc, char** argv) {
	cout<< "Moi ban nhap vao 3 canh cua tam giac: ";
	cin>> a>> b>> c;
	if (a>0 && b>0 && c>0){
		if (a+b>c && a+c>b && b+c>a){
			cout<< "Chu vi la "<< a+b+c<< endl;
			double p = (a+b+c)/2;
			cout<< "Dien tich la "<< pow(p*(p-a)*(p-b)*(p-c), 0.5)<< endl;
		}
		else{
			cout<< "Khong phai la 1 tam giac";
		}
	}
	else {
		cout<< "Do dai cac canh khong dung";
	}
	return 0;
}
