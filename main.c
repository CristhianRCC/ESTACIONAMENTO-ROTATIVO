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
 float preco_base, multa = 0;

 //ENTRADA DE DADOS:
 printf ("============ESTACIONAMENTO TITAN============\n");
 printf ("\nInforme a placa do veiculo: ");
 scanf ("%s", placa);

 //Escolhendo o tipo de veiculo e armazenando na variavel tipo_veiculo.
 printf ("\nInforme o tipo do seu veiculo, digite o numero correspondente.\n");
 printf ("1 - Motocicleta\n");
 printf ("2 - Carro\n");
 printf ("3 - Caminhonete\n");
 printf ("Opcao desejada: ");
 scanf ("%d", &veiculo);

 //Le se o numero digitado pelo usuario e diferente dos dispostos pelo algoritmo.
 if (veiculo < 1 || veiculo > 3) {
     printf("Veiculo invalido. Digite novamente:\n");
     scanf("%d", &veiculo);
 }
 if (veiculo < 1 || veiculo > 3) {
     printf("Veiculo invalido. Digite novamente:\n");
     scanf("%d", &veiculo);
 }
 if (veiculo < 1 || veiculo > 3) {
     printf("Entrada invalida. Encerrando o programa.\n");
     return 1;
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

 //Le o tempo de permanencia no estacionamento.
 printf ("Informe o tempo de permanencia (XX:YY):\n");
 scanf ("%d:%d", &horas, &minutos);

 //PROCESSAMENTO:
 tempo_permanencia = horas + (minutos/60.0);
 preco_pagar = (preco_hora * tempo_permanencia);
 preco_base = preco_pagar;

 if (tempo_permanencia <= 1) {
     preco_pagar = preco_hora;
     preco_base = preco_hora; //Valor minimo: cobra 1 hora cheia.
 }
 else if (tempo_permanencia > 5 && tempo_permanencia <= 10) {
     desconto = 10;
     preco_pagar = preco_pagar - (preco_pagar * 0.10); //Desconto de 10%.
 }
 else if (tempo_permanencia > 10) {
     desconto = 10;
     multa = 20;
     // Desconto aplicado sobre o valor do tempo, multa somada ao final.
     preco_pagar = preco_pagar - (preco_pagar * 0.10) + multa;
 }

 //SAIDA DE DADOS:
 printf ("\n============COMPROVANTE============");
 printf ("\nPlaca do veiculo: %s", placa);
 printf ("\nTipo de veiculo: %s", tipo_veiculo);
 printf ("\nTempo de permanencia.....%d:%02d", horas, minutos);
 printf ("\nValor base.....R$%.2f", preco_base);

 if (desconto > 0) {
     printf("\nDesconto (10%%).....R$%.2f", preco_base * 0.10);
 }
 if (multa > 0) {
     printf("\nMulta adicional.....R$%.2f", multa);
 }
 printf("\nValor final.....R$%.2f", preco_pagar);

 return 0;
}
