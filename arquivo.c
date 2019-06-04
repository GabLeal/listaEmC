#include <stdio.h>
#include <stdlib.h>

#define p1 5
#define p2 3
#define p3 2
#define linha_matriz 5
#define coluna_matriz 5
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


//Faça uma função que receba como parâmetro um vetor A com cinco números reais
//e retorne esses números ordenados de forma crescente.
//QUINTO exercicio
int *vetor_ordemCrescente(int *vetor){
    int valor_maior;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (vetor[i] > vetor[j]){
                valor_maior = vetor[i];

                vetor[i] = vetor[j];
                vetor[j] = valor_maior;


            }
            
        }
        
    }
    
    return vetor;
}


//Faça uma função que receba como parâmetro uma matriz A(5,5) e retorne a soma
//de seus elementos.
int soma_matriz(int matriz[][coluna_matriz]){
                int soma = 0;
                for (int i = 0; i < linha_matriz; i++){
                    for(int j = 0; j< coluna_matriz; j++){
                        printf("Preencha a matriz na poosição (%d,%d) ",i,j);
                        scanf("%d",&matriz[i][j]);
                        //arrumar o codigo depois
                        if (i == 0 && j ==0)
                        {
                            soma = matriz[i][j];
                        }else{
                            soma += matriz[i][j];
                        }
                    }                    
                }

                return soma;
}


//exercicio 8 - trinagulo
int tipo_triangulo(int a, int b, int c){
    if ( a == b && b == c){
        return 0;    
    }else{
        if (a == b && b != c){
            return 1;
        }else{
            return 2;
        }
    }

    
}

void existencia_triangulo(int a, int b, int c){
//a medida de um lado qualquer deve ser inferior ou igual à soma das medidas dos outros dois).
    if (a <= b+c && b<= a+c && c<= a+b){
       int triangulo = tipo_triangulo(a,b,c);
       if(triangulo == 0){
           printf("O triangulo é equilatero");
       }else{
           if (triangulo == 1){
               printf("O trinagulo é isósceles");
           }else{
               printf("o triangulo é escaleno");
           }
           
       }
    }else{
        printf("Para as medidas inseridas NÃO é possivel formar nenhum triangulo!");
    }
}

int verificarMedidas(){
    int a,b,c;
    printf("Digite o valor do lado A do triangulo: ");
    scanf("%d",&a);
    printf("Digite o valor do lado B do triangulo: ");
    scanf("%d",&b);
    printf("Digite o valor do lado C do triangulo: ");
    scanf("%d",&c);

    if (a >0 && b> 0 && c >0){
        existencia_triangulo(a,b,c);
        return 0;
    }else{
        return 1;
    }
    
}

int main (){
    //VARIAVEIS GLOBAIS
    int opc_menu;
    float a,b,c;
    float teste;
    char letra;
    int  vetor1[10],vetor2[10],ordem_crescente[5];  
    int matriz[linha_matriz][coluna_matriz]; 

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
                printf("%0.2f",teste);
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

            case 5:
                for (int i = 0; i < 5; i++){
                    printf("%d º valor do vetor: ",i+1);
                    scanf("%d",&ordem_crescente[i]);
                }
                vetor_ordemCrescente(ordem_crescente);
                //int teste [] = vetor_ordemCrescente(ordem_crescente);
                printf("Mostrando o vetor preenchido na ordem crescente: ");
                for (int i = 5; i > 0; i--){
                    printf("%d ",ordem_crescente[i-1]);
                }

                //REVER A LOGICA DEPOIS
            break;

            case 6:
     
                printf("A soma de todos os elementos da matriz é igual à: %d",soma_matriz(matriz));
            break;

            case  8:

                do{
                    printf("Digite as medidas dos lados do triangulo. Todas elas devem ser maiores que 0. \n");
                    a = verificarMedidas();
                    if (a != 0){
                        printf("Ops! Verifique as medidas, pode ser que alguma esteja com valores igual ou menores que 0 \n");
                        printf("Vamos lá, digite novamente \n");
                    }
                }while(a!=0);
            break;

        }

    }while( opc_menu < 1 || opc_menu >8);

    return 0;
}