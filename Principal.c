#include <stdio.h>
#include <string.h>

char palavrasecreta[20];
char chutes[26];
short tentativas = 0;

void abertura(){
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta(){
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int jachutou(char letra){
    short achou = 0;
    for(size_t j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca(){

    printf("Você já deu %d chutes\n", tentativas);

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
    sprintf(palavrasecreta, "melancia");
}

int main(){

    int acertou = NULL;
    int enforcou = NULL;

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

    } while (!acertou && !enforcou);
}
/*
#include <stdio.h>
#include <string.h>

void abertura(){
    printf("/****************\n");
    printf("/ Jogo de Forca *\n");
    printf("/****************\n\n");
}

void chuta(char chutesP[26], short *tentativasP;){
    //lê a letra
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    //coloca o caracter lido dentro de chutes
    chutesP[*tentativasP] = chute;
    *tentativasP++;
}

int jaChuto(char letra; char chutes[26], short tentativas){
    //acho começa com 0
    short achou = 0;

    //loop para achou receber 1 caso o nu chutado é igual a palavra secreta
    for(size_t j = 0; j < tentativas; j++){
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

int main() {

    //palavra pré-definida
    const char palavrasecreta[] = "melancia\0";

    //acertou e enforcou começa como falso
    short acertou = NULL;
    short enforcou = NULL;

    //numero limitado de chutes de acordo com o array
    char chutes[26];
    short tentativas = 0;

    abertura();

    do {

        //Loop para repetir em todas as casas da palavra secreta
        for(size_t i = 0; i < strlen(palavrasecreta); i++){
            
            int achou = jaChuto(palavrasecreta[i], chutes, tentativas);

            //se a palacra ja foi chutada escreva caso não escreva _
            if(achou) {
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        chuta(chutes, &tentativas);
    } while (!acertou && !enforcou);
}
*/