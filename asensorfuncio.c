#include <stdio.h>// librerias/

int pisoact = 0;   // variables/
int select;
int llamarp;
int i;

void pisoair() {
    printf("Ingrese el piso al que desea ir el ascensor (0-9): ");// printf de lo que quiero que escriba como pregunta*/
    scanf("%d", &select);
    getchar();

    if (select < 0 || select > 9) { //la condicion si*/
        printf("Piso no válido\n");
    } else if (select == pisoact) {
        printf("El ascensor ya está en el piso %d\n", pisoact);
    } else {
        llamarp = pisoact;// las acciones que quiero wque haga*/
        pisoact = select;
        printf("El ascensor ha llegado al piso %d\n", pisoact);
    }
}

void verpisoact() {// funcion
    printf("El ascensor está en el piso %d\n", pisoact);
}

void verubica() {//funciones
    if (pisoact == 0) {
        printf("El ascensor se encuentra en la planta baja\n");
    } else {
        printf("El ascensor se encuentra en el piso %d\n", pisoact);
    }
}

int main() {
    char op;

    do {
        printf("\n\nSeleccione una opcion:\n\n");
        printf("a. Llamar al ascensor desde un piso\n");//  prntf que queremos que escriba 
        printf("b. Ir a un piso\n");
        printf("c. Mostrar ubicacion\n");
        printf("d. Salir del ascensor\n");

        scanf(" %c", &op);

        switch (op) {// condicion para menu
            case 'a':
                printf("Ingrese el piso desde donde llama al ascensor (0-9): ");
                scanf("%d", &llamarp);
                if (llamarp == pisoact) {/// condicion si
                    printf("El ascensor ya está en el piso %d\n", pisoact);
                } else {
                    if (llamarp > pisoact) {
                        for (i = pisoact + 1; i <= llamarp; i++) {//condicion si
                            printf("Ascensor en piso %d\n", i);
                        }
                    } else {
                        for (i = pisoact - 1; i >= llamarp; i--) {// condicion si
                            printf("Ascensor en piso %d\n", i);
                        }
                    }
                    pisoact = llamarp;
                    printf("El ascensor ha llegado al piso %d\n", pisoact);
                }
                break;// finaliza

            case 'b':
                pisoair();
                break;

            case 'c':
                verubica();
                break;

            case 'd':
                printf("Adios\n");
                break;

            default:
                printf("Opcion no válida\n");
        }
    } while (op != 'd');

    return 0;
}