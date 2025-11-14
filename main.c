#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <locale.h>
#include <string.h>

int menuPrincipal ();
int anoBissexto(int ano);
int dataValida(DataDeNascimento nascimento);
void PausaBasica();
char* Categoria ();
void pausarTela();

main () {
	setlocale(LC_ALL, "Portuguese");
    Clientes *clientesLista = criarClientesLista();
    Clientes *golds = NULL;
    Clientes *diamonds = NULL;
    Clientes *simples = NULL;
    DataDeNascimento nascimento;
    char nome[100];
    int numero =0, menu=0;
    
    do {
        menu = menuPrincipal();

        switch(menu) {
            case 0:
                printf("\nSaindo...\n");
                break;

            case 1: {
                printf("\n--- Cadastro de Cliente ---\n");
                numero++;
                printf("\nNúmero id - %d ", numero);
                getchar();
                
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                do {
                    printf("Data de nascimento (dd mm aaaa): ");
                    scanf("%d %d %d", &nascimento.dia, &nascimento.mes, &nascimento.ano);
                    if (!dataValida(nascimento)) {
                        printf("Data inválida! Tente novamente.\n");
                    }
                } while(!dataValida(nascimento));

                char *categoria = Categoria();
                Clientes *novo = criarCliente(numero, nome, categoria, nascimento);
                clientesLista = inserirCliente(clientesLista, novo);

                free(categoria);
                printf("\nCliente cadastrado com sucesso!\n");
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
                int numeroRemover;
                system("cls");
                printf("=== REMOVER CLIENTE ===\n");
                printf("Digite o número do cliente a remover: ");
                scanf("%d", &numeroRemover);
                getchar();
                clientesLista = removerCliente(clientesLista, numeroRemover);
                listarClientes(clientesLista);
                printf("\nCliente removido.\n");
                PausaBasica();
                break;
            }

            case 4: {
                int numeroTroca;
                system("cls");
                printf("=== TROCAR PLANO DE CLIENTE ===\n");
                printf("Digite o número do cliente: ");
                scanf("%d", &numeroTroca);
                getchar();
                char *novoPlano = Categoria();
                clientesLista = trocarPlanoCliente(clientesLista, novoPlano, numeroTroca);
                listarClientes(clientesLista);
                printf("\nPlano atualizado.\n");
                free(novoPlano);
                PausaBasica();
                break;
            }

            case 5:
                system("cls");
                printf("=== ORGANIZAR CLIENTES POR CATEGORIA ===\n");
                clientesLista = organizarClientesPorCategoria(clientesLista);
                listarClientes(clientesLista);
                printf("\nClientes reorganizados com sucesso!\n");
                PausaBasica();
                break;
                
                     case 6: {
    system("cls");
    printf("=== INSERIR CLIENTE POR CATEGORIA ===\n");

    
    numero++;
    printf("\nID : %d\n", numero);
    getchar();

    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    
    do {
        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d",
              &nascimento.dia, &nascimento.mes, &nascimento.ano);

        if (!dataValida(nascimento)) {
            printf("Data inválida! Tente novamente.\n");
        }

    } while (!dataValida(nascimento));

    getchar();

    
    char *categoria = Categoria();

    clientesLista = inserirPorCategoria(
                        clientesLista,
                        numero,
                        nome,
                        categoria,
                        nascimento
                    );

    printf("\nCliente inserido diretamente na categoria!\n");
    free(categoria);
    PausaBasica();
    break;
}


            default:
                printf("\nOpção inválida!\n");
                PausaBasica();
        }

    } while(menu != 0);

    return 0;
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
        printf("6. Inserir cliente diretamente por categoria\n");
        printf("7. Separar clientes em três listas (Gold, Diamond, Simples)\n");
        printf("8. Unir três listas novamente\n");
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

void pausarTela() {
    printf("\nPressione ENTER para continuar...");
    getchar();
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

// Função para verificar se o ano é bissexto

int anoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int dataValida(DataDeNascimento nascimento) {
    if (nascimento.ano < 1900 || nascimento.ano > 2100) return 0;
    if (nascimento.mes < 1 || nascimento.mes > 12) return 0;

    int diasNoMes;
    switch (nascimento.mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasNoMes = 31; break;
        case 4: case 6: case 9: case 11:
            diasNoMes = 30; break;
        case 2:
            diasNoMes = anoBissexto(nascimento.ano) ? 29 : 28; break;
        default:
            return 0;
    }

    return (nascimento.dia >= 1 && nascimento.dia <= diasNoMes);
}
