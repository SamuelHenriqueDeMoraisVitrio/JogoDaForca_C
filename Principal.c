#include <stdio.h>
#include <string.h>

int main(){
    //uma palavra pré-definida
    char palavraSecreta[20];
    //guarda "melancia" no array
    sprintf(palavraSecreta, "melancia\0");
    //acertou começa como falso, sem valor
    short acertou = NULL;
    //enforcou começa como positivo
    short enforcou = 1;

    //primeira coisa a se fazer no while
    do{
        //uma variavel do tipo string que guarda somente um caracter
        char chute;
        //Lẽ e guarda no ponteiro chute
        scanf("%c", &chute);

        //repete até que a string até chegar ao fim dela
        for (size_t i = 0; i < strlen(palavraSecreta); i++){
            //se uma das posições da palavraSecreta tiver a letra escolhida
            if(palavraSecreta[i] == chute){
                //escreve a posição encontrada a letra escolhida
                printf("A posição %zu tem essa letra\n", i);
            }
        }
    //Depois verificar
    //se (não acertou e não enforcou) faça:
    }while(!acertou && !enforcou);
}