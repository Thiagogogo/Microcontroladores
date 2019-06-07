#include <p18F4550.h>           //Register definitions
#include <delays.h>

// Definições de hardware

#define     rs          PORTEbits.RE0   // via do lcd que sinaliza recepção de dados ou comando
#define     rw          PORTBbits.RB7   // via do lcd que configura leitura ou escrita no barramento
#define     enable      PORTEbits.RE1   // enable do lcd
#define 	COLUNA_1  	PORTDbits.RD0   // Coluna 1

// funções para controle do LCD

void comando_lcd(unsigned char caracter)
{
	int TrisTemp = TRISD;
    TRISD = 0b00000000; // configura portd como saída
    rs = 0;             // seleciona o envio de um comando
    PORTD = caracter;   // carrega o PORTD com o caracter
    enable = 1;         // gera pulso no enable
    Delay10TCYx(1);     // espera 10 microsegundos
    enable = 0;         // desce o pino de enable
    TRISD = 0b11110000; // CONFIGURA O PORTD PARA O TECLADO
    Delay10TCYx(4);     // espera mínimo 40 microsegundos
    TRISD = TrisTemp;
    TRISE = TRISE & 0b01111100;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                Rotina que envia um DADO a ser escrito no LCD            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void escreve_lcd(unsigned char caracter)
{
	int TrisTemp = TRISD;
    TRISD = 0b00000000; // configura portd como saída
    rs = 1;             // seleciona o envio de um dado
    PORTD = caracter;   // carrega o PORTD com o caracter
    enable = 1;         // gera pulso no enable
    Delay10TCYx(1);     // espera 10 microsegundos
    enable = 0;         // desce o pino de enable
    TRISD = 0b11110000; // CONFIGURA O PORTD PARA O TECLADO
    Delay10TCYx(4);     // espera mínimo 40 microsegundos
    COLUNA_1 = 1;       // ativa a coluna 1 do teclado
    TRISD = TrisTemp;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              Função para limpar o LCD                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void limpa_lcd(void)
{
    comando_lcd(0x01);  // limpa lcd    
    Delay1KTCYx(2);
}


void inicializa_lcd(void)
{
    rw = 0;             // pino rw em 0
    comando_lcd(0x30);  // envia comando para inicializar display
    Delay1KTCYx(4);     // espera 4 milisengundos

    comando_lcd(0x30);  // envia comando para inicializar display
    Delay10TCYx(10);    // espera 100 microsengundos

    comando_lcd(0x30);  // envia comando para inicializar display

    comando_lcd(0x38);  // liga o display, sem cursor e sem blink

    limpa_lcd();        // limpa lcd

    comando_lcd(0x0c);  // display sem cursor

    comando_lcd(0x06);  // desloca cursor para a direita	
}	

void tela_principal(void)
{
    limpa_lcd();               // limpa lcd
    comando_lcd(0x80);         // posiciona o cursor na linha 0, coluna 0
    escreve_lcd ('S');         // imprime mensagem no lcd 
    escreve_lcd ('i');
    escreve_lcd ('s');
    escreve_lcd ('t');
    escreve_lcd ('e');
    escreve_lcd ('m');
    escreve_lcd ('a');
    escreve_lcd (' ');
    escreve_lcd ('D');
    escreve_lcd ('i');
    escreve_lcd ('d');
    escreve_lcd ('a');
    escreve_lcd ('t');
    escreve_lcd ('i');
    escreve_lcd ('c');
    escreve_lcd ('o');

    comando_lcd(0xC5);         // posiciona o cursor na linha 1, coluna 5
    escreve_lcd ('M');         // imprime mensagem no lcd 
    escreve_lcd ('C');
    escreve_lcd ('L');
    escreve_lcd ('A');
    escreve_lcd ('B');
    escreve_lcd ('3');
}
