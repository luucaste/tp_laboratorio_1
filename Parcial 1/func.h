typedef struct {

    int id;
    char usuario[50];
    char password[50];
    int estado;
    float calificacion;

}Eusuario;


/** \brief Menu de opciones
 *
 *  \return opcion elegida
 *
 */
int menu();


/** \brief Inicializa los usuarios con estado en 0
 *
 * \param Array de usuarios
 * \param Tamaño del array
 *
 */
void inicializarUsuarios(Eusuario[], int);


/** \brief Busca el primer espacio libre en el array de usuarios
 *
 * \param Array de usuarios
 * \param Tamaño del array
 * \return El indice del primer espacio libre
 *
 */
int buscarLibre (Eusuario[], int);


/** \brief Busca el id deseado por el usuario
 *
 * \param Array de usuario
 * \param Tamaño del array
 * \param id a buscar
 * \return El indice del primer espacio libre
 *
 */
int buscarUsuario(Eusuario[], int, int);


/** \brief Da de alta un usuario
 *
 * \param Array de usuario
 * \param Id del usuario
 * \param Tamaño del array
 * \return El usuario
 *
 */
int altaUsuario (Eusuario[], int, int);


/** \brief Muestra los usuarios habilitados en sistema
 *
 * \param Array de usuarios
 * \param Tamaño del array
 *
 */
void mostrarUsuario (Eusuario[], int);


/** \brief Modifica datos seleccionados del usuario
 *
 * \param Array de usuario
 * \param Id del usuario
 * \param Tamaño del array
 *
 */
void modificarUsuario(Eusuario[], int, int);


/** \brief Realiza la baja lógica de un usuario en sistema. (estado=2)
 *
 * \param Array de usuario
 * \param ID del usuario
 * \param Tamaño del array
 *
 */
void bajaUsuario(Eusuario[], int, int);




