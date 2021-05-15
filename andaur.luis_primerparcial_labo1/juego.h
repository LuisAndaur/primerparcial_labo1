#include "categoria.h"

#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct{
    int codigo;
    char descripcion[21];
    float importe;
    int idCategoria;
}eJuego;

#endif // JUEGO_H_INCLUDED

/** \brief Muestra los juegos
 *
 * \param juegos[] eJuego
 * \param tamjue int
 * \param categorias[] eCategoria
 * \param tamcat int
 * \return int int retorna 1 si hay juegos para mostrar sino 0
 *
 */
int mostrarJuegos(eJuego juegos[], int tamjue,eCategoria categorias[], int tamcat);

/** \brief Muestra un solo juego
 *
 * \param unJuego eJuego
 * \param categorias[] eCategoria
 * \param tamcat int
 * \return void
 *
 */
void mostrarJuego(eJuego unJuego, eCategoria categorias[], int tamcat);

/** \brief Carga la descripcion del nombre del juego recibiendo su id
 *
 * \param idJuego int
 * \param juegos[] eJuego
 * \param tamjue int
 * \param descripcion[] char
 * \return int int retorna 1 si hay juegos para mostrar sino 0
 *
 */
int cargarDescripcionJuego(int idJuego, eJuego juegos[], int tamjue, char descripcion[]);
