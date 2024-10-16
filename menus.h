#ifndef menus.h
#define menus.h

///MENIURI///
void main_menu(int* max_users);
void meniu_contact(int max_users);
void submeniu_useri(int max_users,int id_con);
////////////////////////////////////////

///FUNCTII///
int key_value();
void clear_screen(void);
void arrow_location(int poz_real, int poz_new);
void open_file(int* max_users);
void print_lista_contacte(int* poz_list,int max_users);
void meniu_search(int *max_users);
void meniu_addcontact(int *max_users);
void bloc_func(int max_users,int id_con);
void delete_user(int *max_users, int id_c);
///////////////////////////////////////
#endif
