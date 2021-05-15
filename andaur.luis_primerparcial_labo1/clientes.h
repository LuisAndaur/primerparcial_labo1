#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    int isEmpty;
}eCliente;

#endif // CLIENTES_H_INCLUDED

/** \brief Recorre el array e inicializa la bandera isEmpty en 1
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \return int retorna 1 si tuvo exito y 0 si hubo error
 *
 */
int inicializarCliente(eCliente clientes[], int tamcli);

/** \brief Busca un espacio libre en el array
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \return int Retorna el indice del espacio libre sino -1
 *
 */
int buscarLibreCliente(eCliente clientes[], int tamcli);

/** \brief Se da de alta a los clientes en un espacio vacio
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \param idCliente int*
 * \return int retorna 1 si el alta fue exitosa
 *
 */
int altaCliente(eCliente clientes[], int tamcli, int* idCliente);

/** \brief Muestra todos los clientes cargados
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \return int retorna 1 si hay clientes y o s no los hay cargados
 *
 */
int mostrarClientes(eCliente clientes[], int tamcli);

/** \brief Muestra un solo cliente
 *
 * \param unCliente eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente unCliente);

/** \brief Recibe un id y recorre el array de clientes buscandolo
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \param idCliente int
 * \return int retorna el indice si encuentra el cliente sino -1
 *
 */
int buscarCliente(eCliente clientes[], int tamcli, int idCliente);

/** \brief Menu con las opciones para modificar
 *
 * \return char
 *
 */
char menuModificar();

/** \brief Modifica los campos elegidos por el usuario del cliente
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \return int retorna 1 si hay clientes sino retorna 0
 *
 */
int modificarClientes(eCliente clientes[], int tamcli);

/** \brief Se da de baja al cliente que elije el usuario
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \return int retorna 1 si hay clientes para mostrar sino 0
 *
 */
int bajaCliente(eCliente clientes[], int tamcli);

/** \brief Ordena los clientes
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \return int retorna 1 si hay clientes para mostrar sino 0
 *
 */
int ordenarClientes(eCliente clientes[], int tamcli);

/** \brief Carga el nombre del cliente recibiendo su id
 *
 * \param idCliente int
 * \param clientes[] eCliente
 * \param tamcli int
 * \param nombre[] char
 * \return int int retorna 1 si coincide el id sino 0
 *
 */
int cargarDescripcionCliente(int idCliente, eCliente clientes[], int tamcli, char nombre[]);
