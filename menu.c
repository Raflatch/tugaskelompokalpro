#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int menu(int pilih);
int display5();
int display4();
int display3();
int display2();
int display();
int input_data_dosen();
int lihat_data_dosen();
int format_data();

int main()
{
    display();
    int angka;
    printf("pilihan menu: ");
    scanf("%d", &angka);
        switch (angka)
        {
        case 1:
            menu(1);
        case 2:
            menu(2);
            break;
        case 3:
            menu(3);
            break;
        case 4:
            menu(4);
            break;

    }
    return 0;
}
int menu(int pilih)
{
    switch(pilih)
    {
        case 1:
            lihat_data_dosen();
            display2();
            printf("\npilihan menu :");
            scanf("%d", &pilih);
            if(pilih==0)
            {
                display();
                int angka;
                printf("pilihan menu: ");
                scanf("%d", &angka);
                menu(angka);
            }
            break;
        case 2:
            input_data_dosen(); 
            display2();
            printf("\npilihan menu :");
            scanf("%d", &pilih);
            if(pilih==0)
            {
                display();
                int angka;
                printf("pilihan menu: ");
                scanf("%d", &angka);
                menu(angka);
            }
            break;
        case 3:
            format_data();
            display2();
            printf("\npilihan menu :");
            scanf("%d", &pilih);
            if(pilih==0)
            {
                display();
                int angka;
                printf("pilihan menu: ");
                scanf("%d", &angka);
                menu(angka);
            }
            break;
        case 4:
            exit(4);
            break;
    }
    return pilih;
}
int lihat_data_dosen()
{   
    char data_dosen[255],a[255],b[255],c[255],d[255];
    int p,j=0,hit=0,hit2=0,q;
    FILE *fptr;
    display4();
    printf("pilihan menu:");
    scanf("%d", &q);
    switch (q)
    {
    case 1:
        fptr = fopen("D:/app.py/project/data dosen/data dosen.txt","r");
        while(fgets(data_dosen, sizeof(data_dosen), fptr))
        {
            hit2=0;
            p=strlen(data_dosen);
            for (int i = 0; i < p ; ++i)
            {
                if (data_dosen[i]=='*')
                {
                    switch (hit2)
                    {
                        case 0:
                            printf("%s\n",d);
                        break;
                        case 1:
                            printf("nama dosen =%s\n",d);
                        break;
                        case 2:
                            printf("Umur dosen =%s\n",d);
                        break;
                        case 3:
                            printf("alamat dosen =%s\n",d);
                        break;
                        case 4:
                            printf("gelar dosen =%s\n",d);
                        break;
                    }
                    hit2++;
                    strcpy(d,"**");
                    hit=0;
                }
                else
                {
                    d[hit] = data_dosen[i];
                    d[hit+1] = '\0';
                    hit++;
                }          
            }
        }
        fclose(fptr);
        printf("\n");
        break;
    case 2:
        printf("ID dosen yang dicari=");
        scanf("%s", &c);
        fptr = fopen("D:/app.py/project/data dosen/data dosen.txt","r");
        while(fgets(a, sizeof(a), fptr))
        {
            if (strstr(a,c)!=NULL)
            {
                strcpy(b,a);                    
            }
        }
        fclose(fptr);
        p=strlen(b);
        for (int i = 0; i < p ; ++i)
        {
            if (b[i]=='*')
            {
                switch (hit2)
                {
                    case 0: 
                        printf("ID dosen =%s\n",d);
                    break;
                    case 1:
                        printf("nama dosen =%s\n",d);
                    break;
                    case 2:
                        printf("Umur dosen =%s\n",d);
                    break;
                    case 3:
                        printf("alamat dosen =%s\n",d);
                    break;
                    case 4:
                        printf("gelar dosen =%s\n",d);
                    break;
                }
                hit2++;
                strcpy(d,"**");
                hit=0;
            }
            else
            {
                d[hit] = b[i];
                d[hit+1] = '\0';
                hit++;
            }          
        }
    }
    
    return 0;
}
int input_data_dosen()
{
    char a[255],b[255],c[255],d[255],data_dosen[255];
    int g,p,hit=0,hit2=0;
    char *hasil;
    char nama_dosen[100],nama_dosen2[255];
    char umur[100],umur2[255];
    char alamat_dosen[100],alamat_dosen2[255];
    char gelar_dosen[100],gelar_dosen2[255];
    char ID_dosen[20],ID_dosen_check[20];
    FILE *fptr;
    display5();
    printf("pilihan menu:");
    scanf("%d", &g);
    switch (g)
    {
    case 1:
        printf("\n");
        fflush(stdin);
        printf("masukkan nama:");
        gets(nama_dosen);

        fflush(stdin);
        printf("masukkan umur:");
        scanf("%s",umur);
    
    
        fflush(stdin);
        printf("masukkan alamat:");
        gets(alamat_dosen);
    
        fflush(stdin);
        printf("masukkan gelar:");
        gets(gelar_dosen);
    
        fflush(stdin);
        printf("masukkan ID:");
        scanf("%s",ID_dosen);
    
    
        fptr=fopen("D:/app.py/project/data dosen/data dosen.txt","a");
        fprintf(fptr,ID_dosen);
        fprintf(fptr,"*");

        fputs(nama_dosen,fptr);
        fprintf(fptr,"*");

        fprintf(fptr,umur);
        fprintf(fptr,"*");
    
        fputs(alamat_dosen,fptr);
        fprintf(fptr,"*");
    
        fputs(gelar_dosen,fptr);
        fprintf(fptr,"*\n");
    
        printf("data berhasil terisi\n");
        fclose(fptr);
        break;
    
    case 2:
        printf("ID dosen yang dicari=");
        scanf("%s", &c);
    
        fptr = fopen("D:/app.py/project/data dosen/data dosen.txt","r");
        while(fgets(a, sizeof(a), fptr))
        {
            strcat(data_dosen,a);
            if (strstr(a,c)!=NULL)
            {
                strcpy(b,a);                    
            }
        }
        fclose(fptr);
        p=strlen(b);
        for (int i = 0; i < p ; ++i)
        {
            if (b[i]=='*')
                {
                    switch (hit2)
                    {
                        case 0: 
                            printf("ID dosen =%s\n",d);
                            break;
                        case 1:
                            printf("nama dosen =%s\n",d);
                            strcpy(nama_dosen,d);
                            break;
                        case 2:
                            printf("Umur dosen =%s\n",d);
                            strcpy(umur,d);
                            break;
                        case 3:
                            printf("alamat dosen =%s\n",d);
                            strcpy(alamat_dosen,d);
                            break;
                        case 4:
                            printf("gelar dosen =%s\n",d);
                            strcpy(gelar_dosen,d);
                            break;
                    }
                    hit2++;
                    strcpy(d,"**");
                    hit=0;
                }
                else
                {
                    d[hit] = b[i];
                    d[hit+1] = '\0';
                    hit++;
                }          
        }
            display3();
            printf("pilihan menu:");
            scanf("%d", &g);
        switch (g)
        {
            case 1:
                fflush(stdin);
                printf("masukkan nama baru=");
                gets(nama_dosen2);
                strcat(nama_dosen2,"*");
                p = strlen(nama_dosen2);
                hasil = strstr(data_dosen,nama_dosen);
                strncpy(hasil,nama_dosen2,p);
                break;
            case 2:
                printf("masukkan umur baru=");
                scanf("%s*", &umur2);
                strcat(umur2,"*");
                p = strlen(umur2);
                hasil = strstr(data_dosen,umur);
                strncpy(hasil,umur2,p);
                break;
            case 3:
                fflush(stdin);
                printf("masukkan alamat baru=");
                gets(alamat_dosen2);
                strcat(alamat_dosen2,"*");
                p = strlen(alamat_dosen2);
                hasil = strstr(data_dosen,alamat_dosen);
                strncpy(hasil,alamat_dosen2,p);
                break;
            case 4:
                fflush(stdin);
                printf("masukkan gelar baru=");
                gets(gelar_dosen2);
                strcat(gelar_dosen2,"*");
                p = strlen(gelar_dosen2);
                hasil = strstr(data_dosen,gelar_dosen);
                strncpy(hasil,gelar_dosen2,p);
                break;
        }
        fflush(stdin);
        remove("D:/app.py/project/data dosen/data dosen.txt");
        fptr = fopen("D:/app.py/project/data dosen/data dosen.txt","a");
        fputs(data_dosen,fptr);
        fclose(fptr);
        break;
    }
    return 0;
}
int format_data()
{
    FILE *fptr;
    remove("D:/app.py/project/data dosen/data dosen.txt");
    fptr = fopen("D:/app.py/project/data dosen/data dosen.txt","w");
    fclose (fptr);
    printf("data telah diformat\n");
    return 0;
}
int display()
{
    printf("|===================================|\n");
    printf("|     Sistem Data Informasi Dosen   |\n");
    printf("|-----------------------------------|\n");
    printf("|1| lihat data dosen           :    |\n");
    printf("|2| Tambah/edit data Dosen     :    |\n");
    printf("|3| Format Data                :    |\n");
    printf("|4| Exit Program               :    |\n");
    printf("|===================================|\n");
    
    return 0;
}
int display2()
{
    printf("|===================================|\n");
    printf("|     Sistem Data Informasi Dosen   |\n");
    printf("|-----------------------------------|\n");
    printf("|0| kembali ke menu awal       :    |\n");
    printf("|===================================|\n");

    return 0;
    
}
int display3()
{
    printf("|===================================|\n");
    printf("|     Sistem Data Informasi Dosen   |\n");
    printf("|-----------------------------------|\n");
    printf("|         edit data dosen           |\n");
    printf("|-----------------------------------|\n");
    printf("|1| nama dosen                 :    |\n");
    printf("|2| umur dosen                 :    |\n");
    printf("|3| alamat dosen               :    |\n");
    printf("|4| gelar Dosen                :    |\n");
    printf("|===================================|\n");
}
int display4()
{
    printf("|===================================|\n");
    printf("|     Sistem Data Informasi Dosen   |\n");
    printf("|-----------------------------------|\n");
    printf("|         lihat data dosen          |\n");
    printf("|-----------------------------------|\n");
    printf("|1| data dosen                 :    |\n");
    printf("|2| pencarian data dosen       :    |\n");
    printf("|===================================|\n");
}
int display5()
{
    printf("|===================================|\n");
    printf("|     Sistem Data Informasi Dosen   |\n");
    printf("|-----------------------------------|\n");
    printf("|      tambah/edit data dosen       |\n");
    printf("|-----------------------------------|\n");
    printf("|1| tambah data dosen          :    |\n");
    printf("|2| edit data dosen            :    |\n");
    printf("|===================================|\n");
}
