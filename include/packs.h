#ifndef LOAD_PACKS_H
#define LOAD_PACKS_H

#include "tools.h"
#include "cmd.h"
unsigned char *commands[] = {
	"lmp",
	"buffer",
	"eco",
	"dir",
	"salir",
	"ayuda",
	"hcdir",
	"pausa",
	"ver"
};
unsigned char *warnings[] = {
	"error en la sintaxis del comando.",
	"comando desconocido."
};
unsigned char *valueOfCommand(unsigned char *cmd){
	unsigned char *result = (void*)0;
	unsigned i = 0, j = 0, r1 = false;
	while(cmd[i]){
		if(cmd[i] != ' '){
			result[j] = cmd[i];
			j++;
		}
		i++;
	}
	i = 0;
	while(i != 8){
		if(stdcmp(result,commands[i])){
			r1 = true;
			break;	
		} else r1 = false;
		i++;
	}
	if(r1) return warnings[0];
	else return warnings[1];
}
unsigned char *NotSpaces(unsigned char *cmd){
	unsigned char *result = (void*)0;
	unsigned i = 0, j = 0;
	while(cmd[i]){
		if(cmd[i] != ' '){
			result[j] = cmd[i];
			j++;
		}
		i++;
	}
	return result;
}
void help_stat(){
	salto();
	print("* lmp        ------------------------> Limpia la pantalla.");
	salto();
	print("* buffer     ------------------------> Datos almacenados en la pila.");
	salto();
	print("* eco        ------------------------> Envia datos al buffer.");
	salto();
	print("* dir        ------------------------> Directorio actual.");
	salto();
	print("* salir      ------------------------> Termina la ejecucion del sistema.");
	salto();
	print("* ayuda      ------------------------> Lista de los comandos de ayuda.");
	salto();
	print("* hcdir      ------------------------> Crear directorio.");
	salto();
	print("* pausa      ------------------------> Pausa el sistema.");
	salto();
	//T
	print("* ");
	print_color("slackware",COLOR_BLUE_);
	print("  ------------------------> Simulador de instalacion de SO Linux.");
	//T
	salto();
	print("* ver        ------------------------> Version del sistema.");

	salto();
}
void puntero(void){
	char *vidmem = (char*) 0xb8000;
	vidmem [((cursorY * 0x50 + cursorX))*0x02+1] = 0x07;
}



#endif
