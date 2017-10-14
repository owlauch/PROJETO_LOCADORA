void menuPrincipal();

int cadastrarveiculo()
{
   int i = 0;
   Veiculo veiculo;
   char eco[] = "economica";
   char inter[] = "intermediaria";
   char luxo[] = "luxo";

   printf("Digite placa do veiculo \n");
   gets(veiculo.placa);
   fflush(stdin);
   printf("Digite o n° do renavam \n");
   gets(veiculo.renavam);
   fflush(stdin);
   printf("Digite a marca do veiculo \n");
   gets(veiculo.marca);
   fflush(stdin);
   printf("Digite o modelo do veiculo \n");
   gets(veiculo.modelo);
   fflush(stdin);
   printf("Digite a cor do veiculo \n");
   gets(veiculo.cor);
   fflush(stdin);
   do
   {
      printf("Escolha a categoria do veiculo \n");
      printf("1 - economica  \n");
      printf("2 - intermediaria \n");
      printf("3 - luxo \n");
      scanf("%d", &i);
      fflush(stdin);
      if (i > 3 || i < 0)
      {
         printf("Opcao invalida tente novamente");
         getchar();
         fflush(stdin);
         system("cls");
      }
      else
      {
         switch (i)
         {
         case 1:
            strcpy(veiculo.categoria, eco);
            break;
         case 2:
            strcpy(veiculo.categoria, inter);
            break;
         case 3:
            strcpy(veiculo.categoria, luxo);
            break;
         default:
            break;
         }
      }
   } while (i > 3 || i < 0);
   fflush(stdin);
   printf("Digite o ano do veiculo \n");
   gets(veiculo.anoVeiculo);
   fflush(stdin);
   printf("Digite o combustivel do veiculo \n");
   gets(veiculo.combustivel);
   fflush(stdin);
   printf("Digite o valor do veiculo \n");
   scanf("%f", &veiculo.valor);
   fflush(stdin);
   gravarVeiculo(veiculo);
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