#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

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
	
void Cadastra(TCC *novo){
	if (inicio == NULL){
		inicio = novo;
		
	}else{
		fim->proximo = novo;
	}
	
	fim = novo;
}

int encontrou;


void Registrar(){
	
	int c;
	TCC* novo = (TCC*)malloc(sizeof(TCC));
	
	_flushall();
	printf("Titulo do TCC: ");
	fgets(novo->titulo, 99, stdin);
	
	_flushall();
	printf("Curso do TCC: ");
	fgets(novo->curso, 99, stdin);
	
	_flushall();
	printf("Ano de conclusão: ");
	scanf("%d", &novo->ano);
	
	_flushall();
	printf("Quantidade de participantes: ");
	scanf("%d", &novo->qtdAlunos);
	
	_flushall();
	printf("Orientador: ");
	fgets(novo->professor.nome, 99, stdin);
	
	_flushall();
	printf("Email do orientador: ");
	fgets(novo->professor.email, 99, stdin);
	
	
	novo->aluno = (Pessoa*)malloc(sizeof(Pessoa)*novo->qtdAlunos);
	
	for(c = 0; c<novo->qtdAlunos; c++){
		
		_flushall();
		printf("Aluno %d: ", c+1);
		fgets(novo->aluno[c].nome, 99, stdin);
		
		_flushall();
		printf("Email do aluno %d: ", c+1);
		fgets(novo->aluno[c].email, 99, stdin);
		
	}
	
	
	novo->proximo = NULL;
	
	Cadastra(novo);
}


void Listar(TCC* aux){
	
	int i = 0;
//	aux = inicio;
	
	
	if (aux != NULL){
		printf("===============TCC===============");
		printf("\n\nTCC - Titulo: %s", aux->titulo);
		printf("TCC - Curso: %s", aux->curso);
		printf("TCC - Ano: %d", aux->ano);
		printf("\nTCC - Quantidade de participantes: %d\n\n", aux->qtdAlunos);
		
		printf("Professor - nome: %s", aux->professor.nome);
		printf("Professor - email: %s\n\n", aux->professor.email);
		
		
		for(i = 0; i < aux->qtdAlunos; i++){
			
			printf("Aluno - nome: %s", aux->aluno[i].nome);
			printf("Aluno - email: %s\n\n", aux->aluno[i].email);
			
		}
		
		aux = aux->proximo;
        Listar(aux);
	}
	
	   
}

	void buscaPorOrientador(char nomeOrientador[], struct TCC* tcc,
	int *encontrou){
		
		//condição de parada: não existe mais elementos caso TCC seja 
		//nulo
		if(tcc!=NULL){
			
			//avaliar se o orientador está no tcc
			if(!strcmp(nomeOrientador,tcc->professor.nome)){
				Listar(tcc);
			    *encontrou=1;
			}
			
			
			//andar para o proximo tcc para continuar a busca
			buscaPorOrientador(nomeOrientador, tcc->proximo, encontrou);
		}
		
	}
	
	void salvar(char *nomeArquivo){
		
		//abrir o arquivo para escrita
		FILE *file;
		
		file =fopen(nomeArquivo, "w");
		
		if(file!=NULL){
			fprintf(file, "TCCs cadastrados\n");
			
			//andar na lista para imprimir os dados:
			struct TCC *aux = inicio;
			while(aux !=NULL){
				fprintf(file, "\nTitulo: ");
				fprintf(file,"%s",aux->titulo);
				fprintf(file, "\nAno: ");
				fprintf(file,"%d",aux->ano);
				fprintf(file, "\nNumero de alunos: ");
				fprintf(file,"%d",aux->qtdAlunos);
				
				int numero_de_alunos = aux->qtdAlunos;
				int i;
				
				for(i=0; i<numero_de_alunos;i++){
				
					fprintf(file, "\nAluno: ");
					fprintf(file,"%s", aux->aluno[i].nome);
					fprintf(file, "\ne-mail: ");
					fprintf(file,"%s", aux->aluno[i].email);
					fprintf(file, "\nAluno: ");
					fprintf(file,"%s", aux->aluno[i].nome);
				}
					fprintf(file, "\nOrientador: ");
					fprintf(file,"%s", aux->professor.nome);
					fprintf(file, "\ne-mail: ");
					fprintf(file,"%s", aux->professor.email);
					
					aux = aux->proximo;
			}
			fclose(file);
		}
	}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int op;
	char nomeOrientador[30];
	char nomeArquivo[100];
	
	do{
		printf("1 - Cadastrar\n");
		printf("2 - Exibir dados cadastrados\n");
		printf("3 - Listar TCC por orientador\n");
		printf("0 - Sair\n");
		
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				Registrar();
				break;
			
			case 2:
				Listar(inicio);
				break;
				
			case 3:
				encontrou = 0;
				
				if(inicio!=NULL){
					_flushall();
					//ler a informação a ser procurada
					printf("Informe o nome do orientador");
					gets(nomeOrientador);
					
					buscaPorOrientador(nomeOrientador, inicio, 
					&encontrou);
					
					if(!encontrou){
						printf("\nOrientador não encontrado!");
					}
					
				}else{
					printf("\n Lista vazia!");
					
				}
				
				break;
				
			case 0:
				
				printf("Digite o nome do arquivo a ser criado: ");
				scanf("%s", &nomeArquivo);
				
				salvar(nomeArquivo);
				
				break;				
			default:
				printf("Opção não existente. Tente novamente");
				break;
		}
		
	}while(op != 0);
	
	return 0;
}
