#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void meniu_contact(int max_users);

struct user
{
    char name[50];
    char numar[50];
    int block;

} Agenda [100];

/// MAIN MENU ///
void main_menu(int* max_users)
{

    clear_screen();
    //VARIABLES//
#define MAX 4
#define MIN 1

    int poz_cur = 1;
    char key = '0';
    ///////////////

    while(key !=13)
    {

        clear_screen();
        //printf("MAX = %d \n\n",(*max_users));
        //
        printf("#Meniu contacte#\n\n");
        arrow_location(1,poz_cur);
        printf("Lista Contacte\n");
        arrow_location(2,poz_cur);
        printf("Search\n");
        arrow_location(3,poz_cur);
        printf("Add Contact\n");
        arrow_location(4,poz_cur);
        printf("Exit\n");
        //

        //
        int key_asc = key_value();
        printf("\n%d\n",key_asc);
        //
        if (key_asc==13 && poz_cur == MAX) break; //check for ENTER and poz || Access BACK
        else if (key_asc==13 && poz_cur == 1) meniu_contact((*max_users)); //check for ENTER and poz || Access meniu_contact
        else if (key_asc==13 && poz_cur == 2) meniu_search(max_users);//check for ENTER and poz || Access meniu_search
        else if (key_asc==13 && poz_cur == 3) meniu_addcontact(max_users);//check for ENTER and poz || Access meniu_addcontact
        else if((key_asc == 0 || key_asc == 80) && poz_cur != MAX) // check for UP_KEY4
            poz_cur++; // pozitia creste, deci sageata se muta in jos
        else if((key_asc == 0 || key_asc == 72) && poz_cur != MIN) // check for DOWN_KET
            poz_cur--; // pozitia scade, deci sageata se muta in sus
        else
            poz_cur = poz_cur; // FAIL CASE || nu se modifica pozitia
    }
}
////////////////

/// MENIU CONTACTE ///
void meniu_contact(int max_users)
{

#define MIN 1
    ;
    int poz_mc = 1;
    int key_mc = '0';
    int max = max_users;
    open_file(&max);


    system("cls");
    //printf("THIS IS MAX USERS CONTACT%d\n", max_users);
    printf("#Lista Contacte#\n\n");
    print_lista_contacte(&poz_mc,max_users);

    while(key_mc != 27)
    {
        clear_screen();

        printf("#Lista Contacte#\n\n");
        // printf("  ID Nume Prenume Numar\n\n");

        print_lista_contacte(&poz_mc, max_users);

        arrow_location(max_users+1,poz_mc);
        printf("Back\n");

        key_mc = key_value();
        //printf("%d",key_mc);


        if(key_mc == 13 && poz_mc <= max_users && poz_mc >= 1)
        {
            submeniu_useri(max_users,poz_mc);
        }
        else if (key_mc == 13 || (key_mc == 13 && poz_mc == max_users+1) || key_mc == 27)
        {
            system("cls");
            break;
        }
        else if((key_mc == 0 || key_mc == 80) && poz_mc <= max_users) // check for UP_KEY
        {

            poz_mc++; // pozitia creste, deci sageata se muta in jos
            //printf("POZ =%d", poz_mc);
        }
        else if((key_mc == 0 || key_mc == 72) && poz_mc >= MIN) // check for DOWN_KET
            poz_mc--; // pozitia scade, deci sageata se muta in sus
        else
            poz_mc = poz_mc;
    }
}
////////////////////////////////

///SUB MENIU EDIT USERS///
void submeniu_useri(int max_users,int id_con)
{
#define MIN 1
#define MAX 3

    int poz_smu = 1;
    int key_smu = '0';
    system("cls");


    while(key_smu != 27)
    {
        clear_screen();

        printf("#Editare Contact#\n\n");

        arrow_location(1, poz_smu);
        printf("Stergere Contact \n");
        arrow_location(2, poz_smu);
        printf("Blocare Contact\n");
        arrow_location(3, poz_smu);
        printf("Back\n");

        key_smu = key_value();
        //printf("%d",key_smu);
        if(key_smu == 13 && poz_smu == 1)
        {
            clear_screen();
            system("cls");
            delete_user(&max_users,id_con);
        }
        else if(key_smu == 13 && poz_smu == 2)
        {
            clear_screen();
            system("cls");
            bloc_func(max_users,id_con);
        }
        else if (key_smu == 27 || (key_smu == 13 && poz_smu == MAX))
        {
            system("cls");
            break;
        }
        else if((key_smu == 0 || key_smu == 80) && key_smu != MAX) // check for UP_KEY
            poz_smu++; // pozitia creste, deci sageata se muta in jos
        else if((key_smu == 0 || key_smu == 72) && poz_smu != MIN) // check for DOWN_KET
            poz_smu--; // pozitia scade, deci sageata se muta in sus
        else
            poz_smu = poz_smu;
    }
}
/////////////////////////////////
