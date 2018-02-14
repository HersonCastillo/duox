#ifndef CODE_DECIFRED_H
#define CODE_DECIFRED_H
#include "tools.h"
#include "cmd.h"

unsigned char *decode_(unsigned char *text){
	auto unsigned char *result;
	unsigned int i = 0;
	text = on(text);
	result = null;
	if(text == null) print("<text null>");
	else {
		while(text[i]){
			switch(text[i]){
				case 'a':
					result[i] = ('n');
				break;
				case 'b':
					result[i] = ('o');
				break;
				case 'c':
					result[i] = ('p');
				break;
				case 'd':
					result[i] = ('q');
				break;
				case 'e':
					result[i] = ('r');
				break;
				case 'f':
					result[i] = ('s');
				break;
				case 'g':
					result[i] = ('t');
				break;
				case 'h':
					result[i] = ('u');
				break;
				case 'i':
					result[i] = ('v');
				break;
				case 'j':
					result[i] = ('w');
				break;
				case 'k':
					result[i] = ('x');
				break;
				case 'l':
					result[i] = ('y');
				break;
				case 'm':
					result[i] = ('z');
				break;
				case 'n':
					result[i] = ('a');
				break;
				case 'o':
					result[i] = ('b');
				break;
				case 'p':
					result[i] = ('c');
				break;
				case 'q':
					result[i] = ('d');
				break;
				case 'r':
					result[i] = ('e');
				break;
				case 's':
					result[i] = ('f');
				break;
				case 't':
					result[i] = ('g');
				break;
				case 'u':
					result[i] = ('h');
				break;
				case 'v':
					result[i] = ('i');
				break;
				case 'w':
					result[i] = ('j');
				break;
				case 'x':
					result[i] = ('k');
				break;
				case 'y':
					result[i] = ('l');
				break;
				case 'z':
					result[i] = ('m');
				break;
				default:
					result[i] = (text[i]);
			}
			i++;
		}
	}

	__asm__ __volatile__("cli":::"memory");
	return result;
}

/*
	# A B C D E F G H I J K L M #
	<                           >
	# N O P Q R S T U V W X Y Z #
*/

#endif
