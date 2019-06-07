#ifndef LCD_LIB_H
#define LCD_LIB_H
/* 
Blibliteca para utiliza��o do LCD da placa MCLab 3. 
Essa biblioteca j� vem configurada para a placa da mosaico, 
n�o utilizar com outras placas.
*/

// Enviar um comando para o display
// Dura��o: 40uS 
void comando_lcd(unsigned char caracter);

// Escreve um caracter na posi��o do cursos, seguinto padr�o ASCII
// Dura��o: 40uS 
void escreve_lcd(unsigned char caracter);

// Realiza a limpeza em todo o display, posicionando o cursor no primeiro caracter
// Dura��o: 1,65ms
void limpa_lcd(void);

// Inicializar, deve ser o primeiro comando para fazer com que o display
// receba as informa��es
// Dura��o: ~200uS 
void inicializa_lcd(void);

// Apresenta uma tela inicial, demonstrando o funcionamento do display
//Dura��o: ~1mS 
void tela_principal(void);


#endif
