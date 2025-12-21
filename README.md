Program ini dibuat untuk mengelola data peserta dan kejuaraan menggunakan konsep Multi Linked List. Program memungkinkan pengguna untuk menambahkan data peserta dan kejuaraan, menghubungkan peserta ke satu atau lebih kejuaraan, menampilkan relasi antara peserta dan kejuaraan, serta menampilkan statistik berdasarkan data yang tersimpan. Seluruh interaksi dilakukan melalui menu pada terminal.

# HEADER
## Peserta
```cpp
struct Peserta {
    int id;
    string nama;
    string asal;
};
struct ElmPeserta {
    Peserta info;
    ElmPeserta *next;
};
struct ListPeserta {
    ElmPeserta *first;
};
```
Struktur Peserta digunakan untuk menyimpan informasi dasar peserta. Setiap peserta memiliki identitas unik berupa id, nama peserta, dan asal peserta. Struktur ElmPeserta merupakan node pada linked list peserta. Setiap node menyimpan satu data peserta dan pointer next yang menunjuk ke peserta berikutnya dalam list. Struktur ListPeserta digunakan untuk menyimpan alamat elemen pertama dari linked list peserta. Jika list kosong, pointer first bernilai NULL. 

## Kejuaraan
```cpp
struct Kejuaraan {
    int kode;
    string nama;
    string level;
};
struct ElmKejuaraan {
    Kejuaraan info;
    ElmKejuaraan *next;
    ElmRelasi *firstRelasi;
};
struct ListKejuaraan {
    ElmKejuaraan *first;
};
```
Struktur Kejuaraan menyimpan informasi kejuaraan, yang terdiri dari kode kejuaraan sebagai identitas unik, nama kejuaraan, dan level kejuaraan. Struktur ElmKejuaraan merupakan node pada linked list kejuaraan. Selain pointer next untuk menunjuk ke kejuaraan berikutnya, struktur ini memiliki pointer firstRelasi yang menunjuk ke daftar relasi peserta yang mengikuti kejuaraan tersebut. Struktur ListKejuaraan menyimpan alamat elemen pertama dari linked list kejuaraan. Melalui list ini, seluruh data kejuaraan dan relasinya dapat diakses.

## Relasi
```cpp
struct ElmRelasi {
    ElmPeserta *peserta;
    ElmRelasi *next;
};
```
Blok ini digunakan untuk membentuk relasi antara peserta dan kejuaraan.
Setiap elemen relasi menyimpan pointer ke satu peserta dan pointer ke relasi berikutnya.
Struktur ini memungkinkan satu peserta mengikuti banyak kejuaraan, sehingga membentuk relasi many-to-many.`

## Deklarasi Fungsi Dan Prosedur
```cpp
void createListPeserta(ListPeserta &LP);
void createListKejuaraan(ListKejuaraan &LK);
adrPeserta createPeserta(int id, string nama, string asal);
void insertPesertaLast(ListPeserta &LP, adrPeserta P);
adrPeserta findPeserta(ListPeserta LP, int id);
void deletePeserta(ListPeserta &LP, ListKejuaraan &LK, int id);
adrKejuaraan createKejuaraan(int kode, string nama, string level);
void insertKejuaraanFirst(ListKejuaraan &LK, adrKejuaraan K);
adrKejuaraan findKejuaraan(ListKejuaraan LK, int kode);
void deleteKejuaraan(ListKejuaraan &LK, int kode);
void addRelasi(ListKejuaraan &LK, int kodeKejuaraan, adrPeserta P);
void showAllPeserta(ListPeserta LP, ListKejuaraan LK);
void showPesertaByKejuaraan(ListKejuaraan LK, int kode);
void showKejuaraanByPeserta(ListKejuaraan LK, int id);
void showStatistik(ListPeserta LP, ListKejuaraan LK);

