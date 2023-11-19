// TRABAJO PRÁCTICO INTEGRADOR - 1TUP10 - Laboratorio de Programación 1
// - Gonzalez, Nahuel Matias
// - Ninotti, Cristian Elio
// - Poli Veliz, Francisco Alberto
// - Zucco, Juan Ignacio

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DECLARACIÓN DEL STRUCT DE CLIENTE
struct Cliente                                 // Coleccion de variables de distintos tipos  // bajo el mismo nombre, clientes en este caso
{
    int nroCuenta;
    char contrasenia[10];
    char nombre[20];
    float saldo;
    int estado;
};

// DECLARACIÓN DE ARRAY DE CLIENTES
struct Cliente listaClientes[10];

// PROTOTIPOS DE FUNCIONES UTILIZADAS
void cargarClientes();
void ingresoCapital(int nroCliente);
void extraccionCapital(int nroCliente);
void realizarTransferencia(int nroCliente);

// VARIABLES GLOBALES
int operacionesMaximas;
int cuentasClientesMaximos = 10;

// INICIO DE PROGRAMA
void main()
{

    // DECLARACIÓN DE VARIABLES LOCALES
    int opcion, nroCuenta, ENCENDIDO, i, banderaIngreso, nroCliente, banderaContrasenia, contadorIntentos;
    float capital, saldo, operacion, saldoAntesDeMovimiento, saldoDespuesDeMovimiento;
    float resumen[20];
    char contrasenia[10];
    ENCENDIDO = 0;

    cargarClientes(); // INVOCACIÓN, DESARROLLO EN LÍNEA 222

    do
    {
        printf("\n");
        printf("==========================================\n");
        printf("BIENVENIDO A BANCOS UTN\n");
        printf("==========================================\n");

        // PETICIÓN DE CUENTA:
        banderaIngreso = 0;
        i = 0;
        operacionesMaximas = 0;

        do
        {
            do
            {
                printf("Ingrese su n%cmero de cuenta:\n", 163);
                scanf("%d", &nroCuenta);

                if (nroCuenta < 1 || nroCuenta > cuentasClientesMaximos)
                {
                    printf("\n");
                    printf("Ingrese un n%cmero de cuenta entre 1 y %d \n", 163, cuentasClientesMaximos);
                    printf("\n");
                }

            } while (nroCuenta < 1 || nroCuenta > cuentasClientesMaximos);

            while (i < cuentasClientesMaximos)
            {

                if (listaClientes[i].nroCuenta == nroCuenta)
                {
                    nroCliente = i;
                    i = cuentasClientesMaximos;
                    banderaIngreso = 1;
                }

                i++;
            }

        } while (banderaIngreso == 0);

        // PETICIÓN DE CONTRASEÑA:
        contadorIntentos = 3;
        do
        {
            printf("\n");
            printf("Ingrese su contrase%ca:\n", 164);
            scanf("%s", &contrasenia);

            if (strcmp(listaClientes[nroCliente].contrasenia, contrasenia) != 0)  // Si devuelve 0 esta ok, si devuelve otro numero es incorrecto
            {
                contadorIntentos--;
                if (contadorIntentos != 0)
                {
                    printf("\n");
                    printf("Contrase%ca incorrecta, intente nuevamente.\n", 164);
                    printf("N%cmero de intentos restantes: %d\n", 163, contadorIntentos);
                }
            }

        } while (strcmp(listaClientes[nroCliente].contrasenia, contrasenia) != 0 && contadorIntentos > 0);  //Repite siempre que sean distintas y tenga intentos en el contador

        if (contadorIntentos == 0)                  // Si es 0 te bloquea la cuenta
        {
            listaClientes[nroCliente].estado = 0;   // Si es 0 te bloquea la cuenta
        }

        // INGRESO AL PROGRAMA
        if (contadorIntentos != 0 && listaClientes[nroCliente].estado != 0)
        {
            do
            {
                do
                {
                    printf("\n");
                    printf("1. Realizar un Dep%csito.\n", 162);
                    printf("2. Realizar una Extracci%cn.\n", 162);
                    printf("3. Consultar el Saldo de la Cuenta.\n");
                    printf("4. Realizar una Transferencia entre Cuentas.\n");
                    printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual.\n");
                    printf("6. Salir de la Sesi%cn.\n", 162);
                    scanf("%d", &opcion);

                    if (opcion < 1 || opcion > 6)
                    {
                        printf("Opci%cn ingresada incorrecta, intente nuevamente.\n", 162);
                    }

                    // PARA CONTROLAR LA CANTIDAD DE OPERACIONES PERMITIDAS
                    if (opcion == 1 || opcion == 2 || opcion == 3)
                    {
                        operacionesMaximas++;
                    }

                    // SWITCH CASE DE MANEJO DE OPCIONES DEL MENÚ PRINCIPAL
                    switch (opcion)
                    {
                    case 1:

                        ingresoCapital(nroCliente); // INVOCACIÓN, DESARROLLO EN LÍNEA 306
                        break;

                    case 2:

                        extraccionCapital(nroCliente); // INVOCACIÓN, DESARROLLO EN LÍNEA 327
                        break;

                    case 3:

                        printf("\n");
                        printf("===========================\n");
                        printf("Su saldo es:  $%.2f \n", listaClientes[nroCliente].saldo);
                        printf("===========================\n");
                        break;

                    case 4:

                        realizarTransferencia(nroCliente); // INVOCACIÓN, DESARROLLO EN LÍNEA 349
                        break;

                    case 5:

                        printf("\n");
                        printf("===========================\n");
                        printf("Cantidad Operaciones: %d \n", operacionesMaximas);
                        printf("===========================\n");
                        printf("Su saldo es:  $%.2f \n", listaClientes[nroCliente].saldo);
                        printf("===========================\n");
                        break;

                    case 6:

                        printf("\n");
                        printf("Cerrando sesi%cn..\n", 162);
                        operacionesMaximas = 0;
                        break;
                    }

                } while (opcion < 1 || opcion > 6);

                if (operacionesMaximas == 10)
                {
                    printf("\n");
                    printf("L%cmite de operaciones alcanzado. Reingrese..\n", 161);
                }

            } while (opcion != 6 && operacionesMaximas < 10);

            printf("\n");
            printf("Cerrando sesi%cn..\n", 162);
            printf("Gracias por utilizar nuestros servicios, vuelva pronto.\n");
        }
        else if (contadorIntentos == 0) // BLOQUEO DE CUENTA
        {
            listaClientes[nroCliente].estado = 0;
            printf("\n");
            printf("Cantidad de intentos m%cximos alcanzado, su cuenta ha sido bloqueada.\n", 160);
            printf("Gracias por utilizar nuestros servicios!\n");
            printf("\n");
        }
        else if (listaClientes[nroCliente].estado == 0) // AVISO DE CUENTA BLOQUEADA
        {
            printf("\n");
            printf("Su cuenta se encuentra bloqueada, comun%cquese con el banco ~.\n", 161);
            printf("Gracias por utilizar nuestros servicios!\n");
            printf("\n");
        }

    } while (ENCENDIDO == 0);

    system("pause");
}

