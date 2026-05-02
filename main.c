#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

//VARIAVEIS DO ALGORITMO:
char placa [10];
char tipo_veiculo [12];
int preco_hora, veiculo;
int minutos, horas;
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
printf ("O horario que voce escolheu %.2d:%.2d", horas, minutos);

//PROCESSAMENTO:
tempo_permanencia = horas + (minutos/60.0);
preco_pagar = (preco_hora * tempo_permanencia);

//Calcula o valor mínimo a ser pago, somente para os veículos com tempo_permanência entre 0 e 5 horas.
if (tempo_permanencia >= 0 && tempo_permanencia <= 5){
    preco_pagar = (preco_hora * tempo_permanencia);
}
else if (tempo_permanencia > 5)
printf ("\n%.2f", tempo_permanencia);
printf ("\n%.2f", preco_pagar);
return 0;
}