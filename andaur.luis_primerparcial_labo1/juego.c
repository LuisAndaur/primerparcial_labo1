#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juego.h"


int mostrarJuegos(eJuego juegos[], int tamjue,eCategoria categorias[], int tamcat){
    int retorno = -1;
    if(juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0){
        printf("==============================\n");
        printf("         LISTA DE JUEGOS      \n");
        printf("==============================\n");
        printf("ID      Descripcion     Importe   \n");
        for(int i=0;i<tamjue;i++){
            mostrarJuego(juegos[i], categorias, tamcat);
        }
        printf("\n");
        retorno = 0;
    }
    return retorno;
}

void mostrarJuego(eJuego unJuego, eCategoria categorias[], int tamcat){
        printf("%4d    %10s     %.2f  \n", unJuego.codigo, unJuego.descripcion, unJuego.importe);
}

int cargarDescripcionJuego(int idJuego, eJuego juegos[], int tamjue, char descripcion[]){
    int retorno = 0;
    if(idJuego>999 && idJuego<1005 && juegos!=NULL && tamjue>0 && descripcion!=NULL){
        for(int i=0;i<tamjue;i++){
            if(juegos[i].codigo == idJuego){
                strcpy(descripcion, juegos[i].descripcion);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
