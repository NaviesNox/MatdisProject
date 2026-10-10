// Mengimpor pustaka yang dibutuhkan program.
#include <algorithm>
// Mengimpor pustaka yang dibutuhkan program.
#include <cstdlib>
// Mengimpor pustaka yang dibutuhkan program.
#include <iostream>
// Mengimpor pustaka yang dibutuhkan program.
#include <set>
// Mengimpor pustaka yang dibutuhkan program.
#include <string>
// Mengimpor pustaka yang dibutuhkan program.
#include <vector>

// Mengaktifkan penggunaan nama dari namespace std tanpa awalan std::.
using namespace std;

// Mendefinisikan alias Himpunan sebagai kumpulan bilangan bulat terurut.
using Himpunan = set<int>;

// Membersihkan layar terminal sebelum interaksi berikutnya.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void bersihkanTerminal() {
// Memulai pemeriksaan kondisi kompilasi khusus platform.
#ifdef _WIN32
    // Menjalankan perintah terminal untuk membersihkan layar.
    system("cls");
// Memilih cabang kompilasi untuk platform selain kondisi sebelumnya.
#else
    // Menjalankan perintah terminal untuk membersihkan layar.
    system("clear");
// Mengakhiri pemeriksaan kondisi kompilasi platform.
#endif
// Menutup blok kode sebelumnya.
}

// Menunggu pengguna selesai membaca hasil sebelum menampilkan menu berikutnya.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void tungguEnter() {
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\nTekan Enter untuk kembali ke menu...";
    // Mendeklarasikan variabel teks.
    string baris;
    // Membaca satu baris input pengguna.
    getline(cin, baris);
// Menutup blok kode sebelumnya.
}

