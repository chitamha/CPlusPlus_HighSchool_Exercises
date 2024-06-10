#include <iostream>
using namespace std;
int so, sum=0, s;
int k;
int main(int argc, char** argv) {
	cout<< "SO HOAN THIEN"<< endl;
	cout<< "Moi ban nhap 1 so nguyen duong: ";
	cin>> so;
	cout<< "Nhap k: "; cin>>k;
	cout<< "So hoan thien tu 1 den k la: ";
	/*
	for (int i=1; i<so; i++){
		if (so%i==0){
			sum+=i;
		}
	*/
	int h=1;
	while (h<so){
		if (so%h==0){
			sum+=h;
		}
		h++;
	}
	for (int i=2; i<=k; i++){
		s=0;
		for (int j=1; j<i; j++){
			if (i%j==0){
				s+=j;
			}
		}
		if (s==i){
			cout<< i<< " ";
		}
	}
	cout<< endl;
	cout<< so<< (sum==so ? " la so hoan thien": " khong phai la so hoan thien");
	return 0;
}
