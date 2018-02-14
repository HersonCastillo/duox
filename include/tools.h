#ifndef TOOLS_H
//CCC Company. [2012-2013]
//CCC Enterprise Games. [2014]
//CCC Enterprise Technologies,Inc. [2015]
//(c) Intersched Corporation. [2016]
#define TOOLS_H
#define null	((void *)0)
#define NULL 	0
#define salto() printch('\n');
#define low_16(address) (unsigned short)((address) & 0xFFFF)            
#define high_16(address) (unsigned short)(((address) >> 16) & 0xFFFF)

typedef char *string;
enum bool{ false, true };
enum colors_abm{
	COLOR_BLACK,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_WATER,
	COLOR_RED,
	COLOR_PURPLE,
	COLOR_YELLOW,
	COLOR_WHITE,
	COLOR_GRAY,
	COLOR_BLUE_,
	COLOR_GREEN_,
	COLOR_WATER_,
	COLOR_RED_,
	COLOR_PURPLE_,
	COLOR_YELLOW_,
	COLOR_WHITE_,
};
int cursorX = 0, cursorY = 0;
const unsigned short sw = 80, sh = 25, sd = 2; 
void clearScreen();
unsigned char inportb(unsigned short);
void clearLine(unsigned short,unsigned short);
void outportb (unsigned short, unsigned char);
unsigned char *scanft(); 
void print(unsigned char*);
unsigned short strlength(char*);
void printch(char);
void newLineCheck();
void updateCursor();
void scrollUp(unsigned short);
unsigned char *message_alerts(unsigned int);
void help_stat();
void puntero(void);
void printch_hexacolor(char, unsigned int);
void print_color(unsigned char*, unsigned int);
void new_directory(unsigned char*);
void query_directory();
unsigned int dir_compare(unsigned char *[], unsigned char *);
unsigned char *decode_(unsigned char*);
static unsigned _start();
static void to_open();
unsigned char *valueOfCommand(unsigned char *);


#endif