// Mengubah satu baris teks menjadi himpunan bilangan bulat dengan validasi.
// Mendeklarasikan variabel himpunan bilangan bulat.
Himpunan bacaHimpunan(const string& pesan) {
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan hasil;
    // Mendeklarasikan variabel teks.
    string baris;

    // Mengulang blok selama kondisi masih benar.
    while (true) {
        // Menampilkan informasi atau hasil ke terminal.
        cout << pesan;
        // Membaca satu baris input pengguna.
        getline(cin, baris);

        // Memeriksa kondisi sebelum menjalankan blok berikutnya.
        if (!cin) {
            // Menjalankan operasi pada baris ini sesuai alur program.
            cin.clear();
            // Menampilkan informasi atau hasil ke terminal.
            cout << "Input berakhir. Silakan masukkan kembali.\n";
            // Melanjutkan perulangan ke iterasi berikutnya.
            continue;
        // Menutup blok kode sebelumnya.
        }

        // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
        bool valid = true;
        // Mendeklarasikan variabel ukuran atau posisi tanpa nilai negatif.
        size_t posisi = 0;
        // Mengulang blok selama kondisi masih benar.
        while (posisi < baris.size()) {
            // Mengulang blok selama kondisi masih benar.
            while (posisi < baris.size() &&
                   // Menjalankan operasi pada baris ini sesuai alur program.
                   (baris[posisi] == ' ' || baris[posisi] == '\t')) {
                // Memajukan posisi atau penghitung satu langkah.
                ++posisi;
            // Menutup blok kode sebelumnya.
            }
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (posisi == baris.size()) {
                // Mengakhiri blok perulangan atau pilihan saat ini.
                break;
            // Menutup blok kode sebelumnya.
            }

            // Mendeklarasikan variabel ukuran atau posisi tanpa nilai negatif.
            size_t awal = posisi;
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (baris[posisi] == '-' || baris[posisi] == '+') {
                // Memajukan posisi atau penghitung satu langkah.
                ++posisi;
            // Menutup blok kode sebelumnya.
            }
            // Mendeklarasikan variabel ukuran atau posisi tanpa nilai negatif.
            size_t awalAngka = posisi;
            // Mengulang blok selama kondisi masih benar.
            while (posisi < baris.size() && baris[posisi] >= '0' &&
                   // Menjalankan operasi pada baris ini sesuai alur program.
                   baris[posisi] <= '9') {
                // Memajukan posisi atau penghitung satu langkah.
                ++posisi;
            // Menutup blok kode sebelumnya.
            }

            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (awalAngka == posisi ||
                // Menjalankan operasi pada baris ini sesuai alur program.
                (posisi < baris.size() && baris[posisi] != ' ' &&
                 // Menjalankan operasi pada baris ini sesuai alur program.
                 baris[posisi] != '\t')) {
                // Menjalankan operasi pada baris ini sesuai alur program.
                valid = false;
                // Mengakhiri blok perulangan atau pilihan saat ini.
                break;
            // Menutup blok kode sebelumnya.
            }

            // Mendeklarasikan variabel teks.
            string token = baris.substr(awal, posisi - awal);
            // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
            bool negatif = !token.empty() && token[0] == '-';
            // Mendeklarasikan variabel ukuran atau posisi tanpa nilai negatif.
            size_t indeks = (token[0] == '-' || token[0] == '+') ? 1 : 0;
            // Mendeklarasikan bilangan bulat berukuran besar.
            long long nilai = 0;
            // Mengulang blok selama kondisi masih benar.
            while (indeks < token.size()) {
                // Menjalankan operasi pada baris ini sesuai alur program.
                nilai = nilai * 10 + (token[indeks] - '0');
                // Memeriksa kondisi sebelum menjalankan blok berikutnya.
                if ((!negatif && nilai > 2147483647LL) ||
                    // Menjalankan operasi pada baris ini sesuai alur program.
                    (negatif && nilai > 2147483648LL)) {
                    // Menjalankan operasi pada baris ini sesuai alur program.
                    valid = false;
                    // Mengakhiri blok perulangan atau pilihan saat ini.
                    break;
                // Menutup blok kode sebelumnya.
                }
                // Memajukan posisi atau penghitung satu langkah.
                ++indeks;
            // Menutup blok kode sebelumnya.
            }
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!valid) {
                // Mengakhiri blok perulangan atau pilihan saat ini.
                break;
            // Menutup blok kode sebelumnya.
            }
            // Menjalankan operasi pada baris ini sesuai alur program.
            hasil.insert(static_cast<int>(negatif ? -nilai : nilai));
        // Menutup blok kode sebelumnya.
        }

        // Memeriksa kondisi sebelum menjalankan blok berikutnya.
        if (valid) {
            // Mengembalikan hasil dari fungsi atau mengakhiri program.
            return hasil;
        // Menutup blok kode sebelumnya.
        }
        // Menampilkan informasi atau hasil ke terminal.
        cout << "Input tidak valid. Masukkan bilangan bulat dipisahkan spasi.\n";
    // Menutup blok kode sebelumnya.
    }
// Menutup blok kode sebelumnya.
}

// Menampilkan anggota himpunan dengan notasi matematika.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void cetakHimpunan(const Himpunan& himpunan) {
    // Menampilkan informasi atau hasil ke terminal.
    cout << "{";
    // Mengulang proses untuk setiap nilai yang diperlukan.
    for (auto iterator = himpunan.begin(); iterator != himpunan.end(); ++iterator) {
        // Memeriksa kondisi sebelum menjalankan blok berikutnya.
        if (iterator != himpunan.begin()) {
            // Menampilkan informasi atau hasil ke terminal.
            cout << ", ";
        // Menutup blok kode sebelumnya.
        }
        // Menampilkan informasi atau hasil ke terminal.
        cout << *iterator;
    // Menutup blok kode sebelumnya.
    }
    // Menampilkan informasi atau hasil ke terminal.
    cout << "}";
// Menutup blok kode sebelumnya.
}

// Menghitung gabungan dua himpunan.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void gabungan(const Himpunan& a, const Himpunan& b) {
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan hasil = a;
    // Menjalankan operasi pada baris ini sesuai alur program.
    hasil.insert(b.begin(), b.end());
    // Menampilkan informasi atau hasil ke terminal.
    cout << "A ∪ B = ";
    // Menjalankan operasi pada baris ini sesuai alur program.
    cetakHimpunan(hasil);
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\n";
// Menutup blok kode sebelumnya.
}

