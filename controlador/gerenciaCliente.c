void menuPrincipal();

void cadastrarCliente()
{
   int i = 0;
   Cliente cliente;
   printf("Digite o nome do cliente \n");
   gets(cliente.nome);
   fflush(stdin);
   printf("Digite o RG do cliente \n");
   gets(cliente.rg);
   fflush(stdin);
   printf("Digite o CPF do cliente \n");
   gets(cliente.cpf);
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
};

int buscarCliente()
{
}

int deletarCliente()
{
}

int mostrarClientes()
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
   printf("3 - Mostrar Todos Clientes\n");
   printf("4 - Apagar Cliente\n");
   printf("5 - Editar Cliente\n");
   printf("6 - Menu Principal \n");
   scanf("%d", &i);
   fflush(stdin);
   return i;
}

void gerenciadorClientes()
{
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
      mostrarClientes();
      break;
   case 4:
      system("cls");
      apagarcliente();
      break;
   case 5:
      system("cls");
      editarcliente();
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