#include <iostream>
#include <string>
using namespace std;

const int MAX_USER = 100;
const int MAX_PEMAIN = 100;
const int MAX_LOGIN_ATTEMPTS = 3;

struct Stat {
    int poin;
    int assist;
    int rebound;
};

struct User {
    string username;
    string password;
};

struct Pemain {
    string nama;
    string posisi;
    string tim;
    Stat statistik;
};

User users[MAX_USER];
int jumlahUser = 0;

Pemain dataPemain[MAX_PEMAIN];
int jumlahPemain = 0;

bool registerUser() {
    if (jumlahUser < MAX_USER) {
        cout << "\n=== Register User Baru ===\n";
        cout << "Masukkan Username: ";
        cin >> users[jumlahUser].username;
        cout << "Masukkan Password: ";
        cin >> users[jumlahUser].password;
        jumlahUser++;
        cout << "User berhasil terdaftar!\n";
        return true;
    } else {
        cout << "Kapasitas user penuh. Tidak bisa mendaftarkan user baru.\n";
        return false;
    }
}

int loginUser() {
    string username, password;
    int percobaan = 0;

    while (percobaan < MAX_LOGIN_ATTEMPTS) {
        cout << "\n=== Login ===\n";
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        for (int i = 0; i < jumlahUser; i++) {
            if (users[i].username == username && users[i].password == password) {
                cout << "Login berhasil! Selamat datang, " << username << "!\n";
                return i;
            }
        }

        percobaan++;
        cout << "Login gagal. Percobaan " << percobaan << " dari " << MAX_LOGIN_ATTEMPTS << ".\n";
    }

    cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
    return -1;
}

int tampilkanDataPemain() {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain.\n";
        return 0;
    } else {
        cout << "\n=== Data Pemain NBA ===\n";
        cout << "--------------------------------------\n";
        for (int i = 0; i < jumlahPemain; i++) {
            cout << "Pemain ke-" << i + 1 << ":\n";
            cout << "Nama: " << dataPemain[i].nama << "\n";
            cout << "Posisi: " << dataPemain[i].posisi << "\n";
            cout << "Tim: " << dataPemain[i].tim << "\n";
            cout << "Statistik:\n";
            cout << "  Poin: " << dataPemain[i].statistik.poin << "\n";
            cout << "  Assist: " << dataPemain[i].statistik.assist << "\n";
            cout << "  Rebound: " << dataPemain[i].statistik.rebound << "\n";
            cout << "--------------------------------------\n";
        }
        return jumlahPemain;
    }
}

bool tambahDataPemain() {
    if (jumlahPemain < MAX_PEMAIN) {
        cout << "\n=== Tambah Data Pemain ===\n";
        cin.ignore();
        cout << "Masukkan Nama Pemain: ";
        getline(cin, dataPemain[jumlahPemain].nama);
        cout << "Masukkan Posisi Pemain: ";
        getline(cin, dataPemain[jumlahPemain].posisi);
        cout << "Masukkan Tim Pemain: ";
        getline(cin, dataPemain[jumlahPemain].tim);
        cout << "Masukkan Statistik Pemain (poin assist rebound)" << "\n";
        cout << "Poin : ";
        cin >> dataPemain[jumlahPemain].statistik.poin;
        cout << "Assist : ";
        cin >> dataPemain[jumlahPemain].statistik.assist;
        cout << "Rebound : ";
        cin >> dataPemain[jumlahPemain].statistik.rebound;
        jumlahPemain++;
        cout << "Data pemain berhasil ditambahkan.\n";
        return true;
    } else {
        cout << "Kapasitas pemain penuh. Tidak bisa menambah data lagi.\n";
        return false;
    }
}

bool updateDataPemain() {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain untuk diupdate.\n";
        return false;
    } else {
        cout << "\n=== Update Data Pemain ===\n";
        int index;
        cout << "Masukkan nomor pemain yang ingin diupdate (1-" << jumlahPemain << "): ";
        cin >> index;

        if (index > 0 && index <= jumlahPemain) {
            int pilihanUpdate;
            cout << "\nPilih data yang ingin diupdate:\n";
            cout << "1. Nama\n";
            cout << "2. Posisi\n";
            cout << "3. Tim\n";
            cout << "4. Statistik\n";
            cout << "Pilihan: ";
            cin >> pilihanUpdate;

            cin.ignore();
            switch (pilihanUpdate) {
                case 1:
                    cout << "Masukkan Nama Pemain Baru: ";
                    getline(cin, dataPemain[index - 1].nama);
                    cout << "Nama pemain berhasil diupdate.\n";
                    break;
                case 2:
                    cout << "Masukkan Posisi Pemain Baru: ";
                    getline(cin, dataPemain[index - 1].posisi);
                    cout << "Posisi pemain berhasil diupdate.\n";
                    break;
                case 3:
                    cout << "Masukkan Tim Pemain Baru: ";
                    getline(cin, dataPemain[index - 1].tim);
                    cout << "Tim pemain berhasil diupdate.\n";
                    break;
                case 4:
                    cout << "Masukkan Statistik Pemain Baru (poin assist rebound)" << "\n";
                    cout << "Poin : ";
                    cin >> dataPemain[index - 1].statistik.poin;
                    cout << "Assist : ";
                    cin >> dataPemain[index - 1].statistik.assist;
                    cout << "Rebound : ";
                    cin >> dataPemain[index - 1].statistik.rebound;
                    cout << "Statistik pemain berhasil diupdate.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
                    return false;
            }
            return true;
        } else {
            cout << "Nomor pemain tidak valid.\n";
            return false;
        }
    }
}

bool hapusDataPemain() {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain untuk dihapus.\n";
        return false;
    } else {
        cout << "\n=== Hapus Data Pemain ===\n";
        int index;
        cout << "Masukkan nomor pemain yang ingin dihapus (1-" << jumlahPemain << "): ";
        cin >> index;

        if (index > 0 && index <= jumlahPemain) {
            for (int i = index - 1; i < jumlahPemain - 1; i++) {
                dataPemain[i] = dataPemain[i + 1];
            }
            jumlahPemain--;
            cout << "Data pemain berhasil dihapus.\n";
            return true;
        } else {
            cout << "Nomor pemain tidak valid.\n";
            return false;
        }
    }
}

int main() {
    int pilihan;
    int loggedInUserIndex = -1;

    do {
        cout << "\n=== Menu Utama ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                registerUser();
                break;
            case 2:
                loggedInUserIndex = loginUser();
                if (loggedInUserIndex != -1) {
                    int pilihanSetelahLogin;
                    do {
                        cout << "\n=== Manajemen Pemain NBA ===\n";
                        cout << "1. Tambah Data Pemain\n";
                        cout << "2. Tampilkan Data Pemain\n";
                        cout << "3. Update Data Pemain\n";
                        cout << "4. Hapus Data Pemain\n";
                        cout << "5. Logout\n";
                        cout << "Pilih menu: ";
                        cin >> pilihanSetelahLogin;

                        switch (pilihanSetelahLogin) {
                            case 1:
                                tambahDataPemain();
                                break;
                            case 2:
                                tampilkanDataPemain();
                                break;
                            case 3:
                                updateDataPemain();
                                break;
                            case 4:
                                hapusDataPemain();
                                break;
                            case 5:
                                cout << "Anda telah logout.\n";
                                loggedInUserIndex = -1;
                                break;
                            default:
                                cout << "Pilihan tidak valid.\n";
                                break;
                        }
                    } while (loggedInUserIndex != -1);
                }
                break;
            case 3:
                cout << "Program selesai. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 3);

    return 0;
}