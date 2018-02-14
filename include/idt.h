#ifndef IDT_H
#define IDT_H

#include "tools.h"

#define KERNEL_CS 0x08

typedef struct {
    unsigned short low_offset;
    unsigned short sel; 
    unsigned char always0;
    unsigned char flags; 
    unsigned short high_offset;
} __attribute__((packed)) idt_gate_t ;

typedef struct {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, unsigned int handler);
void set_idt();

void set_idt_gate(int n, unsigned int handler) {
    idt[n].low_offset = low_16(handler);
    idt[n].sel = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E; 
    idt[n].high_offset = high_16(handler);
}

void set_idt() {
    idt_reg.base = (unsigned int) &idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg));
}

//IDT - Parte de asm terminada

void isr0();
void isr1();
void isr2();
void isr3();
void isr4();
void isr5();
void isr6();
void isr7();
void isr8();
void isr9();
void isr10();
void isr11();
void isr12();
void isr13();
void isr14();
void isr15();
void isr16();
void isr17();
void isr18();
void isr19();
void isr20();
void isr21();
void isr22();
void isr23();
void isr24();
void isr25();
void isr26();
void isr27();
void isr28();
void isr29();
void isr30();
void isr31();


char *exception_messages[32];

void isr_install();

void isr_install() {
    set_idt_gate(0, (unsigned int)isr0);
    set_idt_gate(1, (unsigned int)isr1);
    set_idt_gate(2, (unsigned int)isr2);
    set_idt_gate(3, (unsigned int)isr3);
    set_idt_gate(4, (unsigned int)isr4);
    set_idt_gate(5, (unsigned int)isr5);
    set_idt_gate(6, (unsigned int)isr6);
    set_idt_gate(7, (unsigned int)isr7);
    set_idt_gate(8, (unsigned int)isr8);
    set_idt_gate(9, (unsigned int)isr9);
    set_idt_gate(10, (unsigned int)isr10);
    set_idt_gate(11, (unsigned int)isr11);
    set_idt_gate(12, (unsigned int)isr12);
    set_idt_gate(13, (unsigned int)isr13);
    set_idt_gate(14, (unsigned int)isr14);
    set_idt_gate(15, (unsigned int)isr15);
    set_idt_gate(16, (unsigned int)isr16);
    set_idt_gate(17, (unsigned int)isr17);
    set_idt_gate(18, (unsigned int)isr18);
    set_idt_gate(19, (unsigned int)isr19);
    set_idt_gate(20, (unsigned int)isr20);
    set_idt_gate(21, (unsigned int)isr21);
    set_idt_gate(22, (unsigned int)isr22);
    set_idt_gate(23, (unsigned int)isr23);
    set_idt_gate(24, (unsigned int)isr24);
    set_idt_gate(25, (unsigned int)isr25);
    set_idt_gate(26, (unsigned int)isr26);
    set_idt_gate(27, (unsigned int)isr27);
    set_idt_gate(28, (unsigned int)isr28);
    set_idt_gate(29, (unsigned int)isr29);
    set_idt_gate(30, (unsigned int)isr30);
    set_idt_gate(31, (unsigned int)isr31);

    set_idt();
}


void isr0()
{
    print(exception_messages[0]);
    asm("hlt");    
}
void isr1()
{
    print(exception_messages[1]);    
    asm("hlt");
}
void isr2()
{
    print(exception_messages[2]);    
    asm("hlt");
}
void isr3()
{
    print(exception_messages[3]);    
    asm("hlt");
}
void isr4()
{
    print(exception_messages[4]);    
    asm("hlt");
}
void isr5()
{
    print(exception_messages[5]);    
    asm("hlt");
}
void isr6()
{
    print(exception_messages[6]);    
    asm("hlt");
}
void isr7()
{
    print(exception_messages[7]);    
    asm("hlt");
}
void isr8()
{
    print(exception_messages[8]);    
    asm("hlt");
}
void isr9()
{
    print(exception_messages[9]);    
    asm("hlt");
}
void isr10()
{
    print(exception_messages[10]);    
    asm("hlt");
}
void isr11()
{
    print(exception_messages[11]);    
    asm("hlt");
}
void isr12()
{
    print(exception_messages[12]);    
    asm("hlt");
}
void isr13()
{
    print(exception_messages[13]);    
    asm("hlt");
}
void isr14()
{
    print(exception_messages[14]);    
    asm("hlt");
}
void isr15()
{
    print(exception_messages[15]);    
    asm("hlt");
}
void isr16()
{
    print(exception_messages[16]);    
    asm("hlt");
}
void isr17()
{
    print(exception_messages[17]);    
    asm("hlt");
}
void isr18()
{
    print(exception_messages[18]);    
    asm("hlt");
}
void isr19()
{
    print(exception_messages[19]);    
    asm("hlt");
}
void isr20()
{
    print(exception_messages[20]);    
    asm("hlt");
}
void isr21()
{
    print(exception_messages[21]);    
    asm("hlt");
}
void isr22()
{
    print(exception_messages[22]);    
    asm("hlt");
}
void isr23()
{
    print(exception_messages[23]);    
    asm("hlt");
}
void isr24()
{
    print(exception_messages[24]);    
    asm("hlt");
}
void isr25()
{
    print(exception_messages[25]);    
    asm("hlt");
}
void isr26()
{
    print(exception_messages[26]);    
    asm("hlt");
}
void isr27()
{
    print(exception_messages[27]);    
    asm("hlt");
}
void isr28()
{
    print(exception_messages[28]);    
    asm("hlt");
}
void isr29()
{
    print(exception_messages[29]);    
    asm("hlt");
}
void isr30()
{
    print(exception_messages[30]);    
    asm("hlt");
}
void isr31()
{
    print(exception_messages[31]);    
    asm("hlt");
}


char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};
 
#endif
