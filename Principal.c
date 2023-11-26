#include <stdio.h>
#include <string.h>

int main() {

    //palavra pré-definida
    const char palavrasecreta[] = "melancia\0";

    //acertou e enforcou começa como falso
    short acertou = NULL;
    short enforcou = NULL;

    //numero limitado de chutes de acordo com o array
    char chutes[26];
    short tentativas = 0;

    do {

        //Loop para repetir em todas as casas da palavra secreta
        for(size_t i = 0; i < strlen(palavrasecreta); i++){
            //acho começa com 0
            short achou = 0;

            //loop para achou receber 1 caso o nu chutado é igual a palavra secreta
            for(size_t j = 0; j < tentativas; j++){
                if(chutes[j] == palavrasecreta[i]) {
                    achou = 1;
                    break;
                }
            }

            //se a palacra ja foi chutada escreva caso não escreva _
            if(achou) {
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        //lê a letra
        char chute;
        printf("Qual letra? ");
        scanf(" %c", &chute);

        //coloca o caracter lido dentro de chutes
        chutes[tentativas] = chute;
        tentativas++;
    } while (!acertou && !enforcou);
}