#include "Biblioteca.c"
#include "Estruturas.c"
#include "Prototipos_de_Funcao.c"
#include "Variaveis_Globais.c"
#include "Funcoes_Extras.c"
#include "Menus.c"
#include "Funcoes_Gravacao_Leitura.c"
#include "Sistema_Login.c"
#include "Sistema_Cadastro.c"
#include "Sistema_Busca.c"
#include "Sistema_Atualizacao.c"
#include "Sistema_Perfil.c"
#include "Sistema_Anamnese.c"
#include "Sistema_Almoxarifado.c"
#include "Sistema_Agendamento.c"

int main(void){
	COR;
	setlocale(LC_ALL, "Portuguese");
	Clientes = Iniciar_Lista_C();
	Administradores = Iniciar_Lista_A();
	Anamneses = Iniciar_Lista_AN();
	Agenda = Iniciar_Lista_AG();
	Inicio_Almoxarifado = NULL;
	Fim_Almoxarifado = NULL;
	Novo_Almoxarifado = NULL;
	Auxiliar_Almoxarifado = NULL;
	Auxiliar_Ajuda = NULL;
	
	Recuperar_Lista_Administrador();
	
	if(Administradores->inicio == NULL){
		MSG("PRIMEIRO CADASTRO");
		MSG("\n\n\n");
		PAUSA;
		administrador = Iniciar_Administrador();
		administrador->tipo = 2;
		Ler_Administrador(administrador);
		Adicionar_Administrador_Na_Lista(administrador);
		Gravar_Lista_Administrador();
	}

	Sistema_Login();
	return 0;
}

void Cadmo(){
	Recuperar_Lista_Cliente();
	Recuperar_Lista_Anamnese();
	Recuperar_Lista_Almoxarifado();
	Recuperar_Lista_Agendamento();
	
	if(cookie->tipo == 2){
		int Manter = 1;
		while(Manter && Flag_Logado){
			switch(MenuIndex1(0)){
				case 1:
				Sistema_De_Cadastro();
				break;
				
				case 2:
				Sistema_De_Busca();
				break;
			
				case 3:
				Sistema_De_Atualizacao();
				break;
				
				case 4:
				Sistema_De_Almoxarifado();
				break;
				
				case 5:
				Sistema_De_Agendamento();
				break;
				
				case 6:
				Sistema_De_Perfil();
				break;
				
				case 0:
				Flag_Logado = Sair();
				break;
				
				default:
				MSG("Opção inválida!");
				MSG("Tente novamente!");
			}
		}
	}else{
		int Manter = 1;
		while(Manter && Flag_Logado){
			switch(MenuIndex2(0)){
				case 1:
				Sistema_De_Busca();
				break;
				
				case 2:
				Sistema_De_Anamnese();
				break;
				
				case 3:
				Sistema_De_Perfil();
				break;
				
				case 0:
				Flag_Logado = Sair();
				break;
				
				default:
				MSG("Opção inválida!");
				MSG("Tente novamente!");
			}
		}	
	}

}

//Menu Geral de opções do sistema
int MenuIndex1(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] SISTEMA DE CADASTRO\n");
	MSG("[ 2 ] SISTEMA DE BUSCA & LISTAGEM\n");
	MSG("[ 3 ] SISTEMA DE ATUALIZAÇÃO\n");
	MSG("[ 4 ] SISTEMA DE ALMOXARIFADO\n");
	MSG("[ 5 ] SISTEMA DE AGENDAMENTO\n");
	MSG("[ 6 ] SISTEMA DE PERFIL\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}

int MenuIndex2(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] SISTEMA DE BUSCA & LISTAGEM\n");
	MSG("[ 2 ] SISTEMA ANAMNESE\n");
	MSG("[ 3 ] SISTEMA DE PERFIL\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}

int MenuIndex(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] SISTEMA DE CADASTRO\n");
	MSG("[ 2 ] SISTEMA DE BUSCA & LISTAGEM\n");
	MSG("[ 3 ] SISTEMA DE ATUALIZAÇÃO\n");
	MSG("[ 4 ] SISTEMA DE ALMOXARIFADO\n");
	MSG("[ 5 ] SISTEMA ANAMNESE\n");
	MSG("[ 6 ] SISTEMA DE AGENDAMENTO\n");
	MSG("[ 7 ] SISTEMA DE PERFIL\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}

//Função para fechar e sair do sistema CADMO
int Sair(){
	CLS;
	//Retorno da função
	return 0;
}

Lista_C* Iniciar_Lista_C(){
	Lista_C *LISTA = (Lista_C*) calloc(1, sizeof(Lista_C));
	
	LISTA->inicio = NULL;
	LISTA->fim = NULL;
	LISTA->ajuda = NULL;
	LISTA->auxiliar = NULL;
	
	return LISTA;
}

Lista_A* Iniciar_Lista_A(){
	Lista_A *LISTA = (Lista_A*) calloc(1, sizeof(Lista_A));
	
	LISTA->inicio = NULL;
	LISTA->fim = NULL;
	LISTA->ajuda = NULL;
	LISTA->auxiliar = NULL;
	
	return LISTA;
}

Lista_AN* Iniciar_Lista_AN(){
	Lista_AN *LISTA = (Lista_AN*) calloc(1, sizeof(Lista_AN));
	
	LISTA->inicio = NULL;
	LISTA->fim = NULL;
	LISTA->ajuda = NULL;
	LISTA->auxiliar = NULL;
	
	return LISTA;
}

Lista_AG* Iniciar_Lista_AG(){
	Lista_AG *LISTA = (Lista_AG*) calloc(1, sizeof(Lista_AG));
	
	LISTA->inicio = NULL;
	LISTA->fim = NULL;
	LISTA->ajuda = NULL;
	LISTA->auxiliar = NULL;
	
	return LISTA;	
}
