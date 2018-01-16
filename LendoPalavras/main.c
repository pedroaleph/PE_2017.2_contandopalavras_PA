#include "ListaD.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 1;
    char Palavras[500],*token;//Palavra[50];
    Lista_Dupla* Lendo = nova_lista();
    FILE* texto = fopen("texto.txt","r");
    while(fgets(Palavras,sizeof(Palavras),texto)!=NULL){
        token = strtok(Palavras," ");
        while( token != NULL ) {
            //sprintf(Palavra,"%s", token );
            insert_end(Lendo,i++,token);
            //printf("%s\n", token );
            token = strtok(NULL, " ");
        }

    }
    fclose(texto);
    print_da_lista(Lendo);
    Liberando_lista(Lendo);
    return 0;
}
