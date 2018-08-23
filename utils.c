#include <stdio.h>


//Função para limbar buffer do teclado
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
