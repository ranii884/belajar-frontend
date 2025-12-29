#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

// ==== WARNA ====
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"

void anim(string text, int speed = 30) {
    for(char c : text){
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}

// ==== NODE PLAYLIST ====
struct Node {
    string lagu;
    Node* next;
    Node* prev;
};

Node* head = NULL;
int jumlahLagu = 0;          
const int MAX_LAGU = 5;      // MAKSIMAL 5 LAGU

bool isEmpty() {
    return head == NULL;
}

// ==== TAMBAH DEPAN ====
void tambahDepan(string lagu) {
    if (jumlahLagu >= MAX_LAGU) {
        cout << RED;
        anim("Playlist sudah penuh (maksimal 5 lagu)!\n");
        cout << RESET;
        return;
    }

    Node* baru = new Node();
    baru->lagu = lagu;

    if (isEmpty()) {
        baru->next = baru;
        baru->prev = baru;
        head = baru;
    } else {
        Node* tail = head->prev;

        baru->next = head;
        baru->prev = tail;
        tail->next = baru;
        head->prev = baru;
        head = baru;
    }

    jumlahLagu++;

    cout << GREEN;
    anim("Lagu \"" + lagu + "\" ditambahkan di depan.\n");
    cout << RESET;
}

// ==== TAMBAH BELAKANG ====
void tambahBelakang(string lagu) {
    if (jumlahLagu >= MAX_LAGU) {
        cout << RED;
        anim("Playlist sudah penuh (maksimal 5 lagu)!\n");
        cout << RESET;
        return;
    }

    Node* baru = new Node();
    baru->lagu = lagu;

    if (isEmpty()) {
        baru->next = baru;
        baru->prev = baru;
        head = baru;
    } else {
        Node* tail = head->prev;

        baru->next = head;
        baru->prev = tail;
        tail->next = baru;
        head->prev = baru;
    }

    jumlahLagu++;

    cout << GREEN;
    anim("Lagu \"" + lagu + "\" ditambahkan di belakang.\n");
    cout << RESET;
}

// ==== HAPUS DEPAN ====
void hapusDepan() {
    if (isEmpty()) {
        cout << RED << "Playlist kosong!\n" << RESET;
        return;
    }

    Node* hapus = head;
    string nama = hapus->lagu;

    if (hapus->next == head) {
        head = NULL;
    } else {
        Node* tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }

    delete hapus;
    jumlahLagu--;

    cout << YELLOW;
    anim("Lagu \"" + nama + "\" dihapus dari depan.\n");
    cout << RESET;
}

// ==== HAPUS BELAKANG ====
void hapusBelakang() {
    if (isEmpty()) {
        cout << RED << "Playlist kosong!\n" << RESET;
        return;
    }

    Node* tail = head->prev;
    string nama = tail->lagu;

    if (tail == head) {
        head = NULL;
    } else {
        Node* newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
    }

    delete tail;
    jumlahLagu--;

    cout << YELLOW;
    anim("Lagu \"" + nama + "\" dihapus dari belakang.\n");
    cout << RESET;
}

// ==== TRAVERSAL MAJU ====
void tampilMaju() {
    if (isEmpty()) {
        cout << RED << "Playlist kosong!\n" << RESET;
        return;
    }

    cout << CYAN << "=== Playlist Maju ===\n" << RESET;
    Node* temp = head;

    do {
        cout << BLUE;
        anim("? " + temp->lagu + "\n", 15);
        cout << RESET;
        temp = temp->next;
    } while (temp != head);
}

// ==== TRAVERSAL MUNDUR ====
void tampilMundur() {
    if (isEmpty()) {
        cout << RED << "Playlist kosong!\n" << RESET;
        return;
    }

    cout << MAGENTA << "=== Playlist Mundur ===\n" << RESET;
    Node* tail = head->prev;
    Node* temp = tail;

    do {
        cout << BLUE;
        anim("? " + temp->lagu + "\n", 15);
        cout << RESET;
        temp = temp->prev;
    } while (temp != tail);
}

// ==== PUTAR NEXT ====
void putarNext(Node*& current) {
    if (isEmpty()) {
        cout << RED << "Playlist kosong!\n" << RESET;
        return;
    }

    current = current->next;

    cout << GREEN;
    anim("Sekarang memutar: " + current->lagu + "\n");
    cout << RESET;
}

// ==== PUTAR PREVIOUS ====
void putarPrev(Node*& current) {
    if (isEmpty()) {
        cout << RED << "Playlist kosong!\n" << RESET;
        return;
    }

    current = current->prev;

    cout << GREEN;
    anim("Kembali ke: " + current->lagu + "\n");
    cout << RESET;
}

// ==== MAIN MENU ====
int main() {
    int pilih;
    string lagu;
    Node* current = NULL;

    while (true) {
        cout << CYAN << "\n=== MENU PLAYLIST ("
             << jumlahLagu << "/5 lagu) ===\n" << RESET;
        cout << "1. Tambah Lagu Depan\n";
        cout << "2. Tambah Lagu Belakang\n";
        cout << "3. Hapus Lagu Depan\n";
        cout << "4. Hapus Lagu Belakang\n";
        cout << "5. Tampilkan Playlist Maju\n";
        cout << "6. Tampilkan Playlist Mundur\n";
        cout << "7. Putar Lagu Berikutnya\n";
        cout << "8. Putar Lagu Sebelumnya\n";
        cout << "9. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                cout << "Masukkan nama lagu: ";
                getline(cin, lagu);
                tambahDepan(lagu);
                if (current == NULL) current = head;
                break;

            case 2:
                cout << "Masukkan nama lagu: ";
                getline(cin, lagu);
                tambahBelakang(lagu);
                if (current == NULL) current = head;
                break;

            case 3:
                hapusDepan();
                if (!isEmpty()) current = head;
                break;

            case 4:
                hapusBelakang();
                if (!isEmpty()) current = head;
                break;

            case 5:
                tampilMaju();
                break;

            case 6:
                tampilMundur();
                break;

            case 7:
                putarNext(current);
                break;

            case 8:
                putarPrev(current);
                break;

            case 9:
                cout << GREEN;
                anim("Terima kasih! Keluar...\n");
                cout << RESET;
                return 0;
 
            default:
                cout << RED << "Pilihan tidak valid!\n" << RESET;
        }
    }

    return 0;
}
