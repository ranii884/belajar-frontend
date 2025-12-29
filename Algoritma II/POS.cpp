#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item {
    string name;
    double price;
    int quantity;
};

int main() {
    vector<Item> cart;
    string itemName;
    double itemPrice;
    int itemQty;
    char moreItems;

    cout << "=== Program Kasir Sederhana ===" << endl;

    do {
        cout << "Masukkan nama barang: ";
        getline(cin, itemName);
        cout << "Masukkan harga barang: ";
        cin >> itemPrice;
        cout << "Masukkan jumlah barang: ";
        cin >> itemQty;
        cin.ignore(); // membersihkan newline dari input sebelumnya

        cart.push_back({itemName, itemPrice, itemQty});

        cout << "Tambah barang lagi? (y/n): ";
        cin >> moreItems;
        cin.ignore();
    } while (moreItems == 'y' || moreItems == 'Y');

    double total = 0;
    cout << "\n=== Struk Pembelian ===" << endl;
    for (size_t i = 0; i < cart.size(); ++i) {  // Perbaikan: gunakan loop for tradisional untuk kompatibilitas Dev C++ 5.11
        const Item& item = cart[i];
        double subtotal = item.price * item.quantity;
        cout << item.name << " x" << item.quantity << " = " << subtotal << endl;
        total += subtotal;
    }
    cout << "Total: " << total << endl;

    double bayar, kembalian;
    cout << "Masukkan jumlah bayar: ";
    cin >> bayar;
    kembalian = bayar - total;
    if (kembalian < 0) {
        cout << "Uang bayar kurang!" << endl;
    } else {
        cout << "Kembalian: " << kembalian << endl;
    }

    return 0;
}
