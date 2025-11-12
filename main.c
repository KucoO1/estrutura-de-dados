#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Clientes *clientesLista = criarClientesLista();
	Clientes *cliente1=NULL, *cliente2=NULL, *cliente3=NULL, *cliente4=NULL,*cliente5=NULL, *cliente6=NULL;
	
	DataDeNascimento nasc1,nasc2;
	nasc1.ano = 2005;
	nasc1.mes = 7;
	nasc1.dia = 17;
	
	nasc2.ano = 1975;
	nasc2.mes = 9;
	nasc2.dia = 28;
	
	
	cliente1 = criarCliente(1, "Nataniel Oliveira","diamond",nasc1);
	cliente2 = criarCliente(2, "Eduardo Oliveira","gold",nasc2);
	cliente3 = criarCliente(3, "Adianeth Tomas","simple",nasc1);
	cliente4 = criarCliente(4, "Mario Pereira","gold",nasc2);
	cliente5 = criarCliente(5, "Josenilson Antonio","simple",nasc1);
	cliente6 = criarCliente(6, "Dario Batista","diamond",nasc2);
	
	clientesLista = inserirCliente(clientesLista, cliente1);
	clientesLista = inserirCliente(clientesLista, cliente2);
	clientesLista = inserirCliente(clientesLista, cliente3);
	clientesLista = inserirCliente(clientesLista, cliente4);
	clientesLista = inserirCliente(clientesLista, cliente5);
	clientesLista = inserirCliente(clientesLista, cliente6);
	
    //clientesLista = trocarPlanoCliente(clientesLista,"gold",2)
	
	clientesLista = organizarClientesPorCategoria(clientesLista);
	
	clientesLista = removerCliente(clientesLista, 6);
	
	listarClientes(clientesLista);
	return 0;
}