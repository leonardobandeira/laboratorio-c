void Sistema_De_Anamnese(){
	int Manter = 1, IDCliente;
	while(Manter){
		switch(MenuAnamnese(0)){
			case 1:
				CLS;
				MSG("Informe o ID do cliente: ");
				scanf("%i", &IDCliente);
				Clientes->ajuda = Clientes->inicio;
				while(!(Clientes->ajuda == NULL)){
					if(Clientes->ajuda->ID == IDCliente){
						break;
					}
					Clientes->ajuda = Clientes->ajuda->next;
				}
				
				if(Clientes->ajuda == NULL){
					CLS;
					MSG("Cliente n�o encontrado!");
					MSG("\n");
				}else{
					item_anamnese = Iniciar_Item_Anamnese();
					item_anamnese->IDCliente = IDCliente;
					Ler_Anamnese(item_anamnese);
					Adicionar_Item_Anamnese_Na_Lista(item_anamnese);
					MSGC("Anamnese cadastrada!", 1);
					Gravar_Lista_Anamnese();
					MSG("\n");
					//Gravar Lista no arquivo;
				}
			break;
			
			case 2:
				Anamneses->ajuda = Anamneses->inicio;
				while(!(Anamneses->ajuda == NULL)){
					Exibir_Anamnese(Anamneses->ajuda, 0);
					Anamneses->ajuda = Anamneses->ajuda->next;
				}
			break;
			
			case 3:
				CLS;
				MSG("Informe o ID do cliente: ");
				scanf("%i", &IDCliente);
				Clientes->ajuda = Clientes->inicio;
				while(!(Clientes->ajuda == NULL)){
					if(Clientes->ajuda->ID == IDCliente){
						break;
					}
					Clientes->ajuda = Clientes->ajuda->next;
				}
				
				if(Clientes->ajuda == NULL){
					CLS;
					MSG("Cliente n�o encontrado!");
					MSG("\n");
				}else{
					Anamneses->ajuda = Anamneses->inicio;
					while(!(Anamneses->ajuda == NULL)){
						if(Anamneses->ajuda->IDCliente == IDCliente){
							Exibir_Anamnese(Anamneses->ajuda, 1);
							break;
						}
						Anamneses->ajuda = Anamneses->ajuda->next;
					}
					MSG("\n");
				}
			break;
			
			case 4:
				CLS;
				MSG("Informe o ID do cliente: ");
				scanf("%i", &IDCliente);
				Clientes->ajuda = Clientes->inicio;
				while(!(Clientes->ajuda == NULL)){
					if(Clientes->ajuda->ID == IDCliente){
						break;
					}
					Clientes->ajuda = Clientes->ajuda->next;
				}
				
				if(Clientes->ajuda == NULL){
					CLS;
					MSG("Cliente n�o encontrado!");
					MSG("\n");
				}else{
					Anamneses->ajuda = Anamneses->inicio;
					while(!(Anamneses->ajuda == NULL)){
						if(Anamneses->ajuda->IDCliente == IDCliente){
							Ler_Anamnese(Anamneses->ajuda);
							MSG("Anamnese atualizada!");
							Gravar_Lista_Anamnese();
							MSG("\n");
							break;
						}
						Anamneses->ajuda = Anamneses->ajuda->next;
					}
				}
			break;
			
			case 5:
				CLS;
				MSG("Informe o ID do cliente: ");
				scanf("%i", &IDCliente);
				Clientes->ajuda = Clientes->inicio;
				while(!(Clientes->ajuda == NULL)){
					if(Clientes->ajuda->ID == IDCliente){
						break;
					}
					Clientes->ajuda = Clientes->ajuda->next;
				}
				
				if(Clientes->ajuda == NULL){
					CLS;
					MSG("Cliente n�o encontrado!");
					MSG("\n");
				}else{
					Anamneses->auxiliar = NULL;
					Anamneses->ajuda = Anamneses->inicio;
					while(!(Anamneses->ajuda == NULL)){
						if(IDCliente == Anamneses->ajuda->IDCliente){
							break;
						}
						Anamneses->auxiliar = Anamneses->ajuda;
						Anamneses->ajuda = Anamneses->ajuda->next;
					}
					
					if(Anamneses->ajuda == NULL){
						CLS;
						MSG("Anamnese n�o encontrada!");
						MSG("");
					}else{
						if(Anamneses->auxiliar == NULL){
							item_anamnese = Anamneses->inicio;
							Anamneses->inicio = Anamneses->inicio->next;
							free(item_anamnese);
						}else{
							item_anamnese = Anamneses->ajuda;
							Anamneses->auxiliar->next = Anamneses->ajuda->next;
							free(item_anamnese);
						}
					CLS;
					Gravar_Lista_Anamnese();
					MSG("Anamnese excluida!");
					MSG("\n");
					}				

				}
			break;
			
			case 0:
			//Sair() deve guardar as listas nos arquivos
			Manter = Sair();
			break;
			
			default:
			MSG("Op��o inv�lida!");
			MSG("Tente novamente!");
		}
		PAUSA;
	}
}

