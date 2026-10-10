#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

using Himpunan = set<int>;

// Membersihkan layar terminal sebelum interaksi berikutnya.
void bersihkanTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Menunggu pengguna selesai membaca hasil sebelum menampilkan menu berikutnya.
void tungguEnter() {
    cout << "\nTekan Enter untuk kembali ke menu...";
    string baris;
    getline(cin, baris);
}

// Mengubah satu baris teks menjadi himpunan bilangan bulat dengan validasi.
Himpunan bacaHimpunan(const string& pesan) {
    Himpunan hasil;
    string baris;

    while (true) {
        cout << pesan;
        getline(cin, baris);

        if (!cin) {
            cin.clear();
            cout << "Input berakhir. Silakan masukkan kembali.\n";
            continue;
        }

        bool valid = true;
        size_t posisi = 0;
        while (posisi < baris.size()) {
            while (posisi < baris.size() &&
                   (baris[posisi] == ' ' || baris[posisi] == '\t')) {
                ++posisi;
            }
            if (posisi == baris.size()) {
                break;
            }

            size_t awal = posisi;
            if (baris[posisi] == '-' || baris[posisi] == '+') {
                ++posisi;
            }
            size_t awalAngka = posisi;
            while (posisi < baris.size() && baris[posisi] >= '0' &&
                   baris[posisi] <= '9') {
                ++posisi;
            }

            if (awalAngka == posisi ||
                (posisi < baris.size() && baris[posisi] != ' ' &&
                 baris[posisi] != '\t')) {
                valid = false;
                break;
            }

            string token = baris.substr(awal, posisi - awal);
            bool negatif = !token.empty() && token[0] == '-';
            size_t indeks = (token[0] == '-' || token[0] == '+') ? 1 : 0;
            long long nilai = 0;
            while (indeks < token.size()) {
                nilai = nilai * 10 + (token[indeks] - '0');
                if ((!negatif && nilai > 2147483647LL) ||
                    (negatif && nilai > 2147483648LL)) {
                    valid = false;
                    break;
                }
                ++indeks;
            }
            if (!valid) {
                break;
            }
            hasil.insert(static_cast<int>(negatif ? -nilai : nilai));
        }

        if (valid) {
            return hasil;
        }
        cout << "Input tidak valid. Masukkan bilangan bulat dipisahkan spasi.\n";
    }
}

// Menampilkan anggota himpunan dengan notasi matematika.
void cetakHimpunan(const Himpunan& himpunan) {
    cout << "{";
    for (auto iterator = himpunan.begin(); iterator != himpunan.end(); ++iterator) {
        if (iterator != himpunan.begin()) {
            cout << ", ";
        }
        cout << *iterator;
    }
    cout << "}";
}

// Menghitung gabungan dua himpunan.
void gabungan(const Himpunan& a, const Himpunan& b) {
    Himpunan hasil = a;
    hasil.insert(b.begin(), b.end());
    cout << "A ∪ B = ";
    cetakHimpunan(hasil);
    cout << "\n";
}

// Menghitung irisan dua himpunan.
void irisan(const Himpunan& a, const Himpunan& b) {
    Himpunan hasil;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                          inserter(hasil, hasil.begin()));
    cout << "A ∩ B = ";
    cetakHimpunan(hasil);
    cout << "\n";
}

// Menghitung selisih A-B dan B-A.
void selisih(const Himpunan& a, const Himpunan& b) {
    Himpunan aKurangB;
    Himpunan bKurangA;
    set_difference(a.begin(), a.end(), b.begin(), b.end(),
                        inserter(aKurangB, aKurangB.begin()));
    set_difference(b.begin(), b.end(), a.begin(), a.end(),
                        inserter(bKurangA, bKurangA.begin()));
    cout << "A - B = ";
    cetakHimpunan(aKurangB);
    cout << "\nB - A = ";
    cetakHimpunan(bKurangA);
    cout << "\n";
}

// Menghitung selisih simetris dua himpunan.
void selisihSimetris(const Himpunan& a, const Himpunan& b) {
    Himpunan hasil;
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(),
                                  inserter(hasil, hasil.begin()));
    cout << "A ⊕ B = ";
    cetakHimpunan(hasil);
    cout << "\n";
}

