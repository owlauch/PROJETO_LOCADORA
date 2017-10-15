void menuPrincipal();
void mostrarveiculo();

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
   gravarVeiculo(veiculo, i);
   menuPrincipal();
}

int buscarveiculo()
{
}

int mostrarTodosVeiculos(String veiculo[100])
{
   int i = 0, selecionado;
   String listaPlacas[100];
      system("cls");
   while (veiculo[i][0])
   {
      printf("ID Veiculo: %d\n",1+i);
      printf("---------------\n");
      mostrarveiculo(veiculo[i]);
      i++;
   }
   do
   {
      printf("selecione pelo id um dos %d Veiculo na lista acima \n",i);
      scanf("%d",&selecionado);
      fflush(stdin);
      if(selecionado<1 || selecionado>(1+i)){
         printf("opcao indisponivel\n");
      }
   } while (selecionado<1 || selecionado>(1+i));
   return selecionado-1;
}

void mostrarveiculo(String veiculo)
{
   int contPipe = 0, cont[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   String placa = {0}, renavam = {0}, marca = {0}, modelo = {0}, cor = {0}, categoria = {0}, anoVeiculo = {0}, combustivel = {0}, valor = {0};
   for (int i = 0; veiculo[i]; i++)
   {
      if (veiculo[i] != '|' && contPipe == 0)
      {
         placa[cont[0]] = veiculo[i];
         cont[0]++;
      }
      if (veiculo[i] != '|' && contPipe == 1)
      {
         renavam[cont[1]] = veiculo[i];
         cont[1]++;
      }
      if (veiculo[i] != '|' && contPipe == 2)
      {
         marca[cont[2]] = veiculo[i];
         cont[2]++;
      }
      if (veiculo[i] != '|' && contPipe == 3)
      {
         modelo[cont[3]] = veiculo[i];
         cont[3]++;
      }
      if (veiculo[i] != '|' && contPipe == 4)
      {
         cor[cont[4]] = veiculo[i];
         cont[4]++;
      }
      if (veiculo[i] != '|' && contPipe == 5)
      {
         categoria[cont[5]] = veiculo[i];
         cont[5]++;
      }
      if (veiculo[i] != '|' && contPipe == 6)
      {
         anoVeiculo[cont[6]] = veiculo[i];
         cont[6]++;
      }
      if (veiculo[i] != '|' && contPipe == 7)
      {
         combustivel[cont[7]] = veiculo[i];
         cont[7]++;
      }
      if ((veiculo[i] != '|' ) && contPipe == 8)
      {
         valor[cont[8]] = veiculo[i];
         cont[8]++;
      }
      if (veiculo[i] == '|')
      {
         contPipe++;
      }
   }
   printf("placa:%s\n", placa);
   printf("renavam:%s\n", renavam);
   printf("marca:%s\n", marca);
   printf("modelo:%s\n", modelo);
   printf("cor:%s\n", cor);
   printf("categoria:%s\n", categoria);
   printf("anoVeiculo:%s\n", anoVeiculo);
   printf("combustivel:%s\n", combustivel);
   printf("valor:%s\n", valor);
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
   printf("2 - Mostrar veiculos Categoria\n");
   printf("3 - Mostrar Todos veiculos\n");
   // printf("4 - Apagar veiculo\n");
   // printf("5 - Editar veiculo\n");
   printf("6 - Menu Principal \n");
   scanf("%d", &i);
   fflush(stdin);
   return i;
}

void gerenciadorVeiculos()
{
   system("cls");
   int selecionado, opSelecao=0;
   selecionado = selecionarOV();
   switch (selecionado)
   {
   case 1:
      system("cls");
      cadastrarveiculo();
      break;
   case 2:
      system("cls");
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
      leiaCategoria(opSelecao);
      gerenciadorVeiculos();
      break;
   case 3:
      system("cls");
      leiaTodosVeiculos();
      gerenciadorVeiculos();
      break;
   case 4:
      system("cls");
      gerenciadorVeiculos();
      break;
   case 5:
      system("cls");
      gerenciadorVeiculos();
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