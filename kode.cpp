#include <iostream>
#include <string>


// jumlah data buku, stock, data anggota maksimal
const int MAX_BUKU = 50;
const int MAX_ANGGOTA = 50;
const int MAX_STOCK = 10;

// array 1D untuk data anggota (ID, nama, poin)
string idAnggota[MAX_ANGGOTA] = {"001", "002", "003"}; 
string namaAnggota[MAX_ANGGOTA] = {"Mulisa", "Atmim", "Sabrina"};
int poinAnggota[MAX_ANGGOTA] = {0, 0, 0}; 
int jumlahAnggota = 3;

// array 2d untuk data daftar buku (judul, stock, sedang dipinjam)
string daftarBuku[MAX_BUKU][3] = {
    {"Algoritma Pemrograman", "10", "0"},
    {"Struktur Data", "10", "0"},
    {"Basis Data", "10", "0"},
    {"Jaringan Komputer", "10", "0"},
    {"Pemograman Visual", "10", "0"}
};
int jumlahBuku = 5;

// Deklarasi Fungsi-fungsi
//void tampilkanMenu();
//void tampilkanDaftarBuku();
//void pinjamBuku();
//void kembalikanBuku();
//void urutkanAnggota();
//void tampilkanLeaderboard();
//int cariBuku(const string &judul);
//int cariAnggota(const string &id);
//string trim(const string &s);


// Fungsi main
int main() {
    while (true) {
        tampilkanMenu();
        cout << "Pilih menu (1-5): ";

        string line;
        if (!getline(cin, line)) break;
        
        if (trim(line).empty()) {
            cout << "Pilihan tidak valid! Masukkan angka antara 1 sampai 5.\n\n";
            continue;
        }

        int pilihan;
        try {
            size_t idx = 0;
            pilihan = stoi(line, &idx);
            if (idx != line.size()) throw invalid_argument("extra chars");
        } catch (...) {
            cout << "Pilihan tidak valid! Masukkan angka antara 1 sampai 5.\n\n";
            continue;
        }

        if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan sistem.\n"; // keluar dari program (menu ke 5)
            break;
        }

        switch (pilihan) {
            case 1:
                tampilkanDaftarBuku();
                break;
            case 2:
                pinjamBuku();
                break;
            case 3:
                kembalikanBuku();
                break;
            case 4:
                urutkanAnggota();
                tampilkanLeaderboard();
                break;
            default:
                cout << "Pilihan tidak valid! Masukkan angka antara 1 sampai 5.\n";
                break;
        }
        cout << endl;
    }

    return 0;
}

// Fungsi Tampilkan Menu

// Fungsi Tampilkan Daftar Buku

// Fungsi Peminjaman Buku

// Fungsi Pengembalian Buku

// Fungsi Lainnya