// Menghitung irisan dua himpunan.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void irisan(const Himpunan& a, const Himpunan& b) {
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan hasil;
    // Menjalankan operasi pada baris ini sesuai alur program.
    set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                          // Menjalankan operasi pada baris ini sesuai alur program.
                          inserter(hasil, hasil.begin()));
    // Menampilkan informasi atau hasil ke terminal.
    cout << "A ∩ B = ";
    // Menjalankan operasi pada baris ini sesuai alur program.
    cetakHimpunan(hasil);
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\n";
// Menutup blok kode sebelumnya.
}

// Menghitung selisih A-B dan B-A.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void selisih(const Himpunan& a, const Himpunan& b) {
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan aKurangB;
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan bKurangA;
    // Menjalankan operasi pada baris ini sesuai alur program.
    set_difference(a.begin(), a.end(), b.begin(), b.end(),
                        // Menjalankan operasi pada baris ini sesuai alur program.
                        inserter(aKurangB, aKurangB.begin()));
    // Menjalankan operasi pada baris ini sesuai alur program.
    set_difference(b.begin(), b.end(), a.begin(), a.end(),
                        // Menjalankan operasi pada baris ini sesuai alur program.
                        inserter(bKurangA, bKurangA.begin()));
    // Menampilkan informasi atau hasil ke terminal.
    cout << "A - B = ";
    // Menjalankan operasi pada baris ini sesuai alur program.
    cetakHimpunan(aKurangB);
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\nB - A = ";
    // Menjalankan operasi pada baris ini sesuai alur program.
    cetakHimpunan(bKurangA);
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\n";
// Menutup blok kode sebelumnya.
}

// Menghitung selisih simetris dua himpunan.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void selisihSimetris(const Himpunan& a, const Himpunan& b) {
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan hasil;
    // Menjalankan operasi pada baris ini sesuai alur program.
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(),
                                  // Menjalankan operasi pada baris ini sesuai alur program.
                                  inserter(hasil, hasil.begin()));
    // Menampilkan informasi atau hasil ke terminal.
    cout << "A ⊕ B = ";
    // Menjalankan operasi pada baris ini sesuai alur program.
    cetakHimpunan(hasil);
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\n";
// Menutup blok kode sebelumnya.
}

// Menghitung komplemen A dan B terhadap himpunan semesta.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void komplemen(const Himpunan& a, const Himpunan& b, const Himpunan& u) {
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan komplemenA;
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan komplemenB;
    // Menjalankan operasi pada baris ini sesuai alur program.
    set_difference(u.begin(), u.end(), a.begin(), a.end(),
                        // Menjalankan operasi pada baris ini sesuai alur program.
                        inserter(komplemenA, komplemenA.begin()));
    // Menjalankan operasi pada baris ini sesuai alur program.
    set_difference(u.begin(), u.end(), b.begin(), b.end(),
                        // Menjalankan operasi pada baris ini sesuai alur program.
                        inserter(komplemenB, komplemenB.begin()));
    // Menampilkan informasi atau hasil ke terminal.
    cout << "A' = ";
    // Menjalankan operasi pada baris ini sesuai alur program.
    cetakHimpunan(komplemenA);
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\nB' = ";
    // Menjalankan operasi pada baris ini sesuai alur program.
    cetakHimpunan(komplemenB);
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\n";
// Menutup blok kode sebelumnya.
}

