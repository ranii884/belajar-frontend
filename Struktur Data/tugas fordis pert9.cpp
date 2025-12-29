#include <iostream>
using namespace std;

struct Node {
    int INFO;
    Node* LINK;
};

int main() {
    // Membuat linked list sederhana (cara kompatibel: alok kemudian assign)
    Node *FIRST, *LAST, *Q, *P;

    Node *n1 = new Node;
    n1->INFO = 25;
    n1->LINK = NULL;

    Node *n2 = new Node;
    n2->INFO = 12;
    n2->LINK = NULL;

    Node *n3 = new Node;
    n3->INFO = 27;
    n3->LINK = NULL;

    Node *n4 = new Node;
    n4->INFO = 14;
    n4->LINK = NULL;

    Node *n5 = new Node;
    n5->INFO = 50;
    n5->LINK = NULL;

    // Hubungkan node
    n1->LINK = n2;
    n2->LINK = n3;
    n3->LINK = n4;
    n4->LINK = n5;
    n5->LINK = NULL;

    FIRST = n1;
    LAST = n5;

    // a. Hitung jumlah simpul
    int jumlah = 0;
    P = FIRST;
    while (P != NULL) {
        jumlah++;
        P = P->LINK;
    }
    cout << "Jumlah simpul = " << jumlah << endl;

    // b. Hitung total INFO
    int total = 0;
    P = FIRST;
    while (P != NULL) {
        total += P->INFO;
        P = P->LINK;
    }
    cout << "Total INFO = " << total << endl;

    // c. Cetak semua INFO
    cout << "Isi INFO di Linked List: ";
    P = FIRST;
    while (P != NULL) {
        cout << P->INFO << " ";
        P = P->LINK;
    }
    cout << endl;

    // d. Hitung jumlah simpul dengan INFO = 50
    int count50 = 0;
    P = FIRST;
    while (P != NULL) {
        if (P->INFO == 50)
            count50++;
        P = P->LINK;
    }
    cout << "Jumlah simpul dengan INFO = 50 adalah " << count50 << endl;

    // optional: delete allocated nodes to avoid memory leak
    P = FIRST;
    while (P != NULL) {
        Node *tmp = P->LINK;
        delete P;
        P = tmp;
    }

    return 0;
}

