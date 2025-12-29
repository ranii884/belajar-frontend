#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

struct Buku {
    int nilai;          
};

class StackBuku {
private:
    Buku rak[MAX];  
    
    int top;        
public:

    StackBuku() {
		 top = -1;   // -1 menandakan stack kosong
    }
    // untuk mengecek apakah stack penuh
    bool isFull() {
        return top == MAX - 1;
    }
    // untuk mengecek apakah stack kosong
    bool isEmpty() {
        return top == -1;
    }
    // untuk menambahkan buku baru ke rak (push)
    void PUSH() {
        if (isFull()) {
            cout << "data sudah penuh, tidak bisa menambah nilai lagi.\n";
            return;
        }
        Buku baru;
        cout << "Masukkan nilai tugas: ";
        cin >> baru.nilai;
              cin.ignore(); 
       
    }

    void POP() {
        if (isEmpty()) {
            cout << "Data kosong, tidak ada Nilai yang bisa dilihat.\n";
            return;
        }
        Buku diambil = rak[top]; // ambil buku paling atas
        top--;                   // turunkan indeks top (hapus buku dari stack)
        cout << "Nilai yang di lihatl:\n";
        cout << "nilai: " << diambil.nilai << "\n";
    }
     // untuk melihat buku paling atas tanpa menghapusnya
    void PEEK() {
        if (isEmpty()) {
            cout << "data kosong, tidak ada nilai di atas.\n";
            return;
        }
        cout << "Nilai paling atas di data:\n";
        cout << "Nilai Tugas: " << rak[top].nilai << "\n";
 
    }
    // untuk menampilkan seluruh isi rak dari bawah ke atas
    void DISPLAY() {
        if (isEmpty()) {
            cout << "data kosong, tidak ada nilai untuk ditampilkan.\n";
            return;
        }
        cout << "Isi data nilai dari bawah ke atas:\n";
        for (int i = 0; i <= top; i++) {
            cout << i+1 << ". Nilai: " << rak[i].nilai << "\n";
        }
    }
};
int main() {
    StackBuku nilai;
    int pilihan;
    do {
        // menu interaktif untuk pengguna
        cout << "\n=== Nilai Tugas Struktur data ===\n";
        cout << "1. Masukan Nilai(PUSH)\n";
        cout << "2. Lihat Nilai (POP)\n";
        cout << "3. Lihat Nilai Teratas (PEEK)\n";
        cout << "4. Tampilkan Semua Nilai (DISPLAY)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                nilai.PUSH();   // tambah buku baru
                break;
            case 2:
                nilai.POP();    // ambil buku teratas
                break;
                case 3:
                nilai.PEEK();   // lihat buku teratas
                break;
            case 4:
                nilai.DISPLAY();// tampilkan semua buku
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
