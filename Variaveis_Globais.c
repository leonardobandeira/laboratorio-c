//DECLARAÇÃO DAS LISTAS
Lista_C *Clientes;
Lista_A *Administradores;
Lista_AN *Anamneses;
Lista_AG *Agenda;

//DECLARAÇÃO VARIÁVEIS AUXILIARES
Cliente *cliente;
Administrador *administrador;
Administrador *cookie;
Item_Anamnese *item_anamnese;
Consulta *consulta;
int cadastrados = 0, Flag_Logado = 0;

// Variáveis da lista de Almoxarifado
Almoxarifado *Inicio_Almoxarifado = NULL;
Almoxarifado *Fim_Almoxarifado = NULL;
Almoxarifado *Novo_Almoxarifado = NULL;
Almoxarifado *Auxiliar_Almoxarifado = NULL;
Almoxarifado *Auxiliar_Ajuda = NULL;

//Contadores de cadastros
int Cont_Almoxarifado = 0;
