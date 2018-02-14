#include "../include/kernel.h"
#include "../include/math.h"
#include "../include/args.h"

void chaos(void){
	isr_install();
	to_open();
	_main_(_start());
	incializar();	
	clearScreen();
	user_t = &usr;
	command = null;
	command = on(command);
	limpiar_Bandera();
	while(true){
	ini:
		command = limpiador_array(command);
		command = borrar_array(command);
		print("T:>");
		puntero();
		command = scanft();
		salto();
		if(command[0] == 0 | onlySpace(command)){
			command = on(command);
			command = borrar_array(command);
			limpiar_Bandera();
			command = null;
			goto ini;
		}else if(NoSpace(command)){
			if(stdcmp(command,"ayuda")){ help_stat(); command = deleteArgs(command); }
			else if(stdcmp(command,"lmp")) { clearScreen(); command = deleteArgs(command); goto ini; }
			else if(stdcmp(command,"ver")) { print(message_alerts(0)); command = deleteArgs(command); }
			else if(stdcmp(command,"pausa")) { pause(); command = deleteArgs(command); }
			//else if(stdcmp(command,"dir")) { query_directory(); command = deleteArgs(command); }
			//else if(stdcmp(command,"hcdir")) { _hcdir(); command = deleteArgs(command); }
			else if(stdcmp(command,"salir")){ clearScreen(); command = deleteArgs(command); print(message_alerts(8)); closed(); }
			else if(stdcmp(command,"encode")) {  _ggcemz(); command = deleteArgs(command); }
			else if(stdcmp(command,"eco")) { _eco(); command = deleteArgs(command); }
			else if(stdcmp(command,"buffer")) { _buffEco(); command = deleteArgs(command); }
			else if(stdcmp(command,"slackware")) { slackware_(); command = deleteArgs(command); }
			else {
				print(message_alerts(4));
				print(command);
				print(message_alerts(5));
				command = deleteArgs(command);
			}
		} else {
			print(NotSpaces(command));
			print(": ");
			print_color(valueOfCommand(command),COLOR_RED_);
		}
		command = on(command);
		command = borrar_array(command);
		command = deleteArgs(command);
		limpiar_Bandera();
		command = null;
		salto();
		salto();
	}

return;
}
