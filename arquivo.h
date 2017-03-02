#define CEM 100
#define MIL 1000
#define DEZMIL 10000
#define CEMMIL 100000

/**Lista*/
struct lista {
    int info;
    struct lista *prox;
};
typedef struct lista Lista;
Lista* cria_lista();
Lista* inserir_lista(Lista* l,int valor);
Lista* busca(Lista* l, int valor);
Lista* remover_lista(Lista* l,int valor);
void liberar_lista(Lista* l);
void mostrar_lista(Lista* l);

void informacoes();
void geraArquivos(FILE* arquivo,int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void insereNumeros(FILE* arquivo,int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void insereNumerosLista(FILE* arquivo,Lista** lcem,Lista** lmil,Lista** ldmil,Lista** lcmil);
void geraArquivosOrdenados(FILE* arquivo,int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void ordenaBubble(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void ordenaSelection(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void ordenaInsertion(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void ordenaMerge(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void ordenaQuick(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void ordenaHeap(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void ordenaRadix(int* vetCem,int* vetMil,int* vetDezMil,int* vetCemMil);
void bubbleSort(int* vetor,int n,long long int* nC,long long int* nT);
void selectionSort(int* vetor,int n,long long int* nC,long long int* nT);
void insertionSort(int* vetor,int n,long long int* nC,long long int* nT);
void mergeSort(int* vetor,int posicaoInicio, int posicaoFim);
void quickSort(int* vetor,int esq, int dir);
void heapSort(int* vetor,int n,long long int* nC,long long int* nT);
void radixsort(int* vetor, int tamanho);
int buscaSequencial(int* vet,int tam,int chave);
int buscaBinaria(int* vet,int tam,int chave);
int buscaSequencialLista(Lista* l,int chave);
Lista* busca_binaria_lista(Lista* l,int chave);
Lista* meio_lista(Lista* inicio_no,Lista* fim_no);
void message_chave();
void message_chave2();


