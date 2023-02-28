#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <windows.h>

using namespace std;

string to_str(int input) {
    stringstream wadah;
    string result;
    wadah << input;
    wadah >> result;
    return result;
}

int to_int(string input) {
    stringstream wadah;
    int result;
    wadah << input;
    wadah >> result;
    return result;
}

int tanggal(int date, int* pointer_bulan, int* pointer_tahun) {
    if (date <= 30) {
        if (*pointer_bulan == 13) {
            *pointer_bulan = 1;
            *pointer_tahun += 1;
        } 
        if (*pointer_bulan == 2 and date >= 29) {
            if (*pointer_tahun % 100 != 0) {
                if (*pointer_tahun % 4 == 0) {
                    if (date == 29)return date;
                    *pointer_bulan += 1;
                    return(tanggal(date - 29, pointer_bulan, pointer_tahun));
                }
                else {
                    *pointer_bulan += 1;
                    return(tanggal(date - 28, pointer_bulan, pointer_tahun));
                }
            }
            else {
                if (*pointer_tahun % 400 == 0) {
                    if (date == 29)return date;
                    *pointer_bulan += 1;
                    return(tanggal(date - 29, pointer_bulan, pointer_tahun));
                }
                else {
                    *pointer_bulan += 1;
                    return(tanggal(date - 28, pointer_bulan, pointer_tahun));
                }
            }
        }
        return date;
    }
    else {
        if ((*pointer_bulan % 2 == 1 and *pointer_bulan != 2 and *pointer_bulan <= 7) or (*pointer_bulan % 2 == 0 and *pointer_bulan > 7)) {
            if (date == 31) return date;
            *pointer_bulan += 1;
            if (*pointer_bulan == 13) {
                *pointer_bulan = 1; *pointer_tahun += 1;
            }
            return(tanggal(date - 31, pointer_bulan, pointer_tahun));
        }
        if (*pointer_bulan == 2) {
            if (*pointer_tahun % 100 != 0) {
                if (*pointer_tahun % 4 == 0) {
                    *pointer_bulan += 1;
                    return(tanggal(date - 29, pointer_bulan, pointer_tahun));
                }
                else {
                    *pointer_bulan += 1;
                    return(tanggal(date - 28, pointer_bulan, pointer_tahun));
                }
            }
            else {
                if (*pointer_tahun % 400 == 0) {
                    *pointer_bulan += 1;
                    return(tanggal(date - 29, pointer_bulan, pointer_tahun));
                }
                else {
                    *pointer_bulan += 1;
                    return(tanggal(date - 28, pointer_bulan, pointer_tahun));
                }
            }
        }
        else
        {
            *pointer_bulan += 1;
            return(tanggal(date - 30, pointer_bulan, pointer_tahun));
        }
    }
}

string checkout(string date, string month, string year, int duration) {
    int wadah_tanggal, wadah_bulan, wadah_tahun;
    string result;
    wadah_tanggal = to_int(date);
    wadah_tanggal += duration;
    wadah_bulan = to_int(month);
    wadah_tahun = to_int(year);
    if (wadah_tanggal >= 29) {
        wadah_tanggal = tanggal(wadah_tanggal, &wadah_bulan, &wadah_tahun);
    }
    if (wadah_tanggal < 10) date = "0" + to_str(wadah_tanggal);
    else date = to_str(wadah_tanggal);
    if (wadah_bulan < 10) month = "0" + to_str(wadah_bulan);
    else month = to_str(wadah_bulan);
    year = to_str(wadah_tahun);
    result = date + "/" + month + "/" + year;
    return result;
}

int margin_left(int length, string var) {
    int temp = (length - var.length()) / 2;
    return temp;
}

int margin_right(int length, string var) {
    float temp = (length - var.length()) / 2.0;
    int spaces = int(temp);
    if (temp - spaces != 0)
        return spaces + 1;
    else {
        return spaces;
    }
}