char* Verifica_Sim_ou_Nao(int SINAL){
	if(SINAL){
		return "SIM";
	}else{
		return "N�O";
	}
}

void Exibir_Anamnese(Item_Anamnese *ANAMNESE, int MODO){	
	//Lista b�sica de informa��es
	MSGI("ID: ", ANAMNESE->IDCliente);
	Clientes->ajuda = Clientes->inicio;
	while(!(Clientes->ajuda == NULL)){
		if(Clientes->ajuda->ID == ANAMNESE->IDCliente){
			MSGS("NOME: ", Clientes->ajuda->nome);
			break;
		}
		Clientes->ajuda = Clientes->ajuda->next;
	}
	//Listagem avan�ada das informa��es da anamnese
	if(MODO){
		MSGS("Gravidez: ", Verifica_Sim_ou_Nao(ANAMNESE->gravidez));
		MSGS("Usa medica��o: ", Verifica_Sim_ou_Nao(ANAMNESE->usaMedicacao));
		if(ANAMNESE->usaMedicacao){
			MSGS("Descri��o da medica��o: ", ANAMNESE->medicacaoDescricao);
		}
		MSGS("Alergias: ", Verifica_Sim_ou_Nao(ANAMNESE->alergia));
		if(ANAMNESE->alergia){
			MSGS("Descri��o da(s) alergia(s): ", ANAMNESE->alergiaDescricao);
		}
		//cardiacosP; respiratorioP;hipertensaoP; diabetes; *observacoes;
		MSGS("Problemas de cicatriza��o: ", Verifica_Sim_ou_Nao(ANAMNESE->cicatrizacaoP));
		MSGS("Problemas com anestesia: ", Verifica_Sim_ou_Nao(ANAMNESE->anestesiaP));
		MSGS("Problemas com hemorragia: ", Verifica_Sim_ou_Nao(ANAMNESE->hemorragia));
		MSGS("Possui febre reum�tica: ", Verifica_Sim_ou_Nao(ANAMNESE->febreReumatica));
		MSGS("Possui problemas cardiacos: ", Verifica_Sim_ou_Nao(ANAMNESE->cardiacosP));
		MSGS("Possui problemas respirat�rios: ", Verifica_Sim_ou_Nao(ANAMNESE->respiratorioP));
		MSGS("Possui hipertens�o: ", Verifica_Sim_ou_Nao(ANAMNESE->hipertensaoP));
		MSGS("Possui diabetes: ", Verifica_Sim_ou_Nao(ANAMNESE->diabetes));
		MSGS("OBSERVA��ES: ", ANAMNESE->observacoes);
	}
	MSG("\n");
}

