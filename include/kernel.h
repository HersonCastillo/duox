#ifndef KERNEL_H
#define KERNEL_H
#define CAT_COMMAND_LANGUAGE_C(X,Y) X ##Y

#include "tools.h"
#include "assembly.h"
#include "cursor.h"
#include "keyboard.h"
#include "print.h"
#include "idt.h"
#include "string.h"
#include "packs.h"
#include "cmd.h"
#include "archiveManager.h"
#include "decifred.h"
#include "extern.h"
#include "ctypes.h"

struct user{
	union{
	unsigned char *dir;
	unsigned char *master;
	unsigned char *archive;
	};
}__attribute__((packed));
struct user usr = {
	.dir = null,
	.master = null,
	.archive = null
};
struct user *user_t;
unsigned char *command;
void incializar(){
	command = " lo ad ";
	NotSpaces(command);
	valueOfCommand(command);
}
static void _main_(unsigned result){
	if(!result){
		clearScreen();
		print_color("Mensaje del sistema: ",0x0c);
		print("duox ha encontrado un grave problema en el");
		salto();
		print("sistema interno, por favor solucionar el problema y reestablecer");
		salto();
		print("la sincronizacion con el sistema.");
		salto();
		salto();		
		print("Por favor reinicie el computador y verifique su problema.");
		asm volatile("hlt":::"memory");
	}
}

#endif
