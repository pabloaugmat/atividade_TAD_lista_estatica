
// TAD para Lista Estática baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _LISTA_ESTATICA
#define _LISTA_ESTATICA

typedef struct lista Lista;
typedef struct produto Produto;
// funções para alocar e desalocar memória
Lista *criar_lista();
int liberar_lista(Lista *li);

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, Produto dado);
int inserir_lista_final(Lista *li, Produto dado);
int inserir_lista_ordenada(Lista *li, Produto dado);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int codigo);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos, Produto *dado);
int buscar_lista_dado(Lista *li, int dado, Produto *pos);

// int imprimir_lista(Lista *li);

/// @brief se houver retona o primeiro produto encontrado com o menor preço
/// @param li ponteiro de lista estatica
/// @return retorna produto com menor preço
Produto buscar_menor_preco(Lista *li);

/// @brief remove os ultimos n elementos da lista
/// @param li ponteiro para lista estatica
/// @param n numeros de elementos a serem removidos no final da lista
/// @return 0 se foi bem sucedido e 1 se não foi possivel
int remover_ultimos_elementos(Lista *li, int n);

/// @brief Se possivel, permuta dois elemtnos de posição
/// @param li ponteiro para lista estatica
/// @param pos1 posição do elemento 1
/// @param pos2 posição do elemento 2
/// @return 0 se foi bem sucedido e 1 se não foi possivel
int permutar_posicao_elementos(Lista *li, int pos1, int pos2);

/// @brief função recursiva, se existente imprime elementos da lista do ultimo para o primeiro
/// @param li ponteiro para lista estatica
/// @param qnt quantidade de itens restantes na lista para serem impressos
void imprimir_lista(Lista *li, int qnt);

#endif