// Menampilkan power set dan jumlah anggotanya.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void himpunanKuasa(const Himpunan& himpunan, const string& nama) {
    // Mendeklarasikan wadah vector untuk menyimpan elemen.
    vector<int> elemen(himpunan.begin(), himpunan.end());
    // Mendeklarasikan bilangan bulat besar tanpa nilai negatif.
    unsigned long long jumlah = 1;
    // Mengulang proses untuk setiap nilai yang diperlukan.
    for (size_t i = 0; i < elemen.size(); ++i) {
        // Menjalankan operasi pada baris ini sesuai alur program.
        jumlah *= 2;
    // Menutup blok kode sebelumnya.
    }

    // Menampilkan informasi atau hasil ke terminal.
    cout << "Jumlah anggota P(" << nama << ") = " << jumlah << "\n";
    // Memeriksa kondisi sebelum menjalankan blok berikutnya.
    if (elemen.size() > 10) {
        // Menampilkan informasi atau hasil ke terminal.
        cout << "Peringatan: n > 10, anggota himpunan kuasa tidak dicetak.\n";
        // Menjalankan operasi pada baris ini sesuai alur program.
        return;
    // Menutup blok kode sebelumnya.
    }

    // Menampilkan informasi atau hasil ke terminal.
    cout << "P(" << nama << ") = {";
    // Mendeklarasikan bilangan bulat besar tanpa nilai negatif.
    unsigned long long batas = jumlah;
    // Mengulang proses untuk setiap nilai yang diperlukan.
    for (unsigned long long mask = 0; mask < batas; ++mask) {
        // Memeriksa kondisi sebelum menjalankan blok berikutnya.
        if (mask != 0) {
            // Menampilkan informasi atau hasil ke terminal.
            cout << ", ";
        // Menutup blok kode sebelumnya.
        }
        // Menampilkan informasi atau hasil ke terminal.
        cout << "{";
        // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
        bool anggotaPertama = true;
        // Mengulang proses untuk setiap nilai yang diperlukan.
        for (size_t indeks = 0; indeks < elemen.size(); ++indeks) {
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if ((mask & (1ULL << indeks)) != 0) {
                // Memeriksa kondisi sebelum menjalankan blok berikutnya.
                if (!anggotaPertama) {
                    // Menampilkan informasi atau hasil ke terminal.
                    cout << ", ";
                // Menutup blok kode sebelumnya.
                }
                // Menampilkan informasi atau hasil ke terminal.
                cout << elemen[indeks];
                // Menjalankan operasi pada baris ini sesuai alur program.
                anggotaPertama = false;
            // Menutup blok kode sebelumnya.
            }
        // Menutup blok kode sebelumnya.
        }
        // Menampilkan informasi atau hasil ke terminal.
        cout << "}";
    // Menutup blok kode sebelumnya.
    }
    // Menampilkan informasi atau hasil ke terminal.
    cout << "}\n";
// Menutup blok kode sebelumnya.
}

// Menampilkan semua pasangan berurutan pada hasil kali kartesian A x B.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void kartesian(const Himpunan& a, const Himpunan& b) {
    // Menampilkan informasi atau hasil ke terminal.
    cout << "A × B = {";
    // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
    bool pasanganPertama = true;
    // Mengulang proses untuk setiap nilai yang diperlukan.
    for (int nilaiA : a) {
        // Mengulang proses untuk setiap nilai yang diperlukan.
        for (int nilaiB : b) {
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!pasanganPertama) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << ", ";
            // Menutup blok kode sebelumnya.
            }
            // Menampilkan informasi atau hasil ke terminal.
            cout << "(" << nilaiA << ", " << nilaiB << ")";
            // Menjalankan operasi pada baris ini sesuai alur program.
            pasanganPertama = false;
        // Menutup blok kode sebelumnya.
        }
    // Menutup blok kode sebelumnya.
    }
    // Menampilkan informasi atau hasil ke terminal.
    cout << "}\n";
// Menutup blok kode sebelumnya.
}

