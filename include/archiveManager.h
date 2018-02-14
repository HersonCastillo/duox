#ifndef MANAGER_H
#define MANAGER_H

#include "tools.h"
#include "cmd.h"

unsigned char *directory[] = {
	"home",
	"documents",
	"desktop"
};

void new_directory(unsigned char *name_dir);
void query_directory();
unsigned int dir_compare(unsigned char *fetch_array[], unsigned char *to_compare);

void new_directory(unsigned char *name_dir){
	unsigned i = 0;
	while(directory[i]) i++;
	directory[i++] = name_dir;
	print("\nEl directorio: '");	
	print_color(name_dir,COLOR_GREEN_);
	print("' ha sido creado.");	
	return;
}
void query_directory(){
	unsigned position = 0, i = 0;
	while(directory[position]){
		if(i > 3) { salto(); i = 0; }
		print_color(directory[position],COLOR_RED_);
		print(" ");
		position++;
		i++;
	}
}
unsigned int dir_compare(unsigned char *fetch_array[], unsigned char *to_compare){
	auto unsigned i = 0, j = 0, d = 0, value = 0, result = 0;
	while(fetch_array[i]){
		while(fetch_array[i][j]){
			if(fetch_array[i][j] == to_compare[j]) break;
			else value++;
			j++;
		}
		if(value == j) { value = 0; d++; }
		else break;
		i++;
	}
	result = (d == i) ? 0 : 1;
	return result;
}


#endif
