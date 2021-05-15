#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "alquileres.h"

int inicializarAlquileres(eAlquiler alquileres[], int tamalq){
    int retorno = 0;
    if(alquileres!=NULL && tamalq>0){
        for(int i=0;i<tamalq;i++){
            alquileres[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int buscarLibreAlquiler(eAlquiler alquileres[], int tamalq){
    int retorno = -1;
    if(alquileres!=NULL && tamalq>0){
        for(int i=0;i<tamalq;i++){
            if(alquileres[i].isEmpty){
                retorno = i;
                break;
            }
        }
    }
    if(retorno==-1){
        printf("El sistema esta lleno.\n\n");
    }
    return retorno;
}

int altaAlquiler(eAlquiler alquileres[], int tamalq, int* idAlquiler, eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat){
    int retorno = 0;
    int indice;
    eAlquiler nuevoAlquiler;
    if(alquileres!=NULL && tamalq>0 && idAlquiler!=NULL && clientes!=NULL && tamcli>0 && juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0){
        indice = buscarLibreAlquiler(alquileres, tamalq);
        system("cls");
        printf("======================\n");
        printf("    ALTAS ALQUILERES    \n");
        printf("======================\n");
        printf("ID Alquiler: %d\n", *idAlquiler);
        nuevoAlquiler.codigo = *idAlquiler;

        mostrarJuegos(juegos,tamjue,categorias,tamcat);
        getInt("Ingrese ID de juegos: ", &nuevoAlquiler.codigoJuego);
        while(nuevoAlquiler.codigoJuego<1000 || nuevoAlquiler.codigoJuego>1004){
            getInt("ERROR: Reingrese ID de juegos: ", &nuevoAlquiler.codigoJuego);
        }

        mostrarClientes(clientes, tamcli);
        getInt("Ingrese el ID de clientes: ", &nuevoAlquiler.codigoCliente);
        while(nuevoAlquiler.codigoCliente<7000 || nuevoAlquiler.codigoCliente>8000){
            getInt("ERROR: Reingrese el ID de clientes: ", &nuevoAlquiler.codigoCliente);
        }

        printf("Ingrese fecha dd/mm/aaaa: ");
        scanf("%d/%d/%d", &nuevoAlquiler.fecha.dia, &nuevoAlquiler.fecha.mes, &nuevoAlquiler.fecha.anio);
        while( nuevoAlquiler.fecha.dia<0 || nuevoAlquiler.fecha.dia>31 || nuevoAlquiler.fecha.mes<1 || nuevoAlquiler.fecha.mes>12 || nuevoAlquiler.fecha.anio<1970 )
        {
            printf("ERROR: Reingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoAlquiler.fecha.dia, &nuevoAlquiler.fecha.mes, &nuevoAlquiler.fecha.anio);
        }

        nuevoAlquiler.isEmpty = 0;
        alquileres[indice] = nuevoAlquiler;
        retorno = 1;
        (*idAlquiler)++;
    }
    if(retorno!=-1){
        printf("\n\nEl alta se realizo con exito.\n\n");
    }
    return retorno;
}

int mostrarAlquileres(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat){
    int flag = 1;

    printf("====================================================================\n");
    printf("                         LISTA DE ALQUILERES                         \n");
    printf("====================================================================\n");
    printf("ID         Juego      Nombre         Fecha\n");
    if(alquileres!=NULL && tamalq>0  && clientes!=NULL && tamcli>0 && juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0){
        for(int i=0;i<tamalq;i++){
            if(!alquileres[i].isEmpty){
                mostrarAlquiler(alquileres[i],tamalq,clientes,tamcli,juegos,tamjue,categorias,tamcat);
                flag = 0;
            }
        }
        if(flag){
            printf("No hay clientes para mostrar.");
        }
    }
    return flag;
}

void mostrarAlquiler(eAlquiler unAlquiler, int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat){
    char descripcionJuego[20];
    char nombre[20];
    if(cargarDescripcionCliente(unAlquiler.codigoCliente ,clientes,tamcli,nombre) &&  cargarDescripcionJuego(unAlquiler.codigoJuego,juegos,tamjue, descripcionJuego)){
        printf("%4d  %10s   %10s   %02d/%02d/%d\n", unAlquiler.codigo,
                                                    descripcionJuego,
                                                    nombre,
                                                    unAlquiler.fecha.dia,
                                                    unAlquiler.fecha.mes,
                                                    unAlquiler.fecha.anio);
    }
    else{
       printf("Hubo un problema con las descripciones\n");
    }

}
