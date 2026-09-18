#include <iostream>
#include <string>
using namespace std;

int main() {
    string pesan;

    //Memasukkan pesan
    cout << "Masukkan pesan: ";
    cin >> pesan;

    //Mengubah semua huruf menjadi huruf kapital
    for (int i = 0; i < pesan.length(); i++)
{ 
    if (pesan[i] >= 'a' && pesan[i] <= 'z') {
        pesan[i] = pesan[i] - 'a' + 'A';
    }
}

//Huruf pertama tidak mengalami perubahan
string hasil = "";
hasil += pesan[0];

//Memproses huruf berikutnya 
for (int i = 1; i < pesan.length(); i++)
{
    //Nilai huruf saat ini 
    int nilaiSekarang = pesan[i] - 'A' + 1;

    //Nilai huruf sebelumnya
    int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;

    //Menjumlahkan kedua nilai
    int nilaiBaru = nilaiSekarang + nilaiSebelumnya;

    //Jika melewati Z, kembali ke A
    if (nilaiBaru > 26) {
        nilaiBaru = nilaiBaru - 26;
    }

    //Mengubah nilai kembali menjadi huruf
    char hurufBaru = 'A' + nilaiBaru - 1;
    hasil += hurufBaru;
}

// Menampilkan hasil
cout << "Pesan asli : " << pesan << 
endl;
cout << "Pesan sandi : " << hasil <<
endl;

return 0;
}