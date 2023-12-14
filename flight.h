#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <iostream>
#include <string>

#define info(P) (P)->info
#define next(P) (P)->next
#define jadwalP(Q) (Q)->jadwalP
#define first(L) ((L).first)

using namespace std;
typedef struct elemenJadwal *adr_jadwalP;
typedef struct elemenPenumpang *adr_penumpangP;
typedef struct penumpang infotypePenumpang;
typedef struct jadwalPenerbangan infotypeJadwal;

struct penumpang
{
	string nama, nik, jk;
	int usia;
};

struct jadwalPenerbangan
{
	string kode, jenis, tanggal, waktu, asal, tujuan;
	int kapasitas;
};

struct elemenJadwal
{
	infotypeJadwal info;
	adr_jadwalP next;
};

struct elemenPenumpang
{
	infotypePenumpang info;
	adr_jadwalP jadwalP;
	adr_penumpangP next;
};

struct listPenumpang
{
	adr_penumpangP first;
};

struct listJadwal
{
	adr_jadwalP first;
};

void createListJadwal_1304212134(listJadwal &LJ);
adr_jadwalP createElemenJadwal_1304212134(infotypeJadwal x);
void insertLastJ_1304212134(listJadwal &LJ, adr_jadwalP p);
void showJadwal_1304212134(listJadwal LJ);
void deleteFirstJ_1304212134(listJadwal &LJ, adr_jadwalP p);
adr_jadwalP searchJ_1304212134(listJadwal LC, string dari, string ke, string tanggal);

// fungsi procedure tambahan untuk dikerjakan di jurnal
void createListPenumpang_1304212134(listPenumpang &LP);
adr_penumpangP createElemenPenumpang_1304212134(infotypePenumpang x);
void insertLastP_1304212134(listPenumpang &LP, adr_penumpangP p);
void booking_1304212134(listPenumpang &LP, infotypePenumpang x, listJadwal LJ, string dari, string ke, string tanggal);
void showPenumpang_1304212134(listPenumpang LP);
void reschedule_1304212134(listPenumpang &LP, listJadwal LJ, string NIK, string newDari, string newKe, string newTanggal);
void showAllListPenumpang_1304212134(listJadwal LJ, listPenumpang LP, string kode);

#endif // FLIGHT_H_INCLUDED
