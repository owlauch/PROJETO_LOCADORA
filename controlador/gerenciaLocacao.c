void menuPrincipal();

int registrarlocacao()
{
   int opSelecao, carroSelecionado=0, clienteSelecionado=0;
   do
   {
      printf("Selecao de Veiculo\n");
      printf("1 - Todos os Veiculos\n");
      printf("2 - Por Categoria\n");
      scanf("%d", &opSelecao);
      fflush(stdin);
      if (opSelecao < 0 || opSelecao > 2)
      {
         printf("Opcao inexistente \n");
         getchar();
         fflush(stdin);
         system("cls");
      }
   } while (opSelecao < 0 || opSelecao > 2);
   switch (opSelecao)
   {
   case 1:
      carroSelecionado = leiaTodosVeiculos();
      break;
   case 2:
      do
      {
         system("cls");
         printf("Selecione a Categoria \n");
         printf("1 - selecao economica \n");
         printf("2 - selecao intermediaria \n");
         printf("3 - selecao luxo \n");
         scanf("%d", &opSelecao);
         fflush(stdin);
         if (opSelecao < 0 || opSelecao > 3)
         {
            printf("Opcao inexistente \n");
            getchar();
            fflush(stdin);
         }
      } while (opSelecao < 0 || opSelecao > 3);
      carroSelecionado = leiaCategoria(opSelecao);
      break;
   }
   
   printf("%d",carroSelecionado);

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