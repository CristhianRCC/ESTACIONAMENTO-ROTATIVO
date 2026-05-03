#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

//VARIAVEIS DO ALGORITMO:
char placa [10];
char tipo_veiculo [12];
int minutos, horas, preco_hora, veiculo;
int desconto = 0; 
float tempo_permanencia, preco_pagar;

//ENTRADA DE DADOS:
printf ("Informe a placa do veiculo: ");
scanf ("%s", placa);

//Escolhendo o tipo de veiculo e armazenando na variavel tipo_veiculo.
printf ("\nInforme o tipo do seu veiculo, digite o numero correspondente.\n");
printf ("1 - Motocicleta\n");
printf ("2 - Carro\n");
printf ("3 - Caminhonete\n");
printf ("Opcao desejada: ");
scanf ("%d", &veiculo);

//Lê se o numero digitado pelo usuario é diferente dos dispostos pelo algoritmo com uma condicional para repetir o printf acima.
 if(veiculo < 1 || veiculo > 3){
        printf("Veiculo invalido. Digite novamente:\n");
        scanf("%d", &veiculo);
    }

switch (veiculo)
{
case 1:
    strcpy (tipo_veiculo, "Moto");
    preco_hora = 3;
    break;
case 2:
    strcpy (tipo_veiculo, "Carro");
    preco_hora = 5;
    break;
case 3: 
    strcpy (tipo_veiculo, "Caminhonete");
    preco_hora = 8;
    break;
default:
    printf ("Veiculo invalido.");
}

//Lê o tempo de permanência no estacionamento em horas inteiras.
printf ("Informe o tempo de permanencia (XX:YY):\n");
scanf ("%d:%d", &horas, &minutos);

//PROCESSAMENTO:
tempo_permanencia = horas + (minutos/60.0);
preco_pagar = (preco_hora * tempo_permanencia);

if (tempo_permanencia <= 1){
    preco_pagar = preco_hora; //Valor base a ser pago, ou seja, a hora cobrada se menor que 1.
}
else if (tempo_permanencia > 5 && tempo_permanencia <= 10){
    desconto = 10;
    preco_pagar = preco_pagar - (preco_pagar * 0.10); //Calcula o valor com 10% de desconto.
}
else if (tempo_permanencia > 10){
    desconto = 10;
    preco_pagar = preco_pagar + 20 - (preco_pagar * 0.10); //Calcula 10% de desconto + multa.
}

//SAÍDA DE DADOS:
printf ("\n============ COMPROVANTE ============");
printf ("\nPlaca do veículo: %s", placa);
printf ("\nTipo de veículo: %s", tipo_veiculo);
printf ("\nTempo de permanência.....%d:%d", horas, minutos);
printf ("\nValor a pagar.....R$%.2f", preco_pagar);
printf ("\nDesconto sobre o valor.....%d%%", desconto);

return 0;
}