// CARGA DE DATOS DE CADA CLIENTE
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

// FUNCIÓN PARA INGRESO DE CAPITAL
void ingresoCapital(int nroCliente)
{
    float ingreso;
    printf("\n");
    printf("Ingrese el monto que desea depositar en su cuenta:\n");
    scanf("%f", &ingreso);
    while (ingreso <= 0)
    {
        printf("\n");
        printf("El monto a ingresar en su cuenta debe ser positivo.\n");
        printf("Reingrese el monto a depositar:\n");
        scanf("%f", &ingreso);
    }
    listaClientes[nroCliente].saldo += ingreso;
    printf("\n");
    printf("===========================\n");
    printf("Su saldo actual es: $%.2f \n", listaClientes[nroCliente].saldo);
    printf("===========================\n");
}

// FUNCIÓN PARA EXTRACCIÓN DE CAPITAL
void extraccionCapital(int nroCliente)
{
    float retiro;
    printf("\n");
    printf("Ingrese el valor a retirar de su cuenta bancaria:\n");
    scanf("%f", &retiro);
    while (retiro > listaClientes[nroCliente].saldo || retiro <= 0)
    {
        printf("\n");
        printf("El monto a retirar de su cuenta no debe superar su saldo total o debe ser positivo.\n");
        printf("Reingrese el monto a extraer:\n");
        scanf("%f", &retiro);
    }
    listaClientes[nroCliente].saldo -= retiro;

    printf("\n");
    printf("===========================\n");
    printf("Su saldo actual es: $%.2f \n", listaClientes[nroCliente].saldo);
    printf("===========================\n");
}

// FUNCIÓN PARA REALIZAR UNA TRANSFERENCIA
void realizarTransferencia(int nroCliente)
{
    int cuentaDestino, monto, distinto, transferencia, i;
    transferencia = 0;
    i = 0;

    do
    {
        printf("\n");
        printf("Ingrese el n%cmero de la cuenta destino:\n", 163);
        scanf("%d", &cuentaDestino);

        if (cuentaDestino < 1 || cuentaDestino > cuentasClientesMaximos)
        {
            printf("\n");
            printf("Ingrese un n%cmero de cuenta entre 1 y %d \n", 163, cuentasClientesMaximos);
        }

    } while (cuentaDestino < 1 || cuentaDestino > cuentasClientesMaximos);

    if (listaClientes[nroCliente].nroCuenta != cuentaDestino)
    {
        while (i < cuentasClientesMaximos)
        {

            if (listaClientes[i].nroCuenta == cuentaDestino)
            {
                if (listaClientes[i].estado != 0)
                {
                    do
                    {
                        printf("\n");
                        printf("Ingrese la cantidad de dinero que desea transferir:\n");
                        scanf("%d", &monto);

                        if (monto <= 0)
                        {
                            printf("\n");
                            printf("El monto debe ser mayor a 0.\n");
                        }
                        else if (listaClientes[nroCliente].saldo < monto)
                        {
                            printf("\n");
                            printf("No posee saldo suficiente para realizar esta transferencia.\n");
                            break;
                        }

                    } while (monto <= 0 || listaClientes[nroCliente].saldo < monto);

                    listaClientes[i].saldo += monto;
                    listaClientes[nroCliente].saldo -= monto;

                    i = cuentasClientesMaximos;
                }
                else
                {
                    printf("\n");
                    printf("La cuenta destino est%c bloqueada.\n", 160);
                }
            }

            i++;
        }
    }
    else
    {
        printf("\n");
        printf("La cuenta origen y destino debe ser diferente.\n");
    }
}