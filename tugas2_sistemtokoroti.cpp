#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Pesanan {
    string nama;
    string jenisRoti;
    int totalHarga;
};

Pesanan antrean[MAX];
int belakang = -1;

Pesanan riwayat[MAX];
int top = -1;

bool queueKosong() {
    return belakang == -1;
}

bool queuePenuh() {
    return belakang == MAX - 1;
}

void enqueue(Pesanan p) {
    if (queuePenuh()) {
        cout << "Antrean penuh!\n";
    } else {
        belakang++;
        antrean[belakang] = p;
        cout << "Pesanan ditambahkan ke antrean.\n";
    }
}

void dequeue() {
    if (queueKosong()) {
        cout << "Antrean kosong!\n";
    } else {
        Pesanan dilayani = antrean[0];

        for (int i = 0; i < belakang; i++) {
            antrean[i] = antrean[i + 1];
        }
        belakang--;

        if (top < MAX - 1) {
            top++;
            riwayat[top] = dilayani;
        }

        cout << "Pesanan " << dilayani.nama << " telah dilayani.\n";
    }
}

void tampilkanAntrean() {
    if (queueKosong()) {
        cout << "Antrean kosong.\n";
    } else {
        cout << "Daftar antrean:\n";
        for (int i = 0; i <= belakang; i++) {
            cout << i + 1 << ". " << antrean[i].nama << " - " << antrean[i].jenisRoti
                 << " - Rp" << antrean[i].totalHarga << endl;
        }
    }
}

void batalkanPesanan() {
    if (queueKosong()) {
        cout << "Antrean kosong, tidak ada pesanan untuk dibatalkan.\n";
    } else {
        cout << "Pesanan " << antrean[belakang].nama << " dibatalkan.\n";
        belakang--;
    }
}

void tampilkanRiwayat() {
    if (top == -1) {
        cout << "Belum ada pesanan yang dilayani.\n";
    } else {
        cout << "Riwayat pesanan yang telah dilayani:\n";
        for (int i = top; i >= 0; i--) {
            cout << "- " << riwayat[i].nama << " - " << riwayat[i].jenisRoti
                 << " - Rp" << riwayat[i].totalHarga << endl;
        }
    }
}

int main() {
    int pilihan;
    Pesanan p;

    do {
        cout << "\n=== Sistem Antrean Toko Roti Manis Lezat ===\n";
        cout << "1. Ambil Antrean\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Pesanan\n";
        cout << "4. Batalkan Pesanan\n";
        cout << "5. Tampilkan History Pesanan\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Nama Pembeli: ";
                getline(cin, p.nama);
                cout << "Jenis Roti: ";
                getline(cin, p.jenisRoti);
                cout << "Total Harga: ";
                cin >> p.totalHarga;
                enqueue(p);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                tampilkanAntrean();
                break;
            case 4:
                batalkanPesanan();
                break;
            case 5:
                tampilkanRiwayat();
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
