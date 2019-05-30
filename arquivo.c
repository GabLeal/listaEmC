#include <stdio.h>
#include <stdlib.h>

#define p1 5
#define p2 3
#define p3 2
//FUNÇÔES


//Segundo exercicio
int segundo_exercicio(int num1, int num2){
    int maior,menor,soma = 0;

    if(num1 > num2){
        maior = num1;
        menor = num2;
    }else{
        maior = num2;
        menor = num1;
    }

    for(int i = menor + 1; i < maior; i++){
        soma += i;
    }

    return soma;
}


//Terceiro exercicio

float media(float a, float b, float c, char letra){

    if(letra== 'a'){
        float ma = (a+b+c)/3;
        return ma;
    }else{
        float mp = (a*p1+b*p2+c*p3)/(p1+p2+p3);
        return mp;
    }

}

int main (){
    //VARIAVEIS GLOBAIS
    int opc_menu;
    float a,b,c;
    float teste;
    char letra;

    do{
        printf("Menu \n");
        printf("Escolha um exercicio entre 1 e 8: ");
        scanf("%d",&opc_menu);

        switch (opc_menu){
            case 2:
                printf("1° numero: ");
                scanf("%f",&a);
                printf("2° numero: ");
                scanf("%f",&b);
                teste = segundo_exercicio(a,b);
                printf("%f",teste);
            break;

            case 3:
                printf("1° nota: ");
                scanf("%f",&a);
                printf("2° nota: ");
                scanf("%f",&b);
                printf("3° nota: ");
                scanf("%f",&c);

                do{
                    printf("a ou p");
                    scanf(" %c",&letra);
                }while(letra != 'a' && letra != 'p');

                printf("A media desejada é : %0.2f ",media(a, b, c ,letra));
            break;


        }

    }while( opc_menu < 1 || opc_menu >8);

    return 0;
}