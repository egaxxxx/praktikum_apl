#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <map>

using namespace std;

const int MAX_DATA = 100;
const int MAX_SEWA = 10;

struct RiwayatSewa {
    string namaPenyewa;
    string durasi;
};

struct Kendaraan {
    string merk;
    string tipe;
    string nomor_polisi;
    double harga_sewa;
    string status;
    RiwayatSewa riwayatPenyewa[MAX_SEWA];
    int jumlahPenyewa = 0;
};

int validasiInputan(int min, int max) {
    int input;
    cin >> input;

    if (cin.fail() || input < min || input > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid! Masukkan angka antara " << min << " dan " << max << ": ";
        return validasiInputan(min, max); 
    }
    return input;
}

void Enter() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
}

void keluar() {
    cout << "Terima kasih telah menggunakan sistem.\n";
    Enter();
}

void Menu(bool isAdmin) {
    if (isAdmin) {
        cout << "|======================================|\n";
        cout << "| Sistem Pendataan Penyewaan Kendaraan |\n";
        cout << "|====|=================================|\n";
        cout << "| No |            Menu                 |\n";
        cout << "|====|=================================|\n";
        cout << "| 1  | Tambah Data Kendaraan           |\n";
        cout << "| 2  | Lihat Data Kendaraan            |\n";
        cout << "| 3  | Perbarui Data Kendaraan         |\n";
        cout << "| 4  | Hapus Data Kendaraan            |\n";
        cout << "| 5  | Lihat Riwayat Penyewaan         |\n";
        cout << "| 6  | Logout                          |\n";
        cout << "|====|=================================|\n";
    } else {
        cout << "|======================================|\n";
        cout << "| Sistem Pendataan Penyewaan Kendaraan |\n";
        cout << "|====|=================================|\n";
        cout << "| No |            Menu                 |\n";
        cout << "|====|=================================|\n";
        cout << "| 1  | Lihat Data Kendaraan            |\n";
        cout << "| 2  | Sewa Kendaraan                  |\n";
        cout << "| 3  | Lihat Riwayat Penyewaan Anda    |\n";
        cout << "| 4  | Logout                          |\n";
        cout << "|====|=================================|\n";
    }
}

void tambah(Kendaraan daftarKendaraan[], int& jumlahKendaraan) {
    if (jumlahKendaraan >= MAX_DATA) {
        cout << "\nData kendaraan sudah penuh! Tidak dapat menambah lagi.\n";
        Enter();
        return;
    }

    Kendaraan k;
    cin.ignore();
    cout << "Masukkan Merk Kendaraan: ";
    getline(cin, k.merk);
    cout << "Masukkan Tipe Kendaraan: ";
    getline(cin, k.tipe);
    cout << "Masukkan Nomor Polisi: ";
    getline(cin, k.nomor_polisi);
    
    do {
        cout << "Masukkan Harga Sewa per Hari: ";
        cin >> k.harga_sewa;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nHarga sewa tidak valid! Masukkan angka.\n";
            continue;
        }

        if (k.harga_sewa <= 0) {
            cout << "\nHarga sewa harus lebih dari 0!\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        break; 
    } while (true);

    k.status = "Tersedia";
    k.jumlahPenyewa = 0;

    daftarKendaraan[jumlahKendaraan] = k;
    jumlahKendaraan++;

    cout << "\nData kendaraan berhasil ditambahkan!\n";
    Enter();
}

void lihatKendaraan(const Kendaraan daftarKendaraan[], int jumlahKendaraan) {
    if (jumlahKendaraan == 0) {
        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
        Enter();
        return;
    }

    cout << "\n====================================== Data Kendaraan ===========================================\n";
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    cout << "| No |      Merk      |      Tipe      |  Nomor Polisi  |    Harga Sewa    |   Status           |\n";
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << "| " << setw(2) << i + 1 << "| " 
             << setw(15) << daftarKendaraan[i].merk << " | " 
             << setw(15) << daftarKendaraan[i].tipe << "| " 
             << setw(15) << daftarKendaraan[i].nomor_polisi << " | "
             << "Rp. " << setw(11) << fixed << setprecision(0) << daftarKendaraan[i].harga_sewa << " | " 
             << setw(10) << daftarKendaraan[i].status << "          |\n";
    }
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    Enter();
}


