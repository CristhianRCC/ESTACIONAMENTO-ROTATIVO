#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

//VARIAVEIS DO ALGORITMO:
char placa [10];
char tipo_veiculo [12];
int tempo_permanencia, preco_hora, preco_pagar, veiculo;

//ENTRADA DE DADOS:
printf ("Informe a placa do veiculo: ");
scanf ("%s", placa);

//Escolhendo o tipo de veiculo e armazenando na variavel tipo_veiculo.
printf ("Informe o tipo do seu veiculo, digite o numero correspondente:\n 1 - Motocicleta\n2 - Carro\n3 - Caminhonete");
scanf ("%d", &veiculo);

//Verifica se o numero digitado pelo usuario é diferente dos dispostos pelo algoritmo com uma condicional para repetir o printf acima.
 if(veiculo < 1 || veiculo > 3){
        printf("Veiculo invalido. Digite novamente:\n");
        scanf("%d", &veiculo);
    }

switch (veiculo)
{
case 1:
    strcpy (tipo_veiculo, "Moto");
    break;
case 2:
    strcpy (tipo_veiculo, "Carro");
    break;
case 3: 
    strcpy (tipo_veiculo, "Caminhonete");
    break;

default:
    printf ("Veiculo invalido.");
}
printf ("Veiculo escolhido: %s", tipo_veiculo);
return 0;
}



  
