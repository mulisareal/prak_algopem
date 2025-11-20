#include <iostream>
#include <string>
#include <iomanip>
#include <limits> // Untuk numeric_limits

using namespace std;

// --- KONSTANTA DAN STRUKTUR DATA (Kriteria C: Array 2D) ---
const int MAX_BUKU = 5;
const int MAX_USER = 5;
const int MAX_STOK = 10; // Stok maksimal per buku
const int POIN_PINJAM = 10; // Poin didapat per peminjaman

// Kolom untuk array 2D dataBuku
const int KOLOM_STOK = 0;
const int KOLOM_DIPINJAM = 1;
const int KOLOM_POIN = 2; // Poin yang diberikan buku ini

// Deklarasi Global Parallel Arrays
string judulBuku[MAX_BUKU]; // Array 1D: Judul (Data Kelompok)
int dataBuku[MAX_BUKU][3];  // Array 2D: [Stok, Dipinjam, PoinPinjam]
string namaPengguna[MAX_USER]; // Array 1D: Nama Pengguna
int poinPengguna[MAX_USER];    // Array 1D: Poin Pengguna

// Counter untuk melacak jumlah data yang terisi
int jumlahBukuAktif = 0;
int jumlahUserAktif = 0;

// --- PROSEDUR DAN FUNGSI (Kriteria D: Modularitas) ---

/**
 * @brief Membersihkan buffer input stream. (Untuk validasi input)
 */
void bersihkanInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Inisialisasi data awal untuk buku dan pengguna.
 */
void inisialisasiData() {
    // Data Buku (Judul, Stok, Dipinjam, Poin)
    judulBuku[0] = "Struktur Data C++"; dataBuku[0][KOLOM_STOK] = 5; dataBuku[0][KOLOM_DIPINJAM] = 0; dataBuku[0][KOLOM_POIN] = 10;
    judulBuku[1] = "Algoritma Pemrograman"; dataBuku[1][KOLOM_STOK] = 2; dataBuku[1][KOLOM_DIPINJAM] = 0; dataBuku[1][KOLOM_POIN] = 15;
    judulBuku[2] = "Matematika Diskrit"; dataBuku[2][KOLOM_STOK] = 0; dataBuku[2][KOLOM_DIPINJAM] = 5; dataBuku[2][KOLOM_POIN] = 8;
    judulBuku[3] = "Basis Data MySQL"; dataBuku[3][KOLOM_STOK] = 8; dataBuku[3][KOLOM_DIPINJAM] = 0; dataBuku[3][KOLOM_POIN] = 12;
    jumlahBukuAktif = 4;

    // Data Pengguna (Nama, Poin)
    namaPengguna[0] = "Alice"; poinPengguna[0] = 50;
    namaPengguna[1] = "Bob"; poinPengguna[1] = 10;
    namaPengguna[2] = "Charlie"; poinPengguna[2] = 120;
    jumlahUserAktif = 3;

    cout << "Data inisialisasi berhasil dimuat.\n";
}

/**
 * @brief Mencari index buku berdasarkan judul.
 * @param judul Judul buku yang dicari (By Value)
 * @return int Index buku, atau -1 jika tidak ditemukan.
 * (Kriteria E: Algoritma Sequential Search)
 */
int sequentialSearchBuku(const string& judul) {
    for (int i = 0; i < jumlahBukuAktif; i++) {
        // Kriteria A: Percabangan untuk Aturan/Kebijakan
        if (judulBuku[i] == judul) {
            return i; // Ditemukan
        }
    }
    return -1; // Tidak Ditemukan
}

/**
 * @brief Mencari index pengguna berdasarkan nama.
 * @param nama Nama pengguna yang dicari (By Value)
 * @return int Index pengguna, atau -1 jika tidak ditemukan.
 */
int sequentialSearchUser(const string& nama) {
    for (int i = 0; i < jumlahUserAktif; i++) {
        if (namaPengguna[i] == nama) {
            return i; // Ditemukan
        }
    }
    return -1; // Tidak Ditemukan
}

/**
 * @brief Menampilkan daftar buku dan statusnya. (Fitur 1)
 */
void tampilkanDaftarBuku() {
    cout << "\n=======================================================\n";
    cout << "              DAFTAR BUKU PERPUSTAKAAN\n";
    cout << "=======================================================\n";
    cout << left << setw(5) << "No."
         << setw(30) << "Judul Buku"
         << setw(10) << "Stok"
         << setw(10) << "Poin\n";
    cout << "-------------------------------------------------------\n";

    for (int i = 0; i < jumlahBukuAktif; i++) { // Kriteria B: Perulangan for
        cout << left << setw(5) << i + 1
             << setw(30) << judulBuku[i]
             << setw(10) << dataBuku[i][KOLOM_STOK]
             << setw(10) << dataBuku[i][KOLOM_POIN] << "\n";
    }
    cout << "=======================================================\n";
}

