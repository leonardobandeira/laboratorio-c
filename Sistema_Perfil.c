void Sistema_De_Perfil(){
	int Manter = 1, Excluir = 0;
	char dia[11];
	
	while(Manter){
		MSG("\n\n");
		switch(MenuPerfil(0)){			
			case 1:
			CLS;
			Ler_Administrador(cookie);
			Gravar_Lista_Administrador();
			MSG("");
			MSG("Alterações realizadas!");
			break;
			
			case 2:
			CLS;
			MSG("Deseja realmente apagar conta (1/0)?");
			CB;
			scanf("%i", &Excluir);
			if(Excluir == 1){
				Administradores->auxiliar = NULL;
				Administradores->ajuda = Administradores->inicio;
				while(!(Administradores->ajuda == NULL)){
					if(Administradores->ajuda->ID == cookie->ID){
						break;
					}
					Administradores->auxiliar = Administradores->ajuda;
					Administradores->ajuda = Administradores->ajuda->next;
				}
				
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
				MSG("Administrador excluido!\n\n");
				free(cookie);
				Gravar_Lista_Administrador();
				Flag_Logado = Sair();
				Manter = Sair();
				PAUSA;
			}else{
				MSG("Operação cancelada!\n\n");
				PAUSA;
			}
			break;
			
			case 3:
				CLS;
				MSG("Informe o dia:");
				CB;
				scanf("%[^\n]", dia);
				
				Agenda->ajuda = Agenda->inicio;
				while(!(Agenda->ajuda == NULL)){
					if((strcmp(Agenda->ajuda->data, dia) == 0) && Agenda->ajuda->status != 1 && Agenda->ajuda->IDDentista == cookie->ID){
						Exibir_Consulta(Agenda->ajuda);
					}
					Agenda->ajuda = Agenda->ajuda->next;
				}
				PAUSA;
			break;
			
			case 0:
				Manter = Sair();
			break;
		}
	}	
}

int MenuPerfil(int OPCAO){
	CLS;
	LINHA;
	Exibir_Login(cookie, 1);
	LINHA;
	MSG("[ 1 ] EDITAR PERFIL\n");
	MSG("[ 2 ] EXCLUIR PERFIL\n");
	if(cookie->tipo == 1){
		MSG("[ 3 ] LISTAR CONSULTAS DO DIA\n");
	}
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	//Retorno da função
	return OPCAO;
}
