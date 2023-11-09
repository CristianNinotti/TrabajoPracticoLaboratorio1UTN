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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente
{
    int nroCuenta;
    char contrasenia[10];
    char nombre[20];
    float saldo;
    int estado;
};

struct Cliente listaClientes[10];
void cargarClientes();

void ingresoCapital(int nroCliente);                     // Prototipo funcion para ingresar dinero
void extraccionCapital(int nroCliente);                  // Prototipo funcion para retirar dinero
void transferenciaEntreCuentas(int nroCliente); // Prototipo funcion para transferencia

// Global
int operacionesMaximas;

void main()
{

    int opcion, nroCuenta, ENCENDIDO, i, banderaIngreso, nroCliente, banderaContrasenia,
        contadorIntentos;
    char contrasenia[10];
    float capital, saldo, operacion, saldoAntesDeMovimiento, saldoDespuesDeMovimiento;
    float resumen[20];
    ENCENDIDO = 0;

    cargarClientes();
    do
    {
        printf("==========================================\n");
        printf("BIENVENIDO A BANCOS Zucco&Asociados S.A \n");
        printf("==========================================\n");

        // PETICION DE CUENTA:
        banderaIngreso = 0;
        i = 0;
        operacionesMaximas = 0;

        do
        {
            do
            {
                printf("Ingrese su n%cmero de cuenta:\n", 163);
                scanf("%d", &nroCuenta);

                if (nroCuenta < 1 || nroCuenta > 10)
                {
                    printf("Ingrese un numero de cuenta entre 1 y 10 \n");
                }

            } while (nroCuenta < 1 || nroCuenta > 10);
            while (i < 10)
            {

                if (listaClientes[i].nroCuenta == nroCuenta)
                {
                    nroCliente = i;
                    i = 10;
                    banderaIngreso = 1;
                }

                i++;
            }
            if (banderaIngreso == 0)
            {
                printf("N%cmero de cuenta incorrecto, intente nuevamente.\n", 163);
            }

        } while (banderaIngreso == 0);

        // PETICIÓN DE CONTRASEÑA:
        contadorIntentos = 3;
        if (listaClientes[nroCliente].estado != 0)
        {

            do
            {
                printf("Ingrese su contrase%ca:\n", 164);
                scanf("%s", &contrasenia);

                if (strcmp(listaClientes[nroCliente].contrasenia, contrasenia) != 0)
                {
                    printf("Contrase%ca incorrecta, intente nuevamente.\n", 164);
                    contadorIntentos--;
                    printf("N%cmero de intentos restantes: %d\n", 163, contadorIntentos);
                }

            } while (strcmp(listaClientes[nroCliente].contrasenia, contrasenia) != 0 && contadorIntentos > 0);

            if (contadorIntentos == 0)
            {
                listaClientes[nroCliente].estado = 0;
            }
        }

        // INGRESO AL PROGRAMA
        if (contadorIntentos != 0 && listaClientes[nroCliente].estado != 0)
        {
            do
            {

                do
                {
                    printf("1. Realizar un Dep%csito.\n", 162);
                    printf("2. Realizar una Extracci%cn.\n", 162);
                    printf("3. Consultar el Saldo de la Cuenta.\n");
                    printf("4. Realizar una Transferencia entre Cuentas.\n");
                    printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual.\n");
                    printf("6. Salir de la Sesi%cn.\n", 162);
                    scanf("%d", &opcion);

                    if (opcion < 1 || opcion > 6)
                    {
                        printf("Opcion ingresada incorrecta, intente nuevamente.\n");
                    }
                    // PARA CONTROLAR LA CANTIDAD DE OPERACIONES
                    if (opcion == 1 || opcion == 2 || opcion == 3)
                    {
                        operacionesMaximas += 1;
                    }

                    switch (opcion)
                    {
                    case 1:

                        ingresoCapital(nroCliente);

                        break;

                    case 2:

                        extraccionCapital(nroCliente);

                        break;

                    case 3:
                        printf("===========================\n");
                        printf("Su saldo es:  $%.2f \n", listaClientes[nroCliente].saldo);
                        printf("===========================\n");
                        break;

                    case 4:
                        void transferenciaEntreCuentas(int nroCliente); // Operando
                        break;

                    case 5:
                        printf("===========================\n");
                        printf("Cantidad Operaciones %d \n", operacionesMaximas);
                        printf("===========================\n");
                        printf("Su saldo es:  $%.2f \n", listaClientes[nroCliente].saldo);
                        printf("===========================\n");

                        break;

                    case 6:
                        printf("Cerrando sesion..\n");
                        operacionesMaximas = 0;
                        break;
                    }

                } while (opcion < 1 || opcion > 6);
                if (operacionesMaximas == 10)
                {
                    printf("L%cmite de operaciones alcanzado. Reingrese..\n", 161);
                }
            } while (opcion != 6 && operacionesMaximas < 10);

            printf("Cerrando sesion..\n");
            printf("Gracias por utilizar nuestro servicio, Zuco&Asociados S.A Vuelva pronto \n");
        }
        else if (contadorIntentos == 0) // BLOQUEO DE CUENTA
        {
            listaClientes[nroCliente].estado = 0;
            printf("Cantidad de intentos m%cximos alcanzado, su cuenta ha sido bloqueada.\n", 160);
            printf("Gracias por utilizar nuestros servicios!\n");
        }
        else if (listaClientes[nroCliente].estado == 0) // AVISO DE CUENTA BLOQUEADA
        {
            printf("Su cuenta se encuentra bloqueada, comun%cquese con el banco ~.\n", 161);
            printf("Gracias por utilizar nuestros servicios!\n");
        }

    } while (ENCENDIDO == 0);

    system("pause");
}