void lihatKendaraan(const Kendaraan daftarKendaraan[], int jumlahKendaraan, string status) {
    if (jumlahKendaraan == 0) {
        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
        Enter();
        return;
    }

    cout << "\n====================================== Data Kendaraan (" << status << ") ===========================================\n";
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    cout << "| No |      Merk      |      Tipe      |  Nomor Polisi  |    Harga Sewa    |   Status           |\n";
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    int count = 0;
    for (int i = 0; i < jumlahKendaraan; i++) {
        if (daftarKendaraan[i].status == status) {
            cout << "| " << setw(2) << ++count << "| " 
                 << setw(15) << daftarKendaraan[i].merk << " | " 
                 << setw(15) << daftarKendaraan[i].tipe << "| " 
                 << setw(15) << daftarKendaraan[i].nomor_polisi << " | "
                 << "Rp. " << setw(11) << fixed << setprecision(0) << daftarKendaraan[i].harga_sewa << " | " 
                 << setw(10) << daftarKendaraan[i].status << "          |\n";
        }
    }
    
    if (count == 0) {
        cout << "| Tidak ada kendaraan dengan status " << status << " saat ini.                                      |\n";
    }
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    Enter();
}

void sewa(Kendaraan daftarKendaraan[], int jumlahKendaraan, string nama) {
    if (jumlahKendaraan == 0) {
        cout << "\nTidak ada kendaraan yang tersedia untuk disewa.\n";
        Enter();
        return;
    }

    lihatKendaraan(daftarKendaraan, jumlahKendaraan);

    cout << "Masukkan nomor kendaraan yang ingin disewa: ";
    int nomor = validasiInputan(1, jumlahKendaraan) - 1;

    if (daftarKendaraan[nomor].status != "Tersedia") {
        cout << "\nKendaraan ini tidak tersedia untuk disewa.\n";
        Enter();
        return;
    }

    cout << "Masukkan durasi sewa (dalam hari): ";
    string durasi;
    cin >> durasi;

    daftarKendaraan[nomor].status = "Disewa";
    daftarKendaraan[nomor].riwayatPenyewa[daftarKendaraan[nomor].jumlahPenyewa].namaPenyewa = nama;
    daftarKendaraan[nomor].riwayatPenyewa[daftarKendaraan[nomor].jumlahPenyewa].durasi = durasi;
    daftarKendaraan[nomor].jumlahPenyewa++;

    cout << "\nKendaraan berhasil disewa.\n";
    Enter();
}

void lihatRiwayatUser(const Kendaraan daftarKendaraan[], int jumlahKendaraan, string nama) {
    cout << "|========================================================|\n";
    cout << "|               Riwayat Penyewaan Anda                   |\n";
    cout << "|========================================================|\n";
    cout << "| No |      Merk      |      Tipe      |  Durasi (hari)  |\n";
    cout << "|========================================================|\n";

    bool adaRiwayat = false; 
    for (int i = 0; i < jumlahKendaraan; i++) {
        for (int j = 0; j < daftarKendaraan[i].jumlahPenyewa; j++) {
            if (daftarKendaraan[i].riwayatPenyewa[j].namaPenyewa == nama) {
                cout << "| " << setw(2) << i + 1 << " | " 
                     << setw(15) << daftarKendaraan[i].merk << " | " 
                     << setw(15) << daftarKendaraan[i].tipe << " | " 
                     << setw(15) << daftarKendaraan[i].riwayatPenyewa[j].durasi << " |\n";
                adaRiwayat = true;
            }
        }
    }

    if (!adaRiwayat) {
        cout << "| Tidak ada riwayat penyewaan untuk Anda.             |\n";
    }

    cout << "===========================================================\n";
    Enter();
}

