#include <bits/stdc++.h>
using namespace std;

/*
struct SinhVien{
    string hoten;
    int tuoi;
    double gpa;
};
void change(int *ptr){
    *ptr=1000;
}
*/

struct node{
    int data;
    //2 con trỏ
    node *left; //Lưu địa chỉ của node bên trái
    node *right; //Lưu địa chỉ của node bên phải
    //Constructor
    /*
    node (int x){
        data=x;
        left=right=NULL;
    }
    */
};

node *MakeNode(int x){
    node *NewNode=new node;
    NewNode->data=x;
    NewNode->left=NewNode->right=NULL;
    return NewNode;
}

int main(){
//Con trỏ
    /*
    int a=100;
    int *ptr=&a;
    *ptr=200;
    cout<< a<< endl;
    change(&a);
    cout<< a<< endl;
    */

    /*
    SinhVien A;
    SinhVien *ptr=&A;
    (*ptr).hoten="Ha Chi Tam";
    //ptr->hoten="Ham Chi Ta";
    (*ptr).tuoi=17;
    //ptr->tuoi=16;
    (*ptr).gpa=4.0;
    //ptr->gpa=0.0;
    cout<< A.hoten<< " "<< A.tuoi<< " "<< A.gpa<< endl;
    */

    //Cấp phát động

    /*
    SinhVien *ptr=new SinhVien();
    //Cấp phát 1 phần tử
    //SinhVien *ptr=new SinhVien[n]; //Cấp phát n phần tử
    //Phần tử thuộc kiểu SinhVien đó, sẽ được quản lí bởi con trỏ ptr
    ptr->hoten="Om"; ptr->tuoi=17; ptr->gpa=4.0;
    cout<< (*ptr).hoten<< " "<< (*ptr).tuoi<< " "<< (*ptr).gpa<< endl;
    cout<< ptr->hoten<< " "<< ptr->tuoi<< " "<< ptr->gpa<< endl;
    //Sau khi cấp phát xong, có thể giải phóng bằng delete (sẽ không bị leak memory)
    delete ptr;
    */

//Cây nhị phân
    //node *root=new node(10);
    //Hoặc node *root=MakeNode(1000);
    //cout<< root->data<< " "<< root->left<< " "<< root->right<< endl;
    node *root=MakeNode(1);
    node *node2=MakeNode(2);
    node *node3=MakeNode(3);
    root->left=node2;
    root->right=node3;
    cout<< root->left<< " "<< node2<< endl;
    cout<< root->right<< " "<< node3<< endl;
    return 0;
}
