#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "arquivo.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    FILE* arquivo;
    arquivo = fopen("teste.txt", "rt");
    if (arquivo == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
       exit(0);
    }
    fclose(arquivo);
    Lista *lcem,*lmil,*ldmil,*lcmil;
    lcem = cria_lista();
    lmil = cria_lista();
    ldmil = cria_lista();
    lcmil = cria_lista();
    int *vetCem,*vetMil,*vetDezMil,*vetCemMil;
    int operador,ocorrencia,chave;
    typedef int *INT;
    vetCem = (INT) malloc(CEM*sizeof(INT));
    vetMil = (INT) malloc(MIL*sizeof(INT));
    vetDezMil = (INT) malloc(DEZMIL*sizeof(INT));
    vetCemMil = (INT) malloc(CEMMIL*sizeof(INT));
    geraArquivos(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
    system("cls");
    do{
        printf("------------------------------------------------\n");
        printf("Projeto de Ordenação e Busca\n\n");
        printf("\t1 - Algoritmos de Ordenação.\n\t2 - Algoritmos de Busca.\n\t3 - Informações.\n\n\t0 - Sair\n\n");
        printf("------------------------------------------------\n");
        printf("Escolha uma Opcao: ");
        scanf("%d",&operador);
        printf("\n");
        switch(operador){
        case 1:
            system("cls");
            do{
                printf("------------------------------------------------\n");
                printf("Escolha um Algoritmo de Ordenacao\n\n");
                printf("\t1 - Bubble Sort.\n\t2 - Selection Sort.\n\t3 - Insertion Sort.\n\t4 - Merge Sort.\n\t5 - Quick Sort.\n\t6 - Heap Sort.\n\t7 - Radix Sort\n\t8 - Gerar Novos Arquivos\n\n\t0 - Sair.\n\n");
                printf("------------------------------------------------\n");
                printf("Escolha uma Opcao: ");
                scanf("%d",&operador);
                switch(operador){
                case 1:
                    system("cls");
                    printf("\nOrdenação Usando Bubble Sort!\n");
                    insereNumeros(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    ordenaBubble(vetCem,vetMil,vetDezMil,vetCemMil);
                    geraArquivosOrdenados(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    printf("Ordenação Concluida!\n");
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    printf("\nOrdenação Usando Selection Sort!\n");
                    insereNumeros(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    ordenaSelection(vetCem,vetMil,vetDezMil,vetCemMil);
                    geraArquivosOrdenados(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    printf("Ordenação Concluida!\n");
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    printf("\nOrdenação Usando Insertion Sort!\n");
                    insereNumeros(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    ordenaInsertion(vetCem,vetMil,vetDezMil,vetCemMil);
                    geraArquivosOrdenados(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    printf("Ordenação Concluida!\n");
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    printf("\nOrdenação Usando MergeSort!\n");
                    insereNumeros(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    ordenaMerge(vetCem,vetMil,vetDezMil,vetCemMil);
                    geraArquivosOrdenados(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    printf("Ordenação Concluida!\n");
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    printf("\nOrdenação Usando QuickSort!\n");
                    insereNumeros(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    ordenaQuick(vetCem,vetMil,vetDezMil,vetCemMil);
                    geraArquivosOrdenados(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    printf("Ordenação Concluida!\n");
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    system("cls");
                    printf("\nOrdenação Usando HeapSort!\n");
                    insereNumeros(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    ordenaHeap(vetCem,vetMil,vetDezMil,vetCemMil);
                    geraArquivosOrdenados(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    printf("Ordenação Concluida!\n");
                    system("pause");
                    system("cls");
                    break;
                case 7:
                    system("cls");
                    printf("\nOrdenação Usando RadixSort!\n");
                    insereNumeros(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    ordenaRadix(vetCem,vetMil,vetDezMil,vetCemMil);
                    geraArquivosOrdenados(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    printf("Ordenação Concluida!\n");
                    system("pause");
                    system("cls");
                    break;
                case 8:
                    geraArquivos(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                    system("cls");
                    break;
                case 0:
                    system("cls");
                    break;
                default:
                    printf("\nOpcao Invalida!\n");
                    Sleep(2000);
                    system("cls");
                    break;
                }
            }while(operador!=0);
            break;
        case 2:
            system("cls");
            do{
                printf("------------------------------------------------\n");
                printf("Escolha uma TAD\n\n");
                printf("\t1 - Vetor.\n\t2 - Lista Encadeada.\n\n\t0 - Sair.\n\n");
                printf("------------------------------------------------\n");
                printf("Escolha uma Opcao: ");
                scanf("%d",&operador);
                switch(operador){
                case 1:
                    system("cls");
                    do{
                        printf("------------------------------------------------\n");
                        printf("Escolha um Algoritmo de Busca\n\n");
                        printf("\t1 - Busca Sequencial.\n\t2 - Busca Binaria.\n\n\t0 - Sair.\n\n");
                        printf("------------------------------------------------\n");
                        printf("Escolha uma Opcao: ");
                        scanf("%d",&operador);
                        switch(operador){
                        case 1:
                            insereNumeros(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                            do{
                                system("cls");
                                printf("----------------Busca Sequêncial----------------\n");
                                printf("Escolha o Vetor para Realizar a Busca\n\n");
                                printf("\t1 - Vetor de 100 Posições.\n\t2 - Vetor de 1.000 Posições.\n\t3 - Vetor de 10.000 Posições.\n\t4 - Vetor de 100.000 Posições.\n\n\t0 - Sair.\n\n");
                                printf("------------------------------------------------\n");
                                printf("Escolha uma Opcao: ");
                                scanf("%d",&operador);
                                switch(operador){
                                system("cls");
                                case 1:
                                    message_chave();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaSequencial(vetCem,CEM,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado no Vetor.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na posição %d do Vetor.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 2:
                                    message_chave();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaSequencial(vetMil,MIL,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado no Vetor.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na posição %d do Vetor.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 3:
                                    message_chave();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaSequencial(vetDezMil,DEZMIL,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado no Vetor.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na posição %d do Vetor.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 4:
                                    message_chave();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaSequencial(vetCemMil,CEMMIL,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado no Vetor.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na posição %d do Vetor.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 0:
                                    system("cls");
                                    break;
                                default:
                                    printf("\nOpcao Invalida!\n");
                                    Sleep(1500);
                                    system("cls");
                                    break;
                                }
                            }while(operador!=0);
                            break;
                        case 2:
                            insereNumeros(arquivo,vetCem,vetMil,vetDezMil,vetCemMil);
                            ordenaHeap(vetCem,vetMil,vetDezMil,vetCemMil);
                            do{
                                system("cls");
                                printf("-----------------Busca Binária-----------------\n");
                                printf("Escolha o Vetor para Realizar a Busca\n\n");
                                printf("\t1 - Vetor de 100 Posições.\n\t2 - Vetor de 1.000 Posições.\n\t3 - Vetor de 10.000 Posições.\n\t4 - Vetor de 100.000 Posições.\n\n\t0 - Sair.\n\n");
                                printf("-----------------------------------------------\n");
                                printf("Escolha uma Opcao: ");
                                scanf("%d",&operador);
                                switch(operador){
                                system("cls");
                                case 1:
                                    message_chave();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaBinaria(vetCem,CEM,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado no Vetor.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na posição %d do Vetor.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 2:
                                    message_chave();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaBinaria(vetMil,MIL,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado no Vetor.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na posição %d do Vetor.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 3:
                                    message_chave();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaBinaria(vetDezMil,DEZMIL,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado no Vetor.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na posição %d do Vetor.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 4:
                                    message_chave();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaBinaria(vetCemMil,CEMMIL,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado no Vetor.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na posição %d do Vetor.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 0:
                                    system("cls");
                                    break;
                                default:
                                    printf("\nOpcao Invalida!\n");
                                    Sleep(1500);
                                    system("cls");
                                    break;
                                }
                            }while(operador!=0);
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            printf("\nOpcao Invalida!\n");
                            Sleep(1500);
                            system("cls");
                            break;
                        }
                    }while(operador!=0);
                    break;
                case 2:
                    system("cls");
                    do{
                        printf("------------------------------------------------\n");
                        printf("Escolha um Algoritmo de Busca\n\n");
                        printf("\t1 - Busca Sequencial.\n\t2 - Busca Binaria.\n\n\t0 - Sair.\n\n");
                        printf("------------------------------------------------\n");
                        printf("Escolha uma Opcao: ");
                        scanf("%d",&operador);
                        switch(operador){
                        case 1:
                            insereNumerosLista(arquivo,&lcem,&lmil,&ldmil,&lcmil);
                            do{
                                system("cls");
                                printf("----------------Busca Sequêncial----------------\n");
                                printf("Escolha uma Lista para Realizar a Busca\n\n");
                                printf("\t1 - Lista de 100 Elementos.\n\t2 - Lista de 1.000 Elementos.\n\t3 - Lista de 10.000 Elementos.\n\t4 - Lista de 100.000 Elementos.\n\n\t0 - Sair.\n\n");
                                printf("------------------------------------------------\n");
                                printf("Escolha uma Opcao: ");
                                scanf("%d",&operador);
                                switch(operador){
                                system("cls");
                                case 1:
                                    message_chave2();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaSequencialLista(lcem,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado na Lista.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na %dº iteração.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 2:
                                    message_chave2();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaSequencialLista(lmil,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado na Lista.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na %dº iteração.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 3:
                                    message_chave2();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaSequencialLista(ldmil,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado na Lista.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na %dº iteração.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 4:
                                    message_chave2();
                                    scanf("%d",&chave);
                                    ocorrencia = buscaSequencialLista(lcmil,chave);
                                    if(ocorrencia<0){
                                        printf("O numero %d não foi encontrado na Lista.\n\n",chave);
                                        system("pause");
                                    }
                                    else{
                                        printf("O numero %d foi encontrado na %dº iteração.\n\n",chave,ocorrencia);
                                        system("pause");
                                    }
                                    system("cls");
                                    break;
                                case 0:
                                    system("cls");
                                    break;
                                default:
                                    printf("\nOpcao Invalida!\n");
                                    Sleep(1500);
                                    system("cls");
                                    break;
                                }
                            }while(operador!=0);
                            break;
                        case 2:
                            system("cls");
                            printf("Indisponivel!\n");
                            system("pause");
                            system("cls");
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            printf("\nOpcao Invalida!\n");
                            Sleep(1500);
                            system("cls");
                            break;
                        }
                    }while(operador!=0);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcao Invalida!\n");
                    Sleep(1500);
                    system("cls");
                    break;
                }
            }while(operador!=0);
            break;
        case 3:
            system("cls");
            informacoes();
            break;
        case 0:
            system("cls");
            printf("Programa Finalizado!\n");
            free(vetCem);
            free(vetMil);
            free(vetDezMil);
            free(vetCemMil);
            liberar_lista(lcem);
            liberar_lista(lmil);
            liberar_lista(ldmil);
            liberar_lista(lcmil);
            exit(0);
        default:
            printf("\nOpcao Invalida!\n");
            Sleep(1500);
            system("cls");
            break;
        }
    }while(1);
    return 0;
}
