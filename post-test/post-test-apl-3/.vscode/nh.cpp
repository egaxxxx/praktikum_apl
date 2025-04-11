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

int main() {
    Kendaraan daftarKendaraan[MAX_DATA];
    int jumlahKendaraan = 0;
    map<string, string> pengguna;
    
    string nama, password;
    int kesempatan = 3;
    bool login = false;
    bool isAdmin = false;

start_menu:
    int menuAwal;
    do {
        //system("cls");
        cout << "======================================\n";
        cout << "|      Sistem Penyewaan Kendaraan    |\n";
        cout << "======================================\n";
        cout << "| 1. Register                        |\n";
        cout << "| 2. Login                           |\n";
        cout << "| 3. Keluar                          |\n";
        cout << "======================================\n";
        cout << "Pilih menu: ";
        cin >> menuAwal;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInput tidak valid! Harus angka.\n";
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
            continue;
        }

        if (menuAwal == 1) {
            ////system("cls");
            string username, password;
            cout << "==============================================\n";
            cout << "|               Menu Register                |\n";
            cout << "==============================================\n";
            cout << "| Masukkan Username: ";
            cin.ignore();
            getline(cin, username);
            if (pengguna.find(username) != pengguna.end()) {
                cout << "================================================\n";
                cout << "\nUsername sudah terdaftar! Silakan gunakan username lain.\n";
                cout << "Tekan Enter untuk melanjutkan...";
                cin.get();
                continue;
            }
            cout << "| Masukkan Password: ";
            getline(cin, password);
            pengguna[username] = password;
            cout << "\nRegistrasi berhasil! Silakan login.\n";
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        } else if (menuAwal == 2) {
            break;
        } else if (menuAwal == 3) {
            cout << "\nTerima kasih telah menggunakan program ini!\n";
            return 0;
        } else {
            cout << "\nPilihan tidak valid! Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
    } while (menuAwal != 2);

    while (kesempatan > 0 && !login) {
        //system("cls");
        cout << "============================================\n";
        cout << "|                Menu Login                |\n";
        cout << "============================================\n";
        cout << "| Masukkan Username: ";
        cin.ignore(cin.peek() == '\n' ? 1 : 0, '\n');
        getline(cin, nama);
        cout << "| Masukkan Password: ";
        getline(cin, password);
        cout << "===========================================\n";

        if (nama == "EgaClearestaHananta" && password == "2409106088") {
            login = true;
            isAdmin = true;
            cout << "\nLogin berhasil sebagai Admin! Tekan Enter untuk melanjutkan...";
            cin.get();
            break;
        }

        if (pengguna.find(nama) != pengguna.end() && pengguna[nama] == password) {
            login = true;
            isAdmin = false;
            cout << "\nLogin berhasil sebagai Pengguna! Tekan Enter untuk melanjutkan...";
            cin.get();
            break;
        }

        kesempatan--;
        cout << "\nLogin gagal! Sisa percobaan: " << kesempatan << "\n";
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
    }

    if (!login) {
        cout << "\nTerlalu banyak percobaan gagal. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    do {
        //system("cls");
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
            cout << "Pilih menu: ";
            cin >> pilihan;

            if (cin.fail() || pilihan < 1 || pilihan > 6) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPilihan tidak valid! Tekan Enter untuk melanjutkan...";
                cin.get();
                continue;
            }

            switch (pilihan) {
                case 1: {
                    if (jumlahKendaraan >= MAX_DATA) {
                        cout << "\nData kendaraan sudah penuh! Tidak dapat menambah lagi.\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    Kendaraan k;
                    cout << "\n=== Tambah Data Kendaraan ===\n";
                    cin.ignore();
                    cout << "Masukkan Merk Kendaraan: ";
                    getline(cin, k.merk);
                    cout << "Masukkan Tipe Kendaraan: ";
                    getline(cin, k.tipe);
                    cout << "Masukkan Nomor Polisi: ";
                    getline(cin, k.nomor_polisi);
                    cout << "Masukkan Harga Sewa per Hari: ";
                    cin >> k.harga_sewa;

                    if (cin.fail() || k.harga_sewa <= 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nHarga sewa tidak valid! Harus lebih dari 0.\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    k.status = "Tersedia";
                    k.jumlahPenyewa = 0;

                    daftarKendaraan[jumlahKendaraan] = k;
                    jumlahKendaraan++;

                    cout << "\nData kendaraan berhasil ditambahkan!\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                case 2: {
                    if (jumlahKendaraan == 0) {
                        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    cout << "\n====================================== Data Kendaraan ===========================================\n";
                    cout << "|-----------------------------------------------------------------------------------------------|\n";
                    cout << "| No |      Merk      |      Tipe      |  Nomor Polisi  |    Harga Sewa    |   Status           |\n";
                    cout << "|-----------------------------------------------------------------------------------------------|\n";

                    for (int i = 0; i < jumlahKendaraan; i++) {
                        cout << "| " << setw(2) << i+1 << "| " 
                             << setw(15) << daftarKendaraan[i].merk << " | " 
                             << setw(15) << daftarKendaraan[i].tipe << "| " 
                             << setw(15) << daftarKendaraan[i].nomor_polisi << " | "
                             << "Rp. " << setw(11) << fixed << setprecision(0) << daftarKendaraan[i].harga_sewa << " | " 
                             << setw(10) << daftarKendaraan[i].status << "         |\n";
                    }
                    cout << "|-----------------------------------------------------------------------------------------------|\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                case 3: {
                    if (jumlahKendaraan == 0) {
                        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    cout << "\n====================================== Data Kendaraan ===========================================\n";
                    cout << "|-----------------------------------------------------------------------------------------------|\n";
                    cout << "| No |      Merk      |      Tipe      |  Nomor Polisi  |    Harga Sewa    |   Status           |\n";
                    cout << "|-----------------------------------------------------------------------------------------------|\n";
                    for (int i = 0; i < jumlahKendaraan; i++) {
                        cout << "| " << setw(2) << i+1 << "| " 
                             << setw(15) << daftarKendaraan[i].merk << " | " 
                             << setw(15) << daftarKendaraan[i].tipe << "| " 
                             << setw(15) << daftarKendaraan[i].nomor_polisi << " | "
                             << "Rp. " << setw(11) << fixed << setprecision(0) << daftarKendaraan[i].harga_sewa << " | " 
                             << setw(10) << daftarKendaraan[i].status << "          |\n";
                    }
                    cout << "|-----------------------------------------------------------------------------------------------|\n";
                    int indeks;
                    cout << "Masukkan nomor kendaraan yang akan diperbarui: ";
                    cin >> indeks;

                    if (cin.fail() || indeks < 1 || indeks > jumlahKendaraan) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nNomor kendaraan tidak valid!\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    indeks--;

                    cout << "\n=== Perbarui Data Kendaraan ===\n";
                    cout << "Data saat ini:\n";
                    cout << "Merk: " << daftarKendaraan[indeks].merk << endl;
                    cout << "Tipe: " << daftarKendaraan[indeks].tipe << endl;
                    cout << "Nomor Polisi: " << daftarKendaraan[indeks].nomor_polisi << endl;
                    cout << "Harga Sewa: Rp. " << fixed << setprecision(0) << daftarKendaraan[indeks].harga_sewa << endl;
                    cout << "Status: " << daftarKendaraan[indeks].status << endl;

                    bool updateMenu = true;
                    while (updateMenu) {
                        cout << "\nPilih data yang ingin diperbarui:\n";
                        cout << "1. Merk\n";
                        cout << "2. Tipe\n";
                        cout << "3. Nomor Polisi\n";
                        cout << "4. Harga Sewa\n";
                        cout << "5. Logout\n";
                        cout << "Pilihan: ";
                        int pilihanUpdate;
                        cin >> pilihanUpdate;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nPilihan tidak valid!\n";
                            cout << "Tekan Enter untuk melanjutkan...";
                            cin.get();
                            continue;
                        }

                        cin.ignore();
                        switch(pilihanUpdate) {
                            case 1: {
                                cout << "\nMasukkan Merk Kendaraan baru: ";
                                string merk;
                                getline(cin, merk);
                                if (!merk.empty()) {
                                    daftarKendaraan[indeks].merk = merk;
                                    cout << "\nMerk kendaraan berhasil diperbarui!\n";
                                } else {
                                    cout << "\nPembaruan dibatalkan karena input kosong.\n";
                                }
                                cout << "Tekan Enter untuk melanjutkan...";
                                cin.get();
                                break;
                            }
                            case 2: {
                                cout << "\nMasukkan Tipe Kendaraan baru: ";
                                string tipe;
                                getline(cin, tipe);
                                if (!tipe.empty()) {
                                    daftarKendaraan[indeks].tipe = tipe;
                                    cout << "\nTipe kendaraan berhasil diperbarui!\n";
                                } else {
                                    cout << "\nPembaruan dibatalkan karena input kosong.\n";
                                }
                                cout << "Tekan Enter untuk melanjutkan...";
                                cin.get();
                                break;
                            }
                            case 3: {
                                cout << "\nMasukkan Nomor Polisi baru: ";
                                string nopol;
                                getline(cin, nopol);
                                if (!nopol.empty()) {
                                    daftarKendaraan[indeks].nomor_polisi = nopol;
                                    cout << "\nNomor polisi kendaraan berhasil diperbarui!\n";
                                } else {
                                    cout << "\nPembaruan dibatalkan karena input kosong.\n";
                                }
                                cout << "Tekan Enter untuk melanjutkan...";
                                cin.get();
                                break;
                            }
                            case 4: {
                                cout << "\nMasukkan Harga Sewa baru: ";
                                double harga;
                                cin >> harga;
                                cin.ignore();
                                if (harga > 0) {
                                    daftarKendaraan[indeks].harga_sewa = harga;
                                    cout << "\nHarga sewa kendaraan berhasil diperbarui!\n";
                                } else {
                                    cout << "\nPembaruan dibatalkan karena harga tidak valid.\n";
                                }
                                cout << "Tekan Enter untuk melanjutkan...";
                                cin.get();
                                break;
                            }
                            case 5:
                                updateMenu = false;
                                break;
                            default:
                                cout << "\nPilihan tidak valid!\n";
                                cout << "Tekan Enter untuk melanjutkan...";
                                cin.get();
                                break;
                        }
                    }
                    break;
                }
            case 4: {
                if (jumlahKendaraan == 0) {
                    cout << "\nBelum ada data kendaraan yang tersimpan!\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << "\n====================================== Data Kendaraan ===========================================\n";
                cout << "|-----------------------------------------------------------------------------------------------|\n";
                cout << "| No |      Merk      |      Tipe      |  Nomor Polisi  |    Harga Sewa    |   Status           |\n";
                cout << "|-----------------------------------------------------------------------------------------------|\n";
                for (int i = 0; i < jumlahKendaraan; i++) {
                    cout << "| " << setw(2) << i+1 << "| " 
                            << setw(15) << daftarKendaraan[i].merk << " | " 
                            << setw(15) << daftarKendaraan[i].tipe << "| " 
                            << setw(15) << daftarKendaraan[i].nomor_polisi << " | "
                            << "Rp. " << setw(11) << fixed << setprecision(0) << daftarKendaraan[i].harga_sewa << " | " 
                            << setw(10) << daftarKendaraan[i].status << "          |\n";
                }
                cout << "|-----------------------------------------------------------------------------------------------|\n";

                int indeks;
                cout << "\nMasukkan nomor kendaraan yang akan dihapus: ";
                cin >> indeks;

                if (cin.fail() || indeks < 1 || indeks > jumlahKendaraan) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nNomor kendaraan tidak valid!\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                indeks--;

                char konfirmasi;
                cout << "Apakah Anda yakin ingin menghapus kendaraan " 
                        << daftarKendaraan[indeks].merk << " " 
                        << daftarKendaraan[indeks].tipe << " "
                        << "(" << daftarKendaraan[indeks].nomor_polisi << ")? (y/n): ";
                cin >> konfirmasi;

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    for (int i = indeks; i < jumlahKendaraan - 1; i++) {
                        daftarKendaraan[i] = daftarKendaraan[i + 1];
                    }
                    jumlahKendaraan--;
                    cout << "\nData kendaraan berhasil dihapus!\n";
                } else {
                    cout << "\nPenghapusan dibatalkan.\n";
                }
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                break;
            }
                case 5: { 
                    if (jumlahKendaraan == 0) {
                        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    bool adaRiwayat = false;

                    for (int i = 0; i < jumlahKendaraan; i++) {
                        if (daftarKendaraan[i].jumlahPenyewa > 0) {
                            adaRiwayat = true;
                            cout << "\n=== Riwayat Penyewaan untuk " << daftarKendaraan[i].merk << " " 
                                 << daftarKendaraan[i].tipe << " (" << daftarKendaraan[i].nomor_polisi << ") ===\n";
                            cout << "-------------------------------------------------\n";
                            cout << "| No |        Penyewa        |     Durasi       |\n";
                            cout << "-------------------------------------------------\n";

                            for (int j = 0; j < daftarKendaraan[i].jumlahPenyewa; j++) {
                                cout << "| " << setw(2) << j+1 << " | " 
                                     << setw(22) << daftarKendaraan[i].riwayatPenyewa[j].namaPenyewa << " | " 
                                     << setw(15) << daftarKendaraan[i].riwayatPenyewa[j].durasi << " |\n";
                            }
                            cout << "-------------------------------------------------\n";
                        }
                    }
                    if (!adaRiwayat) {
                        cout << "\nBelum ada riwayat penyewaan kendaraan.\n";
                    }
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                case 6: { 
                    cout << "\nAnda telah logout sebagai Admin.\n";
                    cout << "Tekan Enter untuk kembali ke menu awal...";
                    cin.ignore();
                    cin.get();
                    login = false;
                    isAdmin = false;
                    goto start_menu;
                }
                default: {
                    cout << "\nPilihan tidak valid!\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }
            }
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
            cout << "Pilih menu: ";
            cin >> pilihan;

            if (cin.fail() || pilihan < 1 || pilihan > 4) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPilihan tidak valid! Tekan Enter untuk melanjutkan...";
                cin.get();
                continue;
            }

            switch (pilihan) {
                case 1: {
                    if (jumlahKendaraan == 0) {
                        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    cout << "\n====================================== Data Kendaraan ===========================================\n";
                    cout << "|-----------------------------------------------------------------------------------------------|\n";
                    cout << "| No |      Merk      |      Tipe      |  Nomor Polisi  |    Harga Sewa    |   Status           |\n";
                    cout << "|-----------------------------------------------------------------------------------------------|\n";

                    for (int i = 0; i < jumlahKendaraan; i++) {
                        cout << "| " << setw(2) << i+1 << "| " 
                             << setw(15) << daftarKendaraan[i].merk << " | " 
                             << setw(15) << daftarKendaraan[i].tipe << "| " 
                             << setw(15) << daftarKendaraan[i].nomor_polisi << " | "
                             << "Rp. " << setw(11) << fixed << setprecision(0) << daftarKendaraan[i].harga_sewa << " | " 
                             << setw(10) << daftarKendaraan[i].status << "          |\n";
                    }
                    cout << "|-----------------------------------------------------------------------------------------------|\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                case 2: {
                    if (jumlahKendaraan == 0) {
                        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    bool hasActiveRental = false;
                    for (int i = 0; i < jumlahKendaraan; i++) {
                        if (daftarKendaraan[i].status == "Disewa") {
                            for (int j = 0; j < daftarKendaraan[i].jumlahPenyewa; j++) {
                                if (daftarKendaraan[i].riwayatPenyewa[j].namaPenyewa == nama) {
                                    hasActiveRental = true;
                                    break;
                                }
                            }
                        }
                        if (hasActiveRental) break;
                    }

                    if (hasActiveRental) {
                        cout << "\nAnda masih memiliki kendaraan yang sedang disewa.\n";
                        cout << "Harap kembalikan kendaraan sebelum menyewa yang baru.\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    cout << "\n====================================== Data Kendaraan ===========================================\n";
                    cout << "|-----------------------------------------------------------------------------------------------|\n";
                    cout << "| No |      Merk      |      Tipe      |  Nomor Polisi  |    Harga Sewa    |   Status           |\n";
                    cout << "|-----------------------------------------------------------------------------------------------|\n";

                    for (int i = 0; i < jumlahKendaraan; i++) {
                        cout << "| " << setw(2) << i+1 << "| " 
                             << setw(15) << daftarKendaraan[i].merk << " | " 
                             << setw(15) << daftarKendaraan[i].tipe << "| " 
                             << setw(15) << daftarKendaraan[i].nomor_polisi << " | "
                             << "Rp. " << setw(11) << fixed << setprecision(0) << daftarKendaraan[i].harga_sewa << " | " 
                             << setw(10) << daftarKendaraan[i].status << "          |\n";
                    }
                    cout << "|-----------------------------------------------------------------------------------------------|\n";
                    int count = 0;
                    for (int i = 0; i < jumlahKendaraan; i++) {
                        if (daftarKendaraan[i].status == "Tersedia") {
                            count++;
                        }
                    }
                    if (count == 0) {
                        cout << "\nTidak ada kendaraan yang tersedia untuk disewa saat ini.\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    int indeks;
                    cout << "\nMasukkan nomor kendaraan yang akan disewa: ";
                    cin >> indeks;

                    if (cin.fail() || indeks < 1 || indeks > jumlahKendaraan) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nNomor kendaraan tidak valid!\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    indeks--;

                    if (daftarKendaraan[indeks].status != "Tersedia") {
                        cout << "\nKendaraan ini tidak tersedia untuk disewa!\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    int lamaSewa;
                    cout << "Masukkan lama sewa (hari): ";
                    cin >> lamaSewa;

                    if (cin.fail() || lamaSewa <= 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nLama sewa tidak valid! Harus lebih dari 0.\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    double totalBiaya = daftarKendaraan[indeks].harga_sewa * lamaSewa;

                    cout << "\n=== Detail Sewa ===\n";
                    cout << "Kendaraan: " << daftarKendaraan[indeks].merk << " " << daftarKendaraan[indeks].tipe << endl;
                    cout << "Nomor Polisi: " << daftarKendaraan[indeks].nomor_polisi << endl;
                    cout << "Harga Sewa per Hari: Rp. " << fixed << setprecision(0) << daftarKendaraan[indeks].harga_sewa << endl;
                    cout << "Lama Sewa: " << lamaSewa << " hari" << endl;
                    cout << "Total Biaya: Rp. " << fixed << setprecision(0) << totalBiaya << endl;

                    char konfirmasi;
                    cout << "\nKonfirmasi penyewaan? (y/n): ";
                    cin >> konfirmasi;

                    if (konfirmasi == 'y' || konfirmasi == 'Y') {
                        daftarKendaraan[indeks].status = "Disewa";

                        if (daftarKendaraan[indeks].jumlahPenyewa < MAX_SEWA) {
                            daftarKendaraan[indeks].riwayatPenyewa[daftarKendaraan[indeks].jumlahPenyewa].namaPenyewa = nama;
                            daftarKendaraan[indeks].riwayatPenyewa[daftarKendaraan[indeks].jumlahPenyewa].durasi = to_string(lamaSewa) + " hari";
                            daftarKendaraan[indeks].jumlahPenyewa++;
                        }

                        cout << "\nPenyewaan berhasil! Terima kasih telah menggunakan layanan kami.\n";
                    } else {
                        cout << "\nPenyewaan dibatalkan.\n";
                    }
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                case 3: {
                    if (jumlahKendaraan == 0) {
                        cout << "\nBelum ada data kendaraan yang tersimpan!\n";
                        cout << "Tekan Enter untuk melanjutkan...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    bool adaRiwayat = false;

                    cout << "\n=== Riwayat Penyewaan untuk " << nama << " ===\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << "| No |      Kendaraan      |  Nomor Polisi  |     Durasi       |\n";
                    cout << "----------------------------------------------------------------\n";

                    int count = 1;
                    for (int i = 0; i < jumlahKendaraan; i++) {
                        for (int j = 0; j < daftarKendaraan[i].jumlahPenyewa; j++) {
                            if (daftarKendaraan[i].riwayatPenyewa[j].namaPenyewa == nama) {
                                adaRiwayat = true;
                                cout << "| " << setw(2) << count++ << " | " 
                                     << setw(20) << daftarKendaraan[i].merk + " " + daftarKendaraan[i].tipe << "| " 
                                     << setw(15) << daftarKendaraan[i].nomor_polisi << " | " 
                                     << setw(15) << daftarKendaraan[i].riwayatPenyewa[j].durasi << " |\n";
                            }
                        }
                    }
                    cout << "----------------------------------------------------------------\n";
                    if (!adaRiwayat) {
                        cout << "Anda belum pernah menyewa kendaraan.\n";
                    }
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                case 4: {
                    cout << "\nAnda telah logout.\n";
                    cout << "Tekan Enter untuk kembali ke menu awal...";
                    cin.ignore();
                    cin.get();
                    login = false;
                    goto start_menu;
                }
                default: {
                    cout << "\nPilihan tidak valid!\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                    break;
                }
            }
        }
    } while (true);

    return 0;
}
