#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eCategoria;


#endif // CATEGORIA_H_INCLUDED


/** \brief Muestra las categorias
 *
 * \param categorias[] eCategoria
 * \param tamcat int
 * \return int int retorna 1 si hay categorias para mostrar sino 0
 *
 */
int mostrarCategorias(eCategoria categorias[], int tamcat);

/** \brief Carga la descripcion de la categoria recibiendo su id
 *
 * \param idCategoria int
 * \param categorias[] eCategoria
 * \param tamcat int
 * \param descripcion[] char
 * \return int int retorna 1 si hay categorias cargadas sino 0
 *
 */
int cargarDescripcionCategoria(int idCategoria, eCategoria categorias[], int tamcat, char descripcion[]);

/** \brief Muestra una sola categoria
 *
 * \param unaCategoria eCategoria
 * \return void
 *
 */
void mostrarCategoria(eCategoria unaCategoria);
