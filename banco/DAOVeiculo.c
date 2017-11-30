void gravaeconomica(float valor, Veiculo a);
void gravaeluxo(float valor, Veiculo a);
void gravaeinter(float valor, Veiculo a);
float verificaValor();
void mostrarTodosVeiculos();
void escolhaCategoria();

void gravarVeiculo(Veiculo a[1], int i)
{
      FILE *escreve = fopen("banco/veiculos/veiculos.txt", "a");
      if (!escreve)
      {
            printf("erro ao ler arquivo");
      }
      fprintf(escreve, "%s|%s|%s|%s|%s|%s|%s|%s|%s\n", a[0].placa, a[0].renavam, a[0].marca, a[0].modelo, a[0].cor, a[0].categoria, a[0].anoVeiculo, a[0].combustivel, a[0].valor);
      fclose(escreve);
      printf("Cadastrado com sucesso\n");
      getchar();
      fflush(stdin);
}

void leiaTodosVeiculos(String placaSelecionada)
{
      String lista[100], listaCPF[100];
      int contador = 0, resultado = 0, cont2 = 0, tamcpf = 0;
      bool estaNalista;

      FILE *le = fopen("banco/veiculos/veiculos.txt", "r");

      while (fgets(lista[contador], 100, le))
      {
            contador++;
      }
      fclose(le);
      mostrarTodosVeiculos(lista, placaSelecionada);
}
void zeraCont(int cont[10])
{
      for (int i = 0; i < 10; i++)
      {
            cont[i] = 0;
      }
}
void zeraStrings(String placa, String renavam, String marca, String modelo, String cor, String categoria, String anoVeiculo, String combustivel, String valor)
{
      for (int i = 0; i < 64; i++)
      {
            placa[i] = ' ';
            renavam[i] = ' ';
            marca[i] = ' ';
            modelo[i] = ' ';
            cor[i] = ' ';
            categoria[i] = ' ';
            anoVeiculo[i] = ' ';
            combustivel[i] = ' ';
            valor[i] = ' ';
      }
}
void leiaCategoria(int selecionado, String placaSelecionada)
{
      Veiculo v[1], v2[20];
      escolhaCategoria(v);
      String lista[100];
      String placa, renavam, marca, modelo, cor, categoria, anoVeiculo, combustivel, valor;
      int contador = 0, resultado = 0, cont[10] = {0}, pipe = 0;
      bool estaNalista;

      FILE *le = fopen("banco/veiculos/veiculos.txt", "r");

      while (fgets(lista[contador], 100, le))
      {
            contador++;
      }
      fclose(le);
      for (int i = 0; i < 20; i++)
      {
            for (int j = 0; j < 64; j++)
            {
                  if (lista[i][j] == '|')
                  {
                        pipe++;
                  }
                  if (pipe == 0 && lista[i][j] != '|')
                  {
                        placa[cont[0]] = lista[i][j];
                        cont[0]++;
                  }
                  else if (pipe == 1 && lista[i][j] != '|')
                  {
                        renavam[cont[1]] = lista[i][j];
                        cont[1]++;
                  }
                  else if (pipe == 2 && lista[i][j] != '|')
                  {
                        marca[cont[2]] = lista[i][j];
                        cont[2]++;
                  }
                  else if (pipe == 3 && lista[i][j] != '|')
                  {
                        modelo[cont[3]] = lista[i][j];
                        cont[3]++;
                  }
                  else if (pipe == 4 && lista[i][j] != '|')
                  {
                        cor[cont[4]] = lista[i][j];
                        cont[4]++;
                  }
                  else if (pipe == 5 && lista[i][j] != '|')
                  {
                        categoria[cont[5]] = lista[i][j];
                        cont[5]++;
                  }
                  else if (pipe == 6 && lista[i][j] != '|')
                  {
                        anoVeiculo[cont[6]] = lista[i][j];
                        cont[6]++;
                  }
                  else if (pipe == 7 && lista[i][j] != '|')
                  {
                        combustivel[cont[7]] = lista[i][j];
                        cont[7]++;
                  }
                  else if (pipe == 8 && lista[i][j] != '|')
                  {
                        valor[cont[8]] = lista[i][j];
                        cont[8]++;
                  }
            }
            zeraCont(cont);
            // strncpy(placa);
            puts(renavam);
            puts(marca);
            puts(modelo);
            puts(cor);
            puts(categoria);
            puts(anoVeiculo);
            puts(combustivel);
            puts(valor);
            system("pause");
            zeraStrings(placa, renavam, marca, modelo, cor, categoria, anoVeiculo, combustivel, valor);
            pipe = 0;
      }
}
void copiaPlacaM(String p1, String p2)
{
      for (int i = 0; i < 63; i++)
      {
            p1[i] = p2[i];
      }
}
void leVeiculostxt(String lista[100])
{
      int contador = 0;

      FILE *le = fopen("banco/veiculos/veiculos.txt", "r");

      while (fgets(lista[contador], 81, le))
      {
            contador++;
      }
      fclose(le);
}

int lerPlaca(Devolucao dev[1])
{
      String lista[100] = {0}, listaPlaca[100], placa = {0}, placa2 = {0};
      int contador = 0, resultado = 0, cont2 = 0, Tamplaca = 0;
      float valor = 0;
      bool estaNalista;
      copiaPlacaM(placa, dev[0].placa);
      copiaPlacaM(placa2, placa);
      contador = 0;
      leVeiculostxt(lista);
      Tamplaca = 7;

      for (int j = 0; j < 10; j++)
      {
            for (int i = 0; i < 64; i++)
            {
                  if (lista[j][i] == '|')
                  {
                        contador++;
                  }
                  if (contador == 0 && lista[j][i] != '|')
                  {
                        if (placa[cont2] == lista[j][i])
                        {
                              cont2++;
                        }
                  }
            }
            if (cont2==7)
            {
                  dev[0].vDiaria = verificaValor(lista[j]);
                  lerDiasLocacao(dev);
                  // if (diasLocados == -1)
                  // {
                  //       printf("Não foi locado ou não existe o veiculo");
                  //       getchar();
                  //       fflush(stdin);
                  // }
                  // return mostrarCliente(lista[j], j);
            }
            cont2 = 0;
            contador = 0;
            Tamplaca=7;
      }
}

float verificaValor(String lista)
{
      int pipe=0, cont = 0;
      String valor;
      for (int i = 0; i < 64; i++)
      {
            if (lista[i] == '|')
            {
                  pipe++;
            }
            if (lista[i] != '|' && pipe == 8)
            {
                  valor[cont] = lista[i];
                  cont++;
            }
      }
      return atof(valor);
}
