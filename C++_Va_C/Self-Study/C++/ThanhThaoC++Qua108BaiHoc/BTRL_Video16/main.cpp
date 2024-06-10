#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char kt;
int main(int argc, char** argv) {
	cout<< "Moi ban nhap 1 ki tu ";
	cin>> kt;
	cout<< "Ma ASCII cua "<< kt<< " la: "<< int(kt)<< endl;
	int maketiep = int(kt)+1;
	cout<< "Ki tu ke tiep la "<< char(maketiep);
	return 0;
}
