#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int so, sai;
string rp;
int somay;
int main() {
	sai=0;
    srand(time(NULL));
    rp="c";
	while (sai<=7){
	    if (sai==0){
            somay=rand()%100+1;
            cout<< "Moi ban nhap vao bat ki 1 so: \n";
            cin>> so;
            cout<< somay;
            cout<< endl;
	    }
        if (rp=="k") break;
        if (sai<7){
            if (so==somay){
                cout<< "Ha ha ban that tai\n";
                sai=-10;
            }
            else{
                sai+=1;
                if (so>somay){
                    cout<< "So ban lon hon so may\n";
                } else{
                    cout<< "So ban nho hon so may\n";
                }
                if (sai!=7) {cout<< "Moi ban nhap lai: "<< endl; cin>> so;}
            }
        }
        if (sai==7 || sai==-10){
			if (sai==7) cout<< "Ban da thua roi, ban co muon choi lai khong (c: choi, k: khong)"<< endl;
			if (sai==-10) cout<< "Ban co muon choi lai khong (c: choi, k: khong)"<< endl;
			cin>> rp;
			if (rp!="k") sai=0;
		}
    }
}
