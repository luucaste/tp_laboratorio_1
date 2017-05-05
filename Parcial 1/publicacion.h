typedef struct {

    int id;
    char nombreProducto[50];
    float precio;
    int stock;
    int estado;
    int idusuario;

}Eproducto;


/** \brief Busca el primer espacio libre en el array de publicacion
 *
 * \param Array de publicacion
 * \param Tamaño del array
 * \return El indice del primer espacio libre
 *
 */
int buscarLibrePublicacion(Eproducto[], int);

/** \brief Habilita en sistema una nueva publicacion
 *
 * \param Array de productos
 * \param Array de usuarios
 * \param Tamaño del array
 * \param ID del producto
 * \return El indice de la publicacion
 *
 */
int nuevaPublicacion(Eproducto[], Eusuario[], int, int);


/** \brief Muestra las publicaciones realizadas en sistema
 *
 * \param Array de publicaciones
 * \param Tamaño del array
 *
 */
void mostrarPublicaciones (Eproducto[], int);


/** \brief Busca una publicacion por su ID
 *
 * \param Array de publicacion
 * \param Tamaño del array
 * \param ID de producto
 * \return El indice de la publicacion
 *
 */
int buscarPublicacion(Eproducto[], int, int);


/** \brief Modifica datos seleccionados de la publicacion
 *
 * \param Array de publicacion
 * \param Id de producto
 * \param Tamaño del array
 *
 */
void modificarPublicacion (Eproducto[], int, int);


/** \brief Realiza la compra de un producto
 *
 * \param Array de productos
 * \param Tamaño del array
 *
 */
void comprarProducto(Eproducto[], int);


/** \brief Realiza la cancelacion de una publicacion
 *
 * \param Array de productos
 * \param Tamaño del array
 *
 */
void CancelarPublicacion (Eproducto[], int);
