#include <bits/stdc++.h>
using namespace std;
class MyClass {
public:
    int item;
    MyClass *lson, *rson; 
    MyClass (int _item) : item(_item) {}
};
class Tree{
public:
    MyClass *node;
};
int main() {
    // Tree t;
    // MyClass *a = new MyClass(2);
    // a->lson = new MyClass(1);
    // a->rson = new MyClass(3);
    // int x = 4;
    // MyClass *root = a, **leave = &root;
    // for (; *leave != nullptr; leave = (x < (*leave)->item ? &((*leave)->lson) : &((*leave)->rson)));
    // *leave = new MyClass(x);
    // cout << a->item << endl;
    // cout << a->rson->item << endl;
    // cout << a->rson->rson->item << endl;
    MyClass *a;
    a = new MyClass(2);
    cerr << (a->lson == nullptr) << endl;
    // cerr << *(a->lson) << endl;
}