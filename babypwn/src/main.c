#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void win(){
	FILE* fichero;
	char buffer[35];

	fichero = fopen("flag.txt","r");
	if (fichero == NULL){
		printf("Error al abrir el fichero 'flag.txt'.\n");
	}else{
		fgets(buffer, 35, fichero);
		printf("%s", buffer);
	}
	fclose(fichero);

}

void saludar(){
    int key = 0xffffffff;
    char buffer[32];
    printf("Introduce tu nombre: ");
    fflush(stdout);
    gets(buffer);
    if(key == 0xdeadbeef){
	    win();
    }
    else{
        printf("Hola %s!!\n", buffer);
    }
}

int main(int argc, char* argv[]){
    saludar();
    return 0;
}
