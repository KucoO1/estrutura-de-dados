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