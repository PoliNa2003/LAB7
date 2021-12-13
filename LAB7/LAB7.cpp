#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;


struct date {
    int day;
    char* month;
    int year;
};

struct deposid {
    int id;
    char* fio;
    double balance;
    date date1;
};

int main() {
    deposid bank1[100];
    int n_bank1 = 0;
    int max_len_fio = 0;

    setlocale(LC_ALL, "Russian");

    ifstream fin;
    fin.open("1.txt");
    fin >> n_bank1;
    for (int i = 0; i < n_bank1; ++i) {
        char buff2[20];
        fin.getline(buff2, 20, '|');
        bank1[i].fio = new char[strlen(buff2) + 1];
        strcpy(bank1[i].fio, buff2);
        if (max_len_fio < strlen(buff2)) max_len_fio = strlen(buff2);
        fin >> bank1[i].id;
        fin >> bank1[i].balance;
        fin >> bank1[i].date1.day;
        char buff1[5];
        fin.getline(buff1, 5, '|');
        bank1[i].date1.month = new char[strlen(buff1) + 1];
        strcpy(bank1[i].date1.month, buff1);
        fin >> bank1[i].date1.year;
    }
    fin.close();

    int q = 1;
    while (q != 6) {
    Begin:
        cout << "Enter:\n1 - new account\n2 - get information about bank\n3-bank accouts with an amount more than...\n4-get information about the bank account\n5 - account started later than...\n6 - finish the program\n";
        cin >> q;
        if (q < 0 || q > 6 || cin.fail()) {
            while (cin.get() != '\n') cin.clear();
            cout << "Error!\n";
            goto Begin;
        }
        if (q == 1) {
            while (cin.get() != '\n') cin.clear();
            char buff[100];

            cout << "Enter fio(max 20 chars)\n";

            gets_s(buff);
            bank1[n_bank1].fio = new char[strlen(buff) + 1];
            strcpy(bank1[n_bank1].fio, buff);
            if (max_len_fio < strlen(buff)) max_len_fio = strlen(buff);

            cout << "The id: " << n_bank1 << '\n';
            bank1[n_bank1].id = n_bank1;
        F:
            cout << "Enter the balance\n";
            cin >> bank1[n_bank1].balance;
            if (cin.fail()) {
                while (cin.get() != '\n') cin.clear();
                cout << "Error!\n";
                goto F;
            }
            cout << "Enter the date:\n";
        H:
            cout << "Day:\n";
            cin >> bank1[n_bank1].date1.day;
            if (cin.fail() || bank1[n_bank1].date1.day < 0 || bank1[n_bank1].date1.day > 31) {
                while (cin.get() != '\n') cin.clear();
                cout << "Error!\n";
                goto H;
            }
            bank1[n_bank1].date1.month = new char[4];
        T:
            cout << "Month.(Format: jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec)\n";
            cin >> bank1[n_bank1].date1.month;
            if (strcmp("jan", bank1[n_bank1].date1.month) != 0 && strcmp("feb", bank1[n_bank1].date1.month) != 0 && strcmp("mar", bank1[n_bank1].date1.month) != 0 && strcmp("apr", bank1[n_bank1].date1.month) != 0 && strcmp("may", bank1[n_bank1].date1.month) != 0 && strcmp("jun", bank1[n_bank1].date1.month) != 0 && strcmp("jul", bank1[n_bank1].date1.month) != 0 && strcmp("aug", bank1[n_bank1].date1.month) != 0 && strcmp("sep", bank1[n_bank1].date1.month) != 0 && strcmp("oct", bank1[n_bank1].date1.month) != 0 && strcmp("nov", bank1[n_bank1].date1.month) != 0 && strcmp("dec", bank1[n_bank1].date1.month) != 0) goto T;
            if (strcmp("jan", bank1[n_bank1].date1.month) != 0 && strcmp("mar", bank1[n_bank1].date1.month) != 0 && strcmp("may", bank1[n_bank1].date1.month) != 0 && strcmp("jul", bank1[n_bank1].date1.month) != 0 && strcmp("aug", bank1[n_bank1].date1.month) != 0 && strcmp("oct", bank1[n_bank1].date1.month) != 0 && strcmp("dec", bank1[n_bank1].date1.month) != 0 and bank1[n_bank1].date1.day == 31) goto H;
            if (strcmp("feb", bank1[n_bank1].date1.month) == 0 && bank1[n_bank1].date1.day > 28) goto H;
        K:
            cout << "Year:\n";
            cin >> bank1[n_bank1].date1.year;
            if (cin.fail() || bank1[n_bank1].date1.year < 0) {
                while (cin.get() != '\n') cin.clear();
                cout << "Error!\n";
                goto K;
            }
            n_bank1++;
        }

        if (q == 2) {
            if (max_len_fio < 12) max_len_fio = 12;
            cout << "Fio       ";
            for (int i = 0; i < max_len_fio - 12; ++i) cout << ' ';
            cout << "ID\tBalance\t\day\tmonth\t\year\n";
            cout << "_______________________________________________________\n";
            for (int i = 0; i < n_bank1; ++i) {
                cout << bank1[i].fio;
                for (int j = 0; j <= max_len_fio - strlen(bank1[i].fio); ++j) cout << ' ';
                cout << bank1[i].id << '\t' << bank1[i].balance << '\t' << bank1[i].date1.day << '\t' << bank1[i].date1.month << '\t' << bank1[i].date1.year << '\n';
                cout << "_______________________________________________________\n";
            }
        }

        if (q == 3) {
            cout << "Enter the sum:\n";
            double sum_1;
        Q:
            cin >> sum_1;
            if (cin.fail()) {
                while (cin.get() != '\n') cin.clear();
                cout << "Error!\n";
                goto Q;
            }
            if (max_len_fio < 12) max_len_fio = 12;
            cout << "Fio       ";
            for (int i = 0; i < max_len_fio - 12; ++i) cout << ' ';
            cout << "ID\tBalance\t\day\tmonth\t\year\n";
            cout << "_______________________________________________________\n";
            for (int i = 0; i < n_bank1; ++i) {
                if (bank1[i].balance <= sum_1) continue;
                cout << bank1[i].fio;
                for (int j = 0; j <= max_len_fio - strlen(bank1[i].fio); ++j) cout << ' ';
                cout << bank1[i].id << '\t' << bank1[i].balance << '\t' << bank1[i].date1.day << '\t' << bank1[i].date1.month << '\t' << bank1[i].date1.year << '\n';
                cout << "_______________________________________________________\n";
            }
        }
        if (q == 4) {
            while (cin.get() != '\n') cin.clear();

            char buff[30];

            cout << "Enter first name(max 20 chars)\n";

            gets_s(buff);
            char* fio1;
            fio1 = new char[strlen(buff) + 1];
            strcpy(fio1, buff);

            if (max_len_fio < 12) max_len_fio = 12;
            cout << "Fio       ";
            for (int i = 0; i < max_len_fio - 10; ++i) cout << ' ';
            cout << "ID\tBalance\t\day\tmonth\t\year\n";
            cout << "_______________________________________________________\n";

            for (int i = 0; i < n_bank1; ++i) {
                if (strcmp(fio1, bank1[i].fio) == 0) {
                    cout << bank1[i].fio;
                    for (int j = 0; j <= max_len_fio - strlen(bank1[i].fio); ++j) cout << ' ';
                    cout << bank1[i].id << '\t' << bank1[i].balance << '\t' << bank1[i].date1.day << '\t' << bank1[i].date1.month << '\t' << bank1[i].date1.year << '\n';
                    cout << "_______________________________________________________\n";
                }
            }
            delete[] fio1;
        }
        if (q == 5) {
            int day1, year1;
            char* month1;
            month1 = new char[4];
            cout << "Enter the date:\n";
        H1:
            cout << "Day:\n";
            cin >> day1;
            if (cin.fail() || day1 < 0 || day1 > 31) {
                while (cin.get() != '\n') cin.clear();
                cout << "Error!\n";
                goto H1;
            }
        T1:
            cout << "Month.(Format: jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec)\n";
            cin >> month1;
            if (strcmp("jan", month1) != 0 && strcmp("feb", month1) != 0 && strcmp("mar", month1) != 0 && strcmp("apr", month1) != 0 && strcmp("may", month1) != 0 && strcmp("jun", month1) != 0 && strcmp("jul", month1) != 0 && strcmp("aug", month1) != 0 && strcmp("sep", month1) != 0 && strcmp("oct", month1) != 0 && strcmp("nov", month1) != 0 && strcmp("dec", month1) != 0) goto T1;
            if (strcmp("jan", month1) != 0 && strcmp("mar", month1) != 0 && strcmp("may", month1) != 0 && strcmp("jul", month1) != 0 && strcmp("aug", month1) != 0 && strcmp("oct", month1) != 0 && strcmp("dec", month1) != 0 and day1 == 31) goto H1;
            if (strcmp("feb", month1) == 0 && day1 > 28) goto H1;
        K1:
            cout << "Year:\n";
            cin >> year1;
            if (cin.fail() || year1 < 0) {
                while (cin.get() != '\n') cin.clear();
                cout << "Error!\n";
                goto K1;
            }

            if (max_len_fio < 12) max_len_fio = 12;
            cout << "Fio       ";
            for (int i = 0; i < max_len_fio - 12; ++i) cout << ' ';
            cout << "ID\tBalance\t\day\tmonth\t\year\n";
            cout << "_______________________________________________________\n";

            for (int i = 0; i < n_bank1; ++i) {
            print:
                cout << bank1[i].fio;
                for (int j = 0; j <= max_len_fio - strlen(bank1[i].fio); ++j) cout << ' ';
                cout << bank1[i].id << '\t' << bank1[i].balance << '\t' << bank1[i].date1.day << '\t' << bank1[i].date1.month << '\t' << bank1[i].date1.year << '\n';
                cout << "_______________________________________________________\n";
                i++;


                if (bank1[i].date1.year < year1) continue;
                else if (bank1[i].date1.year > year1) goto print;
                else if (strcmp(bank1[i].date1.month, month1) == 0 && day1 < bank1[i].date1.day) goto print;
                else if (strcmp(bank1[i].date1.month, month1) == 0 && day1 >= bank1[i].date1.day) continue;
                else if (strcmp("jan", month1) == 0) {
                    if (strcmp("feb", bank1[i].date1.month) != 0 || strcmp("mar", bank1[i].date1.month) != 0 || strcmp("apr", bank1[i].date1.month) != 0 || strcmp("may", bank1[i].date1.month) != 0 || strcmp("jun", bank1[i].date1.month) != 0 || strcmp("jul", bank1[i].date1.month) != 0 || strcmp("aug", bank1[i].date1.month) != 0 || strcmp("sep", bank1[i].date1.month) != 0 || strcmp("oct", bank1[i].date1.month) != 0 || strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("feb", month1) == 0) {
                    if (strcmp("mar", bank1[i].date1.month) != 0 || strcmp("apr", bank1[i].date1.month) != 0 || strcmp("may", bank1[i].date1.month) != 0 || strcmp("jun", bank1[i].date1.month) != 0 || strcmp("jul", bank1[i].date1.month) != 0 || strcmp("aug", bank1[i].date1.month) != 0 || strcmp("sep", bank1[i].date1.month) != 0 || strcmp("oct", bank1[i].date1.month) != 0 || strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("mar", month1) == 0) {
                    if (strcmp("apr", bank1[i].date1.month) != 0 || strcmp("may", bank1[i].date1.month) != 0 || strcmp("jun", bank1[i].date1.month) != 0 || strcmp("jul", bank1[i].date1.month) != 0 || strcmp("aug", bank1[i].date1.month) != 0 || strcmp("sep", bank1[i].date1.month) != 0 || strcmp("oct", bank1[i].date1.month) != 0 || strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("apr", month1) == 0) {
                    if (strcmp("may", bank1[i].date1.month) != 0 || strcmp("jun", bank1[i].date1.month) != 0 || strcmp("jul", bank1[i].date1.month) != 0 || strcmp("aug", bank1[i].date1.month) != 0 || strcmp("sep", bank1[i].date1.month) != 0 || strcmp("oct", bank1[i].date1.month) != 0 || strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("may", month1) == 0) {
                    if (strcmp("jun", bank1[i].date1.month) != 0 || strcmp("jul", bank1[i].date1.month) != 0 || strcmp("aug", bank1[i].date1.month) != 0 || strcmp("sep", bank1[i].date1.month) != 0 || strcmp("oct", bank1[i].date1.month) != 0 || strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("jun", month1) == 0) {
                    if (strcmp("jul", bank1[i].date1.month) != 0 || strcmp("aug", bank1[i].date1.month) != 0 || strcmp("sep", bank1[i].date1.month) != 0 || strcmp("oct", bank1[i].date1.month) != 0 || strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("jul", month1) == 0) {
                    if (strcmp("aug", bank1[i].date1.month) != 0 || strcmp("sep", bank1[i].date1.month) != 0 || strcmp("oct", bank1[i].date1.month) != 0 || strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("aug", month1) == 0) {
                    if (strcmp("sep", bank1[i].date1.month) != 0 || strcmp("oct", bank1[i].date1.month) != 0 || strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("sep", month1) == 0) {
                    if (strcmp("oct", bank1[i].date1.month) != 0 || strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("oct", month1) == 0) {
                    if (strcmp("nov", bank1[i].date1.month) != 0 || strcmp("dec", month1) != 0) goto print;
                }
                else if (strcmp("nov", month1) == 0) {
                    if (strcmp("dec", month1) != 0) goto print;
                }
                else continue;
            }
            delete[] month1;
        }
    }

    ofstream fout;
    fout.open("1.txt");
    fout << n_bank1;
    for (int i = 0; i < n_bank1; ++i) {
        fout << bank1[i].fio << '|';
        fout << bank1[i].id << '\n';
        fout << bank1[i].balance << '\n';
        fout << bank1[i].date1.day;
        fout << bank1[i].date1.month << '|';
        fout << bank1[i].date1.year;
    }
    fout.close();


    for (int i = 0; i < n_bank1; ++i) {
        delete[] bank1[i].fio;
        delete[] bank1[i].date1.month;
    }

    cout << "Googbye\n";
    return 0;
}

