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
    cout << "Terima kasih telah menggunakan sistem.";
    Enter();
}

void ubahHargaSewa(double &harga, double hargaBaru) {
    harga = hargaBaru; 
}

void tampilkanHargaSewa(double *harga) {
    cout << "Harga Sewa: Rp " << fixed << setprecision(0) << *harga << endl;
}

void tambah(Kendaraan daftarKendaraan[], int &jumlahKendaraan) {
    system("cls");
    if (jumlahKendaraan >= MAX_DATA) {
        cout << "Data kendaraan sudah penuh! Tidak dapat menambah lagi." << endl;
        Enter();
        return;
    }

    Kendaraan k;
    cin.ignore();
    cout << "================================ Tambah Data Kendaraan ===============================\n";
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
            cout << "Harga sewa tidak valid! Masukkan angka." << endl;
            continue;
        }
        if (k.harga_sewa <= 0) {
            cout << "Harga sewa harus lebih dari 0!" << endl;
            continue;
        }
        break;
    } while (true);

    k.status = "Tersedia";
    k.jumlahPenyewa = 0;
    daftarKendaraan[jumlahKendaraan] = k;
    jumlahKendaraan++;
    cout << "Data kendaraan berhasil ditambahkan!" << endl;
    Enter();
}

void lihatKendaraan(const Kendaraan daftarKendaraan[], int jumlahKendaraan) {
    system("cls");
    if (jumlahKendaraan == 0) {
        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
        Enter();
        return;
    }

    cout << "\n====================================== Data Kendaraan ===========================================\n";
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    cout << "| No |      Merk      |      Tipe      |  Nomor Polisi  |    Harga Sewa    |      Status        |\n";
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    
    for (int i = 0; i < jumlahKendaraan; i++) {
        cout << "| " << setw(2) << i + 1 << " | " 
             << setw(14) << daftarKendaraan[i].merk << " | " 
             << setw(14) << daftarKendaraan[i].tipe << " | " 
             << setw(14) << daftarKendaraan[i].nomor_polisi << " | "
             << "Rp " << setw(12) << fixed << setprecision(0) << daftarKendaraan[i].harga_sewa << " | "
             << setw(15) << daftarKendaraan[i].status << "     |\n";
    }
    
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    Enter();
}

void lihatKendaraan(const Kendaraan daftarKendaraan[], int jumlahKendaraan, string status) {
    system("cls");
    if (jumlahKendaraan == 0) {
        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
        Enter();
        return;
    }

    cout << "\n====================================== Data Kendaraan (" << status << ") ============================\n";
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    cout << "| No |      Merk      |      Tipe      |  Nomor Polisi  |    Harga Sewa    |      Status        |\n";
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    
    int count = 0;
    for (int i = 0; i < jumlahKendaraan; i++) {
        if (daftarKendaraan[i].status == status) {
            cout << "| " << setw(2) << ++count << " | " 
                 << setw(14) << daftarKendaraan[i].merk << " | " 
                 << setw(14) << daftarKendaraan[i].tipe << " | " 
                 << setw(14) << daftarKendaraan[i].nomor_polisi << " | "
                 << "Rp " << setw(12) << fixed << setprecision(0) << daftarKendaraan[i].harga_sewa << " | "
                 << setw(15) << daftarKendaraan[i].status << " |\n";
        }
    }
    
    if (count == 0) {
        cout << "| Tidak ada kendaraan dengan status " << setw(62) << left << status << " |\n";
    }
    
    cout << "|-----------------------------------------------------------------------------------------------|\n";
    Enter();
}

