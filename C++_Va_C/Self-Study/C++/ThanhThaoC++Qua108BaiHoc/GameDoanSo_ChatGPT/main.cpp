#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int somay = rand() % 100 + 1;
    int so, sai = 0;
    string rp;

    while (sai <= 7) {
        if (sai == 0) {
            cout << "Moi ban nhap vao 1 so: " << endl;
        } else {
            cout << "Moi ban nhap lai: " << endl;
        }

        if (!(cin >> so)) {
            cout << "Nhap khong hop le. Ket thuc tro choi." << endl;
            break;
        }

        if (so == somay) {
            cout << "Chuc mung! Ban da doan dung so." << endl;
            break;
        } else if (so > somay) {
            cout << "So ban lon hon so may." << endl;
        } else {
            cout << "So ban nho hon so may." << endl;
        }

        sai++;

        if (sai == 7) {
            cout << "Ban da het luot. Ban co muon choi lai khong? (Nhap 'Y' de choi lai, 'N' de ket thuc): ";
            cin >> rp;
            if (rp != "Y" && rp != "y") {
                break;
            } else {
                sai = 0;
                somay = rand() % 100 + 1;
            }
        }
    }

    return 0;
}
