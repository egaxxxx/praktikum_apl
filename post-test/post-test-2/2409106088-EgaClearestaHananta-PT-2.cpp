#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

const int MAX_DATA = 100;
const int MAX_SEWA = 10;

struct Kendaraan {
    string merk;
    string tipe;
    string nomor_polisi;
    double harga_sewa;
    string status;
    string riwayatPenyewa[MAX_SEWA][2];
    int jumlahPenyewa = 0;
};

Kendaraan daftarKendaraan[MAX_DATA];
int jumlahKendaraan = 0;

int main() {
    string nama, nim;
    int kesempatan = 3;
    bool login = false;
    
    while (kesempatan > 0) {
cout << "======================================\n";
cout << "            Menu Login                 \n";
cout << "======================================\n";
cout << " Masukkan Username: ";
getline(cin, nama);
cout << "\n Masukkan NIM: ";
getline(cin, nim);
cout << "\n======================================\n";

if (nama == "EgaClearestaHananta" && nim == "2409106088") {
    login = true;
    cout << "\nlogin berhasil! Tekan Enter untuk melanjutkan...";
    cin.get();
    break;
} else {
    kesempatan--;
    cout << "\nLogin gagal! Sisa percobaan: " << kesempatan << "\n";
}
}

if (!login) {
cout << "\nTerlalu banyak percobaan gagal. Program berhenti.\n";
return 0;
}
    
int pilihan;
do {
system("cls");
cout << "|======================================|\n";
cout << "| Sistem Pendataan Penyewaan Kendaraan |\n";
cout << "|====|=================================|\n";
cout << "| No |            Menu                 |\n";
cout << "|====|=================================|\n";
cout << "| 1  | Tambah Data Kendaraan           |\n";
cout << "| 2  | Lihat Data Kendaraan            |\n";
cout << "| 3  | Perbarui Data Kendaraan         |\n";
cout << "| 4  | Hapus Data Kendaraan            |\n";
cout << "| 5  | Sewa Kendaraan                  |\n";
cout << "| 6  | Lihat Riwayat Penyewaan         |\n";
cout << "| 7  | Keluar                          |\n";
cout << "|====|=================================|\n";
cout << "Pilih menu: ";
cin >> pilihan;

        if (cin.fail() || pilihan < 1 || pilihan > 7) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPilihan tidak valid! Tekan Enter untuk melanjutkan...";
            cin.get();
            continue;
        }
        
        switch (pilihan) {
case 1:
if (jumlahKendaraan < MAX_DATA) {
    cout << "\nMasukkan Merk Kendaraan: ";
    cin.ignore();
    getline(cin, daftarKendaraan[jumlahKendaraan].merk);
    cout << "Masukkan Tipe Kendaraan: ";
    getline(cin, daftarKendaraan[jumlahKendaraan].tipe);
    cout << "Masukkan Nomor Polisi: ";
    getline(cin, daftarKendaraan[jumlahKendaraan].nomor_polisi);
    cout << "Masukkan Harga Sewa: ";
    cin >> daftarKendaraan[jumlahKendaraan].harga_sewa;
    if (cin.fail() || daftarKendaraan[jumlahKendaraan].harga_sewa < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInput harga sewa tidak valid! Tekan Enter untuk melanjutkan...";
        cin.get();
        break;
    }
    daftarKendaraan[jumlahKendaraan].status = "Tersedia";
    jumlahKendaraan++;
    cout << "\nKendaraan berhasil ditambahkan!\n";
} else {
    cout << "\nPenyimpanan penuh!\n";
}
cout << "\nTekan Enter untuk melanjutkan...";
cin.ignore();
cin.get();
break;
case 2:
if (jumlahKendaraan == 0) {
cout << "\nTidak ada data kendaraan.\n";
} else {
system("cls");
cout << "|====|===============|==============|=============|============|============|\n";
cout << "| No | Merk          | Tipe         | No. Polisi  | Harga Sewa | Status     |\n";
cout << "|====|===============|==============|=============|============|============|\n";
for (int i = 0; i < jumlahKendaraan; i++) {
cout << "| " << setw(2) << i + 1 << " |"<< setw(12) << daftarKendaraan[i].merk
        << "   | " << setw(10) << daftarKendaraan[i].tipe
        << "   | " << setw(11) << daftarKendaraan[i].nomor_polisi
        << " | " << setw(10) << daftarKendaraan[i].harga_sewa
        << " | " << setw(10) << daftarKendaraan[i].status << " |\n";
}
cout << "|====|===============|==============|=============|============|============|\n";
}
cout << "\nTekan Enter untuk melanjutkan...";
cin.ignore();
cin.get();
break;
case 3:
if (jumlahKendaraan == 0) {
cout << "\nTidak ada data kendaraan.\n";
cout << "\nTekan Enter untuk melanjutkan...";
cin.ignore();
cin.get();
} else {
system("cls");
int index;
cout << "|====|===============|==============|=============|============|============|\n";
cout << "| No | Merk          | Tipe         | No. Polisi  | Harga Sewa | Status     |\n";
cout << "|====|===============|==============|=============|============|============|\n";
for (int i = 0; i < jumlahKendaraan; i++) {
cout << "| " << setw(2) << i + 1 << " |"<< setw(12) << daftarKendaraan[i].merk
<< "   | " << setw(10) << daftarKendaraan[i].tipe
<< "   | " << setw(11) << daftarKendaraan[i].nomor_polisi
<< " | " << setw(10) << daftarKendaraan[i].harga_sewa
<< " | " << setw(10) << daftarKendaraan[i].status << " |\n";
}
cout << "|====|===============|==============|=============|============|============|\n";
cout << "\nMasukkan nomor kendaraan yang ingin diperbarui: ";
cin >> index;
if (cin.fail() || index < 1 || index > jumlahKendaraan) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "\nNomor tidak valid! Tekan Enter untuk melanjutkan...";
cin.get();
break;
}

int subPilihan;
do {
system("cls");
cout << "|========================================|\n";
cout << "|    Pilih data yang ingin diperbarui:   |\n";
cout << "|========================================|\n";
cout << "| 1. Perbarui Merk                       |\n";
cout << "| 2. Perbarui Tipe                       |\n";
cout << "| 3. Perbarui No Polisi                  |\n";
cout << "| 4. Perbarui Harga Sewa                 |\n";
cout << "| 5. Kembali                             |\n";
cout << "|========================================|\n";
cout << "Pilih: ";
cin >> subPilihan;

if (cin.fail() || subPilihan < 1 || subPilihan > 5) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "\nPilihan tidak valid! Tekan Enter untuk melanjutkan...";
cin.get();
continue;
}

switch (subPilihan) {
case 1:
cout << "Masukkan Merk baru: ";
cin.ignore();
getline(cin, daftarKendaraan[index - 1].merk);
cout << "\nMerk berhasil diperbarui!\n";
break;
case 2:
cout << "Masukkan Tipe baru: ";
cin.ignore();
getline(cin, daftarKendaraan[index - 1].tipe);
cout << "\nTipe berhasil diperbarui!\n";
break;
case 3:
cout << "Masukkan Nomor Polisi baru: ";
cin.ignore();
getline(cin, daftarKendaraan[index - 1].nomor_polisi);
cout << "\nNomor Polisi berhasil diperbarui!\n";
break;
case 4:
cout << "Masukkan Harga Sewa baru: ";
cin >> daftarKendaraan[index - 1].harga_sewa;
if (cin.fail() || daftarKendaraan[index - 1].harga_sewa < 0) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nInput harga sewa tidak valid! Tekan Enter untuk melanjutkan...";
    cin.get();
    break;
}
cout << "\nHarga Sewa berhasil diperbarui!\n";
break;
case 5:
break;
}
cout << "\nTekan Enter untuk melanjutkan...";
cin.ignore();
cin.get();
} while (subPilihan != 5);
}
break;
case 4:
if (jumlahKendaraan == 0) {
cout << "\nTidak ada data kendaraan.\n";
} else {
system("cls");
int index;
cout << "|====|===============|==============|=============|============|============|\n";
cout << "| No | Merk          | Tipe         | No. Polisi  | Harga Sewa | Status     |\n";
cout << "|====|===============|==============|=============|============|============|\n";
for (int i = 0; i < jumlahKendaraan; i++) {
cout << "| " << setw(2) << i + 1 << " |"<< setw(12) << daftarKendaraan[i].merk
        << "   | " << setw(10) << daftarKendaraan[i].tipe
        << "   | " << setw(11) << daftarKendaraan[i].nomor_polisi
        << " | " << setw(10) << daftarKendaraan[i].harga_sewa
        << " | " << setw(10) << daftarKendaraan[i].status << " |\n";
}
cout << "|====|===============|==============|=============|============|============|\n";
cout << "\nMasukkan nomor kendaraan yang ingin dihapus: ";
cin >> index;
if (cin.fail() || index < 1 || index > jumlahKendaraan) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "\nNomor tidak valid! Tekan Enter untuk melanjutkan...";
cin.get();
break;
}
for (int i = index - 1; i < jumlahKendaraan - 1; i++) {
daftarKendaraan[i] = daftarKendaraan[i + 1];
}
jumlahKendaraan--;
cout << "\nData kendaraan berhasil dihapus!\n";
}
cout << "\nTekan Enter untuk melanjutkan...";
cin.ignore();
cin.get();
break;
case 5:
if (jumlahKendaraan == 0) {
cout << "\nTidak ada data kendaraan.\n";
} else {
system("cls");
int index;
cout << "|====|===============|==============|=============|============|============|\n";
cout << "| No | Merk          | Tipe         | No. Polisi  | Harga Sewa | Status     |\n";
cout << "|====|===============|==============|=============|============|============|\n";
for (int i = 0; i < jumlahKendaraan; i++) {
    cout << "| " << setw(2) << i + 1 << " |"<< setw(12) << daftarKendaraan[i].merk
            << "   | " << setw(10) << daftarKendaraan[i].tipe
            << "   | " << setw(11) << daftarKendaraan[i].nomor_polisi
            << " | " << setw(10) << daftarKendaraan[i].harga_sewa
            << " | " << setw(10) << daftarKendaraan[i].status << " |\n";
}
cout << "|====|===============|==============|=============|============|============|\n";
cout << "\nMasukkan nomor kendaraan yang ingin disewa: ";
cin >> index;
if (cin.fail() || index < 1 || index > jumlahKendaraan) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nNomor tidak valid! Tekan Enter untuk melanjutkan...";
    cin.get();
    break;
}
if (daftarKendaraan[index - 1].status == "Disewa") {
    cout << "\nKendaraan sedang disewa! Tekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    break;
}
cout << "\nMasukkan Nama Penyewa: ";
cin.ignore();
getline(cin, nama);
cout << "Masukkan NIM Penyewa: ";
getline(cin, nim);
if (daftarKendaraan[index - 1].jumlahPenyewa < MAX_SEWA) {
    daftarKendaraan[index - 1].riwayatPenyewa[daftarKendaraan[index - 1].jumlahPenyewa][0] = nama;
    daftarKendaraan[index - 1].riwayatPenyewa[daftarKendaraan[index - 1].jumlahPenyewa][1] = nim;
    daftarKendaraan[index - 1].jumlahPenyewa++;
    daftarKendaraan[index - 1].status = "Disewa";
    cout << "\nKendaraan berhasil disewa!\n";
} else {
    cout << "\nRiwayat penyewa penuh! Tidak bisa menyewa kendaraan ini.\n";
}
}
cout << "\nTekan Enter untuk melanjutkan...";
cin.ignore();
cin.get();
break;
case 6:
system("cls");
if (jumlahKendaraan == 0) {
cout << "\nTidak ada data kendaraan.\n";
} else {
cout << "|====|===============|==============|=============|=========================|\n";
cout << "| No | Merk          | Tipe         | No. Polisi  | Riwayat Penyewa         |\n";
cout << "|====|===============|==============|=============|=========================|\n";
for (int i = 0; i < jumlahKendaraan; i++) {
    cout << "| " << setw(2) << i + 1 << " | " << setw(12) << daftarKendaraan[i].merk
            << "  | " << setw(10) << daftarKendaraan[i].tipe
            <<"   | " << setw(11) << daftarKendaraan[i].nomor_polisi << " | ";
    if (daftarKendaraan[i].jumlahPenyewa > 0) {
        for (int j = 0; j < daftarKendaraan[i].jumlahPenyewa; j++) {
            cout << daftarKendaraan[i].riwayatPenyewa[j][0] << " (" << daftarKendaraan[i].riwayatPenyewa[j][1] << ") ";
        }
    } else {
        cout << "Belum ada penyewa";
    }
    cout << "       |\n";
}
cout << "|====|===============|==============|=============|=========================|\n";
}
cout << "\nTekan Enter untuk melanjutkan...";
cin.ignore();
cin.get();
break;
case 7:
    cout << "\nTerima kasih telah menggunakan program kami!\n";
    break;
default:
    cout << "\nPilihan tidak valid!\n";
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

} while (pilihan != 7);

return 0;
}