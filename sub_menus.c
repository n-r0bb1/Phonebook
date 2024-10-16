#pragma once
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
struct user
{
    char name[100];
    int block;
    char numar[20];
} Agenda[100];


///ARROW GENERATOR
void arrow_location(int poz_real, int poz_new)
{
    if(poz_real == poz_new)
        printf(">>");
    else printf("  ");
}
///

///GET KEY_VALUE
int key_value()
{
    char key = getch(); // get key_value
    int a = (int)key; //key_value in ASCII int
    return a;
}
///

///CLEAR SCREEN FUNC
void clear_screen()
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
///

///OPEN FILE + READ DATA///
void open_file(int* max_users)
{
    //(*max_users) = 0;
    FILE *in_file;

    in_file = fopen(".\\contact.csv", "r");
    if (in_file == NULL)
    {
        printf("Fisierul nu exista!");
    }

    else
    {
        (*max_users) = 0;
        char buffer[1024];
        char aux[1024];

        char a[5][1024] = {};
        while (fgets(buffer, 1024, in_file))
        {
            int n = 0;
            char *p;
            // printf("%s",buffer);
            char *token = strtok(buffer, "\n");
            strcpy(aux, token);

            for(p = strtok(aux, ","); p; p = strtok(NULL,","))
            {
                strcpy(a[n++],p);
            }
            int id = atoi(a[0]);
            //int nr = atoi(a[2]);

            strcpy(Agenda[id].name,a[1]);
            strcpy(Agenda[id].numar, a[2]);
            Agenda[id].block = atoi(a[3]);
            (*max_users)++;

            // printf("%d\n", (*max_users));
            //printf("MAX USERS");

        }
    }
    fclose(in_file);
}
/// PRINT LIST FROM CSV FILE///
void print_lista_contacte(int* poz_list,int max_users)
{

    int item = 1;
    int item1 = 1;
    int max_len = 0;

    while(item <=max_users)
    {
        //printf("ITEM = %d and MAX = %d", item,(*max_users));
        arrow_location(item, (*poz_list));
        if(item < 10)
        {
            if(Agenda[item].block == 1)
            {
                printf("%d.  \033[36m%s\033[0m ",item,Agenda[item].name);
                printf("\033[34m%s\033[0m ", Agenda[item].numar);
                printf("\033[31m(Blocat)\033[0m\n");
            }
            else
            {
                printf("%d.  \033[36m%s\033[0m ",item,Agenda[item].name);
                printf("\033[34m%s\033[0m\n", Agenda[item].numar);
            }
        }
        else
        {
            if(Agenda[item].block == 1)
            {
                printf("%d.  \033[36m%s\033[0m ",item,Agenda[item].name);
                printf("\033[34m%s\033[0m ", Agenda[item].numar);
                printf("\033[31m(Blocat)\033[0m\n");
            }
            else
            {
                printf("%d.  \033[36m%s\033[0m ",item,Agenda[item].name);
                printf("\033[34m%s\033[0m\n", Agenda[item].numar);
            }
        }
        item ++;

        //printf("Back");
    }
}

///////////////////////////////////

///MENIUS SEARCH///
void meniu_search(int *max_users)
{
    int poz_ms = 1;
    char key_ms = '\0';
    clear_screen();
    system("cls");

    while(key_ms != 13)
    {
        clear_screen();
        printf("#MENIU SEARCH#\n\n");

        printf("Selectati campul dupa care cautati...\n\n");
        arrow_location(1,poz_ms);
        printf("Nume\n");
        arrow_location(2,poz_ms);
        printf("Numar telefon\n");
        arrow_location(3,poz_ms);
        printf("Back\n");


        key_ms = key_value();

        if (key_ms==13 && poz_ms == 3) break; //check for i<= and poz || Access BACK
        else if (key_ms==13 && poz_ms == 1)
        {
            clear_screen();
            system("cls");
            int ok = 0;
            char name[100];
            printf("Introduceti Numele...");
            fgets(name,100,stdin);
            name[strlen(name)-1] = '\0';
            printf("\n");
            for(int i =1; i<(*max_users); i++)
            {
                if(strcmp(name,Agenda[i].name) == 0)
                {
                    ok = 1;
                    printf("ID Contact: %d\nNume Contact: %s\nNumar: %s\n",i,Agenda[i].name,Agenda[i].numar );

                }
            }

            if(ok == 0) printf("Contactul nu exista!\n");
            system("pause");
        } //check for ENTER and poz || Access meniu_contact
        else if (key_ms==13 && poz_ms == 2)
        {
            clear_screen();
            system("cls");
            int ok = 0;
            char numar[100];
            printf("Introduceti numarul...");
            fgets(numar,100,stdin);
            numar[strlen(numar)-1] = '\0';
            printf("\n");
            for(int i =1; i<(*max_users); i++)
            {
                if(strcmp(numar,Agenda[i].numar) == 0)
                {
                    ok = 1;
                    printf("iD Contact %d\nNume Contact: %s\nNumar: %s\n",i,Agenda[i].name,Agenda[i].numar);

                }
            }

            if(ok == 0) printf("Contactul nu exista!\n");
            system("pause");

        }//check for ENTER and poz || Access meniu_search
        else if((key_ms == 0 || key_ms == 80) && poz_ms != 3) // check for UP_KEY4
            poz_ms++; // pozitia creste, deci sageata se muta in jos
        else if((key_ms == 0 || key_ms == 72) && poz_ms != 1) // check for DOWN_KET
            poz_ms--; // pozitia scade, deci sageata se muta in sus
        else
            poz_ms = poz_ms; // FAIL CASE || nu se modifica pozitia

    }
    system("cls");
    return 0;
}
///////////////////////////////////

