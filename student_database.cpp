 // serdar.kokcu@hotmail.com
 
 
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
 
using namespace std;
int main() {
    FILE *fp, *ft;
    char another, choice;
 
struct student {
        char first_name[50], last_name[50];
        char course[100];
        int number;
    };
 
    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;
 
    fp=fopen("kullanıcı.txt","rb+");
 
    if (fp == NULL) {
        fp = fopen("kullanıcı.txt","wb+");
 
        if (fp==NULL)
        {
             puts("Dosya acılamadı");
             return 0;
        }
    }
 
 
 recsize = sizeof(e);
 
 while(1) {
     system("cls");
 
     cout << "\t\t====== OGRENCI DATA BASE ======";
     cout <<"\n\n                                          ";
     cout << "\n\n";
     cout << "\n \t\t\t 1. Kayit Ekle";
     cout << "\n \t\t\t 2. Kayitlari Goster";
     cout << "\n \t\t\t 3. Kayit Duzenle";
     cout << "\n \t\t\t 4. Kayitlari Sil";
     cout << "\n \t\t\t 5. Programi Kapat";
     cout << "\n\n";
     cout << "\t\t\t Seciminizi Giriniz => ";
     fflush(stdin);
     choice = getche();
     switch(choice)
     {
      case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                  system("cls");
                cout << "Ogrencinin ADI : ";
                cin >> e.first_name;
                cout << "Ogrencinin SOYADI : ";
                cin >> e.last_name;
                cout << "Ogrencinin Bölümü  : ";
                cin >> e.course;
                cout << "Ogrencının Numarası   : ";
                cin >> e.number;
                fwrite(&e,recsize,1,fp);
                cout << "\n Devam Etmek Istiyorsan (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
   case '2':
            system("cls");
           rewind(fp);
           cout << "=== KAYITLI OLAN OGRENCI BILGILERI ===";
           cout << "\n";
           while (fread(&e,recsize,1,fp) == 1){
           cout << "\n";
           cout <<"\n" << e.first_name << setw(10)  << e.last_name;
           cout << "\n";
           cout <<"\n" <<e.course <<  setw(8)  << e.number;
           }
           cout << "\n\n";
           system("pause");
           break;
 
   case '3' :
            system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n OGRENCININ SOY ADINI GIRINIZ \t : ";
              cin >> xlast_name;
 
            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)
            {
                if (strcmp(e.last_name,xlast_name) == 0)
                {
                cout << "OGRENCININ ADI : ";
                cin >> e.first_name;
                cout << "OGRENCININ SOYADI : ";
                cin >> e.last_name;
                cout << "BOLUMU GIRINIZ   : ";
                cin >> e.course;
                cout << "OGRENCININ NUMARASI   : ";
                cin >> e.number;
                fseek(fp, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp);
                break;
                }
                else
                cout<<"KAYIT BULUNAMADI";
            }
            cout << "\n BASKA KAYIT DEGISTIRMEK ICIN (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
 
 
     case '4':
       system("cls");
           another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n OGRENCININ SOY ADINI GİRİNİZ : ";
              cin >> xlast_name;
 
              ft = fopen("temp.dat", "wb");
 
              rewind(fp);
              while (fread (&e, recsize,1,fp) == 1)
 
                 if (strcmp(e.last_name,xlast_name) != 0)
                {
                    fwrite(&e,recsize,1,ft);
                }
                fclose(fp);
                fclose(ft);
                remove("kullanıcı.txt");
                rename("temp.dat","kullanıcı.txt");
 
                fp=fopen("kullanıcı.txt","rb+");
 
                cout << "\n BASKA KAYIT SILMEK ICIN (Y/N) ";
                fflush(stdin);
                another = getchar();
              }
 
              break;
 
              case '5':
              fclose(fp);
              exit(0);
          }
     }
 
 
system("pause");
return 0;
}

