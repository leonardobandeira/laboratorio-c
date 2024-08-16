void Sistema_De_Cadastro(){
	int Manter = 1;
	while(Manter){
		switch(Menu_Cadastro(0)){
			case 1:
				cliente = Iniciar_Cliente();
				Ler_Cliente(cliente);
				Adicionar_Cliente_Na_Lista(cliente);
				MSGC("Cadastro realizado!", 1);
				Gravar_Lista_Cliente();
				MSG("\n");
			break;
			
			case 2:
				administrador = Iniciar_Administrador();
				Ler_Administrador(administrador);
				administrador->tipo = 1;
				Adicionar_Administrador_Na_Lista(administrador);
				MSGC("Cadastro realizado!", 1);
				Gravar_Lista_Administrador();
				MSG("\n");
			break;
			
			case 3:
				administrador = Iniciar_Administrador();
				Ler_Administrador(administrador);
				administrador->tipo = 2;
				Adicionar_Administrador_Na_Lista(administrador);
				MSGC("Cadastro realizado!", 1);
				Gravar_Lista_Administrador();
				MSG("\n");
			break;
						
			case 0:
				Manter = Sair();
			break;
			
			default:
				MSG("Opção inválida!");
				MSG("Tente novamente!");
		}
		PAUSA;
	}
}

void Adicionar_Cliente_Na_Lista(Cliente *C){
	char nomeCliente[80], nomeC[80];
	if(Clientes->inicio == NULL){
		Clientes->inicio = C;
		Clientes->fim = C;
	}else{
		Clientes->auxiliar = NULL;
		Clientes->ajuda = Clientes->inicio;
		while(!(Clientes->ajuda == NULL)){
			strcpy(nomeCliente, Clientes->ajuda->nome);
			strcpy(nomeC, C->nome);
			
			strupr(nomeCliente);
			strupr(nomeC);
			
			if(strcmp(nomeCliente, nomeC) == 1){
				break;
			}
			Clientes->auxiliar = Clientes->ajuda;
			Clientes->ajuda = Clientes->ajuda->next;
		}
		
		if(Clientes->auxiliar == NULL){
			C->next = Clientes->inicio;
			Clientes->inicio = C;
		}else if(Clientes->auxiliar->next == NULL){
			Clientes->fim->next = C;
			Clientes->fim = C;
		}else{
			Clientes->auxiliar->next = C;
			C->next = Clientes->ajuda;
		}
	}
}

void Adicionar_Administrador_Na_Lista(Administrador *A){
	char nomeAdm[80], nomeA[80];
	
	if(Administradores->inicio == NULL){
		Administradores->inicio = A;
		Administradores->fim = A;
	}else{
		Administradores->auxiliar = NULL;
		Administradores->ajuda = Administradores->inicio;
		while(!(Administradores->ajuda == NULL)){
			strcpy(nomeAdm, Administradores->ajuda->nome);
			strcpy(nomeA, A->nome);
			strupr(nomeAdm);
			strupr(nomeA);
			if(strcmp(nomeAdm, nomeA) == 1){
				break;
			}
			Administradores->auxiliar = Administradores->ajuda;
			Administradores->ajuda = Administradores->ajuda->next;
		}
		
		if(Administradores->auxiliar == NULL){
			A->next = Administradores->inicio;
			Administradores->inicio = A;
		}else if(Administradores->auxiliar->next == NULL){
			Administradores->fim->next = A;
			Administradores->fim = A;
		}else{
			Administradores->auxiliar->next = A;
			A->next = Administradores->ajuda;
		}
	}
}

void Ler_Cliente(Cliente *C){
	CLS;
	MSG("NOME: ");
	CB;
	scanf("%[^\n]", C->nome);
	
	MSG("DATA DE NASCIMENTO (dd/mm/aaaa): ");
	CB;
	scanf("%[^\n]", C->dataNascimento);
	
	MSG("SEXO (F/M): ");
	CB;
	scanf("%c", &C->sexo);
	
	MSG("TELEFONE [(xx) 9 1234-5678 ]: ");
	CB;
	scanf("%[^\n]", C->telefone);
	
	MSG("CIDADE: ");
	CB;
	scanf("%[^\n]", C->cidade);
	
	MSG("ENDEREÇO: ");
	CB;
	scanf("%[^\n]", C->endereco);
}

void Ler_Administrador(Administrador *A){
	CLS;
	MSG("NOME: ");
	CB;
	scanf("%[^\n]", A->nome);
	MSG("LOGIN: ");
	CB;
	scanf("%[^\n]", A->login);
	
	MSG("Informe sua senha (4 dígitos): ");
	char tecla, senha[5], temp[5];
	senha[4] = '\0';
	
	int contC = 0, logar = 0;
	while(contC < 4){
		CB;
		tecla = getch();
		if(isalnum(tecla)){
			senha[contC] = tecla;
			printf("*");
			++contC;
		}
	}
	strcpy(temp, senha);
	
	MSG("Confirme sua senha: ");
	contC = 0;
	while(contC < 4){
		CB;
		tecla = getch();
		if(isalnum(tecla)){
			senha[contC] = tecla;
			printf("*");
			++contC;
		}
	}
	MSG("");

	contC = 0;
	while(contC < 4){
		if(temp[contC] == senha[contC]){
			logar = 1;
		}else{
			logar = 0;
			break;
		}
		++contC;
	}
	
	if(logar){
		strcpy(A->senha, senha);
		
		MSGS("Login: ", A->login);
		MSGS("Senha: ", A->senha);
		MSG("\n\n");
		PAUSA;
	}else{
		CLS;
		MSG("Cadastro não realizado,");
		MSG("senha e confirmação");
		MSG("não são iguais!");
		MSG("\n\n\n");
		PAUSA;
		CLS;
		MSG("Deseja tentar novamente (1/0)? ");
		scanf("%i", &contC);
		if(contC){
			Ler_Administrador(administrador);
		}
	}
}

int Menu_Cadastro(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] CADASTRAR CLIENTE");
	MSG("[ 2 ] CADASTRAR DENTISTA");
	MSG("[ 3 ] CADASTRAR ADMINISTRADOR\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}

int Criar_ID(){
	return ++cadastrados;
}

Cliente* Iniciar_Cliente(){
	Cliente *c = (Cliente*) calloc(1, sizeof(Cliente));
	c->ID = Criar_ID();
	c->next = NULL;
	return c;
}

Administrador* Iniciar_Administrador(){
	Administrador *a = (Administrador*) calloc(1, sizeof(Administrador));MSG("1");
	a->ID = Criar_ID();
	a->next = NULL;
	return a;
}
