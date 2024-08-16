void Sistema_De_Almoxarifado(){
	int manter = 1;
	
	while(manter){
		switch (MenuAlmoxarifado(0)){
			case 1:
			Cadastro_Almoxarifado();
			Gravar_Lista_Almoxarifado();	
			break;
			
			case 2:
			Listar_Produtos(1);
			break;
			
			case 3:
			Listar_Produtos(0);
			break;
				
			case 4:
			Procurar_Almoxarifado();
			break;
			
			case 5:
			Atualizar_Almoxarifado();
			break;
				
			case 0:
			manter = Sair();
			break;
			
			default:
			MSG("Opção inválida!");
			MSG("Tente novamente!");
			PAUSA;
		}
	}
}

void Cadastro_Almoxarifado(){
	FILE *Arquivo;
	Novo_Almoxarifado = (Almoxarifado*) calloc (1, sizeof(Almoxarifado));
	Novo_Almoxarifado->next = NULL;	
	
	if(Inicio_Almoxarifado == NULL){
		Novo_Almoxarifado->id = 0;
	}else{
		Novo_Almoxarifado->id = Fim_Almoxarifado->id + 1;
	}
			
	MSG("CADASTRO DE NOVO PRODUTO");
	LINHA;
	MSG("NOME: ");
	CB;
	scanf("%[^\n]", Novo_Almoxarifado->nome);
	
	MSG("DESCRIÇÃO DO PRODUTO: ");
	CB;
	scanf("%[^\n]", Novo_Almoxarifado->descricao);
	
	MSG("QUANTIDADE: ");
	CB;
	scanf("%i", &Novo_Almoxarifado->quantidade);
	
	MSG("PREÇO DE MERCADO: R$ ");
	CB;
	scanf("%f", &Novo_Almoxarifado->preco);

	if(Inicio_Almoxarifado == NULL){
		Inicio_Almoxarifado = Novo_Almoxarifado;
		Fim_Almoxarifado = Novo_Almoxarifado;
	}else{
		Fim_Almoxarifado->next = Novo_Almoxarifado;
		Fim_Almoxarifado = Novo_Almoxarifado;
	}
	CLS;
	MSG("Produto adicionado!\n");
	PAUSA;
}

void Listar_Produtos(int MODO){
	if(MODO){
		int IDBuscar;
		MSG("Informe o ID do produto: ");
		CB;
		scanf("%i", &IDBuscar);
		
		Auxiliar_Almoxarifado = Inicio_Almoxarifado;
		while(Auxiliar_Almoxarifado != NULL){
			if(Auxiliar_Almoxarifado->id == IDBuscar){
				MSGI("ID: ", Auxiliar_Almoxarifado->id);
				MSGS("Nome:", Auxiliar_Almoxarifado->nome);
				MSGS("Descrição: ", Auxiliar_Almoxarifado->descricao);
				MSGI("Quantidade: ", Auxiliar_Almoxarifado->quantidade);
				MSGF("Preço: ", Auxiliar_Almoxarifado->preco);
				QUEBRA_LINHA;
				break;
			}
			Auxiliar_Almoxarifado = Auxiliar_Almoxarifado->next;	
		}
	}else{
		Auxiliar_Almoxarifado = Inicio_Almoxarifado;
		while(Auxiliar_Almoxarifado != NULL){
			MSGI("ID: ", Auxiliar_Almoxarifado->id);
			MSGS("Nome:", Auxiliar_Almoxarifado->nome);
			QUEBRA_LINHA;
			Auxiliar_Almoxarifado = Auxiliar_Almoxarifado->next;	
		}
	}
	PAUSA;
}

void Procurar_Almoxarifado(){
	char str[80];
	MSG("Informe o nome do produto: ");
	CB;
	scanf("%[^\n]", str);
	
	Auxiliar_Almoxarifado = Inicio_Almoxarifado;
	while(Auxiliar_Almoxarifado != NULL){
		if(String_Matching(Auxiliar_Almoxarifado->nome, str)){
			MSGI("ID: ", Auxiliar_Almoxarifado->id);
			MSGS("Nome:", Auxiliar_Almoxarifado->nome);
			QUEBRA_LINHA;
		}
		Auxiliar_Almoxarifado = Auxiliar_Almoxarifado->next;
	}
	PAUSA;	
}

void Atualizar_Almoxarifado(){
	int manter = 1;
	while(manter){
		switch(MenuAtualizacaoAlmoxarifado(0)){
			case 1:
			Editar_Produto_Almoxarifado();
			Gravar_Lista_Almoxarifado();
			break;
			
			case 2:
			Exluir_Produto_Almoxarifado();
			Gravar_Lista_Almoxarifado();
			break;
			
			case 0:
			manter = Sair();
			break; 
			
			default:
			MSG("Opção inválida!");
			MSG("Tente novamente!");
			PAUSA;
		}
	}
}

void Editar_Produto_Almoxarifado(){
	CLS;
	int IDEdicao = -1, Flag = 0;
	MSG("Informe o ID que terá os dados editados: ");
	scanf("%i", &IDEdicao);
	
	Auxiliar_Almoxarifado = Inicio_Almoxarifado;
	while(!(Auxiliar_Almoxarifado == NULL)){
	 	if(Auxiliar_Almoxarifado->id == IDEdicao){
	 		MSG("NOME: ");
			CB;
			scanf("%[^\n]", Novo_Almoxarifado->nome);
			
			MSG("DESCRIÇÃO DO PRODUTO: ");
			CB;
			scanf("%[^\n]", Novo_Almoxarifado->descricao);
			
			MSG("QUANTIDADE: ");
			CB;
			scanf("%i", &Novo_Almoxarifado->quantidade);
			
			MSG("PREÇO DE MERCADO: R$ ");
			CB;
			scanf("%f", &Novo_Almoxarifado->preco);
			
			Flag = 1;
			MSG("");
			MSG("Alterações realizadas!");
			break;	
		}
		Auxiliar_Almoxarifado = Auxiliar_Almoxarifado->next;
	}
	
	if(!Flag){
		MSG("ID não encontrado!");
	}
}

void Exluir_Produto_Almoxarifado(){
	int IDExcluir, Flag = 0;
	MSG("Informe o ID do produto: ");
	CB;
	scanf("%i", &IDExcluir);
	
	Auxiliar_Ajuda = NULL;
	Auxiliar_Almoxarifado = Inicio_Almoxarifado;
	while(Auxiliar_Almoxarifado != NULL){
		if(Auxiliar_Almoxarifado->id == IDExcluir){
			Flag = 1;
			break;
		}
		Auxiliar_Ajuda = Auxiliar_Almoxarifado;
		Auxiliar_Almoxarifado = Auxiliar_Almoxarifado->next;
	}
	
	if (Flag){
		if(Auxiliar_Ajuda == NULL){
			Novo_Almoxarifado = Inicio_Almoxarifado;		
			Inicio_Almoxarifado = Inicio_Almoxarifado->next;
			free(Novo_Almoxarifado);
			MSG("Ítem excluído!");
			MSG("\n");
		}else{
			Novo_Almoxarifado = Auxiliar_Almoxarifado;
			Auxiliar_Ajuda->next = Auxiliar_Almoxarifado->next;
			free(Novo_Almoxarifado);
		}
	}else{
		MSG("ID não encontrado!");
		MSG("\n");
	}
	PAUSA;
}
