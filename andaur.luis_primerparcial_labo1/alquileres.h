#include "fecha.h"
#include "juego.h"
#include "clientes.h"
#include "categoria.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct{
    int codigo;
    int codigoJuego;
    int codigoCliente;
    int isEmpty;
    eFecha fecha;
}eAlquiler;

#endif // ALQUILERES_H_INCLUDED

/** \brief Recorre el array e inicializa la bandera isEmpty en 1
 *
 * \param alquileres[] eAlquiler
 * \param tamalq int
 * \return int retorna 1 si tuvo exito y 0 si hubo error
 *
 */
int inicializarAlquileres(eAlquiler alquileres[], int tamalq);

/** \brief Busca un espacio libre en el array
 *
 * \param alquileres[] eAlquiler
 * \param tamalq int
 * \return int Retorna el indice del espacio libre sino -1
 *
 */
int buscarLibreAlquiler(eAlquiler alquileres[], int tamalq);

/** \brief Da de alta un alquiler
 *
 * \param alquileres[] eAlquiler array alquiler
 * \param tamalq int tamaño del array alquiler
 * \param idAlquiler int* puntero de id alquiler
 * \param clientes[] eCliente array cliente
 * \param tamcli int tamaño del array cliente
 * \param juegos[] eJuego array juego
 * \param tamjue int tamaño del array juego
 * \param categorias[] eCategoria array categoria
 * \param tamcat int tamaño del array categoria
 * \return int retorna 1 si el alta fue exitosa o 0 si no lo fue
 *
 */
int altaAlquiler(eAlquiler alquileres[], int tamalq, int* idAlquiler, eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat);

/** \brief Recorre y muestra los alquileres que estan cargados
 *
 * \param alquileres[] eAlquiler
 * \param tamalq int
 * \param clientes[] eCliente
 * \param tamcli int
 * \param juegos[] eJuego
 * \param tamjue int
 * \param categorias[] eCategoria
 * \param tamcat int
 * \return int retorna 1 si hay alquileres cargados sino 0
 *
 */
int mostrarAlquileres(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat);

/** \brief Muestra un solo alquiler
 *
 * \param unAlquiler eAlquiler
 * \param tamalq int
 * \param clientes[] eCliente
 * \param tamcli int
 * \param juegos[] eJuego
 * \param tamjue int
 * \param categorias[] eCategoria
 * \param tamcat int
 * \return void
 *
 */
void mostrarAlquiler(eAlquiler unAlquiler, int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat);
