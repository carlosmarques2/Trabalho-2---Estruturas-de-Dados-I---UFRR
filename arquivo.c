#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include "arquivo.h"

long long int swap = 0,comp = 0;

void informacoes(){
    setlocale(LC_ALL, "Portuguese");
    printf("------------------------------------------------\n");
    printf("UFRR - DCC - Ciencia da Computação\n");
    printf("Projeto da Disciplina de Estrutura de Dados I\n");
    printf("Prof.: Filipe Dwan Pereira\n");
    printf("Trabalho de Ordenação e Busca\n");
    printf("Integrantes do Grupo:\n\n\tBruno Rodrigues\n\tCarlos Alberto Vieira Marques Filho\n");
    printf("------------------------------------------------\n\n");
    system("pause");
    system("cls");
}

void geraArquivos(FILE* arquivo,int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){
    int num,cont=0;
    srand(time(NULL));
    /**Inicio: 100 Numeros*/
    /**Abre o Arquivo para Escrita*/
    arquivo = fopen("cemNumeros.txt","w");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    else{
        /**Escreve no Arquivo numeros aleatorios de 0 a 100*/
        while(cont<100){
            num = rand()%100;
            if(cont!=99)
                fprintf(arquivo,"%d\n",num);
            else
                fprintf(arquivo,"%d",num);
            cont++;
        }
        printf("Arquivo de 100 Numeros Gerado com Sucesso!\n");
        //Sleep(1000);
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);

    cont = 0;

    /**Inicio:1000 Numeros*/
    arquivo = fopen("milNumeros.txt","w");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    else{
        /**Escreve no Arquivo numeros aleatorios de 0 a 1000*/
        while(cont<1000){
            num = rand()%1000;
            if(cont!=999)
                fprintf(arquivo,"%d\n",num);
            else
                fprintf(arquivo,"%d",num);
            cont++;
        }
        printf("Arquivo de 1000 Numeros Gerado com Sucesso!\n");
        //Sleep(1000);
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);

    cont = 0;

    /**Inicio: 10000 Numeros*/
    arquivo = fopen("dezMilNumeros.txt","w");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    else{
        /**Escreve no Arquivo numeros aleatorios de 0 a 10000*/
        while(cont<10000){
            num = rand()%1000;
            if(cont!=9999)
                fprintf(arquivo,"%d\n",num);
            else
                fprintf(arquivo,"%d",num);
            cont++;
        }
        printf("Arquivo de 10000 Numeros Gerado com Sucesso!\n");
        //Sleep(1000);
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);

    cont = 0;

    /**Inicio: 100000 Numeros*/
    arquivo = fopen("cemMilNumeros.txt","w");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    else{
        /**Escreve no Arquivo numeros aleatorios de 0 a 1000*/
        while(cont<100000){
            num = rand()%10000;
            if(cont!=99999)
                fprintf(arquivo,"%d\n",num);
            else
                fprintf(arquivo,"%d",num);
            cont++;
        }
        printf("Arquivo de 100000 Numeros Gerado com Sucesso!\n");
        //Sleep(1000);
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
}

void insereNumeros(FILE* arquivo,int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){
    int index = 0,num;
    /**Abre o Arquivo para Leitura*/
    arquivo = fopen("cemNumeros.txt","rt");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    /**Escreve em um vetor de 100 posições o conteudo do Arquivo*/
    while(!feof(arquivo)){
        fscanf(arquivo,"%d",&num);
        vetCem[index] = num;
        index++;
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
    /**Fim: 100 Numeros*/
    index = 0;

    /**Abre o Arquivo para Leitura*/
    arquivo = fopen("milNumeros.txt","rt");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    /**Escreve em um vetor de 1000 posições o conteudo do Arquivo*/
    while(!feof(arquivo)){
        fscanf(arquivo,"%d",&num);
        vetMil[index] = num;
        index++;
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
    /**Fim: 1000 Numeros*/
    index = 0;

    /**Abre o Arquivo para Leitura*/
    arquivo = fopen("dezMilNumeros.txt","rt");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    /**Escreve em um vetor de 10000 posições o conteudo do Arquivo*/
    while(!feof(arquivo)){
        fscanf(arquivo,"%d",&num);
        vetDezMil[index] = num;
        index++;
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
    /**Fim: 10000 Numeros*/
    index = 0;

    /**Abre o Arquivo para Leitura*/
    arquivo = fopen("cemMilNumeros.txt","rt");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    /**Escreve em um vetor de 100000 posições o conteudo do Arquivo*/
    while(!feof(arquivo)){
        fscanf(arquivo,"%d",&num);
        vetCemMil[index] = num;
        index++;
    }
    /**Fecha o Arquivo*/
    /**Fim: 100000 Numeros*/
    fclose(arquivo);
}
/**Função para Inserir o Conteudo dos Arquivos em uma Lista Encadeada*/
void insereNumerosLista(FILE* arquivo,Lista** lcem,Lista** lmil,Lista** ldmil,Lista** lcmil){
    int num;
    /**Abre o Arquivo para Leitura*/
    arquivo = fopen("cemNumeros.txt","rt");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    /**Insere em uma lista o conteudo do Arquivo*/
    while(!feof(arquivo)){
        fscanf(arquivo,"%d",&num);
        *lcem = inserir_lista(*lcem,num);
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
    /**Fim: 100 Numeros*/

    /**Abre o Arquivo para Leitura*/
    arquivo = fopen("milNumeros.txt","rt");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    /**Insere em uma lista o conteudo do Arquivo*/
    while(!feof(arquivo)){
        fscanf(arquivo,"%d",&num);
        *lmil = inserir_lista(*lmil,num);
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
    /**Fim: 1000 Numeros*/

    /**Abre o Arquivo para Leitura*/
    arquivo = fopen("dezMilNumeros.txt","rt");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    /**Insere em uma lista o conteudo do Arquivo*/
    while(!feof(arquivo)){
        fscanf(arquivo,"%d",&num);
        *ldmil = inserir_lista(*ldmil,num);
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
    /**Fim: 10000 Numeros*/

    /**Abre o Arquivo para Leitura*/
    arquivo = fopen("cemMilNumeros.txt","rt");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    /**Insere em uma lista o conteudo do Arquivo*/
    while(!feof(arquivo)){
        fscanf(arquivo,"%d",&num);
        *lcmil = inserir_lista(*lcmil,num);
    }
    /**Fecha o Arquivo*/
    /**Fim: 100000 Numeros*/
    fclose(arquivo);
}

void geraArquivosOrdenados(FILE* arquivo,int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){
    int cont = 0;

    /**Inicio: 100 Numeros*/
    /**Abre o Arquivo para Escrita*/
    arquivo = fopen("cemNumerosOrdenados.txt","w");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    else{
        /**Escreve no Arquivo numeros Ordenados*/
        while(cont<100){
            if(cont!=99)
                fprintf(arquivo,"%d\n",vetCem[cont]);
            else
                fprintf(arquivo,"%d",vetCem[cont]);
            cont++;
        }
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
    cont = 0;
    /**Inicio: 1000 Numeros*/
    /**Abre o Arquivo para Escrita*/
    arquivo = fopen("milNumerosOrdenados.txt","w");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    else{
        /**Escreve no Arquivo numeros Ordenados*/
        while(cont<1000){
            if(cont!=999)
                fprintf(arquivo,"%d\n",vetMil[cont]);
            else
                fprintf(arquivo,"%d",vetMil[cont]);
            cont++;
        }
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
    cont = 0;
    /**Inicio: 10000 Numeros*/
    /**Abre o Arquivo para Escrita*/
    arquivo = fopen("dezMilNumerosOrdenados.txt","w");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    else{
        /**Escreve no Arquivo numeros Ordenados*/
        while(cont<10000){
            if(cont!=9999)
                fprintf(arquivo,"%d\n",vetDezMil[cont]);
            else
                fprintf(arquivo,"%d",vetDezMil[cont]);
            cont++;
        }
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
    cont = 0;
    /**Inicio: 100000 Numeros*/
    /**Abre o Arquivo para Escrita*/
    arquivo = fopen("cemMilNumerosOrdenados.txt","w");
    if (arquivo == NULL) {
        printf ("Houve um erro ao abrir o arquivo.\n");
        exit(0);
    }
    else{
        /**Escreve no Arquivo numeros Ordenados*/
        while(cont<100000){
            if(cont!=99999)
                fprintf(arquivo,"%d\n",vetCemMil[cont]);
            else
                fprintf(arquivo,"%d",vetCemMil[cont]);
            cont++;
        }
    }
    /**Fecha o Arquivo*/
    fclose(arquivo);
}

void bubbleSort(int* vetor,int n,long long int* nC,long long int* nT){
    int i, t, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < n; i++) {
            *nC+=1;
            if (vetor[i] < vetor[i - 1]) {
                *nT+=1;
                t = vetor[i];
                vetor[i] = vetor[i - 1];
                vetor[i - 1] = t;
                s = 1;
            }
        }
    }
}

void ordenaBubble(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){

    long long int nC = 0,nT = 0;
    bubbleSort(vetCem,CEM,&nC,&nT);
    printf("Para 100 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 0;

    bubbleSort(vetMil,MIL,&nC,&nT);
    printf("Para 1000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 0;

    bubbleSort(vetDezMil,DEZMIL,&nC,&nT);
    printf("Para 10000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 0;

    bubbleSort(vetCemMil,CEMMIL,&nC,&nT);
    printf("Para 100000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);
}

void selectionSort(int* vetor,int n,long long int* nC,long long int* nT){
    int i, j, min, aux;
    for (i = 0; i < n-1; i++){
        for (j = i+1, min = i; j < n; j++) {
            if(vetor[j] < vetor[min]){
                min = j;
                *nT+=1;
            }
            *nC+=1;
        }
        if(i!=min){
            *nT+=1;
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
        *nC+=1;
    }
}

void ordenaSelection(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){

    long long int nC = 1,nT = 1;

    selectionSort(vetCem,CEM,&nC,&nT);
    printf("Para 100 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 1;

    selectionSort(vetMil,MIL,&nC,&nT);
    printf("Para 1000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 1;

    selectionSort(vetDezMil,DEZMIL,&nC,&nT);
    printf("Para 10000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 1;

    selectionSort(vetCemMil,CEMMIL,&nC,&nT);
    printf("Para 100000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);
}

void insertionSort(int* vetor,int n,long long int* nC,long long int* nT){

    for(int i = 1; i < n; i++) {
		int key = vetor[i];
		int j = i - 1;
		while((j >= 0) && (vetor[j] > key)) {
			vetor[j + 1] = vetor[j];
			j--;
			*nT+=1;
            *nC+=1;
		}
		*nC+=1;
		vetor[j + 1] = key;
	}
}

void ordenaInsertion(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){
    long long int nC = 0,nT = 0;

    insertionSort(vetCem,CEM,&nC,&nT);
	printf("Para 100 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 0;

    insertionSort(vetMil,MIL,&nC,&nT);
	printf("Para 1000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 0;

    insertionSort(vetDezMil,DEZMIL,&nC,&nT);
	printf("Para 10000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 0;

    insertionSort(vetCemMil,CEMMIL,&nC,&nT);
	printf("Para 100000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);
}

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;

    if(posicaoInicio == posicaoFim) return;

    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) {
            vetorTemp[k] = vetor[j];
            j++;
            k++;
            swap++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
                swap++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                    swap++;
                    comp++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                    swap++;
                    comp++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
        swap++;
    }
    free(vetorTemp);
}

void ordenaMerge(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){
    mergeSort(vetCem,0,CEM-1);
    printf("Para 100 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",comp);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",swap);

    swap = comp = 0;

    mergeSort(vetMil,0,MIL-1);
    printf("Para 1000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",comp);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",swap);

    swap = comp = 0;

    mergeSort(vetDezMil,0,DEZMIL-1);
    printf("Para 10000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",comp);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",swap);

    swap = comp = 0;

    mergeSort(vetCemMil,0,CEMMIL-1);
    printf("Para 100000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",comp);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",swap);

    swap = comp = 0;
}

void quickSort(int* vetor,int esq, int dir){
    int pivo = esq, i,ch,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        comp++;
        if(vetor[j] < vetor[pivo]){
            ch = vetor[j];
            while(j > pivo){
                vetor[j] = vetor[j-1];
                swap++;
                j--;
            }
            vetor[j] = ch;
            pivo++;
        }
    }
    if(pivo-1 >= esq){
        quickSort(vetor,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quickSort(vetor,pivo+1,dir);
    }
}

void ordenaQuick(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){

    quickSort(vetCem,0,CEM-1);
    printf("Para 100 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",comp);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",swap);

    swap = comp = 0;

    quickSort(vetMil,0,MIL-1);
    printf("Para 1000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",comp);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",swap);

    swap = comp = 0;

    quickSort(vetDezMil,0,DEZMIL-1);
    printf("Para 10000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",comp);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",swap);

    swap = comp = 0;

    quickSort(vetCemMil,0,CEMMIL-1);
    printf("Para 100000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",comp);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",swap);

    swap = comp = 0;
}

void heapSort(int* vetor,int n,long long int* nC,long long int* nT){
    int i = n / 2, pai, filho, t;
    for (;;) {
        if (i > 0) {
            i--;
            t = vetor[i];
        }
        else{
            n--;
            if (n == 0)
                return;
            t = vetor[n];
            vetor[n] = vetor[0];
            *nT+=1;
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n)  &&  (vetor[filho + 1] > vetor[filho])){
                filho++;
                *nC+=1;
            }
            if (vetor[filho] > t) {
                *nC+=1;
                *nT+=1;
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }
            else{
                break;
            }
        }
        *nT+=1;
        vetor[pai] = t;
    }
}

void ordenaHeap(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){
    long long int nC = 0,nT = 0;

    heapSort(vetCem,CEM,&nC,&nT);
	printf("Para 100 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 0;

    heapSort(vetMil,MIL,&nC,&nT);
	printf("Para 1000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 0;

    heapSort(vetDezMil,DEZMIL,&nC,&nT);
	printf("Para 10000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);

    nC = nT = 0;

    heapSort(vetCemMil,CEMMIL,&nC,&nT);
	printf("Para 100000 Numeros\n");
    printf("Quantidade de Comparações Realizadas: %I64d\n",nC);
    printf("Quantidade de Trocas Realizadas: %I64d\n\n",nT);
}

void radixsort(int *vetor, int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}

void ordenaRadix(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil){

    radixsort(vetCem,CEM);
    radixsort(vetMil,MIL);
    radixsort(vetDezMil,DEZMIL);
    radixsort(vetCemMil,CEMMIL);
}

int buscaSequencial(int* vetor,int tam,int chave){
    int i;
    for (i = 0; i < tam; i++) {
        if (vetor[i] == chave) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int* vet,int tam,int chave){
    int inf = 0;
    int sup = tam-1;
    int meio;
    while (inf <= sup){
        meio = (inf + sup)/2;
        if (chave == vet[meio])
            return meio;
        if (chave < vet[meio])
            sup = meio-1;
        else
            inf = meio+1;
    }
    return -1;
}

int buscaSequencialLista(Lista* l,int chave){
    int cont = 0;
    Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        cont++;
        if(chave==p->info)
            return cont;
    }
    return -1;
}

void message_chave(){
    system("cls");
    printf("------------------------------------------------\n");
    printf("Digite um Numero a ser Buscado no Vetor\n\n");
    printf("------------------------------------------------\n");
    printf("K = ");
}

void message_chave2(){
    system("cls");
    printf("------------------------------------------------\n");
    printf("Digite um Numero a ser Buscado na Lista\n\n");
    printf("------------------------------------------------\n");
    printf("K = ");
}

/**Lista*/

Lista* cria_lista(){
    return NULL;
}
Lista* inserir_lista(Lista* l,int valor){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

Lista* busca(Lista* l, int valor){
    Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        if(p->info==valor)
            return p;
    }
    return NULL;
}

Lista* remover_lista(Lista* l,int valor){
    Lista* a = NULL;
    Lista* p = l;

    while(p!=NULL&&p->info!=valor) {
        a = p;
        p = p->prox;
    }
    if (p == NULL)
        return l;
    if(a == NULL)
        l = p->prox;
    else
        a->prox = p->prox;
    free(p);
    return l;
}

void liberar_lista(Lista* l){
    Lista* p = l;
    while(p!=NULL){
        Lista* t = p->prox;
        free(p);
        p=t;
    }
}

void mostrar_lista(Lista* l){
    Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        printf("Lista: %d\n",p->info);
    }
}
