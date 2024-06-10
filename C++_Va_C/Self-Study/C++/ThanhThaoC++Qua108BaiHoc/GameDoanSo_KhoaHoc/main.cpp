#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	srand(time(NULL));
	while(true)
	{	
		int somay=1+rand()%100;
		cout<<"Chuong trinh choi Game doan so!\n";	
		int solandoan=0;
		bool iswin=false;
		do
		{	
			cout<<"May da doan so [1..100], moi ban doan:\n";
			int songuoi;
			cin>>songuoi;
			solandoan++;
			cout<<"Ban doan lan thu "<<solandoan<<endl;
			if(songuoi==somay)
			{
				cout<<"Ha ha ban tai that, so may ="<<somay<<endl;
				iswin=true;
				break;//Thang va ngung vong lap
			}	
			else if (songuoi>somay)
			{
				cout<<"Ban doan sai, so nguoi>so may"<<endl;
			}
			else 
			{
				cout<<"Ban doan sai, so nguoi<so may"<<endl;
			}
			if(solandoan==7)
				break;//Thua ngung
		}while(true);
		if(iswin!=true)
		{
			cout<<"GAME OVER!\n";
			cout<<"So cua may ="<<somay<<endl;
		}
		cout<<"Tiep khong Thim?(c/k):";
		char c;
		cin>>c;
		if(c=='k')
			break;//ngung Game khong choi nua
	}
	cout<<"GOODBYE!";
	return 0;
}
