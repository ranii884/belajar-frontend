#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;

// Fungsi Set Warna Console
void warna(int kode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kode);
}

// Efek animasi teks

void anim(string text, int delay=30) {
    for (auto c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

// Efek suara "ting ting"
void ting() {
    Beep(900, 80);
    Beep(1200, 80);
}

// =========================
// Struktur Data Layanan Kampus
// =========================
struct DataNode {
    string tanggal;
    string nama;
    string layanan;
    DataNode* prev;
    DataNode* next;
};

// =========================
// Kelas Linear Double Linked List
// =========================
class DoubleLinkedList {
private:
    DataNode* head;
    DataNode* tail;
    int count;
    const int MAX_DATA = 5;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    bool isFull() {
        return count >= MAX_DATA;
    }

    void insertRight(string t, string n, string l) {
        if (isFull()) {
            warna(12); ting();
            anim("Max 5 data. Hapus dulu data agar bisa tambah.\n");
            warna(7);
            return;
        }
        DataNode* baru = new DataNode{t, n, l, nullptr, nullptr};

        if (isEmpty()) {
            head = tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
        count++;
        warna(10);
        anim("\n>> Insert data di Kanan (Akhir) Berhasil!\n", 20);
        warna(7);
        ting();
        tampilAnimasi();
    }

    void insertLeft(string t, string n, string l) {
        if (isFull()) {
            warna(12); ting();
            anim("Max 5 data. Hapus dulu data agar bisa tambah.\n");
            warna(7);
            return;
        }
        DataNode* baru = new DataNode{t, n, l, nullptr, nullptr};

        if (isEmpty()) {
            head = tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
        count++;
        warna(10);
        anim("\n>> Insert data di Kiri (Awal) Berhasil!\n", 20);
        warna(7);
        ting();
        tampilAnimasi();
    }

    void deleteRight() {
        if (isEmpty()) {
            warna(12); ting();
            anim("Data kosong, tidak bisa delete kanan.\n");
            warna(7);
            return;
        }
        DataNode* hapus = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        count--;
        warna(9);
        anim("\n>> Menghapus data kanan (akhir):\n");
        warna(14);
        cout << "Tanggal  : " << hapus->tanggal << endl;
        cout << "Nama     : " << hapus->nama << endl;
        cout << "Layanan  : " << hapus->layanan << endl;
        warna(7);
        delete hapus;
        ting();
        anim("\n>> Data berhasil dihapus!\n");
        tampilAnimasi();
    }

    void deleteLeft() {
        if (isEmpty()) {
            warna(12); ting();
            anim("Data kosong, tidak bisa delete kiri.\n");
            warna(7);
            return;
        }
        DataNode* hapus = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        count--;
        warna(9);
        anim("\n>> Menghapus data kiri (awal):\n");
        warna(14);
        cout << "Tanggal  : " << hapus->tanggal << endl;
        cout << "Nama     : " << hapus->nama << endl;
        cout << "Layanan  : " << hapus->layanan << endl;
        warna(7);
        delete hapus;
        ting();
        anim("\n>> Data berhasil dihapus!\n");
        tampilAnimasi();
    }

    void tampilAnimasi() {
        system("cls");
        warna(11);
        anim("====== TAMPILAN DATA Layanan Administrasi Kampus ======\n\n", 15);
        warna(7);

        if (isEmpty()) {
            warna(12);
            anim("Data masih kosong.\n");
            warna(7);
            return;
        }

        // Menampilkan node satu per satu dengan animasi
        DataNode* now = head;
        int index = 1;
        while (now != nullptr) {
            warna(13);
            anim("-----------------------------\n", 5);
            warna(10);
            cout << "Data ke-" << index++ << ":" << endl;
            warna(14);
            cout << "Tanggal    : "; warna(15); cout << now->tanggal << endl;
            warna(14);
            cout << "Nama       : "; warna(15); cout << now->nama << endl;
            warna(14);
            cout << "Jenis Layanan: "; warna(15); cout << now->layanan << endl;
            warna(13);
            anim("-----------------------------\n\n", 5);
            warna(7);

            now = now->next;
            this_thread::sleep_for(chrono::milliseconds(700));
        }
    }
};

int main() {
    DoubleLinkedList list;
    int pilih;

    do {
        warna(10);
        cout << "==========================================\n";
        cout << " PROGRAM Linear Double Linked List Layanan\n";
        cout << "==========================================\n";
        warna(7);

        warna(14);
        cout << "1. Insert Data\n";
        cout << "2. Delete Data\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Exit\n";
        warna(7);

        cout << "Pilih menu : ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            int subMenu;
            warna(11);
            cout << "\n-- Insert Data --\n";
            warna(7);
            cout << "1. Insert Kiri (Awal)\n";
            cout << "2. Insert Kanan (Akhir)\n";
            cout << "Pilih Insert : ";
            cin >> subMenu;
            cin.ignore();

            if (subMenu != 1 && subMenu != 2) {
                warna(12);
                anim("Pilihan Insert tidak valid!\n");
                warna(7);
                continue;
            }

            string tgl, namaMhs, layanan;
            cout << "Tanggal         : ";
            getline(cin, tgl);
            cout << "Nama Mahasiswa  : ";
            getline(cin, namaMhs);
            cout << "Jenis Layanan   : ";
            getline(cin, layanan);

            if (subMenu == 1) list.insertLeft(tgl, namaMhs, layanan);
            else list.insertRight(tgl, namaMhs, layanan);

        } else if (pilih == 2) {
            int subMenu;
            warna(11);
            cout << "\n-- Delete Data --\n";
            warna(7);
            cout << "1. Delete Kiri (Awal)\n";
            cout << "2. Delete Kanan (Akhir)\n";
            cout << "Pilih Delete : ";
            cin >> subMenu;
            cin.ignore();

            if (subMenu != 1 && subMenu != 2) {
                warna(12);
                anim("Pilihan Delete tidak valid!\n");
                warna(7);
                continue;
            }

            if (subMenu == 1) list.deleteLeft();
            else list.deleteRight();

        } else if (pilih == 3) {
            list.tampilAnimasi();

        } else if (pilih == 4) {
            warna(10);
            ting();
            anim("\nTerima kasih sudah menggunakan program ini.\n");
            warna(7);
            break;

        } else {
            warna(12);
            anim("Pilihan menu tidak valid!\n");
            warna(7);
        }

        cout << "\nTekan ENTER untuk melanjutkan...";
        cin.get();
        system("cls");

    } while (true);

    return 0;
}
