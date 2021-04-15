//NOMBRE DEL ESTUDIANTE: JORDAN AYUZO PACHECO
//GRUPO 102-A
//PROGRAMA DE UN CONTROL ADMINISTRATIVO
#include <stdio.h>
#include<conio.h>
#include <string.h>
#include<stdlib.h>
#define USUARIOS 500
#define NOMBRES 100
#define PRODUCTOS 500
#define PALABRAS 250
#define VENTAS 800
int n_adornos,cont_producto=0,cont_usuarios=0,cont_vend=0;
int auxiliar=0,zize1,zize2,z1=0,z2=0;
void margen();
void menu_principal();
void menu_ing_jefe();
void error_opt();
void error_c();
void ADM();
void inicializador();
void inicio(int cont_jefe1[],char nom_jefe1[],int clave_venta1[]);
void principal(int *opt1,int cont_jefe_aux[],char nom_jefe_aux[], int clave_venta_aux[2],
int realizado[],int *token1);
void ing_jefe(int cont_jefe2[],char nom_jefe2[],int clave_venta2[],char aviso[],
int realizado[],int *token_aux,int cant_venta_aux[],int venta_codi_aux[] );
void ingresar_producto();
void ingresar_trabajador();
void mostrar();
void modificar_datos(char nom_jefe[], int cont_jefe[]);
void mod_personal();
void mod_producto();
void mod_jefe(char nom_jefe[], int cont_jefe[]);
void anotar_aviso(char aviso_aux[]);
void ver_ventas(int cant_venta1[],int venta_codi1[VENTAS]);
void ing_trabajador(int clave_venta3[],char aviso[],int realizado[],int *token2,int cant_venta2[],int venta_codi2[]);
void mostrar_producto();
void vender_producto(int clave_venta31[],int cant_venta21[],int venta_codi21[]);
void cambiar_contra(int *clave1);
void pago_tabajadores(int *clave2);
void mostrar_personal_public();
void mostrar_aviso(char aviso[]);
//estructuras
struct producto{
  char nombre[100];
  float precio_compra;
  float precio_venta;
  int codigo;
  int cantidad;
}*productos;
struct personas{
  char nombre[100];
  int clave;
  float salario;
  int matricula;
}*personal;
int main() {
char nom_jefe[NOMBRES];
int cont_jefe[2],clave_venta[2],realizado[USUARIOS];
int contador=0,opt=0,token=1;
while (opt != 5){
  if(contador==0){
    inicializador();
    inicio(cont_jefe,nom_jefe,clave_venta);
    contador++;
  }
  principal(&opt,cont_jefe,nom_jefe,clave_venta,realizado,&token);
  if (opt==5){
  	int x;
  	system("cls");
		n_adornos=41;
		printf("\t");margen();
  	printf("\t %cEstas Seguro De Tu Respuesta%c\n",168,63);
  	printf("\t si sale se borrar%c toda la informaci%cn\n",160,162);
  	printf("\t Si Desea Salir Presione (1)\n");
  	printf("\t Si No Es lo que desea presione 2 \n");
  	scanf("%d",&x);
  	if(x!=1){
  		opt=0;
		}
  	
	}
}
return 0;
}
void margen(){
int i;
for(i=1;i<n_adornos;i++)
  printf("%c",176 );
printf("\n");
}
void inicio(int cont_jefe1[],char nom_jefe1[],int clave_venta1[]){
system("cls");
n_adornos=74;
printf("\t");margen();
printf("\t%c                              BIENVENIDO.                              %c\n",176,176);
printf("\t");margen();
printf("\t%c %c Inventario Para Un control administrativo.                          %c\n",176,175,176);
printf("\t%c %c A continuaci%cn Ingresar%c datos del propietario e ingresar           %c\n",176,175,162,160,176);
printf("\t%c      una contrase%ca.                                                  %c\n",176,164,176);
printf("\t%c %c Esto es importante ya que solo el Propietario podr%c modificar datos.%c\n",176,175,160,176);
printf("\t%c %c Presione cualquier bot%cn para continuar.                            %c\n",176,175,162,176);
printf("\t");margen();printf("\t");
getch();
system("cls");
n_adornos=49;
printf("\n\n\t\t");margen();
printf("\t\t");margen();
printf("\t\t %c Nombre Del Propietario: ",175);
gets(nom_jefe1);
printf("\t\t");margen();
printf("\t\t %c Contrase%ca: ",175,164);
scanf("%d",&cont_jefe1[0]);
printf("\t\t");margen();
printf("\t\t %c Clave de permiso de ventas: ",175);
scanf("%d",&clave_venta1[0]);
printf("\t\t");margen();
printf("\t\t %c Cantidad Limite de Productos: ",175);
scanf("%d",&zize1);
printf("\t\t");margen();
printf("\t\t %c Cantidad Limite de Usuarios: ",175);
scanf("%d",&zize2);
printf("\t\t %c Presione Cualquier Bot%cn Para Guardar Datos.\n",175,162);
printf("\t\t");margen();
printf("\t\t");margen();
productos= (struct producto*)calloc(zize1,sizeof(struct producto));
personal= (struct personas*)calloc(zize2,sizeof(struct personas));
getch();

}
void principal(int *opt1,int cont_jefe_aux[],char nom_jefe_aux[], int clave_venta_aux[],int realizado[],int *token1){
	char aviso[PALABRAS];
	int cant_venta[VENTAS],venta_codi[VENTAS];
	menu_principal();
	scanf("%d",&*opt1 );
	switch (*opt1) {
	  case 1:
  	  ing_jefe(cont_jefe_aux,nom_jefe_aux,clave_venta_aux,aviso,realizado,&*token1,cant_venta,venta_codi);
  	  break;
  	case 2:
  	  ing_trabajador(clave_venta_aux,aviso,realizado,&*token1,cant_venta,venta_codi);
    	break;
  	case 3:
   		mostrar_personal_public();
   		break;
  	case 4:
    	mostrar_aviso(aviso);
    	break;
  	case 5:
    	break;
}	
}
void ing_jefe(int cont_jefe2[],char nom_jefe2[],int clave_venta2[],char aviso[],int realizado[],int *token_aux,int cant_venta_aux[],int venta_codi_aux[] ){
int opt1=0;
do{
  system("cls");
  n_adornos=50;
  printf("\n\n\t\t");margen();
  printf("\t\t");margen();
  printf("\t\tNombre:%s  (-1)Salir.\n",nom_jefe2);
  printf("\t\t");margen();
  printf("\t\t%c Contrase%ca: ",175,164);
  scanf("%d",&cont_jefe2[1]);
  if(cont_jefe2[0]==cont_jefe2[1]){
    do{
      menu_ing_jefe();
      scanf("%d",&opt1);
      switch (opt1) {
        case 1:
            	ingresar_producto();
          break;
        case 2:
        	ingresar_trabajador();
          break;
        case 3:
          mostrar();
          break;
        case 4:
          modificar_datos(nom_jefe2,cont_jefe2);
          break;
        case 5:
          anotar_aviso(aviso);
          break;
        case 6:
          ver_ventas(cant_venta_aux,venta_codi_aux);
          break;
        case 7:
        *token_aux=2;
        int j;
  			for(j=0;j<=USUARIOS;j++){
  				realizado[j]=1;
  			}
        system("cls");
        printf("\n\n                                                        #      \n");
        printf("                                       +    +   +    #         \n");
        printf("                                    +              #            \n");
        printf("                                   +            #   +         \n");
        printf("                                  +     #    #       +       \n");
        printf("                                  +       #          +     \n");
        printf("                                   +                +       \n");
        printf("                                     +            +           \n");
        printf("                                        + + + + +            \n");
        printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
        getch();
          break;
        case 8:
        system("cls");
          *token_aux=1;
          printf("\n\n                                                        #      \n");
          printf("                                       +    +   +    #         \n");
          printf("                                    +              #            \n");
          printf("                                   +            #   +         \n");
          printf("                                  +     #    #       +       \n");
          printf("                                  +       #          +     \n");
          printf("                                   +                +       \n");
          printf("                                     +            +           \n");
          printf("                                        + + + + +            \n");
          printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
          getch();
          break;
        case 9:
          break;
        default:
          error_opt();
          break;
      }
    }while(opt1 !=9);
  }
  else{
    if (cont_jefe2[1] !=-1)
      error_c();
  }
}while((cont_jefe2[0] != cont_jefe2[1])&&(cont_jefe2[1] !=-1));
}
void ingresar_producto(){
int opt,opt2,n_producto;
do{
  system("cls");
  n_adornos=49;
  printf("\n\n\t\t");
  margen();
  printf("\t\t");
  margen();
  printf("\t\t%c 1)   A%cadir Producto Uno Por Uno             %c\n",176,164,176);
  printf("\t\t%c 2)   A%cadir Sabiendo La Cantidad De Productos%c\n",176,164,176);
  printf("\t\t%c 3)   Salir                                   %c\n",176,176);
  printf("\t\t");
  margen();
  printf("\t\t %c Ingresar Una opci%cn: ",175,162);
  scanf("%d",&opt);
  switch(opt){
    case 1 :
     	system("cls");
     	n_adornos=53;
     	printf("\n\n\t\t");margen();
     	printf("\t\t");margen();
     	printf("\t\tIngresa 1 Para Guardar Productos o 2 Para Salir: ");
     	scanf ("%d",&opt2);
      while(opt2!=2){
      	if(z1<=zize1){
      		z1++;
        	printf("\t\t");margen();
        	printf("\t\t%c Producto: ",175);
        	getchar();
        	gets(productos[cont_producto].nombre);
        	printf("\t\tCantidad: ");
        	scanf("%d",&productos[cont_producto].cantidad);
        	printf("\t\tPrecio: $");
        	scanf("%f",&productos[cont_producto].precio_venta);
        	printf("\t\t");margen();
        	printf("\t\t");margen();
        	cont_producto++;
        	printf("\t\tIngresa 1 Para Guardar Productos o 2 Para Salir: ");
        	scanf("%d",&opt2);
      	}
      }
			break;
    case 2:
      system("cls");
      n_adornos=44;
      printf("\n\n\t\t");margen();
      printf("\t\t");margen();
      printf("\t\t%c %cCu%cntos Productos Ingresar%c%c ",175,168,160,160,63);
      scanf("%d",&n_producto);
      getchar();
      int i;
      if(z1<=zize1 && n_producto<=(zize1-z1)){
      	for(i=1;i<=n_producto;i++){
        	printf("\t\t%c Producto: ",175);
        	gets(productos[cont_producto].nombre);
        	printf("\t\tCantidad: ");
        	scanf("%d",&productos[cont_producto].cantidad);
        	printf("\t\tPrecio: $");
        	scanf("%f",&productos[cont_producto].precio_venta);
        	fflush(stdin);
        	cont_producto++;
        	z1++;
      	}
    	}
      break;
    case 3:
      break;
    default :
      error_opt();
      break;
  }
}while(opt != 3);
}
void ingresar_trabajador(){
  int opt,opt2,n_trabajador;
  do{
    system("cls");
    n_adornos=49;
    printf("\n\n\t\t");margen();
    printf("\t\t");margen();
    printf("\t\t%c 1)   A%cadir Empleado Uno Por Uno             %c\n",176,164,176);
    printf("\t\t%c 2)   A%cadir Sabiendo La Cantidad De Empleados%c\n",176,164,176);
    printf("\t\t%c 3)   Salir                                   %c\n",176,176);
    printf("\t\t");margen();
    printf("\t\t Ingresar Una opci%cn: ",162);
    scanf("%d",&opt);
    switch(opt){
      case 1 :
        system("cls");
        n_adornos=50;
        printf("\n\n\t\t");margen();
        printf("\t\t");margen();
        printf("\t\tIngresa 1 Para Guardar Empleado o 2 Para Salir: ");
        scanf ("%d",&opt2);
        while(opt2!=2){
        	if(z2<=zize2){
      			z2++;
          	n_adornos=50;
          	printf("\t\t");margen();
          	printf("\t\t%c Empleado: ",175);
          	getchar();
          	gets(personal[cont_usuarios].nombre);
          	printf("\t\t Contrase%ca: ",164);
          	scanf("%d",&personal[cont_usuarios].clave);
          	printf("\t\t Salario: %c",36);
          	scanf("%f",&personal[cont_usuarios].salario);
          	fflush(stdin);
          	printf("\t\t");margen();
          	cont_usuarios++;
          	printf("\t\tIngresa 1 Para Guardar Productos o 2 Para Salir: ");
          	scanf("%d",&opt2);
        	}
        }
        break;
      case 2:
        n_adornos=47;
        system("cls");
        printf("\n\n\t\t");margen();
        printf("\t\t");margen();
        printf("\t\t%c Cu%cntos Empleados ingresar%c%c ",168,160,160,63);
        scanf("%d",&n_trabajador);
        getchar();
        int i;
        if(z2<=zize2 && n_trabajador<=(zize2-z2)){
        	for(i=1;i<=n_trabajador;i++){
          	printf("\t\t%c Empleado: ",175);
          	gets(personal[cont_usuarios].nombre);
          	printf("\t\t Contrase%ca: ",164);
          	scanf("%d",&personal[cont_usuarios].clave);
          	printf("\t\t Salario: %c",36);
          	scanf("%f",&personal[cont_usuarios].salario);
          	fflush(stdin);
          	cont_usuarios++;
          	z2++;
        	}
      	}
        break;
      case 3:
        break;
      default :
        error_opt();
        break;
    }
  }while(opt != 3);
}
void mostrar(){
  int opt;
  do{
		system("cls");
		n_adornos=49;
		printf("\n\n\t\t");margen();
		printf("\t\t");margen();
		printf("\t\t%c 1)   Mostrar productos                       %c\n",176,176);
		printf("\t\t%c 2)   Mostrar usuarios                        %c\n",176,176);
		printf("\t\t%c 3)   Salir                                   %c\n",176,176);
		printf("\t\t");margen();
		printf("\t\t %c Ingresar Una opci%cn: ",175,162);
		scanf("%d",&opt);
		switch(opt){
			case 1:
        system("cls");
        int cont=0;
        n_adornos=85;
        margen();
        printf("	CLAVE	|	CANTIDAD	|	PRECIO	|	PRODUCTO\n");
        margen();
        while(cont<=(cont_producto-1)){
          printf("	%d		",cont);
          printf(" %d  	",productos[cont].cantidad);
          printf("	 	$%.2f  	",productos[cont].precio_venta);
          printf("   %s\n",productos[cont].nombre);
          cont++;
        }margen();getch();
				break;
			case 2:
        n_adornos=95;
        system("cls");
        margen();
        printf("	CLAVE		|  Contrase%ca		|  SUELDO		| TRABAJADOR	\n",164);
        margen();
      cont=0;
      while(cont<=(cont_usuarios-1)){
        printf("	%d		|",cont);
        printf("	%d		|",personal[cont].clave);
        printf("	%.2f		|",personal[cont].salario);
          printf("	%s			\n",personal[cont].nombre);
        cont++;
      }margen();getch();
				break;
			case 3:
				break;
			default :
				error_opt();
				break;

		}
	}while(opt != 3);
}
void modificar_datos(char nom_jefe[], int cont_jefe[]){
	int opt;
	do{
		system("cls");n_adornos=38;
		printf("\t\t\t");margen();
		printf("\t\t\t%c      MEN%c DE OPCIONES             %c\n",176,233,176);
		printf("\t\t\t");margen();
		printf("\t\t\t%c    Modificar:                     %c\n",176,176);
		printf("\t\t\t%c 1)   Datos Del Personal           %c\n",176,176);
		printf("\t\t\t%c 2)   Datos Del Producto           %c\n",176,176);
		printf("\t\t\t%c 3)   Datos Del Jefe               %c\n",176,176);
		printf("\t\t\t%c 4)   Salir                        %c\n",176,176);
		printf("\t\t\t");margen();
		printf("\t\t\t%c Ingresar Una Opci%cn: ",175,162);
		scanf("%d",&opt);
		switch(opt){
			case 1:
				mod_personal();
				break;
			case 2:
				mod_producto();
				break;
			case 3:
				mod_jefe(nom_jefe,cont_jefe);
				break;
			case 4:
				break;
			Default:
				error_opt();
				break;
		}
	
	}while(opt!=4);
}
void mod_personal(){
	int codi,opt;
  system ("cls");
	n_adornos=74;
	printf("\t\t");margen();
	printf("\t\t%c Clave Del Personal que desea modificar: ",175);
	scanf("%d",&codi);
	system ("cls");
	printf("\t\t");margen();
	getchar();
	printf("\t\t\tNombre: %s\n",personal[codi].nombre);
	printf("\t\t\tSalario:  %.2f \n",personal[codi].salario);
	printf("\t\t\tContrase%ca %d \n",164,personal[codi].clave);
	n_adornos=38;
	printf("\t\t");margen();
	printf("\t\t%c 1)   Modificar Nombre             %c\n",176,176);
	printf("\t\t%c 2)   Modificar Salario            %c\n",176,176);
	printf("\t\t%c 3)   Modificar Contrase%ca         %c\n",176,164,176);
	printf("\t\t%c 4)   Salir                        %c\n",176,176);
	printf("\t\t");margen();
	printf("\t\t%c Ingresar Una Opci%cn: ",175,162);
	scanf("%d",&opt);
	n_adornos=50;
	switch (opt){
		case 1:
			system("cls");
			printf("\t\t");margen();
			printf("\t\t%c Ingrese Nuevo nombre del Personal: ",175);
			getchar();
			gets(personal[codi].nombre);
      system("cls");
      printf("\n\n                                                        #      \n");
      printf("                                       +    +   +    #         \n");
      printf("                                    +              #            \n");
      printf("                                   +            #   +         \n");
      printf("                                  +     #    #       +       \n");
      printf("                                  +       #          +     \n");
      printf("                                   +                +       \n");
      printf("                                     +            +           \n");
      printf("                                        + + + + +            \n");
      printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
      getch();
			break;
		case 2:
      system("cls");
			printf("\t\t");margen();
			printf("\t\t%c Ingrese nuevo Salario: ",175);
			scanf("%d",&personal[codi].salario);
      system("cls");
      printf("\n\n                                                        #      \n");
      printf("                                       +    +   +    #         \n");
      printf("                                    +              #            \n");
      printf("                                   +            #   +         \n");
      printf("                                  +     #    #       +       \n");
      printf("                                  +       #          +     \n");
      printf("                                   +                +       \n");
      printf("                                     +            +           \n");
      printf("                                        + + + + +            \n");
      printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
      getch();
			break;
		case 3:
      system("cls");
			printf("\t\t");margen();
			printf("\t\t%c Ingrese Nueva Contrase%ca: ",175,164);
			scanf("%f",&personal[codi].clave);
      system("cls");
      printf("\n\n                                                        #      \n");
      printf("                                       +    +   +    #         \n");
      printf("                                    +              #            \n");
      printf("                                   +            #   +         \n");
      printf("                                  +     #    #       +       \n");
      printf("                                  +       #          +     \n");
      printf("                                   +                +       \n");
      printf("                                     +            +           \n");
      printf("                                        + + + + +            \n");
      printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
      getch();
      break;
		case 4:
			break;
		default:
			error_opt();
			break;
	}
}
void mod_producto(){
  int codi,opt;
  system ("cls");
	n_adornos=74;
	printf("\t\t");margen();
	printf("\t\t%c Clave Del Producto que desea modificar: ",175);
	scanf("%d",&codi);
	system ("cls");
	printf("\t\t");margen();
	getchar();
	printf("\t\t\tProducto: %s\n",productos[codi].nombre);
	printf("\t\t\tprecio:  %.2f \n",productos[codi].precio_venta);
	printf("\t\t\tCantidad %d \n",productos[codi].cantidad);
	n_adornos=38;
	printf("\t\t");margen();
	printf("\t\t%c 1)   Modificar Producto           %c\n",176,176);
	printf("\t\t%c 2)   Modificar Cantidad           %c\n",176,176);
	printf("\t\t%c 3)   Modificar Precio             %c\n",176,176);
	printf("\t\t%c 4)   Salir                        %c\n",176,176);
	printf("\t\t");margen();
	printf("\t\t%c Ingresar Una Opci%cn: ",175,162);
	scanf("%d",&opt);
	n_adornos=50;
	switch (opt){
		case 1:
			system("cls");
			printf("\t\t");margen();
			printf("\t\t%c Ingrese Nuevo nombre del producto: ",175);
			getchar();
			gets(productos[codi].nombre);
      system("cls");
      printf("\n\n                                                        #      \n");
      printf("                                       +    +   +    #         \n");
      printf("                                    +              #            \n");
      printf("                                   +            #   +         \n");
      printf("                                  +     #    #       +       \n");
      printf("                                  +       #          +     \n");
      printf("                                   +                +       \n");
      printf("                                     +            +           \n");
      printf("                                        + + + + +            \n");
      printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
      getch();
			break;
		case 2:
      system("cls");
			printf("\t\t");margen();
			printf("\t\t%c Ingrese nueva Cantidad: ",175);
			scanf("%d",&productos[codi].cantidad);
      system("cls");
      printf("\n\n                                                        #      \n");
      printf("                                       +    +   +    #         \n");
      printf("                                    +              #            \n");
      printf("                                   +            #   +         \n");
      printf("                                  +     #    #       +       \n");
      printf("                                  +       #          +     \n");
      printf("                                   +                +       \n");
      printf("                                     +            +           \n");
      printf("                                        + + + + +            \n");
      printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
      getch();
			break;
		case 3:
      system("cls");
			printf("\t\t");margen();
			printf("\t\t%c Ingrese Nuevo Precio: ",175);
			scanf("%f",&productos[codi].precio_venta);
      system("cls");
      printf("\n\n                                                        #      \n");
      printf("                                       +    +   +    #         \n");
      printf("                                    +              #            \n");
      printf("                                   +            #   +         \n");
      printf("                                  +     #    #       +       \n");
      printf("                                  +       #          +     \n");
      printf("                                   +                +       \n");
      printf("                                     +            +           \n");
      printf("                                        + + + + +            \n");
      printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
      getch();
      break;
		case 4:
			break;
		default:
			error_opt();
			break;
	}
}
void mod_jefe(char nom_jefe[], int cont_jefe[]){
	int opt;
	system ("cls");
	printf("\t\t");margen();
	printf("\t\t\tNombre: %s\n",nom_jefe);
	printf("\t\t\tContrase%ca %d \n",164,cont_jefe[0]);
	n_adornos=38;
	printf("\t\t");margen();
	printf("\t\t%c 1)   Modificar Nombre             %c\n",176,176);
	printf("\t\t%c 2)   Modificar Contrase%ca         %c\n",176,164,176);
	printf("\t\t%c 3)   Salir                        %c\n",176,176);
	printf("\t\t");margen();
	printf("\t\t%c Ingresar Una Opci%cn: ",175,162);
	scanf("%d",&opt);
	n_adornos=50;
	switch (opt){
		case 1:
			system("cls");
			printf("\t\t");margen();
			printf("\t\t%c Ingrese Su Nuevo Nombre: ",175);
			getchar();
			gets(nom_jefe);
      system("cls");
      printf("\n\n                                                        #      \n");
      printf("                                       +    +   +    #         \n");
      printf("                                    +              #            \n");
      printf("                                   +            #   +         \n");
      printf("                                  +     #    #       +       \n");
      printf("                                  +       #          +     \n");
      printf("                                   +                +       \n");
      printf("                                     +            +           \n");
      printf("                                        + + + + +            \n");
      printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
      getch();
			break;
		case 2:
      system("cls");
			printf("\t\t");margen();
			printf("\t\t%c Ingrese Nueva Contrase%ca: ",175,164);
			scanf("%d",&cont_jefe[0]);
      system("cls");
      printf("\n\n                                                        #      \n");
      printf("                                       +    +   +    #         \n");
      printf("                                    +              #            \n");
      printf("                                   +            #   +         \n");
      printf("                                  +     #    #       +       \n");
      printf("                                  +       #          +     \n");
      printf("                                   +                +       \n");
      printf("                                     +            +           \n");
      printf("                                        + + + + +            \n");
      printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
      getch();
      break;
		case 3:
			break;
		default:
			error_opt();
			break;
	}	
}
void anotar_aviso(char aviso_aux[]){
  n_adornos=130;
  system("cls");
  margen();
  printf("\t\t Escribe el Aviso\n\t\t");
  getchar();
  gets(aviso_aux);
}
void ver_ventas(int cant_venta1[],int venta_codi1[]){
  int i;
  float tot1;
  if (cont_vend!=0){
  	for(i=0;i<cont_vend;i++){
  		system("cls");
  		n_adornos=85;
  		margen();
  		printf("	CANTIDAD	|	PRECIO. U	|	TOTAL	|	PRODUCTO\n");
  		margen();
  		printf("	%d		",cant_venta1[i]);
  		printf(" 	$%.2f 	",productos[venta_codi1[i]].precio_venta);
  		tot1=(float)cant_venta1[i]*productos[venta_codi1[i]].precio_venta;
  		printf("   $%.2f	 ",tot1);
  	  printf("   %s\n",productos[venta_codi1[i]].nombre);
  	}
  	margen();printf("\n");
  	n_adornos=40;
  		margen();
  	printf(" Para Guardar  Datos  Presione  (1)\n");
  	printf(" Para No Guardar Datos Presione (2)\n\t\t");
  	int imprimir;
		scanf("%d",&imprimir);
		if(imprimir != 2){
			system("cls");
			char a[100];
			n_adornos=35;
  		printf("\t");margen();
			printf("\tNombre del Archivo: ");
    	fflush(stdin);
			gets(a);
    	char b[6]= ".txt";
   		char c[110];
   		strcpy(c,a);
  		strcat(c,".txt");
 			FILE *ventas;
    	if ((ventas = fopen(c,"w")) == NULL){
      	printf("hubo un error");
    	} else {
        for(i=0;i<cont_vend;i++){
  				fprintf(ventas,"\tCANTIDAD\t\tPRECIO. U\t TOTAL\t   PRODUCTO\n");
  				fprintf(ventas,"	%d		",cant_venta1[i]);
  				fprintf(ventas," 	$%.2f 	",productos[venta_codi1[i]].precio_venta);
  				tot1=(float)cant_venta1[i]*productos[venta_codi1[i]].precio_venta;
  				fprintf(ventas,"   $%.2f	 ",tot1);
  	  		fprintf(ventas,"   %s\n",productos[venta_codi1[i]].nombre);
    		}
    		fclose(ventas);
			}
  		printf("\t");margen();
  		printf("Se Ha guardado en la carpeta AMD\n");
  		margen();
  		getch();
 	 }
	}
  else{
  	system ("cls");
  	printf("\n\n\n");
  	printf("\t****\n");
  	printf("\t   **\n");
  	printf("\t    **\n");
  	printf("\t     ******************************\n");
  	printf("\t      **                        **\n");
  	printf("\t       **     AUN NO HAY       **\n");
  	printf("\t        **    VENTAS :(       **\n");
  	printf("\t         **                  **\n");
  	printf("\t          ********************\n");
  	printf("\t          ********************\n");
  	printf("\t             **        **\n");
  	printf("\t            ****      ****\n");
  	printf("\t             **        **\n");
  	getch();
  }
}
void ing_trabajador(int clave_venta3[],char aviso[],int realizado[],int *token2,int cant_venta2[],int venta_codi2[]){
  int clave=0,contrasena,opt;
  do{
    system("cls");
    n_adornos=50;
    printf("\t\t");margen();
    printf("\t\t%c CLAVE DEL EMPLEADO: ",175);
    scanf("%d",&clave);
    system("cls");
    printf("\t\t");margen();
    printf("\t\tNombre: %s    (-1 para salir)\n",personal[clave].nombre);
    printf("\t\t");margen();
    printf("\t\tIngresar contrase%ca: ",164);
    scanf("%d",&contrasena);
    if(contrasena==personal[clave].clave){
      if(*token2==1){
        do{
          system("cls");
          n_adornos=38;
          printf("\t\t");margen();
            printf("\t\t%c      MEN%c DE OPCIONES             %c\n",176,233,176);
            printf("\t\t");margen();
            printf("\t\t%c 1)   Mostrar productos            %c\n",176,176);
            printf("\t\t%c 2)   Vender un producto           %c\n",176,176);
            printf("\t\t%c 3)   Cambiar contrase%ca           %c\n",176,164,176);
            printf("\t\t%c 4)   Salir                        %c\n",176,176);
            printf("\t\t");margen();
            printf("\t\t %c Ingresar Una Opci%cn: ",175,162);
          scanf("%d",&opt);
              switch (opt){
                case 1:
                    mostrar_producto();
                    break;
                case 2:
                    vender_producto(clave_venta3,cant_venta2,venta_codi2);
                    break;
                case 3:
                  cambiar_contra(&clave);
                  break;
                case 4:
                    break;
                default:
                    error_opt();
              }
        }while(opt !=4);
      }
      else{
        do{
          system("cls");
          n_adornos=38;
          printf("\t\t");margen();
            printf("\t\t%c      MEN%c DE OPCIONES             %c\n",176,233,176);
            printf("\t\t");margen();
            printf("\t\t%c 1)   Mostrar productos            %c\n",176,176);
            printf("\t\t%c 2)   Vender un producto           %c\n",176,176);
            printf("\t\t%c 3)   Cambiar contrase%ca           %c\n",176,164,176);
            printf("\t\t%c 4)   Recibir clave de Pago        %c\n",176,176);
            printf("\t\t%c 5)   Salir                        %c\n",176,176);
            printf("\t\t");margen();
            printf("\t\t %c Ingresar Una Opci%cn: ",175,162);
          scanf("%d",&opt);
              switch (opt){
                case 1:
                    mostrar_producto();
                    break;
                case 2:
                    vender_producto(clave_venta3,cant_venta2,venta_codi2);
                    break;
                case 3:
                  cambiar_contra(&clave);
                  break;
                case 4:
                    if(realizado[clave]==1)	{
                    pago_tabajadores(&clave);
                    realizado[clave]=2;
                  }
                  else{
                    system("cls");
                    n_adornos=50;
                    printf("\t\t");margen();
                    printf("\t\t%c Usted Ya Ha Realizado Esta opcion \n",176);
                    getch();
              }
                    break;
                  case 5:
                    break;
                default:
                    error_opt();
              }
        }while(opt !=5);
      }
    }
    else{
      if(contrasena !=-1)
      error_c();
    }
  }while(contrasena != personal[clave].clave && contrasena !=-1);
}
void mostrar_producto(){
  system("cls");
  int cont=0;
  n_adornos=85;
  margen();
  printf("	CLAVE	|	CANTIDAD	|	PRECIO	|	PRODUCTO\n");
  margen();
  while(cont<cont_producto){
    printf("	%d		",cont);
    printf(" %d  	",productos[cont].cantidad);
    printf("	 	$%.2f  	",productos[cont].precio_venta);
      printf("   %s\n",productos[cont].nombre);
    cont++;
  }
  margen();
  getch();

}
void vender_producto(int clave_venta31[],int cant_venta21[],int venta_codi21[]){
  int codi = 0,vendido=0;
  system("cls");
  n_adornos=50;
  printf("\t\t");margen();
  printf("\t\tEscriba el codigo del producto: ");
  scanf("%d",&codi);
  system("cls");
  n_adornos=37;
  printf("\t\t");margen();
  printf("\t\tProducto: %s\n",productos[codi].nombre);
  printf("\t\tCantidad: %d\n",productos[codi].cantidad);
  printf("\t\tPrecio: %.2f\n",productos[codi].precio_venta);
  printf("\t\t");margen();
  printf("\t\t PRODUCTOS A VENDER: ");
  scanf("%d",&vendido);
  system ("cls");
  n_adornos=60;
  printf("\t\t");margen();
  float tot = (float)vendido*productos[codi].precio_venta;
  printf("\t\t cantidad a pagar %.2f\n",tot);
  printf("\t\t NOTA: Si no desea generar la compra ingresar cualquier valor\n",164);
  printf("\t\t Escriba la clave de Permiso para continuar: ",164);
  scanf("%d",&clave_venta31[1]);
      if(clave_venta31[0]==clave_venta31[1]){
        if(vendido>productos[codi].cantidad){
          system("cls");
          n_adornos=32;
          printf("\t\t");margen();
          printf("\t\t No Hay La Cantidad Suficiente \n");
          getch();
        }
        else{
          system("cls");
          productos[codi].cantidad-=vendido;
          cant_venta21[auxiliar]=vendido;
          venta_codi21[auxiliar]=codi;
          auxiliar++;
          cont_vend++;
          printf("\t\t cantidad a pagar %.2f\n",tot);
          printf("\n\n                                                        #      \n");
          printf("                                       +    +   +    #         \n");
          printf("                                    +              #            \n");
          printf("                                   +            #   +         \n");
          printf("                                  +     #    #       +       \n");
          printf("                                  +       #          +     \n");
          printf("                                   +                +       \n");
          printf("                                     +            +           \n");
          printf("                                        + + + + +            \n");
          printf("                             SE HA REALIZADO CORRECTAMENTE             \n");
          getch();
      }
    }
}
void cambiar_contra(int *clave1){
  system("cls");
  n_adornos=70;
	printf("\t\t");margen();
  printf("\t\t Ingrese una nueva contrase%ca ",164);
	scanf("%d",&personal[*clave1].clave);
  system("cls");
  n_adornos=70;
	printf("\t\t");margen();
  printf("\t\t Contrase%ca modificada\n",164);
  printf("\t\t Nueva Contrase%ca %d \n",164,personal[*clave1].clave);
	getch();

}
void pago_tabajadores(int *clave2){
  system("cls");
  char c[110];
	int part1=260,part2;
	srand(time(NULL));
	part2=1+rand()%99;
	n_adornos=50;
	printf("\n\n\t\t");margen();
	printf("\n\t\t Hola %s \n",personal[*clave2].nombre);
	printf("\t\t tu sueldo es de  %.2f \n",personal[*clave2].salario);
	printf("\t\tPasa a ventanilla con este numero de clave: \n");
	printf("\t\t\t %c  00975%d%d %c\n",175,part1,part2,174);
  strcpy(c,personal[*clave2].nombre);
  strcat(c,".txt");
 	FILE *cheque;
  if ((cheque = fopen(c,"w")) == NULL){
  	n_adornos=85;
		printf("\t\t");margen();
  	printf("\t\tEl Servidor Tiene Un Error...\n",
					 "\t\tNotifica Al Supervisor Del Area\n");
  } 
	else {
		fprintf(cheque," =====================================================\n");
		fprintf(cheque," =====================================================\n");
  	fprintf(cheque,"               Banco De Mexico S.A de C.V             \n",169);
  	fprintf(cheque," =====================================================\n");
  	fprintf(cheque," Pague a nombre de: %s\n",personal[*clave2].nombre);
  	fprintf(cheque,"                   __________________________________.\n");
  	fprintf(cheque," La cantidad de: %.2f\n",personal[*clave2].salario);
  	fprintf(cheque,"                _____________________________________.\n");
  	fprintf(cheque," Clave de Retiro: 00975%d%d \n",part1,part2);
  	fprintf(cheque,"                 _____________________.  \n");
  	fprintf(cheque," =====================================================\n");
  	fprintf(cheque," NOTA: Se recomienda llevar un comprobante para el\n");
		fprintf(cheque,"        movimiento solicitado.\n");
		fprintf(cheque," =====================================================\n");
  	fprintf(cheque," =====================================================\n");
  	fclose(cheque);
		printf("\t\t");margen();
  	printf("\n\t\tEl cheque ha sido guardado en la carpeta ADM \n");
		printf("\t\tpara mayor seguurdiad al pasar su documento en\n");
		printf("\t\tun pendrive o immprimir, eliminarlo de dicha carpeta\n");
		getch();
  }
}
void mostrar_personal_public(){
  system("cls");
  int cont=0;
  n_adornos=60;
  printf("\n\t");margen();
  printf("\t	CLAVE		|	TRABAJADOR	\n");
  printf("\t");margen();
  while(cont<cont_usuarios){
    printf("\t	%d		|",cont);
      printf("\t	%s			\n",personal[cont].nombre);
    cont++;
  }
printf("\t");margen();
getch();

}
void mostrar_aviso(char aviso[]){
  n_adornos=70;
  system("cls");
  printf("\n");margen();
  printf("\t\t\t  Aviso\n" );
  margen();
  printf("%s ",aviso);
  getch();
}
void error_opt(){
system("cls");
printf("\a\n\t\t         #\n");
printf("\t\t        # #\n");
printf("\t\t       #   #\n");
printf("\t\t      #  %c  #\n",178);
printf("\t\t     #   %c   #\n",178);
printf("\t\t    #    %c    #\n",178);
printf("\t\t   #     %c     #\n",220);
printf("\t\t  #             #\n");
printf("\t\t # # # # # # # # #\n\n");
n_adornos=20;
printf("\t\t");margen();
printf("\t\t%c      ERROR      %c\n",176,176);
printf("\t\t");margen();
printf("\t  Usted ingres%c una opci%cn no valida\n",162,162);
printf("\t  Presione un bot%cn cualquiera para \n",162);
printf("\t         regresar al men%c.\n",163);
getch();
}
void error_c(){
system("cls");
printf("\a\n\t\t         #\n");
printf("\t\t        # #\n");
printf("\t\t       #   #\n");
printf("\t\t      #  %c  #\n",178);
printf("\t\t     #   %c   #\n",178);
printf("\t\t    #    %c    #\n",178);
printf("\t\t   #     %c     #\n",220);
printf("\t\t  #             #\n");
printf("\t\t # # # # # # # # #\n\n");
n_adornos=20;
printf("\t\t");margen();
printf("\t\t%c      ERROR      %c\n",176,176);
printf("\t\t");margen();
printf("\t  Usted ingres%c una contrase%ca incorrecta\n",162,164);
printf("\t     Presione un bot%cn cualquiera para\n",162);
printf("\t         regresar al men%c.\n",163);
getch();
}
void menu_ing_jefe(){
system("cls");
n_adornos =38;
printf("\t\t\t");margen();
printf("\t\t\t%c      MEN%c DE OPCIONES             %c\n",176,233,176);
printf("\t\t\t");margen();
printf("\t\t\t%c 1)   A%cadir Productos             %c\n",176,164,176);
printf("\t\t\t%c 2)   A%cadir Usuarios              %c\n",176,164,176);
printf("\t\t\t%c 3)   Ver Datos Ingresados         %c\n",176,176);
printf("\t\t\t%c 4)   Modificar Datos              %c\n",176,176);
printf("\t\t\t%c 5)   Anotar Aviso                 %c\n",176,176);
printf("\t\t\t%c 6)   Ver ventas                   %c\n",176,176);
printf("\t\t\t%c 7)   Habilitar Pago               %c\n",176,176);
printf("\t\t\t%c 8)   Deshabilitar Pago            %c\n",176,176);
printf("\t\t\t%c 9)   Salir                        %c\n",176,176);
printf("\t\t\t");margen();
printf("\t\t\t %c Ingresar Una Opci%cn: ",175,162);
}
void menu_principal() {
system("cls");
n_adornos=38;
printf("\t\t\t");margen();
printf("\t\t\t%c      MEN%c DE OPCIONES             %c\n",176,233,176);
printf("\t\t\t");margen();
printf("\t\t\t%c 1)   Ingresar Como Administrador  %c\n",176,176);
printf("\t\t\t%c 2)   Ingresar Como Empleado       %c\n",176,176);
printf("\t\t\t%c 3)   mostrar personal             %c\n",176,176);
printf("\t\t\t%c 4)   Notas Y Avisos               %c\n",176,176);
printf("\t\t\t%c 5)   Salir                        %c\n",176,176);
printf("\t\t\t");margen();
printf("\t\t\t%c Ingresar Una Opci%cn: ",175,162);
}
void inicializador() {
  n_adornos=47;
	int i,tiempo=8,j;
	for(i=0;i<=tiempo;i++){
	    ADM();
	    printf("\t\t\t             CONTROL ADMINISTRATIVO            \n");
	    printf("\t\t\t                   %c%c            \n",178,177);
	}
	for(i=0;i<=tiempo;i++){
	    ADM();
	    printf("\t\t\t             CONTROL ADMINISTRATIVO            \n");
	    printf("\t\t\t                   %c%c%c%c            \n",178,178,178,177);
	}
	for(i=0;i<=tiempo;i++){
	    ADM();
	    printf("\t\t\t             CONTROL ADMINISTRATIVO            \n");
	    printf("\t\t\t                   %c%c%c%c%c%c            \n",178,178,178,178,178,177);
	}
	for(i=0;i<=tiempo;i++){
		ADM();
	    printf("\t\t\t             CONTROL ADMINISTRATIVO            \n");
	    printf("\t\t\t                   %c%c%c%c%c%c%c%c            \n",178,178,178,178,178,178,178,177);
	}
	for(i=0;i<=tiempo;i++){
		ADM();
	    printf("\t\t\t             CONTROL ADMINISTRATIVO            \n");
	    printf("\t\t\t                   %c%c%c%c%c%c%c%c%c%c            \n",178,178,178,178,178,178,178,178,178,178);
	}
}
void ADM(){
		    system("cls");
	    printf("\t\t\t          *          * * *        * *       ** \n");
	    printf("\t\t\t         * *         *     *      *  *     * * \n");
	    printf("\t\t\t        *   *        *       *    *   *   *  * \n");
	    printf("\t\t\t       *     *       *       *    *     *    * \n");
	    printf("\t\t\t      *********      *       *    *          * \n");
	    printf("\t\t\t     *         *     *     *      *          * \n");
	    printf("\t\t\t    *           *    * * *        *          * \n\n");
}

