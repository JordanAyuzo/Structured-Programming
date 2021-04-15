//NOMBRE DEL ESTUDIANTE: JORDAN AYUZO PACHECO
//GRUPO 102-A
//PROGRAMA DE UN CONTROL ADMINISTRATIVO
#include <stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define USUARIOS 500
#define NOMBRES 100
#define PRODUCTOS 500
#define PALABRAS 250
#define VENTAS 800

int n_adornos,cont_producto=0,cont_usuarios=0,cont_vend=0,auxiliar=0;
void margen();
void menu_principal();
void menu_ing_jefe();
void error_opt();
void error_c();
void ADM();
void inicializador();
void inicio(int cont_jefe1[2],char nom_jefe1[NOMBRES],int clave_venta1[2]);
void principal(int *opt1,int cont_jefe_aux[2],char nom_jefe_aux[NOMBRES], int clave_venta_aux[2],int realizado[USUARIOS],int *token1);
void ing_jefe(int cont_jefe2[2],char nom_jefe2[NOMBRES],int clave_venta2[2],
  char nom_producto_aux[PRODUCTOS][NOMBRES],float precio_producto_aux[PRODUCTOS],int cant_producto_aux[PRODUCTOS],
  char nom_trabajadores[USUARIOS][NOMBRES],int cont_trabajadores[USUARIOS],float pago_tabajadores[USUARIOS],char aviso[PALABRAS],int realizado[USUARIOS],int *token_aux,int cant_venta_aux[VENTAS],int venta_codi_aux[VENTAS]);
void ingresar_producto(char nom_producto1[PRODUCTOS][NOMBRES],int cant_producto1[PRODUCTOS],
  float precio_producto1[PRODUCTOS]);