/**
 * @brief Memproses peminjaman buku. (Fitur 2)
 * @param namaPeminjam Parameter by Value
 * @param idxBuku Index buku yang dipinjam (By Value)
 * @param poinPengguna Pointer ke array poin pengguna (By Reference)
 */
void peminjamanBuku(const string& namaPeminjam, int idxBuku, int& poinUser) {
    // Kriteria A: Aturan/Kebijakan (Percabangan)
    if (dataBuku[idxBuku][KOLOM_STOK] > 0) {
        // Kurangi Stok Buku
        dataBuku[idxBuku][KOLOM_STOK]--;
        // Tambah Jumlah Dipinjam
        dataBuku[idxBuku][KOLOM_DIPINJAM]++;
        // Tambah Poin Pengguna
        poinUser += dataBuku[idxBuku][KOLOM_POIN];

        cout << "\n[BERHASIL] Peminjaman sukses!\n";
        cout << "  - " << namaPeminjam << " meminjam: " << judulBuku[idxBuku] << "\n";
        cout << "  - Anda mendapatkan +" << dataBuku[idxBuku][KOLOM_POIN] << " Poin!\n";
        cout << "  - Total Poin Anda saat ini: " << poinUser << "\n";
        cout << "  - Sisa Stok " << judulBuku[idxBuku] << ": " << dataBuku[idxBuku][KOLOM_STOK] << "\n";
    } else {
        cout << "\n[GAGAL] Stok buku '" << judulBuku[idxBuku] << "' habis!\n"; // Flowchart: 'Stok habis'
    }
}

/**
 * @brief Memproses pengembalian buku. (Fitur 3)
 * @param namaPengembali Parameter by Value
 * @param idxBuku Index buku yang dikembalikan (By Value)
 * @param poinPengguna Pointer ke array poin pengguna (By Reference)
 */
void pengembalianBuku(const string& namaPengembali, int idxBuku, int& poinUser) {
    // Kriteria A: Aturan/Kebijakan (Percabangan)
    if (dataBuku[idxBuku][KOLOM_STOK] < MAX_STOK) {
        // Tambah Stok Buku
        dataBuku[idxBuku][KOLOM_STOK]++;
        // Kurangi Jumlah Dipinjam (Asumsi buku ini sebelumnya dipinjam)
        if (dataBuku[idxBuku][KOLOM_DIPINJAM] > 0) {
            dataBuku[idxBuku][KOLOM_DIPINJAM]--;
        }
        // Tambah Poin Pengguna (Gamifikasi)
        poinUser += 5; // Poin tambahan untuk pengembalian tepat waktu
        
        cout << "\n[BERHASIL] Pengembalian sukses!\n";
        cout << "  - " << judulBuku[idxBuku] << " berhasil dikembalikan oleh " << namaPengembali << ".\n";
        cout << "  - Anda mendapatkan +5 Poin tambahan!\n";
        cout << "  - Total Poin Anda saat ini: " << poinUser << "\n";
        cout << "  - Stok " << judulBuku[idxBuku] << " kini: " << dataBuku[idxBuku][KOLOM_STOK] << "\n";
    } else {
        cout << "\n[WARNING] Stok buku sudah penuh (" << MAX_STOK << "). Tidak perlu penambahan.\n"; // Flowchart: 'Stok sudah penuh'
    }
}

/**
 * @brief Mengurutkan pengguna berdasarkan poin secara descending (tertinggi ke terendah)
 * Menggunakan Bubble Sort pada array Poin dan menukar Nama secara paralel.
 * (Kriteria E: Algoritma Sorting - Bubble Sort)
 */
void bubbleSortPoin(int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        // Inner loop untuk membandingkan
        for (int j = 0; j < jumlah - 1 - i; j++) { // Kriteria B: Perulangan
            // Kriteria A: Percabangan (Aturan: Sorting Descending)
            if (poinPengguna[j] < poinPengguna[j + 1]) { 
                // Swap Poin
                int tempPoin = poinPengguna[j];
                poinPengguna[j] = poinPengguna[j + 1];
                poinPengguna[j + 1] = tempPoin;

                // Swap Nama secara paralel
                string tempNama = namaPengguna[j];
                namaPengguna[j] = namaPengguna[j + 1];
                namaPengguna[j + 1] = tempNama;
            }
        }
    }
}

/**
 * @brief Menampilkan papan peringkat (Leaderboard). (Fitur 4)
 */
