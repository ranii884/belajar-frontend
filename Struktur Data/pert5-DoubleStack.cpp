#include <iostream>
using namespace std;

#define MAX 6
// Deklarasi Double Stack
class DStack {
private:
    int top1;
    int top2;
    int ele[MAX];

public:
    DStack();
    void pushA(int item);
    void pushB(int item);
    int popA(int *item);
    int popB(int *item);
    void display();
};

// Inisialisasi Double Stack
DStack::DStack() {
    top1 = -1;
    top2 = MAX;
}

// Operasi Push di Stack1
void DStack::pushA(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack1";
        return;
    }
    top1++;
    ele[top1] = item;
    cout << "\nItem disisipkan di Stack1 : " << item;
}

// Operasi Push di Stack2
void DStack::pushB(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack2";
        return;
    }
    top2--;
    ele[top2] = item;
    cout << "\nItem disisipkan di Stack2 : " << item;
}

// Operasi Pop di Stack1
int DStack::popA(int *item) {
    if (top1 == -1) {
        cout << "\nStack Underflow Stack1";
        return -1;
    }
    *item = ele[top1--];
    cout << "\nItem di-pop dari Stack1 : " << *item;
    return 0;
}

// Operasi Pop di Stack2
int DStack::popB(int *item) {
    if (top2 == MAX) {
        cout << "\nStack Underflow Stack2";
        return -1;
    }
    *item = ele[top2++];
    cout << "\nItem di-pop dari Stack2 : " << *item;
    return 0;
}

void DStack::display() {
    cout << "\n\nIsi Stack1 (atas -> bawah): ";
    if (top1 == -1) {
        cout << "Kosong";
    } else {
        for (int i = top1; i >= 0; i--) {
            cout << ele[i] << " ";
        }
    }

    cout << "\nIsi Stack2 (atas -> bawah): ";
    if (top2 == MAX) {
        cout << "Kosong";
    } else {
        for (int i = top2; i < MAX; i++) {
            cout << ele[i] << " ";
        }
    }
    cout << "\n";
}

int main() {
    int item = 0;
    DStack s = DStack();

    s.pushA(24);
    s.pushA(10);
    s.pushA(11);

    s.pushB(40);
    s.pushB(13);
    s.pushB(73);

    s.display();

    s.popA(&item);
    s.popA(&item);
    s.popA(&item);

    s.popB(&item);
    s.popB(&item);
    s.popB(&item);

    s.display();

    return 0;
}
