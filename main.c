/*Victor Vieira Ribeiro 201911243
Pedro Candido da Silva 201906008
Alcebiades Alves Barbosa Filho 142442
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




//AQUI DECLARO AS FUNÇÕES A SEREM USADAS
int verifica_pos(void);
int verifica_cod( int cod );
int op;
int pos;
void cadastroP(int cod,int pos);
void list(void);
void cadastroPedido(void);
void consultaCod (void);
void excluirCliente (void);
void limparBuffer (void);
void alterarcliente (void);
void cadastro_conta(void);
void list_nome_conta(void);






void limparBuffer (void){
  char c;
  while((c = getchar()) != '\n' && c !=EOF);
}

struct cadastro_conta // struct de cadastro do conta
{
    
    char agencia[10];
    char saldo[25];
    int vazio;
    
    
}vetor_conta[100];

struct transacao{   // struct de transacao
    int valor;
    char data[20];
    char descricao[100];
    struct cadastro_conta conta;
}vetor_trans[100];

struct cadastro_cliente // struct de cadastro do cliente
{
    
    
    char nome[50];
    char CPF[20];
    char endereco[50];
    char telefone[20];
    int  vazio,cod;
    struct cadastro_conta ag;
    struct cadastro_conta sal;
   
}vetor[100];






void insercao_cadastro_cliente_nome (struct cadastro_cliente *vetor, int n)
{
   int i,j;
   struct cadastro_cliente x ;
   for (i = 1; i < n; i++) {
       x = vetor[i];
      for (j = i;(j>0)  && (strcmp(x.nome,vetor[j-1].nome)<0); j--) 
         vetor[j] = vetor [j-1];
      vetor[j] = x;
   }
}


void list_nome_conta(){ // Lista os usuarios cadastrados.
    int i,n; 
      
        insercao_cadastro_cliente_nome (vetor,100);
        
        for(i=0;i < 100; i++){
            
            if(vetor[i].vazio==1){
            
            printf("\nCodigo: %d \nNome: %s\nCPF: %s\nAgencia: %s\nSaldo: %s\n\n", vetor[i].cod,vetor[i].nome,vetor[i].CPF,vetor[i].ag.agencia,vetor[i].sal.saldo);}
            }
        
    printf ("Aperte qualquer tecla  para voltar ao menu principal.........\n\n\n\n\n ");
    char c;
    scanf("%c",&c);
    getchar();
    system("cls");

} //FIM DO LIST

void list_nome(){ // Lista os usuarios cadastrados.
    int i,n; 
      
        insercao_cadastro_cliente_nome (vetor,100);
        for(i=0;i < 100; i++){
            
            if(vetor[i].vazio==1){
            
            printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[i].cod,vetor[i].nome,vetor[i].CPF,vetor[i].endereco,vetor[i].telefone);}
            }
        
    printf ("Aperte qualquer tecla  para voltar ao menu principal.........\n\n\n\n\n ");
    char c;
    scanf("%c",&c);
    getchar();
    system("cls");

} //FIM DO LIST



int busca_cod(struct cadastro_cliente *vetor,int n,int elem){ //FUNÇAO BUSCA CODIGO
    int i;
    for(i=0;i<n;i++){
    if(elem == vetor[i].cod){
        return(i);
    }
}
return(-1);
}                      // FIM DO BUSCA CODIGO

int busca_nome(struct cadastro_cliente *vetor,int n,char* elem){ //FUNÇAO BUSCA NOME
    int i;
    for(i=0;i<n;i++){
    if(strcmp(elem,vetor[i].nome)==0){
        return(i);//elemento encontrado
    }
}
return(-1);//elemento nao encontrado
}

int verifica_pos( void ) //VERIFICADOR DA POSIÇÃO
{
    
    
    for(int i=0;i<100;i++)
    {

        if ( vetor[i].vazio == 0 )
            return(i);
    }

    return(-1);

} // FIM DO VERIFICADOR

int verifica_cod( int cod ) // VERIFICADOR DE CÓDIGO
{
    
    
    if (cod==0) 
    return 0;
    
    for(int i=0;i<100;i++)
    {
        
        if ( vetor[i].cod == cod ){
            return(i);
        }
            
       
    }

    return(1);

} // FIM DO VERIFICADOR


int main(void){ //INICIO DO MAIN

    int i,OpcaoCliente,posicao,retorno;
    int codaux;
    char Opcao;
    do
    {
          printf("\t\t\t\t Digite um comando para prosseguir:\n\n");
          printf("\t\t\t\t C - Gerenciar Clientes\n\n");
          printf("\t\t\t\t T - Gerenciar Contas\n\n");
          printf("\t\t\t\t S - Sair\n \n");
          printf("******************************************************************\n \n");
          scanf("%c",&Opcao);
          getchar();
          
          if(Opcao == 'C' || Opcao == 'c'){
          printf("\t\t\t\t C - Cadastrar um cliente\n\n");
          printf("\t\t\t\t L - Listar todos os clientes cadastrados\n\n");
          printf("\t\t\t\t B - Buscar cliente já cadastrado\n\n");
          printf("\t\t\t\t A - Atualizar um cliente cadastrado\n\n");
          printf("\t\t\t\t E - Excluir um cliente cadastrado\n\n");
          printf("\t\t\t\t S - Sair\n\n");
          printf("\t\t\t\t Selecione uma opcao por favor: \n \n ");
          printf("****************************************************************** \n \n");
          scanf("%c", &Opcao);
          
          getchar();
         
        if (Opcao == 'C' || Opcao == 'c')
        {
            printf("Voce selecionou a opcao  - Cadastrar Novo Cliente\n");
            
            posicao = verifica_pos ();
               
               do{
                    if ( posicao != -1 )
                {

                    printf("\nEntre com um codigo de 1 a 100 para seu cadastro: \n");
                    scanf("%d",&codaux);

                    retorno = verifica_cod( codaux );
            if(codaux<=100){
                    if ( retorno == 1 ){
                        
                          cadastroP( codaux, posicao );}
                          
                          
                        

                    else{
                        printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
                        getchar();
                        system("cls");
                        main();
                    }

                }
                else{
                printf("Codigo invalido tente novamente\n");
            }    
                }
                else{
                    printf("\nNao e possivel realizar mais cadastros!\n");

                break;}
            
        
               printf("\nDigite 1  para efetuar novo cadastro ou qualquer outro numero  para voltar ao menu principal... ");
                               
                          scanf("%d", &op);

                          
                          getchar();
                          if(op!=1){
                          system("cls");
                          main();}
                        }while(op==1);
        }
                else if (Opcao == 'L' || Opcao == 'l')
                {
                    printf("Voce selecionou a opcao  - Listar todos os clientes cadastrados\n\n");
                    printf("Tecle enter para continuar");
                    
                    
                    

                    list_nome();
                    getchar();
                    
                }
                
                else if (Opcao == 'B' || Opcao == 'b')
                {
                
                    printf("Voce selecionou a opcao  - Buscar cliente já cadastrado\n");
                    printf("1 - Buscar por codigo\n\n");
                    printf("2 - Buscar por nome\n\n");
                    printf("3 - Buscar por CPF/CNPJ\n\n");
                    printf("4 - Sair\n\n");
                    int x,ops;
                    scanf("%d",&ops);
                    if(ops == 1){
                    printf("Digite o codigo que deseja procurar:  ");
                    scanf("%d",&x);
                    busca_cod(vetor,100,x);
                    for(i=0;i<100;i++){
                    if(vetor[i].vazio==1){ //verifica se tem elemento na struct
                    if(busca_cod(vetor,100,x) != -1){
                        printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[i].cod,vetor[i].nome,vetor[i].CPF,vetor[i].endereco,vetor[i].telefone);
                    }
                    }
                    }
                    }
                    if(ops == 2){
                    printf("Digite o nome que deseja procurar:  ");
                    char nome[50];
                    scanf("%s", nome);
                    busca_nome(vetor,100,nome);
                    for(i=0;i<100;i++){
                    if(vetor[i].vazio==1){
                    if(busca_nome(vetor,100,nome) != -1){
                        printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[i].cod,vetor[i].nome,vetor[i].CPF,vetor[i].endereco,vetor[i].telefone);
                    }
                    
                    else
                    printf("Nome inválido digite qualquer tecla para sair:");
                    char c;
                    scanf("%c",&c);
                    system("cls");
                    
                    }
                    }
                    }
                
                
                 }

                else if (Opcao == 'A' || Opcao == 'a')
                {
                
                printf("Voce selecionou a opcao  - Atualizar um cliente cadastrado\n");
                
                alterarcliente();
                }
                else if (Opcao == 'E' || Opcao == 'e')
                {
                
                printf("Voce selecionou a opcao  - Excluir Cliente\n");
                
                excluirCliente();
                }
                else if (Opcao == 'S' || Opcao == 's')
                {
                
                printf("Voce selecionou a opcao");

                printf("Deseja mesmo sair?\n");

                getchar();
                system("cls");
                break;
                }
        
                else{
                printf("Opcao invalida, favor pressione enter para voltar ao menu principal");
                getchar();
                system("cls");
                }
                }
                else if (Opcao == 'T' || Opcao == 't'){
                  printf("\t\t\t\t\t R - Listagem de todas as contas cadastradas\n\n");
                  printf("\t\t\t\t\t C - Cadastrar uma conta para um cliente\t\t\t\t\n\n");
                  printf("\t\t\t\t\t L - Listar todas as contas de um cliente\t\t\t\t\n\n");
                  printf("\t\t\t\t\t S - Realizar um saque em uma conta\t\t\t\t\n\n");
                  printf("\t\t\t\t\t D - Realizar um deposito em uma conta\t\t\t\t\n\n");
                  printf("\t\t\t\t\t T - Realizar transferencia entre contas\t\t\t\t\n\n");
                  printf("\t\t\t\t\t E - Exibir extrato de uma conta\t\t\t\t\n\n");
                  printf("\t\t\t\t\t F- Sair\t\t\t\t\n\n");
                  printf(" \t Selecione uma opcao por favor: ");
                  scanf("%c", &Opcao);
                  getchar();
                
                if(Opcao=='R' || Opcao == 'r'){
                    printf("Voce selecionou a opcao - Listagem de todas as contas cadastradas \n");
                    list_nome_conta();
                }
                else if (Opcao == 'C' || Opcao == 'c'){
                    printf ("Voce selecionou a opcao - Cadastrar uma conta para um cliente\n");
                    cadastro_conta();        
                }
                else if (Opcao == 'L' || Opcao == 'l'){
                    printf ("Voce selecionou a opcao - Listar todas as contas de um cliente\n");
                    getchar();
                    main();
                }
                else if (Opcao == 'S' || Opcao == 's' ){
                    printf ("Voce selecionou a opcao - Realizar um saque em uma conta\n");
                }
                else if (Opcao == 'D' || Opcao == 'd'){
                    printf ("Voce selecionou a opcao - Realizar um deposito em uma conta\n");
                }
                else if (Opcao == 'T' || Opcao =='t'){
                    printf ("Voce selecionou a opcao -  Realizar transferencia entre contas\n");   
                }
                else if (Opcao == 'E' || Opcao == 'e'){
                    printf ("Voce selecionou a opcao - Exibir extrato de uma conta\n");
                }  
                else if (Opcao == 'F' || Opcao == 'f'){
                    printf ("Voce selecionou a opcao - Sair\n");
                }
                
                
                }
                else if (Opcao == 'S' || Opcao == 's'){
                    
                printf("Voce deseja mesmo sair?\n\n");
                printf("Digite (S) para sim e (N) para nao. \n\n");
                char c;
                scanf("%c",&c);
                if(c=='S' || c=='s'){
                    break;
                }
                else if(c=='N' || c== 'n'){
                    main();
                }

                }               
                
                
                
               
                }while (Opcao != 's' || Opcao != 'S' || Opcao !='C' || Opcao != 'c' || Opcao !='T'|| Opcao !='t' || Opcao !='L' ||Opcao !='l' ||Opcao !='B' ||Opcao !='b' ||Opcao !='A' ||Opcao !='a'||Opcao !='E'||Opcao !='e'||Opcao !='D'||Opcao !='d'||Opcao !='R'||Opcao !='r'||Opcao !='F'||Opcao !='f');
                
                
                  }

 // FIM DO MAIN
 void cadastroP(int cod, int pos){ //Cadastro das pessoas
    int i;
    
    
    pos = verifica_pos();
    
    vetor[pos].cod = cod;
        
        printf("\nDigite seu nome: ");
        scanf(" %[^\n]", vetor[pos].nome);
        limparBuffer();
        printf("\nDigite seu CPF: ");
        scanf(" %[^\n]", vetor[pos].CPF);
        printf("\nDigite seu Endereco: ");
        scanf(" %[^\n]", vetor[pos].endereco);
        printf("\nDigite seu Telefone: ");
        scanf(" %[^\n]", vetor[pos].telefone);
        vetor[pos].vazio = 1; //salva os dados
       
} // FIM DO CADASTRO DE PESSOAS

//system('cls')-> serve para limpar a tela, porem n funciona no repl.it
void excluirCliente(void)  // INICIO DA EXCLUI CLIENTE
{
    int cod, cont,ops;
    char resp;
    char c;
    char nome[50];
    char CPF[20];
    do{
    printf("\n1-  Excluir registro por Codigo:  \n");
    printf("\n2-  Excluir registro por Nome:  \n");
    printf("\n3-  Excluir registro por CPF/CNPJ:  \n");
    printf("\n4-  Sair: \n");
    
    scanf("%d",&ops);
    if(ops==1){
        
        
        
        for (cont=0; cont < 100 ; cont++ )
    {
        printf("\n Entre com o Codigo do registro que deseja excluir: \n");
        scanf("%d",&cod);

        if ( vetor[cont].cod == cod )
        {

            if (vetor[cont].vazio == 1 )
            {
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[cont].cod,vetor[cont].nome,vetor[cont].CPF,vetor[cont].endereco,vetor[cont].telefone);
                getchar();
                printf("\nDeseja realmente exlucir? s/n: ");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    vetor[cont].vazio = 0;
                    
                    printf("\nExclusao feita com sucesso\n");
                    getchar();
                    main();
                    
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        getchar();
                        main();
                    }
                }

            }

        }
    
        else{
            printf("\nCodigo nao encontrado\n");
            getchar();
            main();}
    }
    }      
    

    
    else if(ops==2){
        printf("\n1- Entre com o Nome do registro que deseja excluir: \n");
        scanf("%s",nome);
        for (cont=0; cont <= 100 ; cont++ ){
            if(strcmp(nome,vetor[cont].nome)==0){
                if (vetor[cont].vazio == 1){    //se ele estiver salvo 
                
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[cont].cod,vetor[cont].nome,vetor[cont].CPF,vetor[cont].endereco,vetor[cont].telefone);
                
                getchar();
                
                printf("\nDeseja realmente exlucir? s/n: ");
                
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    vetor[cont].vazio = 0;
                    vetor[cont].cod = 0;
                    printf("\nExclusao feita com sucesso\n");
                    getchar();
                    main();
                    
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        main();
                    }
                }
                } 
            }
        else{
            printf("\nNome nao encontrado\n");
            getchar();
            main();}
        }
        }





    
    else if (ops==3){
        printf("\n1- Entre com o CPF/CNPJ do registro que deseja excluir: \n");
        scanf("%s",CPF);
        for (cont=0; cont <= 100 ; cont++ ){
            if(strcmp(CPF,vetor[cont].CPF)==0){
                if (vetor[cont].vazio == 1){    //se ele estiver salvo 
                
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[cont].cod,vetor[cont].nome,vetor[cont].CPF,vetor[cont].endereco,vetor[cont].telefone);
                
                getchar();
                
                printf("\nDeseja realmente exlucir? s/n: ");
                
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    vetor[cont].vazio = 0;
                    
                    printf("\nExclusao feita com sucesso\n");
                    getchar();
                    main();
                    
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        main();
                    }
                }
                } 
            }
            else{
                printf("\nCPF/CNPJ nao encontrado\n");
                getchar();
                main();}
            }
        }





    
    else if (ops==4){
                printf("Voce deseja mesmo sair?\n\n");
                printf("Digite (S) para sim e (N) para nao. \n\n");
                scanf("%c",&c);
                getchar();
                if(c=='S' || c=='s'){
                    
                    main();
                }
                else if(c=='N' || c== 'n'){
                    excluirCliente();
    }
    }
}while(ops!=1 || ops!=2 || ops!=3 || ops!=4 );
}
 // FIM DA FUNÇAO EXLCUIR 

void alterarcliente (void){ // FUNCÃO ALTERAR CLIENTE

int cont,cod,ops;
char resp;
char nome2[50];
char CPF2 [20];
char endereco2[50];
char telefone2[20];

    printf("\n\n1-  Alterar registro por Codigo:  \n");
    printf("\n\n2-  Alterar registro por Nome:  \n");
    printf("\n\n3-  Alterar registro por CPF/CNPJ:  \n");
    printf("\n\n4-  Sair: \n");
    scanf("%d",&ops);
    if(ops == 1 ){
            
            printf("Entre com o codigo da matricula que deseja alterar: \n ");

            scanf("%d",&cod);

                        for (cont=0 ; cont<100 ; cont++ )
                        {

                            if ( vetor[cont].cod == cod )
                            { 

                            if (vetor[cont].vazio == 1 )
                            {
		                    printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[cont].cod,vetor[cont].nome,vetor[cont].CPF,vetor[cont].endereco,vetor[cont].telefone);
                            getchar();
                            printf("\nDeseja mesmo alterar ? ");
                            printf("\n S - Sim: \n");
                            printf("\n N - Nao: \n ");
                            printf("\n E - Sair: \n");
		                    char resp;
		                    scanf("%c",&resp);
		
		
		
                                if(resp == 'S' || resp == 's' ){

                                    printf("\nDigite o novo codigo: ");
                                    scanf("%d",&cod);
                                    
                                    vetor[cont].cod = cod;
                                    printf("\nDigite o novo nome: ");
                                    scanf("%s",nome2);
                                    
                                    strcpy(vetor[cont].nome, nome2); 
                                    printf("\nDigite o novo CPF: ");
                                    scanf("%s",CPF2);
                                    
                                    strcpy(vetor[cont].CPF, CPF2);
                                    printf("\nDigite seu Endereco: ");
                                    scanf("%s",endereco2);
                                    
                                    strcpy(vetor[cont].endereco, endereco2);
                                    printf("\nDigite seu Telefone: ");
                                    scanf("%s",telefone2);
                                    
                                    strcpy(vetor[cont].telefone, telefone2);
                                    vetor[pos].vazio = 1;
                                    getchar();
                                    }
                                else if(resp=='N' || resp=='n'){
                                    getchar();
                                    main();
                                }
                                 else if (resp=='E' || resp=='e'){
                                    break;
                                }
           	    
   		      
	   }
    }
else{
            printf("\nCodigo nao encontrado\n");
            getchar();
            main();}
}
}
    else if (ops==2){
                       printf("Entre com o nome da matricula que deseja alterar: \n ");
                        char nome [50];
                        scanf("%s",nome);

                        for (cont=0 ; cont<100 ; cont++ )
                        {

                            if ( strcmp(nome,vetor[cont].nome)==0)
                            { 

                            if (vetor[cont].vazio == 1 )
                            {
		                    printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[cont].cod,vetor[cont].nome,vetor[cont].CPF,vetor[cont].endereco,vetor[cont].telefone);
                            getchar();
                            printf("\nDeseja mesmo alterar ? ");
                            printf(" S - Sim: \n");
                            printf(" N - Nao: \n ");
                            printf(" E - Sair: \n");
		                    char resp;
		                    scanf("%c",&resp);
		
		
		
                                if(resp == 'S' || resp == 's' ){

                                    printf("\nDigite o novo codigo: ");
                                    scanf("%d",&cod);
                                    vetor[cont].cod = cod;

                                    printf("\nDigite o novo nome: ");
                                    scanf("%s",nome2);
                                    
                                    strcpy(vetor[cont].nome, nome2); 
                                    printf("\nDigite o novo CPF: ");
                                    scanf("%s",CPF2);
                                    
                                    strcpy(vetor[cont].CPF, CPF2);
                                    printf("\nDigite seu Endereco: ");
                                    scanf("%s",endereco2);
                                    
                                    strcpy(vetor[cont].endereco, endereco2);
                                    printf("\nDigite seu Telefone: ");
                                    scanf("%s",telefone2);
                                   
                                    strcpy(vetor[cont].telefone, telefone2);
                                    vetor[pos].vazio = 1;
                                    getchar();
                                    }
                                else if(resp=='N' || resp=='n'){
                                    getchar();
                                    main();
                                }
                                 else if (resp=='E' || resp=='e'){
                                    break;
                                }
           	    
   		      
	   }
    }
    else{
            printf("\nNome nao encontrado\n");
            getchar();
            main();}
    }
}
  
    else if(ops==3){
        printf("Entre com o CPF/CNPJ da matricula que deseja alterar: \n ");
                        char CPF [20];
                        scanf("%s",CPF);

                        for (cont=0 ; cont<100 ; cont++ )
                        {

                            if ( strcmp(CPF,vetor[cont].CPF)==0)
                            { 

                            if (vetor[cont].vazio == 1 )
                            {
		                    printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[cont].cod,vetor[cont].nome,vetor[cont].CPF,vetor[cont].endereco,vetor[cont].telefone);
                            getchar();
                            printf("\nDeseja mesmo alterar ? ");
                            printf(" S - Sim: \n");
                            printf(" N - Nao: \n ");
                            printf(" E - Sair: \n");
		                    char resp;
		                    scanf("%c",&resp);
		
		
		
                                if(resp == 'S' || resp == 's' ){

                                    printf("\nDigite o novo codigo: ");
                                    scanf("%d",&cod);
                                    
                                    vetor[cont].cod = cod;
                                    printf("\nDigite o novo nome: ");
                                    scanf("%s",nome2);
                                    
                                    strcpy(vetor[cont].nome, nome2); 
                                    printf("\nDigite o novo CPF: ");
                                    scanf("%s",CPF2);
                                    
                                    strcpy(vetor[cont].CPF, CPF2);
                                    printf("\nDigite seu Endereco: ");
                                    scanf("%s",endereco2);
                                    
                                    strcpy(vetor[cont].endereco, endereco2);
                                    printf("\nDigite seu Telefone: ");
                                    scanf("%s",telefone2);
                                    
                                    strcpy(vetor[cont].telefone, telefone2);
                                    vetor[pos].vazio = 1;
                                    getchar();
                                    }
                                else if(resp=='N' || resp=='n'){
                                    getchar();
                                    main();
                                }
                                 else if (resp=='E' || resp=='e'){
                                    break;
                                }
           	    
   		      
	   }
    }
    else{
            printf("\nCPF/CNPJ nao encontrado\n");
            getchar();
            main();}
    }

}
    
    else if (ops==4){
         printf("Voce deseja mesmo sair?\n\n");
                printf("Digite (S) para sim e (N) para nao. \n\n");
                char c;
                scanf("%c",&c);
                getchar();
                if(c=='S' || c=='s'){
                    
                    main();
                }
                else if(c=='N' || c== 'n'){
                    
                    alterarcliente ();
    }
    }
   }

    // fim da função alterar





// começo da função dinheiro 

void dinheiro(void){
    int notas100 = 0, notas50 = 0, notas20 = 0, notas10 = 0, notas5 = 0, notas2 = 0, notas1 = 0;
   int moedas50 = 0, moedas25 = 0, moedas10 = 0, moedas5 = 0, moedas1 = 0;
   double N;

   scanf ("%lf", &N);
   N += 1e-9;

   // ********* Notas *********

   printf("NOTAS:\n");
      if (N >= 100) {
         notas100 = N /100;
      }
      printf("%d nota(s) de R$ 100.00\n", notas100);


      if (N >= 50)
      {
         notas50 = (N - (notas100 * 100)) / 50;
      }
      printf("%d nota(s) de R$ 50.00\n", notas50);


      if (N >= 20)
      {
         notas20 = (N - (notas100 * 100) - (notas50 * 50)) / 20;
      }
      printf("%d nota(s) de R$ 20.00\n", notas20);

      if (N >= 10)
      {
         notas10 = (N - (notas100 * 100) - (notas50 * 50) - (notas20 * 20)) / 10;
      }
      printf("%d nota(s) de R$ 10.00\n", notas10);

      if (N >= 5)
      {
         notas5 = (N - (notas100 * 100) - (notas50 * 50) - (notas20 * 20) - (notas10 * 10)) / 5;
      }
      printf("%d nota(s) de R$ 5.00\n", notas5);

            if (N >= 2)
      {
         notas2 = (N - (notas100 * 100) - (notas50 * 50) - (notas20 * 20) - (notas10 * 10) - (notas5 * 5)) / 2;
      }
      printf("%d nota(s) de R$ 2.00\n", notas2);

      
}
















void cadastro_conta(void){
            
    
    int cont,cod,ops,pos;
    char resp;  
    
    pos = verifica_pos();
    
    vetor[pos].cod = cod;
    
    
     printf("\n\n1-  Registrar  por Codigo:  \n");
     printf("\n\n2-  Registrar por Nome:  \n");
     printf("\n\n3-  Registrar por CPF/CNPJ:  \n");
     printf("\n\n4-  Sair: \n");
     scanf("%d",&ops);
     if(ops == 1 ){
            
            printf("Entre com o codigo do cliente que deseja alterar: \n ");

            scanf("%d",&cod);

                        for (cont=0 ; cont<100 ; cont++ )
                        {

                            if ( vetor[cont].cod == cod )
                            { 

                            if (vetor[cont].vazio == 1 )
                            {
		                    printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[cont].cod,vetor[cont].nome,vetor[cont].CPF,vetor[cont].endereco,vetor[cont].telefone);
                            getchar();
                            printf("\nDeseja mesmo Registar ? ");
                            printf("\n S - Sim: \n");
                            printf("\n N - Nao: \n ");
                            printf("\n E - Sair: \n");
		                    char resp;
		                    scanf("%c",&resp);
		

		
                                if(resp == 'S' || resp == 's' ){
                                    
                                    
                                    printf("\nInforme o numero da agencia da conta do cliente: ");
                                    scanf(" %[^\n]", vetor_conta[cont].agencia);
                                    printf("\nInforme o saldo inicial da conta: ");
                                    scanf(" %[^\n]", vetor_conta[cont].saldo);
                                   
                                   
                                    getchar();
                                    main();
                                    }
                                else if(resp=='N' || resp=='n'){
                                    getchar();
                                    main();
                                }
                                 else if (resp=='E' || resp=='e'){
                                    break;
                                }
           	    
   		      
	   }
    }
                        
     
                        
else{
            printf("\nCodigo nao encontrado\n");
            getchar();
            main();

}
}
}
else if (ops==2){

                       printf("Entre com o nome do cliente que deseja cadastrar: \n ");
                        char nome [50];
                        scanf("%s",nome);

                        for (cont=0 ; cont<100 ; cont++ )
                        {

                            if ( strcmp(nome,vetor[cont].nome)==0)
                            { 

                            if (vetor[cont].vazio == 1 )
                            {
		                    printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[cont].cod,vetor[cont].nome,vetor[cont].CPF,vetor[cont].endereco,vetor[cont].telefone);
                            getchar();
                            printf("\nDeseja mesmo cadastrar ? ");
                            printf(" S - Sim: \n");
                            printf(" N - Nao: \n ");
                            printf(" E - Sair: \n");
		                    char resp;
		                    scanf("%c",&resp);
		
		
		
                                if(resp == 'S' || resp == 's' ){

                                     printf("\nInforme o numero da agencia da conta do cliente: ");
                                    scanf(" %[^\n]", vetor_conta[cont].agencia);
                                    limparBuffer();
                                    printf("\nInforme o saldo inicial da conta: ");
                                    scanf(" %[^\n]", vetor_conta[cont].saldo);
                                    limparBuffer();
                                    
                                    getchar();
                                    main();
                                    }
                                else if(resp=='N' || resp=='n'){
                                    getchar();
                                    main();
                                }
                                 else if (resp=='E' || resp=='e'){
                                    break;
                                }
           	    
   		      
	   }
    }
                        }
}
else if(ops==3){
        printf("Entre com o CPF/CNPJ do cliente que deseja cadastrar: \n ");
                        char CPF [20];
                        scanf("%s",CPF);

                        for (cont=0 ; cont<100 ; cont++ )
                        {

                            if ( strcmp(CPF,vetor[cont].CPF)==0)
                            { 

                            if (vetor[cont].vazio == 1 )
                            {
		                    printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", vetor[cont].cod,vetor[cont].nome,vetor[cont].CPF,vetor[cont].endereco,vetor[cont].telefone);
                            getchar();
                            printf("\nDeseja mesmo cadastrar ? ");
                            printf(" S - Sim: \n");
                            printf(" N - Nao: \n ");
                            printf(" E - Sair: \n");
		                    char resp;
		                    scanf("%c",&resp);
		
		
		
                                if(resp == 'S' || resp == 's' ){

                                    printf("\nInforme o numero da agencia da conta do cliente: ");
                                    scanf(" %[^\n]", vetor_conta[cont].agencia);
                                    limparBuffer();
                                    printf("\nInforme o saldo inicial da conta: ");
                                    scanf(" %[^\n]", vetor_conta[cont].saldo);
                                    
                                    getchar();
                                    main();
                                    }
                                else if(resp=='N' || resp=='n'){
                                    getchar();
                                    main();
                                }
                                 else if (resp=='E' || resp=='e'){
                                    break;
                                }
           	    
   		      
	   }
    }
    else{
            printf("\nCPF/CNPJ nao encontrado\n");
            getchar();
            main();}
    }

}
else if (ops==4){
         printf("Voce deseja mesmo sair?\n\n");
                printf("Digite (S) para sim e (N) para nao. \n\n");
                char c;
                scanf("%c",&c);
                getchar();
                if(c=='S' || c=='s'){
                    
                    main();
                }
                else if(c=='N' || c== 'n'){
                    
                    cadastro_conta();
    }
    }
    
}

//INICIO TRANSAÇÃO DE CONTAS
/*

void transacao (void){

typedef struct
{
char nome[40]; // guarda o nome da pessoa
char cpf[50]; // guarda o cpf da pessoa
float saldo;
}registro;

registro usuarioA;
registro usuarioB;
float retirar, depositar, transferir;
int usuario;
char enter[10];
int option;



void retirada () {
    printf("\nQuando voce deseja retirar: R$");
    scanf("%f", &retirar);
    if (usuario == 1 && (usuarioA.saldo-retirar>=0)){
        usuarioA.saldo -= retirar;
        printf("\nRetirada efetuada!");
    }

    else if (usuario == 2 && (usuarioB.saldo-retirar>=0)){
        usuarioB.saldo -= retirar;
        printf("\nRetirada efetuada!");
    }
    else{
        printf("\nVoce nao tem dinheiro suficiente.");
    }
    gets (enter);
}

void deposito (){
    printf("\nQuanto voce deseja depositar: R$");
    scanf("%f", &depositar);
    if (usuario == 1){
        usuarioA.saldo += depositar;
        printf("\nDeposito efetuado!");
    }

    else if (usuario == 2){
        usuarioB.saldo += depositar;
        printf("\nDeposito efetuado!");
    }
    gets(enter);
}

void transferencia (){
    printf("\nQuanto voce deseja transferir: R$");
    scanf("%f", &transferir);
    if (usuario == 1 && (usuarioA.saldo - transferir >= 0)){
        usuarioB.saldo += transferir;
        usuarioA.saldo -= transferir;
        printf("\nTransferencia para %s concluida!", usuarioB.nome);
    }
    else if (usuario == 2 && (usuarioB.saldo - transferir >=0)) {
        usuarioA.saldo += transferir;
        usuarioB.saldo -= transferir;
        printf("\nTransferencia para %s concluida!", usuarioA.nome);
    }
    else {
        printf("Voce nao tem dinheiro suficiente.");
    }
    gets(enter);
}

void verSaldo (){
    if (usuario == 1){
        printf("\nSeu saldo e: R$%.2f", usuarioA.saldo);
    }
    else if (usuario == 2){
        printf("\nSeu saldo e: R$%.2f", usuarioB.saldo);
    }
    gets(enter);
}

void identificador(){
     system("cls");
     job:
     printf("\nQual usuario voce deseja:\n1 - %s\n2 - %s\n\n", usuarioA.nome, usuarioB.nome);
     scanf("%d", &usuario);
     if (usuario != 1 && usuario != 2){
                 printf("\nNumero Invalido\n");
                 goto job;
                 }     
}


void cadastrador(){
    printf("\nQual o nome do USUARIO 1: ");
    gets(usuarioA.nome);
    printf("\nQual o CPF do USUARIO 1: ");
    gets(usuarioA.cpf);
    printf("\nQual o nome do USUARIO 2 (caso nao exista, deixe em branco): ");
    gets(usuarioB.nome);
    printf("\nQual o CPF do USUARIO 2 (caso nao exista, deixe em branco): ");
    gets(usuarioB.cpf);

    identificador();
}

void menu(){
     system("cls");
     printf("\n1 - Verificar saldo\n2- Retirar\n3 - Depositar\n4 - Transferir\n5 - Trocar de Usuario\n");
     scanf("%i", &option);

                 switch(option)
                 {
                  case 1: verSaldo(); break;
                  case 2: retirada(); break;
                  case 3: deposito(); break;
                  case 4: transferencia(); break;
                  case 5: identificador(); break;
                  case 6: break;
                  default: printf("\nOpcao Invalida"); break;
                 }
}

int main (){
    cadastrador();
    while(option!=6)
    {
       main();
    }
    return 0;
}
*/

//FIM DA TRANSAÇÃO DE CONTAS