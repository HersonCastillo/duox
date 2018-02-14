#ifndef STRING_H
#define STRING_H
#define NULL 	0

unsigned int strln(unsigned char *format){
	unsigned int i = 0;
	while(format[i]) i++;
	return i;
}

unsigned char *cat(unsigned char *_f, unsigned char *_t){
	auto unsigned i = 0, j = 0, f = 0;
	unsigned char *val = NULL;
	val = (void*)NULL;
	auto unsigned conteof = strln(_f), conteot = strln(_t);
	auto unsigned conteo = ((conteof + conteot));
	while(_f[i]){ val[i] = _f[i]; i++; }
	while(_t[j]){ val[i++] = _t[j]; j++; }
	while(val[f]){ if(f > conteo) val[f] = NULL; f++; }
	i = NULL; j = NULL; f = NULL;
	__asm__ __volatile__("cli":::"memory");
	return val;
}

unsigned char *message_alerts(unsigned int number){
	unsigned char *message[] = {
		"duox kernel: 1.0.1804.16-nodistribuibleBASIC, (c) Herson Castillo.",
		"",/*[1]*/
		"Configuracion de duox no disponible.",
		"",/*[3]*/
		"error: '",
		"' comando externo o interno no encontrado.",
		"",/*[6]*/
		"",/*[7]*/
		"Estado del sistema: Apagada, tomar medidas preventivas con el computador.",
		"",/*[9]*/
		"Error en la sintaxis del comando.",
		"FATAL_ERROR: En la funcion 'message_alerts()', mensaje no encontrado."
	};
	if(number < 0 || number > 10) return message[11];
	else return message[number];
}

#endif
