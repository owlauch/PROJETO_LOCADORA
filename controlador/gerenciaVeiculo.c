void menuPrincipal();
void mostrarveiculo();
int selecionarOV();

int cadastrarveiculo()
{
   int i = 0;
   Veiculo veiculo[1];

   printf("Digite placa do veiculo \n");
   gets(veiculo[0].placa);
   fflush(stdin);
   printf("Digite o numero do renavam \n");
   gets(veiculo[0].renavam);
   fflush(stdin);
   printf("Digite a marca do veiculo \n");
   gets(veiculo[0].marca);
   fflush(stdin);
   printf("Digite o modelo do veiculo \n");
   gets(veiculo[0].modelo);
   fflush(stdin);
   printf("Digite a cor do veiculo \n");
   gets(veiculo[0].cor);
   fflush(stdin);
   escolhaCategoria(veiculo);
   printf("Digite o ano do veiculo \n");
   gets(veiculo[0].anoVeiculo);
   fflush(stdin);
   printf("Digite o combustivel do veiculo \n");
   gets(veiculo[0].combustivel);
   fflush(stdin);
   gravarVeiculo(veiculo, i);
   menuPrincipal();
}

int buscarveiculo()
{
}

void mostrarTodosVeiculos(String veiculo[100],String placaSelecionada)
{
   int i = 0, selecionado;
   String listaPlacas[100];

   system("cls");
   while (veiculo[i][0])
   {
      printf("ID Veiculo: %d\n", 1 + i);
      printf("---------------\n");
      mostrarveiculo(veiculo[i],0);
      i++;
   }
   do
   {
      printf("selecione pelo id um dos %d Veiculo na lista acima \n", i);
      scanf("%d", &selecionado);
      fflush(stdin);
      if (selecionado < 1 || selecionado > (1 + i))
      {
         printf("opcao indisponivel\n");
      }
   } while (selecionado < 1 || selecionado > (1 + i));
   mostrarveiculo(veiculo[selecionado-1],placaSelecionada);
}

void mostrarveiculo(String veiculo, String placaSele)
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
         if ((veiculo[i] != '|') && contPipe == 8)
         {
            valor[cont[8]] = veiculo[i];
            cont[8]++;
         }
         if (veiculo[i] == '|')
         {
            contPipe++;
         }
      }
      if(!placaSele)
      {
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
      else 
      {
         strcpy(placaSele, placa);
      }
}

int apagarveiculo()
{
}

int editarveiculo()
{
}
int cadastrarCategoria()
{
      Categoria categoria;
      printf("digite o nome da categoria \n");
      fflush(stdin);
      gets(categoria.nome);
      fflush(stdin);
      printf("digite o valor da categoria\n");
      fflush(stdin);
      gets(categoria.valor);
      fflush(stdin);
      gravaCategoria(categoria);
      selecionarOV();
}

int selecionarOV()
{
   int i = 0;
   printf("Gestor de Locacoes - Gerenciador de Veiculos\n");
   printf("Selecione uma Opcao:\n");
   printf("1 - Cadastrar Veiculo\n");
//    printf("2 - Mostrar veiculos Categoria\n");
   printf("3 - Mostrar Todos veiculos\n");
   // printf("4 - Apagar veiculo\n");
   printf("5 - cadastrar categoria\n");
   printf("6 - Menu Principal \n");
   scanf("%d", &i);
   fflush(stdin);
   return i;
}

void gerenciadorVeiculos()
{
   system("cls");
   int selecionado, opSelecao = 0;
   String placa ={0};
   selecionado = selecionarOV();
   switch (selecionado)
   {
   case 1:
      system("cls");
      cadastrarveiculo();
      break;
   case 2:
      system("cls");
      // leiaCategoria(opSelecao,placa);
      gerenciadorVeiculos();
      break;
   case 3:
      system("cls");
      leiaTodosVeiculos(0);
      gerenciadorVeiculos();
      break;
   case 4:
      system("cls");
      gerenciadorVeiculos();
      break;
   case 5:
      system("cls");
      cadastrarCategoria();
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