/*#include <iostream>
#include <cctype> // S? d?ng h�m std::toupper d? d?m b?o k� t? vi?t hoa

using namespace std;

int main() {
    char hexChar;
    
    cout << "Nh?p k� t? bi?u di?n k� s? h? th?p l?c ph�n: ";
    cin >> hexChar;
    
    // Chuy?n d?i k� t? nh?p v�o th�nh ch? hoa d? d?m b?o so s�nh d�ng
    hexChar = toupper(hexChar);
    
    int decimalValue;
    
    if (hexChar >= '0' && hexChar <= '9') {
        // K� t? l� s? t? 0 d?n 9
        decimalValue = hexChar - '0';
    } else if (hexChar >= 'A' && hexChar <= 'F') {
        // K� t? l� A, B, C, D, E, ho?c F
        decimalValue = hexChar - 'A' + 10;
    } else {
        // K� t? kh�ng h?p l?
        cout << "H? th?p l?c ph�n kh�ng d�ng k� s? n�y" << endl;
        return 1; // Tho�t chuong tr�nh v?i m� l?i 1
    }
    
    cout << "Gi� tr? th?p ph�n tuong ?ng l�: " << decimalValue << endl;
    
    return 0;
}
*/
#include <iostream>
using namespace std;
char kt;
int main(int argc, char** argv) {
	cout<< "Moi ban nhap vao 1 ki tu: ";
	cin>> kt;
	if ((kt>='0' && kt<='9') || (kt>='A' && kt<='F')) {
		if (kt>='0' && kt<='9'){
			cout<< "Gia tri tuong ung cua ki tu tren la: "<< kt;
		}
		else
		{
			cout<< "Gia tri tuong ung cua ki so tren la: "<< int(kt)-55;
		}
	}
	else{
		cout<< "Ki tu ban nhap khong hop le";
	}
	return 0;
}
