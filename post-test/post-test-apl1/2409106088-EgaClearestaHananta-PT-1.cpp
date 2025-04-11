#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool Masukkan(const string& str) {
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

int main() {
    const string Nama = "EgaClearestaHananta";
    const string NIM = "2409106088";
    
    string username, password;
    int percobaan = 0;
    const int batas_login = 3;
    bool login_berhasil = false;
    
    while (percobaan < batas_login && !login_berhasil) {
        cout << "==============================================================" << endl;
        cout << "                         Menu Login                 " << endl;
        cout << "==============================================================" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        
        if (username == Nama && password == NIM) {
            login_berhasil = true;
            cout << "Login berhasil!\n";
            cout << "Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        } else {
            percobaan++;
            if (percobaan < batas_login) {
                cout << "Login gagal! Silahkan Coba lagi, Sisa percobaan anda " << batas_login - percobaan << " Kali lagi\n";
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
            } else {
                cout << "Login gagal! Anda telah mencapai batas percobaan.\nProgram akan berhenti.\n";
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                return 0;
            }
        }
    }
    
    int pilihan, perubahan;
    double jumlah;
    string input;
    
    do {
        system("cls");
        cout << " " <<endl;
        cout << "==============================================================" << endl;
        cout << "                         Menu Utama                 " << endl;
        cout << "==============================================================" << endl;
        cout << "1. Konversi mata uang \n";
        cout << "2. Konversi Jarak\n";
        cout << "3. Konversi Waktu\n";
        cout << "4. Konversi Suhu\n";
        cout << "5. Logout\n";
        cout << "Pilih menu: ";
        cin >> input;
        
        if (Masukkan(input)) {
            pilihan = stoi(input);
        } else {
            pilihan = -1;
        }
        
        if (pilihan == 1) {
            do {
                system("cls");
                cout << " " <<endl;
                cout << "==============================================================" << endl;
                cout << "                    Konversi mata uang               " << endl;
                cout << "==============================================================" << endl;
                cout << "1. Rupiah ke Dolar AS\n2. Rupiah ke Euro\n3. Dolar AS ke Rupiah\n4. Dolar AS ke Euro\n5. Euro ke Rupiah\n6. Euro ke Dolar AS\n7. Kembali\nPilih: ";
                cin >> input;
                
                if (Masukkan(input)) {
                    perubahan = stoi(input);
                } else {
                    perubahan = -1;
                }
                
                if (perubahan >= 1 && perubahan <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    if (perubahan == 1) cout << jumlah << " Rp = " << jumlah / 16270 << " USD\n";
                    else if (perubahan == 2) cout << jumlah << " Rp = " << jumlah / 17628 << " Euro\n";
                    else if (perubahan == 3) cout << jumlah << " USD = " << jumlah * 16310 << " Rp\n";
                    else if (perubahan == 4) cout << jumlah << " USD = " << jumlah * 0.91 << " Euro\n";
                    else if (perubahan == 5) cout << jumlah << " Euro = " << jumlah * 17666 << " Rp\n";
                    else if (perubahan == 6) cout << jumlah << " Euro = " << jumlah * 1.10 << " USD\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (perubahan != 7) {
                    cout << "Pilihan tidak tersedia. Tekan Enter untuk kembali ke menu...";
                    cin.ignore();
                    cin.get();
                }
            } while (perubahan != 7);
        }
        
        else if (pilihan == 2) {
            do {
                system("cls");
                cout << " " <<endl;
                cout << "==============================================================" << endl;
                cout << "                    Konversi jarak                 " << endl;
                cout << "==============================================================" << endl;
                cout << "1. Kilometer ke Meter\n2. Kilometer ke Centimeter\n3. Meter ke Kilometer\n4. Meter ke Centimeter\n5. Centimeter ke Kilometer\n6. Centimeter ke Meter\n7. Kembali\nPilih: ";
                cin >> input;
                
                if (Masukkan(input)) {
                    perubahan = stoi(input);
                } else {
                    perubahan = -1;
                }
                
                if (perubahan >= 1 && perubahan <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    if (perubahan == 1) cout << jumlah << " km = " << jumlah * 1000 << " m\n";
                    else if (perubahan == 2) cout << jumlah << " km = " << jumlah * 100000 << " cm\n";
                    else if (perubahan == 3) cout << jumlah << " m = " << jumlah / 1000 << " km\n";
                    else if (perubahan == 4) cout << jumlah << " m = " << jumlah * 100 << " cm\n";
                    else if (perubahan == 5) cout << jumlah << " cm = " << jumlah / 100000 << " km\n";
                    else if (perubahan == 6) cout << jumlah << " cm = " << jumlah / 100 << " m\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (perubahan != 7) {
                    cout << "Pilihan tidak tersedia. Tekan Enter untuk kembali ke menu...";
                    cin.ignore();
                    cin.get();
                }
            } while (perubahan != 7);
        }
        
        else if (pilihan == 3) {
            do {
                system("cls");
                cout << " " <<endl;
                cout << "==============================================================" << endl;
                cout << "                    Konversi Waktu                 " << endl;
                cout << "==============================================================" << endl;
                cout << "1. Jam ke Menit\n2. Jam ke Detik\n3. Menit ke Jam\n4. Menit ke Detik\n5. Detik ke Jam\n6. Detik ke Menit\n7. Kembali\nPilih: ";
                cin >> input;
                
                if (Masukkan(input)) {
                    perubahan = stoi(input);
                } else {
                    perubahan = -1;
                }
                
                if (perubahan >= 1 && perubahan <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    if (perubahan == 1) cout << jumlah << " jam = " << jumlah * 60 << " menit\n";
                    else if (perubahan == 2) cout << jumlah << " jam = " << jumlah * 3600 << " detik\n";
                    else if (perubahan == 3) cout << jumlah << " menit = " << jumlah / 60 << " jam\n";
                    else if (perubahan == 4) cout << jumlah << " menit = " << jumlah * 60 << " detik\n";
                    else if (perubahan == 5) cout << jumlah << " detik = " << jumlah / 3600 << " jam\n";
                    else if (perubahan == 6) cout << jumlah << " detik = " << jumlah / 60 << " menit\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (perubahan != 7) {
                    cout << "Pilihan tidak tersedia. Tekan Enter untuk kembali ke menu...";
                    cin.ignore();
                    cin.get();
                }
            } while (perubahan != 7);
        }

        else if (pilihan == 4) {
            do {
                system("cls");
                cout << " " << endl;
                cout << "==============================================================" << endl;
                cout << "                    Konversi Suhu                 " << endl;
                cout << "==============================================================" << endl;
                cout << "1. Celsius ke Fahrenheit\n2. Celsius ke Kelvin\n3. Fahrenheit ke Celsius\n4. Fahrenheit ke Kelvin\n5. Kelvin ke Celsius\n6. Kelvin ke Fahrenheit\n7. Kembali\nPilih: ";
                cin >> input;
                
                if (Masukkan(input)) {
                    perubahan = stoi(input);
                } else {
                    perubahan = -1; 
                }
                
                if (perubahan >= 1 && perubahan <= 6) {
                    cout << "Masukkan suhu: ";
                    cin >> jumlah;
                    if (perubahan == 1) cout << jumlah << " C = " << (jumlah * 9/5) + 32 << " F\n";
                    else if (perubahan == 2) cout << jumlah << " C = " << jumlah + 273.15 << " K\n";
                    else if (perubahan == 3) cout << jumlah << " F = " << (jumlah - 32) * 5/9 << " C\n";
                    else if (perubahan == 4) cout << jumlah << " F = " << ((jumlah - 32) * 5/9) + 273.15 << " K\n";
                    else if (perubahan == 5) cout << jumlah << " K = " << jumlah - 273.15 << " C\n";
                    else if (perubahan == 6) cout << jumlah << " K = " << ((jumlah - 273.15) * 9/5) + 32 << " F\n";
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } else if (perubahan != 7) {
                    cout << "Pilihan tidak tersedia. Tekan Enter untuk kembali ke menu...";
                    cin.ignore();
                    cin.get();
                }
            } while (perubahan != 7);
        }
        
        else if (pilihan == 5) {
            cout << "Logout berhasil. Program selesai.\n";
        } else {
            cout << "Pilihan tidak tersedia. Tekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
        }
    } while (pilihan != 5);
    
    return 0;
}