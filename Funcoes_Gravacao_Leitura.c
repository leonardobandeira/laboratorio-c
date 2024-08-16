//Funções de Gravação
void Gravar_Lista_Cliente(){
	FILE *Arquivo, *Quant_Arquivo;

	unlink("bd/Clientes.dat");
	unlink("bd/quant_Clientes.dat");
	
	Arquivo = fopen("bd/Clientes.dat", "wb");
	Quant_Arquivo = fopen("bd/quant_Clientes.dat", "wb");
	
	Clientes->ajuda = Clientes->inicio;	
	while(!(Clientes->ajuda == NULL)){
		fwrite(Clientes->ajuda, sizeof(Cliente), 1, Arquivo);
		Clientes->ajuda = Clientes->ajuda->next;
	}
	fprintf(Quant_Arquivo, "%i", Tamanho_Clientes(0));
	fclose(Quant_Arquivo);
	fclose(Arquivo);
}

void Gravar_Lista_Administrador(){
	FILE *Arquivo, *Quant_Arquivo;
	unlink("bd/Administradores.dat");
	unlink("bd/quant_Administradores.dat");
	
	Arquivo = fopen("bd/Administradores.dat", "wb");
	Quant_Arquivo = fopen("bd/quant_Administradores.dat", "wb");
	
	Administradores->ajuda = Administradores->inicio;	
	while(!(Administradores->ajuda == NULL)){
		fwrite(Administradores->ajuda, sizeof(Administrador), 1, Arquivo);
		Administradores->ajuda = Administradores->ajuda->next;
	}
	fprintf(Quant_Arquivo, "%i", Tamanho_Administradores(0));
	fclose(Quant_Arquivo);
	fclose(Arquivo);
}

void Gravar_Lista_Anamnese(){
	FILE *Arquivo, *Quant_Arquivo;
	unlink("bd/Anamneses.dat");
	unlink("bd/quant_Anamneses.dat");
	
	Arquivo = fopen("bd/Anamneses.dat", "wb");
	Quant_Arquivo = fopen("bd/quant_Anamneses.dat", "wb");
	
	Anamneses->ajuda = Anamneses->inicio;	
	while(!(Anamneses->ajuda == NULL)){
		fwrite(Anamneses->ajuda, sizeof(Item_Anamnese), 1, Arquivo);
		Anamneses->ajuda = Anamneses->ajuda->next;
	}
	fprintf(Quant_Arquivo, "%i", Tamanho_Anamneses(0));
	fclose(Quant_Arquivo);
	fclose(Arquivo);
}

void Gravar_Lista_Almoxarifado(){
	FILE *Arquivo, *Quant_Arquivo;
	unlink("bd/Almoxarifado.dat");
	unlink("bd/quant_Almoxarifado.dat");
	
	Arquivo = fopen("bd/Almoxarifado.dat", "wb");
	Quant_Arquivo = fopen("bd/quant_Almoxarifado.dat", "wb");
	
	Auxiliar_Ajuda = Inicio_Almoxarifado;	
	while(!(Auxiliar_Ajuda == NULL)){
		fwrite(Auxiliar_Ajuda, sizeof(Almoxarifado), 1, Arquivo);
		Auxiliar_Ajuda = Auxiliar_Ajuda->next;
	}
	fprintf(Quant_Arquivo, "%i", Tamanho_Almoxarifado(0));
	fclose(Quant_Arquivo);
	fclose(Arquivo);
}

void Gravar_Lista_Agendamento(){
	FILE *Arquivo, *Quant_Arquivo;
	unlink("bd/Agenda.dat");
	unlink("bd/quant_Agenda.dat");
	
	Arquivo = fopen("bd/Agenda.dat", "wb");
	Quant_Arquivo = fopen("bd/quant_Agenda.dat", "wb");
	
	Agenda->ajuda = Agenda->inicio;	
	while(!(Agenda->ajuda == NULL)){
		fwrite(Agenda->ajuda, sizeof(Consulta), 1, Arquivo);
		Agenda->ajuda = Agenda->ajuda->next;
	}
	fprintf(Quant_Arquivo, "%i", Tamanho_Agenda(0));
	fclose(Quant_Arquivo);
	fclose(Arquivo);
}

//Funções de Leitura
void Recuperar_Lista_Cliente(){
	int i, quantidade;
	FILE *Arquivo;
	FILE *Quant_Arquivo;
	
	Arquivo = fopen("bd/Clientes.dat", "rb");
	Quant_Arquivo = fopen("bd/quant_Clientes.dat", "rb");
	if(Arquivo == NULL){
		Clientes = Iniciar_Lista_C();
	}else{
		fscanf(Quant_Arquivo, "%i", &quantidade);
		for(i = 0; i < quantidade; ++i){
			cliente = Iniciar_Cliente();
			fseek(Arquivo, sizeof(Cliente)*i, SEEK_SET);
			fread(cliente, sizeof(Cliente), 1, Arquivo);
			cliente->next = NULL;
			Adicionar_Cliente_Na_Lista(cliente);
		}
	}
	fclose(Quant_Arquivo);
	fclose(Arquivo);
}

