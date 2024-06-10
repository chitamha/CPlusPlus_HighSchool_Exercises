#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double so;
const int x=600, y=700, z=900, zz=1100;
int main(int argc, char** argv) {
	cout<< "Nhap so kWh da tieu thu: ";
	cin>> so;
	if (so<0)
	{
		cout<< "Khong hop le";
	}
	else if (so<=100)
	{
		cout<< "Tien dien la "<< so*x<< " VND"<< endl;
	}
	else if (so<=150)
	{
		cout<< "Tien dien la "<< so*y<< " VND"<< endl;
	}
	else if (so<=200)
	{
		cout<< "Tien dien la "<< so*z<< " VND"<< endl;
	}
	else
	{
		cout<< "Tien dien la "<< so*zz<< " VND"<< endl;
	}
	return 0;
}
