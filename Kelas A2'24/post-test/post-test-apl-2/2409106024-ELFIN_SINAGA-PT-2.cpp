#include <iostream>
#include <string>
using namespace std;

const int MAX_PEMAIN = 100; 
const int MAX_LOGIN_ATTEMPTS = 3;
const int JUMLAH_DATA = 3;

int main() {
    string namaBenar = "elfin";
    string nimBenar = "024";
    string nama, nim;
    int percobaan = 0;
    bool loginBerhasil = false;

    while (percobaan < MAX_LOGIN_ATTEMPTS) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == namaBenar && nim == nimBenar) {
            cout << "Login berhasil!\n";
            loginBerhasil = true;
            break;
        } else {
            percobaan++;
            cout << "Login gagal. Percobaan " << percobaan << " dari " << MAX_LOGIN_ATTEMPTS << ".\n";
        }
    }

    if (!loginBerhasil) {
        cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
        return 0;
    }

    string dataPemain[MAX_PEMAIN][JUMLAH_DATA];
    int jumlahPemain = 0;
    int pilihan;

    do {
        cout << "\n=== Menu Manajemen Data Pemain NBA ===\n";
        cout << "======================================\n";
        cout << "1. Tambah Data Pemain\n";
        cout << "2. Tampilkan Data Pemain\n";
        cout << "3. Update Data Pemain\n";
        cout << "4. Hapus Data Pemain\n";
        cout << "5. Keluar\n";
        cout << "======================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (jumlahPemain < MAX_PEMAIN) {
                    cout << "\n=== Tambah Data Pemain ===\n";
                    cin.ignore();
                    cout << "Masukkan Nama Pemain: ";
                    getline(cin, dataPemain[jumlahPemain][0]);
                    cout << "Masukkan Posisi Pemain: ";
                    getline(cin, dataPemain[jumlahPemain][1]);
                    cout << "Masukkan Tim Pemain: ";
                    getline(cin, dataPemain[jumlahPemain][2]);
                    jumlahPemain++;
                    cout << "Data pemain berhasil ditambahkan.\n";
                } else {
                    cout << "Kapasitas pemain penuh. Tidak bisa menambah data lagi.\n";
                }
                break;

            case 2:
                if (jumlahPemain == 0) {
                    cout << "\nBelum ada data pemain.\n";
                } else {
                    cout << "\n=== Data Pemain NBA ===\n";
                    cout << "--------------------------------------\n";
                    for (int i = 0; i < jumlahPemain; i++) {
                        cout << "Pemain ke-" << i + 1 << ":\n";
                        cout << "Nama: " << dataPemain[i][0] << "\n";
                        cout << "Posisi: " << dataPemain[i][1] << "\n";
                        cout << "Tim: " << dataPemain[i][2] << "\n";
                        cout << "--------------------------------------\n";
                    }
                }
                break;

            case 3:
                if (jumlahPemain == 0) {
                    cout << "\nBelum ada data pemain untuk diupdate.\n";
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
                        cout << "Pilihan: ";
                        cin >> pilihanUpdate;

                        cin.ignore();
                        switch (pilihanUpdate) {
                            case 1:
                                cout << "Masukkan Nama Pemain Baru: ";
                                getline(cin, dataPemain[index - 1][0]);
                                cout << "Nama pemain berhasil diupdate.\n";
                                break;
                            case 2:
                                cout << "Masukkan Posisi Pemain Baru: ";
                                getline(cin, dataPemain[index - 1][1]);
                                cout << "Posisi pemain berhasil diupdate.\n";
                                break;
                            case 3:
                                cout << "Masukkan Tim Pemain Baru: ";
                                getline(cin, dataPemain[index - 1][2]);
                                cout << "Tim pemain berhasil diupdate.\n";
                                break;
                            default:
                                cout << "Pilihan tidak valid.\n";
                                break;
                        }
                    } else {
                        cout << "Nomor pemain tidak valid.\n";
                    }
                }
                break;

            case 4:
                if (jumlahPemain == 0) {
                    cout << "\nBelum ada data pemain untuk dihapus.\n";
                } else {
                    cout << "\n=== Hapus Data Pemain ===\n";
                    int index;
                    cout << "Masukkan nomor pemain yang ingin dihapus (1-" << jumlahPemain << "): ";
                    cin >> index;

                    if (index > 0 && index <= jumlahPemain) {
                        for (int i = index - 1; i < jumlahPemain - 1; i++) {
                            dataPemain[i][0] = dataPemain[i + 1][0];
                            dataPemain[i][1] = dataPemain[i + 1][1];
                            dataPemain[i][2] = dataPemain[i + 1][2];
                        }
                        jumlahPemain--;
                        cout << "Data pemain berhasil dihapus.\n";
                    } else {
                        cout << "Nomor pemain tidak valid.\n";
                    }
                }
                break;

            case 5:
                cout << "\nTerima kasih telah menggunakan program.\n";
                break;

            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}