void lihatRiwayat(const Kendaraan daftarKendaraan[], int jumlahKendaraan) {
    if (jumlahKendaraan == 0) {
        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
        Enter();
        return;
    }

    cout << "|=========================================================================|\n";
    cout << "| No |      Merk      |      Tipe      |  Penyewa       |  Durasi (hari)  |\n";
    cout << "|=========================================================================|\n";

    bool adaRiwayat = false; 

    for (int i = 0; i < jumlahKendaraan; i++) {
        for (int j = 0; j < daftarKendaraan[i].jumlahPenyewa; j++) {
            cout << "| " << setw(2) << i + 1 << " | " 
                 << setw(15) << daftarKendaraan[i].merk << " | " 
                 << setw(15) << daftarKendaraan[i].tipe << " | " 
                 << setw(15) << daftarKendaraan[i].riwayatPenyewa[j].namaPenyewa << " | " 
                 << setw(15) << daftarKendaraan[i].riwayatPenyewa[j].durasi << " |\n";
            adaRiwayat = true;
        }
    }

    if (!adaRiwayat) {
        cout << "| Tidak ada riwayat penyewaan.                                       |\n";
    }

    cout << "==========================================================================\n";
    Enter(); 
}

void perbarui(Kendaraan daftarKendaraan[], int jumlahKendaraan) {
    if (jumlahKendaraan == 0) {
        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
        Enter();
        return;
    }

    lihatKendaraan(daftarKendaraan, jumlahKendaraan);

    cout << "Masukkan nomor kendaraan yang ingin diperbarui (atau 0 untuk kembali): ";
    int nomor = validasiInputan(0, jumlahKendaraan);

    if (nomor == 0) {
        cout << "Kembali ke menu admin...\n";
        Enter();
        return;
    }

    nomor--; 

    bool kembaliKeMenu = false;
    do {
        cout << "\n======================================\n";
        cout << "| Pilih Data yang Ingin Diperbarui   |\n";
        cout << "|====================================|\n";
        cout << "| 1. Perbarui Merk                   |\n";
        cout << "| 2. Perbarui Tipe                   |\n";
        cout << "| 3. Perbarui Nomor Polisi           |\n";
        cout << "| 4. Perbarui Harga Sewa             |\n";
        cout << "| 5. Kembali                         |\n";
        cout << "======================================\n";
        cout << "Pilih opsi: ";
        int pilihan = validasiInputan(1, 5);

        switch (pilihan) {
            case 1: {
                cout << "Masukkan Merk Kendaraan Baru: ";
                cin.ignore();
                getline(cin, daftarKendaraan[nomor].merk);
                cout << "Merk kendaraan berhasil diperbarui!\n";
                break;
            }
            case 2: {
                cout << "Masukkan Tipe Kendaraan Baru: ";
                cin.ignore();
                getline(cin, daftarKendaraan[nomor].tipe);
                cout << "Tipe kendaraan berhasil diperbarui!\n";
                break;
            }
            case 3: {
                cout << "Masukkan Nomor Polisi Baru: ";
                cin.ignore();
                getline(cin, daftarKendaraan[nomor].nomor_polisi);
                cout << "Nomor polisi kendaraan berhasil diperbarui!\n";
                break;
            }
            case 4: {
                cout << "Masukkan Harga Sewa Baru: ";
                cin >> daftarKendaraan[nomor].harga_sewa;
                if (cin.fail() || daftarKendaraan[nomor].harga_sewa <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nHarga sewa tidak valid! Perubahan dibatalkan.\n";
                } else {
                    cout << "Harga sewa kendaraan berhasil diperbarui!\n";
                }
                break;
            }
            case 5: {
                kembaliKeMenu = true; 
                break;
            }
            default: {
                cout << "Pilihan tidak valid!\n";
                break;
            }
        }

        if (!kembaliKeMenu) {
            Enter();
        }
    } while (!kembaliKeMenu);

    cout << "Kembali ke menu admin...\n";
    Enter();
}

void hapus(Kendaraan daftarKendaraan[], int& jumlahKendaraan) {
    if (jumlahKendaraan == 0) {
        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
        Enter();
        return;
    }

    lihatKendaraan(daftarKendaraan, jumlahKendaraan);

    cout << "Masukkan nomor kendaraan yang ingin dihapus (atau 0 untuk kembali): ";
    int nomor = validasiInputan(0, jumlahKendaraan);

    if (nomor == 0) {
        cout << "Kembali ke menu admin...\n";
        Enter();
        return;
    }

    nomor--; 

    for (int i = nomor; i < jumlahKendaraan - 1; i++) {
        daftarKendaraan[i] = daftarKendaraan[i + 1];
    }
    jumlahKendaraan--; 

    cout << "\nData kendaraan berhasil dihapus!\n";
    Enter();
}

