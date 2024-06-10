#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int somay, songuoi, solan;
int main() {
	while(true){
		solan=0;
		srand(time(NULL));
		cout<< "GAME DOAN SO"<< endl;
		somay=rand()%100+1;
		cout<< somay<< endl;
		cout<< "Nhap bat ki 1 so tu [1;100]: "; cin>> songuoi;
		do{
			solan++;
			if (songuoi==somay){
				cout<< "Ha ha ban that tai"<< endl;
				break;
			} else if (songuoi>somay) {
				cout<< "So ban nhap > so cua may"<< endl;
			} else if (songuoi<somay) {
				cout<< "So ban nhap < so cua may"<< endl;
			}
			if (solan==7) {
				cout<< "Ban da thua cuoc"<< endl;
				break;
			}
			cout<< "Ban da nhap sai, moi ban nhap lai: "; cin>>songuoi;

		} while(true);
		cout<< "So may la: "<< somay<< endl;
		cout<< "Ban co muon choi lai khong (c: co, k: khong)"<< endl;
		char c;
		cin>> c;
		if (c=='k') break;
}
	return 0;
}

