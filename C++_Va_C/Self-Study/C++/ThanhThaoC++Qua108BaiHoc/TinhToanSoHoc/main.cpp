#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double a, b;
char phep;
int main(int argc, char** argv) {
	cout<< "Nhap 2 so a va b: ";
	cin>> a>> b;
	cout<< "Phep gi ";
	cin>> phep;
	cout<< "Ket qua cua "<< a<< phep<< b<< " la "<< endl;
	switch (phep)
	{
		case '+': cout<< a+b; break;
		case '-': cout<< a-b; break;
		case '*': cout<< a*b; break;
		case '/': if (b==0){
			cout<< "Khong xac dinh";
			break;
		}
		else {
			cout<< a/b;
			break;
		}
		default:
		cout<< "Khong thoa man";
	}
	return 0;
}
