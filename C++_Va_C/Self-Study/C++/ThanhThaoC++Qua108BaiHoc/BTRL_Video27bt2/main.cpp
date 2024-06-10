#include <bits/stdc++.h>
using namespace std;
int nam, thang;
int main(){
	cout<< "Moi ban nhap lan luot thang va nam: ";
	cin>> thang>> nam;
	if (thang>=1 && thang<=12){
		if (thang==1 || thang==3 || thang==5 || thang==7|| thang==8 || thang==10|| thang==12){
			cout<< "Thang " << thang<< " nam "<< nam<< " co 31 ngay";
		}
		else if (thang==2) {
			if ((nam%4==0 && nam%100!=0)||(nam%400==0)) {
				cout<< "Thang " << thang<< " nam "<< nam<< " co 29 ngay";
			}
			else{
				cout<< "Thang " << thang<< " nam "<< nam<< " co 28 ngay";
			}
		}
		else{
			cout<< "Thang " << thang<< " nam "<< nam<< " co 30 ngay";
		}
	}
	else
	{
		cout<< "Khong ton tai thang do";
	}
	return 0;
}
