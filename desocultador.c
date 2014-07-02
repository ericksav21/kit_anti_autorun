#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <conio.h>

#define ATTRIB1 "attrib -r -s -h "
#define ATTRIB2 " /s /d"

using namespace std;

int main(int argc, char **argv){

	//Constantes con acento
	char cA = 160,
		 cE = 130,
		 cI = 161,
		 cO = 162,
		 cU = 163;

	//Derechos de autor y le decimos al usuario cómo acceder a la ayuda
	printf("Desocultador de archivos v1.0\n");
	printf("\nSoftware desarrollado por Erick Salvador Alvarez Valencia. Este software es para uso libre y no comercial. (Uso %cnico en Windows).\n",cU);

	if((argc>1 && (strcmp(argv[1], "--h")!=0 && strcmp(argv[1], "-help")!=0)) || argc==1){
		printf("Para recibir ayuda del sistema ejecuta este programa desde l%cnea de comandos usando una de las siguientes formas:\n\n",cI);
		printf("COMANDO: desocultador -help\n");
		printf("COMANDO: desocultador --h\n\n");
	}

	//Si el usuario a escrito mas de 1 parámetro, ignoramos y cerramos directamente
	if(argc>2){
		printf("Debes escribir solamente un par%cmetro",cA);
		return 0;
	}

	//Si el usuario tipea -help o --h desplegamos la ayuda
	if(argc==2){
		if(strcmp(argv[1], "-help")==0 || strcmp(argv[1], "--h")==0){

			printf("\nAyuda del sistema:\n\n");
			printf("Ejecuci%cn por comando desde prompt:\n\n",cO);

			printf("COMANDO: desocultador [path]\n\n");

			printf("*Para desocultar los archivos de una ruta espec%cfica, solo ejecuta el programa y como %cnico par%cmetro ",cI,cU,cA);
			printf("escribe la ruta (absoluta o relativa) en la cual ser%cn desocultados todos los archivos, subcarpetas, y archivos de subcarpetas.\n",cA);
			printf("Ejemplo:\n");
			printf("Se ejecuta el programa de la siguiente manera desde el prompt: desocultador C:\\miCarpeta\\miSubcarpeta...\\");
			printf("miSubcarpetaN \n");
			printf("De esta forma todo lo que est%c dentro de \"miSubcarpetaN\" ser%c desocultado.\n\n",cE,cA);

			printf("Ejecuci%cn directa:\n\n",cO);

			printf("COMANDO: [no es necesario]\n\n");

			printf("*Si no quieres meterte con la l%cnea de comandos, puedes ejecutar este programa directamente haciendo doble ",cI);
			printf("clic, solo tienes que pegar este archivo dentro de la carpeta donde ser%cn desocultados todos los archivos y ",cA);
			printf("subcarpetas y ejecutar el mismo, se te preguntar%c si realmente deseas desocultar todo, a lo que tu tendr%cs que ",cA,cA);
			printf("tiperar una \"Y\" para confirmar y el programa har%c el resto.\n\n",cA);

			printf("Errores del sistema:\n\n");

			printf("*Algunas veces el sistema puede detenerse al estar haciendo el proceso de desocultando los archivos y mandarnos ");
			printf("2 errores que ser%cn descritos a continuaci%cn:\n\n",cA,cO);
		
			printf("1.-Si en el mensaje de error encontramos un (1) entre par%cntesis esto quiere decir que la ruta (PATH) ",cE);
			printf("ingresada por el usuario (en el caso de que ejecute el programa con par%cmetros) sea incorrecta (no exista o ",cA);
			printf("contiene caracteres inv%clidos. Se recomienda verificar la ruta que sea correcta y volver a correr el programa.\n\n",cA);

			printf("2.-Si en el mensaje de error encontramos un (2) entre par%cntesis esto quiere decir que hubo un error interno al ",cE);
			printf("llamar al proceso encargado de desocultar los archivos. Se recuerda al usuario que este software funciona %cnicamente ",cU);
			printf("en Windows (XP en adelante) ya que el usarlo en otros sistemas operativos puede provocar este error.\n\n");

			return 0;
		}
	}

	//Si el usuario ingresa un argumento tendremos por entendido que es la ruta a tratar
	if(argc==2){
		char cad [200]; /*Cadena del comando attrib*/
		char resp[100]; /*Respuesta que nos dará el proceso en caso de algún error*/
		FILE *proceso = NULL;

		strcpy(cad, ATTRIB1);
		strcat(cad, argv[1]);
		strcat(cad, "\\*.*");
		strcat(cad, ATTRIB2);

		printf("Desocultando archivos...\n");
		proceso = popen(cad, "r");

		if(proceso){
			if(fgets(resp, 100, proceso)!=NULL){
				puts(resp);

				printf("Hubo un error. (1)\n\n");
			
			}else{
				printf("Archivos desocultados correctamente.\n");
				printf("El programa finaliz%c correctamente sin ningun mensaje de salida.\n\n", cO);
			}

			pclose(proceso);
		
		}else{
			printf("\nHubo un error. (2)\n\n");
			pclose(proceso);
		}

	}

	//Si el usuario no ingresa parámetros tendremos por entendido que la ruta actual será la tratada
	if(argc==1){
		char user_resp; /*La respuesta que nos dará el usuario, solo continuaremos si escribe Y*/
		char dir[100], dir_2[100], resp[100], cad[200]; /*El nombre del directorio a tratar*/
		int i;
		FILE *proc_dir = NULL, *proceso = NULL;

		/*Se extrae el directorio sobre el que está el programa*/
		proc_dir = popen("chdir", "r");
		if(proc_dir){
			fgets(dir, 100, proc_dir);

			pclose(proc_dir);

			for(int i=0;dir[i]!='\n' && dir[i]!='\0';i++)
				dir_2[i] = dir[i];
		
			printf("\n%cDesocultar todos los archivos y carpetas en %s%c ",168,dir_2,63);
			user_resp = getche();

			if(user_resp=='n' || user_resp=='N'){
				printf("\nNos vemos.\n\n");
			}

			else if(user_resp=='y' || user_resp=='Y'){
				strcpy(cad, ATTRIB1);
				strcat(cad, "*.*");
				strcat(cad, ATTRIB2);
			
				printf("\nDesocultando archivos...\n");
				proceso = popen(cad, "r");

				if(proceso){
					if(fgets(resp, 100, proceso)!=NULL){
						puts(resp);

						printf("Hubo un error. (1)\n\n");
					
					}else{
						printf("Archivos desocultados correctamente.\n");
						printf("El programa finaliz%c correctamente sin ningun mensaje de salida.\n\n", cO);
					}

					pclose(proceso);
				
				}else{
					printf("\nHubo un error. (2)\n\n");
					pclose(proceso);
				} //proceso

			}else{
				printf("\n%cError%c Debes utilizar \"y\" o \"Y\" para confirmar, \"n\" o \"N\" para negar.\n\n",173,33);
			} //respuesta del usuario

		}else{
			printf("Hubo un error. (2)");
			pclose(proc_dir);

			return 0;
		} //proceso superior
	}

	system("pause");
	return 0;
}
