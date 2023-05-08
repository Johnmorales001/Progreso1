#include <stdio.h>
#include <string.h>
//John Morales
// funcion de usuarios y contraseñas
int login() {
    char nombres[3][20] = {"John", "Juan", "Andres"};
    char contras[3][20]= {"1122", "2233", "3344"};

    char nombre[20];
    char contra[20];
    int intentos = 0;

    while (intentos < 3) {
        printf("Ingrese su usuario: ");
        scanf("%s", nombre);
        printf("Ingrese su contraseña: ");
        scanf("%s", contra);

        int i;
        for (i = 0; i < 3; i++) {
            if (strcmp(nombre, nombres[i]) == 0 && strcmp(contra, contras[i]) == 0) {
                return 1; 
            }
        }

        intentos++;
        printf("Usuario o contraseña fallidos. Intento #%d\n", intentos);
    }

    printf("No se puede ingresar.\n"); // si el usuario y contraseña no coincide no se puede acceder
    return 0;  
}

// funcion para calcular precio ruta y la distancia en kilómetros
float calcularPrecioRuta(char tipoRuta) {
    float precio;

    switch (tipoRuta) {
        case '1':
            precio = 0.10;
            break;
        case '2':
            precio = 0.15;
            break;
        case '3':
            precio = 0.20;
            break;
        default:
            printf("Tipo de ruta inválido.\n");
            precio = 0.0;
            break;
    }

    return precio;
}
// funcion para calcular el descuento segun ranfo de distancia
float calcularDescuento(float precio) {
    float descuento = 0.0;

    if (precio < 50.0) {
        descuento = 0.0;
    } else if (precio >= 50.0 && precio < 100.0) {
        descuento = precio * 0.05;
    } else if (precio >= 100.0 && precio < 500.0) {
        descuento = precio * 0.1;
    } else if (precio >= 500.0) {
        descuento = precio * 0.2;
    }

    return descuento;
}

// funcion para la operacion del transporte
void operacionTransporte() {
    int i;
    char tipoRuta;
    float distancia, subtotal, descuento, precioTotal;

    for (i = 0; i < 5; i++) {
        printf("Cliente %d\n", i + 1);
        printf("Ingrese el tipo de ruta (Urbana [1], Interurbana [2], Internacional [3]): ");
        scanf(" %c", &tipoRuta);
        printf("Ingrese la distancia en kilómetros: ");
        scanf("%f", &distancia);

        float precioPorKilometro = calcularPrecioRuta(tipoRuta);
        subtotal = distancia * precioPorKilometro;
        descuento = calcularDescuento(subtotal);
        precioTotal = subtotal - descuento;

        printf("Subtotal: %.2f\n", subtotal);
        printf("Descuento: %.2f\n", descuento);
        printf("Precio Total: %.2f\n",precioTotal);
}
}

//funcion para interactuar con la red social
void redSocial() {
int i;
char mensaje[100];
char categoria;
int noticias = 0, eventos = 0, preguntas = 0;
for (i = 0; i < 5; i++) {
    printf("Mensaje %d\n", i + 1);
    printf("Ingrese el contenido del mensaje: ");
    scanf(" %[^\n]", mensaje);
    printf("Ingrese la categoria del mensaje (Noticias [1], Eventos [2]: ");
    scanf(" %c", &categoria);

    switch (categoria) {
        case '1':
            noticias++;
            break;
        case '2':
            eventos++;
            break;
     
    }
}

printf("Publicaciones:\n");
printf("Noticias: %d\n", noticias);
printf("Eventos: %d\n", eventos);
}

// menu que permite seleccionar la opcion en el menu
void menu() {
int opcion;
do {
    printf("\n--- Menu de opciones ---\n");
    printf("1. Operacion de transporte\n");
    printf("2. Interactuar en la red social\n");
    printf("3. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            operacionTransporte();
            break;
        case 2:
            redSocial();
            break;
        case 3:
            printf("Fin del programa\n");
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }
} while (opcion != 3);
}

int main() {
printf("Transporte Publico\n");
if (login()) {
    menu();
} else {
    printf("Ingreso incorrecto. Fin del programa.\n");
}

return 0;
}