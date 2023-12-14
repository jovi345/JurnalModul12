#include "flight.h"

void createListJadwal_1304212134(listJadwal &LJ)
{
	first(LJ) = NULL;
}

adr_jadwalP createElemenJadwal_1304212134(infotypeJadwal x)
{
	adr_jadwalP p;
	p = new elemenJadwal;
	info(p) = x;
	next(p) = NULL;
	return p;
}

void insertLastJ_1304212134(listJadwal &LJ, adr_jadwalP p)
{
	if (first(LJ) != NULL)
	{
		adr_jadwalP j = first(LJ);
		while (next(j) != NULL)
		{
			j = next(j);
		}
		next(j) = p;
	}
	else
	{
		first(LJ) = p;
	}
}

void showJadwal_1304212134(listJadwal LJ)
{
	adr_jadwalP j = first(LJ);

	cout << "=================JADWAL=================" << endl;
	while (j != NULL)
	{
		cout << "Kode: " << info(j).kode << endl;
		cout << "Jenis: " << info(j).jenis << endl;
		cout << "Tanggal: " << info(j).tanggal << endl;
		cout << "Waktu: " << info(j).waktu << endl;
		cout << "Asal: " << info(j).asal << endl;
		cout << "Tujuan: " << info(j).tujuan << endl;
		cout << "Kapasitas: " << info(j).kapasitas << endl;
		cout << endl;
		j = next(j);
	}
	cout << "=======================================" << endl;
}

void deleteFirstJ_1304212134(listJadwal &LJ, adr_jadwalP p)
{
	adr_jadwalP j = first(LJ);
	if (j == NULL)
	{
		p = NULL;
	}
	else if (next(j) == NULL)
	{
		first(LJ) = NULL;
	}
	else
	{
		j = next(j);
		next(p) = NULL;
	}
}

adr_jadwalP searchJ_1304212134(listJadwal LJ, string dari, string ke, string tanggal)
{
	adr_jadwalP j = first(LJ);
	while (j != NULL)
	{
		if (info(j).asal == dari && info(j).tujuan == ke && info(j).tanggal == tanggal)
		{
			return j;
		}
		j = next(j);
	}
	return NULL;
}

//=================================================
// Procedure dan function yang dikerjakan saat jurnal

void createListPenumpang_1304212134(listPenumpang &LP)
{
    first(LP) = NULL;
}

adr_penumpangP createElemenPenumpang_1304212134(infotypePenumpang x)
{
    adr_penumpangP p;
    p = new elemenPenumpang;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void insertLastP_1304212134(listPenumpang &LP, adr_penumpangP p)
{
    if (first(LP) != NULL)
    {
        adr_penumpangP curr;
        curr = first(LP);
        while (next(curr) != NULL)
        {
            curr = next(curr);
        }
        next(curr) = p;
    }
    else
    {
        first(LP) = p;
    }
}

void booking_1304212134(listPenumpang &LP, infotypePenumpang x, listJadwal LJ, string dari, string ke, string tanggal)
{
    adr_penumpangP newP = createElemenPenumpang_1304212134(x);
    adr_jadwalP j = searchJ_1304212134(LJ, dari, ke, tanggal);

    if (j != NULL)
    {
        jadwalP(newP) = j;
    }
    else
    {
        cout << "Jadwal tidak ditemukan\n";
    }
    insertLastP_1304212134(LP, newP);
}

void showPenumpang_1304212134(listPenumpang LP)
{
    if (first(LP) != NULL)
    {
        adr_penumpangP curr = first(LP);
        cout << "\n=================PENUMPANG=================\n";
        while (curr != NULL)
        {
            cout << "Nama: " << info(curr).nama << "\n";
            cout << "NIK: " << info(curr).nik << "\n";
            cout << "JenisKelamin: " << info(curr).jk << "\n";
            cout << "Usia: " << info(curr).usia << "\n";
            cout << "KodePenerbangan: " << curr->jadwalP->info.kode << "\n\n";
            curr = next(curr);
        }
        cout << "==========================================";
    }
    else
    {
        cout << "List penumpang kosong\n";
    }
}

void reschedule_1304212134(listPenumpang &LP, listJadwal LJ, string NIK, string newDari, string newKe, string newTanggal)
{
	adr_penumpangP p = first(LP);
  bool foundP;
	while (p != NULL)
    {
        if (info(p).nik == NIK)
        {
            foundP = true;
            break;
        }
        p = next(p);
        foundP = false;
    }

	adr_jadwalP j = first(LJ);
	bool foundJ;
	while (j != NULL)
    {
        if (j->info.tanggal == newTanggal)
        {
            foundJ = true;
            break;
        }
        j = next(j);
        foundJ = false;
    }

	if (foundP && foundJ)
    {
        p->jadwalP = j;
    }
}

void showAllListPenumpang_1304212134(listJadwal LJ, listPenumpang LP, string kode)
{
    adr_penumpangP curr = first(LP);
    int total = 0;
    cout << "\n=================PENUMPANG=================\n";
    while (curr != NULL)
    {
        if (curr->jadwalP->info.kode == kode)
        {
            cout << "Nama: " << curr->info.nama << "\n";
            cout << "NIK: " << curr->info.nik << "\n\n";
            total++;
        }
        curr = next(curr);
    }
    cout << "Total Penumpang: " << total;
    cout << "\n=========================================";
}
