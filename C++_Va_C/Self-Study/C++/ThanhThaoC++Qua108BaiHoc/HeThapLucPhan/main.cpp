/*#include <iostream>
#include <cctype> // S? d?ng hàm std::toupper d? d?m b?o ký t? vi?t hoa

using namespace std;

int main() {
    char hexChar;
    
    cout << "Nh?p ký t? bi?u di?n ký s? h? th?p l?c phân: ";
    cin >> hexChar;
    
    // Chuy?n d?i ký t? nh?p vào thành ch? hoa d? d?m b?o so sánh dúng
    hexChar = toupper(hexChar);
    
    int decimalValue;
    
    if (hexChar >= '0' && hexChar <= '9') {
        // Ký t? là s? t? 0 d?n 9
        decimalValue = hexChar - '0';
    } else if (hexChar >= 'A' && hexChar <= 'F') {
        // Ký t? là A, B, C, D, E, ho?c F
        decimalValue = hexChar - 'A' + 10;
    } else {
        // Ký t? không h?p l?
        cout << "H? th?p l?c phân không dùng ký s? này" << endl;
        return 1; // Thoát chuong trình v?i mã l?i 1
    }
    
    cout << "Giá tr? th?p phân tuong ?ng là: " << decimalValue << endl;
    
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
