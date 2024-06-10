#include <bits/stdc++.h>
using namespace std;
int so, tram, chuc, dv;
int main() {
	cout<< "Nhap 1 so nguyen duong co 3 chu so ";
	cin>> so;
	tram = so/100;
	chuc = (so%100)/10;
	dv = (so%100)%10;
	cout<< "So dao nguoc la "<< dv*100 + chuc*10 + tram;
	
	
	
}
