#include <iostream>
#include <string>
using namespace std;
// Kapasitas maksimal rak buku
const int MAX = 10;
// Struktur data untuk menyimpan informasi buku
struct Buku {
    int id;         // ID Buku (integer)
    string judul;   // Judul Buku (string sederhana)
};
// Kelas StackBuku mengimplementasikan stack menggunakan array
class StackBuku {
private:
    Buku rak[MAX];  // Array untuk menyimpan buku-buku
    int top;        // Indeks elemen paling atas di stack
public:
    // Konstruktor, inisialisasi stack kosong
    StackBuku() {
		 top = -1;   // -1 menandakan stack kosong
    }
    // Fungsi untuk mengecek apakah stack penuh
    bool isFull() {
        return top == MAX - 1;
    }
    // Fungsi untuk mengecek apakah stack kosong
    bool isEmpty() {
        return top == -1;
    }
    // Fungsi untuk menambahkan buku baru ke rak (push)
    void PUSH() {
        if (isFull()) {
            cout << "Rak sudah penuh, tidak bisa menambah buku lagi.\n";
            return;
        }
        Buku baru;
        cout << "Masukkan ID Buku: ";
        cin >> baru.id;
              cin.ignore(); // Membersihkan karakter newline dari buffer input
        cout << "Masukkan Judul Buku: ";
        getline(cin, baru.judul);
        top++;              // Naikkan indeks top
        rak[top] = baru;    // Simpan buku baru di posisi top
        cout << "Buku berhasil ditambahkan ke rak.\n";
    }
    // Fungsi untuk mengambil buku dari rak (pop)
    void POP() {
        if (isEmpty()) {
            cout << "Rak kosong, tidak ada buku yang bisa diambil.\n";
            return;
        }
        Buku diambil = rak[top]; // Ambil buku paling atas
        top--;                   // Turunkan indeks top (hapus buku dari stack)
        cout << "Buku yang diambil:\n";
        cout << "ID Buku: " << diambil.id << "\n";
        cout << "Judul Buku: " << diambil.judul << "\n";
    }
     // Fungsi untuk melihat buku paling atas tanpa menghapusnya (peek)
    void PEEK() {
        if (isEmpty()) {
            cout << "Rak kosong, tidak ada buku di atas.\n";
            return;
        }
        cout << "Buku paling atas di rak:\n";
        cout << "ID Buku: " << rak[top].id << "\n";
        cout << "Judul Buku: " << rak[top].judul << "\n";
    }
    // Fungsi untuk menampilkan seluruh isi rak dari bawah ke atas
    void DISPLAY() {
        if (isEmpty()) {
            cout << "Rak kosong, tidak ada buku untuk ditampilkan.\n";
            return;
        }
        cout << "Isi rak buku dari bawah ke atas:\n";
        for (int i = 0; i <= top; i++) {
            cout << i+1 << ". ID Buku: " << rak[i].id << ", Judul: " << rak[i].judul << "\n";
        }
    }
};
int main() {
    StackBuku perpustakaan;  // Membuat objek stack buku
    int pilihan;
    do {
        // Menu interaktif untuk pengguna
        cout << "\n=== Sistem Manajemen Tumpukan Buku Perpustakaan ===\n";
        cout << "1. Tambah Buku (PUSH)\n";
        cout << "2. Ambil Buku (POP)\n";
        cout << "3. Lihat Buku Teratas (PEEK)\n";
        cout << "4. Tampilkan Semua Buku (DISPLAY)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                perpustakaan.PUSH();   // Tambah buku baru
                break;
            case 2:
                perpustakaan.POP();    // Ambil buku teratas
                break;
                case 3:
                perpustakaan.PEEK();   // Lihat buku teratas
                break;
            case 4:
                perpustakaan.DISPLAY();// Tampilkan semua buku
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program.\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    } while (pilihan != 5);
    return 0;
}
