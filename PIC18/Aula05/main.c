/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * T�tulo do Programa:  Blablablabla...                                    *
 * Desenvolvido por:    Fulano de Tal, Z� das C�vi e Pinduca da Silva      *
 * IF Sudeste MG - Engenharia Mecatronica                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   VERS�O : 1.0                                                          *
 *   DATA : 21/05/2012                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                             Descri��o geral                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Template para desenvolvimento de programas e aplica��es com MCUs
// Adaptado dos exemplos fornecidos pela Labtools/Mosaico (www.mosaico.com.br)


// Observa��o: observe...

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              DEFINI��O PIC                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <p18F4550.h>           //Register definitions

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                INCLUDES DAS FUN��ES DE PERIF�RICOS DO PIC             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                         Configura��es para grava��o                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma config FOSC = HS
#pragma config CPUDIV = OSC1_PLL2
#pragma config WDT = OFF
#pragma config WDTPS = 128
#pragma config LVP = OFF
#pragma config PWRT = ON
#pragma config BOR = OFF
#pragma config BORV = 0
#pragma config PBADEN = OFF
#pragma config DEBUG = OFF
#pragma config PLLDIV = 1
#pragma config USBDIV = 1
#pragma config FCMEN = OFF
#pragma config IESO = OFF
#pragma config VREGEN = OFF
#pragma config MCLRE = ON
#pragma config LPT1OSC = OFF
#pragma config CCP2MX = ON
#pragma config STVREN = OFF
#pragma config ICPRT = OFF
#pragma config XINST = OFF

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *              Defini��o e inicializa��o das vari�veis globais          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//Neste bloco est�o definidas as vari�veis globais do programa.
//Este programa n�o utiliza nenhuma vari�vel de usu�rio
int uni = 0;
int dez = 0;
int cen = 0;
int mil = 0;



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           Constantes internas                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//A defini��o de constantes facilita a programa��o e a manuten��o.
//Este programa n�o utiliza nenhuma constante de usu�rio
const char tabela[] = {0b00111111,     // n�mero 0
                       0b00000110,     // n�mero 1
                       0b01111011,     // n�mero 2
                       0x4F,		   // n�mero 3
                       0x66,		   // n�mero 4
                       0x6D,		   // n�mero 5
                       0x7C,		   // n�mero 6
                       0x07,		   // n�mero 7
                       0x7F,		   // n�mero 8
                       0x67,		   // n�mero 9
                       0            // apaga display  
                       };


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                    Declara��o dos flags de software                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//A defini��o de flags ajuda na programa��o e economiza mem�ria RAM.
//Este programa n�o utiliza nenhum flag de usu�rio



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                       PROTOTIPAGEM DE FUN��ES                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                ENTRADAS                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// As entradas devem ser associadas a nomes para facilitar a programa��o e
//futuras altera��es do hardware.

#define BOTAO PORTDbits.RD4     //PORTA DO BOT�O S1
                                //1 -> PRESSIONADO
                                //0 -> LIBERADO

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                 SA�DAS                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//As sa�das devem ser associadas a nomes para facilitar a programa��o e
//futuras altera��es do hardware.

#define     LED         PORTBbits.RB0   //PORTA DO LED
                                        //0 -> APAGADO
                                        //1 -> ACESO

#define     COLUNA_1    PORTDbits.RD0   //PINO PARA ATIVAR COLUNA 1 DO TECLADO
                                        //MATRICIAL
                                        //1 -> COLUNA ATIVADA
                                        //0 -> COLUNA DESATIVADA

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                            Fun��o Principal                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void main(void)
{
	uni = 1;
	dez = 2;
	cen = 9;
	mil = 7;    

 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                        Inicializa��o do Sistema                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 // inicializando (limpando) as portas de I/O   
    PORTA = 0x00;               //Limpa PORTA
    PORTB = 0x00;               //Limpa PORTB
    PORTC = 0x00;               //Limpa PORTC
    PORTD = 0x00;               //Limpa PORTD
    PORTE = 0x00;               //Limpa PORTE

    LATA = 0x00;                //Limpa PORTA
    LATB = 0x00;                //Limpa PORTB
    LATC = 0x00;                //Limpa PORTC
    LATD = 0x00;                //Limpa PORTD
    LATE = 0x00;                //Limpa PORTE

 //configurando a dira��o dos pinos das portas de I/O  
   
    TRISA = 0b11000011;         //CONFIG DIRE��O DOS PINOS PORTA
    TRISB = 0b00000000;         //CONFIG DIRE��O DOS PINOS PORTB
    TRISC = 0b11111111;         //CONFIG DIRE��O DOS PINOS PORTC
    TRISD = 0b11110000;         //CONFIG DIRE��O DOS PINOS PORTD
    TRISE = 0b00000111;         //CONFIG DIRE��O DOS PINOS PORTE

    ADCON1 = 0b00001111;        //DESLIGA CONVERSORES A/D

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Inicializa��o de Vari�veis de Pinos de Sa�da do Sistema            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    COLUNA_1 = 1;                //ATIVA COLUNA 1 DO TECLADO MATRICIAL

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                            Rotina Principal                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    while(1)
    {
        //Insira aqui o seu programa;
        
        // unidade
        PORTAbits.RA2 = 1; // unidade
        PORTAbits.RA3 = 0; // dezena
        PORTAbits.RA4 = 0; // centena
        PORTAbits.RA5 = 0; // milhar
        PORTD = tabela[uni];
        Delay1KTCYx(4);
        
        
        // dezena
        PORTAbits.RA2 = 0; // unidade
        PORTAbits.RA3 = 1; // dezena
        PORTAbits.RA4 = 0; // centena
        PORTAbits.RA5 = 0; // milhar
        PORTD = tabela[dez];
        Delay1KTCYx(4);
        
        
        
        

    }
}   // FIM DO PROGRAMA

