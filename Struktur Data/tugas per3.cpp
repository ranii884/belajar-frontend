#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct Buku {
    int id;
    string judul;
};
//mengimplementasikan stack menggunakan array
class StackBuku {
private:
    Buku rak[MAX];
    int top;

public:
    StackBuku() {
        top = -1; // -1 menandakan stack kosong
    }
//untk mnegecek stack penuh
    bool isFull() {
        return top == MAX - 1;
    }
//untk mengecek stack kosong
    bool isEmpty() {
        return top == -1;
    }
//untk menambahkan buku baru ke rak
    void PUSH() {
        if (isFull()) {
            cout << "Rak sudah penuh, tidak bisa menambah buku lagi.\n";
            return;
        }
        Buku baru;
        cout << "Masukkan ID Buku: ";
        cin >> baru.id;
        cin.ignore();
        cout << "Masukkan Judul Buku: ";
        getline(cin, baru.judul);

        top++;
        rak[top] = baru;
        cout << "Buku berhasil ditambahkan ke rak.\n";
    }

    void POP() {
        if (isEmpty()) {
            cout << "Rak kosong, tidak ada buku yang bisa diambil.\n";
            return;
        }
        Buku diambil = rak[top];
        top--;
        cout << "Buku yang diambil:\n";
        cout << "ID Buku: " << diambil.id << "\n";
        cout << "Judul Buku: " << diambil.judul << "\n";
    }

    void PEEK() {
        if (isEmpty()) {
            cout << "Rak kosong, tidak ada buku di atas.\n";
            return;
        }
        cout << "Buku paling atas di rak:\n";
        cout << "ID Buku: " << rak[top].id << "\n";
        cout << "Judul Buku: " << rak[top].judul << "\n";
    }

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
    StackBuku perpustakaan;
    int pilihan;

    do {
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
                perpustakaan.PUSH();
                break;
            case 2:
                perpustakaan.POP();
                break;
            case 3:
                perpustakaan.PEEK();
                break;
            case 4:
                perpustakaan.DISPLAY();
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