// Menghitung komplemen A dan B terhadap himpunan semesta.
void komplemen(const Himpunan& a, const Himpunan& b, const Himpunan& u) {
    Himpunan komplemenA;
    Himpunan komplemenB;
    set_difference(u.begin(), u.end(), a.begin(), a.end(),
                        inserter(komplemenA, komplemenA.begin()));
    set_difference(u.begin(), u.end(), b.begin(), b.end(),
                        inserter(komplemenB, komplemenB.begin()));
    cout << "A' = ";
    cetakHimpunan(komplemenA);
    cout << "\nB' = ";
    cetakHimpunan(komplemenB);
    cout << "\n";
}

// Menampilkan power set dan jumlah anggotanya.
void himpunanKuasa(const Himpunan& himpunan, const string& nama) {
    vector<int> elemen(himpunan.begin(), himpunan.end());
    unsigned long long jumlah = 1;
    for (size_t i = 0; i < elemen.size(); ++i) {
        jumlah *= 2;
    }

    cout << "Jumlah anggota P(" << nama << ") = " << jumlah << "\n";
    if (elemen.size() > 10) {
        cout << "Peringatan: n > 10, anggota himpunan kuasa tidak dicetak.\n";
        return;
    }

    cout << "P(" << nama << ") = {";
    unsigned long long batas = jumlah;
    for (unsigned long long mask = 0; mask < batas; ++mask) {
        if (mask != 0) {
            cout << ", ";
        }
        cout << "{";
        bool anggotaPertama = true;
        for (size_t indeks = 0; indeks < elemen.size(); ++indeks) {
            if ((mask & (1ULL << indeks)) != 0) {
                if (!anggotaPertama) {
                    cout << ", ";
                }
                cout << elemen[indeks];
                anggotaPertama = false;
            }
        }
        cout << "}";
    }
    cout << "}\n";
}

// Menampilkan semua pasangan berurutan pada hasil kali kartesian A x B.
void kartesian(const Himpunan& a, const Himpunan& b) {
    cout << "A × B = {";
    bool pasanganPertama = true;
    for (int nilaiA : a) {
        for (int nilaiB : b) {
            if (!pasanganPertama) {
                cout << ", ";
            }
            cout << "(" << nilaiA << ", " << nilaiB << ")";
            pasanganPertama = false;
        }
    }
    cout << "}\n";
}

// Memeriksa relasi subset, kesamaan, dan saling lepas antarhimpunan.
void cekSubset(const Himpunan& a, const Himpunan& b) {
    bool aSubsetB = includes(b.begin(), b.end(), a.begin(), a.end());
    bool bSubsetA = includes(a.begin(), a.end(), b.begin(), b.end());
    bool disjoint = true;
    for (int nilai : a) {
        if (b.find(nilai) != b.end()) {
            disjoint = false;
            break;
        }
    }

    cout << "A subset B: " << (aSubsetB ? "ya" : "tidak") << "\n";
    cout << "B subset A: " << (bSubsetA ? "ya" : "tidak") << "\n";
    cout << "A sama dengan B: " << (a == b ? "ya" : "tidak") << "\n";
    cout << "A dan B saling lepas: " << (disjoint ? "ya" : "tidak") << "\n";
}

// Menampilkan kardinalitas dua himpunan.
void kardinalitas(const Himpunan& a, const Himpunan& b) {
    cout << "|A| = " << a.size() << "\n";
    cout << "|B| = " << b.size() << "\n";
}

// Menampilkan seluruh himpunan yang tersimpan.
void tampilkanSemua(const Himpunan& a, const Himpunan& b, const Himpunan& u,
                    bool aDiisi, bool bDiisi, bool uDiisi) {
    cout << "A = ";
    if (aDiisi) {
        cetakHimpunan(a);
    } else {
        cout << "(belum diisi)";
    }
    cout << "\nB = ";
    if (bDiisi) {
        cetakHimpunan(b);
    } else {
        cout << "(belum diisi)";
    }
    cout << "\nU = ";
    if (uDiisi) {
        cetakHimpunan(u);
    } else {
        cout << "(belum diisi)";
    }
    cout << "\n";
}

