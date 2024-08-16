typedef struct CLIENTE{
	int ID;
	char nome[80];
	char dataNascimento[80];;
	char sexo;
	char telefone[80];;
	char cidade[80];
	char endereco[80];
	struct CLIENTE *next;
}Cliente;

typedef struct ADMINISTRADOR{
	int ID;
	char nome[80];
	char login[5];
	char senha[5];
	int tipo;
	struct ADMINISTRADOR *next;
}Administrador;

typedef struct LISTA_CLIENTE{
	Cliente *inicio;
	Cliente *fim;
	Cliente *ajuda;
	Cliente *auxiliar;
}Lista_C;

typedef struct LISTA_ADMINISTRADOR{
	Administrador *inicio;
	Administrador *fim;
	Administrador *ajuda;
	Administrador *auxiliar;
}Lista_A;

typedef struct ITEM_ANAMNESE{
	int IDCliente;
	int gravidez;
	int usaMedicacao;
	char medicacaoDescricao[100];
	int alergia;
	char alergiaDescricao[100];
	int cicatrizacaoP;
	int anestesiaP;
	int hemorragia;
	int febreReumatica;
	int cardiacosP;
	int respiratorioP;
	int hipertensaoP;
	int diabetes;
	char observacoes[100];
	struct ITEM_ANAMNESE *next;
}Item_Anamnese;

typedef struct LISTA_ANAMNESE{
	Item_Anamnese *inicio;
	Item_Anamnese *fim;
	Item_Anamnese *ajuda;
	Item_Anamnese *auxiliar;
}Lista_AN;

typedef struct ALMOXARIFADO{
	//Dados dos produtos
	int id, quantidade;
	char nome[80], descricao[100];
	float preco;
	struct ALMOXARIFADO *next;
}Almoxarifado;

typedef struct CONSULTA{
	int ID;
	int IDDentista;
	int IDCliente;
	char data[11];
	int status;
	struct CONSULTA *next;
}Consulta;

typedef struct AGENDA{
	Consulta *inicio;
	Consulta *fim;
	Consulta *ajuda;
	Consulta *auxiliar;
}Lista_AG;
