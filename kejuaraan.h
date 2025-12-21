#ifndef KEJUARAAN_H
#define KEJUARAAN_H
#include <iostream>
using namespace std;

struct Peserta {
    int id;
    string nama;
    string asal;
};

struct Kejuaraan {
    int kode;
    string nama;
    string level;
};

struct ElmPeserta;
struct ElmKejuaraan;
struct ElmRelasi;

typedef ElmPeserta* adrPeserta;
typedef ElmKejuaraan* adrKejuaraan;
typedef ElmRelasi* adrRelasi;

struct ElmPeserta {
    Peserta info;
    adrPeserta next;
};

struct ElmRelasi {
    adrPeserta peserta;
    adrRelasi next;
};

struct ElmKejuaraan {
    Kejuaraan info;
    adrKejuaraan next;
    adrRelasi firstRelasi;
};

struct ListPeserta {
    adrPeserta first;
};

struct ListKejuaraan {
    adrKejuaraan first;
};

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


