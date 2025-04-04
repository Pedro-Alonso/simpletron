/*
Simpletron - Trabalho do semestre da matéria de Linguagens de Programação
Curso - Ciência da Computação
Discente - Pedro Alonso Oliveira dos Santos
Docente - prof. Dr. Rogério Eduardo Garcia
Universidade Estadual Paulista "Júlio de Mesquita Filho" - UNESP
2024 - FCT UNESP

As instruções não citadas no enunciado inicial do livro Como programar Em C (DEITEL & DEITEL, 1992) estão com comentários explicativos na implementação. Estas são: EXPONENTIATION, INCREMENT, DECREMENT, ZERO e MODULO.
Os arquivos .txt citados no programa precisam estar na pasta raiz do projeto para funcionar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define READ 10
#define WRITE 11

#define LOAD 20
#define STORE 21

#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define EXPONENTIATION 34
#define INCREMENT 35
#define DECREMENT 36
#define ZERO 37
#define MODULO 38

#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

#define MEMORY_SIZE 100

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int
        memory[MEMORY_SIZE] = {0},
        accumulator = +0000,         // Acumulador
        instructionCounter = 00,     // Local de memória que contém a instrução que está sendo executada
        instructionRegister = +0000, // Local temporário para armazenar a instrução que está sendo executada
        operationCode = 00,          // Código da operação (dois primeiros dígitos da instrução)
        operand = 00,                // Operando (dois últimos dígitos da instrução)
        i = 0,
        option;

    printf("\t*** Bem-vindo ao Simpletron! ***\n"
           "\t*** Favor digitar seu programa, uma instrução ***\n"
           "\t*** (ou palavra de dados) por vez. Mostrarei ***\n"
           "\t*** o número do local e uma interrogação (?). ***\n"
           "\t*** Você, então, deverá digitar a palavra para esse ***\n"
           "\t*** local. Digite a sentinela -99999 para ***\n"
           "\t*** encerrar a entrada do seu programa. ***\n");

    printf("\n\t > Digite 1 para inserir o programa manualmente ou 2 para ler de um arquivo texto: ");
    do
    {
        printf("\n>> ");
        scanf("%d", &option);
        if (option != 1 && option != 2)
        {
            printf("\n\t*** Opção inválida ***\n");
        }
    } while (option != 1 && option != 2);

    if (option == 2)
    {
        FILE *file;
        char fileName[50];
        printf("\n\t*** Escolha um arquivo de programa ***\n"
               "\n\t1. mostrarMaiorValor.txt"
               "\n\t2. fatorial.txt"
               "\n\t3. verificarSeEPrimo.txt"
               "\n\t4. calcularResto.txt"
               "\n\t5. calcularPotencia.txt"
               "\n\t6. custom.txt"
               "\n\n\t > Digite o número do arquivo: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            strcpy(fileName, "./mostrarMaiorValor.txt");
            break;
        case 2:
            strcpy(fileName, "./fatorial.txt");
            break;
        case 3:
            strcpy(fileName, "./verificarSeEPrimo.txt");
            break;
        case 4:
            strcpy(fileName, "./calcularResto.txt");
            break;
        case 5:
            strcpy(fileName, "./calcularPotencia.txt");
            break;
        case 6:
            strcpy(fileName, "./custom.txt");
            break;
        default:
            printf("\n\t*** Opção inválida ***\n");
            system("pause");
            return 0;
        }

        file = fopen(fileName, "r");

        i = 0;
        while (fscanf(file, "%d", &memory[i]) != EOF)
        {
            i++;
        }

        fclose(file);
    }

    else
    {
        for (i = 0; i < MEMORY_SIZE; i++)
        {
            do
            {
                printf("%02d ? ", i);
                scanf("%d", &memory[i]);

                if (memory[i] == -99999)
                {
                    break;
                }

                if (memory[i] < -9999 || memory[i] > 9999)
                {
                    printf("\n\t*** O valor deve estar entre -9999 e 9999 ***\n");
                }
            } while (memory[i] < -9999 || memory[i] > 9999);

            if (memory[i] == -99999)
            {
                break;
            }
        }
    }

    printf("\n\t*** Executando o programa ***\n");

    for (i = 0; i < MEMORY_SIZE; i++)
    {
        instructionCounter = i;
        instructionRegister = memory[i];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;

        switch (operationCode)
        {
        case READ:
            printf("\nREADING %02d ? ", operand);
            scanf("%d", &memory[operand]);
            break;

        case WRITE:
            printf("\nWRITING %02d : %d\n", operand, memory[operand]);
            break;

        case LOAD:
            accumulator = memory[operand];
            break;

        case STORE:
            memory[operand] = accumulator;
            break;

        case ADD:
            accumulator += memory[operand];

            break;

        case SUBTRACT:
            accumulator -= memory[operand];

            break;

        case DIVIDE:
            if (accumulator == 0)
            {
                printf("\n\t*** Tentativa de divisão por zero ***\n");
                printf("\n\t*** Execução do Simpletron encerrada de forma anormal. ***\n");
                i = MEMORY_SIZE;
                break;
            }

            accumulator = memory[operand] / accumulator;

            break;

        case MULTIPLY:
            accumulator *= memory[operand];
            break;

        case EXPONENTIATION:
        // Calcula a potência de um número com base no acumulador e expoente num local específico da memória, armazenando o resultado no acumulador
            accumulator = pow(accumulator, memory[operand]);
            break;

        case INCREMENT:
        // Incrementa o acumulador
            accumulator++;
            break;

        case DECREMENT:
        // Decrementa o acumulador
            accumulator--;
            break;

        case ZERO:
        // Zera o acumulador
            accumulator = 0;
            break;

        case MODULO:
        // Calcula o módulo de um número com base no acumulador e um número num local específico da memória, armazenando o resultado no acumulador
            if (accumulator == 0)
            {
                printf("\n\t*** Tentativa de divisão por zero ***\n");
                printf("\n\t*** Execução do Simpletron encerrada de forma anormal. ***\n");
                i = MEMORY_SIZE;
                break;
            }

            accumulator = memory[operand] % accumulator;

            break;

        case BRANCH:
            i = operand - 1;
            break;

        case BRANCHNEG:
            if (accumulator < 0)
            {
                i = operand - 1;
            }
            break;

        case BRANCHZERO:
            if (accumulator == 0)
            {
                i = operand - 1;
            }
            break;

        case HALT:
            printf("\n\t*** Execução do Simpletron encerrada ***\n");
            i = MEMORY_SIZE;
            break;

        default:
            printf("\n\t*** Código de operação inválido ***\n");
            printf("\n\t*** Execução do Simpletron encerrada de forma anormal. ***\n");
            i = MEMORY_SIZE;
            break;
        }

        if (accumulator > 9999 || accumulator < -9999)
        {
            printf("\n\t*** Overflow do acumulador ***\n");
            printf("\n\t*** Execução do Simpletron encerrada de forma anormal. ***\n");
            i = MEMORY_SIZE;
        }
    }

    printf("\n\t*** Estado final da memória ***\n");

    printf("\n\tREGISTERS:\n"
           "\taccumulator: +%04d\n"
           "\tinstructionCounter: %02d\n"
           "\tinstructionRegister: +%04d\n"
           "\toperationCode: %02d\n"
           "\toperand: %02d\n",
           accumulator, instructionCounter, instructionRegister, operationCode, operand);

    printf("\n\tMEMORY:\n\n"
           "\t");

    for (i = 0; i < 10; i++)
    {
        printf("%6d ", i);
    }
    printf("\n");

    for (i = 0; i < MEMORY_SIZE; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n\t%02d ", i);
        }

        if (memory[i] >= 0)
        {
            printf("+%04d  ", memory[i]);
        }
        else
        {
            printf("-%04d  ", memory[i] * -1);
        }
    }

    printf("\n\n");
    system("pause");

    return 0;
}