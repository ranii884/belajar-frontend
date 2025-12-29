#include <iostream>
using namespace std;

#define MAX 5  

struct Notifikasi {
    string pesan;
    string waktu;
};

struct Queue {
    Notifikasi data[MAX];
    int front, rear;
};

// Inisialisasi Queue
void init(Queue &q) {
    q.front = q.rear = -1;
}

bool isEmpty(Queue &q) {
    return q.front == -1;
}

bool isFull(Queue &q) {
    return q.rear == MAX - 1;
}

// Tambah notifikasi baru (INSERT / Enqueue)
void enqueue(Queue &q, Notifikasi notif) {
    if (isFull(q)) {
        cout << "Kotak notifikasi penuh! Tidak bisa menambah notifikasi baru.\n";
        return;
    }
    if (isEmpty(q)) {
        q.front = q.rear = 0;
    } else {
        q.rear++;
    }
    q.data[q.rear] = notif;
    cout << "Notifikasi masuk: \"" << notif.pesan 
         << "\" pada " << notif.waktu << endl;
}

// Hapus notifikasi terdepan (DELETE / Dequeue)
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Tidak ada notifikasi untuk dibuka/hapus.\n";
        return;
    }
    cout << "Membuka notifikasi: \"" << q.data[q.front].pesan 
         << "\" pada " << q.data[q.front].waktu << endl;

    if (q.front == q.rear) {
        init(q); // kosongkan kalau terakhir dihapus
    } else {
        q.front++;
    }
}

// Reset queue
void reset(Queue &q) {
    init(q);
    cout << "Semua notifikasi dihapus (reset).\n";
}

// Menampilkan isi notifikasi
void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "Tidak ada notifikasi.\n";
        return;
    }
    cout << "\n=== Daftar Notifikasi WhatsApp ===\n";
    for (int i = q.front; i <= q.rear; i++) {
        cout << i - q.front + 1 << ". [" << q.data[i].waktu 
             << "] " << q.data[i].pesan << endl;
    }
    cout << "Front = " << q.front << " | Rear = " << q.rear << endl;
}

int main() {
    Queue q;
    init(q);
    
    cout << "TUGAS STRUKTUR DATA PERT6\n";
    cout << "=================================\n";
    cout << "Nama : Siti Fatul Zahrani\n";
    cout << "NIM  : 241011401373\n";
    cout << "STUDI KASUS: NOTIFIKASI WHATSAPP\n";
    cout << "=================================\n";

    int pilihan;
    Notifikasi notif;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah notifikasi baru\n";
        cout << "2. Buka notifikasi terdepan\n";
        cout << "3. Lihat semua notifikasi\n";
        cout << "4. Reset semua notifikasi\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid! Masukkan angka.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(); // membersihkan newline sebelum getline

        switch (pilihan) {
            case 1:
                cout << "Pesan notifikasi: ";
                getline(cin, notif.pesan);
                cout << "Waktu (HH:MM): ";
                getline(cin, notif.waktu);
                enqueue(q, notif);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                reset(q);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
