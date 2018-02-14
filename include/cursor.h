#include "tools.h"

void updateCursor(){
    unsigned temp;

    temp = cursorY * sw + cursorX;                                                   

    outportb(0x3D4, 14);                                                               
    outportb(0x3D5, temp >> 8);                                                         
    outportb(0x3D4, 15);                                                           
    outportb(0x3D5, temp);                                                              
}

void newLineCheck(){
        if(cursorY >=sh-1)
        {
                scrollUp(1);
        }
}

void scrollUp(unsigned short lineNumber){
        string vidmem = (string)0xb8000;
        unsigned short i = 0;
        clearLine(0,lineNumber-1);                                            
        for (i;i<sw*(sh-1)*2;i++)
        {
                vidmem[i] = vidmem[i+sw*2*lineNumber];
        }
        clearLine(sh-1-lineNumber,sh-1);
        if((cursorY - lineNumber) < 0 ) 
        {
                cursorY = 0;
                cursorX = 0;
        } 
        else 
        {
                cursorY -= lineNumber;
        }
        updateCursor();
}

void clearLine(unsigned short from,unsigned short to){
        unsigned short i = sw * from * sd;
        string vidmem=(string)0xb8000;
        for(i;i<(sw*to*sd);i++)
        {
                vidmem[i] = 0x0;
        }
}

void clearScreen(){
        clearLine(0,sh-1);
        cursorX = 0;
        cursorY = 0;
        updateCursor();
}
unsigned short strlength(string ch){
        unsigned short i = 0;         
        while(ch[i++]);  
        return i;               
}


