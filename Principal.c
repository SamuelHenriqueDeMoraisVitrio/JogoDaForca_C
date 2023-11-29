#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[20];
char chutes[26];
short chutesDados = 0;

short enforcou(){

    short erros = 0;

    // vamos fazer o loop em todos os chutes dados
    for(size_t i = 0; i < chutesDados; i++){

        short existe = 0;

        // agora vamos olhar letra a letra da palavra secreta
        // e ver se encontramos o chute aqui
        for(size_t j = 0; j < strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]) {

                // encontramos, vamos quebrar o loop
                existe = 1;
                break;
            }
        }

        // se nao encontrou, soma um na quantidade de erros
        if(!existe) erros++;
    }

    // se tivermos mais do que 5 erros, retornamos 1
    // caso contrario, retornamos 0.
    return erros >= 5;
}

void abertura(){
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta(){
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

short jachutou(char letra){
    short achou = 0;
    for(size_t j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca(){

    printf("Você já deu %d chutes\n", chutesDados);

    for(size_t i = 0; i < strlen(palavrasecreta); i++){

        if(jachutou(palavrasecreta[i])){
            printf("%c ", palavrasecreta[i]);
        } else{
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra(){
    FILE *f;
    
    f = fopen("../palavras.txt", "r");
     if(f == 0){
        printf("\n\nErro ao encontrar banco de dados\n\n");
        exit(1);
     }
    short numDeLinhas = 0;
    short linhaAleatoria = 0;

    fscanf(f, "%hd", &numDeLinhas);

    srand(time(NULL));
    linhaAleatoria = rand() % numDeLinhas;

    for(size_t i = 0; i <= linhaAleatoria; i++){
        
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
    //sprintf(palavrasecreta, "melancia");
}

short acertou(){
    for(size_t i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}


int main(){

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());
}