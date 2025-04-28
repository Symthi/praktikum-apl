#include <iostream>
#include <string>
using namespace std;

const int MAKS_USER = 100;
const int MAKS_PEMAIN = 100;
const int PERCOBAAN_LOGIN_MAKS = 3;

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

User users[MAKS_USER];
int jumlahUser = 0;

Pemain dataPemain[MAKS_PEMAIN];
int jumlahPemain = 0;

void tampilkanHeader(string judul);
bool registerUser(User users[], int &jumlahUser, int maxUser);
int loginUser(User users[], int jumlahUser, int maxAttempts);
void tampilkanDataPemain(Pemain dataPemain[], int jumlahPemain);
bool tambahDataPemain(Pemain dataPemain[], int &jumlahPemain, int maxPemain);
bool updateDataPemain(Pemain dataPemain[], int jumlahPemain);
bool hapusDataPemain(Pemain dataPemain[], int &jumlahPemain);
void menuUtama();
void menuManajemenPemain(int &indeksloginuser);
int hitungTotalStatistik(const Stat &stat);
void updateStatistikPemain(Stat *stat, int poin, int assist, int rebound);
void tampilkanDetailPemain(const Pemain &pemain);

void selectionSortDescending(Pemain arr[], int n); 
void mergeSortAscending(Pemain arr[], int l, int r); 
void merge(Pemain arr[], int l, int m, int r);
void insertionSortDescendingPoin(Pemain arr[], int n);

int main() {
    menuUtama();
    return 0;
}

void tampilkanHeader(string judul) {
    cout << "\n=== " << judul << " ===\n";
}

bool registerUser(User users[], int &jumlahUser, int maxUser) {
    if (jumlahUser < maxUser) {
        tampilkanHeader("Register User Baru");
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

int loginUser(User users[], int jumlahUser, int maxAttempts) {
    string username, password;
    int percobaan = 0;

    while (percobaan < maxAttempts) {
        tampilkanHeader("Login");
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
        cout << "Login gagal. Percobaan " << percobaan << " dari " << maxAttempts << ".\n";
    }

    cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
    return -1;
}

void selectionSortDescending(Pemain arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].nama > arr[max_idx].nama) {
                max_idx = j;
            }
        }
        swap(arr[i], arr[max_idx]);
    }
}

