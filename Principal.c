#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
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
    short numDeLinhas = NULL;
    short linhaAleatoria = NULL;
    
    f = fopen("palavras.txt", "r");
     if(f == 0){
        printf("\n\nErro ao encontrar banco de dados\n\n");
        exit(1);
     }

    fscanf(f, " %d", &numDeLinhas);

    srand(time(NULL));
    linhaAleatoria = rand() % numDeLinhas;

    for(size_t i = 0; i <= linhaAleatoria; i++){
        
        fscanf(f, "%s", palavrasecreta);
    }
    fclose(f);
}

short acertou(){
    for(size_t i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

void adicionarPalavra(){
    char quer;

    printf("Quer adicionar uma nova palavra? [S/N]\n");
    scanf(" %c", &quer);

    getchar();
    if(quer == 'S' || quer =='s'){
        char novaPalavra[20];

        sleep(1);
        printf("\nDigite uma nova palavra em minusculo\n");

        scanf(" %s", novaPalavra);

        FILE *f;

        f = fopen("palavras.txt", "r+");
        if(f == 0) {
            printf("Banco de dados de palavras não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

int main(){

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());
    adicionarPalavra();
}