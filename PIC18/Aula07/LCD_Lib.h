#ifndef LCD_LIB_H
#define LCD_LIB_H
/* 
Blibliteca para utilização do LCD da placa MCLab 3. 
Essa biblioteca já vem configurada para a placa da mosaico, 
não utilizar com outras placas.
*/

// Enviar um comando para o display
// Duração: 40uS 
void comando_lcd(unsigned char caracter);

// Escreve um caracter na posição do cursos, seguinto padrão ASCII
// Duração: 40uS 
void escreve_lcd(unsigned char caracter);

// Realiza a limpeza em todo o display, posicionando o cursor no primeiro caracter
// Duração: 1,65ms
void limpa_lcd(void);

// Inicializar, deve ser o primeiro comando para fazer com que o display
// receba as informações
// Duração: ~200uS 
void inicializa_lcd(void);

// Apresenta uma tela inicial, demonstrando o funcionamento do display
//Duração: ~1mS 
void tela_principal(void);


#endif
