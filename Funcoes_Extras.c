// String Matching retorna se a segunda string esta dentro da primeira
// Retorna 1 caso exista e 0 caso contrário
int String_Matching(char *palavra_1, char *palavra_2){
	char p1[80];
	char p2[80];
	
	strcpy(p1, palavra_1);
	strcpy(p2, palavra_2);
	
	strupr(p1);
	strupr(p2);
	
	int tamanho_1 = strlen(p1);
	int tamanho_2 = strlen(p2);
	
	int i = -1;
	int j = -1;
	while(!(p1[++i] == '\0')){
		j = -1;
		while((++j < tamanho_2) && (p2[j] == p1[i+j])){}
		
		if(j == tamanho_2){
			return 1;
		}
	}
	return 0;
}
