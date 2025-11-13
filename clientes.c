#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <ctype.h> 
#include "clientes.h"



struct Cliente{
	int numero;
	char nome[50];
	char categoria[50];
	DataDeNascimento nascimento;
	struct Cliente *proximo;
};

/* 


Clientes * removerCliente(Clientes * clientesLista);
;

*/

Clientes * criarClientesLista(){
	return NULL;
}


Clientes * criarCliente(int numero, char *nome, char *categoria, DataDeNascimento nascimento) {
    Clientes *novoCliente = (Clientes*)malloc(sizeof(Clientes));

    if (novoCliente) { 
        novoCliente->numero = numero;
        strcpy(novoCliente->nome, nome);
        strcpy(novoCliente->categoria, categoria);
        novoCliente->nascimento = nascimento;
        novoCliente->proximo = NULL;
        return novoCliente;
    } else {
        printf("Erro ao alocar memória para o cliente.\n");
        return NULL;
    }
}


Clientes * inserirCliente(Clientes * clientesLista, Clientes *cliente){
	if (clientesLista == NULL){
		clientesLista = cliente;
		return clientesLista;
	}else{
		Clientes *aux = clientesLista;
		
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		if(aux== NULL){
			printf("Erro, auxiliar é igual a NULL na função inserirCliente()");
			return NULL;
		}
		aux->proximo = cliente;
		return clientesLista;
	}
}
Clientes * trocarPlanoCliente(Clientes * clientesLista, char *plano, int numero){
	
	if(clientesLista == NULL) return NULL;
	
	Clientes *aux = clientesLista;
	
	while(aux != NULL && aux->numero != numero){
		aux=aux->proximo;
	}
	
	if(aux == NULL){
		printf("Cliente nao encontrado");
		return clientesLista;
	}
	
	strcpy(aux->categoria,plano);
	return clientesLista;
}


void listarClientes(Clientes * clientesLista){
	
	if(clientesLista==NULL){
		printf("Lista vazia");
		return;
	}
	
	Clientes *aux = clientesLista;
	int cont=1;
	
	while(aux != NULL){
		printf("----------------------------------------");
		printf("\n");
		printf("%d-%s",cont,aux->nome);
		printf("\n   - Categoria: %s", aux->categoria);
		printf("\n   - Data de nascimento: %d/%d/%d", aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano);
		printf("\n");
		cont++;
		aux = aux->proximo;
	}
}

Clientes * organizarClientesPorCategoria(Clientes * clientesLista) {
	
    if(clientesLista == NULL) return NULL;

    Clientes *diamonds = NULL, *golds = NULL, *simples = NULL;
    Clientes *aux = clientesLista;

    while(aux != NULL) {
        Clientes *proximo = aux->proximo; 
        aux->proximo = NULL; 

        if(strcmp(aux->categoria, "diamond") == 0)
            diamonds = inserirCliente(diamonds, aux);
        else if(strcmp(aux->categoria, "gold") == 0)
            golds = inserirCliente(golds, aux);
        else if(strcmp(aux->categoria, "simple") == 0)
            simples = inserirCliente(simples, aux);

        aux = proximo;
    }

    Clientes *novaLista = NULL;
    Clientes *fim = NULL;

    if(diamonds) { 
		novaLista = diamonds; 
		fim = diamonds; 
		while(fim->proximo != NULL) {
			fim = fim->proximo;
		} 
	}
    if(golds) { 
		if(novaLista==NULL){
			novaLista = golds; 
		} 
			
		else{
			fim->proximo = golds; 
            while(fim->proximo != NULL){
               fim = fim->proximo; 
            } 
		}
	}
			
    if(simples){ 
    
		if(novaLista==NULL) 
			novaLista = simples; 
		else 
			fim->proximo = simples; 
			while(fim->proximo != NULL){
			fim = fim->proximo;	
			}
	}

    return novaLista;
}

Clientes * removerCliente(Clientes * clientesLista, int numero){
	if(clientesLista == NULL) return NULL;
	
	Clientes *aux = clientesLista,*anterior=NULL;
	
	while(aux != NULL && aux->numero != numero){
		anterior = aux;
		aux = aux->proximo;
	}
	if(anterior == NULL){
		clientesLista = aux->proximo;
		free(aux);
		return clientesLista;
	}
	anterior->proximo = aux->proximo;
	free(aux);
	return clientesLista;
}
//Novas atualizaçõees by Mário
Clientes * criarListaDiamond(){
    return NULL; // Inicializa lista vazia
}
Clientes * criarListaGold(){
    return NULL; // Inicializa lista vazia
}
Clientes * criarListaSimple(){
    return NULL; // Inicializa lista vazia
}

void tresListasClientes(Clientes **golds, Clientes **diamonds, Clientes **simples, Clientes *clientesLista){
    Clientes *aux = clientesLista;
    Clientes *a = NULL; 

    if(clientesLista == NULL) return;

    while(aux != NULL){
        a = aux->proximo; // Guarda próximo antes de alterar ponteiro

        if(strcmp(aux->categoria, "diamond") == 0){
            // Insere no início da lista diamond
            aux->proximo = *diamonds;
            *diamonds = aux;
        }
        else if(strcmp(aux->categoria, "gold") == 0){
            // Insere no início da lista gold
            aux->proximo = *golds;
            *golds = aux;
        }                                     
        else if(strcmp(aux->categoria, "simple") == 0){
            // Insere no início da lista simple
            aux->proximo = *simples;
            *simples = aux;
        }

        aux = a; // Avança para o próximo nó original
    }
}