// Memeriksa relasi subset, kesamaan, dan saling lepas antarhimpunan.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void cekSubset(const Himpunan& a, const Himpunan& b) {
    // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
    bool aSubsetB = includes(b.begin(), b.end(), a.begin(), a.end());
    // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
    bool bSubsetA = includes(a.begin(), a.end(), b.begin(), b.end());
    // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
    bool disjoint = true;
    // Mengulang proses untuk setiap nilai yang diperlukan.
    for (int nilai : a) {
        // Memeriksa kondisi sebelum menjalankan blok berikutnya.
        if (b.find(nilai) != b.end()) {
            // Menjalankan operasi pada baris ini sesuai alur program.
            disjoint = false;
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menutup blok kode sebelumnya.
        }
    // Menutup blok kode sebelumnya.
    }

    // Menampilkan informasi atau hasil ke terminal.
    cout << "A subset B: " << (aSubsetB ? "ya" : "tidak") << "\n";
    // Menampilkan informasi atau hasil ke terminal.
    cout << "B subset A: " << (bSubsetA ? "ya" : "tidak") << "\n";
    // Menampilkan informasi atau hasil ke terminal.
    cout << "A sama dengan B: " << (a == b ? "ya" : "tidak") << "\n";
    // Menampilkan informasi atau hasil ke terminal.
    cout << "A dan B saling lepas: " << (disjoint ? "ya" : "tidak") << "\n";
// Menutup blok kode sebelumnya.
}

// Menampilkan kardinalitas dua himpunan.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void kardinalitas(const Himpunan& a, const Himpunan& b) {
    // Menampilkan informasi atau hasil ke terminal.
    cout << "|A| = " << a.size() << "\n";
    // Menampilkan informasi atau hasil ke terminal.
    cout << "|B| = " << b.size() << "\n";
// Menutup blok kode sebelumnya.
}

// Menampilkan seluruh himpunan yang tersimpan.
// Mendeklarasikan fungsi yang tidak mengembalikan nilai.
void tampilkanSemua(const Himpunan& a, const Himpunan& b, const Himpunan& u,
                    // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
                    bool aDiisi, bool bDiisi, bool uDiisi) {
    // Menampilkan informasi atau hasil ke terminal.
    cout << "A = ";
    // Memeriksa kondisi sebelum menjalankan blok berikutnya.
    if (aDiisi) {
        // Menjalankan operasi pada baris ini sesuai alur program.
        cetakHimpunan(a);
    // Menutup blok kode sebelumnya.
    } else {
        // Menampilkan informasi atau hasil ke terminal.
        cout << "(belum diisi)";
    // Menutup blok kode sebelumnya.
    }
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\nB = ";
    // Memeriksa kondisi sebelum menjalankan blok berikutnya.
    if (bDiisi) {
        // Menjalankan operasi pada baris ini sesuai alur program.
        cetakHimpunan(b);
    // Menutup blok kode sebelumnya.
    } else {
        // Menampilkan informasi atau hasil ke terminal.
        cout << "(belum diisi)";
    // Menutup blok kode sebelumnya.
    }
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\nU = ";
    // Memeriksa kondisi sebelum menjalankan blok berikutnya.
    if (uDiisi) {
        // Menjalankan operasi pada baris ini sesuai alur program.
        cetakHimpunan(u);
    // Menutup blok kode sebelumnya.
    } else {
        // Menampilkan informasi atau hasil ke terminal.
        cout << "(belum diisi)";
    // Menutup blok kode sebelumnya.
    }
    // Menampilkan informasi atau hasil ke terminal.
    cout << "\n";
// Menutup blok kode sebelumnya.
}

// Membaca pilihan menu dan mengubahnya menjadi angka menu yang valid.
// Mendeklarasikan variabel atau fungsi bertipe bilangan bulat.
int bacaPilihanMenu() {
    // Mendeklarasikan variabel teks.
    string teks;
    // Membaca satu baris input pengguna.
    getline(cin, teks);
    // Memeriksa kondisi sebelum menjalankan blok berikutnya.
    if (teks.empty()) {
        // Mengembalikan hasil dari fungsi atau mengakhiri program.
        return -1;
    // Menutup blok kode sebelumnya.
    }

    // Mendeklarasikan variabel atau fungsi bertipe bilangan bulat.
    int pilihan = 0;
    // Mengulang proses untuk setiap nilai yang diperlukan.
    for (char karakter : teks) {
        // Memeriksa kondisi sebelum menjalankan blok berikutnya.
        if (karakter < '0' || karakter > '9') {
            // Mengembalikan hasil dari fungsi atau mengakhiri program.
            return -1;
        // Menutup blok kode sebelumnya.
        }
        // Menjalankan operasi pada baris ini sesuai alur program.
        pilihan = pilihan * 10 + (karakter - '0');
        // Memeriksa kondisi sebelum menjalankan blok berikutnya.
        if (pilihan > 12) {
            // Mengembalikan hasil dari fungsi atau mengakhiri program.
            return -1;
        // Menutup blok kode sebelumnya.
        }
    // Menutup blok kode sebelumnya.
    }
    // Mengembalikan hasil dari fungsi atau mengakhiri program.
    return pilihan;
// Menutup blok kode sebelumnya.
}

