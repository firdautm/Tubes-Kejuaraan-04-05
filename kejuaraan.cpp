#include "kejuaraan.h"

void createListPeserta(ListPeserta &LP) {
    LP.first = NULL;
}

void createListKejuaraan(ListKejuaraan &LK) {
    LK.first = NULL;
}

adrPeserta createPeserta(int id, string nama, string asal) {
    adrPeserta P = new ElmPeserta;
    P->info.id = id;
    P->info.nama = nama;
    P->info.asal = asal;
    P->next = NULL;
    return P;
}

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

adrPeserta findPeserta(ListPeserta LP, int id) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.id == id)
            return P;
        P = P->next;
    }
    return NULL;
}

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

/* ================= KEJUARAAN ================= */
adrKejuaraan createKejuaraan(int kode, string nama, string level) {
    adrKejuaraan K = new ElmKejuaraan;
    K->info.kode = kode;
    K->info.nama = nama;
    K->info.level = level;
    K->firstRelasi = NULL;
    K->next = NULL;
    return K;
}

void insertKejuaraanFirst(ListKejuaraan &LK, adrKejuaraan K) {
    K->next = LK.first;
    LK.first = K;
}

adrKejuaraan findKejuaraan(ListKejuaraan LK, int kode) {
    adrKejuaraan K = LK.first;
    while (K != NULL) {
        if (K->info.kode == kode)
            return K;
        K = K->next;
    }
    return NULL;
}

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

/* ================= RELASI ================= */
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

/* ================= DISPLAY ================= */
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

/* ================= STATISTIK ================= */
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
