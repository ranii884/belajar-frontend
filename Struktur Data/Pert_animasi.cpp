#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <windows.h>

using namespace std;

// =========================
//  WARNA CONSOLE
// =========================
void warna(int kode)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kode);
}

// =========================
//  ANIMASI TULISAN
// =========================
void anim(const string &text, int w = 40)
{
    for (char c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(w));
    }
    cout << endl;
}

// =========================
//  SUARA BEEP
// =========================
void soundInsert() { Beep(800, 150); }
void soundDelete() { Beep(500, 150); }
void soundShow() { Beep(700, 100); }

// =========================
//  STRUKTUR DATA
// =========================
struct Mahasiswa
{
    string nama;
    string nim;
    string gender;
    float nilai;
};

struct Node
{
    Mahasiswa mhs;
    Node *next;
};

Node *topStack = NULL;

// =========================
// PUSH (INSERT)
// =========================
void push()
{
    system("cls");

    warna(11);
    cout << "\n=== INSERT MAHASISWA ===\n";
    warna(7);

    Node *baru = new Node;

    cout << "Nama\t\t: ";
    getline(cin >> ws, baru->mhs.nama);

    cout << "NIM\t\t: ";
    getline(cin, baru->mhs.nim);

    cout << "Gender (L/P)\t: ";
    getline(cin, baru->mhs.gender);

    cout << "Nilai Struktur Data : ";
    cin >> baru->mhs.nilai;

    baru->next = topStack;
    topStack = baru;

    warna(10);
    anim("\n[+] Menambahkan ke Stack...");
    warna(7);

    soundInsert();
    anim("✅ Data berhasil ditambahkan!\n");
}

// =========================
// POP (DELETE)
// =========================
void pop()
{
    system("cls");

    warna(12);
    cout << "\n=== DELETE (POP) ===\n";
    warna(7);

    if (topStack == NULL)
    {
        warna(14);
        anim("⚠️  Stack masih kosong!\n");
        warna(7);
        return;
    }

    Node *hapus = topStack;
    topStack = topStack->next;

    warna(12);
    anim("[-] Menghapus data teratas...");
    warna(7);

    soundDelete();

    cout << "\nData yang dihapus:\n";
    cout << "Nama   : " << hapus->mhs.nama << endl;
    cout << "NIM    : " << hapus->mhs.nim << endl;
    cout << "Gender : " << hapus->mhs.gender << endl;
    cout << "Nilai  : " << hapus->mhs.nilai << endl;

    delete hapus;

    warna(10);
    anim("\n✅ Data berhasil dihapus!\n");
    warna(7);
}

// =========================
// CETAK LIFO (URUT MASUK)
// =========================
void cetakFIFO()
{
    system("cls");

    warna(10);
    cout << "\n=== CETAK FIFO (URUTAN MASUK) ===\n";
    warna(7);

    if (topStack == NULL)
    {
        warna(14);
        anim("⚠️  Stack kosong!\n");
        warna(7);
        return;
    }

    vector<Node *> nodes;
    Node *bantu = topStack;

    // simpan data dari top ke vector
    while (bantu != NULL)
    {
        nodes.push_back(bantu);
        bantu = bantu->next;
    }

    // tampilkan dari paling bawah (data pertama)
    int nomor = 1;

    soundShow();

    for (int i = nodes.size() - 1; i >= 0; i--)
    {
        warna(3);
        cout << "\n-------------------------------\n";
        warna(7);

        cout << "Data Ke-" << nomor++ << endl;
        cout << "Nama   : " << nodes[i]->mhs.nama << endl;
        cout << "NIM    : " << nodes[i]->mhs.nim << endl;
        cout << "Gender : " << nodes[i]->mhs.gender << endl;
        cout << "Nilai  : " << nodes[i]->mhs.nilai << endl;

        this_thread::sleep_for(chrono::milliseconds(200));
        soundShow();
    }

    warna(3);
    cout << "-------------------------------\n";
    warna(7);
}

// =========================
// MAIN PROGRAM
// =========================
int main()
{
    int pilih;

    do
    {
        warna(13);
        cout << "\n====================================\n";
        cout << " PROGRAM STACK MAHASISWA (LINKED LIST)\n";
        cout << "====================================\n";
        warna(7);

        cout << "1. Insert (Push)\n";
        cout << "2. Delete (Pop)\n";
        cout << "3. Cetak (LIFO / Urutan Masuk)\n";
        cout << "4. Exit\n";
        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            cetakFIFO();
            break;

        case 4:
            warna(10);
            anim("\n👋 Program selesai, terima kasih!\n");
            warna(7);
            soundDelete();
            break;

        default:
            warna(12);
            anim("❌ Menu tidak valid!\n");
            warna(7);
        }

        cout << "\nTekan ENTER untuk melanjutkan...";
        cin.ignore();
        cin.get();

        system("cls");

    } while (pilih != 4);

    return 0;
}