Clientes* unirTresListas(Clientes *golds, Clientes *diamonds, Clientes *simples){
    Clientes *novaLista = NULL;
    Clientes *fim = NULL;

    if(diamonds) { 
        // Diamond será a cabeça inicial
        novaLista = diamonds; 
        fim = diamonds; 
        while(fim->proximo != NULL) {
            fim = fim->proximo; // Avança até ao último nó
        } 
    }
    if(golds) { 
        if(novaLista == NULL){
            // Caso não haja diamond, gold será a cabeça
            novaLista = golds; 
            fim = golds; 
        } else {
            // Liga fim da lista diamond ao início da lista gold
            fim->proximo = golds; 
            while(fim->proximo != NULL){
                fim = fim->proximo; // Avança até ao último nó
            } 
        }
    }
    if(simples){ 
        if(novaLista == NULL) {
            // Caso não haja diamond nem gold, simples será a cabeça
            novaLista = simples; 
        } else { 
            // Liga fim da lista atual ao início da lista simples
            fim->proximo = simples; 
            while(fim->proximo != NULL){
                fim = fim->proximo; 
            }
        }
    }

    return novaLista; // Retorna lista unificada
}
Clientes *inserirPorCategoria_atualizado(Clientes *clientesLista, int numero, char *nome, char *categoria, DataDeNascimento nascimento){
    Clientes *novoCliente = (Clientes*)malloc(sizeof(Clientes));
    Clientes *aux = clientesLista, *a = NULL;

    if(aux){ 
        if(novoCliente){
            // Inicialização do novo nó
            novoCliente->numero = numero;
            strcpy(novoCliente->nome, nome);
            strcpy(novoCliente->categoria, categoria);
            novoCliente->nascimento = nascimento;
            novoCliente->proximo = NULL;

            // Caso seja "diamond", insere sempre no início
            if(strcmp(novoCliente->categoria, "diamond") == 0){
                novoCliente->proximo = aux;
                return novoCliente; // novo nó vira cabeça
            }

            // Caso seja "gold"
            if(strcmp(novoCliente->categoria, "gold") == 0){
                while(aux != NULL){
                    a = aux;
                    aux = aux->proximo;

                    if(aux != NULL){
                        if(strcmp(a->categoria, "gold") == 0){
                            //  Aqui o novo nó substitui a cabeça gold,ele só cai neste if no primeiro ciclo de iteração da lista
                            novoCliente->proximo = a;
                            return novoCliente;
                        } 
                        else if(strcmp(a->categoria, "diamond") == 0){
                            // Insere entre diamond e gold
                            if(strcmp(aux->categoria, "gold") == 0){
                                novoCliente->proximo = aux;
                                a->proximo = novoCliente;
                                return clientesLista;
                            }
                            // Insere entre diamond e simples
                            if(strcmp(aux->categoria, "simple") == 0){
                                novoCliente->proximo = aux;
                                a->proximo = novoCliente;
                                return clientesLista;
                            }
                        } 
                        else if(strcmp(a->categoria, "simple") == 0){
                            // Se a lista começar com simple o Novo nó vira cabeça antes de simple
                            novoCliente->proximo = a;
                            return novoCliente;
                        }
                    } else {
                        // Caso chegue ao fim, insere no final
                        a->proximo = novoCliente;
                        return clientesLista;
                    }
                }
            }

            // Caso seja "simple"
            if(strcmp(novoCliente->categoria, "simple") == 0){
                a = aux;
                aux = aux->proximo;

                if(aux != NULL){
                    if(strcmp(a->categoria, "simple") == 0){
                        //  Novo nó substitui cabeça simples
                        novoCliente->proximo = a;
                        return novoCliente;
                    } 
                    else if(strcmp(a->categoria, "diamond") == 0){
                        if(strcmp(aux->categoria, "simple") == 0){
                            // Insere entre diamond e simples
                            novoCliente->proximo = aux;
                            a->proximo = novoCliente;
                            return clientesLista;
                        }   
                    }
                    else if(strcmp(a->categoria, "gold") == 0){
                        if(strcmp(aux->categoria, "simple") == 0){
                            // Insere entre gold e simple
                            novoCliente->proximo = aux;
                            a->proximo = novoCliente;
                            return clientesLista;
                        }   
                    }
                } else {
                    // Caso chegue ao fim, insere no final
                    a->proximo = novoCliente;
                    return clientesLista;
                }
            }
        }
        else {
            printf("\nErro na alocação de memória do novo cliente!\n");
			return NULL;
        }
    }
    else {
        // Lista vazia: novo nó vira cabeça
        novoCliente->numero = numero;
        strcpy(novoCliente->nome, nome);
        strcpy(novoCliente->categoria, categoria);
        novoCliente->nascimento = nascimento;
        novoCliente->proximo = NULL;
        aux = novoCliente;
        return aux;
    }
}