void cargarClientes()
{
    // CLIENTE 1:
    listaClientes[0].nroCuenta = 1;
    strcpy(listaClientes[0].contrasenia, "123456");
    strcpy(listaClientes[0].nombre, "Juan Pérez");
    listaClientes[0].saldo = 45000;
    listaClientes[0].estado = 1;

    // CLIENTE 2:

    listaClientes[1].nroCuenta = 2;
    strcpy(listaClientes[1].contrasenia, "123456");
    strcpy(listaClientes[1].nombre, "Carlos Rodriguez");
    listaClientes[1].saldo = 100000;
    listaClientes[1].estado = 1;

    // CLIENTE 3:

    listaClientes[2].nroCuenta = 3;
    strcpy(listaClientes[2].contrasenia, "123456");
    strcpy(listaClientes[2].nombre, "Franco Pérez");
    listaClientes[2].saldo = 150000;
    listaClientes[2].estado = 0;

    // CLIENTE 4:

    listaClientes[3].nroCuenta = 4;
    strcpy(listaClientes[3].contrasenia, "123456");
    strcpy(listaClientes[3].nombre, "Ana García");
    listaClientes[3].saldo = 200000;
    listaClientes[3].estado = 1;

    // CLIENTE 5:

    listaClientes[4].nroCuenta = 5;
    strcpy(listaClientes[4].contrasenia, "123456");
    strcpy(listaClientes[4].nombre, "Clara Díaz");
    listaClientes[4].saldo = 300000;
    listaClientes[4].estado = 0;

    // CLIENTE 6:

    listaClientes[5].nroCuenta = 6;
    strcpy(listaClientes[5].contrasenia, "1234567");
    strcpy(listaClientes[5].nombre, "Gastón López");
    listaClientes[5].saldo = 400000;
    listaClientes[5].estado = 0;

    // CLIENTE 7:

    listaClientes[6].nroCuenta = 7;
    strcpy(listaClientes[6].contrasenia, "1234567");
    strcpy(listaClientes[6].nombre, "María Romero");
    listaClientes[6].saldo = 500000;
    listaClientes[6].estado = 1;

    // CLIENTE 8:

    listaClientes[7].nroCuenta = 8;
    strcpy(listaClientes[7].contrasenia, "1234567");
    strcpy(listaClientes[7].nombre, "Andrés Sosa");
    listaClientes[7].saldo = 1000000;
    listaClientes[7].estado = 0;

    // CLIENTE 9:

    listaClientes[8].nroCuenta = 9;
    strcpy(listaClientes[8].contrasenia, "1234567");
    strcpy(listaClientes[8].nombre, "Diego Torres");
    listaClientes[8].saldo = 1000000;
    listaClientes[8].estado = 1;

    // CLIENTE 10:

    listaClientes[9].nroCuenta = 10;
    strcpy(listaClientes[9].contrasenia, "1234567");
    strcpy(listaClientes[9].nombre, "Ana Acosta");
    listaClientes[9].saldo = 2000000;
    listaClientes[9].estado = 0;
}

void ingresoCapital(int nroCliente) // ingresoCapital(float ingreso, float dinero) A Borrar
{
    float ingreso;
    printf("Ingrese el valor a ingresar en su cuenta Bancaria \n");
    scanf("%f", &ingreso);
    while (ingreso <= 0)
    {
        printf("El monto a ingresar en su cuenta debe ser positivo \n");
        printf("Reingrese el monto a depositar \n");
        scanf("%f", &ingreso);
    }
    listaClientes[nroCliente].saldo += ingreso;
    printf("Su saldo actual es: $%.2f \n", listaClientes[nroCliente].saldo);
}

void extraccionCapital(int nroCliente)

{
    float retiro;
    printf("Ingrese el valor a retirar en su cuenta Bancaria \n");
    scanf("%f", &retiro);
    while (retiro > listaClientes[nroCliente].saldo || retiro <= 0)
    {
        printf("El monto a retirar en su cuenta no debe superar su saldo total o debe ser positivo \n");
        printf("Reingrese el monto a extraer \n");
        scanf("%f", &retiro);
    }
    listaClientes[nroCliente].saldo -= retiro;

    printf("Su saldo actual es: $%.2f \n", listaClientes[nroCliente].saldo);
}

void transferenciaEntreCuentas(int nroCliente)
{
    int nroCuentaATransferir;

    do
    {
    printf("Ingrese el n%cmero cuenta a la que desea transferir \n", 163);
    scanf("%d", &nroCuentaATransferir);
    if (nroCuentaATransferir == listaClientes[nroCliente].nroCuenta)
    {
        printf("No te puedes autotransferir dinero, cuenta origin y destino iguales \n");
    }
    

    } while (nroCuentaATransferir == listaClientes[nroCliente].nroCuenta);
    
}