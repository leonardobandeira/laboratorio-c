void Sistema_De_Atualizacao(){
	int Manter = 1;
	while(Manter){
		switch(MenuAtualizacao(0)){			
			case 1:
				Sistema_de_Edicao();
			break;
			
			case 2:
				Sistema_de_Exclusao();
			break;
			
			case 0:
				Manter = Sair();
			break;
		}
	}	
}

int MenuAtualizacao(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] SISTEMA DE ALTERAÇÕES");
	MSG("[ 2 ] SISTEMA DE EXCLUSÃO\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}

int MenuEdicao(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] EDITAR CLIENTE");
	MSG("[ 2 ] EDITAR ODONTÓLOGO\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}

void Sistema_de_Edicao(){
	int Manter = 1;
	while(Manter){
		switch(MenuEdicao(0)){			
			case 1:
				Editar_Pessoa(Clientes);
				Gravar_Lista_Cliente();
			break;
			
			case 2:
				Editar_Administrador(Administradores);
				Gravar_Lista_Administrador();
			break;
			
			case 0:
				Manter = Sair();
			break;
		}
		MSG("\n\n");
		PAUSA;
	}	
}

void Editar_Pessoa(Lista_C *LISTA){
	CLS;
	int IDEdicao = -1, Flag = 0;
	MSG("Informe o ID que terá os dados editados: ");
	scanf("%i", &IDEdicao);
	
	LISTA->ajuda = LISTA->inicio;
	while(!(LISTA->ajuda == NULL)){
	 	if(LISTA->ajuda->ID == IDEdicao){
	 		Ler_Cliente(LISTA->ajuda);
	 		Flag = 1;
	 		MSG("");
			MSG("Alterações realizadas!");
			break;	
		}
		LISTA->ajuda = LISTA->ajuda->next;
	}
	
	if(!Flag){
		MSG("ID não encontrado!");
	}
}

void Editar_Administrador(Lista_A *LISTA){
	CLS;
	int IDEdicao = -1, Flag = 0;
	MSG("Informe o ID terá os dados editados: ");
	scanf("%i", &IDEdicao);
	
	LISTA->ajuda = LISTA->inicio;
	while(!(LISTA->ajuda == NULL)){
	 	if(IDEdicao == LISTA->ajuda->ID){
	 		Ler_Administrador(LISTA->ajuda);
	 		Flag = 1;
			MSG("");
			MSG("Alterações realizadas!");
			break;	
		}
		LISTA->ajuda = LISTA->ajuda->next;
	}
	
	if(!Flag){
		MSG("ID não encontrado!");
	}
}

int MenuExclusao(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] EXCLUIR CLIENTE");
	MSG("[ 2 ] EXCLUIR ODONTÓLOGO\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}

void Sistema_de_Exclusao(){
	int Manter = 1;
	while(Manter){
		switch(MenuExclusao(0)){			
			case 1:
				Excluir_Cliente(Clientes);
				Gravar_Lista_Cliente();
			break;
			
			case 2:
				Excluir_Administrador(Administradores);
				Gravar_Lista_Administrador();
			break;
			
			case 0:
				Manter = Sair();
			break;
		}
		MSG("\n\n");
		PAUSA;
	}	
}

void Excluir_Cliente(Lista_C *LISTA){
	CLS;
	int IDExcluir = -1, Flag = 0;
	CLS;
	MSG("Informe o ID a ser excluido: ");
	CB;
	scanf("%i", &IDExcluir);
	
	Clientes->auxiliar = NULL;
	Clientes->ajuda = Clientes->inicio;
	while(!(Clientes->ajuda == NULL)){
		if(IDExcluir == Clientes->ajuda->ID){
			Flag = 1;
			break;
		}
		Clientes->auxiliar = Clientes->ajuda;
		Clientes->ajuda = Clientes->ajuda->next;
	}
	
	if(!Flag){
		MSG("ID não encontrado!");
	}else{
		if(Clientes->auxiliar == NULL){
			cliente = Clientes->inicio;
			Clientes->inicio = Clientes->inicio->next;
			free(cliente);
		}else{
			cliente = Clientes->ajuda;
			Clientes->auxiliar->next = Clientes->ajuda->next;
			free(cliente);
		}
		
		Anamneses->auxiliar = NULL;
		Anamneses->ajuda = Anamneses->inicio;
		while(!(Anamneses->ajuda == NULL)){
			if(IDExcluir == Anamneses->ajuda->IDCliente){
				break;
			}
			Anamneses->auxiliar = Anamneses->ajuda;
			Anamneses->ajuda = Anamneses->ajuda->next;
		}
		
		if(!(Anamneses->ajuda == NULL)){
			if(Anamneses->auxiliar == NULL){
				item_anamnese = Anamneses->inicio;
				Anamneses->inicio = Anamneses->inicio->next;
				free(item_anamnese);
			}else{
				item_anamnese = Anamneses->ajuda;
				Anamneses->auxiliar->next = Anamneses->ajuda->next;
				free(item_anamnese);
			}
			Gravar_Lista_Anamnese();
		}
		
		CLS;
		MSG("Cliente excluido!");
	}
}

void Excluir_Administrador(Lista_A *LISTA){
	CLS;
	int IDExcluir = -1;
	CLS;
	MSG("Informe o ID a ser excluido: ");
	CB;
	scanf("%i", &IDExcluir);
	
	Administradores->auxiliar = NULL;
	Administradores->ajuda = Administradores->inicio;
	while(!(Administradores->ajuda == NULL)){
		if(IDExcluir == Administradores->ajuda->ID){
			break;
		}
		Administradores->auxiliar = Administradores->ajuda;
		Administradores->ajuda = Administradores->ajuda->next;
	}
	
	if(Administradores->ajuda == NULL){
		MSG("ID não encontrado!");
	}else{
		if(Administradores->auxiliar == NULL){
			administrador = Administradores->inicio;
			Administradores->inicio = Administradores->inicio->next;
			free(administrador);
		}else{
			administrador = Administradores->ajuda;
			Administradores->auxiliar->next = Administradores->ajuda->next;
			free(administrador);
		}
		CLS;
		MSG("Administrador excluido!");
	}	
}
