#include "stdlib.h"
#include "stdio.h"


struct Pessoa{
	char nome[100];
	char email[100];
	
}typedef Pessoa;

struct TCC{
	char titulo[100];
	char curso[100];
	int ano;
	int qtdAlunos;
	
	Pessoa professor;
	Pessoa *aluno;
	
	struct TCC *proximo;
	
}typedef TCC;
	
	TCC* inicio = NULL;
	TCC* fim = NULL;
	
	
void cadastra(TCC *novo){
	if (inicio == NULL){
		inicio = (TCC*)malloc(sizeof(TCC));
		
		if (inicio != NULL){
			inicio = novo;
			fim = inicio;
		}
		
	}else{
		fim->proximo = (TCC*)malloc(sizeof(TCC));
		fim->proximo = novo;
		
		fim = novo;
		
	}
}


void Listar(TTC* aux){
	
	int i = 0;
	TCC* aux = inicio;
	
	
	if (aux != NULL){
		printf("TCC - Titulo: %s", aux->titulo);
		printf("TCC - Curso: %s", aux->curso);
		printf("TCC - Ano: %d", aux->ano);
		printf("TCC - Quantidade de participantes: %d", aux->qtdAlunos);
		
		printf("Professor - nome: %s", aux->professor.nome);
		printf("Professor - email %s", aux->professor.email);
		
		
		for(i = 0; i<aux->qtdAlunos; i++){
			
			printf("Aluno - nome: %s", aux->aluno[i].email);
			printf("Aluno - email %s", aux->aluno[i].nome);
			
		}
		
		aux = aux->proximo;
	}
	
	imprime(aux);
}

int main(){
	
	printf("Digite o título do TCC: ");
	scanf()
	
	cadastra();
	
	imprime();
	
	return 0;
}
