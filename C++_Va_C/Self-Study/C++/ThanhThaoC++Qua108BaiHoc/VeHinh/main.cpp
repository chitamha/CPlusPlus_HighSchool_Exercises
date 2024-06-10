#include<iostream>
#include<iomanip>
using namespace std;
int n;
int giaithua(int n){
	int s=1;
	for(int i=1;i<=n;i++) s*=i;
	return s;
}
int main(){
	cin>>n;
		cout<<(int)giaithua(n)/(giaithua(3)*giaithua(n-3));
	return 0;
}
