// TAD para Lista Estática baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

#define MAX 100

struct produto
{
  int codigo;
  char nome[30];
  float preco;
  int qtd;
};

// definição do tipo lista
struct lista
{
  int qtd;
  Produto dados[MAX];
};

//**************************************************************************
// função para alocar memória do tipo Lista
Lista *criar_lista()
{
  // 'li' é um ponteiro do tipo Lista
  Lista *li = (Lista *)malloc(sizeof(Lista));

  // se a alocação estiver correta qtd da lista é zero
  if (li != NULL)
  {
    li->qtd = 0;
  }

  return li;
}

//**************************************************************************
// função para liberar memória
int liberar_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente
  if (li == NULL)
  {
    return 0;
  }

  // libera o ponteiro (Lista)
  free(li);

  return 1;
}

//**************************************************************************
// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // verifica se a lista foi alocada corretamente
  if (li == NULL)
  {
    return -1;
  }
  else
  {
    // retorna a quantidade de elementos da lista
    return li->qtd;
  }
}

//**************************************************************************
// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if (li == NULL)
  {
    return -1;
  }

  // verifica se a lista esta vazia
  if (li->qtd == 0)
  {
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}

//**************************************************************************
// função para verificar se a lista está cheia
int lista_cheia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, 'li' não é uma lista válida
  if (li == NULL)
  {
    return -1;
  }

  // verifica se a lista esta cheia
  if (li->qtd == MAX)
  {
    return 1;
  }

  // se não estiver cheia, retorna 0
  return 0;
}

//**************************************************************************
// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, Produto dado)
{
  // verifica se a lista foi criada corretamente
  if (li == NULL)
  {
    return 0;
  }

  // verifica se a lista esta cheia
  if (lista_cheia(li) == 1)
  {
    return 0;
  }

  // movimenta todos os elementos da lista uma posição para frente
  for (int i = li->qtd - 1; i >= 0; i--)
  {
    li->dados[i + 1] = li->dados[i];
  }

  // insere o dado na primeira posição do vetor
  li->dados[0] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}

//**************************************************************************
// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, Produto dado)
{
  // verifica se a lista foi criada corretamente
  if (li == NULL)
  {
    return 0;
  }

  // verifica se a lista esta cheia
  if (lista_cheia(li) == 1)
  {
    return 0;
  }

  // insere o dado na posição logo após o último elemento do vetor
  li->dados[li->qtd] = dado;

  // incrementa quantidade de elementos
  li->qtd++;

  return 1;
}

//**************************************************************************
// função para remover o elemento do início da lista
int remover_lista_inicio(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if (li == NULL)
  {
    return 0;
  }

  // verifica se a lista esta vazia
  if (lista_vazia(li) == 1)
  {
    return 0;
  }

  // movimenta uma posição para trás, todos os elementos depois do primeiro
  for (int k = 0; k < li->qtd - 1; k++)
  {
    li->dados[k] = li->dados[k + 1];
  }

  li->qtd--;

  return 1;
}

//**************************************************************************
// função para remover o elemento do final da lista
int remover_lista_final(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if (li == NULL)
  {
    return 0;
  }

  // verifica se a lista esta vazia
  if (lista_vazia(li) == 1)
  {
    return 0;
  }

  li->qtd--;

  return 1;
}
/*

// função para imprimir a lista estática
int imprimir_lista(Lista *li)
{
  // verifica se a lista foi criada corretamente
  if (li == NULL)
  {
    return 0;
  }


  for(int i=0; i<li->qtd; i++){
    printf("%d ", li->dados[i]);
  }


  return 1;
}
*/

int buscar_lista_posicao(Lista *li, int pos, Produto *dado)
{
  // verifica se a lista foi criada corretamente e se a posição é válida (note que é a posição na lista e não o índice do vetor)
  if (li == NULL || pos <= 0 || pos > li->qtd)
  {
    return 0;
  }

  // copia o dado da posição desejada (parâmetro passado por referência)
  *dado = li->dados[pos - 1];

  return 1;
}

/// @brief se houver retona o primeiro produto encontrado com o menor preço
/// @param li ponteiro de lista estatica
/// @return retorna produto com menor preço
Produto buscar_menor_preco(Lista *li)
{

  Produto produto;
  int i;

  if (lista_vazia == 0)
  {

    produto = li->dados[0];

    for (i = 0; i < li->qtd; i++)
    {

      if (li->dados[i].preco < produto.preco)
      {
        produto = li->dados[i];
      }
    }

    return produto;
  }
  else
  {
    return;
  }
}

/// @brief remove os ultimos n elementos da lista
/// @param li ponteiro para lista estatica
/// @param n numeros de elementos a serem removidos no final da lista
/// @return 0 se foi bem sucedido e 1 se não foi possivel
int remover_ultimos_elementos(Lista *li, int n)
{

  int i;

  if (lista_vazia == 0)
  {
    if (li->qtd < n)
    {
      for (i = 0; i < n; i++)
      {
        li->dados[0 - 1 - i];
      }

      return 0;
    }
  }

  return 1;
}

/// @brief Se possivel, permuta dois elemtnos de posição
/// @param li ponteiro para lista estatica
/// @param pos1 posição do elemento 1
/// @param pos2 posição do elemento 2
/// @return 0 se foi bem sucedido e 1 se não foi possivel
int permutar_posicao_elementos(Lista *li, int pos1, int pos2)
{

  Produto produtoAuxiliar;

  if (lista_vazia == 0)
  {
    if (li->qtd < pos1 && li->qtd < pos2)
    {

      produtoAuxiliar = li->dados[pos1];
      li->dados[pos1] = li->dados[pos2];
      li->dados[pos2] = produtoAuxiliar;

      return 0;
    }
  }

  return 1;
}

/// @brief função recursiva, se existente imprime elementos da lista do ultimo para o primeiro
/// @param li ponteiro para lista estatica
/// @param qnt quantidade de itens restantes na lista para serem impressos
void imprimir_lista(Lista *li, int qnt)
{

  if (lista_vazia == 0)
  {

    int controle = qnt;

    if (controle <= 0)
    {
      return;
    }

    printf("Codigo: %d \n", li->dados[controle - 1].codigo);
    printf("Nome: %s \n", li->dados[controle - 1].nome);
    printf("Preco: %f \n", li->dados[controle - 1].preco);
    printf("Quantidade: %d \n", li->dados[controle - 1].qtd);

    imprimir_lista(li, (controle - 1));
  }
  else
  {
    printf("Lista vazia.\n");
  }
}
