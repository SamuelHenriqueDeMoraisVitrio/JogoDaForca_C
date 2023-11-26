#include <stdio.h>
#include <string.h>

int main(){
    //uma palavra pré-definida
    const char palavraSecreta[] = "melancia\0";
    //acertou começa como falso, sem valor
    short acertou = NULL;
    //enforcou começa como positivo
    short enforcou = NULL;

    //primeira coisa a se fazer no while
    do{
        //uma variavel do tipo string que guarda somente um caracter
        char chute;
        //Lẽ e guarda no ponteiro chute//Espaço%c para ignorar o enter
        scanf(" %c", &chute);

        printf("\n");
        //repete até que a string até chegar ao fim dela
        for (size_t i = 0; i < strlen(palavraSecreta); i++){
            short chuteAcertou = 0;
            //se uma das posições da palavraSecreta tiver a letra escolhida
            if(palavraSecreta[i] == chute){
                chuteAcertou++;
                /*
                //escreve a posição encontrada a letra escolhida
                printf("\nA posição %zu tem essa letra\n", i);
                */
                printf(" %c", palavraSecreta[i]);
            }else{
                printf(" _");
            }
            if(chuteAcertou == strlen(palavraSecreta)){
                acertou = 1;
            }
        }
        printf("\n\n");
    //Depois verificar
    //se (não acertou e não enforcou) faça:
    }while(!acertou && !enforcou);
}
/*
#include <stdio.h>
#include <string.h>

int main() {

    char palavrasecreta[20];
    sprintf(palavrasecreta, "melancia");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    do {

        for(int i = 0; i < strlen(palavrasecreta); i++) {
            int achou = 0;

            for(int j = 0; j < tentativas; j++) {
                if(chutes[j] == palavrasecreta[i]) {
                    achou = 1;
                    break;
                }
            }

            if(achou) {
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        char chute;
        printf("Qual letra? ");
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;


    } while (!acertou && !enforcou);

}
*/