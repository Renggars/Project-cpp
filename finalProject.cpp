#include<iostream>
#include<string>
using namespace std;

const string USERNAME = "kasir";
const string PASSWORD = "1";

struct MENU{
    /* data */
    string namaMenu;
    double harga;
    int stock;
};

struct pesanan{
    int nomorMenu;
    int jumlahPesan;
};

double diskon(double total, double diskon) {
    return total - (total * diskon / 100);
}

int main() {
    MENU menus[100];
    // int menuCount = 0;
    int menuCount = 1;
    menus[0].namaMenu = "Ayam";
    menus[0].harga = 10;
    menus[0].stock = 10;

    pesanan listOrder[100];
    int order = 0;
    
    bool selesai = false;
    bool ulang = false;

    double totalHarga = 0.0;

    cout<<"Selamat datang di cafe sederhana kami!"<<endl;
    cout<<"=================================================="<<endl;

    // MAIN CODE
    while(ulang == false) {
        totalHarga = 0.0;
        order = 0;
        cout<<"Pilih menu yang anda ingin gunakan : "<<endl;
        cout<<"1. Input menu"<<endl;
        cout<<"2. Menu dan Pemesanan"<<endl;

        int menu;
        cin>>menu;

        if(menu == 1) {
            cout<<"Masukkan username : ";
            string username;
            cin>>username;

            cout<<"Masukkan password : ";
            string password;
            cin>>password;

            if(username == USERNAME && password == PASSWORD) {
                
                system("cls");
                cout << "Pilih opsi: " << endl;
                cout << "1. Tambah menu baru" << endl;
                cout << "2. Modifikasi menu" << endl;
                int opsi;
                cin >> opsi;

                if (opsi == 1) {

                    // Input Menu Baru
                    cout<<"Masukkan nama menu \t: ";
                    string namaMenu;
                    cin.ignore();
                    getline(cin, namaMenu);

                    cout<<"Masukkan harga \t\t: ";
                    double harga;
                    cin>>harga;

                    cout<<"Masukkan stock \t\t: ";
                    int stock;
                    cin>>stock;

                    menus[menuCount].namaMenu = namaMenu;
                    menus[menuCount].harga = harga;
                    menus[menuCount].stock = stock;
                    menuCount++;

                } else if (opsi == 2) {
                    // Ubah menu yang sudah ada
                            cout << "Menu yang sudah tersedia : " << endl;
                            for (int i = 0; i < menuCount; i++) {
                                cout << i + 1 << ". " << menus[i].namaMenu << endl;
                            }

                            cout << "Pilih nomor menu yang ingin diubah : ";
                            int menuPilihan;
                            cin >> menuPilihan;

                            if (menuPilihan > 0 && menuPilihan <= menuCount) {
                                cout << "Menu yang dipilih : " << menus[menuPilihan - 1].namaMenu << endl;
                                cout << "Pilih opsi : " << endl;
                                cout << "1. Ubah harga" << endl;
                                cout << "2. Ubah stok" << endl;
                                int opsiUbah;
                                cin >> opsiUbah;

                                if (opsiUbah == 1) {
                                    cout << "Masukkan harga baru : ";
                                    double hargaBaru;
                                    cin >> hargaBaru;
                                    menus[menuPilihan - 1].harga = hargaBaru;
                                    cout << "Harga berhasil diubah menjadi Rp" << hargaBaru << endl;
                                } else if (opsiUbah == 2) {
                                    cout << "Masukkan stok baru : ";
                                    int stokBaru;
                                    cin >> stokBaru;
                                    menus[menuPilihan - 1].stock = stokBaru;
                                    cout << "Stok berhasil diubah menjadi " << stokBaru << endl;
                                } else {
                                    cout << "Opsi yang dimasukkan salah." << endl;

                                }
                            } else {
                                    cout << "Nomor menu yang dimasukkan salah." << endl;
                            }

                        } else {
                                    cout << "Nomor menu yang dimasukkan salah." << endl;
                        }

            } else {
                cout<<"Username atau password yang anda masukkan salah. Silahkan coba lagi."<<endl;
            }

        } else if (menu == 2) {
            //pemesanan
            cout<<endl;
            cout<<"DISKON"<<endl;
            cout<<"pembelian minimal Rp50 mendapat DISC 5% dari total belanja"<<endl;
            cout<<"========================================================================"<<endl;
            cout<<"No. | Nama Menu \t| Harga \t| Stock \t "<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;

            for(int i = 0; i < menuCount; i++) {
                cout<< i + 1 << ".  | " << menus[i].namaMenu<< " \t\t| Rp"<< menus[i].harga << " \t\t| "<< menus[i].stock<< endl;
            }

            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<endl;
            cout<<"MASUKKAN 0 JIKA SELESAI MELAKUKAN PEMESANAN"<<endl;
            cout<<"========================================================================"<<endl<<endl;
            if (ulang == false) {
                selesai = false;
            }
            while (selesai == false) {
                cout<<"Pilih menu : ";
                int nomorMenu;
                cin>>nomorMenu;

                if(nomorMenu == 0){
                    selesai = true;
                    break;
                }

                if (nomorMenu < 0 || nomorMenu > menuCount) {
                    cout<<"Nomor menu yang anda masukkan salah. Silahkan memasukkan nomor menu sesuai yang ada di daftar menu"<<endl;
                    cout<<endl;
                    continue;
                }

                if (nomorMenu <= menuCount) {
                        // Pemesanan menu
                    cout << "Masukkan jumlah pesanan : ";
                    cin >> listOrder[order].jumlahPesan;
                    listOrder[order].nomorMenu = nomorMenu;

                    if(listOrder[order].jumlahPesan < 0) {
                        cout<<"Jumlah pesanan yang anda masukkan salah. Silahkan coba lagi"<<endl<<endl;
                    // Cek ketersediaan stok

                    }else if (listOrder[order].jumlahPesan <= menus[nomorMenu - 1].stock) {
                        // Mengurangi stok sesuai dengan pesanan
                        menus[nomorMenu - 1].stock -= listOrder[order].jumlahPesan;
                        // Akumulasi totalharga
                        totalHarga += (menus[nomorMenu - 1].harga * listOrder[order].jumlahPesan);

                        cout << "Pesanan Anda untuk " << menus[nomorMenu - 1].namaMenu << " sebanyak " << listOrder[order].jumlahPesan << " telah dipesan." << endl;
                        cout << "Total harga sementara : Rp" << totalHarga <<endl<<endl;

                        order++;

                    } else if (menus[nomorMenu - 1].stock == 0) {
                        cout<<"Maaf, stok menu yang anda pilih sedang kosong. Silahkan coba lagi nanti atau pilih menu yang masih tersedia."<<endl<<endl;

                    } else {
                        cout<<"Maaf, stok menu tidak mencukupi untuk pesanan Anda."<<endl<<endl;
                    }
                }
            }

            cout << endl;
            cout << "INVOICE PEMBELIAN MENU CAFE SEDERHANA" << endl;
            cout<<"------------------------------------------------------------------------"<<endl;
            cout << "No. | Nama Menu \t| Harga \t| Jumlah \t| Subtotal" << endl;
            cout<<"------------------------------------------------------------------------"<<endl;

            double subtotalMenu[100];  // Tentukan array untuk menyimpan subtotal setiap menu

            for (int j = 0; j < order; ++j) {
                int jumlahPesan = listOrder[j].jumlahPesan;
                int nomorMenu = listOrder[j].nomorMenu ;
                
                subtotalMenu[j] = menus[nomorMenu - 1].harga * jumlahPesan;

                cout << j + 1 << ".  | " << menus[nomorMenu - 1].namaMenu << " \t\t| Rp" << menus[nomorMenu - 1].harga << " \t\t| " << jumlahPesan << " \t\t| Rp" << subtotalMenu[j] << endl;
            }

            cout<<"------------------------------------------------------------------------"<<endl;

            if (totalHarga >= 50) {
                cout<<"Anda mendapat diskon sebesar \t: Rp"<<totalHarga * 5 / 100<<endl;
                totalHarga = diskon(totalHarga, 5);
                cout<<"Total harga \t\t\t: Rp"<<totalHarga<<endl;
            } else {
            cout << "Total harga \t\t: Rp" << totalHarga << endl;
            }
        }
        cout<<endl;
        cout<<"========================================================================"<<endl;
        cout<<"Apakah anda ingin menggunakan program lagi ? (y/n)"<<endl;
        string ulangi;
        cin>>ulangi;
        if(ulangi == "n") {
            ulang = true;
        } else {
            system("cls");
        }
    }
    system("cls");
    cout<<"Program Selesai"<<endl;
}