void Adicionar_Item_Anamnese_Na_Lista(Item_Anamnese *ITEM){
	if(Anamneses->inicio == NULL){
		Anamneses->inicio = ITEM;
		Anamneses->fim = ITEM;
	}else{
		Anamneses->auxiliar = Anamneses->inicio;
		Anamneses->ajuda = Anamneses->inicio->next;
		while(!(Anamneses->ajuda == NULL)){
			if(ITEM->IDCliente < Anamneses->ajuda->IDCliente){
				break;
			}
			Anamneses->auxiliar = Anamneses->ajuda;
			Anamneses->ajuda = Anamneses->ajuda->next;
		}
		
		if(Anamneses->auxiliar == Anamneses->inicio){
			ITEM->next = Anamneses->inicio;
			Anamneses->inicio = ITEM;
		}else if(Anamneses->auxiliar->next == NULL){
			Anamneses->fim->next = ITEM;
			Anamneses->fim = ITEM;
		}else{
			Anamneses->auxiliar->next = ITEM;
			ITEM->next = Anamneses->ajuda;
		}
	}
}

void Zerar_Anamnese(Item_Anamnese *ANAMNESE){
	ANAMNESE->alergia= 0;
	strcpy(ANAMNESE->alergiaDescricao, "");
	ANAMNESE->anestesiaP = 0;
	ANAMNESE->cardiacosP = 0;
	ANAMNESE->cicatrizacaoP = 0;
	ANAMNESE->diabetes = 0;
	ANAMNESE->febreReumatica = 0;
	ANAMNESE->gravidez = 0;
	ANAMNESE->hipertensaoP = 0;
	strcpy(ANAMNESE->medicacaoDescricao , "");
	strcpy(ANAMNESE->observacoes, "");
	ANAMNESE->respiratorioP = 0;
	ANAMNESE->usaMedicacao = 0;
}

void Ler_Anamnese(Item_Anamnese *ANAMNESE){
	//Pregunta por uso de medica��o
	Zerar_Anamnese(ANAMNESE);
	
	MSG("Est� fazendo uso de alguma medica��o (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->usaMedicacao);
	if(ANAMNESE->usaMedicacao){
		MSG("Qual(is): ");
		CB;
		scanf("%[^\n]", ANAMNESE->medicacaoDescricao);
	}else{
		strcpy(ANAMNESE->medicacaoDescricao, "");
	}
	
	//Pergunta por poss�vel gravidez
	MSG("Gravidez (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->gravidez);
	
	//Pergunta por alergias
	MSG("Teve alergia (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->alergia);
	if(ANAMNESE->alergia){
		MSG("Qual(is): ");
		CB;
		scanf("%[^\n]", ANAMNESE->alergiaDescricao);
	}else{
		strcpy(ANAMNESE->alergiaDescricao, "");
	}
	
	// Pergunta por problemas de cicatriza��o
	MSG("Teve problemas com a cicatriza��o (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->cicatrizacaoP);
	
	//Pergunta por problemas com anestesia
	MSG("Problemas com a anestesia (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->anestesiaP);
	
	//Pergunta por problemas com hemorragia
	MSG("Teve problemas de hemorragia (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->hemorragia);
	
	//Pergunta por problemas com febre reum�tica
	MSG("Sofre de febre reum�tica (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->febreReumatica);
	
	//Pergunta por problemas com hemorragia
	MSG("Sofre de problemas card�acos (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->cardiacosP);
	
	//Pergunta por problemas respirat�rios
	MSG("Sofre de problemas respirat�rios (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->respiratorioP);
	
	//Pergunta por problemas com diabetes
	MSG("Sofre de diabetes (1/0)?");
	CB;
	scanf("%i", &ANAMNESE->diabetes);
	
	//Pergunta por observa��es
	MSG("Outras observa��es importantes: ");
	CB;
	scanf("%[^\n]", ANAMNESE->observacoes);
}

Item_Anamnese* Iniciar_Item_Anamnese(){
	Item_Anamnese *ITEM = (Item_Anamnese*) calloc(1, sizeof(Item_Anamnese));
	ITEM->next = NULL;
	
	return ITEM;
}

int MenuAnamnese(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] CADASTRAR ANAMNESE");
	MSG("[ 2 ] LISTAR ANAMNESES");
	MSG("[ 3 ] ANAMNESE DE UM CLIENTE");
	MSG("[ 4 ] EDITAR ANAMNESE DE UM CLIENTE");
	MSG("[ 5 ] EXCLUIR ANAMNESE DE UM CLIENTE");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a op��o escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da fun��o
	return OPCAO;
}
