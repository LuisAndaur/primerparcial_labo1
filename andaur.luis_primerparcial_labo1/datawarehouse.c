#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

#define TAMJUE 5
#define TAMCAT 5

#define TAMCLI 30
#define TAMALQ 30


//juegos
int idJuego[TAMJUE] = {1000,1001,1002,1003,1004};
char descripcionJuego[TAMJUE][21] = {"Damas","Cartas","Ajedrez","Metegol","MagicPRO"};
float precio[TAMJUE] = {250,300,400,350,150};

int hardcodearJuego(eJuego juegos[], int tamjue){
    int retorno = -1;
    if(juegos!=NULL && tamjue>0){
        for(int i=0;i<tamjue;i++){
            juegos[i].codigo = idJuego[i];
            strcpy(juegos[i].descripcion,descripcionJuego[i]);
            juegos[i].importe = precio[i];
        }
        retorno = 0;
    }
    return retorno;
}

//categoria
int idCategoria[TAMCAT] = {5000,5001,5002,5003,5004};
char descripcionCategoria[TAMCAT][21] = {"Mesa","Azar","Estrategia", "Salon", "Magia"};

int hardcodearCategoria(eCategoria categorias[], int tamcat){
    int retorno = -1;
    if(categorias!=NULL && tamcat>0){
        for(int i=0;i<tamcat;i++){
            categorias[i].id = idCategoria[i];
            strcpy(categorias[i].descripcion,descripcionCategoria[i]);
        }
        retorno = 0;
    }
    return retorno;
}