// Membaca pilihan menu dan mengubahnya menjadi angka menu yang valid.
int bacaPilihanMenu() {
    string teks;
    getline(cin, teks);
    if (teks.empty()) {
        return -1;
    }

    int pilihan = 0;
    for (char karakter : teks) {
        if (karakter < '0' || karakter > '9') {
            return -1;
        }
        pilihan = pilihan * 10 + (karakter - '0');
        if (pilihan > 12) {
            return -1;
        }
    }
    return pilihan;
}

// Menjalankan menu interaktif kalkulator himpunan.
int main() {
    Himpunan a;
    Himpunan b;
    Himpunan u;
    bool aDiisi = false;
    bool bDiisi = false;
    bool uDiisi = false;
    while (true) {
        bersihkanTerminal();
        cout << "\n=== KALKULATOR HIMPUNAN ===\n"
                  << "1. Input himpunan A dan B\n"
                  << "2. Input himpunan semesta U\n"
                  << "3. Gabungan (A union B)\n"
                  << "4. Irisan (A intersection B)\n"
                  << "5. Selisih (A-B dan B-A)\n"
                  << "6. Selisih simetris (A symmetric_difference B)\n"
                  << "7. Komplemen (A' dan B')\n"
                  << "8. Himpunan kuasa\n"
                  << "9. Hasil kali kartesian (A x B)\n"
                  << "10. Cek hubungan himpunan\n"
                  << "11. Kardinalitas\n"
                  << "12. Tampilkan himpunan saat ini\n"
                  << "0. Keluar\n"
                  << "Pilihan: ";
        switch (bacaPilihanMenu()) {
        case 0:
            cout << "Program selesai.\n";
            return 0;
        case 1:
            a = bacaHimpunan("Masukkan elemen A (kosongkan untuk {}): ");
            b = bacaHimpunan("Masukkan elemen B (kosongkan untuk {}): ");
            aDiisi = true;
            bDiisi = true;
            break;
        case 2:
            u = bacaHimpunan("Masukkan elemen U (kosongkan untuk {}): ");
            uDiisi = true;
            break;
        case 3:
            if (!aDiisi || !bDiisi) {
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            } else {
                gabungan(a, b);
            }
            break;
        case 4:
            if (!aDiisi || !bDiisi) {
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            } else {
                irisan(a, b);
            }
            break;
        case 5:
            if (!aDiisi || !bDiisi) {
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            } else {
                selisih(a, b);
            }
            break;
        case 6:
            if (!aDiisi || !bDiisi) {
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            } else {
                selisihSimetris(a, b);
            }
            break;
        case 9:
            if (!aDiisi || !bDiisi) {
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            } else {
                kartesian(a, b);
            }
            break;
        case 10:
            if (!aDiisi || !bDiisi) {
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            } else {
                cekSubset(a, b);
            }
            break;
        case 11:
            if (!aDiisi || !bDiisi) {
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
            } else {
                kardinalitas(a, b);
            }
            break;
        case 7:
            if (!aDiisi || !bDiisi || !uDiisi) {
                cout << "A, B, dan U harus diisi terlebih dahulu.\n";
            } else {
                bool aDiLuarU =
                    !includes(u.begin(), u.end(), a.begin(), a.end());
                bool bDiLuarU =
                    !includes(u.begin(), u.end(), b.begin(), b.end());
                if (aDiLuarU || bDiLuarU) {
                    cout << "Peringatan: ada elemen A atau B yang tidak ada di U.\n";
                }
                komplemen(a, b, u);
            }
            break;
        case 8: {
            if (!aDiisi || !bDiisi) {
                cout << "Himpunan A dan B harus diisi terlebih dahulu.\n";
                break;
            }
            string target;
            cout << "Pilih himpunan (A/B): ";
            getline(cin, target);
            if (target == "A" || target == "a") {
                himpunanKuasa(a, "A");
            } else if (target == "B" || target == "b") {
                himpunanKuasa(b, "B");
            } else {
                cout << "Pilihan himpunan tidak valid.\n";
            }
            break;
        }
        case 12:
            tampilkanSemua(a, b, u, aDiisi, bDiisi, uDiisi);
            break;
        default:
            cout << "Pilihan menu tidak valid.\n";
            break;
        }
        tungguEnter();
    }
}
