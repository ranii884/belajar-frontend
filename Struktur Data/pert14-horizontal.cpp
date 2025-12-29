#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;

// Fungsi mengatur warna teks console
void warna(int kode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kode);
}

// Efek animasi teks ketik perlahan
void anim(string text, int delay=20) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

// Fungsi beep "ting-ting"
void ting() {
    Beep(900, 80);
    Beep(1200, 80);
}

// Struktur data node
struct DataNode {
    string tanggal;
    string nama;
    string layanan;
    DataNode* prev;
    DataNode* next;
};

// Double Linked List linear
class DoubleLinkedList {
private:
    DataNode* head;
    DataNode* tail;
    int count;
    static const int MAX_DATA = 5;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    bool isEmpty() { return head == nullptr; }
    bool isFull() { return count >= MAX_DATA; }

    void insertLeft(const string& tgl, const string& nama, const string& lay) {
        if (isFull()) {
            warna(12);
            ting();
            anim("Data maksimal 5. Hapus dulu agar bisa tambah.\n");
            warna(7);
            return;
        }
        DataNode* baru = new DataNode{tgl, nama, lay, nullptr, nullptr};
        if (isEmpty()) {
            head = tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
        count++;
        warna(10);
        anim(">> Insert data di Kiri (Awal) BERHASIL!\n");
        warna(7);
        ting();
    }

    void insertRight(const string& tgl, const string& nama, const string& lay) {
        if (isFull()) {
            warna(12);
            ting();
            anim("Data maksimal 5. Hapus dulu agar bisa tambah.\n");
            warna(7);
            return;
        }
        DataNode* baru = new DataNode{tgl, nama, lay, nullptr, nullptr};
        if (isEmpty()) {
            head = tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
        count++;
        warna(10);
        anim(">> Insert data di Kanan (Akhir) BERHASIL!\n");
        warna(7);
        ting();
    }

    void deleteLeft() {
        if (isEmpty()) {
            warna(12);
            ting();
            anim("Data kosong. Tidak bisa hapus kiri.\n");
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
        anim(">> Menghapus data Kiri (Awal):\n");
        warna(14);
        cout << "Tanggal: " << hapus->tanggal << endl;
        cout << "Nama   : " << hapus->nama << endl;
        cout << "Layanan: " << hapus->layanan << endl;
        warna(7);
        delete hapus;
        ting();
        anim(">> Data berhasil dihapus!\n");
    }

    void deleteRight() {
        if (isEmpty()) {
            warna(12);
            ting();
            anim("Data kosong. Tidak bisa hapus kanan.\n");
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
        anim(">> Menghapus data Kanan (Akhir):\n");
        warna(14);
        cout << "Tanggal: " << hapus->tanggal << endl;
        cout << "Nama   : " << hapus->nama << endl;
        cout << "Layanan: " << hapus->layanan << endl;
        warna(7);
        delete hapus;
        ting();
        anim(">> Data berhasil dihapus!\n");
    }

    // Fungsi untuk print data horizontal rapi
    void tampilDataHorizontal() {
        system("cls");
        warna(11);
        anim("===== DATA LAYANAN ADMINISTRASI KAMPUS (MAX 5) =====\n\n", 15);
        warna(7);

        if (isEmpty()) {
            warna(12);
            anim("Data masih kosong.\n");
            warna(7);
            return;
        }

        // Kumpulkan node
        DataNode* now = head;
        int idx = 0;
        DataNode* nodes[MAX_DATA];
        while (now != nullptr) {
            nodes[idx++] = now;
            now = now->next;
        }

        // Lebar kotak
        const int boxWidth = 31; // panjang kotak agar muat teks

        // Fungsi buat garis horizontal kotak
        auto drawLine = [](int n) {
            for (int i = 0; i < n; i++) cout << "-";
        };

        // Baris atas kotak
        for (int i = 0; i < idx; i++) {
            cout << "+";
            drawLine(boxWidth);
            cout << "+";
            if (i != idx - 1) cout << "     "; // spasi antar node
        }
        cout << endl;

        // Baris isi tanggal
        for (int i = 0; i < idx; i++) {
            string tglDisplay = "Tanggal: " + nodes[i]->tanggal;
            cout << "| " << tglDisplay;
            int pad = boxWidth - (int)tglDisplay.length() - 1; // -1 untuk spasi setelah :
            for (int j = 0; j < pad; j++) cout << " ";
            cout << "|";
            if (i != idx - 1) cout << "  <-->  ";
        }
        cout << endl;

        // Baris isi nama
        for (int i = 0; i < idx; i++) {
            string namaDisplay = "Nama   : " + nodes[i]->nama;
            cout << "| " << namaDisplay;
            int pad = boxWidth - (int)namaDisplay.length() - 1;
            for (int j = 0; j < pad; j++) cout << " ";
            cout << "|";
            if (i != idx - 1) cout << "        ";
        }
        cout << endl;

        // Baris isi layanan
        for (int i = 0; i < idx; i++) {
            string layDisplay = "Layanan: " + nodes[i]->layanan;
            cout << "| " << layDisplay;
            int pad = boxWidth - (int)layDisplay.length() - 1;
            for (int j = 0; j < pad; j++) cout << " ";
            cout << "|";
            if (i != idx - 1) cout << "        ";
        }
        cout << endl;

        // Baris bawah kotak
        for (int i = 0; i < idx; i++) {
            cout << "+";
            drawLine(boxWidth);
            cout << "+";
            if (i != idx - 1) cout << "     ";
        }
        cout << "\n\n";
    }
};

int main() {
    DoubleLinkedList list;
    int pilih;

    do {
        warna(10);
        cout << "=======================================\n";
        cout << " PROGRAM LINEAR DOUBLE LINKED LIST\n";
        cout << " MANAJEMEN LAYANAN ADMINISTRASI KAMPUS\n";
        cout << "=======================================\n";
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
            cout << "Pilih Insert: ";
            cin >> subMenu;
            cin.ignore();

            if (subMenu != 1 && subMenu != 2) {
                warna(12);
                anim("Pilihan insert tidak valid!\n");
                warna(7);
                continue;
            }

            string tgl, namaMhs, layanan;
            cout << "Input Tanggal (dd-mm-yyyy): ";
            getline(cin, tgl);
            cout << "Input Nama Mahasiswa       : ";
            getline(cin, namaMhs);
            cout << "Input Jenis Layanan        : ";
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
            cout << "Pilih Delete: ";
            cin >> subMenu;
            cin.ignore();

            if (subMenu != 1 && subMenu != 2) {
                warna(12);
                anim("Pilihan delete tidak valid!\n");
                warna(7);
                continue;
            }

            if (subMenu == 1) list.deleteLeft();
            else list.deleteRight();

        } else if (pilih == 3) {
            list.tampilDataHorizontal();

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
