#include "kejuaraan.h"

int main() {
    ListPeserta LP;
    ListKejuaraan LK;
    createListPeserta(LP);
    createListKejuaraan(LK);

    int pilih;

    do {
        cout << "\n===== MENU DATA KEJUARAAN =====";
        cout << "\n1. Tambah Peserta";
        cout << "\n2. Tambah Kejuaraan";
        cout << "\n3. Hubungkan Peserta ke Kejuaraan";
        cout << "\n4. Hapus Peserta";
        cout << "\n5. Hapus Kejuaraan";
        cout << "\n6. Tampilkan Semua Peserta & Kejuaraan";
        cout << "\n7. Tampilkan Peserta pada Kejuaraan";
        cout << "\n8. Tampilkan Kejuaraan yang Diikuti Peserta";
        cout << "\n9. Statistik Kejuaraan";
        cout << "\n0. Keluar";
        cout << "\nPilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            int id, umur;
            string nama;
            cout << "ID Peserta: ";
            cin >> id;
            cout << "Nama Peserta: ";
            cin >> nama;
           string asal;
           cout << "Asal Peserta: ";
           cin >> asal;


            insertPesertaLast(LP, createPeserta(id, nama, umur));
        }

        else if (pilih == 2) {
            int kode;
            string nama, level;
            cout << "Kode Kejuaraan: ";
            cin >> kode;
            cout << "Nama Kejuaraan: ";
            cin >> nama;
            cout << "Level: ";
            cin >> level;

            insertKejuaraanFirst(LK, createKejuaraan(kode, nama, level));
        }

        else if (pilih == 3) {
            int id, kode;
            cout << "ID Peserta: ";
            cin >> id;
            cout << "Kode Kejuaraan: ";
            cin >> kode;

            adrPeserta P = findPeserta(LP, id);
            if (P != NULL) {
                addRelasi(LK, kode, P);
                cout << "Relasi berhasil dibuat\n";
            } else {
                cout << "Peserta tidak ditemukan\n";
            }
        }

        else if (pilih == 4) {
            int id;
            cout << "ID Peserta yang dihapus: ";
            cin >> id;
            deletePeserta(LP, LK, id);
        }

        else if (pilih == 5) {
            int kode;
            cout << "Kode Kejuaraan yang dihapus: ";
            cin >> kode;
            deleteKejuaraan(LK, kode);
        }

        else if (pilih == 6) {
            showAllPeserta(LP, LK);
        }

        else if (pilih == 7) {
            int kode;
            cout << "Kode Kejuaraan: ";
            cin >> kode;
            showPesertaByKejuaraan(LK, kode);
        }

        else if (pilih == 8) {
            int id;
            cout << "ID Peserta: ";
            cin >> id;
            showKejuaraanByPeserta(LK, id);
        }

        else if (pilih == 9) {
            showStatistik(LP, LK);
        }

    } while (pilih != 0);

    return 0;
}