// Menjalankan menu interaktif kalkulator himpunan.
// Mendeklarasikan fungsi utama sebagai titik masuk program.
int main() {
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan a;
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan b;
    // Mendeklarasikan variabel himpunan bilangan bulat.
    Himpunan u;
    // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
    bool aDiisi = false;
    // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
    bool bDiisi = false;
    // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
    bool uDiisi = false;
    // Mengulang blok selama kondisi masih benar.
    while (true) {
        // Menjalankan operasi pada baris ini sesuai alur program.
        bersihkanTerminal();
        // Menampilkan informasi atau hasil ke terminal.
        cout << "\n=== KALKULATOR HIMPUNAN ===\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "1. Input himpunan A dan B\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "2. Input himpunan semesta U\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "3. Gabungan (A union B)\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "4. Irisan (A intersection B)\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "5. Selisih (A-B dan B-A)\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "6. Selisih simetris (A symmetric_difference B)\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "7. Komplemen (A' dan B')\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "8. Himpunan kuasa\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "9. Hasil kali kartesian (A x B)\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "10. Cek hubungan himpunan\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "11. Kardinalitas\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "12. Tampilkan himpunan saat ini\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "0. Keluar\n"
                  // Menjalankan operasi pada baris ini sesuai alur program.
                  << "Pilihan: ";
        // Memilih tindakan berdasarkan pilihan menu pengguna.
        switch (bacaPilihanMenu()) {
        // Menandai tindakan untuk pilihan menu tertentu.
        case 0:
            // Menampilkan informasi atau hasil ke terminal.
            cout << "Program selesai.\n";
            // Mengembalikan hasil dari fungsi atau mengakhiri program.
            return 0;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 1:
            // Menjalankan operasi pada baris ini sesuai alur program.
            a = bacaHimpunan("Masukkan elemen A (kosongkan untuk {}): ");
            // Menjalankan operasi pada baris ini sesuai alur program.
            b = bacaHimpunan("Masukkan elemen B (kosongkan untuk {}): ");
            // Menjalankan operasi pada baris ini sesuai alur program.
            aDiisi = true;
            // Menjalankan operasi pada baris ini sesuai alur program.
            bDiisi = true;
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 2:
            // Menjalankan operasi pada baris ini sesuai alur program.
            u = bacaHimpunan("Masukkan elemen U (kosongkan untuk {}): ");
            // Menjalankan operasi pada baris ini sesuai alur program.
            uDiisi = true;
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 3:
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!aDiisi || !bDiisi) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            // Menutup blok kode sebelumnya.
            } else {
                // Menjalankan operasi pada baris ini sesuai alur program.
                gabungan(a, b);
            // Menutup blok kode sebelumnya.
            }
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 4:
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!aDiisi || !bDiisi) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            // Menutup blok kode sebelumnya.
            } else {
                // Menjalankan operasi pada baris ini sesuai alur program.
                irisan(a, b);
            // Menutup blok kode sebelumnya.
            }
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 5:
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!aDiisi || !bDiisi) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            // Menutup blok kode sebelumnya.
            } else {
                // Menjalankan operasi pada baris ini sesuai alur program.
                selisih(a, b);
            // Menutup blok kode sebelumnya.
            }
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 6:
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!aDiisi || !bDiisi) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            // Menutup blok kode sebelumnya.
            } else {
                // Menjalankan operasi pada baris ini sesuai alur program.
                selisihSimetris(a, b);
            // Menutup blok kode sebelumnya.
            }
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 9:
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!aDiisi || !bDiisi) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            // Menutup blok kode sebelumnya.
            } else {
                // Menjalankan operasi pada baris ini sesuai alur program.
                kartesian(a, b);
            // Menutup blok kode sebelumnya.
            }
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 10:
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!aDiisi || !bDiisi) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            // Menutup blok kode sebelumnya.
            } else {
                // Menjalankan operasi pada baris ini sesuai alur program.
                cekSubset(a, b);
            // Menutup blok kode sebelumnya.
            }
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 11:
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!aDiisi || !bDiisi) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            // Menutup blok kode sebelumnya.
            } else {
                // Menjalankan operasi pada baris ini sesuai alur program.
                kardinalitas(a, b);
            // Menutup blok kode sebelumnya.
            }
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 7:
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!aDiisi || !bDiisi || !uDiisi) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "A, B, dan U harus diisi terlebih dahulu.\n";
            // Menutup blok kode sebelumnya.
            } else {
                // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
                bool aDiLuarU =
                    // Menjalankan operasi pada baris ini sesuai alur program.
                    !includes(u.begin(), u.end(), a.begin(), a.end());
                // Mendeklarasikan nilai logika untuk menyimpan benar atau salah.
                bool bDiLuarU =
                    // Menjalankan operasi pada baris ini sesuai alur program.
                    !includes(u.begin(), u.end(), b.begin(), b.end());
                // Memeriksa kondisi sebelum menjalankan blok berikutnya.
                if (aDiLuarU || bDiLuarU) {
                    // Menampilkan informasi atau hasil ke terminal.
                    cout << "Peringatan: ada elemen A atau B yang tidak ada di U.\n";
                // Menutup blok kode sebelumnya.
                }
                // Menjalankan operasi pada baris ini sesuai alur program.
                komplemen(a, b, u);
            // Menutup blok kode sebelumnya.
            }
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menandai tindakan untuk pilihan menu tertentu.
        case 8: {
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (!aDiisi || !bDiisi) {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
                // Mengakhiri blok perulangan atau pilihan saat ini.
                break;
            // Menutup blok kode sebelumnya.
            }
            // Mendeklarasikan variabel teks.
            string target;
            // Menampilkan informasi atau hasil ke terminal.
            cout << "Pilih himpunan (A/B): ";
            // Membaca satu baris input pengguna.
            getline(cin, target);
            // Memeriksa kondisi sebelum menjalankan blok berikutnya.
            if (target == "A" || target == "a") {
                // Menjalankan operasi pada baris ini sesuai alur program.
                himpunanKuasa(a, "A");
            // Menutup blok kode sebelumnya.
            } else if (target == "B" || target == "b") {
                // Menjalankan operasi pada baris ini sesuai alur program.
                himpunanKuasa(b, "B");
            // Menutup blok kode sebelumnya.
            } else {
                // Menampilkan informasi atau hasil ke terminal.
                cout << "Pilihan himpunan tidak valid.\n";
            // Menutup blok kode sebelumnya.
            }
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menutup blok kode sebelumnya.
        }
        // Menandai tindakan untuk pilihan menu tertentu.
        case 12:
            // Menjalankan operasi pada baris ini sesuai alur program.
            tampilkanSemua(a, b, u, aDiisi, bDiisi, uDiisi);
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menangani pilihan menu yang tidak dikenali.
        default:
            // Menampilkan informasi atau hasil ke terminal.
            cout << "Pilihan menu tidak valid.\n";
            // Mengakhiri blok perulangan atau pilihan saat ini.
            break;
        // Menutup blok kode sebelumnya.
        }
        // Menjalankan operasi pada baris ini sesuai alur program.
        tungguEnter();
    // Menutup blok kode sebelumnya.
    }
// Menutup blok kode sebelumnya.
}
