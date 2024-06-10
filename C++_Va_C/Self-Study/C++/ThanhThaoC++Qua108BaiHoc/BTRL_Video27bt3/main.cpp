#include <bits/stdc++.h>
using namespace std;
int so, dv, chuc;
string tam1, tam2;
int main(int argc, char** argv) {
	cout<< "Nhap so: ";
	cin>> so;
	dv = so%10;
	chuc = so/10;
	switch (dv){
		case 0:
			tam1 = "";
			break;
		case 1:
			tam1 = "mot";
			break;
		case 2:
			tam1 = "hai";
			break;
		case 3:
			tam1 = "ba";
			break;
		case 4:
			tam1 = "bon";
			break;
		case 5:
			tam1 = "lam";
			break;
		case 6:
			tam1 = "sau";
			break;
		case 7:
			tam1 = "bay";
			break;
		case 8:
			tam1 = "tam";
			break;
		case 9:
			tam1 = "chin";
			break;
	}
	switch (chuc){
		case 1:
			tam2 = "mot";
			break;
		case 2:
			tam2 = "hai";
			break;
		case 3:
			tam2 = "ba";
			break;
		case 4:
			tam2 = "bon";
			break;
		case 5:
			tam2 = "nam";
			break;
		case 6:
			tam2 = "sau";
			break;
		case 7:
			tam2 = "bay";
			break;
		case 8:
			tam2 = "tam";
			break;
		case 9:
			tam2 = "chin";
			break;
	}
	if (chuc==1){
		cout<< "Doc la muoi "<< tam1;
	}
	else if (dv==0){
		cout<< "Doc la "<< tam2<< " muoi";
	}
	else{
		cout<< "Doc la "<< tam2 << " muoi "<< tam1;
	}
	return 0;
}
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap mot so tu nhien co 2 chu so: ";
    cin >> n;

    if (n >= 10 && n <= 99) {
        int hangChuc = n / 10;
        int hangDonVi = n % 10;

        string docHangChuc, docHangDonVi;

        switch (hangChuc) {
            case 1:
                docHangChuc = "mý?i";
                break;
            case 2:
                docHangChuc = "hai mýõi";
                break;
            case 3:
                docHangChuc = "ba mýõi";
                break;
            case 4:
                docHangChuc = "b?n mýõi";
                break;
            case 5:
                docHangChuc = "nãm mýõi";
                break;
            case 6:
                docHangChuc = "sáu mýõi";
                break;
            case 7:
                docHangChuc = "b?y mýõi";
                break;
            case 8:
                docHangChuc = "tám mýõi";
                break;
            case 9:
                docHangChuc = "chín mýõi";
                break;
        }

        switch (hangDonVi) {
            case 0:
                docHangDonVi = "";
                break;
            case 1:
                docHangDonVi = "m?t";
                break;
            case 2:
                docHangDonVi = "hai";
                break;
            case 3:
                docHangDonVi = "ba";
                break;
            case 4:
                docHangDonVi = "b?n";
                break;
            case 5:
                docHangDonVi = "nãm";
                break;
            case 6:
                docHangDonVi = "sáu";
                break;
            case 7:
                docHangDonVi = "b?y";
                break;
            case 8:
                docHangDonVi = "tám";
                break;
            case 9:
                docHangDonVi = "chín";
                break;
        }

        cout << "So " << n << " doc la " << docHangChuc << " " << docHangDonVi << endl;
    } else {
        cout << "So nhap vao khong hop le." << endl;
    }

    return 0;
}
*/
