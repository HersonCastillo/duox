#include "../include/cmd.h"

extern unsigned char *decode_(unsigned char *);
extern void new_directory(unsigned char *);
extern void print(unsigned char*);
extern unsigned char *scanft();
extern unsigned char *limpiador_array(unsigned char*);
extern unsigned char *borrar_array(unsigned char*);
unsigned char *buffer = 0;

void _ggcemz(){
	print("E: ");
	auto unsigned char *message = scanft();
	auto unsigned char *newMessage = decode_(message);
	newMessage = limpiador_array(newMessage);
	print("\nS: ");
	print(newMessage);
	print("\n");
	print("aplicacion terminada.- el sistema retomo el control.");
	return;
}
void _hcdir(){
	print("Nombre de la carpeta: ");
	auto unsigned char *NameC = scanft();
	new_directory(NameC);
	return;
}
void _eco(){
	buffer = borrar_array(buffer);
	print(">");
	auto unsigned char *buff = scanft();
	buffer = buff;
	return;
}
void _buffEco(){
	if(buffer != (void*)0) print(buffer);
	else print("<null>");
	return;
}
void closed(){
	asm volatile("hlt":::"memory");
	/*asm volatile(
		"movl 5307, %%eax\n"
		"movl 0001, %%ebx\n"
		"movl 0003, %%ecx\n"
		"int $(0x0F)\n"
		: : : "ax","bx","cx","memory"
	);*/
}
