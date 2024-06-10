#include <bits/stdc++.h>
using namespace std;
int ngay, thang, nam;

int main(int argc, char** argv) {
	cout<< "Moi ban nhap ngay thang nam: ";
	cin>> ngay>> thang>> nam;
	if ((ngay>=1 && ngay<=31) && (thang>=1 && thang<=12)){
		if ((ngay>=1 && ngay<=29) && (thang==4 || thang==6 || thang==9 || thang==11)){
			cout<< "Ngay tiep theo la: "<< ngay+1<< " "<< thang<< " "<< nam;
		}
		else if ((ngay==30) && (thang==4 || thang==6 || thang==9 || thang==11)){
			cout<< "Ngay tiep theo la: 1"<< " "<< thang+1<< " "<< nam;
		}
		else if ((ngay>=1 && ngay<=30) && (thang==1 || thang==3 || thang==5 || thang==7 || thang==8 || thang==10 || thang==12))
			cout<< "Ngay tiep theo la: "<< ngay+1<< " "<< thang<< " "<< nam;
		else if  ((ngay==31) && (thang==1 || thang==3 || thang==5 || thang==7 || thang==8 || thang==10)){
			cout<< "Ngay tiep theo la: 1 "<< thang+1<< " "<< nam;
		}
		else if (ngay==31 && thang==12){
			cout<< "Ngay tiep theo la: 1 1 "<< nam+1;
		}
		else if ((ngay>=1 && ngay<=27) && (thang==2)){
			cout<< "Ngay tiep theo la: "<< ngay+1<< " "<< thang<< " "<< nam;
		}
		else if ((nam%4==0 && nam%100!=0) || (nam%4==0 && nam%100==0 && nam%400==0)) {
			if (ngay==29 && thang==2){
				cout<< "Ngay tiep theo la: 1 3 "<< nam;
			}
			if (ngay==28 && thang==2){
				cout<< "Ngay tiep theo la: 29 2 "<< nam;
			}
		}
		else if (ngay==28 && thang==2){
				cout<< "Ngay tiep theo la: 1 3 "<< nam;
			}
		else {
			cout<< "Ngay khong hop le";
		}
		}
	else {
		cout<< "Ngay hoac thang khong hop le";
	}
	return 0;
}