void registerUser(map<string, string>& pengguna) {
    string nama, password;

    cout << "Masukkan username baru: ";
    cin >> nama;

    if (pengguna.find(nama) != pengguna.end()) {
        cout << "username sudah terdaftar! Gunakan nama lain.\n";
        Enter();
        return;
    }

    cout << "Masukkan password baru: ";
    cin >> password;

    pengguna[nama] = password;

    cout << "Registrasi berhasil!\n";
    Enter();
}

bool loginUser(map<string, string>& pengguna, string& nama, string& password, bool& isAdmin) {
    int percobaan = 0; 
    while (percobaan < 3) {
        system("cls"); 
        cout << "|======================================|\n";
        cout << "|          Login ke Sistem             |\n";
        cout << "|======================================|\n";
        cout << "Masukkan username: ";
        cin >> nama;
        cout << "Masukkan password: ";
        cin >> password;

        if (nama == "EgaClearestaHananta" && password == "2409106088") {
            isAdmin = true;
            cout << "Login sebagai admin berhasil!\n";
            return true;
        } else if (pengguna.find(nama) != pengguna.end() && pengguna[nama] == password) {
            isAdmin = false;
            cout << "Login berhasil!\n";
            return true;
        } else {
            percobaan++;
            cout << "username atau password salah! Percobaan ke-" << percobaan << " dari 3.\n";
            Enter();
        }
    }

    cout << "Anda telah salah memasukkan username atau password sebanyak 3 kali. Program berhenti.\n";
    Enter();
    return false;
}

int main() {
    Kendaraan daftarKendaraan[MAX_DATA];
    int jumlahKendaraan = 0;
    map<string, string> pengguna;
    string nama, password;
    bool login = false, isAdmin = false;

    while (true) {
        do {
            system("cls");
            cout << "|======================================|\n";
            cout << "| Sistem Pendataan Penyewaan Kendaraan |\n";
            cout << "|====|=================================|\n";
            cout << "| No |            Menu                 |\n";
            cout << "|====|=================================|\n";
            cout << "| 1  | Register                        |\n";
            cout << "| 2  | Login                           |\n";
            cout << "| 3  | Keluar                          |\n";
            cout << "|====|=================================|\n";
            cout << "Pilih menu: ";
            int pilihan = validasiInputan(1, 3);

            switch (pilihan) {
                case 1:
                    registerUser(pengguna); 
                    break;
                case 2:
                    login = loginUser(pengguna, nama, password, isAdmin); 
                    break;
                case 3:
                    keluar(); 
                    return 0;
            }
        } while (!login);

        do {
            system("cls"); 
            Menu(isAdmin); 
            cout << "Pilih menu: ";
            int pilihan = validasiInputan(1, isAdmin ? 6 : 4);

            if (isAdmin) {
                switch (pilihan) {
                    case 1: 
                        tambah(daftarKendaraan, jumlahKendaraan); break;
                    case 2: 
                        lihatKendaraan(daftarKendaraan, jumlahKendaraan); break;
                    case 3: 
                        perbarui(daftarKendaraan, jumlahKendaraan); break;
                    case 4: 
                        hapus(daftarKendaraan, jumlahKendaraan); break;
                    case 5: 
                        lihatRiwayat(daftarKendaraan, jumlahKendaraan); break;
                    case 6: 
                        login = false; 
                        cout << "Anda telah logout. Kembali ke menu awal...\n";
                        Enter();
                        break;
                }
            } else {
                switch (pilihan) {
                    case 1: 
                        lihatKendaraan(daftarKendaraan, jumlahKendaraan); break;
                    case 2: 
                        sewa(daftarKendaraan, jumlahKendaraan, nama); break;
                    case 3: 
                        lihatRiwayatUser(daftarKendaraan, jumlahKendaraan, nama); break;
                    case 4: 
                        login = false; 
                        cout << "Anda telah logout. Kembali ke menu awal...\n";
                        Enter();
                        break;
                }
            }
        } while (login);
    }

    return 0;
}
