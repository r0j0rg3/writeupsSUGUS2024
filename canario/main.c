// $ gcc -fstack-protector -no-pie -m32 main.c -o canario
#include <stdio.h>

void vuln() {
    char nombre[33];
    char lugar[33];

	printf("Estoy muy ilusionado, por haber ganado un CTF mis padres han adoptado un canario, pero no se que nombre ponerle, se te ocurre alguno?\n");
    gets(nombre);

	printf("Asi que dices que debería llamarse...\n");
    printf(nombre);

    printf("\nSuena bien, ¿la jaula deberíamos ponerla en el porche o en la cocina?\n");
    gets(lugar);
}

int main() {
    vuln();
}

void print_flag() {
    FILE* fichero;
    char buffer[35];

    fichero = fopen("flag.txt", "r");
    if (fichero==NULL)
        printf("Error al abrir el fichero flag.txt.\n");
    fgets(buffer, 35, fichero);
    printf("%s", buffer);
    fclose(fichero);
}
