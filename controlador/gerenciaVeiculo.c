void menuPrincipal();

int cadastrarveiculo()
{
}

int buscarveiculo()
{
}

int mostrarveiculo()
{
}

int apagarveiculo()
{
}

int editarveiculo()
{
}

int selecionarOV()
{
   int i = 0;
   printf("Gestor de Locacoes - Gerenciador de Veiculos\n");
   printf("Selecione uma Opcao:\n");
   printf("1 - Cadastrar Veiculo\n");
   printf("2 - Buscar veiculo\n");
   printf("3 - Mostrar Todos veiculos\n");
   printf("4 - Apagar veiculo\n");
   printf("5 - Editar veiculo\n");
   printf("6 - Menu Principal \n");
   scanf("%d", &i);
   fflush(stdin);
   return i;
}

void gerenciadorVeiculos()
{
   int selecionado;
   selecionado = selecionarOV();
   switch (selecionado)
   {
   case 1:
      system("cls");
      cadastrarveiculo();
      break;
   case 2:
      system("cls");
      buscarveiculo();
      break;
   case 3:
      system("cls");
      mostrarClientes();
      break;
   case 4:
      system("cls");
      apagarveiculo();
      break;
   case 5:
      system("cls");
      editarveiculo();
      break;
   case 6:
      system("cls");
      menuPrincipal();
      break;
   default:
      printf("Opcao Invalida - tente novamente");
      getchar();
      system("cls");
      gerenciadorVeiculos();
      break;
   }
};