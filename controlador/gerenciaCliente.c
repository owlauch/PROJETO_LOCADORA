void menuPrincipal();
int mostrarCliente();
void gerenciadorClientes();

void cadastrarCliente()
{
   int i = 0;
   Cliente cliente;
   printf("Digite o nome do cliente \n");
   gets(cliente.nome);
   fflush(stdin);
   printf("Digite o CPF do cliente \n");
   gets(cliente.cpf);
   fflush(stdin);
   printf("Digite o RG do cliente \n");
   gets(cliente.rg);
   fflush(stdin);
   printf("Digite a Nacionalidade do cliente \n");
   gets(cliente.nacionalidade);
   fflush(stdin);
   printf("Digite a CNH do cliente \n");
   gets(cliente.cnh);
   fflush(stdin);
   printf("Digite a data de nascimento do cliente \n");
   gets(cliente.nascimento);
   fflush(stdin);
   printf("Digite o data da validade da CNH\n");
   gets(cliente.validadeCNH);
   fflush(stdin);
   gravarCliente(cliente);
   menuPrincipal();
};

void buscarCliente()
{
   String cpf,cliente;
   printf("Digite o CPF do cliente \n");
   gets(cpf);
   fflush(stdin);
   lerCliente(cpf);
   getchar();
   fflush(stdin);
   gerenciadorClientes();
}

int deletarCliente()
{
}
int mostrarCliente(String cliente,int idcliente){
   int contPipe=0, cont[10]={0,0,0,0,0,0,0,0,0,0};
   String nome={0}, cpf={0},rg={0},nacionalidade={0},cnh={0},nascimento = {0},validadeCNH={0};
   for(int i = 0; cliente[i]; i++)
   {
      if(cliente[i]!='|' && contPipe==0){
         nome[cont[0]]=cliente[i];
         cont[0]++;
      }
      if(cliente[i]!='|' && contPipe ==1){
         cpf[cont[1]]=cliente[i];
         cont[1]++;;
      }
      if(cliente[i]!='|' && contPipe ==2){
         rg[cont[2]]=cliente[i];
         cont[2]++;;
      }
      if(cliente[i]!='|' && contPipe ==3){
         nacionalidade[cont[3]]=cliente[i];
         cont[3]++;;
      }
      if(cliente[i]!='|' && contPipe ==4){
         cnh[cont[4]]=cliente[i];
         cont[4]++;;
      }
      if(cliente[i]!='|' && contPipe ==4){
         nascimento[cont[5]]=cliente[i];
         cont[5]++;;
      }
      if(cliente[i]!='|' && contPipe ==4){
         validadeCNH[cont[6]]=cliente[i];
         cont[6]++;;
      }
      if(cliente[i]=='|'){
         contPipe++;
      }
   }
   printf("Nome:%s\n",nome);
   printf("CPF:%s\n",cpf);
   printf("RG:%s\n",rg);
   printf("Nacionalidade:%s\n",nacionalidade);
   printf("CNH:%s\n",cnh);
   printf("Nascimento:%s\n",nascimento);
   printf("Validade CNH:%s\n  ",validadeCNH);
   return 1+idcliente;
}
void mostrarClientes()
{
}

int apagarcliente()
{
}
int editarcliente()
{
}
int selecionarOC()
{
   int i = 0;
   printf("Gestor de locacoes - Gerenciador de Clientes\n");
   printf("Selecione uma Opcao:\n");
   printf("1 - Cadastrar Cliente\n");
   printf("2 - Buscar Cliente\n");
   // printf("3 - Mostrar Todos Clientes\n");
   // printf("4 - Apagar Cliente\n");
   // printf("5 - Editar Cliente\n");
   printf("6 - Menu Principal \n");
   scanf("%d", &i);
   fflush(stdin);
   return i;
}

void gerenciadorClientes()
{
   system("cls");
   int selecionado;
   selecionado = selecionarOC();
   switch (selecionado)
   {
   case 1:
      system("cls");
      cadastrarCliente();
      break;
   case 2:
      system("cls");
      buscarCliente();
      break;
   case 3:
      system("cls");
      gerenciadorClientes();
      // mostrarClientes();
      break;
   case 4:
      system("cls");
      gerenciadorClientes();
      // apagarcliente();
      break;
   case 5:
      system("cls");
      gerenciadorClientes();
      // editarcliente();
      break;
   case 6:
      system("cls");
      menuPrincipal();
      break;
   default:
      printf("Opcao Invalida - tente novamente");
      getchar();
      system("cls");
      gerenciadorClientes();
      break;
   }
};