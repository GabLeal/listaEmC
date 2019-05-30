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

//QUARTO exercicio
//Crie uma função que receba como parâmetro dois vetores de dez elementos inteiros
//positivos e mostre o vetor união desses dois vetores.
void ler_vetor(int vetor[]){

    for(int i = 0; i < 10; i++){
        printf("%d º valor: ",i+1);
        scanf("%d",&vetor[i]);
    }
}
void uniao_de_vetores(int *v1, int *v2){

    int comparar = 0, cont = 10;
    int uniao[20];

    printf("A união dos dois vetores é: \n");

    for (int i = 0; i < 10; i++){
        uniao[i] = v1[i];
    }

    for (int i = 0; i < 10; i++){
        for (int j  = 0; j < cont; j++){
           if (v2[i]==uniao[j]){
              comparar++;
           }
           
        }
        if (comparar==0){
            uniao[cont] = v2[i];
            cont++;
        }

        comparar = 0;
        
    }

    for ( int i = 0; i < cont; i++){
        printf("%d ",uniao[i]);
    }
    

    
 
}

int main (){
    //VARIAVEIS GLOBAIS
    int opc_menu;
    float a,b,c;
    float teste;
    char letra;
    int  vetor1[10],vetor2[10];   

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
                    printf(" (a) media simples (p) media ponderada");
                    scanf(" %c",&letra);
                }while(letra != 'a' && letra != 'p');

                printf("A media desejada é : %0.2f ",media(a, b, c ,letra));
            break;

            case 4:
                ler_vetor(vetor1);
                ler_vetor(vetor2);
                uniao_de_vetores(vetor1,vetor2);
            break;


        }

    }while( opc_menu < 1 || opc_menu >8);

    return 0;
}