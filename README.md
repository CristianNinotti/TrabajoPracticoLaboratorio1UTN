# TrabajoPracticoLaboratorio1UTN


/* LC1 – Trabajo Práctico Integrador
Cajero automático
El siguiente enunciado deberá ser resuelto en grupo de entre 3 y 4 integrantes. Luego de su
entrega y corrección por parte de los docentes, se acordará una fecha para la defensa
individual del mismo.
Simulación de Funcionamiento del Cajero Automático
Debemos desarrollar un programa de simulación del funcionamiento de un cajero
automático de un banco.
/////////////////////////
Datos de los Clientes
El banco tiene 10 clientes. Los datos de los mismos son:
Número de cuenta: Un número entero entre 100 y 999.
Contraseña: La contraseña de acceso del cliente.
Nombre: El nombre del cliente.
Saldo: El saldo en la cuenta del cliente.
Estado: Activo o Bloqueado.
Funcionalidades del Cajero Automático
El programa permitirá que un cliente inicie sesión, realice operaciones de depósito,
extracción y consulta de saldo, y finalice sesión, quedando el cajero disponible para la
consulta de otro cliente.
//////////////////////
Las acciones que podrá realizar un cliente que ha iniciado sesión son las siguientes:
1. Realizar un Depósito.
2. Realizar una Extracción.
3. Consultar el Saldo de la Cuenta.
4. Realizar una Transferencia entre Cuentas.
5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual.
6. Salir de la Sesión.
//////////////////////
Inicio de Sesión
Para iniciar sesión, el cliente deberá ingresar su número de cuenta y su contraseña. Si
ambos datos son correctos y el estado del cliente es "Activo," se mostrará el menú con las
opciones detalladas. Si alguno de los datos es incorrecto, se mostrará "Número de cuenta o
contraseña incorrecta." Si el cliente está bloqueado, se mostrará "Su cuenta está
bloqueada; comuníquese con la entidad bancaria."
Bloqueo de Cuenta
El programa permite tres intentos fallidos de inicio de sesión. Se considera un intento
cuando el usuario ingresa su número de cuenta correctamente pero su contraseña de
manera incorrecta. En el tercer intento, se muestra "No se permiten más intentos. Su cuenta
ha sido bloqueada; comuníquese con la entidad bancaria."
//////////////////////////////
Operaciones de Depósito y Extracción

Las operaciones de depósito y extracción modifican el saldo del cliente. Se valida que el
monto de extracción no supere el saldo, mostrando un mensaje informativo en caso
contrario.
Límite de Operaciones

No se permitirá más de 10 movimientos de depósito, extracción o consulta de saldo. Al
llegar al límite, el sistema muestra "Ha alcanzado el límite de operaciones. Gracias." Para
continuar, el cliente debe iniciar sesión nuevamente.
Consideraciones

La resolución deberá contemplar el uso de buenas prácticas de programación. La aplicación
de arreglos y funciones, así como el uso correcto de estructuras.
El archivo a entregar debe contener en su interior a modo de comentario a los integrantes
del TPI. Sólo hará entrega del TPI un solo integrante del grupo.*/



/// Realizado por: Nahuel Gonzalez, Ninotti Cristian, Francisco Poli Veliz, Juan Ignacio Zucco ///
/// Horas trabajadas: 20 Horas ///