void ingresar_trabajador(char nom_trabajadores1[USUARIOS][NOMBRES],int cont_trabajadores1[USUARIOS],float pago_tabajadores1[USUARIOS]);
void mostrar(char nom_producto2[PRODUCTOS][NOMBRES],int cant_producto2[PRODUCTOS],float precio_producto2[PRODUCTOS],char nom_trabajadores2[USUARIOS][NOMBRES],int cont_trabajadores2[USUARIOS],float pago_tabajadores2[USUARIOS]);
void mod_producto(char nom_producto3[PRODUCTOS][NOMBRES],int cant_producto3[PRODUCTOS],float precio_producto3[PRODUCTOS]);
void anotar_aviso(char aviso_aux[PALABRAS]);
void ver_ventas(int cant_venta1[VENTAS],int venta_codi1[VENTAS],char nom_producto4[PRODUCTOS][NOMBRES],float precio_producto4[PRODUCTOS]);
void ing_trabajador(int clave_venta3[2],char nom_producto5[PRODUCTOS][NOMBRES],float precio_producto5[PRODUCTOS],int cant_producto5[PRODUCTOS],char nom_trabajadores3[USUARIOS][NOMBRES],int cont_trabajadores3[USUARIOS],float pago_trabajadores3[USUARIOS],char aviso[PALABRAS],int realizado[USUARIOS],int *token2,int cant_venta2[VENTAS],int venta_codi2[VENTAS]);
void mostrar_producto(char nom_producto51[PRODUCTOS][NOMBRES],int cant_producto51[PRODUCTOS],float precio_producto51[PRODUCTOS]);
void vender_producto(int clave_venta31[2],char nom_producto52[PRODUCTOS][NOMBRES],int cant_producto5[PRODUCTOS],float precio_producto[PRODUCTOS],int cant_venta21[VENTAS],int venta_codi21[VENTAS]);
void cambiar_contra(int cont_trabajadores4[USUARIOS],int *clave1);
void pago_tabajadores(char nom_trabajadores31[USUARIOS][NOMBRES],float pago_trabajadores31[USUARIOS],int *clave2);
void mostrar_personal_public(char nom_trabajadores_public[USUARIOS][NOMBRES]);
void mostrar_aviso(char aviso[PALABRAS]);
//funciones
int main() {
//system ("color 0B");
char nom_jefe[NOMBRES];
int cont_jefe[2],clave_venta[2],realizado[USUARIOS];
int contador=0,opt=0,token=1;
//SE FINALIZA LAS VARIABLES
while (opt != 5){
  if(contador==0){
    inicializador();
    inicio(cont_jefe,nom_jefe,clave_venta);
    contador++;
  }
  principal(&opt,cont_jefe,nom_jefe,clave_venta,realizado,&token);
}
return 0;
}
void margen(){
int i;
for(i=1;i<n_adornos;i++)
  printf("%c",176 );
printf("\n");
}
void inicio(int cont_jefe1[2],char nom_jefe1[NOMBRES],int clave_venta1[2]){
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
printf("\t\t %c Presione Cualquier Bot%cn Para Guardar Datos.\n",175,162);
printf("\t\t");margen();
printf("\t\t");margen();printf("\t\t");
getch();
}
void principal(int *opt1,int cont_jefe_aux[2],char nom_jefe_aux[NOMBRES], int clave_venta_aux[2],int realizado[USUARIOS],int *token1){
char nom_producto[PRODUCTOS][NOMBRES],nom_trabajadores[USUARIOS][NOMBRES],aviso[PALABRAS];
int cant_producto[PRODUCTOS],cont_trabajadores[USUARIOS],cant_venta[VENTAS],venta_codi[VENTAS];
float pago_trabajadores[USUARIOS],precio_producto[PRODUCTOS];
menu_principal();
scanf("%d",&*opt1 );
switch (*opt1) {
  case 1:
    ing_jefe(cont_jefe_aux,nom_jefe_aux,clave_venta_aux,nom_producto,precio_producto,cant_producto,nom_trabajadores,cont_trabajadores,pago_trabajadores,aviso,realizado,&*token1,cant_venta,venta_codi);
    break;
  case 2:
    ing_trabajador(clave_venta_aux,nom_producto,precio_producto,cant_producto,nom_trabajadores,cont_trabajadores,pago_trabajadores,aviso,realizado,&*token1,cant_venta,venta_codi);
    break;
  case 3:
    mostrar_personal_public(nom_trabajadores);
    break;
  case 4:
    mostrar_aviso(aviso);
    break;
  case 5:
    break;
}
}
void ing_jefe(int cont_jefe2[2],char nom_jefe2[NOMBRES],int clave_venta2[2],char nom_producto_aux[PRODUCTOS][NOMBRES],  float precio_producto_aux[PRODUCTOS],int cant_producto_aux[PRODUCTOS],char nom_trabajadores_aux[USUARIOS][NOMBRES],int cont_trabajadores_aux[USUARIOS],float pago_tabajadores_aux[USUARIOS],char aviso[PALABRAS],int realizado[USUARIOS],int *token_aux,int cant_venta_aux[VENTAS],int venta_codi_aux[VENTAS] ){
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
            ingresar_producto(nom_producto_aux,cant_producto_aux,precio_producto_aux);
          break;
        case 2:
        	ingresar_trabajador(nom_trabajadores_aux,cont_trabajadores_aux,pago_tabajadores_aux);
          break;
        case 3:
          mostrar(nom_producto_aux,cant_producto_aux,precio_producto_aux,nom_trabajadores_aux,cont_trabajadores_aux,pago_tabajadores_aux);
          break;
        case 4:
          mod_producto(nom_producto_aux,cant_producto_aux,precio_producto_aux);
          break;
        case 5:
          anotar_aviso(aviso);
          break;
        case 6:
          ver_ventas(cant_venta_aux,venta_codi_aux,nom_producto_aux,precio_producto_aux);
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
void ingresar_producto(char nom_producto1[PRODUCTOS][NOMBRES],int cant_producto1[PRODUCTOS],float precio_producto1[PRODUCTOS]){
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
        printf("\t\t");margen();
        printf("\t\t%c Producto: ",175);
        getchar();
        gets(nom_producto1[cont_producto]);
        printf("\t\tCantidad: ");
        scanf("%d",&cant_producto1[cont_producto]);
        printf("\t\tPrecio: $");
        scanf("%f",&precio_producto1[cont_producto]);
        printf("\t\t");margen();
        printf("\t\t");margen();
        cont_producto++;
        printf("\t\tIngresa 1 Para Guardar Productos o 2 Para Salir: ");
        scanf("%d",&opt2);
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
      for(i=1;i<=n_producto;i++){
        printf("\t\t%c Producto: ",175);
        gets(nom_producto1[cont_producto]);
        printf("\t\tCantidad: ");
        scanf("%d",&cant_producto1[cont_producto]);
        printf("\t\tPrecio: $");
        scanf("%f",&precio_producto1[cont_producto]);
        fflush(stdin);
        cont_producto++;
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
void ingresar_trabajador(char nom_trabajadores1[USUARIOS][NOMBRES],int cont_trabajadores1[USUARIOS],float pago_tabajadores1[USUARIOS]){
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
          n_adornos=50;
          printf("\t\t");margen();
          printf("\t\t%c Empleado: ",175);
          getchar();
          gets(nom_trabajadores1[cont_usuarios]);
          printf("\t\t Contrase%ca: ",164);
          scanf("%d",&cont_trabajadores1[cont_usuarios]);
          printf("\t\t Salario: %c",36);
          scanf("%f",&pago_tabajadores1[cont_usuarios]);
          fflush(stdin);
          printf("\t\t");margen();
          cont_usuarios++;
          printf("\t\tIngresa 1 Para Guardar Productos o 2 Para Salir: ");
          scanf("%d",&opt2);
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
        for(i=1;i<=n_trabajador;i++){
          printf("\t\t%c Empleado: ",175);
          gets(nom_trabajadores1[cont_usuarios]);
          printf("\t\t Contrase%ca: ",164);
          scanf("%d",&cont_trabajadores1[cont_usuarios]);
          printf("\t\t Salario: %c",36);
          scanf("%f",&pago_tabajadores1[cont_usuarios]);
          fflush(stdin);
          cont_usuarios++;
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
void mostrar(char nom_producto2[PRODUCTOS][NOMBRES],int cant_producto2[PRODUCTOS],float precio_producto2[PRODUCTOS],char nom_trabajadores2[USUARIOS][NOMBRES],int cont_trabajadores2[USUARIOS],float pago_tabajadores2[USUARIOS]){
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
          printf(" %d  	",cant_producto2[cont]);
          printf("	 	$%.2f  	",precio_producto2[cont]);
          printf("   %s\n",nom_producto2[cont]);
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
        printf("	%d		|",cont_trabajadores2[cont]);
        printf("	%.2f		|",pago_tabajadores2[cont]);
          printf("	%s			\n",nom_trabajadores2[cont]);
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
void mod_producto(char nom_producto3[PRODUCTOS][NOMBRES],int cant_producto3[PRODUCTOS],float precio_producto3[PRODUCTOS]){
  int codi,opt;
  system ("cls");
	n_adornos=74;
	printf("\t\t");margen();
	printf("\t\t%c Clave Del Producto que desea modificar: ",175);
	scanf("%d",&codi);
	system ("cls");
	printf("\t\t");margen();
	getchar();
	printf("\t\t\tProducto: %s\n",nom_producto3[codi]);
	printf("\t\t\tprecio:  %.2f \n",precio_producto3[codi]);
	printf("\t\t\tCantidad %d \n",cant_producto3[codi]);
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
			gets(nom_producto3[codi]);
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
			scanf("%d",&cant_producto3[codi]);
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
			scanf("%f",&precio_producto3[codi]);
      printf("\t\t%c Ingrese Nuevo Precio: ",175);
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
void anotar_aviso(char aviso_aux[PALABRAS]){
  n_adornos=100;
  system("cls");
  margen();
  printf("\t\t Escribe el Aviso\n\t\t");
  getchar();
  gets(aviso_aux);
}
void ver_ventas(int cant_venta1[VENTAS],int venta_codi1[VENTAS],char nom_producto4[PRODUCTOS][NOMBRES],float precio_producto4[PRODUCTOS]){
  int i;
  float tot1;
  if (cont_vend!=0){
  	for(i=0;i<=cont_vend;i++){
  		system("cls");
  		n_adornos=85;
  		margen();
  		printf("	CANTIDAD	|	PRECIO. U	|	TOTAL	|	PRODUCTO\n");
  		margen();
  		printf("	%d		",cant_venta1[i]);
  		printf(" 	$%.2f 	",precio_producto4[venta_codi1[i]]);
  		tot1=(float)cant_venta1[i]*precio_producto4[venta_codi1[i]];
  		printf("   $%.2f	 ",tot1);
  	  printf("   %s\n",nom_producto4[venta_codi1[i]]);
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
void ing_trabajador(int clave_venta3[2],char nom_producto5[PRODUCTOS][NOMBRES],float precio_producto5[PRODUCTOS],int cant_producto5[PRODUCTOS],char nom_trabajadores3[USUARIOS][NOMBRES],int cont_trabajadores3[USUARIOS],float pago_trabajadores3[USUARIOS],char aviso[PALABRAS],int realizado[USUARIOS],int *token2,int cant_venta2[VENTAS],int venta_codi2[VENTAS]){
  int clave=0,contrasena,opt;
  do{
    system("cls");
    n_adornos=50;
    printf("\t\t");margen();
    printf("\t\t%c CLAVE DEL EMPLEADO: ",175);
    scanf("%d",&clave);
    system("cls");
    printf("\t\t");margen();
    printf("\t\tNombre: %s    (-1 para salir)\n",nom_trabajadores3[clave]);
    printf("\t\t");margen();
    printf("\t\tIngresar contrase%ca: ",164);
    scanf("%d",&contrasena);
    if(contrasena==cont_trabajadores3[clave]){
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
                    mostrar_producto(nom_producto5,cant_producto5,precio_producto5);
                    break;
                case 2:
                    vender_producto(clave_venta3,nom_producto5,cant_producto5,precio_producto5,cant_venta2,venta_codi2);
                    break;
                case 3:
                  cambiar_contra(cont_trabajadores3,&clave);
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
                    mostrar_producto(nom_producto5,cant_producto5,precio_producto5);
                    break;
                case 2:
                    vender_producto(clave_venta3,nom_producto5,cant_producto5,precio_producto5,cant_venta2,venta_codi2);
                    break;
                case 3:
                  cambiar_contra(cont_trabajadores3,&clave);
                  break;
                case 4:
                    if(realizado[clave]==1)	{
                    pago_tabajadores(nom_trabajadores3,pago_trabajadores3,&clave);
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
  }while(contrasena != cont_trabajadores3[clave] && contrasena !=-1);
}
void mostrar_producto(char nom_producto51[PRODUCTOS][NOMBRES],int cant_producto51[PRODUCTOS],float precio_producto51[PRODUCTOS]){
  system("cls");
  int cont=0;
  n_adornos=85;
  margen();
  printf("	CLAVE	|	CANTIDAD	|	PRECIO	|	PRODUCTO\n");
  margen();
  while(cont<=cont_producto-1){
    printf("	%d		",cont);
    printf(" %d  	",cant_producto51[cont]);
    printf("	 	$%.2f  	",precio_producto51[cont]);
      printf("   %s\n",nom_producto51[cont]);
    cont++;
  }
  margen();
  getch();

}
void vender_producto(int clave_venta31[2],char nom_producto52[PRODUCTOS][NOMBRES],int cant_producto52[PRODUCTOS],float precio_producto52[PRODUCTOS],int cant_venta21[VENTAS],int venta_codi21[VENTAS]){
  int codi = 0,vendido=0;
  system("cls");
  n_adornos=50;
  printf("\t\t");margen();
  printf("\t\tEscriba el codigo del producto: ");
  scanf("%d",&codi);
  system("cls");
  n_adornos=37;
  printf("\t\t");margen();
  printf("\t\tProducto: %s\n",nom_producto52[codi]);
  printf("\t\tCantidad: %d\n",cant_producto52[codi]);
  printf("\t\tPrecio: %.2f\n",precio_producto52[codi]);
  printf("\t\t");margen();
  printf("\t\t PRODUCTOS A VENDER: ");
  scanf("%d",&vendido);
  system ("cls");
  n_adornos=60;
  printf("\t\t");margen();
  float tot = (float)vendido*precio_producto52[codi];
  printf("\t\t cantidad a pagar %.2f\n",tot);
  printf("\t\t NOTA: Si no desea generar la compra ingresar cualquier valor\n",164);
  printf("\t\t Escriba la clave de Permiso para continuar: ",164);
  scanf("%d",&clave_venta31[1]);
      if(clave_venta31[0]==clave_venta31[1]){
        if(vendido>cant_producto52[codi]){
          system("cls");
          n_adornos=32;
          printf("\t\t");margen();
          printf("\t\t No Hay La Cantidad Suficiente \n");
          getch();
        }
        else{
          system("cls");
          cant_producto52[codi]-=vendido;
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
void cambiar_contra(int cont_trabajadores4[USUARIOS],int *clave1){
  system("cls");
  n_adornos=70;
	printf("\t\t");margen();
  printf("\t\t Ingrese una nueva contrase%ca ",164);
	scanf("%d",&cont_trabajadores4[*clave1]);
  system("cls");
  n_adornos=70;
	printf("\t\t");margen();
  printf("\t\t Contrase%ca modificada\n",164);
  printf("\t\t Nueva Contrase%ca %d \n",164,cont_trabajadores4[*clave1]);
	getch();

}
void pago_tabajadores(char nom_trabajadores31[USUARIOS][NOMBRES],float pago_trabajadores31[USUARIOS],int *clave2){
  system("cls");
	int part1=260,part2;
	srand(time(NULL));
	part2=1+rand()%99;
	n_adornos=85;
	printf("\t\t");margen();
	printf("\t\t Hola %s \n",nom_trabajadores31[*clave2]);
	printf("\t\t tu sueldo es de  $%.2f \n",pago_trabajadores31[*clave2]);
	printf("\t\tPasa a ventanilla con este numero de clave: \n");
	printf("\t\t\t %c  00975%d%d %c\n",175,part1,part2,174);
	getch();
}
void mostrar_personal_public(char nom_trabajadores_public[USUARIOS][NOMBRES]){
  system("cls");
  int cont=0;
  n_adornos=60;
  printf("\n\t");margen();
  printf("\t	CLAVE		|	TRABAJADOR	\n");
  printf("\t");margen();
  while(cont<cont_usuarios){
    printf("\t	%d		|",cont);
      printf("\t	%s			\n",nom_trabajadores_public[cont]);
    cont++;
  }
printf("\t");margen();
getch();

}
void mostrar_aviso(char aviso[PALABRAS]){
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
printf("\t\t\t%c 3)   Ver Datos Ingresados         %c\n",176,176,176);
printf("\t\t\t%c 4)   Modificar Producto           %c\n",176,176,176);
printf("\t\t\t%c 5)   Anotar Aviso                 %c\n",176,176,176);
printf("\t\t\t%c 6)   Ver ventas                   %c\n",176,176,176);
printf("\t\t\t%c 7)   Habilitar Pago               %c\n",176,176,176);
printf("\t\t\t%c 8)   Deshabilitar Pago            %c\n",176,176,176);
printf("\t\t\t%c 9)   Salir                        %c\n",176,176,176);
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
	int i,tiempo=3,j;
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
