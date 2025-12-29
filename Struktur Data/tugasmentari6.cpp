#include <iostream>
using namespace std;

#define MAX 5

struct Notifikasi {
    string pesan, waktu;
};

struct Queue {
    Notifikasi data[MAX];
    int front = -1, rear = -1;
};

bool isEmpty(Queue &q) {
    return q.front == -1;
}

bool isFull(Queue &q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue &q, Notifikasi notif) {
    if (isFull(q)) {
        cout << "Kotak notifikasi penuh!\n";
        return;
    }
    if (isEmpty(q)) q.front = 0;
    q.data[++q.rear] = notif;
    cout << "Notifikasi masuk: \"" << notif.pesan << "\" pada " << notif.waktu << endl;
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Tidak ada notifikasi untuk dibuka.\n";
        return;
    }
    cout << "Membuka notifikasi: \"" << q.data[q.front].pesan << "\" pada " << q.data[q.front].waktu << endl;
    if (q.front == q.rear) q.front = q.rear = -1;
    else q.front++;
}

void reset(Queue &q) {
    q.front = q.rear = -1;
    cout << "Semua notifikasi dihapus.\n";
}

void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "Tidak ada notifikasi.\n";
        return;
    }
    cout << "\n=== Daftar Notifikasi WhatsApp ===\n";
    for (int i = q.front; i <= q.rear; i++)
        cout << (i - q.front + 1) << ". [" << q.data[i].waktu << "] " << q.data[i].pesan << endl;
}

int main() {
    Queue q;
    int pilihan;
    Notifikasi notif;

    cout << "TUGAS STRUKTUR DATA PERT6\n";
    cout << "Nama : Siti Fatul Zahrani\nNIM  : 241011401373\nSTUDI KASUS: NOTIFIKASI WHATSAPP\n";

    do {
        cout << "\nMenu:\n1. Tambah notifikasi\n2. Buka notifikasi\n3. Lihat semua\n4. Reset\n5. Keluar\nPilih: ";
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();

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
