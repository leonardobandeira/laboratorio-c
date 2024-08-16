void Sistema_Login(){
	int Manter = 1;
	
	while(Manter){
		int contC = 0;
		char login[5] = "", senha[5] = "", tecla[2] = "", logar = '0';
		senha[4] = '\0';
		tecla[1] = '\0';
		PAUSA;
		switch(Menu_Login(0)){
			case 1:
				CLS;
				MSG("LOGIN: ");
				CB;
				gets(login);
				CB;
				MSG("SENHA: ");			
				while(contC < 4){
					CB;
					tecla[0] = getch();
					if(isalnum(tecla[0]) && contC < 4){
						strcat(senha, tecla);
						contC++;
						printf("*");
					}
				}
				MSG("\n");
				MSG("TENTAR LOGIN (1/0)?  ");
				CB;
				scanf("%c", &logar);
				if(logar == '1'){
					CLS;
					Administradores->ajuda = Administradores->inicio;
					while(!(Administradores->ajuda == NULL)){
						if(strcmp(login, Administradores->ajuda->login) == 0){
							if(strcmp(senha, Administradores->ajuda->senha) == 0){
								cookie = Administradores->ajuda;
								Flag_Logado = 1;
								Cadmo();
								break;
							}else{
								MSG("Senha incorreta!");
								MSG("\n\n");
							}
						}else{
							MSG("Login incorreto!");
							MSG("\n\n");
						}
						Administradores->ajuda = Administradores->ajuda->next;
					}
				}				
			break;
			
			case 0:
				Manter = Sair();
			break;
			
			default:
			MSG("Opção inválida!");
			MSG("Tente novamente!");
			PAUSA;
		}
	}
}

int Menu_Login(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] ENTRAR\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}
