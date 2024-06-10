#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double a, b, c, delta;
int main(int argc, char** argv) {
	cout<< "Nhap he so a, b, c: ";
	cin>> a>> b>> c;
	delta = pow(b, 2) - 4*a*c;
	if (delta>0)
	{
		double x1 = (-b+sqrt(delta))/(2*a);
		double x2 = (-b-sqrt(delta))/(2*a);
		cout<< "Phuong trinh co 2 nghiem phan biet la "<< x1<< " va "<< x2;
	}
	else if (delta<0)
	{
		cout<< "Phuong trinh vo nghiem";
	}
	else
		cout<< "Phuong trinh co nghiem duy nhat, x = "<< -b/(2*a);
	
	
	
	
	return 0;
}
