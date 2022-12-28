#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h> //contains _dos_getdate
#include <time.h>

#define RETURNTIME 15

char catagories[][15] = {"Programming", "Database", "Data Analytics", "Data Mining", "Machine Learning", "Artificial intelligence"};
void returnfunc(void);
void mainMenu(void);
void tambahBuku(void);
void hapusBuku(void);
void ubahBuku(void);
void cariBuku(void);
void pinjamBuku(void);
void lihatBuku(void);
void closeApplication(void);
int getdata();
int checkid(int);
int t(void);
// void show_mouse(void);
void Password();
void issuerecord();
void loaderanim();

// list of global files that can be acceed form anywhere in program
FILE *fp, *ft, *fs;

COORD coord = {0, 0};
// list of global variable
int s;
char findbook;
char password[10] = {"passme"};

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
    int mm, dd, yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};
struct books a;
int main()
{
    Password();
    getch();
    return 0;
}
void mainMenu()
{
    // loaderanim();
    system("cls");
    //    textbackground(13);
    int i;
    gotoxy(20, 3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2");
    //    show_mouse();
    gotoxy(20, 5);
    printf("\xB2\xB2\xB2\xB2\ 1=> Tambah Buku   ");
    gotoxy(20, 7);
    printf("\xB2\xB2\xB2\xB2\ 2=> Hapus Buku");
    gotoxy(20, 9);
    printf("\xB2\xB2\xB2\xB2\ 3=> Cari Buku");
    gotoxy(20, 11);
    printf("\xB2\xB2\xB2\xB2\ 4=> Pinjam Buku");
    gotoxy(20, 13);
    printf("\xB2\xB2\xB2\xB2\ 5=> Lihat Daftar Buku");
    gotoxy(20, 15);
    printf("\xB2\xB2\xB2\xB2\ 6=> Ubah Catatan Buku");
    gotoxy(20, 17);
    printf("\xB2\xB2\xB2\xB2\ 7=> Tutup Aplikasi");
    gotoxy(20, 19);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 20);

    gotoxy(20, 21);
    printf("Masukkan pilihan anda:");
    switch (getch())
    {
    case '1':
        tambahBuku();
        break;
    case '2':
        hapusBuku();
        break;
    case '3':
        cariBuku();
        break;
    case '4':
        pinjamBuku();
        break;
    case '5':
        lihatBuku();
        break;
    case '6':
        ubahBuku();
        break;
    case '7':
    {
        system("cls");
        gotoxy(16, 3);
        printf("\tLibrary Management System");
        gotoxy(16, 5);
        printf("\tProject Using C");
        gotoxy(16, 7);
        printf("\tpresent to you by");
        gotoxy(16, 9);
        printf("\t #Abb");
        gotoxy(16, 11);
        printf("::::::::::::::::::::::::::::");
        gotoxy(16, 13);
        printf("::::::::::::::::::::::::::::");
        gotoxy(16, 15);
        printf("Exiting in 3 second...........>");
        // flushall();
        Sleep(3000);
        exit(0);
    }
    default:
    {
        gotoxy(10, 23);
        printf("\aEntri Salah!! Harap masukkan kembali opsi yang benar");
        if (getch())
            mainMenu();
    }
    }
}
void tambahBuku(void) // add books
{
    system("cls");
    int i;
    gotoxy(20, 3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 5);
    printf("\xB2\xB2\xB2\xB2\ 1=> Programming");
    gotoxy(20, 7);
    printf("\xB2\xB2\xB2\xB2\ 2=> Database");
    gotoxy(20, 9);
    printf("\xB2\xB2\xB2\xB2\ 3=> Data Analytics");
    gotoxy(20, 11);
    printf("\xB2\xB2\xB2\xB2\ 4=> Data Mining");
    gotoxy(20, 13);
    printf("\xB2\xB2\xB2\xB2\ 5=> Machine Learning");
    gotoxy(20, 15);
    printf("\xB2\xB2\xB2\xB2\ 6=> Artificial intelligence");
    gotoxy(20, 17);
    printf("\xB2\xB2\xB2\xB2\ 7=> Back to main menu");
    gotoxy(20, 19);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 21);
    printf("Masukkan pilihan anda:");
    scanf("%d", &s);
    if (s == 7)

        mainMenu();
    system("cls");
    fp = fopen("lib.dat", "ab+");
    if (getdata() == 1)
    {
        a.cat = catagories[s - 1];
        fseek(fp, 0, SEEK_END);
        fwrite(&a, sizeof(a), 1, fp);
        fclose(fp);
        gotoxy(21, 14);
        printf("Catatan Berhasil Disimpan");
        gotoxy(21, 15);
        printf("Apakah Anda ingin menyimpan lagi?(Y / N):");
        if (getch() == 'n')
            mainMenu();
        else
            system("cls");
        tambahBuku();
    }
}
void hapusBuku() // Delete items
{
    system("cls");
    int d;
    char another = 'y';
    while (another == 'y') // infinite loop
    {
        system("cls");
        gotoxy(10, 5);
        printf("Masukkan ID Buku yang akan dihapus:");
        scanf("%d", &d);
        fp = fopen("lib.dat", "rb+");
        rewind(fp);
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (a.id == d)
            {

                gotoxy(10, 7);
                printf("Catatan Buku Tersedia");
                gotoxy(10, 8);
                printf("Nama buku adalah %s", a.name);
                gotoxy(10, 9);
                printf("Nomor rak adalah %d", a.rackno);
                findbook = 't';
            }
        }
        if (findbook != 't')
        {
            gotoxy(10, 10);
            printf("No record is found modify the search");
            if (getch())
                mainMenu();
        }
        if (findbook == 't')
        {
            gotoxy(10, 9);
            printf("Apakah Anda ingin menghapusnya?(Y/N):");
            if (getch() == 'y')
            {
                ft = fopen("test.dat", "wb+"); // temporary file for delete
                rewind(fp);
                while (fread(&a, sizeof(a), 1, fp) == 1)
                {
                    if (a.id != d)
                    {
                        fseek(ft, 0, SEEK_CUR);
                        fwrite(&a, sizeof(a), 1, ft); // write all in tempory file except that
                    }                                 // we want to delete
                }
                fclose(ft);
                fclose(fp);
                remove("lib.dat");
                rename("test.dat", "lib.dat"); // copy all item from temporary file to fp except that
                fp = fopen("lib.dat", "rb+");  // we want to delete
                if (findbook == 't')
                {
                    gotoxy(10, 10);
                    printf("Catatan Berhasil Dihapus");
                    gotoxy(10, 11);
                    printf("Hapus catatan lain?(Y/N)");
                }
            }
            else
                mainMenu();
            fflush(stdin);
            another = getch();
        }
    }
    gotoxy(10, 15);
    mainMenu();
}
void cariBuku()
{
    system("cls");
    int d;
    printf(":::::::::::::::::::::::::::::Cari Buku:::::::::::::::::::::::::::::");
    gotoxy(20, 3);
    printf("\xB2\xB2\xB2\xB2\ 1=> Cari Berdasarkan ID");
    gotoxy(20, 5);
    printf("\xB2\xB2\xB2\xB2\ 2=> Cari Berdasarkan Nama");
    gotoxy(20, 9);
    printf("Masukkan Pilihan Anda");
    fp = fopen("lib.dat", "rb+"); // open file for reading propose
    rewind(fp);                   // move pointer at the begining of file
    switch (getch())
    {
    case '1':
    {
        system("cls");
        gotoxy(25, 4);
        printf("::::Cari Buku Berdasarkan ID::::");
        gotoxy(20, 6);
        printf("Masukkan id buku:");
        scanf("%d", &d);
        gotoxy(20, 8);
        printf("Mencari.....");
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (a.id == d)
            {
                Sleep(2);
                gotoxy(20, 7);
                printf("Buku Tersedia");
                gotoxy(20, 8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20, 9);
                printf("\xB2 ID:%d", a.id);
                gotoxy(47, 9);
                printf("\xB2");
                gotoxy(20, 10);
                printf("\xB2 Nama:%s", a.name);
                gotoxy(47, 10);
                printf("\xB2");
                gotoxy(20, 11);
                printf("\xB2 Penulis:%s ", a.Author);
                gotoxy(47, 11);
                printf("\xB2");
                gotoxy(20, 12);
                printf("\xB2 Jumlah:%d ", a.quantity);
                gotoxy(47, 12);
                printf("\xB2");
                gotoxy(47, 11);
                printf("\xB2");
                gotoxy(20, 13);
                printf("\xB2 Harga:Rp.%.2f", a.Price);
                gotoxy(47, 13);
                printf("\xB2");
                gotoxy(20, 14);
                printf("\xB2 Nomor Rak:%d ", a.rackno);
                gotoxy(47, 14);
                printf("\xB2");
                gotoxy(20, 15);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                findbook = 't';
            }
        }
        if (findbook != 't') // checks whether conditiion enters inside loop or not
        {
            gotoxy(20, 8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20, 9);
            printf("\xB2");
            gotoxy(38, 9);
            printf("\xB2");
            gotoxy(20, 10);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(22, 9);
            printf("\aTidak Ada Catatan Ditemukan");
        }
        gotoxy(20, 17);
        printf("Coba pencarian lain?(Y/N)");
        if (getch() == 'y')
            cariBuku();
        else
            mainMenu();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");
        gotoxy(25, 4);
        printf("::::Cari Buku Berdasarkan Nama::::");
        gotoxy(20, 5);
        printf("Masukkan Nama Buku:");
        scanf("%s", s);
        int d = 0;
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (strcmp(a.name, (s)) == 0) // checks whether a.name is equal to s or not
            {
                gotoxy(20, 7);
                printf("Buku Tersedia");
                gotoxy(20, 8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20, 9);
                printf("\xB2 ID:%d", a.id);
                gotoxy(47, 9);
                printf("\xB2");
                gotoxy(20, 10);
                printf("\xB2 Nama:%s", a.name);
                gotoxy(47, 10);
                printf("\xB2");
                gotoxy(20, 11);
                printf("\xB2 Penulis:%s", a.Author);
                gotoxy(47, 11);
                printf("\xB2");
                gotoxy(20, 12);
                printf("\xB2 Jumlah:%d", a.quantity);
                gotoxy(47, 12);
                printf("\xB2");
                gotoxy(20, 13);
                printf("\xB2 Harga:Rp.%.2f", a.Price);
                gotoxy(47, 13);
                printf("\xB2");
                gotoxy(20, 14);
                printf("\xB2 Nomor Rak:%d ", a.rackno);
                gotoxy(47, 14);
                printf("\xB2");
                gotoxy(20, 15);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                d++;
            }
        }
        if (d == 0)
        {
            gotoxy(20, 8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20, 9);
            printf("\xB2");
            gotoxy(38, 9);
            printf("\xB2");
            gotoxy(20, 10);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(22, 9);
            printf("\aTidak Ada Catatan Ditemukan");
        }
        gotoxy(20, 17);
        printf("Coba pencarian lain?(Y/N)");
        if (getch() == 'y')
            cariBuku();
        else
            mainMenu();
        break;
    }
    default:
        getch();
        cariBuku();
    }
    fclose(fp);
}
void pinjamBuku(void) // function that issue books from library
{
    int t;

    system("cls");
    printf(":::::::::::::::::::::::::::::::BAGIAN PEMINJAMAN::::::::::::::::::::::::::::::::");
    gotoxy(20, 5);
    printf("\xB2\xB2\xB2\xB2\ 1=> Pinjam buku");
    gotoxy(20, 7);
    printf("\xB2\xB2\xB2\xB2\ 2=> Lihat Buku Yang Dipinjam");
    gotoxy(20, 9);
    printf("\xB2\xB2\xB2\xB2\ 3=> Cari Buku Yang Dipinjam");
    gotoxy(20, 11);
    printf("\xB2\xB2\xB2\xB2\ 4=> Hapus Buku Yang Dipinjam");
    gotoxy(20, 14);
    printf("Masukkan pilihan:");
    switch (getch())
    {
    case '1': // issue book
    {
        system("cls");
        int c = 0;
        char another = 'y';
        while (another == 'y')
        {
            system("cls");
            gotoxy(15, 4);
            printf(":::Bagian peminjaman buku:::");
            gotoxy(10, 6);
            printf("Masukkan ID Buku:");
            scanf("%d", &t);
            fp = fopen("lib.dat", "rb");
            fs = fopen("Issue.dat", "ab+");
            if (checkid(t) == 0) // issues those which are present in library
            {
                gotoxy(10, 8);
                printf("Catatan Buku Tersedia!");
                gotoxy(10, 9);
                printf("Ada %d buku yang belum dipinjam di perpustakaan ", a.quantity);
                gotoxy(10, 10);
                printf("Nama Buku Adalah %s", a.name);
                gotoxy(10, 11);
                printf("Masukkan nama siswa:");
                scanf("%s", a.stname);
                // struct dosdate_t d; //for current date
                //_dos_getdate(&d);
                // a.issued.dd=d.day;
                // a.issued.mm=d.month;
                // a.issued.yy=d.year;
                gotoxy(10, 12);
                printf("Tanggal pinjam=%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
                gotoxy(10, 13);
                printf("ID Buku %d dipinjam", a.id);
                a.duedate.dd = a.issued.dd + RETURNTIME; // for return date
                a.duedate.mm = a.issued.mm;
                a.duedate.yy = a.issued.yy;
                if (a.duedate.dd > 30)
                {
                    a.duedate.mm += a.duedate.dd / 30;
                    a.duedate.dd -= 30;
                }
                if (a.duedate.mm > 12)
                {
                    a.duedate.yy += a.duedate.mm / 12;
                    a.duedate.mm -= 12;
                }
                gotoxy(10, 14);
                printf("akan dikembalikan:%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
                fseek(fs, sizeof(a), SEEK_END);
                fwrite(&a, sizeof(a), 1, fs);
                fclose(fs);
                c = 1;
            }
            if (c == 0)
            {
                gotoxy(10, 11);
                printf("Tidak ada catatan yang ditemukan");
            }
            gotoxy(10, 15);
            printf("Pinjam lagi(Y/N):");
            fflush(stdin);
            another = getche();
            fclose(fp);
        }

        break;
    }
    case '2': // show issued book list
    {
        system("cls");
        int j = 4;
        printf("::::::::::::::::::::::::::::::Daftar Buku Yang Dipinjam:::::::::::::::::::::::::::::::\n");
        gotoxy(2, 2);
        printf("NAMA SISWA    KATEGORI    ID    NAMA BUKU    TANGGAL PINJAM    TANGGAL KEMBALI");
        fs = fopen("Issue.dat", "rb");
        while (fread(&a, sizeof(a), 1, fs) == 1)
        {

            gotoxy(2, j);
            printf("%s", a.stname);
            gotoxy(18, j);
            printf("%s", a.cat);
            gotoxy(30, j);
            printf("%d", a.id);
            gotoxy(36, j);
            printf("%s", a.name);
            gotoxy(51, j);
            printf("%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
            gotoxy(65, j);
            printf("%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
            // struct dosdate_t d;
            //_dos_getdate(&d);
            gotoxy(50, 25);
            //            printf("Current date=%d-%d-%d",d.day,d.month,d.year);
            j++;
        }
        fclose(fs);
        gotoxy(1, 25);
        returnfunc();
    }
    break;
    case '3': // search issued books by id
    {
        system("cls");
        gotoxy(10, 6);
        printf("Masukkan ID Buku:");
        int p, c = 0;
        char another = 'y';
        while (another == 'y')
        {

            scanf("%d", &p);
            fs = fopen("Issue.dat", "rb");
            while (fread(&a, sizeof(a), 1, fs) == 1)
            {
                if (a.id == p)
                {
                    issuerecord();
                    gotoxy(10, 12);
                    printf("Tekan tombol apa saja.......");
                    getch();
                    issuerecord();
                    c = 1;
                }
            }
            fflush(stdin);
            fclose(fs);
            if (c == 0)
            {
                gotoxy(10, 8);
                printf("Tidak Ada Catatan Ditemukan");
            }
            gotoxy(10, 13);
            printf("Coba Pencarian Lain?(Y/N)");
            another = getch();
        }
    }
    break;
    case '4': // remove issued books from list
    {
        system("cls");
        int b;
        FILE *fg; // declaration of temporary file for delete
        char another = 'y';
        while (another == 'y')
        {
            gotoxy(10, 5);
            printf("Masukkan id buku yang ingin dihapus:");
            scanf("%d", &b);
            fs = fopen("Issue.dat", "rb+");
            while (fread(&a, sizeof(a), 1, fs) == 1)
            {
                if (a.id == b)
                {
                    issuerecord();
                    findbook = 't';
                }
                if (findbook == 't')
                {
                    gotoxy(10, 12);
                    printf("Apakah Anda Ingin Menghapusnya?(Y/N)");
                    if (getch() == 'y')
                    {
                        fg = fopen("record.dat", "wb+");
                        rewind(fs);
                        while (fread(&a, sizeof(a), 1, fs) == 1)
                        {
                            if (a.id != b)
                            {
                                fseek(fs, 0, SEEK_CUR);
                                fwrite(&a, sizeof(a), 1, fg);
                            }
                        }
                        fclose(fs);
                        fclose(fg);
                        remove("Issue.dat");
                        rename("record.dat", "Issue.dat");
                        gotoxy(10, 14);
                        printf("The issued book is removed from list");
                    }
                }
                if (findbook != 't')
                {
                    gotoxy(10, 15);
                    printf("Tidak Ada Catatan Ditemukan");
                }
            }
            gotoxy(10, 16);
            printf("Hapus lagi?(Y/N)");
            another = getch();
        }
    }
    default:
        gotoxy(10, 18);
        printf("\aEntri Salah!!");
        getch();
        pinjamBuku();
        break;
    }
    gotoxy(1, 30);
    returnfunc();
}
void lihatBuku(void) // show the list of book persists in library
{
    int i = 0, j;
    system("cls");
    gotoxy(1, 1);
    printf("::::::::::::::::::::::::::::::::Daftar Buku:::::::::::::::::::::::::::::::::");
    gotoxy(2, 2);
    printf(" KATEGORI     ID    NAMA BUKU     PENULIS       JUMLAH     HARGA     NOMOR RAK ");
    j = 4;
    fp = fopen("lib.dat", "rb");
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        gotoxy(3, j);
        printf("%s", a.cat);
        gotoxy(16, j);
        printf("%d", a.id);
        gotoxy(22, j);
        printf("%s", a.name);
        gotoxy(36, j);
        printf("%s", a.Author);
        gotoxy(50, j);
        printf("%d", a.quantity);
        gotoxy(57, j);
        printf("%.2f", a.Price);
        gotoxy(69, j);
        printf("%d", a.rackno);
        printf("\n\n");
        j++;
        i = i + a.quantity;
    }
    gotoxy(3, 25);
    printf("Jumlah Buku =%d", i);
    fclose(fp);
    gotoxy(35, 25);
    returnfunc();
}
void ubahBuku(void) // Edit information about books
{
    system("cls");
    int c = 0;
    int d, e;
    gotoxy(20, 4);
    printf("****Bagian Ubah Buku****");
    char another = 'y';
    while (another == 'y')
    {
        system("cls");
        gotoxy(15, 6);
        printf("Masukkan Id Buku yang akan diubah:");
        scanf("%d", &d);
        fp = fopen("lib.dat", "rb+");
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (checkid(d) == 0)
            {
                gotoxy(15, 7);
                printf("Buku Tersedia");
                gotoxy(15, 8);
                printf("ID Buku:%d", a.id);
                gotoxy(15, 9);
                printf("Masukkan Nama Baru:");
                scanf("%s", a.name);
                gotoxy(15, 10);
                printf("Masukkan Penulis Baru:");
                scanf("%s", a.Author);
                gotoxy(15, 11);
                printf("Masukkan Jumlah Baru:");
                scanf("%d", &a.quantity);
                gotoxy(15, 12);
                printf("Masukkan Harga Baru:");
                scanf("%f", &a.Price);
                gotoxy(15, 13);
                printf("Masukkan Nomor Rak Baru:");
                scanf("%d", &a.rackno);
                gotoxy(15, 14);
                printf("Catatan diubah");
                fseek(fp, ftell(fp) - sizeof(a), 0);
                fwrite(&a, sizeof(a), 1, fp);
                fclose(fp);
                c = 1;
            }
            if (c == 0)
            {
                gotoxy(15, 9);
                printf("Tidak ada catatan yang ditemukan");
            }
        }
        gotoxy(15, 16);
        printf("Ubah Catatan lain?(Y/N)");
        fflush(stdin);
        another = getch();
    }
    returnfunc();
}
void returnfunc(void)
{
    {
        printf(" Tekan ENTER untuk kembali ke menu utama");
    }
a:
    if (getch() == 13) // allow only use of enter
        mainMenu();
    else
        goto a;
}
int getdata()
{
    int t;
    gotoxy(20, 3);
    printf("Masukkan Informasi Di Bawah Ini");
    gotoxy(20, 4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20, 5);
    printf("\xB2");
    gotoxy(46, 5);
    printf("\xB2");
    gotoxy(20, 6);
    printf("\xB2");
    gotoxy(46, 6);
    printf("\xB2");
    gotoxy(20, 7);
    printf("\xB2");
    gotoxy(46, 7);
    printf("\xB2");
    gotoxy(20, 8);
    printf("\xB2");
    gotoxy(46, 8);
    printf("\xB2");
    gotoxy(20, 9);
    printf("\xB2");
    gotoxy(46, 9);
    printf("\xB2");
    gotoxy(20, 10);
    printf("\xB2");
    gotoxy(46, 10);
    printf("\xB2");
    gotoxy(20, 11);
    printf("\xB2");
    gotoxy(46, 11);
    printf("\xB2");
    gotoxy(20, 12);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21, 5);
    printf("Kategori:");
    gotoxy(31, 5);
    printf("%s", catagories[s - 1]);
    gotoxy(21, 6);
    printf("ID Buku:\t");
    gotoxy(30, 6);
    scanf("%d", &t);
    if (checkid(t) == 0)
    {
        gotoxy(21, 13);
        printf("\aID buku sudah ada\a");
        getch();
        mainMenu();
        return 0;
    }
    a.id = t;
    gotoxy(21, 7);
    printf("Nama Buku:");
    gotoxy(33, 7);
    scanf("%s", a.name);
    gotoxy(21, 8);
    printf("Penulis:");
    gotoxy(30, 8);
    scanf("%s", a.Author);
    gotoxy(21, 9);
    printf("Jumlah:");
    gotoxy(31, 9);
    scanf("%d", &a.quantity);
    gotoxy(21, 10);
    printf("Harga:");
    gotoxy(28, 10);
    scanf("%f", &a.Price);
    gotoxy(21, 11);
    printf("Nomor Rak:");
    gotoxy(30, 11);
    scanf("%d", &a.rackno);
    return 1;
}
int checkid(int t) // check whether the book is exist in library or not
{
    rewind(fp);
    while (fread(&a, sizeof(a), 1, fp) == 1)
        if (a.id == t)
            return 0; // returns 0 if book exits
    return 1;         // return 1 if it not
}

void Password(void) // password option
{
    system("cls");
    char d[25] = "Masukkan Password";
    char ch, pass[10];
    int i = 0, j;

    gotoxy(10, 4);
    for (j = 0; j < 20; j++)
    {
        Sleep(50);
        printf(":");
    }
    for (j = 0; j < 20; j++)
    {
        Sleep(50);
        printf("%c", d[j]);
    }
    for (j = 0; j < 20; j++)
    {
        Sleep(50);
        printf(":");
    }
    gotoxy(10, 10);
    gotoxy(15, 7);
    printf("Masukkan Password:");

    while (ch != 13)
    {
        ch = getch();

        if (ch != 13 && ch != 8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, password) == 0)
    {

        gotoxy(15, 9);
        // textcolor(BLINK);
        printf("Sekarang Anda Telah Masuk!");
        gotoxy(17, 10);
        printf("\n\xB2\xB2\xB2\xB2\Tekan tombol apa saja untuk melanjutkan...");
        getch();
        mainMenu();
    }
    else
    {
        gotoxy(15, 16);
        printf("\aPeringatan!! Password Salah");
        getch();
        Password();
    }
}

void issuerecord() // display issued book's information
{
    system("cls");
    gotoxy(10, 8);
    printf("Buku telah dipinjam oleh Mr. %s", a.stname);
    gotoxy(10, 9);
    printf("Tanggal Pinjam:%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
    gotoxy(10, 10);
    printf("Tanggal Kembali:%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
}
