#include <iostream>
using namespace std;
int n;
int main() {
	cout<< "Moi ban nhap n: "; cin>> n;
	for (int i=0; i<=n-1; i++){
		for (int j=0; j<=n-1; j++){
			if ((i==(n-1)/2) || (j==0 && i<=(n-1)/2) || (j==n-1 && i>=(n-1)/2) || (i==j)){
				cout<< "*";
			}
			else{
				cout<< " ";
			}
		}
		cout<< endl;
	}	
	return 0;
}