void merge(Pemain arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Pemain L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (hitungTotalStatistik(L[i].statistik) <= hitungTotalStatistik(R[j].statistik)) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortAscending(Pemain arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortAscending(arr, l, m);
        mergeSortAscending(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void insertionSortDescendingPoin(Pemain arr[], int n) {
    for (int i = 1; i < n; i++) {
        Pemain key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].statistik.poin < key.statistik.poin) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void tampilkanDataPemain(Pemain dataPemain[], int jumlahPemain) {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain.\n";
        return;
    }

    tampilkanHeader("Pilihan Sorting");
    cout << "1. Urutkan berdasarkan nama (Z-A)\n";
    cout << "2. Urutkan berdasarkan total statistik (ascending)\n";
    cout << "3. Urutkan berdasarkan poin (descending)\n";
    cout << "Pilih metode sorting (0 untuk tidak sorting): ";
    int pilihanSorting;
    cin >> pilihanSorting;

    Pemain tempData[MAKS_PEMAIN];
    for (int i = 0; i < jumlahPemain; i++) {
        tempData[i] = dataPemain[i];
    }

    switch (pilihanSorting) {
        case 1:
            selectionSortDescending(tempData, jumlahPemain);
            cout << "\nData diurutkan berdasarkan nama (Z-A):\n";
            break;
        case 2:
            mergeSortAscending(tempData, 0, jumlahPemain - 1);
            cout << "\nData diurutkan berdasarkan total statistik (ascending):\n";
            break;
        case 3:
            insertionSortDescendingPoin(tempData, jumlahPemain);
            cout << "\nData diurutkan berdasarkan poin (descending):\n";
            break;
        default:
            cout << "\nMenampilkan data tanpa sorting:\n";
            break;
    }

    tampilkanHeader("Data Pemain NBA");
    cout << "--------------------------------------\n";
    for (int i = 0; i < jumlahPemain; i++) {
        cout << "Pemain ke-" << i + 1 << ":\n";
        tampilkanDetailPemain(tempData[i]);
        cout << "  Total Statistik: " << hitungTotalStatistik(tempData[i].statistik) << "\n";
        cout << "--------------------------------------\n";
    }
}

void tampilkanDetailPemain(const Pemain &pemain) {
    cout << "Nama: " << pemain.nama << "\n";
    cout << "Posisi: " << pemain.posisi << "\n";
    cout << "Tim: " << pemain.tim << "\n";
    cout << "Statistik:\n";
    cout << "  Poin: " << pemain.statistik.poin << "\n";
    cout << "  Assist: " << pemain.statistik.assist << "\n";
    cout << "  Rebound: " << pemain.statistik.rebound << "\n";
}

bool tambahDataPemain(Pemain dataPemain[], int &jumlahPemain, int maxPemain) {
    if (jumlahPemain < maxPemain) {
        tampilkanHeader("Tambah Data Pemain");
        cin.ignore();
        cout << "Masukkan Nama Pemain: ";
        getline(cin, dataPemain[jumlahPemain].nama);
        cout << "Masukkan Posisi Pemain: ";
        getline(cin, dataPemain[jumlahPemain].posisi);
        cout << "Masukkan Tim Pemain: ";
        getline(cin, dataPemain[jumlahPemain].tim);
        cout << "Masukkan Statistik Pemain (poin assist rebound)\n";
        
        int poin, assist, rebound;
        cout << "Poin : ";
        cin >> poin;
        cout << "Assist : ";
        cin >> assist;
        cout << "Rebound : ";
        cin >> rebound;
        
        updateStatistikPemain(&dataPemain[jumlahPemain].statistik, poin, assist, rebound);
        
        jumlahPemain++;
        cout << "Data pemain berhasil ditambahkan.\n";
        return true;
    } else {
        cout << "Kapasitas pemain penuh. Tidak bisa menambah data lagi.\n";
        return false;
    }
}

void updateStatistikPemain(Stat *stat, int poin, int assist, int rebound) {
    stat->poin = poin;
    stat->assist = assist;
    stat->rebound = rebound;
}

bool updateDataPemain(Pemain dataPemain[], int jumlahPemain) {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain untuk diupdate.\n";
        return false;
    }

    tampilkanHeader("Update Data Pemain");
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
                cout << "Masukkan Statistik Pemain Baru (poin assist rebound)\n";
                int poin, assist, rebound;
                cout << "Poin : ";
                cin >> poin;
                cout << "Assist : ";
                cin >> assist;
                cout << "Rebound : ";
                cin >> rebound;
                updateStatistikPemain(&dataPemain[index - 1].statistik, poin, assist, rebound);
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

bool hapusDataPemain(Pemain dataPemain[], int &jumlahPemain) {
    if (jumlahPemain == 0) {
        cout << "\nBelum ada data pemain untuk dihapus.\n";
        return false;
    }

    tampilkanHeader("Hapus Data Pemain");
    int index;
    cout << "Masukkan nomor pemain yang ingin dihapus (1-" << jumlahPemain << "): ";
    cin >> index;

    if (index > 0 && index <= jumlahPemain) {
        Pemain *ptrHapus = &dataPemain[index - 1];
        cout << "Menghapus data pemain: " << ptrHapus->nama << endl;
        
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

int hitungTotalStatistik(const Stat &stat) {
    return stat.poin + stat.assist + stat.rebound;
}

void menuUtama() {
    int pilihan;
    int indeksloginuser = -1;

    do {
        tampilkanHeader("Menu Utama");
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                registerUser(users, jumlahUser, MAKS_USER);
                break;
            case 2:
                indeksloginuser = loginUser(users, jumlahUser, PERCOBAAN_LOGIN_MAKS);
                if (indeksloginuser != -1) {
                    menuManajemenPemain(indeksloginuser);
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
}

void menuManajemenPemain(int &indeksloginuser) {
    int pilihanSetelahLogin;
    
    do {
        tampilkanHeader("Manajemen Pemain NBA");
        cout << "1. Tambah Data Pemain\n";
        cout << "2. Tampilkan Data Pemain\n";
        cout << "3. Update Data Pemain\n";
        cout << "4. Hapus Data Pemain\n";
        cout << "5. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihanSetelahLogin;

        switch (pilihanSetelahLogin) {
            case 1:
                tambahDataPemain(dataPemain, jumlahPemain, MAKS_PEMAIN);
                break;
            case 2:
                tampilkanDataPemain(dataPemain, jumlahPemain);
                break;
            case 3:
                updateDataPemain(dataPemain, jumlahPemain);
                break;
            case 4:
                hapusDataPemain(dataPemain, jumlahPemain);
                break;
            case 5:
                cout << "Anda telah logout.\n";
                indeksloginuser = -1;
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (indeksloginuser != -1);
}