void menuPrincipal();

int registrarlocacao()
{
}

int buscarlocacao()
{
}

int mostrarlocacao()
{
}

int apagarlocacao()
{
}

int editarlocacao()
{
}

int selecionarOL()
{
   int i = 0;
   printf("Gestor de locacoes - Gerenciador de Locacoes\n");
   printf("Selecione uma Opcao:\n");
   printf("1 - registrar locacao\n");
   printf("2 - Buscar locacao\n");
   printf("3 - Mostrar Todos locacoes\n");
   printf("4 - Apagar locacao\n");
   printf("5 - Editar locacao\n");
   printf("6 - Menu Principal \n");
   scanf("%d", &i);
   fflush(stdin);
   return i;
}

void gerenciadorLocacoes()
{
   int selecionado;
   selecionado = selecionarOL();
   switch (selecionado)
   {
   case 1:
      system("cls");
      registrarlocacao();
      break;
   case 2:
      system("cls");
      buscarlocacao();
      break;
   case 3:
      system("cls");
      mostrarClientes();
      break;
   case 4:
      system("cls");
      apagarlocacao();
      break;
   case 5:
      system("cls");
      editarlocacao();
      break;
   case 6:
      system("cls");
      menuPrincipal();
      break;
   default:
      printf("Opcao Invalida - tente novamente");
      getchar();
      system("cls");
      gerenciadorLocacoes();
      break;
   }
};