void perbarui(Kendaraan daftarKendaraan[], int jumlahKendaraan) {
    system("cls");
    if (jumlahKendaraan == 0) {
        cout << "\nBelum ada data kendaraan untuk diperbarui!\n";
        Enter();
        return;
    }

    lihatKendaraan(daftarKendaraan, jumlahKendaraan);
    cout << "Masukkan nomor kendaraan yang ingin diperbarui: ";
    int nomor = validasiInputan(1, jumlahKendaraan) - 1;
    system("cls");

    cout << "\n=========== Detail Kendaraan Terpilih ===========\n";
    cout << "|---------------------------------------------|\n";
    cout << "| Merk         : " << setw(30) << left << daftarKendaraan[nomor].merk <<"|\n";
    cout << "| Tipe         : " << setw(30) << left << daftarKendaraan[nomor].tipe <<"|\n";
    cout << "| Nomor Polisi : " << setw(30) << left << daftarKendaraan[nomor].nomor_polisi <<"|\n";
    cout << "| Harga Sewa   : Rp " << setw(27) << left << fixed << setprecision(2) << daftarKendaraan[nomor].harga_sewa <<"|\n";
    cout << "| Status       : " << setw(30) << left << daftarKendaraan[nomor].status << "|\n";
    cout << "|---------------------------------------------|\n";

    bool kembaliKeMenu = false;
    do {
        cout << "\n============= Menu Perbarui Data =============\n";
        cout << "|---------------------------------------------|\n";
        cout << "| No |            Pilihan Menu                |\n";
        cout << "|----|----------------------------------------|\n";
        cout << "| 1  | Perbarui Merk                          |\n";
        cout << "| 2  | Perbarui Tipe                          |\n";
        cout << "| 3  | Perbarui Nomor Polisi                  |\n";
        cout << "| 4  | Perbarui Harga Sewa                    |\n";
        cout << "| 5  | Kembali ke Menu Utama                  |\n";
        cout << "|---------------------------------------------|\n";
        cout << "Pilih opsi: ";
        int pilihan = validasiInputan(1, 5);

        switch (pilihan) {
            case 1: {
                cout << "\n--------------- Perbarui Merk ---------------\n";
                cout << "Merk Lama     : " << daftarKendaraan[nomor].merk << endl;
                cout << "Masukkan Merk Baru: ";
                cin.ignore();
                getline(cin, daftarKendaraan[nomor].merk);
                cout << "\nMerk kendaraan berhasil diperbarui!\n";
                break;
            }
            case 2: {
                cout << "\n--------------- Perbarui Tipe ---------------\n";
                cout << "Tipe Lama     : " << daftarKendaraan[nomor].tipe << endl;
                cout << "Masukkan Tipe Baru: ";
                cin.ignore();
                getline(cin, daftarKendaraan[nomor].tipe);
                cout << "\nTipe kendaraan berhasil diperbarui!\n";
                break;
            }
            case 3: {
                cout << "\n------------ Perbarui Nomor Polisi ----------\n";
                cout << "Nomor Polisi Lama: " << daftarKendaraan[nomor].nomor_polisi << endl;
                cout << "Masukkan Nomor Polisi Baru: ";
                cin.ignore();
                getline(cin, daftarKendaraan[nomor].nomor_polisi);
                cout << "\nNomor polisi kendaraan berhasil diperbarui!\n";
                break;
            }
            case 4: {
                cout << "\n------------- Perbarui Harga Sewa -----------\n";
                cout << "Harga Sewa Lama: Rp" << fixed << setprecision(2) << daftarKendaraan[nomor].harga_sewa << endl;
                cout << "Masukkan Harga Sewa Baru: Rp";
                double hargaBaru;
                cin >> hargaBaru;
                ubahHargaSewa(daftarKendaraan[nomor].harga_sewa, hargaBaru);
                tampilkanHargaSewa(&daftarKendaraan[nomor].harga_sewa);
                cout << "\nHarga sewa kendaraan berhasil diperbarui!\n";
                break;
            }
            case 5: {
                kembaliKeMenu = true;
                break;
            }
        }

        if (!kembaliKeMenu) {
            Enter();
        }
    } while (!kembaliKeMenu);

    cout << "\nKembali ke menu admin...\n";
    Enter();
}

