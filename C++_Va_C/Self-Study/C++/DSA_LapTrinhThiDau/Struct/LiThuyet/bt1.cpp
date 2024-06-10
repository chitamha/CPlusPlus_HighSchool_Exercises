#include <bits/stdc++.h>
using namespace std;

//Nội dung bài học
/*
    + Khai báo
    struct ten_struct{
        members
    };
*/

struct SinhVien{
    //#1

    int sothutu;
    string hoten;
    string ngaysinh;
    int tuoi;
    string diachi;
    void in(){
        cout<< "IN"<< endl;
        cout<< sothutu<< ' '<< hoten<< ' '<< ngaysinh<< ' '<< tuoi<< ' '<< diachi<< endl;
    }
    void nhap(){
        cin>> sothutu; cin.ignore();
        getline(cin, hoten);
        getline(cin, ngaysinh);
        cin>> tuoi; cin.ignore();
        getline(cin, diachi);
    }

    //#2
    //Nếu có struct SinhVien trong đây thì chắc chắn sẽ gọi hàm
    //Việc gọi hàm sẽ phụ thuộc vào có tham số hay không và số lượng tham số

    SinhVien(){
        sothutu=10;
        hoten="Ham Chi Ta";
        ngaysinh="02-09-2007";
        tuoi=16;
        diachi="Lap Vo";
    }
    SinhVien(int x){
        sothutu=10;
        hoten="Ci Tam";
        ngaysinh="02-09-2007";
        tuoi=16;
        diachi="Lap Vo";
    }
};

struct sophuc{
    int x, y;

    //#3 Nạp chồng toán tử
    /*
    kieu_tra_ve operator (+, -, *, /, ...) (danh sach tham so){
        coding
    }
    - Định nghĩa operator trong struct chỉ cho phép 1 tham số
    - Nếu muốn 2 tham số thì thêm hàm friend
    */

    sophuc operator + (const sophuc b){
        //Không cần const cũng được
        sophuc c;
        c.x=x+b.x;
        c.y=y+b.y;
        //x, y đơn lẻ là của sophuc a
        return c;
    }
    friend sophuc operator - (const sophuc a, sophuc b){
        sophuc c;
        c.x=a.x-b.x;
        c.y=a.y-b.y;
        return c;
    }
    bool operator == (const sophuc a){
        return x==a.x && y==a.y;
    }
    friend bool operator < (const sophuc a, const sophuc b){
        return a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;
    }

    //insertion >>
    friend istream& operator >> (istream& in, sophuc &a){
        //Thêm & tại vì sau này mình có thể sẽ thay đổi giá trị
        in>> a.x>> a.y;
        return in;
    }

    //extraction <<
    friend ostream& operator << (ostream& out, sophuc a){
        //Không thêm & tại vì mình chỉ in ra thôi
        out<< a.x<< " "<< a.y;
        return out;
    }
};

//So sánh 2 struct theo 1 tiêu chí nào đó

struct sv{
    string ht;
    double gpa;
    bool operator < (const sv sv1){
        return gpa<sv1.gpa;
    }
};


int main(){
    /*
    SinhVien A(1);
    A.in();
    SinhVien B;
    B.in();
    SinhVien C;
    C.nhap();
    C.in();
    sophuc a={1, 2};
    sophuc b={4, 8};
    sophuc d={-3, -6};
    sophuc c=a-b-d;
    cout<< c.x<< " "<< c.y;
    sophuc a;
    cin>> a;
    cout<< a<< endl;
    sophuc b;
    cin>> b;
    cout<< b<< endl;
    if (a<b) cout<< "YES"<< endl;
    else cout<< "NO"<< endl;
    cout<< to_string(a==b);
    */
    int n; cin>> n;
    sv ds[n];
    for (int i=0; i<n; i++){
        cin.ignore();
        getline(cin, ds[i].ht);
        cin>> ds[i].gpa;
    }
    sort(ds, ds+n);
    for (sv A:ds){
        cout<< A.ht<< " "<< A.gpa<< endl;
    }
    return 0;
}
