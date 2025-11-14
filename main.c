#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <locale.h>
#include <string.h>

int menuPrincipal ();
void PausaBasica();
char* Categoria ();

main () {
	setlocale(LC_ALL, "Portuguese");
    Clientes *clientesLista = criarClientesLista();
    Clientes *golds = NULL;
    Clientes *diamonds = NULL;
    Clientes *simples = NULL;
    DataDeNascimento nascimento;

    int numero, menu=0;
    char nome[100], plano[50];
   
  do {
  	
  	menu = menuPrincipal ();
	
	switch (menu) {
	 case 0:
	     printf("\n--- Voltar ---\n");
               	int menu = menuPrincipal ();
               	break; 
    case 1: {
    printf("\n--- Cadastro de Cliente ---\n");

    printf("Número: ");
    scanf("%d", &numero);
    getchar();

    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    char *categoria = Categoria();

    printf("Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &nascimento.dia, &nascimento.mes, &nascimento.ano);

    Clientes *novo = criarCliente(numero, nome, categoria, nascimento);
    clientesLista = inserirCliente(clientesLista, novo);
  getchar ();
    printf("\nCliente cadastrado com sucesso!\n");

    free(categoria);
    PausaBasica();
    break;
}

    case 2:
    	        system("cls");
                printf("\n--- Lista de Clientes ---\n");
                listarClientes(clientesLista);
                PausaBasica();
                break;
                
                
      case 3: {
                system("cls");
                printf("=== REMOVER CLIENTE ===\n");
                int numero;
                printf("Digite o número do cliente a remover: ");
                scanf("%d", &numero);
                getchar();
                clientesLista = removerCliente(clientesLista, numero);
                 listarClientes(clientesLista);
                printf("\nCliente removido.\n");
                
                PausaBasica();
                break;
            }

            case 4: {
                system("cls");
                printf("=== TROCAR PLANO DE CLIENTE ===\n");
                printf("Digite o número do cliente: ");
                scanf("%d", &numero);
                char *novoPlano = Categoria();
                clientesLista = trocarPlanoCliente(clientesLista, novoPlano, numero);
                listarClientes(clientesLista);
                printf("\nPlano atualizado.\n");
                PausaBasica();
                break;
            }

            case 5:
                system("cls");
                printf("=== ORGANIZAR CLIENTES POR CATEGORIA ===\n");
                clientesLista = organizarClientesPorCategoria(clientesLista);
                listarClientes(clientesLista);
                printf("\nClientes reorganizados com sucesso!\n");
                
                pausarTela();
                break;

               	
              default:
                printf("\nOpção inválida!\n");
                PausaBasica();
	}
  	
     } while (menu!=0);
	
}

int menuPrincipal () {
	int opcao = 0;
	printf("\n============================================\n");
        printf("         SISTEMA DE GESTÃO DE CLIENTES       \n");
        printf("============================================\n");
        printf("1. Cadastrar novo cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Remover cliente\n");
        printf("4. Trocar plano de cliente\n");
        printf("5. Organizar clientes por categoria\n");
        printf("6. Separar clientes em três listas (Gold, Diamond, Simples)\n");
        printf("7. Unir três listas novamente\n");
        printf("0. Sair\n");
        printf("============================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        return opcao;
}

void PausaBasica() {
	printf ("\nPressione Enter para continuar... ");
	getchar();
	system("cls");
}

char* Categoria () {
	 char *categoria = (char*) malloc(20 * sizeof(char));
	printf("\nEscolha a categoria:\n");
    printf("1. Simples\n");
    printf("2. Diamond\n");
    printf("3. Gold\n");
    printf("Opção: ");
    int catOpcao;
    
   while (catOpcao < 1 || catOpcao > 3) {
    scanf("%d", &catOpcao);
    getchar();
		}

    switch (catOpcao) {
        case 1:
            strcpy(categoria, "simple");
            break;
        case 2:
            strcpy(categoria, "diamond");
            break;
        case 3:
            strcpy(categoria, "gold");
            break;
        default:
            printf("Opção inválida! Escolha o que está nas opções.\n");
            
    
    }
	return categoria;
}
