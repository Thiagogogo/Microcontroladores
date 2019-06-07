// teclado.c
#include <p18F4550.h>


int ler_teclado(void)
{
	
	int chave = 0;
	TRISD = 0b11110000;

	// LEITURA DE CHAVES
	
	PORTDbits.RD0 = 1;
	PORTDbits.RD1 = 0;
	PORTDbits.RD2 = 0;
	PORTDbits.RD3 = 0;
	if (PORTDbits.RD4 == 1)
	{
		chave = 1;
	}	
	if (PORTDbits.RD5 == 1)
	{
		chave = 5;
	}	
	if (PORTDbits.RD6 == 1)
	{
		chave = 9;
	}	
		if (PORTDbits.RD7 == 1)
	{
		chave = 11;
	}

	return chave;
}
	