void Recuperar_Lista_Administrador(){
	int i, quantidade;
	FILE *Arquivo;
	FILE *Quant_Arquivo;
	
	Arquivo = fopen("bd/Administradores.dat", "rb");
	Quant_Arquivo = fopen("bd/quant_Administradores.dat", "rb");
	if(Arquivo == NULL){
		Administradores = Iniciar_Lista_A();
	}else{
		fscanf(Quant_Arquivo, "%i", &quantidade);
		for(i = 0; i < quantidade; ++i){
			administrador = Iniciar_Administrador();
			fseek(Arquivo, sizeof(Administrador)*i, SEEK_SET);
			fread(administrador, sizeof(Administrador), 1, Arquivo);
			administrador->next = NULL;
			Adicionar_Administrador_Na_Lista(administrador);
		}
	}
	fclose(Quant_Arquivo);
	fclose(Arquivo);
}

void Recuperar_Lista_Anamnese(){
	int i, quantidade;
	FILE *Arquivo;
	FILE *Quant_Arquivo;
	
	Arquivo = fopen("bd/Anamneses.dat", "rb");
	Quant_Arquivo = fopen("bd/quant_Anamneses.dat", "rb");
	if(Arquivo == NULL){
		Anamneses = Iniciar_Lista_AN();
	}else{
		fscanf(Quant_Arquivo, "%i", &quantidade);
		for(i = 0; i < quantidade; ++i){
			item_anamnese = Iniciar_Item_Anamnese();
			fseek(Arquivo, sizeof(Item_Anamnese)*i, SEEK_SET);
			fread(item_anamnese, sizeof(Item_Anamnese), 1, Arquivo);
			item_anamnese->next = NULL;
			Adicionar_Item_Anamnese_Na_Lista(item_anamnese);
		}
	}
	fclose(Quant_Arquivo);
	fclose(Arquivo);
}

void Recuperar_Lista_Almoxarifado(){
	FILE *Arquivo, *Quant_Arquivo;
	int quant_Arquivos, i;
	
	Arquivo = fopen("bd/Almoxarifado.dat", "rb");
	Quant_Arquivo = fopen("bd/quant_Almoxarifado.dat", "rb");
	
	if(Arquivo == NULL){
		Inicio_Almoxarifado = NULL;
		Fim_Almoxarifado = NULL;
		Novo_Almoxarifado = NULL;
		Auxiliar_Almoxarifado = NULL;
		Auxiliar_Ajuda = NULL;
	}else{
		fscanf(Quant_Arquivo, "%i", &quant_Arquivos);
		for(i = 0; i < quant_Arquivos; ++i){
			
			Novo_Almoxarifado = (Almoxarifado*) calloc (1, sizeof(Almoxarifado));
			fseek(Arquivo, sizeof(Almoxarifado)*i, SEEK_SET);
			fread(Novo_Almoxarifado, sizeof(Almoxarifado), 1, Arquivo);
			Novo_Almoxarifado->next = NULL;
			
			if(Inicio_Almoxarifado == NULL){
				Inicio_Almoxarifado = Novo_Almoxarifado;
				Fim_Almoxarifado = Novo_Almoxarifado;
			}else{
				Fim_Almoxarifado->next = Novo_Almoxarifado;
				Fim_Almoxarifado = Novo_Almoxarifado;
			}
		}
	}
	fclose(Quant_Arquivo);
	fclose(Arquivo);	
}

void Recuperar_Lista_Agendamento(){
	int i, quantidade;
	FILE *Arquivo;
	FILE *Quant_Arquivo;
	
	Arquivo = fopen("bd/Agenda.dat", "rb");
	Quant_Arquivo = fopen("bd/quant_Agenda.dat", "rb");
	
	if(Arquivo == NULL){
		Agenda = Iniciar_Lista_AG();
	}else{
		fscanf(Quant_Arquivo, "%i", &quantidade);
		for(i = 0; i < quantidade; ++i){
			consulta = Iniciar_Consulta();
			fseek(Arquivo, sizeof(Consulta) * i, SEEK_SET);
			fread(consulta, sizeof(Consulta), 1, Arquivo);
			consulta->next = NULL;
			Marcar_Consulta(consulta);
		}
	}
	fclose(Quant_Arquivo);
	fclose(Arquivo);
}

//Contar tamanho das listas
int Tamanho_Clientes(int T){
	Clientes->ajuda = Clientes->inicio;
	while(!(Clientes->ajuda == NULL)){
		++T;
		Clientes->ajuda = Clientes->ajuda->next;
	}
	return T;
}
int Tamanho_Administradores(int T){
	Administradores->ajuda = Administradores->inicio;
	while(!(Administradores->ajuda == NULL)){
		++T;
		Administradores->ajuda = Administradores->ajuda->next;
	}
	return T;
}
int Tamanho_Anamneses(int T){
	Anamneses->ajuda = Anamneses->inicio;
	while(!(Anamneses->ajuda == NULL)){
		++T;
		Anamneses->ajuda = Anamneses->ajuda->next;
	}
	return T;
}
int Tamanho_Agenda(int T){
	Agenda->ajuda = Agenda->inicio;
	while(!(Agenda->ajuda == NULL)){
		++T;
		Agenda->ajuda = Agenda->ajuda->next;
	}
	return T;
}
int Tamanho_Almoxarifado(int T){
	Auxiliar_Almoxarifado = Inicio_Almoxarifado;
	while(Auxiliar_Almoxarifado != NULL){
		++T;	
		Auxiliar_Almoxarifado = Auxiliar_Almoxarifado->next;
	}
	return T;
}

