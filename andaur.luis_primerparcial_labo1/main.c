#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "categoria.h"
#include "juego.h"
#include "alquileres.h"
#include "datawarehouse.h"

#define TAMJUE 4
#define TAMCAT 5

#define TAMCLI 100
#define TAMALQ 100

char menu();

int main()
{
    eJuego juegos[TAMJUE];
    eCategoria categorias[TAMCAT];

    eCliente clientes[TAMCLI];
    eAlquiler alquileres[TAMALQ];

    char respuesta = 'n';
    int idClientes = 7000;
    int idAlquileres = 4000;
    int cantidadClientes = 0;
    int cantidadAlquileres = 0;

    inicializarCliente(clientes, TAMCLI);
    inicializarAlquileres(alquileres, TAMALQ);

    hardcodearJuego(juegos,TAMJUE);
    hardcodearCategoria(categorias,TAMCAT);


    do{
        switch(menu()){
            case 'A':
                //ALTA CLIENTES
                if(cantidadClientes<TAMCLI){
                    altaCliente(clientes, TAMCLI,&idClientes);
                    cantidadClientes++;
                }
                else{
                    printf("\nEl sistema esta completo.\n");
                }
                break;

            case 'B':
                //MODIFICAR CLIENTES
                if(cantidadClientes>0){
                    modificarClientes(clientes, TAMCLI);
                    cantidadClientes--;
                }
                else{
                    printf("\nNo hay clientes en el sistema para modificar.\n");
                }
                break;

            case 'C':
                //BAJA CLIENTES
                if(cantidadClientes>0){
                   bajaCliente(clientes, TAMCLI);
                }
                else{
                    printf("No hay clientes en el sistema.\n\n");
                }
                break;

            case 'D':
                //LISTAR CLIENTES
                if(cantidadClientes>0){
                    system("cls");
                    ordenarClientes(clientes, TAMCLI);
                    mostrarClientes(clientes, TAMCLI);
                }
                else{
                    printf("No hay clientes en el sistema.\n\n");
                }
                break;

            case 'E':
                //ALTA alquileres
                if(cantidadAlquileres<TAMALQ){
                    altaAlquiler(alquileres, TAMALQ,&idAlquileres,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT);
                    cantidadAlquileres++;
                }
                else{
                    printf("\nEl sistema esta completo.\n");
                }
                break;

            case 'F':
                //ALTA alquileres
                if(cantidadAlquileres<TAMALQ){
                    mostrarAlquileres(alquileres, TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT);
                    cantidadAlquileres++;
                }
                else{
                    printf("\nEl sistema esta completo.\n");
                }
                break;

            case 'G':
                printf("Seguro desea salir? s-n: ");
                fflush(stdin);
                scanf("%c", &respuesta);
                respuesta = tolower(respuesta);
                while(respuesta!='s' && respuesta!='n'){
                    printf("ERROR: Ingrese s-n: ");
                    fflush(stdin);
                    scanf("%c", &respuesta);
                    respuesta = tolower(respuesta);
                }
                break;

            default:
                printf("La opcion ingresada es incorrecta.\n");
                break;
        }
    system("pause");
    }while(respuesta == 'n');

    return 0;
}

char menu(){
    char opcion;

    system("cls");
    printf("|| CLIENTES ||\n\n");
    printf("A- ALTA clientes\n");
    printf("B- MODIFICAR clientes\n");
    printf("C- BAJA clientes\n");
    printf("D- LISTAR Clientes\n");
    printf("E- ALTA Alquileres\n");
    printf("F- LISTAR Alquileres\n");
    printf("G- SALIR\n");
    printf("\n\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    while(opcion!='A' && opcion!='B' && opcion!='C' && opcion!='D' && opcion!='E' && opcion!='F' && opcion!='G'){
        printf("ERROR: Ingrese una opcion correcta: ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = toupper(opcion);
    }
    return opcion;
}
