#include <iostream> 
#include <string>
#include <sstream>      
#include <limits>
using namespace std;

#define MAX 10              

struct Deque {               
    string data[MAX];      
    int front;               
    int rear;                
};

// --- Inisialisasi Deque ---
// Fungsi ini mengatur deque ke kondisi awal (kosong)
void init(Deque &Q) {
    Q.front = -1;            // Set front ke -1 untuk menandakan antrian kosong
    Q.rear = -1;             // Set rear ke -1 untuk menandakan antrian kosong
}

bool isEmpty(Deque Q) {      // Fungsi untuk memeriksa apakah antrian kosong
    return (Q.front == -1 && Q.rear == -1);  // Kembalikan true jika front dan rear adalah -1
}

bool isFull(Deque Q) {       // Fungsi untuk memeriksa apakah antrian penuh
    return ((Q.front == 0 && Q.rear == MAX - 1) || (Q.front == Q.rear + 1));
                                 // Kondisi: Antrian penuh jika mencapai akhir array atau wrap-around
}

// Insert dari kanan
// Fungsi untuk menambahkan elemen baru ke sisi kanan (rear) jika antrian tidak penuh
void insertRight(Deque &Q, const string &nama) {
    if (isFull(Q)) {         // Periksa jika antrian penuh
        cout << "--Antrian penuh! Tidak bisa tambah dari kanan.--\n";
        return;              
    }

    if (isEmpty(Q)) {        // Jika antrian kosong
        Q.front = Q.rear = 0;  // Set front dan rear ke 0
    } else if (Q.rear == MAX - 1) {  // Jika rear berada di akhir array
        Q.rear = 0;          // Pindahkan rear ke awal array
    } else {
        Q.rear++;            // penambahan rear secara normal
    }

    Q.data[Q.rear] = nama;   // Simpan nama ke posisi rear
    cout << "=> " << nama << " masuk antrian dari kanan.\n";  
}

// Insert dari kiri
// Fungsi untuk menambahkan elemen baru ke sisi kiri (front) jika antrian tidak penuh
void insertLeft(Deque &Q, const string &nama) {
    if (isFull(Q)) {         // Periksa jika antrian penuh
        cout << "--Antrian penuh! Tidak bisa tambah dari kiri.--\n";
        return;              // Keluar fungsi jika penuh
    }

    if (isEmpty(Q)) {        // Jika antrian kosong
        Q.front = Q.rear = 0;  // Set front dan rear ke 0
    } else if (Q.front == 0) {  // Jika front berada di awal array
        Q.front = MAX - 1;   // Pindahkan front ke akhir array
    } else {
        Q.front--;           // pengurangan front secara normal
    }

    Q.data[Q.front] = nama;  // Simpan nama ke posisi front
    cout << "=> " << nama << " masuk antrian dari kiri.\n";  
}

// Delete dari kanan
// Fungsi untuk menghapus elemen dari sisi kanan (rear) jika antrian tidak kosong
void deleteRight(Deque &Q) {
    if (isEmpty(Q)) {        // Periksa jika antrian kosong
        cout << "--Antrian kosong! Tidak ada yang dihapus dari kanan.--\n";
        return;              
    }

    cout << "-- " << Q.data[Q.rear] << " keluar dari antrian (kanan).--\n";  // Tampilkan elemen yang dihapus

    if (Q.front == Q.rear) { // Jika hanya satu elemen
        Q.front = Q.rear = -1;  // Set antrian ke kosong
    } else if (Q.rear == 0) {  // Jika rear berada di awal array
        Q.rear = MAX - 1;    // Pindahkan rear ke akhir array
    } else {
        Q.rear--;            // pengurangan rear secara normal
    }
}

// Delete dari kiri
// Fungsi untuk menghapus elemen dari sisi kiri (front) jika antrian tidak kosong
void deleteLeft(Deque &Q) {
    if (isEmpty(Q)) {        // Periksa jika antrian kosong
        cout << "--Antrian kosong! Tidak ada yang dihapus dari kiri.--\n";
        return;             
    }

    cout << "-- " << Q.data[Q.front] << " keluar dari antrian (kiri).--\n";  // Tampilkan elemen yang dihapus

    if (Q.front == Q.rear) { // Jika hanya satu elemen
        Q.front = Q.rear = -1;  // Set antrian ke kosong
    } else if (Q.front == MAX - 1) {  // Jika front berada di akhir array
        Q.front = 0;         // Pindahkan front ke awal array
    } else {
        Q.front++;           // penambahan front secara normal
    }
}

// Tampilkan isi antrian
// Fungsi untuk menampilkan semua elemen dalam antrian dari front ke rear
void tampil(Deque Q) {
    if (isEmpty(Q)) {        // Periksa jika antrian kosong
        cout << "Antrian kosong.\n";
        return;              // Keluar fungsi jika kosong
    }

    cout << "\nDaftar Antrian Galon:\n";  // Judul untuk daftar antrian
    int i = Q.front;             // Mulai dari indeks front
    while (true) {
        cout << "- " << Q.data[i] << endl;  // Cetak elemen saat ini
        if (i == Q.rear) break;  // Hentikan loop jika mencapai rear
        i = (i + 1) % MAX;       // penambahan nilai i 
    }
    cout << endl;                
}

int main() {
    Deque antrian;               // Deklarasikan variabel deque
    init(antrian);               // Inisialisasi deque

    int pilih;                   // Variabel untuk pilihan menu
    string nama;                 // Variabel untuk nama pelanggan

    do {
        cout << "=============================\n";
        cout << "   ANTRIAN ISI ULANG GALON\n";
        cout << "=============================\n";
        cout << "1. Tambah antrian dari kanan\n";
        cout << "2. Tambah antrian dari kiri\n";
        cout << "3. Hapus antrian dari kanan\n";
        cout << "4. Hapus antrian dari kiri\n";
        cout << "5. Tampilkan semua antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        
        if (!(cin >> pilih)) {   // Validasi input: Pastikan input adalah angka
            cin.clear();         // Bersihkan error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Abaikan input yang salah
            cout << "Input tidak valid.\n\n";  // Tampilkan pesan error
            continue;            // Lanjut ke berikutnya
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  

        cout << endl;

        switch (pilih) {         
            case 1:  //kanan
                cout << "Masukkan nama pelanggan: ";
                getline(cin, nama);  
                insertRight(antrian, nama);  // Panggil fungsi insertRight
                break;

            case 2:  //kiri
                cout << "Masukkan nama pelanggan: ";
                getline(cin, nama);  // Baca nama lengkap
                insertLeft(antrian, nama);   // Panggil fungsi insertLeft
                break;

            case 3:
                deleteRight(antrian);  // Panggil fungsi deleteRight
                break;

            case 4:
                deleteLeft(antrian);   // Panggil fungsi deleteLeft
                break;

            case 5:
                tampil(antrian);       // Panggil fungsi tampil
                break;
                
            case 0:
                cout << "Program selesai.\n";  // Pesan keluar
                break;

            default:
                cout << "Pilihan tidak valid.\n";  // Pesan untuk pilihan salah
        }
        cout << endl;            // Baris baru untuk pemisah
    } while (pilih != 0);    // Loop berlanjut hingga pilih == 0

    return 0;                // Akhiri program
}
