int verificadia(int j, float l);
int buscadias(String data, float vv);
int lerLocacao(int id_Veiculo, float vv, String placa);

int buscaPlaca(String placa)
{
   return lerLocacao(0, 0, placa);
}

void gravarlocacao(Locado a)
{
   FILE *escreve = fopen("banco/locacoes/locacoes.txt", "a");
   if (!escreve)
   {
      printf("erro ao ler arquivo");
   }
   fprintf(escreve, "%s|%d|%s|%s\n", a.placa, a.id_cliente, a.dataLocacao, a.dataDevolucao);
   fclose(escreve);
   printf("Cadastrado com sucesso");
   getchar();
   fflush(stdin);
}
int tamanhocpf();

int lerLocacao(int id_Veiculo, float vv, String placa)
{

   String lista[100], idVeiculo = {0}, devolucao;
   int contador = 0, resultado = 0, cont2 = 0, tamid = 0, dias = 0, dias2 = 0, tamplaca =0;
   bool estaNalista;

   zeraString(lista[0]);

   sprintf(idVeiculo, "%d", id_Veiculo);

   FILE *le = fopen("banco/locacoes/locacoes.txt", "r");

   while (fgets(lista[contador], 81, le))
   {
      contador++;
   }
   fclose(le);
   contador = 0;

   tamid = tamanhocpf(idVeiculo);
   tamplaca = tamanhocpf(placa);
   for (int j = 0; j < 100; j++)
   {
      for (int i = 0; i < 64; i++)
      {
         if (lista[j][i])
         {
            if (lista[j][i] == '|')
            {
               i++;
               contador++;
            }
            if (tamplaca!= 0 && contador == 0 && lista[j][i]==placa[i])
            {
               tamplaca--;
            }
            if (contador == 1)
            {
               if ((idVeiculo[cont2] == lista[j][i]))
               {
                  cont2++;
               }
            }
         }
         else
         {
            break;
         }
      }
      if (cont2 == tamid)
      {
         dias = buscadias(lista[j], vv);
      }
      cont2 = 0;
      contador = 0;
   }
   if(!tamplaca){
      return 0;
   }
   system("pause");
   return -1;
}
int buscadias(String datas, float vv)
{
   int contador = 0, cont = 0, cl = 0, cd = 0, diferenca = 0, df2 = 0;
   String locacao, devolucao;

   for (int i = 0; datas[i]; i++)
   {
      if (datas[i] == '|')
      {
         contador++;
         i++;
      }
      if (contador == 2 && datas[i])
      {
         locacao[cl] = datas[i];
         cl++;
      }
      if (contador == 3 && datas[i])
      {
         devolucao[cd] = datas[i];
         cd++;
      }
   }
   diferenca = diferencaDatas(locacao, devolucao);
   printf("digita a data de devolucao do veiculo\n");
   gets(devolucao);
   fflush(stdin);
   df2 = diferencaDatas(locacao, devolucao);
   printf("%d - %d :%f\n", diferenca, df2, vv);
   if (diferenca > df2 || (diferenca - df2 == 0))
   {
      printf("Valor a ser pago sem multa:%.2f", diferenca * vv);
   }
   else
   {
      printf("valor a ser pago com Multa %.2f", ((df2 - diferenca) * (vv * 2)) + (diferenca * vv));
   }
   return 0;
}

int verificadia(int j, float l)
{
   String placa = {0};
   lerLocacao(j, l, placa);
   return 0;
}
