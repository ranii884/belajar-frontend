// Listing Program untuk Implementasi Circular Queue
//Nama : Ranii
//Nim :
#include <iostream>
using namespace std;
#define MAX 6

// Deklarasi Circular Queue
class CirQueue
{
private:
    int front;
    int rear;
    int count;
    int ele[MAX];

public:
    CirQueue();
    int isFull();
    int isEmpty();
    void insertQueue(int item);
    int deleteQueue(int *item);
    void displayQueue(); // ?? fungsi untuk menampilkan isi queue
};


// Inisialisasi Circular Queue
CirQueue::CirQueue()
{
    front = 0;
    rear = -1;
    count = 0;
}

// Untuk mengecek queue sudah penuh atau belum
int CirQueue::isFull()
{
    int full = 0;
    if (count == MAX)
        full = 1;
    return full;
}

// Untuk memeriksa antrian kosong atau tidak
int CirQueue::isEmpty()
{
    int empty = 0;
    if (count == 0)
        empty = 1;
    return empty;
}

// Sisipkan item ke dalam antrian melingkar
void CirQueue::insertQueue(int item)
{
    if (isFull())
    {
        cout << "\nQueue Overflow";
        return;
    }
    rear = (rear + 1) % MAX;
    ele[rear] = item;
    count++;
    cout << "\nDimasukkan item :" << item;
}

// Hapus item dari circular queue
int CirQueue::deleteQueue(int *item)
{
    if (isEmpty())
    {
        cout << "\nQueue Underflow";
        return -1;
    }
    *item = ele[front];
    front = (front + 1) % MAX;
    count--;
    return 0;
}
void CirQueue::displayQueue() {
    if (isEmpty()) {
        cout << "\n?? Queue kosong.\n";
        return;
    }

    cout << "\n?? Isi Queue saat ini: ";
    int i = front;
    for (int c = 0; c < count; c++) {
        cout << ele[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main()
{
    int item;
    CirQueue q = CirQueue();

    q.insertQueue(24);
    q.insertQueue(10);
    q.insertQueue(11);
    q.insertQueue(40);
    q.insertQueue(13);
	q.insertQueue(73);
    if (q.deleteQueue(&item) == 0)
    {
        cout << "\nItem dihapus :" << item << endl;
    }

    if (q.deleteQueue(&item) == 0)
    {
        cout << "\nItem dihapus :" << item << endl;
    }

    if (q.deleteQueue(&item) == 0)
    {
        cout << "\nItem dihapus :" << item << endl;
    }

    if (q.deleteQueue(&item) == 0)
    {
        cout << "\nItem dihapus :" << item << endl;
    }

    q.insertQueue(60);
    q.insertQueue(29);
    

    if (q.deleteQueue(&item) == 0)
    {
        cout << "\nItem dihapus :" << item << endl;
    }
    if (q.deleteQueue(&item) == 0)
    {
    	cout << "\nItem dihapus :" << item << endl;
    }
    q.displayQueue();

    cout << "\n";
    return 0;
}
