#include <iostream>
#define maximo 10
using namespace std;

struct Queue { // Estrutura que compõe a Pilha
    int dado; // Dado armazenado na Pilha
    Queue *prox; // Apontamento para o proximo nivel
}; 

int quantidade(Queue * & ultimo){ //Retorna a quantidade de niveis da pilha
  
 Queue *temp = ultimo; //Ponteiro temporario para contar niveis
 int qnt = 0;  //Variavel que armazenara o dado
  
   while(temp != NULL){  //Enquanto ponteiro temporario não apontar para NULO
     qnt++; //Acrescenta em 1 nivel da pilha
     temp=temp->prox; //Temporario percorre todos os niveis da pilha
  } 
   return qnt; //Retorna tamanho da pilha
  }

void listar(Queue * & ultimo){
  if(ultimo == NULL){  //Verifica se pilha está vazia
		printf("\n                     **Fila Atual vazia!**\n");
	}

  else{ //Lista todos elementos da pilha
    
		printf("\nFila Atual:\n");
		Queue * aux = ultimo;
    cout << "Ultimo  -->\t";
		while(aux != NULL){ //Percorre a pilha inteira
			printf("\t%d\t", aux->dado);
			aux = aux->prox;  
			}
    cout << "\t<--  Primeiro\n\n\n";
	}
}
  
void Enqueue(Queue * & ultimo, Queue * & primeiro, int dado){

  if(maximo <= 0){   //Verifica se o valor maximo definido pelo usuario nao seja 0
    printf("Fila sem espaços disponiveis!\n");
   } 
    
  else {    
    if(ultimo == NULL){        //Verifica se a pilha esta inicialmente vazia
    
      Queue *fila = NULL;  //Aloca espaço para novo nivel da pilha
    fila = (Queue*) calloc (1, sizeof(Queue));  
      
      if(fila == NULL){     //Verifica se foi alocado memória
     printf("ERRO DE ALOCAÇÂO!\n");
      } 
        
      else{  //aloca elemento na pilha
      fila->dado = dado;   //Novo nivel recebe dado informado pelo usuario
      fila->prox = NULL;   //Nivel mais baixo da pilha aponta para NULO
      primeiro = fila;    //Atualiza Topo para novo nivel
      ultimo = fila;
      
      
      cout << "\n\n" << dado << " - Adicionado à fila!\n";  
        listar(ultimo);
      return;
      }
   }
      
  else if(quantidade(ultimo) < maximo) { //verifica se pilha não esta cheia
   Queue *fila = NULL;  //Aloca espaço para novo nivel da pilha
    fila = (Queue*) calloc (1, sizeof(Queue)); //aloca ponteiro
    
    if(fila == NULL){ 
      printf("ERRO DE ALOCAÇÂO!\n");}//verifica falha na alocação
    else{ //demais elementos da pilha
      fila->dado = dado;
      fila->prox = ultimo;
      ultimo = fila;
      cout << "\n" << dado << " - Adicionado à fila!\n";   
      listar(ultimo);
   } 
   } 
   }
      
  }

int Dequeue(Queue * & primeiro, Queue * & ultimo){  //Função para remover elementos da fila
  
if(ultimo != NULL){
	Queue * aux = ultimo;
  Queue *eliminar = primeiro;               //Ponteiro váriavel
  
  int val;                   //Valor a ser removido da pilha
    val = eliminar->dado;
  
  int d;
    d = (quantidade(ultimo) - 2);
  
  if(quantidade(ultimo) > 1){
  for (int i = 0; i< d; i++){
    aux=aux->prox; 
  }
  

  
    //Libera Endereço do antigo topo
  primeiro = aux; 
  free(eliminar); 

  primeiro->prox = NULL;
  if(eliminar != primeiro){           //Verifica se o topo foi removido
    cout << "\n"<< val << " - Removido da fila!\n";
  }

  else{
    cout << "Erro ao remover nivel atual!\n";
  }
   listar(ultimo);
	 return val;             //Retorna valor removido da fila
 }
  
else{

  
    free(ultimo);
    ultimo = NULL;
  
  cout <<"\n" << val << " - Removido da fila!\n";
  cout <<"\n                   **A Lista foi esvaziada!** \n";
  listar(ultimo);
  return val;
  }
  }
  

else{
  return 0;
}
}
  
void Isfull_Isempty(Queue *& ultimo) { //Verifica se pilha esta vazia ou cheia 
  if(ultimo == NULL){ 
    cout << "\nFila Vazia!\n";
  }
  else if(quantidade(ultimo) == maximo){
    cout << "\n\nFila cheia!\n\n";
  }

  else{  //Indica quantos niveis ainda podem ser adicionados
    cout << "\nFila com " << maximo - quantidade(ultimo) << " espaços disponiveis\n";
    }
}

void consultar(Queue * ultimo, int c){ //Verifica se valor esta contido na pilha
  Queue * aux;
  aux = ultimo;
  int nivel = quantidade(ultimo);
 
 if(ultimo == NULL){
    cout << "Pilha Vazia!\n";
    return;
  }
  else{
    while(aux != NULL){
    if (aux->dado == c){ //Se valor for encontrado na pilha
     printf("\n\nValor encontrado na %dª posição!\n", nivel);
      return;
    }
    else {  //Enquanto valor não for encontrado na pilha
      aux = aux->prox; 
      nivel--;
    } 
  }
   printf("Valor não encontrado na pilha!\n");
 }
}



int main() {
  
  Queue *primeiro = NULL;;
  Queue *ultimo = NULL;;
  int i;
  int qtd; //Variavel que armazena tamanho da pilha

  Isfull_Isempty(ultimo); //Verifica situação da pilha

  for (i=1;i<10;i++){ //Adiciona valor na pilha
   Enqueue(ultimo, primeiro, i);
  }

  
  Isfull_Isempty(ultimo);

  Dequeue (primeiro, ultimo);
  Dequeue (primeiro, ultimo);
  Dequeue (primeiro, ultimo);
  Dequeue (primeiro, ultimo);
  
  consultar(ultimo, 6);
  
  
  
 // listar(ultimo);
}