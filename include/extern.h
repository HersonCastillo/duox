#ifndef EXTERNAL_H
#define EXTERNAL_H

#include "cmd.h"

unsigned char* limpiador_array(unsigned char* cmd){
	unsigned int i = 0u;
	while(cmd[i]){
		switch(cmd[i]){
			case 'a':
				cmd[i] = 'a';
			break;
			case 'b':
				cmd[i] = 'b';
			break;
			case 'c':
				cmd[i] = 'c';
			break;
			case 'd':
				cmd[i] = 'd';
			break;
			case 'e':
				cmd[i] = 'e';
			break;
			case 'f':
				cmd[i] = 'f';
			break;
			case 'g':
				cmd[i] = 'g';
			break;
			case 'h':
				cmd[i] = 'h';
			break;
			case 'i':
				cmd[i] = 'i';
			break;
			case 'j':
				cmd[i] = 'j';
			break;
			case 'k':
				cmd[i] = 'k';
			break;
			case 'l':
				cmd[i] = 'l';
			break;
			case 'm':
				cmd[i] = 'm';
			break;
			case 'n':
				cmd[i] = 'n';
			break;
			case 'o':
				cmd[i] = 'o';
			break;
			case 'p':
				cmd[i] = 'p';
			break;
			case 'q':
				cmd[i] = 'q';
			break;
			case 'r':
				cmd[i] = 'r';
			break;
			case 's':
				cmd[i] = 's';
			break;
			case 't':
				cmd[i] = 't';
			break;
			case 'u':
				cmd[i] = 'u';
			break;
			case 'v':
				cmd[i] = 'v';
			break;
			case 'w':
				cmd[i] = 'w';
			break;
			case 'x':
				cmd[i] = 'x';
			break;
			case 'y':
				cmd[i] = 'y';
			break;
			case 'z':
				cmd[i] = 'z';
			break;
			case '0':
				cmd[i] = '0';
			break;
			case '1':
				cmd[i] = '1';
			break;
			case '2':
				cmd[i] = '2';
			break;
			case '3':
				cmd[i] = '3';
			break;
			case '4':
				cmd[i] = '4';
			break;
			case '5':
				cmd[i] = '5';
			break;
			case '6':
				cmd[i] = '6';
			break;
			case '7':
				cmd[i] = '7';
			break;
			case '8':
				cmd[i] = '8';
			break;
			case '9':
				cmd[i] = '9';
			break;
		}
		i++;
	}
return cmd;
}

void limpiar_Bandera(void){
	asm volatile("cli":::);
}

unsigned char convert(unsigned int num){
	unsigned char Nl = ((unsigned char)num + 48);
	return Nl;
}

unsigned int conteo(unsigned char* f){
	unsigned int n = 0;
	while(f[n]) n += 1;
	return n;
}

int suma(unsigned int n1, unsigned int n2){
	int value = 0;
	asm volatile(
	"movl %1,%%eax\n"
	"movl %2,%%ebx\n"
	"addl %%ebx,%%eax\n"
	"mov %0,%%eax\n"
	: "=g"(value)
	: "g"(n1),"g"(n2)
	: "ax","bx","memory"
	);
}

unsigned char* on(unsigned char* cmd){
	limpiar_Bandera();
	cmd = limpiador_array(cmd);
	return cmd;
}
unsigned char *borrar_array(unsigned char *cmd){
	unsigned short i = 0;
	while(cmd[i]){
		switch(cmd[i]){
			case 'a':
				cmd[i] = 0;
			break;
			case 'b':
				cmd[i] = 0;
			break;
			case 'c':
				cmd[i] = 0;
			break;
			case 'd':
				cmd[i] = 0;
			break;
			case 'e':
				cmd[i] = 0;
			break;
			case 'f':
				cmd[i] = 0;
			break;
			case 'g':
				cmd[i] = 0;
			break;
			case 'h':
				cmd[i] = 0;
			break;
			case 'i':
				cmd[i] = 0;
			break;
			case 'j':
				cmd[i] = 0;
			break;
			case 'k':
				cmd[i] = 0;
			break;
			case 'l':
				cmd[i] = 0;
			break;
			case 'm':
				cmd[i] = 0;
			break;
			case 'n':
				cmd[i] = 0;
			break;
			case 'o':
				cmd[i] = 0;
			break;
			case 'p':
				cmd[i] = 0;
			break;
			case 'q':
				cmd[i] = 0;
			break;
			case 'r':
				cmd[i] = 0;
			break;
			case 's':
				cmd[i] = 0;
			break;
			case 't':
				cmd[i] = 0;
			break;
			case 'u':
				cmd[i] = 0;
			break;
			case 'v':
				cmd[i] = 0;
			break;
			case 'w':
				cmd[i] = 0;
			break;
			case 'x':
				cmd[i] = 0;
			break;
			case 'y':
				cmd[i] = 0;
			break;
			case 'z':
				cmd[i] = 0;
			break;
		default:	
			cmd[i] = '\0';
			cmd[i] = 0;
		}
		i++;
	}
	cmd = (void*)0;
	cmd = 0;
	return cmd;
}

unsigned int stdcmp(unsigned char *_for, unsigned char *_to){
	unsigned int i = 0, value = 0, result = 0;
	unsigned int conteoP1 = conteo(_for);
	unsigned int conteoP2 = conteo(_to);
	while(_for[i]){
		if(conteoP2 == conteoP1){
			if(_for[i] == _to[i]) value += 1;
			else break;
		}else break;
		i += 1;
	}
	result = (value == conteoP2) ? 1 : 0;
	return result;
}

unsigned int stdsrch_char(unsigned char *l, unsigned char t){
	unsigned int i = 0, value = 0, result = 0;
	while(l[i]){
		if(l[i] == t) break;
		else value++;
		i++;
	}
	result = (value == i) ? 0 : 1;
	return result;
}

unsigned int stdsrch_string(unsigned char *l, unsigned char *t){
	auto unsigned i = 0l, value = 0, result = 0;
	auto unsigned cont = conteo(t);
	while(l[i]){
		if(l[i] == t[i]) value++;
		i++;
	}
	result = (value == cont) ? 1 : 0;
	return result;
}

#endif
