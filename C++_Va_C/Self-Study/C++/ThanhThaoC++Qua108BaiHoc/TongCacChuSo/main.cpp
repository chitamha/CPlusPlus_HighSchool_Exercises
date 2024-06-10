/*#include <bits/stdc++.h>
using namespace std;
int so, soso, sum=0;
int hang;
int main(){
	cout<< "Moi ban nhap so: "; cin>> so;
	int hangsoso=so;
	for (int i=1; i<=20; i++){
		if (pow(10, i)>so){
			soso=i;
			cout<< "So cac chu so cua "<< so<< " la "<< soso<< endl;
			break;
		}
	}
	for (int i=soso-1; i>=0; i--){
		int hh=pow(10,i);
		hang = so/hh;
		sum = sum + hang;
		so = so%hh;
	}
	cout<< "Tong cac chu so tao nen "<< hangsoso<< " la: "<< sum;
	
	
	//std::cout << std::numeric_limits<int>::min() << " den " << std::numeric_limits<int>::max() << std::endl;
	return 0;
}
*/
/*
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int so, soso, sum = 0;
    int hang;

    cout << "Moi ban nhap so: ";
    cin >> so;
	int hangso = so;
    for (int i = 1; i <= 10; i++) {
        if (i > log10(so)) {
            soso = i;
            cout << soso << endl;
            break;
        }
    }

    for (int i = soso - 1; i >= 0; i--) {
        hang = so / pow(10, i);
        sum = sum + hang;
        so = so % static_cast<int>(pow(10, i));
    }

    cout << "Tong cac chu so tao nen so " << hangso << " la: " << sum;

    return 0;
}*/
/*
#include <bits/stdc++.h>
using namespace std;
int so, soso, sum=0;
int hang;
int main(){
	cout<< "Moi ban nhap so: "; cin>> so;
	int kkk = so;
	for (int i=1; i<=20; i++){
		if (pow(10, i)>so){
			soso=i;
			cout<< soso<< endl;
			break;
		}
	}
	for (int i=soso-1; i>=0; i--){
		//int hhhh=pow(10, i);
		//hang = so/hhhh;
		hang = so/int(pow(10, i));
		sum = sum + hang;
		so = so%int(pow(10, i));
		//so = so%hhhh;
	}
	cout<< "Tong cac chu so tao nen so "<< kkk<< " la: "<< sum;
	
	
	//std::cout << std::numeric_limits<int>::min() << " den " << std::numeric_limits<int>::max() << std::endl;
	return 0;
}
*/
#include <iostream>
using namespace std;
int n, sum = 0, dv;
int main(){
	cout<< "Nhap n: ";
	cin>> n;
	/*do {
		dv = n%10;
		n = n/10;
		sum += dv;
	} while (n>0);
	*/
	while (n>0){
		dv = n%10;
		n = n/10;
		sum += dv;
	}
	cout<< "Tong bang: "<< sum;
}
