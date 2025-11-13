typedef struct Cliente Clientes;

typedef struct{
	int dia, mes, ano;
}DataDeNascimento;

// Operações escolhidas pelo grupo
Clientes * criarClientesLista();
Clientes * criarCliente(int numero, char *nome, char *categoria,DataDeNascimento nascimento);
Clientes * inserirCliente(Clientes * clientesLista, Clientes *cliente);
Clientes * removerCliente(Clientes * clientesLista, int numero);
Clientes * trocarPlanoCliente(Clientes * clientesLista, char *plano,int numero);
Clientes * organizarClientesPorCategoria(Clientes * clientesLista);
void listarClientes(Clientes * clientesLista);
Clientes *inserirPorCategoria_atualizado(Clientes *clientesLista, int numero, char *nome, char *categoria, DataDeNascimento nascimento);
Clientes* unirTresListas(Clientes*golds,Clientes*diamonds,Clientes*simples);
Clientes * criarListaDiamond();
Clientes * criarsListaGold();
Clientes * criarListaSimples();
void tresListasClientes(Clientes**golds,Clientes**diamonds,Clientes**simples,Clientes * clientesLista);
