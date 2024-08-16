//FUNÇÕES DA INDEX
void Cadmo();

int String_Matching(char *palavra_1, char *palavra_2);

int MenuIndex1(int OPCAO);
int MenuIndex2(int OPCAO);

int Sair();
void Carregar_Clientes();

void Sistema_Login();
int Menu_Login(int OPCAO);

void Sistema_De_Cadastro();
int Menu_Cadastro(int OPCAO);
int Criar_ID();
Cliente* Iniciar_Cliente();
Lista_C* Iniciar_Lista_C();
Lista_A* Iniciar_Lista_A();
void Ler_Cliente(Cliente *C);
void Adicionar_Cliente_Na_Lista(Cliente *C);
Administrador* Iniciar_Administrador();
void Ler_Administrador(Administrador *A);
void Adicionar_Administrador_Na_Lista(Administrador *A);

void Sistema_De_Busca();
int MenuBusca(int OPCAO);
void Listar_Pessoa(Lista_C *LISTA, int MODO);
void Listar_Administrador(Lista_A *LISTA, int MODO, int TIPO);
int Perguntar_Modo(int MODO);
void Exibir_Pessoa(Cliente *DADOS, int MODO);
void Exibir_Login(Administrador *DADOS, int MODO);

void Sistema_De_Perfil();
int MenuPerfil(int OPCAO);

void Sistema_De_Atualizacao();
int MenuAtualizacao(int OPCAO);
int MenuEdicao(int OPCAO);
void Sistema_de_Edicao();
void Editar_Pessoa(Lista_C *LISTA);
void Editar_Administrador(Lista_A *LISTA);
int MenuExclusao(int OPCAO);
void Sistema_de_Exclusao();
void Excluir_Cliente(Lista_C *LISTA);
void Excluir_Administrador(Lista_A *LISTA);

void Sistema_De_Anamnese();
int MenuAnamnese(int OPCAO);
Lista_AN* Iniciar_Lista_AN();
Item_Anamnese* Iniciar_Item_Anamnese();
void Ler_Anamnese(Item_Anamnese *ANAMNESE);
void Adicionar_Item_Anamnese_Na_Lista(Item_Anamnese *ITEM);
void Exibir_Anamnese(Item_Anamnese *ANAMNESE, int MODO);
char* Verifica_Sim_ou_Nao(int SINAL);
void Zerar_Anamnese(Item_Anamnese *ANAMNESE);

//Sistema de almoxarifado
void Sistema_De_Almoxarifado();
void Cadastro_Almoxarifado();
void Listar_Produtos(int MODO);
void Procurar_Almoxarifado();
void Atualizar_Almoxarifado();
void Editar_Produto_Almoxarifado();
void Exluir_Produto_Almoxarifado();
int MenuAtualizacaoAlmoxarifado(int OPCAO);
int MenuAlmoxarifado(int OPCAO);

void Sistema_De_Agendamento();
int MenuAgendamento(int OPCAO);
void Marcar_Consulta(Consulta *C);
void Registrar_Consulta();
void Remarcar_Consulta();
void Desmarcar_Consulta();
void Listar_Consultas();
void Ler_Consulta(Consulta *C);
Lista_AG* Iniciar_Lista_AG();
Consulta* Iniciar_Consulta();
void Verifica_Consulta(Consulta *C);
void Exibir_Consulta(Consulta *C);

//Funções de Gravação
void Gravar_Lista_Cliente();
void Gravar_Lista_Administrador();
void Gravar_Lista_Anamnese();
void Gravar_Lista_Almoxarifado();
void Gravar_Lista_Agendamento();

//Funções de Leitura
void Recuperar_Lista_Cliente();
void Recuperar_Lista_Administrador();
void Recuperar_Lista_Anamnese();
void Recuperar_Lista_Almoxarifado();
void Recuperar_Lista_Agendamento();

//Tamanho das listas
int Tamanho_Clientes(int T);
int Tamanho_Administradores(int T);
int Tamanho_Anamneses(int T);
int Tamanho_Agenda(int T);
int Tamanho_Almoxarifado(int T);
