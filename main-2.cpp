
#include <iostream>
#include <string>

using namespace std;

class AkilliTelefon {
private:
    string marka;
    string model;
    int batarya_yuzdesi;

public:
    AkilliTelefon(string telefon_markasi, string telefon_modeli, int ilk_sarj) {
        marka = telefon_markasi;
        model = telefon_modeli;
        if (ilk_sarj >= 0 && ilk_sarj <= 100) {
            batarya_yuzdesi = ilk_sarj;
        } else {
            batarya_yuzdesi = 100;
        }
    }

    void uygulama_calistir(int harcanacak_sarj) {
        if (harcanacak_sarj > 0) {
            if (batarya_yuzdesi - harcanacak_sarj < 0) {
                batarya_yuzdesi = 0;
            } else {
                batarya_yuzdesi -= harcanacak_sarj;
            }
        }
    }

    void telefonu_sarj_et(int dolum_miktari) {
        if (dolum_miktari > 0) {
            if (batarya_yuzdesi + dolum_miktari > 100) {
                batarya_yuzdesi = 100;
            } else {
                batarya_yuzdesi += dolum_miktari;
            }
        }
    }

    void telefonu_yazdir() {
        cout << "=== TELEFON BILGILERI ===" << endl;
        cout << "Marka: " << marka << " | Model: " << model << endl;
        cout << "Batarya Durumu: %" << batarya_yuzdesi << endl;
        if (batarya_yuzdesi == 0) {
            cout << "Uyari: Telefon kapandi!" << endl;
        }
    }
};

int main() {
    AkilliTelefon ilk_telefonum("Samsung", "Galaxy S23", 45);
    ilk_telefonum.telefonu_yazdir();

    cout << "\nOyun oynaniyor..." << endl;
    ilk_telefonum.uygulama_calistir(30);
    ilk_telefonum.telefonu_yazdir();

    cout << "\nTelefon sarja takiliyor..." << endl;
    ilk_telefonum.telefonu_sarj_et(50);
    ilk_telefonum.telefonu_yazdir();

    return 0;
}