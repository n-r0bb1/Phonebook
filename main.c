#include <stdio.h>
#include "menus.h"

//void open_file(int* max_users);


int max_users = 0;

int main()
{
    //meniu_contact(&max_users);
    open_file(&max_users);
   //rint_lista_contacte(1, max_users);
    main_menu(&max_users);
    printf("\n");

    return 0;
}
