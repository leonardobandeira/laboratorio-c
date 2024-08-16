void Sistema_De_Busca(){
	int Manter = 1, Modo = 0;
	while(Manter){
		switch(MenuBusca(0)){
			case 1:
				Modo = Perguntar_Modo(0);
				Listar_Pessoa(Clientes, Modo);
			break;
			
			case 2:
				Modo = Perguntar_Modo(0);
				Listar_Administrador(Administradores, Modo, 1);
			break;
			
			case 3:
				Modo = Perguntar_Modo(0);
				Listar_Administrador(Administradores, Modo, 2);
			break;
			
			case 4:
				Listar_Pessoa(Clientes, 0);
			break;
			
			case 5:
				Listar_Administrador(Administradores, 0, 1);
			break;
			
			case 6:
				Listar_Administrador(Administradores, 0, 2);
			break;
			
			case 0:
				Manter = Sair();
			break;
		}
		MSG("\n\n");
		PAUSA;
	}	
}

//Menu para perguntar qual o modo de busca
int Perguntar_Modo(int MODO){
	CLS;
	LINHA;
	MSG("MODOS DE BUSCA\n");
	MSG("Busca por NOME ==> 1");
	MSG("Busca por ID ==> 2");
	LINHA;
	MSG("Informe o modo escolhido: ");
	scanf("%i", &MODO);
	return MODO;
}

//Menu de opções de Busca no sistema
int MenuBusca(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] BUSCAR DE CLIENTE");
	MSG("[ 2 ] BUSCAR DE ODONTÓLOGO");
	MSG("[ 3 ] BUSCAR DE ADMISTRADOR\n");
	MSG("[ 4 ] LISTAR DE CLIENTES"); 
	MSG("[ 5 ] LISTAR DE ODONTÓLOGOS");
	MSG("[ 6 ] LISTAR DE ADMISTRADORES\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}

void Listar_Pessoa(Lista_C *LISTA, int MODO){	
	char *NomeBuscar = (char*) calloc(80, sizeof(char));
	int IDBuscar = -1, Flag = 1;
	if(MODO == 1){
		CLS;
		MSG("Informe o nome que deseja buscar: ");
		CB;
		scanf("%[^\n]", NomeBuscar);
	}else if(MODO == 2){
		CLS;
		MSG("Informe o ID que deseja buscar: ");
		CB;
		scanf("%i", &IDBuscar);
	}
	
	LISTA->ajuda = LISTA->inicio;
	while(!(LISTA->ajuda == NULL)){
		if(MODO == 1){
			if(String_Matching(LISTA->ajuda->nome, NomeBuscar)){
				Exibir_Pessoa(LISTA->ajuda, 1);
				Flag = 0;
			}
		}else if(MODO == 2){
			if(IDBuscar == LISTA->ajuda->ID){
				Exibir_Pessoa(LISTA->ajuda, 1);
				Flag = 0;
				break;
			}
		}else{
			Exibir_Pessoa(LISTA->ajuda, 0);
		}
		LISTA->ajuda = LISTA->ajuda->next;
	}
	
	if((MODO == 1 || MODO == 2) && Flag){
		CLS;
		MSG("Pessoa não encontrada!\n\n");
	}
}

void Listar_Administrador(Lista_A *LISTA, int MODO, int TIPO){
	char *NomeBuscar = (char*) calloc(80, sizeof(char));
	int IDBuscar = -1, Flag = 1;
	if(MODO == 1){
		CLS;
		MSG("Informe o nome que deseja buscar: ");
		CB;
		scanf("%[^\n]", NomeBuscar);
	}else if(MODO == 2){
		CLS;
		MSG("Informe o ID que deseja buscar: ");
		CB;
		scanf("%i", &IDBuscar);
	}
	
	LISTA->ajuda = LISTA->inicio;
	while(!(LISTA->ajuda == NULL)){
		if(MODO == 1){
			if(String_Matching(LISTA->ajuda->nome, NomeBuscar)){
				if(LISTA->ajuda->tipo == TIPO){
					Exibir_Login(LISTA->ajuda, 1);
				}
				Flag = 0;
			}
		}else if(MODO == 2){
			if(IDBuscar == LISTA->ajuda->ID){
				if(LISTA->ajuda->tipo == TIPO){
					Exibir_Login(LISTA->ajuda, 1);
				}
				Flag = 0;
				break;
			}
		}else{
			if(LISTA->ajuda->tipo == TIPO){
				Exibir_Login(LISTA->ajuda, 0);
			}
		}
		LISTA->ajuda = LISTA->ajuda->next;
	}
	
	if((MODO == 1 || MODO == 2) && Flag){
		CLS;
		MSG("Pessoa não encontrada!\n\n");
	}
}

void Exibir_Pessoa(Cliente *DADOS, int MODO){
	if(MODO){
		//DataNascimento; sexo;telefone;*cidade; *endereco;
		MSGI("ID: ", DADOS->ID);
		MSGS("NOME: ", DADOS->nome);
		MSGS("DATA DE NASCIMENTO: ", DADOS->dataNascimento);
		MSGC("SEXO: ", DADOS->sexo);
		MSGS("TELEFONE: ", DADOS->telefone);
		MSGS("CIDADE: ", DADOS->cidade);		
		MSGS("ENDEREÇO: ", DADOS->endereco);
	}else{
		MSGI("ID: ", DADOS->ID);
		MSGS("NOME: ", DADOS->nome);
	}
	MSG("\n");
}

void Exibir_Login(Administrador *DADOS, int MODO){
	if(MODO){
		MSGI("ID: ", DADOS->ID);
		MSGS("NOME: ", DADOS->nome);
		MSGI("TIPO: ", DADOS->tipo);
	}else{
		MSGI("ID: ", DADOS->ID);
		MSGS("NOME: ", DADOS->nome);
	}
	MSG("\n");
}


