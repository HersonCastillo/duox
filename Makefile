#********************************************************************
#		(c) CCC Enterprise Technologies, Inc.		    *
#********************************************************************

CHANGE = -o
GCC = gcc
CHAOS = CHAOS.bin
LINKER = linker.ld
FUNCS = -nostdlib -ffreestanding -lgcc -fPIC
T = -T
EXCALIBUR = libs system_compilation image_iso extra

all: $(EXCALIBUR)
	@clear

image_iso:
	@echo "Generando Imagen [.iso]..."
	@(cd ../; mkdir Chronnos_chaosx86; cd Chronnos_chaosx86; mkdir boot; mkdir bin; cd boot; mkdir grub; cd ../bin; mkdir chaOS; cd ../../; cd duox/boot/grub; cp grub.cfg ../../../Chronnos_chaosx86/boot/grub; cd ../../bin/chaOS; cp CHAOS.bin ../../../Chronnos_chaosx86/bin/chaOS; cd ../../../; grub-mkrescue -o duox86.iso Chronnos_chaosx86; rm -fr Chronnos_chaosx86)

run:
	@echo "Ejecutando..."
	@(cd ../; qemu-system-i386 duox86.iso)

help:
	@echo ""
	@echo " MAKEFILE - DUOX OPERATIVE SYSTEM - (c)CCC ENTERPRISE TECHNOLOGIES, INC."
	@echo ""
	@echo "Para realizar la accion del Makefile tiene que ingresar solamente 'make' para ejecutar el compilador y realizar los cambios necesarios; si desea hacerlo manualmente debe ingresar 'make' (sin comillas) <comando>, 'comando' dependera de las siguientes instrucciones:"
	@echo ""
	@echo " * system_compilation  >   Compila los scripts basicos."
	@echo " * image_iso           >   Genera una imagen .iso del SO."
	@echo " * run                 >   Ejecuta el Sistema."
	@echo ""
	@echo "Intersched Corporation - v4.1.01"
	@echo ""

system_compilation:
	@echo "Compilando kernel..."
	@(cd kernel; as kernel.s -o kernel_ini.o; gcc -c main.c -o main.o)
	@echo "Compilando libreria..."
	@$(GCC) $(CHANGE) $(CHAOS) $(FUNCS) kernel/kernel_ini.o kernel/main.o include/idt.h include/keyboard.h include/assembly.h include/cursor.h include/print.h include/kernel.h include/tools.h include/packs.h include/string.h include/archiveManager.h include/decifred.h include/cmd.h include/extern.h include/ctypes.h include/math.h tools/math.o include/args.h tools/args.o tools/slackware.o tools/funt.o $(T)kernel/$(LINKER)
	@echo "Compilando Sistema Operativo..."
	@mv $(CHAOS) bin/chaOS/
	@echo "Compilacion terminada exitosamente."

extra:
	@(echo "Iniciando limpieza..."; echo "Amenaza: [~]..."; rm *~; cd boot/grub; rm *~; cd ../../; cd kernel/; rm *~; rm *.o; cd ../; cd include/; rm *~; cd ../; cd tools/;  rm *.o && rm *~; echo "Limpieza completada."; )

libs:
	@(cd tools; gcc -c math.c -o math.o; gcc -c args.c -o args.o; gcc -c funt.c -o funt.o; gcc -c slackware.c -o slackware.o)


#TODO: Sistema Operativo duox - 20160104

