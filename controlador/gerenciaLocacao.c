void menuPrincipal();
int lerCliente();
int lerLocacao(int id_Veiculo,float vv, String placa);

int registrarlocacao()
{
   int opSelecao=0;
   String cpf = {0};
   Locado locado;
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
       leiaTodosVeiculos(locado.placa);
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
      leiaCategoria(opSelecao,locado.placa);
      break;
   }
   while (!locado.id_cliente)
   {
      printf("CPF do cliente \n");
      gets(cpf);
      fflush(stdin);
      locado.id_cliente = lerCliente(cpf);
      if (!locado.id_cliente)
      {
         printf("cliente não cadastrado ou cpf invalido \n");
         getchar();
         fflush(stdin);
      }
   }
   printf("Data de Locacao\n");
   gets(locado.dataLocacao);
   fflush(stdin);
   printf("Data de Devolucao\n");
   gets(locado.dataDevolucao);
   fflush(stdin);
   if(buscaPlaca(locado.placa)){
   gravarlocacao(locado);
   }
   else 
   {
      printf("Veiculo ja alocado!\n");
      system("pause");
   }
   menuPrincipal();
}
void registrardevolucao(){
   String placa;
   String veiculo;
   int id;
   printf("Qual a Placa do Veiculo:\n");
   gets(placa);
   fflush(stdin);
   lerPlaca(placa);
   getchar();
   menuPrincipal();
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
   printf("2 - Devolucao\n");
   // printf("3 - Mostrar Todos locacoes\n");
   // printf("4 - Apagar locacao\n");
   // printf("5 - Editar locacao\n");
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
      gerenciadorLocacoes();
      break;
      case 2:
      system("cls");
      registrardevolucao();
      gerenciadorLocacoes();
      break;
      case 3:
      system("cls");
      gerenciadorLocacoes();
      break;
      case 4:
      system("cls");
      // apagarlocacao();
      gerenciadorLocacoes();
      break;
      case 5:
      system("cls");
      // editarlocacao();
      gerenciadorLocacoes();
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