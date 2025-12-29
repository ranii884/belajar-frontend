#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;

// =========================
//  Fungsi Warna
// =========================
void warna(int kode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kode);
}

// =========================
//  Efek Animasi Teks
// =========================
void anim(string text, int delay = 35) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

// =========================
//  Efek Suara "ting ting"
// =========================
void ting() {
    Beep(900, 80);
    Beep(1200, 80);
}

// Struktur data mahasiswa (ada ID tambahan)
struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    int nilai;
    int id;    // nomor urut input
};

// Node LL
struct Node {
    Mahasiswa mhs;
    Node* next;
};

Node* topStack = NULL;

// Counter ID global
int counterID = 1;

// =========================
// PUSH
// =========================
void push() {
    system("cls");

    warna(11); // Cyan
    cout << "\n=========== INPUT DATA MAHASISWA ===========\n";
    warna(7);

    Node* baru = new Node;

    cout << "Nama\t\t: ";
    getline(cin >> ws, baru->mhs.nama);
    cout << "NIM\t\t: ";
    getline(cin, baru->mhs.nim);
    cout << "Gender (L/P)\t: ";
    getline(cin, baru->mhs.gender);
    cout << "Nilai Struktur Data : ";
    cin >> baru->mhs.nilai;

    // Set ID berdasarkan urutan input
    baru->mhs.id = counterID++;

    baru->next = topStack;
    topStack = baru;

    warna(14);
    anim("\n---> Menambahkan ke stack...");
    warna(7);
    this_thread::sleep_for(chrono::milliseconds(400));

    ting();
    warna(10);
    anim("? Data berhasil ditambahkan!\n", 40);
    warna(7);
}

// =========================
// POP
// =========================
void pop() {
    system("cls");

    warna(12);
    cout << "\n============== DELETE DATA MAHASISWA ==============\n";
    warna(7);

    if (topStack == NULL) {
        warna(12);
        ting();
        anim("Stack masih kosong!\n");
        warna(7);
        return;
    }

    Node* hapus = topStack;
    topStack = topStack->next;

    anim("Menghapus data teratas...");
    this_thread::sleep_for(chrono::milliseconds(400));

    cout << "\nData yang dihapus:\n";
    warna(14);
    cout << "Data Ke- : " << hapus->mhs.id << endl;
    cout << "Nama     : " << hapus->mhs.nama << endl;
    cout << "NIM      : " << hapus->mhs.nim << endl;
    cout << "Gender   : " << hapus->mhs.gender << endl;
    cout << "Nilai    : " << hapus->mhs.nilai << endl;
    warna(7);

    delete hapus;

    ting();
    warna(10);
    anim("\n? Data berhasil dihapus!\n");
    warna(7);
}

// =========================
// CETAK
// =========================
void cetak() {
    system("cls");

    warna(9);
    cout << "\n============= CETAK SEMUA DATA =============\n";
    warna(7);

    if (topStack == NULL) {
        warna(12);
        ting();
        anim("Stack kosong!\n");
        warna(7);
        return;
    }

    Node* bantu = topStack;

    while (bantu != NULL) {
        warna(13);
        cout << "\n-----------------------------\n";
        warna(7);

        warna(11);
        cout << "Data Ke-" << bantu->mhs.id << endl;
        warna(7);

        cout << "Nama   : " << bantu->mhs.nama << endl;
        cout << "NIM    : " << bantu->mhs.nim << endl;
        cout << "Gender : " << bantu->mhs.gender << endl;
        cout << "Nilai  : " << bantu->mhs.nilai << endl;

        bantu = bantu->next;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    warna(13);
    cout << "-----------------------------\n";
    warna(7);
}

// =========================
// MAIN MENU
// =========================
int main() {
    int pilih;

    do {
        warna(10);
        cout << "\n===========================================\n";
        cout << "         PROGRAM STACK MAHASISWA\n";
        cout << "               (LINKED LIST)\n";
        cout << "===========================================\n";
        warna(7);

        warna(14);
        cout << "1. Insert Data\n";
        cout << "2. Delete Data\n";
        cout << "3. Cetak Data\n";
        cout << "4. Exit Program\n";
        warna(7);

        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih) {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: cetak(); break;
        case 4:
            warna(11);
            ting();
            anim("\n*** Program selesai. Terima kasih! ***\n", 40);
            warna(7);
            break;
        default:
            warna(12);
            anim("Menu tidak valid!");
            warna(7);
        }

        cout << "\nTekan ENTER untuk melanjutkan...";
        cin.ignore();
        cin.get();
        system("cls");

    } while (pilih != 4);

    return 0;
}
