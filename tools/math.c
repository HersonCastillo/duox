#include "../include/math.h"

unsigned int xor(unsigned int x, unsigned int y){
	if(x < 0) return x;
	else if(y < 0) return y;
	unsigned int result = 0;
	asm volatile(
		"pushl %%eax\n"
		"pushl %%ebx\n"
		"movl %1,%%eax\n"
		"movl %2,%%ebx\n"
		"xorl %%ebx,%%eax\n"
		"movl %0,%%eax\n"
		"popl %%eax\n"
		"popl %%ebx\n"
		: "=g"(result) : "g"(x), "g"(y)
		: "ax", "bx", "memory"
	);
	return result;
}

unsigned long long _pow(unsigned x, unsigned y){
	unsigned long long result = 0;
	double i = 0;
	for(;i<(y-1);i++) result *= x;
	return result;
}

unsigned int not(unsigned int Num){
	if(Num < 0) return Num;
	unsigned int result = 0;
	asm volatile(
		"pushl %%eax\n"
		"movl %1,%%eax\n"
		"notl %%eax\n"
		"movl %0,%%eax\n"
		"popl %%eax\n"
		: "=g"(result) : "g"(Num)
		: "ax", "memory"
	);
	return result;
}

