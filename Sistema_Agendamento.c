void Sistema_De_Agendamento(){
	int Manter = 1;
	while(Manter){
		switch(MenuAgendamento(0)){
			case 1:
				consulta = Iniciar_Consulta();
				Ler_Consulta(consulta);
				Verifica_Consulta(consulta);
				Gravar_Lista_Agendamento();
				CLS;
				MSG("Consulta marcada!");
				MSG("\n\n");
				PAUSA;
			break;
			
			case 2:
				Registrar_Consulta();
				Gravar_Lista_Agendamento();
			break;
			
			case 3:
				Desmarcar_Consulta();
				Gravar_Lista_Agendamento();
			break;
			
			case 4:
				Listar_Consultas();
				PAUSA;
			break;
			
			case 0:
			//Sair() deve guardar as listas nos arquivos
			Manter = Sair();
			break;
			
			default:
			MSG("Opção inválida!");
			MSG("Tente novamente!");
		}
	}
}

void Desmarcar_Consulta(){
	int IDConsulta;
	char data[11];
	
	CLS;
	MSG("Informe o número da consulta: ");
	CB;
	scanf("%i", &IDConsulta);
	
	MSG("Informe a data da consulta (dd/mm/aaaa): ");
	CB;
	scanf("%[^\n]", data);
	
	Agenda->auxiliar = NULL;
	Agenda->ajuda = Agenda->inicio;
	while(!(Agenda->ajuda == NULL)){
		if((strcmp(Agenda->ajuda->data, data) == 0) && (Agenda->ajuda->ID == IDConsulta) && (Agenda->ajuda->status != 1)){
			break;
		}
		Agenda->auxiliar = Agenda->ajuda;
		Agenda->ajuda = Agenda->ajuda->next;
	}
	
	if(Agenda->ajuda == NULL){
		CLS;
		MSG("Consulta não encontrada!");
		MSG("Verifique as informações e tente novamente!");
	}else{
		if(Agenda->auxiliar == NULL){
			consulta = Agenda->inicio;
			Agenda->inicio = Agenda->inicio->next;
			free(consulta);
		}else{
			consulta = Agenda->ajuda;
			Agenda->auxiliar->next = Agenda->ajuda->next;
			free(consulta);
		}
		CLS;
		MSG("Consulta desmarcada!");
		MSG("\n\n");
	}
	PAUSA;
}

void Registrar_Consulta(){
	int IDConsulta;
	char data[11];
	
	CLS;
	MSG("Informe o número da consulta: ");
	CB;
	scanf("%i", &IDConsulta);
	
	MSG("Informe a data da consulta (dd/mm/aaaa): ");
	CB;
	scanf("%[^\n]", data);
	
	Agenda->ajuda = Agenda->inicio;
	while(!(Agenda->ajuda == NULL)){
		if((strcmp(Agenda->ajuda->data, data) == 0) && (Agenda->ajuda->ID == IDConsulta)){
			Agenda->ajuda->status = 1;
			CLS;
			MSG("Consulta registrada!");
			MSG("\n\n");
			PAUSA;
			break;
		}
		Agenda->ajuda = Agenda->ajuda->next;
	}
	
	if(Agenda->ajuda == NULL){
		CLS;
		MSG("Consulta não encontrada!");
		MSG("Verifique as informações e tente novamente!");
		MSG("\n\n");
		PAUSA;
	}
}

void Exibir_Consulta(Consulta *C){
	MSGI("Consulta: ", C->ID);
	MSGI("ID Cliente: ", C->IDCliente);
	Clientes->ajuda = Clientes->inicio;
	while(!(Clientes->ajuda == NULL)){
		if(Clientes->ajuda->ID == C->IDCliente){
			break;
		}
		Clientes->ajuda = Clientes->ajuda->next;
	}
	MSGS("Cliente: ", Clientes->ajuda->nome);
	
	MSGI("ID Dentista: ", C->IDDentista);
	Administradores->ajuda = Administradores->inicio;
	while(!(Administradores->ajuda == NULL)){
		if(Administradores->ajuda->ID == C->IDDentista){
			break;
		}
		Administradores->ajuda = Administradores->ajuda->next;
	}
	MSGS("Dentista: ", Administradores->ajuda->nome);
	
	MSGS("Data: ", C->data);
	MSGS("Realizada: ", Verifica_Sim_ou_Nao(C->status));
	MSG("\n");
}

