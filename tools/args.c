#include "../include/math.h"
#include "../include/args.h"

extern unsigned int conteo(unsigned char*);
extern unsigned int stdcmp(unsigned char*,unsigned char*);
extern unsigned char *limpiador_array(unsigned char*);

unsigned short stdCommandArgs(unsigned char *cmd, unsigned char *sndCmd){
	auto unsigned short result = 0, i;
	auto unsigned cont = conteo(sndCmd);
	auto unsigned char *recibeChar = 0;
	for(i = 0;i<cont;i++){
		recibeChar[i] = cmd[i];
	}
	recibeChar = limpiador_array(recibeChar);
	if(stdcmp(recibeChar,sndCmd)) result = 1;
	return result;
}

unsigned int numArguments(unsigned char *command){
	auto unsigned int result = 0, i = 0;
	auto unsigned short Space = 0;
	while(command[i]){
	if(command[i] == ' '){
	if(!Space){ Space = 1; result++; }}
	if(Space){ if(command[i] != ' ') Space = 0; }
	i++; }
	return result;
}


unsigned short onlySpace(unsigned char *cmd){
	auto unsigned short result = 0;
	auto unsigned i = 0;
	auto unsigned cont = conteo(cmd);
	while(cmd[i]){
		if(cmd[i] != ' ') break;
		else i++;
	}
	result = (i == cont) ? 1 : 0;
	return result;
}

unsigned char *futureSpace(unsigned char *cmd){
	auto unsigned value = 0, i = 0, ii = 0;
	auto unsigned char *extracmd;
	extracmd = 0;
	while(cmd[i]){
		if(cmd[i] != ' '){
			extracmd[ii] = cmd[i];
			ii++;
		}
		i++;
	}
	extracmd = limpiador_array(extracmd);
	extracmd[ii] = 0;
	return extracmd;	
}
unsigned char *deleteArgs(unsigned char *cmd){
	auto unsigned i = 0;
	while(cmd[i]){
		cmd[i] = 0;
		i++;
	}
	cmd = 0;
	return cmd;
}

unsigned NoSpace(unsigned char *cmd){
	unsigned result = 0, i = 0;
	while(cmd[i]){
		if(cmd[i] == ' ') return 0;
		i++;
	}
	return 1;
}
