#include <bits/stdc++.h>
using namespace std;

int n, A[1000005];
struct node{
    node *left, *right;
    //left, right sẽ là con trỏ
    int val;
    node(int x){
        left=nullptr;
        right=nullptr;
        val=x;
    }
};

void Insert(node* &ptr, int x){
    //*ptr là một con trỏ
    //* &ptr là ô địa chỉ của con trỏ ptr
    if (ptr==nullptr){
        ptr=new node(x);
        //new node(x) là địa chỉ của node(x)
        return;
    }
    if (ptr->val>=x) Insert(ptr->left, x);
    else Insert(ptr->right, x);
}

node* Find(node* ptr, int x){
    if (ptr==nullptr) return nullptr;
    if (ptr->val==x) return ptr;
    else if (ptr->val>=x) return Find(ptr->left, x);
    else return Find(ptr->right, x);
}

void Delete(node* &ptr, int x){
    if (ptr==nullptr) return;
    if (ptr->val>x) Delete(ptr->left, x);
    else if (ptr->val<x) Delete(ptr->right, x);
    if (ptr->val==x){
        if (ptr->left==nullptr && ptr->right==nullptr){
            ptr=nullptr;
            return;
        }
        else if (ptr->left!=nullptr && ptr->right!=nullptr){
            node* tmp=ptr->right;
            while (tmp->left!=nullptr) tmp=tmp->left;
            ptr->val=tmp->val;
            Delete(ptr->right, tmp->val);
        }
        else{
            if (ptr->right==nullptr) ptr=ptr->left;
            else ptr=ptr->right;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>> n;
    for (int i=1; i<=n; i++) cin>> A[i];
    node* root=nullptr;
    for (int i=1; i<=n; i++) Insert(root, A[i]);
    int x; cin>> x;
    if (Find(root, x)==nullptr) cout<< "Khong tim thay "<< x<< endl;
    else cout<< "Tim thay "<< x<< endl;
    Delete(root, x);
    if (Find(root, x)==nullptr) cout<< "Da xoa "<< x<< endl;
    return 0;
}
