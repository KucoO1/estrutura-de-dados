#include <stdio.h>
#include <stdlib.h>

#include <locale.h>
#include <string.h>
#include "clientes.h"

int menuPrincipal ();
int anoBissexto(int ano);
int VerificarData(DataDeNascimento nascimento);
void PausaBasica();
char* Categoria ();
void pausarTela();
void VerCategoria ();
void PausaSemLimpar() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

main () {
	setlocale(LC_ALL, "Portuguese");
    Clientes *clientesLista = criarClientesLista();
    Clientes *golds = criarListaGold();
    Clientes *diamonds =criarListaDiamond();
    Clientes *simples =criarListaSimple();
    DataDeNascimento nascimento;
    

    int numero = 0, menu=0, VerifNumero= 0;
    int VerListaCategoria=0;
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
    numero ++;
    printf("\nNúmero id: %d ", numero);
    //getchar();

    printf("\nNome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    char *categoria = Categoria();
    
    do {
    printf("Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &nascimento.dia, &nascimento.mes, &nascimento.ano);
		
	} 
	while (!VerificarData(nascimento));
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

                
                printf("Digite o número do cliente a remover: ");
                scanf("%d", &numero);
                getchar();
                VerifNumero = NumEncontrado(clientesLista, numero) ;
				if (!VerifNumero ) {
					 printf ("Número invalido");
					 break;
				} 
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
                
                PausaBasica();
                break;
                
              case 6:
                system("cls");
    printf("=== INSERIR CLIENTE POR CATEGORIA ===\n");
    numero ++;
    printf("\nNúmero id: %d ", numero);
    //getchar();

    printf("\nNome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    char *categoria = Categoria();
    
    do {
    printf("Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &nascimento.dia, &nascimento.mes, &nascimento.ano);
		
	} 
	while (!VerificarData(nascimento));

    clientesLista = inserirPorCategoria_atualizado(
                        clientesLista,
                        numero,
                        nome,
                        categoria,
                        nascimento
                    );
	getchar();
    printf("\nCliente inserido diretamente na categoria!\n");
    free(categoria);
    PausaBasica();
    break;
                
            case 7:
    system("cls");
    printf("=== Separar clientes em três listas (Gold, Diamond, Simples) ===\n");
    golds = NULL;
    diamonds = NULL;
    simples = NULL;
    tresListasClientes(&golds, &diamonds, &simples, &clientesLista);

    VerCategoria();
    scanf(" %d", &VerListaCategoria);

    switch (VerListaCategoria) {
        case 1:
            system("cls");
            printf("\n--- Lista Gold ---\n");
            listarClientes(golds);
            PausaSemLimpar();
            break;

        case 2:
            system("cls");
            printf("\n--- Lista Diamond ---\n");
            listarClientes(diamonds);
            PausaSemLimpar();
            break;

        case 3:
            system("cls");
            printf("\n--- Lista Simples ---\n");
            listarClientes(simples);
            PausaSemLimpar();
            break;

        case 0:
            printf("\nVoltando...\n");
            break;

        default:
            printf("\nOpção inválida!\n");
            break;
    }
    PausaBasica(); 
    break;

                
                  case 8:
                system("cls");
                printf("=== Unir três listas novamente ===\n");
                clientesLista = unirTresListas(golds,diamonds,simples);
                listarClientes(clientesLista);
                printf("\nListas unidas com sucesso!\n");
                 golds = NULL;
   				 diamonds = NULL;
   				 simples = NULL;
                PausaBasica();
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

int VerificarData(DataDeNascimento nascimento) {
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
void VerCategoria () {
printf("\n=== Ver Listas por Categoria ===\n");
printf("1. Lista Gold\n");
printf("2. Lista Diamond\n");
printf("3. Lista Simples\n");
printf("0. Voltar\n");
printf("Escolha: ");
}
