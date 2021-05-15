#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"


int inicializarCliente(eCliente clientes[], int tamcli){
    int retorno = 0;
    if(clientes!=NULL && tamcli>0){
        for(int i=0;i<tamcli;i++){
            clientes[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int buscarLibreCliente(eCliente clientes[], int tamcli){
    int retorno = -1;
    if(clientes!=NULL && tamcli>0){
        for(int i=0;i<tamcli;i++){
            if(clientes[i].isEmpty){
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

int altaCliente(eCliente clientes[], int tamcli, int* idCliente){
    int retorno = 0;
    int indice;
    eCliente nuevoCliente;
    if(clientes!=NULL && tamcli>0 && idCliente!=NULL){
        indice = buscarLibreCliente(clientes, tamcli);
        system("cls");
        printf("======================\n");
        printf("     ALTAS CLIENTES   \n");
        printf("======================\n");
        printf("ID Cliente: %d\n", *idCliente);
        nuevoCliente.codigo = *idCliente;

        getString("Ingrese nombre: ", nuevoCliente.nombre);
        while(strlen(nuevoCliente.nombre)<2 || strlen(nuevoCliente.nombre)>20){
            getString("ERROR: Reingrese nombre: ", nuevoCliente.nombre);
        }

        getString("Ingrese apellido: ", nuevoCliente.apellido);
        while(strlen(nuevoCliente.apellido)<2 || strlen(nuevoCliente.apellido)>20){
            getString("ERROR: Reingrese apellido: ", nuevoCliente.apellido);
        }

        printf("Ingrese sexo m-f: ");
        fflush(stdin);
        scanf("%c", &nuevoCliente.sexo);
        while(nuevoCliente.sexo!='f' && nuevoCliente.sexo!='m'){
            printf("Ingrese sexo m-f: ");
            fflush(stdin);
            scanf("%c", &nuevoCliente.sexo);
        }


        getString("Ingrese telefono: ", nuevoCliente.telefono);
        while(strlen(nuevoCliente.telefono)<2 || strlen(nuevoCliente.telefono)>20){
            getString("ERROR: Reingrese telefono: ", nuevoCliente.telefono);
        }

        nuevoCliente.isEmpty = 0;
        clientes[indice] = nuevoCliente;
        retorno = 1;
        (*idCliente)++;
    }
    if(retorno!=-1){
        printf("\n\nEl alta se realizo con exito.\n\n");
    }
    return retorno;
}

int mostrarClientes(eCliente clientes[], int tamcli){
    int flag = 1;

    printf("===============================================\n");
    printf("               LISTA DE CLIENTES               \n");
    printf("===============================================\n");
    printf("Codigo   Nombre     Apellido  Sexo   Telefono\n");
    if(clientes!=NULL && tamcli>0)
    {
        for(int i=0;i<tamcli;i++)
        {
            if(!clientes[i].isEmpty)
            {
                mostrarCliente(clientes[i]);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay clientes para mostrar.");
        }
    }
    return flag;
}

void mostrarCliente(eCliente unCliente){
    printf("%4d %10s   %10s     %c %10s\n", unCliente.codigo,
                                                    unCliente.nombre,
                                                    unCliente.apellido,
                                                    unCliente.sexo,
                                                    unCliente.telefono);
}

int buscarCliente(eCliente clientes[], int tamcli, int idCliente){
    int indice = -1;
    if(clientes!=NULL && tamcli>0 && idCliente)
    {
        for(int i=0;i<tamcli;i++)
        {
            if(!clientes[i].isEmpty && clientes[i].codigo == idCliente)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaCliente(eCliente clientes[], int tamcli){
    int retorno = 0;
    int indice;
    int idCliente;
    char confirmacion;
    if(clientes!=NULL && tamcli>0){
        system("cls");
        printf("===============================================\n");
        printf("                  BAJAS CLIENTES               \n");
        printf("===============================================\n");
        mostrarClientes(clientes, tamcli);

        printf("\nIngrese ID Cliente: ");
        scanf("%d", &idCliente);

        indice = buscarCliente(clientes, tamcli, idCliente);
        if(indice==-1)
        {
            printf("\nNo existe un cliente con el ID: %d\n", idCliente);
        }
        else
        {
            mostrarCliente(clientes[indice]);
            printf("\nConfirma la baja? s-n: ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);
            while(confirmacion!='s' && confirmacion!='n'){
                printf("\nERROR: Confirma? s-n: ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);
            }
            if(confirmacion == 's')
            {
                clientes[indice].isEmpty = 1;
                retorno = 1;
                printf("\n\nLa baja se realizo con exito.\n\n");
            }
            else
            {
                printf("\nBaja cancelada por el usuario.\n");
            }
        }
    }
    return retorno;
}

char menuModificar(){
    char opcion;

    system("cls");
    printf("==============================================\n");
    printf("               MODIFICAR CLIENTES             \n");
    printf("==============================================\n");
    printf("A- Modificar Nombre\n");
    printf("B- Modificar Apellido\n");
    printf("C- Modificar Telefono\n");
    printf("D- Volver\n");
    printf("\n\nIngrese opcion que desea modificar: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    while(opcion!='A' && opcion!='B' && opcion!='C' && opcion!='D'){
        printf("ERROR: Ingrese una opcion correcta: ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = toupper(opcion);
    }

    return opcion;
}

int modificarClientes(eCliente clientes[], int tamcli){
    int retorno = 0;
    int idBuscar;
    int indice;
    eCliente auxCliente;
    if(clientes!=NULL && tamcli>0){
        system("cls");
        printf("===============================================\n");
        printf("                MODIFICAR CLIENTES             \n");
        printf("===============================================\n");
        mostrarClientes(clientes, tamcli);
        getInt("\nIngrese el ID que desea modificar: ", &idBuscar);
        for(int i=0;i<tamcli;i++){
            if(clientes[i].codigo == idBuscar){
                indice = i;
            }
        }
        auxCliente = clientes[indice];

        do{
            switch(menuModificar()){
                case 'A':
                    getString("Ingrese nuevo nombre: ", auxCliente.nombre);
                    while(strlen(auxCliente.nombre)<2 || strlen(auxCliente.nombre)>20){
                        getString("ERROR: Reingrese nuevo nombre: ", auxCliente.nombre);
                    }
                    break;

                case 'B':
                    getString("Ingrese nuevo apellido: ", auxCliente.apellido);
                    while(strlen(auxCliente.apellido)<2 || strlen(auxCliente.apellido)>20){
                        getString("ERROR: Reingrese nuevo apellido: ", auxCliente.apellido);
                    }
                    break;

                case 'C':
                    getString("Ingrese nuevo telefono: ", auxCliente.telefono);
                    while(strlen(auxCliente.telefono)<2 || strlen(auxCliente.telefono)>20){
                        getString("ERROR: Reingrese nuevo telefono: ", auxCliente.telefono);
                    }
                    break;

                case 'D':
                    break;

                default:
                    printf("Opcion incorrecta.\n");
                    break;
            }

        }while(menuModificar()!= 'D');
        clientes[indice] = auxCliente;
        retorno = 1;
    }
    return retorno;
}

int ordenarClientes(eCliente clientes[], int tamcli){
    int retorno = -1;
    eCliente auxCliente;
    if(clientes!=NULL && tamcli>0){
        for(int i=0;i<tamcli-1;i++){
            for(int j=i+1;j<tamcli;j++){
                if(strcmpi(clientes[i].apellido,clientes[j].apellido)>0){
                    auxCliente = clientes[i];
                    clientes[i] = clientes[j];
                    clientes[j] = auxCliente;
                }
            }
        }
        retorno = 0;
    }
    if(retorno==-1){
        printf("\n\nNo hay clientes para mostrar.\n\n");
    }
    return retorno;
}

int cargarDescripcionCliente(int idCliente, eCliente clientes[], int tamcli, char nombre[]){
    int retorno = 0;
    if(idCliente>6999 && idCliente<7999 && clientes!=NULL && tamcli>0 && nombre!=NULL){
        for(int i=0;i<tamcli;i++){
            if(clientes[i].codigo == idCliente){
                strcpy(nombre, clientes[i].nombre);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
