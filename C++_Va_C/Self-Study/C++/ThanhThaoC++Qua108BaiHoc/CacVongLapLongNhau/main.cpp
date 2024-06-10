#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int i=0, j=0, h;
int main(int argc, char** argv) {
	cout<< "Moi ban nhap chieu cao: ";
	cin>> h;
	for (i=0; i<h; i++){
		for (j=0; j<h; j++){
			if (j==0 || i==h-1 || i==j){
				cout<< "*";
			} else{
				cout<< " ";
			}
		}
		cout<< endl;
	}
	return 0;
}
