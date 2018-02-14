#ifndef TYPES_H
#define TYPES_H
#define inicializate 1
#define desactived 0
struct connect{
	unsigned bitdefault: 1;
	unsigned bit0: 1;
	unsigned bit1: 1;
	unsigned bit2: 1;
	unsigned bit3: 1;
	unsigned bit4: 1;
	unsigned bit5: 1;
	unsigned bit6: 1;
	unsigned bit7: 1;
	unsigned bit8: 1;
	unsigned bit9: 1;
	unsigned bit10: 1;
	unsigned bit11: 1;
	unsigned bit12: 1;
	unsigned bit13: 1;
	unsigned bit14: 1;
	unsigned bit15: 1;
	long long: 32;
}__attribute__((packed));
struct connect *kernel_hlt;
struct connect onfirst = {
	.bitdefault = 	1,
	.bit0 = 	inicializate,
	.bit2 =		inicializate,
	.bit4 = 	inicializate,
	.bit6 = 	inicializate,
	.bit8 = 	inicializate,
	.bit10 = 	inicializate,
	.bit12 = 	inicializate,
	.bit14 = 	inicializate,
	.bit1 = 	desactived,
	.bit3 = 	desactived,
	.bit5 = 	desactived,
	.bit7 = 	desactived,
	.bit9 = 	desactived,
	.bit11 = 	desactived,
	.bit13 = 	desactived,
	.bit15 = 	desactived
};

static unsigned _start(){
	kernel_hlt = &onfirst;
	if(kernel_hlt->bit0 & kernel_hlt->bit15){
	if(kernel_hlt->bit2 & kernel_hlt->bit13);
	else return desactived;
	if(kernel_hlt->bit4 & kernel_hlt->bit11);
	else return desactived;
	if(kernel_hlt->bit6 & kernel_hlt->bit9);
	else return desactived;
	if(kernel_hlt->bit8 & kernel_hlt->bit7);
	else return desactived;
	if(kernel_hlt->bit10 & kernel_hlt->bit5);
	else return desactived;
	if(kernel_hlt->bit12 & kernel_hlt->bit3);
	else return desactived;
	if(kernel_hlt->bit14 & kernel_hlt->bit1)
	return inicializate;
	else return desactived;
	}else return desactived;
}

static void to_open(){
	kernel_hlt = &onfirst;
	unsigned port1 = inicializate, 
		 port2 = desactived, 
		 port3 = inicializate, 
		 port4 = desactived;
	__asm__ __volatile__(
		"pushl %%eax\n\t"
		"pushl %%ebx\n\t"
		"movl %1,%%eax\n\t"
		"movl %2,%%ebx\n\t"
		"xorl %%ebx,%%eax\n\t"
		"movl %0,%%eax\n\t"
		"popl %%eax\n\t"
		"popl %%ebx\n\t" 
		: "=g" (port4) : "g"(port1), "g"(port2)
		: "ax", "bx", "memory"
	);
	if(port4 ^ port3){
		kernel_hlt->bit1 |= 	kernel_hlt->bitdefault;
		kernel_hlt->bit3 |= 	kernel_hlt->bitdefault;
		kernel_hlt->bit5 |= 	kernel_hlt->bitdefault;
		kernel_hlt->bit7 |= 	kernel_hlt->bitdefault;
		kernel_hlt->bit9 |= 	kernel_hlt->bitdefault;
		kernel_hlt->bit11 |= 	kernel_hlt->bitdefault;
		kernel_hlt->bit13 |= 	kernel_hlt->bitdefault;
		kernel_hlt->bit15 |= 	kernel_hlt->bitdefault;
	}
	return;
}


#endif


