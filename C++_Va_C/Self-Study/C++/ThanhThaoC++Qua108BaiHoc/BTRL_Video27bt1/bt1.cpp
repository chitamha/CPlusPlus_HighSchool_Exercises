#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double a, b, c;
int main(int argc, char** argv) {
	cout<< "Moi ban nhap 3 so a, b, c: ";
	cin>> a>> b>> c;
	double max=a;
	max = (b>max) && (b>c) ? (b) : ((c>b)&&(c>max) ? c : a);
	cout<< max;
	/*
	int soLonNhat = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
	*/
	
	return 0;
}