int main()
{
    char ulangi, pesan, cetak_bukti, bulan_pesan[10];
    int stok_reguler = 10, stok_premium = 10, stok_vip = 10, pilihan, durasi;
    int harga_reguler = 300000, harga_premium = 450000, harga_vip = 600000, harga_kamar;
    string nama, jenis_kamar, no_hp, checkout1, checkin, durasi_str;
    string history[100][6];
    int dimension1 = 0, dimension2, nilai = 0, jumlah_waktu, max, kabisat;

    do {
        system("cls");
        cout << "------------------ MENU PEMESANAN HOTEL -------------------" << endl;
        cout << endl;
        cout << "1. INFO KAMAR\n2. PEMESANAN\n3. HISTORY PEMESANAN";
        cout << "\nMasukkan pilihan : ";
        cin >> pilihan;
        if (pilihan == 1) {
            system("cls");
            cout << "---------------------------------- INFO KAMAR -------------------------------------" << endl;
            cout << endl;
            cout << "+===================+======================+=====================+================+" << endl;
            cout << "|    JENIS KAMAR    |   FASILITAS KAMAR    |  HARGA KAMAR/24 JAM |  STOK TERSEDIA |" << endl;
            cout << "+===================+======================+=====================+================+" << endl;
            cout << "|                   | 1. Ukuran 3 X 4      |                     |                |" << endl;
            cout << "|                   | 2. Single Bed        |                     |                |" << endl;
            cout << "|      Reguler      | 3. AC                |     Rp 300.000      |" << setw(10) << stok_reguler << setw(7) << "|" << endl;
            cout << "|                   | 4. Kamar Mandi Dalam |                     |                |" << endl;
            cout << "|                   | 5. WIFI              |                     |                |" << endl;
            cout << "+-------------------+----------------------+---------------------+----------------+" << endl;
            cout << "|                   | 1. Ukuran 4 X 4      |                     |                |" << endl;
            cout << "|                   | 2. Double Bed        |                     |                |" << endl;
            cout << "|      Premium      | 3. AC                |     Rp 450.000      |" << setw(10) << stok_premium << setw(7) << "|" << endl;
            cout << "|                   | 4. Kamar Mandi Dalam |                     |                |" << endl;
            cout << "|                   | 5. TV                |                     |                |" << endl;
            cout << "|                   | 6. WIFI              |                     |                |" << endl;
            cout << "+-------------------+----------------------+---------------------+----------------+" << endl;
            cout << "|                   | 1. Ukuran 4 X 5      |                     |                |" << endl;
            cout << "|                   | 2. Double Bed        |                     |                |" << endl;
            cout << "|                   | 3. AC                |                     |                |" << endl;
            cout << "|                   | 4. Kamar Mandi Dalam |                     |                |" << endl;
            cout << "|        VIP        | 5. View Menarik      |     Rp 600.000      |" << setw(10) << stok_vip << setw(7) << "|" << endl;
            cout << "|                   | 6. Free Breakfast    |                     |                |" << endl;
            cout << "|                   |    & Dinner          |                     |                |" << endl;
            cout << "|                   | 7. TV                |                     |                |" << endl;
            cout << "|                   | 8. WIFI              |                     |                |" << endl;
            cout << "+===================+======================+=====================+================+" << endl;
        }
        else
            if (pilihan == 2) {
                system("cls");
                cout << "-------------------- PEMESANAN KAMAR -----------------------" << endl;
                cout << endl;
                cout << "+============================+=============================+" << endl;
                cout << "|        JENIS KAMAR         |         HARGA KAMAR         |" << endl;
                cout << "+============================+=============================+" << endl;
                cout << "|          Reguler           |         Rp " << harga_reguler << setw(12) << right << '|' << endl;
                cout << "+----------------------------+-----------------------------+" << endl;
                cout << "|          Premium           |         Rp " << harga_premium << setw(12) << right << '|' << endl;
                cout << "+----------------------------+-----------------------------+" << endl;
                cout << "|            VIP             |         Rp " << harga_vip << setw(12) << right << '|' << endl;
                cout << "+============================+=============================+" << endl;
                cout << "\nNama \t\t\t\t : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Jenis Kamar \t\t\t : ";
                getline(cin, jenis_kamar);
                if (jenis_kamar == "reguler" or jenis_kamar == "Reguler" or jenis_kamar == "REGULER") {
                    cout << "Harga Kamar \t\t\t : " << harga_reguler << endl;
                    cout << "Stok Tersedia \t\t\t : " << stok_reguler << endl;
                    if (stok_reguler == 0) {
                        ulangi = 'Y';
                        cout << "STOK KAMAR HABIS!!!";
                        system("pause>0");
                        continue;
                    }
                    jenis_kamar = "Reguler";
                    harga_kamar = harga_reguler;
                }
                else if (jenis_kamar == "premium" or jenis_kamar == "Premium" or jenis_kamar == "PREMIUM") {
                    cout << "Harga Kamar \t\t\t : " << harga_premium << endl;
                    cout << "Stok Tersedia \t\t\t : " << stok_premium << endl;
                    if (stok_premium == 0) {
                        ulangi = 'Y';
                        cout << "STOK KAMAR HABIS!!!";
                        system("pause>0");
                        continue;
                    }
                    jenis_kamar = "Premium";
                    harga_kamar = harga_premium;
                }
                else if (jenis_kamar == "vip" or jenis_kamar == "Vip" or jenis_kamar == "VIP") {
                    cout << "Harga Kamar \t\t\t : " << harga_vip << endl;
                    cout << "Stok Tersedia \t\t\t : " << stok_vip << endl;
                    if (stok_vip == 0) {
                        ulangi = 'Y';
                        cout << "STOK KAMAR HABIS!!!";
                        system("pause>0");
                        continue;
                    }
                    jenis_kamar = "VIP";
                    harga_kamar = harga_vip;
                }
                else {
                	ulangi = 'Y';
                	cout<<endl;
                	cout<<"MASUKKAN KAMAR SESUAI YANG TERTERA!!!!!!";
                	system("pause>0");
                	continue;
				}
                cout << "Tanggal Check In (DD/MM/YYYY)    : ";
                getline(cin, checkin);
                cout << "Lama Inap (hari)  \t\t : ";
                cin >> durasi;
                checkout1 = checkout(checkin.substr(0,2), checkin.substr(3,2), checkin.substr(6,4), durasi);
                durasi_str = to_str(durasi);
                durasi_str += " Hari";
                cout << "Nomor HP \t\t\t : ";
                cin.ignore();
                getline(cin, no_hp);
                cout << "Total Pembayaran \t\t : " << harga_kamar * durasi << endl;
                cout << endl;
                cout << "Yakin Ingin Memesan (Y/T) ? ";
                cin >> pesan;
                pesan = toupper(pesan);
                if (pesan == 'Y') {
                    if (jenis_kamar == "reguler" or jenis_kamar == "Reguler" or jenis_kamar == "REGULER") {
                        stok_reguler--;
                    }
                    else if (jenis_kamar == "premium" or jenis_kamar == "Premium" or jenis_kamar == "PREMIUM") {
                        stok_premium--;
                    }
                    else if (jenis_kamar == "vip" or jenis_kamar == "Vip" or jenis_kamar == "VIP") {
                        stok_vip--;
                    }

                    for (dimension2 = 0; dimension2 < 6; dimension2++) {
                        switch (dimension2)
                        {
                        case(0):
                            history[dimension1][dimension2] = nama;
                            break;
                        case(1):
                            history[dimension1][dimension2] = jenis_kamar;
                            break;
                        case(2):
                            history[dimension1][dimension2] = checkin;
                            break;
                        case(3):
                            history[dimension1][dimension2] = checkout1;
                            break;
                        case(4):
                            history[dimension1][dimension2] = no_hp;
                            break;
                        case(5):
                            history[dimension1][dimension2] = durasi_str;
                            break;
                        default:
                            break;
                        }
                    }
                    dimension1 += 1;
                    cout << endl;
                    cout << "PEMESANAN SUKSES!!!" << endl;
                    cout << endl;
                    cout << "Cetak Bukti Pemesanan...";
                    system("pause>0");
                    system("cls");
                    Sleep(1000);
                    cout << "+===========================================================================+" << endl;
                    Sleep(1000);
                    cout << "|                            BUKTI PEMESANAN                                |" << endl;
                    Sleep(1000);
                    cout << "+===========================================================================+" << endl;
                    cout << resetiosflags(ios::right);
                    Sleep(1000);
                    cout << "|    Nama              : " << setw(51) << setiosflags(ios::left) << nama << "|" << endl;
                    Sleep(1000);
                    cout << "|    Jenis Kamar       : " << setw(51) << setiosflags(ios::left) << jenis_kamar << "|" << endl;
                    Sleep(1000);
                    cout << "|    Tanggal Check In  : " << setw(51) << setiosflags(ios::left) << checkin << "|" << endl;
                    Sleep(1000);
                    cout << "|    Tanggal Check Out : " << setw(51) << setiosflags(ios::left) << checkout1 << "|" << endl;
                    Sleep(1000);
                    cout << "|    Lama Menginap     : " << setw(51) << setiosflags(ios::left) << durasi_str << "|" << endl;
                    Sleep(1000);
                    cout << "+===========================================================================+" << endl;
                    Sleep(1000);
                    cout << resetiosflags(ios::left);
                }
                else if (pesan == 'T') {
                	cout<<endl;
                    cout << "PESANAN DIBATALKAN!!!" << endl;
                }
            }
            else
                if (pilihan == 3) {
                    system("cls");
                    cout << "---------------------------------------------------- HISTORY PEMESANAN -------------------------------------------------------" << endl;
                    cout << endl;
                    if (dimension1 == 0) {
                        cout << "anda belum memesan apapun!!!";
                        cout<<endl;
                    }
                    else {
                        cout << "+=================================+===============+=======================+=======================+===============+==========+" << endl;
                        cout << '|' << string(margin_left(33, "nama"), ' ') << "NAMA" << string(margin_right(33, "nama"), ' ') << '|' << string(margin_left(15, "tipe kamar"), ' ') << "TIPE KAMAR" << string(margin_right(15, "tipe kamar"), ' ') << "|" << string(margin_left(23, "Tanggal Check In"), ' ') << "Tanggal Check In"
                            << string(margin_right(23, "tanggal check in"), ' ') << '|' << string(margin_left(23, "Tanggal Check Out"), ' ') << "Tanggal Check Out" << string(margin_right(23, "tanggal check out"), ' ') << '|' << string(margin_left(15, "Nomor HP"), ' ') << "NOMOR HP"
                            << string(margin_right(15, "NOMOR HP"), ' ') << '|' << string(margin_left(10, "DURASI"), ' ') << "DURASI" << string(margin_right(10, "DURASI"), ' ') << '|' << endl;
                        cout << "+=================================+===============+=======================+=======================+===============+==========+" << endl;
                        for (int x = 0; x < dimension1 * 2; x++) {
                            int y = 0;
                            if (x % 2 == 1) {
                                if (x == (dimension1 * 2) - 1) {
                                    cout << "+=================================+===============+=======================+=======================+===============+==========+" << endl;
                                }
                                else {
                                    cout << "+---------------------------------+---------------+-----------------------+-----------------------+---------------+----------+" << endl;
                                }
                            }
                            else {
                                cout << '|' << string(margin_left(33, history[x / 2][y]), ' ') << history[x / 2][y] << string(margin_right(33, history[x / 2][y]), ' ') << '|'; y++;
                                cout << string(margin_left(15, history[x / 2][y]), ' ') << history[x / 2][y] << string(margin_right(15, history[x / 2][y]), ' ') << '|'; y++;
                                cout << string(margin_left(23, history[x / 2][y]), ' ') << history[x / 2][y] << string(margin_right(23, history[x / 2][y]), ' ') << '|'; y++;
                                cout << string(margin_left(23, history[x / 2][y]), ' ') << history[x / 2][y] << string(margin_right(23, history[x / 2][y]), ' ') << '|'; y++;
                                cout << string(margin_left(15, history[x / 2][y]), ' ') << history[x / 2][y] << string(margin_right(15, history[x / 2][y]), ' ') << '|'; y++;
                                cout << string(margin_left(10, history[x / 2][y]), ' ') << history[x / 2][y] << string(margin_right(10, history[x / 2][y]), ' ') << '|' << endl;
                            }
                        }
                    }
                }
                else {
                    cout << endl;
                    cout << "MASUKKAN SESUAI KODE MENU!!!!!!" << endl;
                    cout << endl;
                }
        cout << "\nBalik Lagi ke Menu Awal(Y/T) ? ";
        cin >> ulangi; ulangi = toupper(ulangi);
    } while (ulangi == 'Y');
    cout << endl;
    cout << "PROGRAM SELESAI!!! ";
}
