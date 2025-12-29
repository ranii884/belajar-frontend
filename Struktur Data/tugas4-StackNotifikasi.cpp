#include <iostream>
using namespace std;

#define MAX 20


struct Notifikasi {
    string pesan;
    string waktu;
};

struct Stack {
    Notifikasi data[MAX];
    int top;
};

// Inisialisasi Stack
void init(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == MAX - 1;
}

void push(Stack &s, Notifikasi notif) {
    if (isFull(s)) {
        cout << "Kotak notifikasi penuh! Tidak bisa menambah notifikasi baru.\n";
        return;
    }
    s.top++;
    s.data[s.top] = notif;
    cout << "Notifikasi baru: \"" << notif.pesan 
         << "\" pada " << notif.waktu << " berhasil ditambahkan.\n";
}

void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "?? Tidak ada notifikasi untuk dihapus.\n";
        return;
    }
    Notifikasi notif = s.data[s.top];
    s.top--;
    cout << "Notifikasi \"" << notif.pesan << "\" dihapus dari daftar.\n";
}

void peek(Stack &s) {
    if (isEmpty(s)) {
        cout << "?? Tidak ada notifikasi baru.\n";
        return;
    }
    cout << "Notifikasi terbaru: \"" 
         << s.data[s.top].pesan 
         << "\" pada " << s.data[s.top].waktu << "\n";
}

void display(Stack &s) {
    if (isEmpty(s)) {
        cout << "Kotak notifikasi kosong.\n";
        return;
    }
    cout << "\n=== DAFTAR NOTIFIKASI (dari bawah ke atas) ===\n";
    for (int i = 0; i <= s.top; i++) {
        cout << i + 1 << ". [" << s.data[i].waktu 
             << "] " << s.data[i].pesan << "\n";
    }
}

int main() {
    Stack notifStack;
    init(notifStack);

    int pilihan;
    Notifikasi notif;

    do {
        cout << "\n=== SISTEM NOTIFIKASI APLIKASI ===\n";
        cout << "1. Tambah notifikasi baru\n";
        cout << "2. Hapus notifikasi terakhir\n";
        cout << "3. Lihat notifikasi terbaru\n";
        cout << "4. Tampilkan semua notifikasi\n";
        cout << "5. Keluar program\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cin.ignore();
                cout << "Masukkan pesan notifikasi: ";
                getline(cin, notif.pesan);
                cout << "Masukkan waktu notifikasi (HH:MM): ";
                getline(cin, notif.waktu);
                push(notifStack, notif);
                break;
            case 2:
                pop(notifStack);
                break;
            case 3:
                peek(notifStack);
                break;
            case 4:
                display(notifStack);
                break;
            case 5:
                cout << "? Program selesai. Sampai jumpa!\n";
                break;
            default:
                cout << "? Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}


