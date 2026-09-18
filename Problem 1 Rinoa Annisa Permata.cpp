#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    long long K;

    //input jumlah astronaut sebagai nilai K 
    cout << "Masukan jumlah astronaut (N) :";
    cin >> N;
    cout << "Masukkan nilai K: ";
    cin >> K;

    //Membuat daftar astronaut 1 sampai N 
    vector<int> astronaut;

    for (int i = 1; i <= N; i++) {
        astronaut.push_back(i);
    }

    int index = 0;

    cout << "\nUrutan astronaut yang dieliminasi : \n";

    //Proses eliminasi sampai tersisa satu astronaut
    while (astronaut.size() > 1) {

        //Menentukan posisi astronaut yang dieliminasi
        int posisi = (index +  K - 1) % astronaut.size();

        //Menyimpan nomor astronaut yang dieliminasi
        int tereliminasi = astronaut[posisi];

        //Menampilkan astronaut yang dieliminasi
        cout << tereliminasi << " ";

        //Menghapus astronaut dari vector 
        astronaut.erase(astronaut.begin() + posisi);

        //Mengubah nilai K
        if (tereliminasi % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }

        //K tidak boleh kurang dari 2
        if (K < 2) {
            K = 2;
        }

        // KSetelah penghapusan, perhitungan dilanjutkan dari astronaut setelah astronaut yang dihapus
        if (!astronaut.empty()) {
            index = posisi % astronaut.size();
        }
    }

    //Menampilkan astronaut terakhir
    cout << "\n\nAstronaut terakhir yang bertahan : "
    << astronaut[0] << endl;

    return 0;
}