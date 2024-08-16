//Menu de opções do Almoxarifado do sistema
int MenuAlmoxarifado(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] CADASTRO DE NOVO PRODUTO\n");
	MSG("[ 2 ] LISTAGEM COMPLETA DE PRODUTO");
	MSG("[ 3 ] LISTAGEM PARCIAL\n");
	MSG("[ 4 ] PROCURAR PRODUTO");
	MSG("[ 5 ] ATUALIZAR ALMOXARIFADO\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	CLS;
	//Retorno da função
	return OPCAO;
}

int MenuAtualizacaoAlmoxarifado(int OPCAO){
	CLS;
	LINHA;
	MSG("[ 1 ] EDITAR");
	MSG("[ 2 ] EXCLUIR\n");
	MSG("[ 0 ] SAIR");
	LINHA;
	MSG("Informe a opção escolhida: ");
	CB;
	scanf("%i", &OPCAO);
	CLS;
	//Retorno de Função
	return OPCAO;
}