void papanPeringkat() {
    // 1. Urutkan data pengguna
    bubbleSortPoin(jumlahUserAktif); // Kriteria E: Panggil Algoritma Sorting

    cout << "\n=========================================\n";
    cout << "          PAPAN PERINGKAT (LEADERBOARD)\n";
    cout << "=========================================\n";
    cout << left << setw(10) << "Peringkat"
         << setw(20) << "Nama Pengguna"
         << setw(10) << "Poin\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < jumlahUserAktif; i++) { // Kriteria B: Perulangan
        cout << left << setw(10) << i + 1
             << setw(20) << namaPengguna[i]
             << setw(10) << poinPengguna[i] << "\n";
    }
    cout << "=========================================\n";
}

/**
 * @brief Fungsi utama untuk menampilkan menu.
 */
int tampilkanMenu() {
    int pilihan;
    cout << "\n=========================================\n";
    cout << "   SISTEM MANAJEMEN PERPUSTAKAAN (CPS)\n";
    cout << "=========================================\n";
    cout << "1. Tampilkan Daftar Buku\n";
    cout << "2. Peminjaman Buku\n";
    cout << "3. Pengembalian Buku\n";
    cout << "4. Papan Peringkat (Leaderboard)\n";
    cout << "5. Keluar\n";
    cout << "-----------------------------------------\n";
    cout << "Masukkan pilihan Anda (1-5): ";
    
    // Kriteria F: Validasi kesalahan input dasar
    if (!(cin >> pilihan)) {
        cout << "[ERROR] Input harus berupa angka. Silakan coba lagi.\n";
        bersihkanInput();
        return 0; // Mengembalikan 0 untuk mengulang menu
    }
    bersihkanInput();
    return pilihan;
}


// --- FUNGSI UTAMA (MAIN) ---
int main() {
    inisialisasiData();
    int pilihan;

    // Kriteria B: Perulangan do-while untuk mengontrol menu utama
    do {
        pilihan = tampilkanMenu();
        string inputJudul;
        string inputNamaUser;
        int idxBuku;
        int idxUser;

        // Kriteria A: Percabangan (Switch/Case) untuk memproses menu
        switch (pilihan) {
            case 1:
                tampilkanDaftarBuku();
                break;

            case 2: // Peminjaman Buku
                tampilkanDaftarBuku();
                cout << "Masukkan Nama Peminjam: ";
                getline(cin, inputNamaUser);
                cout << "Masukkan Judul Buku yang dipinjam: ";
                getline(cin, inputJudul);
                
                idxBuku = sequentialSearchBuku(inputJudul);
                idxUser = sequentialSearchUser(inputNamaUser);
                
                if (idxBuku != -1 && idxUser != -1) {
                    // Panggil fungsi Peminjaman (dengan parameter by reference untuk Poin Pengguna)
                    peminjamanBuku(inputNamaUser, idxBuku, poinPengguna[idxUser]);
                } else if (idxBuku == -1) {
                    cout << "[ERROR] Buku dengan judul '" << inputJudul << "' tidak ditemukan.\n";
                } else if (idxUser == -1) {
                    cout << "[ERROR] Pengguna '" << inputNamaUser << "' tidak ditemukan.\n";
                }
                break;

            case 3: // Pengembalian Buku
                tampilkanDaftarBuku();
                cout << "Masukkan Nama Pengembali: ";
                getline(cin, inputNamaUser);
                cout << "Masukkan Judul Buku yang dikembalikan: ";
                getline(cin, inputJudul);

                idxBuku = sequentialSearchBuku(inputJudul);
                idxUser = sequentialSearchUser(inputNamaUser);
                
                if (idxBuku != -1 && idxUser != -1) {
                    // Panggil fungsi Pengembalian (dengan parameter by reference untuk Poin Pengguna)
                    pengembalianBuku(inputNamaUser, idxBuku, poinPengguna[idxUser]);
                } else if (idxBuku == -1) {
                    cout << "[ERROR] Buku dengan judul '" << inputJudul << "' tidak ditemukan.\n";
                } else if (idxUser == -1) {
                    cout << "[ERROR] Pengguna '" << inputNamaUser << "' tidak ditemukan.\n";
                }
                break;

            case 4:
                papanPeringkat();
                break;

            case 5:
                cout << "\nTerima kasih telah menggunakan Sistem Manajemen Perpustakaan (CPS). Sampai jumpa!\n";
                break;

            default:
                cout << "\n[ERROR] Pilihan tidak valid. Silakan masukkan angka 1 sampai 5.\n";
                break;
        }

    } while (pilihan != 5);

    return 0;
}