void hapus(Kendaraan daftarKendaraan[], int &jumlahKendaraan) {
    system("cls");
    if (jumlahKendaraan == 0) {
        cout << "\n|==============================================|\n";
        cout << "|    Belum ada data kendaraan yang tersimpan!  |\n";
        cout << "|==============================================|\n";
        Enter();
        return;
    }

    lihatKendaraan(daftarKendaraan, jumlahKendaraan);
    cout << "\n|==============================================|\n";
    cout << "|            Hapus Data Kendaraan              |\n";
    cout << "|==============================================|\n";
    cout << "Masukkan nomor kendaraan yang ingin dihapus (0 untuk kembali): ";
    int nomor = validasiInputan(0, jumlahKendaraan);

    if (nomor == 0) {
        system("cls");
        cout << "\n|==============================================|\n";
        cout << "|          Kembali ke menu utama...            |\n";
        cout << "|==============================================|\n";
        Enter();
        return;
    }

    nomor--; 

    cout << "\n========== Detail Kendaraan yang Akan Dihapus ==========\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "| Merk         : " << setw(35) << left << daftarKendaraan[nomor].merk << "|\n";
    cout << "| Tipe         : " << setw(35) << left << daftarKendaraan[nomor].tipe << "|\n";
    cout << "| Nomor Polisi : " << setw(35) << left << daftarKendaraan[nomor].nomor_polisi << "|\n";
    cout << "| Harga Sewa   : Rp " << setw(32) << left << fixed << setprecision(2) << daftarKendaraan[nomor].harga_sewa << "|\n";
    cout << "| Status       : " << setw(35) << left << daftarKendaraan[nomor].status << "|\n";
    cout << "|-----------------------------------------------------|\n";

    cout << "\nApakah Anda yakin ingin menghapus data ini? (y/n): ";
    char konfirmasi;
    cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        for (int i = nomor; i < jumlahKendaraan - 1; i++) {
            daftarKendaraan[i] = daftarKendaraan[i + 1];
        }
        jumlahKendaraan--;

        cout << "\n|==============================================|\n";
        cout << "|       Data kendaraan berhasil dihapus!       |\n";
        cout << "|==============================================|\n";
    } else {
        cout << "\n|==============================================|\n";
        cout << "|         Penghapusan data dibatalkan!         |\n";
        cout << "|==============================================|\n";
    }
    
    Enter();
}