///ADD CONTACT///

void meniu_addcontact(int *max_users)
{
    char name[101];
    char numar[100];
    char choice;

    int ok = 0;
    clear_screen();
    system("cls");
    printf("#ADD Contact#\n\n");

    printf("Nume Contact ...  ");
    fgets(name, 100, stdin);
    name[strlen(name)-1] = '\0';

    printf("Numar de telefon ...  ");
    scanf("%s", &numar);
    getchar();

    printf("Adaugati contact?(Y\\N)...\n");
    scanf("%c",&choice);
    printf("%c ",choice);

    if (choice == 'Y' || choice == 'y')
    {
        printf("%d\n",(*max_users));
        (*max_users)++;
        Agenda[(*max_users)].block = 0;
        strcpy(Agenda[(*max_users)].name, name);
        strcpy(Agenda[(*max_users)].numar, numar);

        printf("%d,%s,%s\n",Agenda[(*max_users)].block,Agenda[(*max_users)].name,Agenda[(*max_users)].numar );
        printf("%d", (*max_users));

        FILE *in_file;
        in_file = fopen(".\\contact.csv", "w");
        if (in_file == NULL)
        {
            printf("Fisierul nu exista!");
        }
        else
        {
            for (int j = 1; j <= (*max_users); j++)
            {
                fprintf(in_file, "%d,%s,%s,%d\n", j, Agenda[j].name, Agenda[j].numar, Agenda[j].block); //,itoa(k,Agenda[i].block, 10));
            }
            system("cls");
            main_menu(max_users);
        }
    }
    else
    {
        system("cls");
        main_menu(max_users);
    }
    system("cls");
}
///////////////////////////////////

///BLOCL FUNTION
void bloc_func(int max_users, int id_)
{
    clear_screen();
    int id = id_;
    char choice;
    FILE  *in_file = fopen(".\\contact.csv", "w");
    if (Agenda[id].block == 1)
    {
        printf("Doriti sa deblocati acest contact?(Y\N)...\n");
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y')
        {
            Agenda[id].block = 0;
            if (in_file == NULL)
            {
                printf("Fisierul nu exista!");
            }
            else
            {
                for (int j = 1; j <= max_users; j++)
                {
                    fprintf(in_file, "%d,%s,%s,%d\n", j, Agenda[j].name, Agenda[j].numar, Agenda[j].block); //,itoa(k,Agenda[i].block, 10));
                }
                fclose(in_file);
            }
        }
        else
        {
            meniu_contact(max_users);
        }
    }
    else if (Agenda[id].block == 0)
    {
        printf("Doriti sa blocati acest contact(Y\N)?...\n");
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y')
        {
            Agenda[id].block = 1;
            if (in_file == NULL)
            {
                printf("Fisierul nu exista!");
            }
            else
            {
                printf("%d", max_users);
                for (int j = 1; j <= max_users; j++)
                {
                    fprintf(in_file, "%d,%s,%s,%d\n", j, Agenda[j].name, Agenda[j].numar, Agenda[j].block); //,itoa(k,Agenda[i].block, 10));
                }
                fclose(in_file);
            }

        }
        else
        {
            meniu_contact(max_users);
        }
    }
    fclose(in_file);
    system("cls");
}
///DELETE FUNCTION
void delete_user(int* max_users, int id_c)
{
    char choice;
    clear_screen();
    printf("Doriti sa stergeti acest user din lista de contacte?(Y/N)...\n");
    FILE *in_file;
    scanf("%c", &choice);
    if(choice == 'y' || choice == 'Y')
    {
        in_file = fopen(".\\contact.csv", "w");
        if (in_file == NULL)
        {
            printf("Fisierul nu exista!");
        }

        else
        {
            for(int i = id_c; i<(*max_users); i++)
            {
                strcpy(Agenda[i].numar,Agenda[i+1].numar);
                strcpy(Agenda[i].name,Agenda[i+1].name);
                Agenda[i].block = Agenda[i+1].block;
            }
            (*max_users) -= 1;

            for(int j = 1; j<=(*max_users); j++)
            {
                fprintf(in_file,"%d,%s,%s,%d\n",j,Agenda[j].name,Agenda[j].numar,Agenda[j].block);//,itoa(k,Agenda[i].block, 10));
            }
            fclose(in_file);
        }
        system("cls");
        meniu_contact((*max_users));
    }
    else
    {
        meniu_contact((*max_users));
    }
    system("cls");
}
//////////////////////////////////