void Listar_Consultas(){
	char dia[11];
	CLS;
	MSG("Informe o dia:");
	CB;
	scanf("%[^\n]", dia);
	
	Agenda->ajuda = Agenda->inicio;
	while(!(Agenda->ajuda == NULL)){
		if((strcmp(Agenda->ajuda->data, dia) == 0) && Agenda->ajuda->status != 1){
			Exibir_Consulta(Agenda->ajuda);
		}
		Agenda->ajuda = Agenda->ajuda->next;
	}
}

void Marcar_Consulta(Consulta *C){
	if(Agenda->inicio == NULL){
		Agenda->inicio = C;
		Agenda->fim = C;
	}else{
		Agenda->fim->next = C;
		Agenda->fim = C;
	}
}

void Verifica_Consulta(Consulta *C){
	int Flag = 0;
	
	Administradores->ajuda = Administradores->inicio;
	while(!(Administradores->ajuda == NULL)){
		if(Administradores->ajuda->ID == C->IDDentista){
			break;
		}
		Administradores->ajuda = Administradores->ajuda->next;
	}
	if(Administradores->ajuda == NULL){
		CLS;
		MSG("Dentista não encontrado!");
		MSG("Verificar o ID e tentar novamente!");
		MSG("\n\n");
		PAUSA;
		Flag = 1;
	}
	
	Clientes->ajuda = Clientes->inicio;
	while(!(Clientes->ajuda == NULL)){
		if(Clientes->ajuda->ID == C->IDCliente){
			break;
		}
		Clientes->ajuda = Clientes->ajuda->next;
	}
	if(Clientes->ajuda == NULL){
		MSG("Cliente não encontrado!");
		MSG("Verificar o ID e tentar novamente!");
		MSG("\n\n");
		PAUSA;
		Flag = 1;
	}
	
	if(!Flag){
		int consultas = 0;
		Agenda->ajuda = Agenda->inicio;
		while(!(Agenda->ajuda == NULL)){
			if(strcmp(Agenda->ajuda->data, C->data) == 0){
				++consultas;
			}
			Agenda->ajuda = Agenda->ajuda->next;
		}
		
		if(consultas < 2){
			C->ID = consultas + 1;
			Marcar_Consulta(C);
		}else{
			CLS;
			MSG("Agenda do dia cheia!");
			MSG("Marcar em outra data!");
			MSG("\n\n");
			PAUSA;
			Ler_Consulta(C);
			Verifica_Consulta(C);
		}
	}
}
//Verificar cliente e dentista
void Ler_Consulta(Consulta *C){
	CLS;
	MSG("Informe o ID do Cliente: ");
	CB;
	scanf("%i", &C->IDCliente);
	
	MSG("Informe o ID do Dentista: ");
	CB;
	scanf("%i", &C->IDDentista);
	
	MSG("Informe a data da consulta (dd/mm/aaaa): ");
	CB;
	scanf("%[^\n]", C->data);
}

Consulta* Iniciar_Consulta(){
	Consulta *c = (Consulta*) calloc(1, sizeof(Consulta));
	c->status = 0;
	c->next = NULL;
	return c;
}

//Menu de opções de Busca no sistema
int MenuAgendamento(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] MARCAR CONSULTA");
	MSG("[ 2 ] REGISTRAR CONSULTA");
	MSG("[ 3 ] DESMARCAR CONSULTA");
	MSG("[ 4 ] LISTAR CONSULTAS DO DIA\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}