void sewa(Kendaraan daftarKendaraan[], int jumlahKendaraan, string nama) {
    system("cls");
    if (jumlahKendaraan == 0) {
        cout << "Belum ada data kendaraan yang tersedia untuk disewa!" << endl;
        Enter();
        return;
    }

    lihatKendaraan(daftarKendaraan, jumlahKendaraan);
    cout << "Masukkan nomor kendaraan yang ingin disewa: ";
    int nomor = validasiInputan(1, jumlahKendaraan) - 1;

    if (daftarKendaraan[nomor].status != "Tersedia") {
        cout << "Kendaraan ini tidak tersedia untuk disewa!" << endl;
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

    cout << "Kendaraan berhasil disewa!" << endl;
    Enter();
}

void lihatRiwayatUser(const Kendaraan daftarKendaraan[], int jumlahKendaraan, string nama, bool isAdmin = false) {
    system("cls");
    cout << "\n|=================================================================|\n";
    cout << "|                     Riwayat Penyewaan " << (isAdmin ? "Semua User" : "Anda") << "                |\n";
    cout << "|=================================================================|\n";
    cout << "| No |  Penyewa  |    Merk     |    Tipe     |  Durasi  | Status  |\n";
    cout << "|-----------------------------------------------------------------|\n";

    bool adaRiwayat = false;
    int count = 0;

    for (int i = 0; i < jumlahKendaraan; i++) {
        for (int j = 0; j < daftarKendaraan[i].jumlahPenyewa; j++) {
            if (isAdmin || daftarKendaraan[i].riwayatPenyewa[j].namaPenyewa == nama) {
                cout << "| " << setw(2) << ++count << " | "
                     << setw(9) << daftarKendaraan[i].riwayatPenyewa[j].namaPenyewa << " | "
                     << setw(11) << daftarKendaraan[i].merk << " | "
                     << setw(11) << daftarKendaraan[i].tipe << " | "
                     << setw(8) << daftarKendaraan[i].riwayatPenyewa[j].durasi + " Hari" << " | "
                     << setw(7) << daftarKendaraan[i].status << " |\n";
                adaRiwayat = true;
            }
        }
    }

    if (!adaRiwayat) {
        cout << "|                                                                 |\n";
        cout << "|                Belum ada riwayat penyewaan!                     |\n";
        cout << "|                                                                 |\n";
    }

    cout << "|=================================================================|\n";
    if (adaRiwayat) {
        cout << "| Total Riwayat: " << setw(47) << left << count << "  |\n";
        cout << "|=================================================================|\n";
    }
    Enter();
}

void Menu(bool isAdmin) {
    system("cls");
    if (isAdmin) {
        cout << "|======================================|" << endl;
        cout << "| Sistem Pendataan Penyewaan Kendaraan |" << endl;
        cout << "|======================================|" << endl;
        cout << "| No | Menu                            |" << endl;
        cout << "|====|=================================|" << endl;
        cout << "| 1  | Tambah Data Kendaraan           |" << endl;
        cout << "| 2  | Tampilkan Data Kendaraan        |" << endl;
        cout << "| 3  | Perbarui Data Kendaraan         |" << endl;
        cout << "| 4  | Hapus Data Kendaraan            |" << endl;
        cout << "| 5  | Lihat Riwayat Penyewaan         |" << endl;
        cout << "| 6  | Logout                          |" << endl;
        cout << "|======================================|" << endl;
    } else {
        cout << "|======================================|" << endl;
        cout << "| Sistem Pendataan Penyewaan Kendaraan |" << endl;
        cout << "|======================================|" << endl;
        cout << "| No | Menu                            |" << endl;
        cout << "|====|=================================|" << endl;
        cout << "| 1  | Lihat Data Kendaraan            |" << endl;
        cout << "| 2  | Sewa Kendaraan                  |" << endl;
        cout << "| 3  | Lihat Riwayat Penyewaan Anda    |" << endl;
        cout << "| 4  | Logout                          |" << endl;
        cout << "|======================================|" << endl;
    }
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

void registerUser(map<string, string>& pengguna) {
    system("cls");
    string nama, password;
    
    cout << "\n|======================================|\n";
    cout << "|            Register Akun             |\n";
    cout << "|======================================|\n";
    cout << "Masukkan username baru: ";
    cin >> nama;

    if (pengguna.find(nama) != pengguna.end()) {
        cout << "\n|======================================|\n";
        cout << "|    Username sudah terdaftar!          |\n";
        cout << "|    Silahkan gunakan username lain     |\n";
        cout << "|=======================================|\n";
        Enter();
        return;  
    }

    cout << "Masukkan password baru: ";
    cin >> password;

    pengguna[nama] = password;

    cout << "\n|======================================|\n";
    cout << "|         Registrasi Berhasil!         |\n";
    cout << "|     Silahkan login untuk masuk       |\n";
    cout << "|======================================|\n";
    Enter();
}

int main() {
    Kendaraan daftarKendaraan[MAX_DATA];
    int jumlahKendaraan = 0;
    map<string, string> pengguna;
    string nama, password;
    bool isAdmin = false;
    bool login = false;

    pengguna["user1"] = "password1";
    pengguna["user2"] = "password2";

    while (true) {
        system("cls");
        cout << "|======================================|\n";
        cout << "| Sistem Pendataan Penyewaan Kendaraan |\n";
        cout << "|====|=================================|\n";
        cout << "| 1  | Login                           |\n";
        cout << "| 2  | Register                        |\n";
        cout << "| 3  | Keluar                          |\n";
        cout << "|====|=================================|\n";
        cout << "Pilihan: ";
        
        int pilihan = validasiInputan(1, 3);
        
        switch (pilihan) {
            case 1:
                login = loginUser(pengguna, nama, password, isAdmin);
                break;
            case 2:
                registerUser(pengguna);
                continue;  
            case 3:
                keluar();
                return 0;
        }

        if (login) {
            string namaPengguna = nama;
            int pilihanMenu;
            bool loginState = true;
            do {
                Menu(isAdmin);
                cout << "Pilihan: ";
                pilihanMenu = validasiInputan(1, isAdmin ? 6 : 4);

                if (isAdmin) {
                    switch (pilihanMenu) {
                        case 1:
                            tambah(daftarKendaraan, jumlahKendaraan);
                            break;
                        case 2:
                            lihatKendaraan(daftarKendaraan, jumlahKendaraan);
                            break;
                        case 3:
                            perbarui(daftarKendaraan, jumlahKendaraan);
                            break;
                        case 4:
                            hapus(daftarKendaraan, jumlahKendaraan);
                            break;
                        case 5:
                            lihatRiwayatUser(daftarKendaraan, jumlahKendaraan, namaPengguna, isAdmin);
                            break;
                        case 6:
                            loginState = false;
                            cout << "Anda telah logout. Kembali ke menu awal..." << endl;
                            Enter();
                            break;
                    }
                } else {
                    switch (pilihanMenu) {
                        case 1:
                            lihatKendaraan(daftarKendaraan, jumlahKendaraan);
                            break;
                        case 2:
                            sewa(daftarKendaraan, jumlahKendaraan, namaPengguna);
                            break;
                        case 3:
                            lihatRiwayatUser(daftarKendaraan, jumlahKendaraan, namaPengguna);
                            break;
                        case 4:
                            loginState = false;
                            cout << "Anda telah logout. Kembali ke menu awal..." << endl;
                            Enter();
                            break;
                    }
                }
            } while (loginState);
        }
    }

    return 0;
}