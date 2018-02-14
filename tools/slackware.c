#include "../include/args.h"
#include "../include/cmd.h"

extern void print(unsigned char*);
extern void print_color(unsigned char*,unsigned int);
extern void pause(void);
extern void clearScreen(void);
extern unsigned char* limpiador_array(unsigned char*);
extern unsigned char *scanft(void);
#define salto print("\n")
#define clear clearScreen()

inline void slackware_(){
	salto;
	print("	 Bienvenido al simulador de instalacion del S.O Slackware.");
	salto;
	pause();
	clear;
	print_color("Pasos: \n",0x0C);
	print_color("* root: sirve para cederles los permisos especiales al usuario.\n",0xF);
	pause();
	salto;
	print_color("* cfdisk: para crear una particion, puede darse una numero en especial.\n",0xF);
	pause();
	salto;	
	print_color("* setup: cPanel de instalacion.\n",0xF);
	pause();
	salto;
	print_color("*root: login, con datos ya pedidos en cpanel.\n",0xF);
	pause();
	salto;
	print_color("*reboot: se reinicia la PC para terminar la instalacion.\n",0x0D);
	pause();
	salto;
	print_color("*startx: la GUI se carga y se lanza.\n",0x0A);
	pause();
	salto;
	print_color("FELICIDADES!! Instalastes Slackware.\n",0xF);
	pause();
	salto;

	salto;
	print("aplicacion terminada.- el sistema retomo el control.");
	return;
}
