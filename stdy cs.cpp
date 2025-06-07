#include <iostream>
using namespace std;

class Mahasiswa {
public:
    string nama;
    string nim;
    float nilai[4];
    float rataRata;
    char huruf;
    string status;

    void inputData(int i) {
        cout << "\n\t\t  ================================\n";
        cout << "\t\t   INPUT NILAI MAHASISWA\n";
        cout << "\t\t  ================================\n";
        cout << "Masukkan Nama Mahasiswa Ke-" << i+1 << " : ";
        cin.ignore(); getline(cin, nama);
        cout << "Masukkan NIM " << nama << " : ";
        getline(cin, nim);
        cout << "\nInput Nilai Alpro " << nama << " : ";
        cin >> nilai[0];
        cout << "Input Nilai Matdis " << nama << " : ";
        cin >> nilai[1];
        cout << "Input Nilai pWeb " << nama << " : ";
        cin >> nilai[2];
        cout << "Input Nilai Aljabar " << nama << " : ";
        cin >> nilai[3];
    }

    void hitungRata() {
        rataRata = (nilai[0] + nilai[1] + nilai[2] + nilai[3]) / 4;
        if (rataRata < 60) {
            huruf = 'D';
            status = "TIDAK LULUS";
        } else if (rataRata < 75) {
            huruf = 'C';
            status = "TIDAK LULUS";
        } else if (rataRata < 85) {
            huruf = 'B';
            status = "LULUS";
        } else {
            huruf = 'A';
            status = "LULUS";
        }
    }

    void tampilData() {
        cout << "\n\t\t  ================================\n";
        cout << "\t\t     DATA NILAI MAHASISWA\n";
        cout << "\t\t  ================================\n";
        cout << "Nama\t\t: " << nama << endl;
        cout << "NIM\t\t: " << nim << endl;
        cout << "Nilai Akhir Mahasiswa\t: " << rataRata << endl;
        cout << "Huruf\t\t: " << huruf << endl;
        cout << "Kelulusan\t: " << status << endl;
    }
};

int main() {
    int jumlah;
    int pilihan;
    float totalNilai = 0;
    
    cout << "Masukkan jumlah Mahasiswa : ";
    cin >> jumlah;

    Mahasiswa mhs[100];

    do {
        cout << "\n\t\t  ================================\n";
        cout << "\t\t\t\t MENU\n";
        cout << "\t\t  ================================\n";
        cout << "\t\t 1. Input Nilai\n";
        cout << "\t\t 2. Tampilkan Data Nilai\n";
        cout << "\t\t 3. Keluar\n";
        cout << "\t\t ================================\n";
        cout << "\t\t Masukkan Pilihan : ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                for (int i = 0; i < jumlah; i++) {
                    mhs[i].inputData(i);
                    mhs[i].hitungRata();
                }
                break;

            case 2:
                totalNilai = 0;
                for (int i = 0; i < jumlah; i++) {
                    mhs[i].tampilData();
                    totalNilai += mhs[i].rataRata;
                }
                cout << "\n\t\t  ================================\n";
                cout << "Jumlah Mahasiswa\t: " << jumlah << endl;
                cout << "Total Nilai Mahasiswa\t: " << totalNilai << endl;
                cout << "Rata-rata nilai Mahasiswa : " << totalNilai / jumlah << endl;
                break;

            case 3:
                cout << "\nTerima Kasih\n";
                break;

            default:
                cout << "Pilihan tidak tersedia!\n";
        }
    } while(pilihan != 3);

    return 0;
}

