/* Program C++ untuk mengimplementasikan operasi dasar pada Stack */
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack {
    int top;

public:
    int a[MAX]; // Ukuran maksimum Stack

    Stack() { top = -1; }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow\n";
        return false;
    } else {
        a[++top] = x;
        cout << x << " didorong ke dalam tumpukan\n";
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return 0;
    } else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Tumpukan Kosong\n";
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

// Program untuk menguji fungsi di atas
int main() {
    class Stack s;
    s.push(40);
    s.push(13);
    s.push(73);

    cout << s.pop() << " dikeluarkan dari tumpukan\n";
    cout << "nilai paling atas" << s.peek()<<endl;

    return 0;
}
