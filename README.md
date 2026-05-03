# Estacionamento Rotativo — Sistema de Gerenciamento

Atividade Avaliativa — Laboratório de Programação  
Engenharia da Computação — UFMA  
Prof. Rondineli Seba Salomão

---

## Discentes

| Matrícula | Nome |
|---|---|
| [MATRÍCULA 1] |  [NOME 1]  |
| [220033791] | [Lucas André do Nascimento Nogueira] |
| [MATRÍCULA 3] | [NOME 3] |

---

## Descrição do Problema

Um estacionamento rotativo cobra por tempo de permanência, com valores diferentes para cada tipo de veículo. O sistema recebe a placa, o tipo do veículo e o tempo de permanência, aplica as regras de preço e exibe um comprovante detalhado ao usuário.

---

## Análise do Problema

### Como funciona um estacionamento rotativo na vida real

Em estacionamentos rotativos, o cliente entra com o veículo, registra a entrada e ao sair paga pelo tempo que ficou. O valor cobrado varia conforme o tipo do veículo e o tempo de permanência. Regras especiais podem aplicar descontos para estadias longas ou multas para permanências muito prolongadas.

### Decisões que o sistema precisa tomar

- Qual tipo de veículo está sendo registrado?
- Quanto tempo o veículo ficou?
- O tempo é menor ou igual a 1 hora? (cobra o mínimo)
- O tempo está entre 5h e 10h? (aplica desconto de 10%)
- O tempo passou de 10h? (aplica desconto de 10% e multa de R$20)

---

## Definição das Variáveis

| Nome | Tipo | Finalidade |
|---|---|---|
| `placa` | `char[10]` | Armazena a placa do veículo |
| `tipo_veiculo` | `char[12]` | Armazena o nome do tipo do veículo (Moto, Carro, Caminhonete) |
| `veiculo` | `int` | Número digitado pelo usuário para escolher o tipo |
| `horas` | `int` | Horas de permanência informadas pelo usuário |
| `minutos` | `int` | Minutos de permanência informados pelo usuário |
| `preco_hora` | `int` | Preço por hora conforme o tipo do veículo |
| `desconto` | `int` | Percentual de desconto aplicado (0 ou 10) |
| `tempo_permanencia` | `float` | Tempo total em horas (horas + minutos/60) |
| `preco_pagar` | `float` | Valor final a pagar após regras aplicadas |
| `preco_base` | `float` | Valor sem desconto ou multa, exibido no comprovante |
| `multa` | `float` | Valor da multa (R$20 se tempo > 10h, senão 0) |

---

## Regras de Negócio

### Tabela de preços por tipo de veículo

| Tipo | Preço por hora |
|---|---|
| Moto | R$ 3,00 |
| Carro | R$ 5,00 |
| Caminhonete | R$ 8,00 |

### Regras de tempo

- **Até 1 hora:** cobra o valor de 1 hora cheia (valor mínimo)
- **Entre 1h e 5h:** cobra normalmente pelo tempo (sem desconto ou multa)
- **Acima de 5h até 10h:** aplica desconto de 10% sobre o valor total
- **Acima de 10h:** aplica desconto de 10% sobre o valor do tempo e soma multa de R$20

> O desconto é calculado sobre o valor do tempo, e a multa é somada depois.

---

## Fluxograma

![Fluxograma do sistema]

---

## Explicação da Lógica

O programa segue três etapas principais:

**Entrada:** lê a placa, o tipo do veículo (com validação de até 3 tentativas) e o tempo de permanência no formato `HH:MM`.

**Processamento:** calcula o tempo em horas decimais, determina o valor base e aplica as regras de desconto e multa usando estruturas `if/else if`. O tipo do veículo e seu preço por hora são definidos via `switch-case`.

**Saída:** exibe o comprovante com placa, tipo, tempo, valor base, desconto (se houver), multa (se houver) e valor final.

---

## Como Compilar e Executar

### Requisitos

- Compilador GCC instalado (Linux/Mac) ou MinGW (Windows)

### Compilar

```bash
gcc main.c -o estacionamento
```

### Executar

```bash
./estacionamento
```

No Windows:

```bash
estacionamento.exe
```

---

## Exemplo de Entrada e Saída

### Exemplo 1 — Carro por 3 horas (sem desconto)

**Entrada:**
```
Placa: ABC1234
Tipo: 2 (Carro)
Tempo: 03:00
```

**Saída:**
```
============COMPROVANTE============
Placa do veiculo: ABC1234
Tipo de veiculo: Carro
Tempo de permanencia.....3:00
Valor base.....R$15.00
Valor final.....R$15.00
```

---

### Exemplo 2 — Moto por 6 horas (com desconto)

**Entrada:**
```
Placa: XYZ9999
Tipo: 1 (Moto)
Tempo: 06:00
```

**Saída:**
```
============COMPROVANTE============
Placa do veiculo: XYZ9999
Tipo de veiculo: Moto
Tempo de permanencia.....6:00
Valor base.....R$18.00
Desconto (10%).....R$1.80
Valor final.....R$16.20
```

---

### Exemplo 3 — Caminhonete por 12 horas (desconto + multa)

**Entrada:**
```
Placa: DEF5678
Tipo: 3 (Caminhonete)
Tempo: 12:00
```

**Saída:**
```
============COMPROVANTE============
Placa do veiculo: DEF5678
Tipo de veiculo: Caminhonete
Tempo de permanencia.....12:00
Valor base.....R$96.00
Desconto (10%).....R$9.60
Multa adicional.....R$20.00
Valor final.....R$106.40
```

---

## Estrutura do Repositório

```
ESTACIONAMENTO-ROTATIVO/
├── main.c
├── README.md
└── fluxograma.png
```
