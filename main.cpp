#include "flight.h"

int main()
{
    listJadwal LJ;
    infotypeJadwal x;
    adr_jadwalP j;
    createListJadwal_1304212134(LJ);

    cout << "Input Penerbangan\n";
	int i = 0;
	while (i < 4)
	{
    	i++;
    	cout << "Data ke-" << i;
    	cout << "\nKode: ";
    	cin >> x.kode;
    	cout << "Jenis: ";
    	cin >> x.jenis;
    	cout << "Tanggal: ";
    	cin >> x.tanggal;
    	cout << "Waktu: ";
    	cin >> x.waktu;
    	cout << "Asal: ";
    	cin >> x.asal;
    	cout << "Tujuan: ";
    	cin >> x.tujuan;
    	cout << "Kapasitas: ";
    	cin >> x.kapasitas;
    	cout << "\n";
    	j  = createElemenJadwal_1304212134(x);
        insertLastJ_1304212134(LJ, j);
	}
    showJadwal_1304212134(LJ);

    listPenumpang LP;
    adr_penumpangP p;
    infotypePenumpang penumpang;
    string asal, tujuan, tanggal;
    createListPenumpang_1304212134(LP);

    cout << "\nInput jadwal\n";
    int k = 0;
    while (k < 6)
    {
        k++;
        cout << "\nData ke-" << k;
        cout << "\nNama: ";
        cin >> penumpang.nama;
        cout << "NIK: ";
        cin >> penumpang.nik;
        cout << "Jenis Kelamin: ";
        cin >> penumpang.jk;
        cout << "Usia: ";
        cin >> penumpang.usia;
        cout << "Asal Penerbangan: ";
        cin >> asal;
        cout << "Tujuan Penerbangan: ";
        cin >> tujuan;
        cout << "Tanggal Penerbangan: ";
        cin >> tanggal;
        booking_1304212134(LP, penumpang, LJ, asal, tujuan, tanggal);
    }
    showPenumpang_1304212134(LP);

    string kode;
    cout << "\nTampilkan Penumpang Berdasarkan Kode Penerbangan";
    cout << "\nKode: ";
    cin >> kode;
    showAllListPenumpang_1304212134(LJ, LP, kode);

    string NIK, newDari, newKe, newTanggal;
    cout << "\nNIK: ";
    cin >> NIK;
    cout << "Asal: ";
    cin >> newDari;
    cout << "Tujuan: ";
    cin >> newKe;
    cout << "Tanggal: ";
    cin >> newTanggal;

    reschedule_1304212134(LP, LJ, NIK, newDari, newKe, newTanggal);

    showAllListPenumpang_1304212134(LJ, LP, kode);

    return 0;
}
