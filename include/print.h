#ifndef PRINT_H
#define PRINT_H

#include "tools.h"

void print(unsigned char *ch){
        unsigned short i = 0;
        unsigned char length = strlength(ch)-1;              
        for(i;i<length;i++){
                printch(ch[i]);
        }        
}

void printch(char c){
    unsigned char *vidmem = (unsigned char*) 0xb8000;     
    switch(c){
        case (0x08):
                if(cursorX > 0){
	                cursorX--;									
                        vidmem[(cursorY * sw + cursorX)*sd]=0x00;	                              
	        }
	        break;
        case ('\r'):
                cursorX = 0;
                break;
        case ('\n'):
                cursorX = 0;
                cursorY++;
                break;
        default:
                vidmem [((cursorY * sw + cursorX))*sd] = c;
                vidmem [((cursorY * sw + cursorX))*sd+1] = 0x07;
                cursorX++; 
                break;
	
    }
    if(cursorX >= sw){
        cursorX = 0;                                                                
        cursorY++;                                                                    
    }
    updateCursor();
    newLineCheck();
}

void print_color(unsigned char *ch, unsigned int color_t){
        unsigned short i = 0;
        unsigned char length = strlength(ch)-1;              
        for(i;i<length;i++){
                printch_hexacolor(ch[i], color_t);
        }        
}

void printch_hexacolor(char c, unsigned int color){
    unsigned char *vidmem = (unsigned char*) 0xb8000;     
    switch(c){
        case (0x08):
                if(cursorX > 0){
	                cursorX--;									
                        vidmem[(cursorY * sw + cursorX)*sd]=0x00;	                              
	        }
	        break;
        case ('\r'):
                cursorX = 0;
                break;
        case ('\n'):
                cursorX = 0;
                cursorY++;
                break;
        default:
                vidmem [((cursorY * sw + cursorX))*sd] = c;
                vidmem [((cursorY * sw + cursorX))*sd+1] = color;
                cursorX++; 
                break;
	
    }
    if(cursorX >= sw){
        cursorX = 0;                                                                
        cursorY++;                                                                    
    }
    updateCursor();
    newLineCheck();
}



#endif

