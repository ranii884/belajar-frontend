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

// Struktur data nasabah
struct Nasabah {
    int kode;
    string nama;
    string gender;
    string alamat;
};

// Node Circular Linked List
struct Node {
    Nasabah nasabah;
    Node* next;
};

Node* head = NULL;
int jumlahNasabah = 0; // Counter untuk maksimal 3

// =========================
// Fungsi untuk cek apakah list kosong
// =========================
bool isEmpty() {
    return head == NULL;
}

// =========================
// Fungsi untuk cari posisi insert (sorted ascending berdasarkan kode)
// =========================
Node* findInsertPosition(int kode) {
    if (isEmpty()) return NULL;
    
    Node* current = head;
    do {
        if (current->nasabah.kode > kode) return current;
        current = current->next;
    } while (current != head);
    
    return head; // Jika kode terbesar, insert di akhir
}

// =========================
// INSERT (Sorted, FIFO style - insert di posisi sorted)
// =========================
void insert() {
    system("cls");

    if (jumlahNasabah >= 3) {
        warna(12);
        ting();
        anim("Maksimal 3 nasabah! Tidak dapat menambah data.\n");
        warna(7);
        return;
    }

    warna(11); // Cyan
    cout << "\n=========== INPUT DATA NASABAH ===========\n";
    warna(7);

    Node* baru = new Node;

    // Validasi input kode: hanya angka
    while (true) {
        cout << "No. Kode\t: ";
        cin >> baru->nasabah.kode;
        if (cin.fail()) {
            cin.clear(); // Clear error state
            cin.ignore(1000, '\n'); // Ignore invalid input
            warna(12);
            Beep(500, 200); // Suara error beep rendah dan panjang
            anim("Kode tidak bisa di input, masukkan angka!\n");
            warna(7);
        } else {
            Beep(600, 100); // Suara beep rendah saat input kode valid
            break; // Keluar loop jika valid
        }
    }

    // Cek apakah kode sudah ada
    if (!isEmpty()) {
        Node* check = head;
        do {
            if (check->nasabah.kode == baru->nasabah.kode) {
                warna(12);
                ting();
                anim("Kode sudah ada! Tidak dapat insert.\n");
                warna(7);
                delete baru;
                return;
            }
            check = check->next;
        } while (check != head);
    }

    cout << "Nama\t\t: ";
    cin.ignore();
    getline(cin, baru->nasabah.nama);
    Beep(700, 100); // Suara beep sedang saat input nama

    cout << "Gender (L/P)\t: ";
    getline(cin, baru->nasabah.gender);
    Beep(800, 100); // Suara beep lebih tinggi saat input gender

    cout << "Alamat\t\t: ";
    getline(cin, baru->nasabah.alamat);
    Beep(900, 100); // Suara beep tinggi saat input alamat

    baru->next = NULL;

    if (isEmpty()) {
        head = baru;
        baru->next = head; // Circular
    } else {
        Node* pos = findInsertPosition(baru->nasabah.kode);
        if (pos == head && baru->nasabah.kode < head->nasabah.kode) {
            // Insert di awal
            baru->next = head;
            Node* last = head;
            while (last->next != head) last = last->next;
            last->next = baru;
            head = baru;
        } else {
            // Insert di tengah atau akhir
            baru->next = pos;
            Node* prev = head;
            while (prev->next != pos) prev = prev->next;
            prev->next = baru;
        }
    }

    jumlahNasabah++;

    warna(14);
    anim("\n---> Menambahkan ke circular linked list...");
    warna(7);
    this_thread::sleep_for(chrono::milliseconds(400));

    ting(); // Suara "ting ting" saat berhasil insert
    warna(10);
    anim("? Data berhasil ditambahkan!\n", 40);
    warna(7);
}

// =========================
// DELETE (FIFO - delete dari head)
// =========================
void delet() {
    system("cls");

    warna(12);
    cout << "\n============== DELETE DATA NASABAH ==============\n";
    warna(7);

    if (isEmpty()) {
        warna(12);
        ting();
        anim("List masih kosong!\n");
        warna(7);
        return;
    }

    Node* hapus = head;
    if (head->next == head) {
        // Hanya satu node
        head = NULL;
    } else {
        Node* last = head;
        while (last->next != head) last = last->next;
        last->next = head->next;
        head = head->next;
    }

    anim("Menghapus data terdepan (FIFO)...");
    this_thread::sleep_for(chrono::milliseconds(400));

    cout << "\nData yang dihapus:\n";
    warna(14);
    cout << "No. Kode : " << hapus->nasabah.kode << endl;
    cout << "Nama     : " << hapus->nasabah.nama << endl;
    cout << "Gender   : " << hapus->nasabah.gender << endl;
    cout << "Alamat   : " << hapus->nasabah.alamat << endl;
    warna(7);

    delete hapus;
    jumlahNasabah--;

    ting();
    warna(10);
    anim("\n? Data berhasil dihapus!\n");
    warna(7);
}

// =========================
// CETAK DATA
// =========================
void cetak() {
    system("cls");

    warna(9);
    cout << "\n============= CETAK SEMUA DATA NASABAH =============\n";
    warna(7);

    if (isEmpty()) {
        warna(12);
        ting();
        anim("List kosong!\n");
        warna(7);
        return;
    }

    Node* bantu = head;
    int count = 1;
    do {
        warna(13);
        cout << "\n-----------------------------\n";
        warna(7);

        warna(11);
        cout << "Data Ke-" << count << endl;
        warna(7);

        cout << "No. Kode : " << bantu->nasabah.kode << endl;
        cout << "Nama     : " << bantu->nasabah.nama << endl;
        cout << "Gender   : " << bantu->nasabah.gender << endl;
        cout << "Alamat   : " << bantu->nasabah.alamat << endl;

        bantu = bantu->next;
        count++;
        this_thread::sleep_for(chrono::milliseconds(500)); // Delay untuk animasi
    } while (bantu != head);

    warna(13);
    cout << "-----------------------------\n";
    warna(7);

    // Animasi circular
    warna(14);
    anim("\nList ini bersifat circular (kembali ke awal).", 50);
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
        cout << "     PROGRAM CIRCULAR LINKED LIST NASABAH\n";
        cout << "              BANK CUANTIK (FIFO)\n";
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
        case 1: insert(); break;
        case 2: delet(); break;
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