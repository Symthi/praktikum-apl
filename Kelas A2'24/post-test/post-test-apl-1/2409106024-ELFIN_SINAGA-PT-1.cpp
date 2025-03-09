#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "==================== LOGIN ==========================" << endl;
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan 3 digit terakhir NIM: ";
        cin >> nim;

        if (nama == "elfin" && nim == "024") break;
        cout << "Nama atau NIM salah. Percobaan ke-" << ++percobaan << " dari 3." << endl;
    }

    if (percobaan == 3) {
        cout << "Anda telah salah memasukkan nama atau NIM sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    int suhu;

    while (true) {
        cout << "========================================================================" << endl;
        cout << "                           Menu Konversi Suhu                           " << endl;
        cout << "========================================================================" << endl;
        cout << "1. Konversi Celcius ke Fahrenheit, Reamur, dan Kelvin" << endl;
        cout << "2. Konversi Fahrenheit ke Celcius, Reamur, dan Kelvin" << endl;
        cout << "3. Konversi Reamur ke Celcius, Fahrenheit, dan Kelvin" << endl;
        cout << "4. Konversi Kelvin ke Celcius, Fahrenheit, dan Reamur" << endl;
        cout << "5. Keluar dari program" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        if (pilihan == 5) {
            cout << "========================================================================" << endl;
            cout << "            Ubur - Ubur Ikan Lele, Terima Kasih udah datang lee" << endl;
            cout << "========================================================================" << endl;
            break;
        }

        if (pilihan < 1 || pilihan > 4) {
            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
            continue;
        }

        while (true) {
            cout << "========================================================================" << endl;
            cout << "Masukkan nilai suhu: ";
            if (cin >> suhu) break;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Coba Lagi, Masukkan Angka" << endl;
        }

        switch (pilihan) {
            case 1:
                cout << "========================================================================" << endl;
                cout << "Hasil dari konversi Celcius" << endl;
                cout << "Fahrenheit: " << (suhu * 9/5) + 32 << endl;
                cout << "Reamur: " << suhu * 4/5 << endl;
                cout << "Kelvin: " << suhu + 273 << endl;
                break;
            case 2:
                cout << "========================================================================" << endl;
                cout << "Hasil dari konversi Fahrenheit" << endl;
                cout << "Celcius: " << (suhu - 32) * 5/9 << endl;
                cout << "Reamur: " << (suhu - 32) * 4/9 << endl;
                cout << "Kelvin: " << (suhu - 32) * 5/9 + 273 << endl;
                break;
            case 3:
                cout << "========================================================================" << endl;
                cout << "Hasil dari konversi Reamur" << endl;
                cout << "Celcius: " << suhu * 5/4 << endl;
                cout << "Fahrenheit: " << (suhu * 9/4) + 32 << endl;
                cout << "Kelvin: " << suhu * 5/4 + 273 << endl;
                break;
            case 4:
                cout << "========================================================================" << endl;
                cout << "Hasil dari konversi Kelvin" << endl;
                cout << "Celcius: " << suhu - 273 << endl;
                cout << "Fahrenheit: " << (suhu - 273) * 9/5 + 32 << endl;
                cout << "Reamur: " << (suhu - 273) * 4/5 << endl;
                break;
        }
    }

    return 0;
}