#endif
```
**createListPeserta** digunakan untuk menginisialisasi list peserta agar berada dalam kondisi kosong sebelum digunakan.

**createListKejuaraan** digunakan untuk menginisialisasi list kejuaraan agar siap menampung data kejuaraan.

**tambahPeserta** digunakan untuk menerima input data peserta dari pengguna dan menyimpannya ke dalam list peserta.

**tambahKejuaraan** digunakan untuk menerima input data kejuaraan dari pengguna dan menyimpannya ke dalam list kejuaraan.

**relasikanPesertaKeKejuaraan** digunakan untuk menghubungkan seorang peserta dengan kejuaraan tertentu melalui struktur relasi.

**hapusPeserta** digunakan untuk menghapus data peserta dari list beserta seluruh relasi yang terkait.

**hapusKejuaraan** digunakan untuk menghapus data kejuaraan dari list beserta seluruh relasi pesertanya.

**tampilPesertaDanKejuaraan** digunakan untuk menampilkan data peserta beserta kejuaraan yang diikutinya.

**statistikKejuaraan** digunakan untuk menampilkan kejuaraan yang paling diminati serta peserta yang paling sedikit mengikuti kejuaraan.

# KEJUARAAN.CPP
## createListPeserta
```cpp
void createListPeserta(ListPeserta &LP) {
    LP.first = NULL;
}
```
Prosedur createListPeserta berfungsi untuk menginisialisasi list peserta dengan cara mengatur pointer first agar bernilai NULL. Hal ini menandakan bahwa list peserta masih kosong dan siap digunakan untuk menyimpan data baru.

## createListKejuaraan
```cpp
void createListKejuaraan(ListKejuaraan &LK) {
    LK.first = NULL;
}
```
Prosedur createListKejuaraan bekerja dengan logika yang sama, yaitu menginisialisasi list kejuaraan dengan mengatur pointer first menjadi NULL. Dengan demikian, list kejuaraan berada dalam kondisi awal yang aman sebelum dilakukan operasi lain.

## createPeserta
```cpp
adrPeserta createPeserta(int id, string nama, string asal) {
    adrPeserta P = new ElmPeserta;
    P->info.id = id;
    P->info.nama = nama;
    P->info.asal = asal;
    P->next = NULL;
    return P;
}
```
Prosedur tambahPeserta menerima input data peserta dari pengguna, kemudian membuat node peserta baru. Node tersebut dihubungkan ke dalam linked list peserta, sehingga data peserta tersimpan secara dinamis. Prosedur ini memastikan bahwa peserta baru berhasil ditambahkan ke struktur data.

## insertPesertaLast 
```cpp
void insertPesertaLast(ListPeserta &LP, adrPeserta P) {
    if (LP.first == NULL) {
        LP.first = P;
    } else {
        adrPeserta Q = LP.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
}
```
Prosedur insertPesertaLast digunakan untuk memasukkan node peserta ke bagian akhir linked list peserta. Jika list masih kosong, node peserta langsung menjadi elemen pertama. Jika list sudah berisi data, prosedur akan menelusuri list hingga elemen terakhir, lalu menghubungkan node baru di bagian akhir.

## findPeserta
```cpp
adrPeserta findPeserta(ListPeserta LP, int id) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.id == id)
            return P;
        P = P->next;
    }
    return NULL;
}
```
Fungsi findPeserta digunakan untuk mencari peserta berdasarkan id. Proses pencarian dilakukan dengan menelusuri linked list peserta dari awal hingga akhir. Jika peserta dengan id yang dicari ditemukan, fungsi mengembalikan alamat node peserta tersebut, jika tidak maka mengembalikan NULL.

## deletePeserta
```cpp
void deletePeserta(ListPeserta &LP, ListKejuaraan &LK, int id) {
    adrPeserta P = LP.first, prev = NULL;

    while (P != NULL && P->info.id != id) {
        prev = P;
        P = P->next;
    }

    if (P == NULL) {
        cout << "Peserta tidak ditemukan\n";
        return;
    }

    adrKejuaraan K = LK.first;
    while (K != NULL) {
        adrRelasi R = K->firstRelasi, pr = NULL;
        while (R != NULL) {
            if (R->peserta == P) {
                if (pr == NULL)
                    K->firstRelasi = R->next;
                else
                    pr->next = R->next;
                delete R;
                break;
            }
            pr = R;
            R = R->next;
        }
        K = K->next;
    }

    if (prev == NULL)
        LP.first = P->next;
    else
        prev->next = P->next;

    delete P;
    cout << "Peserta berhasil dihapus\n";
}
```
Prosedur deletePeserta digunakan untuk menghapus data peserta dari list peserta. Prosedur ini terlebih dahulu mencari peserta berdasarkan id. Jika peserta tidak ditemukan, program menampilkan pesan kesalahan. Jika ditemukan, prosedur akan menghapus seluruh relasi peserta tersebut dari setiap kejuaraan, kemudian menghapus node peserta dari linked list dan menampilkan pesan bahwa peserta berhasil dihapus.

## createKejuaraan
```cpp
adrKejuaraan createKejuaraan(int kode, string nama, string level) {
    adrKejuaraan K = new ElmKejuaraan;
    K->info.kode = kode;
    K->info.nama = nama;
    K->info.level = level;
    K->firstRelasi = NULL;
    K->next = NULL;
    return K;
}
```
Fungsi createKejuaraan digunakan untuk membuat node kejuaraan baru. Fungsi ini mengalokasikan memori, mengisi data kode, nama, dan level kejuaraan, menginisialisasi pointer relasi menjadi NULL, serta mengatur pointer next menjadi NULL. Node kejuaraan yang telah dibuat kemudian dikembalikan.

## insertKejuaraanFirst
```cpp
void insertKejuaraanFirst(ListKejuaraan &LK, adrKejuaraan K) {
    K->next = LK.first;
    LK.first = K;
}
```
Prosedur insertKejuaraanFirst digunakan untuk menambahkan node kejuaraan di awal linked list kejuaraan. Node baru langsung diarahkan ke elemen pertama sebelumnya, kemudian dijadikan sebagai elemen pertama yang baru.

## findKejuaraan
```cpp
adrKejuaraan findKejuaraan(ListKejuaraan LK, int kode) {
    adrKejuaraan K = LK.first;
    while (K != NULL) {
        if (K->info.kode == kode)
            return K;
        K = K->next;
    }
    return NULL;
}
```
Fungsi findKejuaraan digunakan untuk mencari data kejuaraan berdasarkan kode. Proses pencarian dilakukan dengan menelusuri linked list kejuaraan. Jika data ditemukan, fungsi mengembalikan alamat node kejuaraan, jika tidak maka mengembalikan NULL.

## deleteKejuaraan
```cpp
void deleteKejuaraan(ListKejuaraan &LK, int kode) {
    adrKejuaraan K = LK.first, prev = NULL;

    while (K != NULL && K->info.kode != kode) {
        prev = K;
        K = K->next;
    }

    if (K == NULL) {
        cout << "Kejuaraan tidak ditemukan\n";
        return;
    }

    adrRelasi R = K->firstRelasi;
    while (R != NULL) {
        adrRelasi temp = R;
        R = R->next;
        delete temp;
    }

    if (prev == NULL)
        LK.first = K->next;
    else
        prev->next = K->next;

    delete K;
    cout << "Kejuaraan berhasil dihapus\n";
}
```
Prosedur deleteKejuaraan digunakan untuk menghapus data kejuaraan dari list kejuaraan. Prosedur ini mencari kejuaraan berdasarkan kode, kemudian menghapus seluruh relasi peserta yang terhubung dengan kejuaraan tersebut. Setelah itu, node kejuaraan dihapus dari linked list dan program menampilkan pesan bahwa kejuaraan berhasil dihapus.

## addRelasi
```cpp
void addRelasi(ListKejuaraan &LK, int kodeKejuaraan, adrPeserta P) {
    adrKejuaraan K = findKejuaraan(LK, kodeKejuaraan);
    if (K == NULL) return;

    adrRelasi R = K->firstRelasi;
    while (R != NULL) {
        if (R->peserta == P) {
            cout << "Peserta sudah terdaftar pada kejuaraan ini\n";
            return;
        }
        R = R->next;
    }

    adrRelasi baru = new ElmRelasi;
    baru->peserta = P;
    baru->next = K->firstRelasi;
    K->firstRelasi = baru;

    cout << "Relasi berhasil ditambahkan\n";
}
```
Prosedur addRelasi digunakan untuk menambahkan hubungan antara peserta dan kejuaraan. Prosedur ini mencari kejuaraan berdasarkan kode, lalu mengecek apakah peserta sudah terdaftar pada kejuaraan tersebut. Jika belum, maka dibuat node relasi baru yang menghubungkan peserta dengan kejuaraan tersebut dan disisipkan ke dalam daftar relasi.

## showAllPeserta
```cpp
void showAllPeserta(ListPeserta LP, ListKejuaraan LK) {
    adrPeserta P = LP.first;

    while (P != NULL) {
        cout << "Peserta " << P->info.nama
             << " (asal: " << P->info.asal << ") mengikuti kejuaraan: ";

        adrKejuaraan K = LK.first;
        bool pertama = true;
        bool ada = false;

        while (K != NULL) {
            adrRelasi R = K->firstRelasi;
            while (R != NULL) {
                if (R->peserta == P) {
                    if (!pertama)
                        cout << ", ";
                    cout << K->info.nama;
                    pertama = false;
                    ada = true;
                }
                R = R->next;
            }
            K = K->next;
        }

        if (!ada)
            cout << "belum mengikuti kejuaraan";

        cout << endl;
        P = P->next;
    }
}
```
Prosedur showAllPeserta digunakan untuk menampilkan seluruh peserta beserta kejuaraan yang diikutinya. Prosedur ini menelusuri list peserta dan, untuk setiap peserta, menelusuri list kejuaraan serta relasinya untuk menentukan kejuaraan apa saja yang diikuti. Jika peserta belum mengikuti kejuaraan apa pun, program akan menampilkan keterangan yang sesuai.

## showPesertaByKejuaraan
```cpp
void showPesertaByKejuaraan(ListKejuaraan LK, int kode) {
    adrKejuaraan K = findKejuaraan(LK, kode);
    if (K == NULL) {
        cout << "Kejuaraan tidak ditemukan\n";
        return;
    }

    cout << "Kejuaraan " << K->info.nama << " diikuti oleh peserta: ";

    adrRelasi R = K->firstRelasi;
    bool pertama = true;

    if (R == NULL) {
        cout << "belum ada peserta\n";
        return;
    }

    while (R != NULL) {
        if (!pertama)
            cout << ", ";
        cout << R->peserta->info.nama;
        pertama = false;
        R = R->next;
    }
    cout << endl;
}
```
Logika fungsi ini dimulai dengan mencari kejuaraan berdasarkan kode. Jika kejuaraan tidak ditemukan, program langsung berhenti dan menampilkan pesan kesalahan.

Jika kejuaraan ditemukan, program langsung menelusuri list relasi milik kejuaraan tersebut. Setiap relasi di dalam list ini sudah pasti menunjuk ke peserta yang mengikuti kejuaraan tersebut, sehingga program cukup menampilkan nama peserta dari setiap relasi yang ada.

Apabila list relasi kosong, berarti kejuaraan tersebut belum memiliki peserta, sehingga program menampilkan keterangan yang sesuai.

## showKejuaraanByPeserta
```cpp
void showKejuaraanByPeserta(ListKejuaraan LK, int id) {
    adrKejuaraan K = LK.first;
    bool pertama = true;
    bool ketemu = false;
    string nama = "";

    while (K != NULL) {
        adrRelasi R = K->firstRelasi;
        while (R != NULL) {
            if (R->peserta->info.id == id) {
                if (!ketemu) {
                    nama = R->peserta->info.nama;
                    cout << nama << " mengikuti kejuaraan: ";
                    ketemu = true;
                }
                if (!pertama)
                    cout << ", ";
                cout << K->info.nama;
                pertama = false;
            }
            R = R->next;
        }
        K = K->next;
    }

    if (!ketemu)
        cout << "Peserta tidak mengikuti kejuaraan apapun";

    cout << endl;
}
```
Logika fungsi ini kebalikan dari fungsi sebelumnya. Program tidak langsung tahu kejuaraan apa yang diikuti peserta, sehingga proses dimulai dengan menelusuri seluruh list kejuaraan.

Pada setiap kejuaraan, program menelusuri list relasi untuk mengecek apakah ada relasi yang menunjuk ke peserta dengan id yang dicari. Jika ditemukan relasi pertama, program menampilkan nama peserta dan mulai mencetak daftar kejuaraan yang diikutinya.

Selanjutnya, setiap kejuaraan lain yang juga memiliki relasi ke peserta tersebut akan ditambahkan ke daftar. Jika setelah seluruh kejuaraan dicek tidak ditemukan relasi apa pun, maka program menampilkan pesan bahwa peserta tidak mengikuti kejuaraan apa pun.

## showStatistik
```cpp
void showStatistik(ListPeserta LP, ListKejuaraan LK) {
    adrKejuaraan K = LK.first;
    int max = -1;
    string favorit = "";

    while (K != NULL) {
        int count = 0;
        adrRelasi R = K->firstRelasi;
        while (R != NULL) {
            count++;
            R = R->next;
        }

        if (count > max) {
            max = count;
            favorit = K->info.nama;
        }
        K = K->next;
    }

    if (max >= 0)
        cout << "Kejuaraan paling diminati adalah: " << favorit << endl;

    adrPeserta P = LP.first;
    int min = 999;
    string palingSedikit = "";

    while (P != NULL) {
        int count = 0;
        K = LK.first;

        while (K != NULL) {
            adrRelasi R = K->firstRelasi;
            while (R != NULL) {
                if (R->peserta == P)
                    count++;
                R = R->next;
            }
            K = K->next;
        }

        if (count < min) {
            min = count;
            palingSedikit = P->info.nama;
        }
        P = P->next;
    }

    if (palingSedikit != "")
        cout << "Peserta yang paling sedikit mengikuti kejuaraan adalah: "
             << palingSedikit << endl;
}
```
Logika fungsi ini diawali dengan menelusuri seluruh list kejuaraan untuk mengetahui tingkat minat peserta pada setiap kejuaraan. Untuk setiap kejuaraan, program menghitung jumlah peserta dengan cara menelusuri list relasi yang dimiliki kejuaraan tersebut. Setiap relasi merepresentasikan satu peserta yang mengikuti kejuaraan, sehingga jumlah relasi menunjukkan jumlah peserta.

Hasil perhitungan tersebut kemudian dibandingkan untuk menentukan kejuaraan dengan jumlah peserta terbanyak. Kejuaraan yang memiliki jumlah relasi paling besar disimpan sebagai kejuaraan yang paling diminati dan ditampilkan sebagai hasil statistik pertama.

Setelah itu, fungsi melanjutkan proses dengan menelusuri seluruh list peserta untuk menentukan peserta yang paling sedikit mengikuti kejuaraan. Untuk setiap peserta, program kembali menelusuri seluruh kejuaraan dan relasinya untuk menghitung berapa kali peserta tersebut muncul dalam relasi. Jumlah kemunculan ini menunjukkan berapa kejuaraan yang diikuti oleh peserta tersebut.

Nilai jumlah keikutsertaan peserta kemudian dibandingkan untuk menentukan peserta dengan jumlah kejuaraan paling sedikit. Peserta dengan jumlah keikutsertaan terendah disimpan dan ditampilkan sebagai hasil statistik kedua. Dengan cara ini, fungsi statistik memberikan gambaran tingkat minat terhadap kejuaraan dan tingkat keaktifan peserta berdasarkan data relasi yang tersimpan.

# MAIN
## Deklarasi Variabel
```cpp
int main() {
    ListPeserta LP;
    ListKejuaraan LK;
    createListPeserta(LP);
    createListKejuaraan(LK);
    int pilih;
```
Pada awal fungsi main, program mendeklarasikan dua buah variabel, yaitu LP bertipe ListPeserta dan LK bertipe ListKejuaraan. Kedua variabel ini digunakan sebagai wadah utama untuk menyimpan seluruh data peserta dan kejuaraan selama program berjalan. Program kemudian memanggil prosedur createListPeserta dan createListKejuaraan untuk menginisialisasi kedua list agar berada dalam kondisi kosong sebelum digunakan.

Selanjutnya, program mendeklarasikan variabel pilih yang digunakan untuk menyimpan pilihan menu dari pengguna. Program kemudian masuk ke dalam perulangan do-while yang berfungsi untuk menampilkan menu secara berulang sampai pengguna memilih menu keluar.

## Pilihan Menu
```cpp
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
```

## Pilihan-pilihan
```cpp
if (pilih == 1) {
            int id
            string nama, asal;
            cout << "ID Peserta: ";
            cin >> id;
            cout << "Nama Peserta: ";
            cin >> nama;
            cout << "Asal Peserta: ";
            cin >> asal;



            insertPesertaLast(LP, createPeserta(id, nama, asal));
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
```
Setiap pilihan menu mengarahkan program untuk melakukan proses tertentu, seperti menambahkan data peserta dan kejuaraan, menghubungkan peserta ke kejuaraan, menghapus data peserta atau kejuaraan beserta relasinya, menampilkan data peserta dan kejuaraan, menampilkan data berdasarkan relasi tertentu, serta menampilkan statistik kejuaraan. Program akan terus menampilkan menu dan memproses input pengguna hingga pengguna memilih menu keluar, yang menandakan bahwa program selesai dijalankan.
