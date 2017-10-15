int mostrarCliente();
void zeraString(char a[64])
{
   for (int i = 0; i < 64; i++)
   {
      a[i] = ' ';
   }
}

bool vExiste(Cliente b)
{
   String gravado, nome[100];
   int contador = 0, resultado = 0;

   zeraString(gravado);

   FILE *le = fopen("banco/clientes/clientes.txt", "r");

   fgets(gravado, 64, le);
   fclose(le);
   puts(gravado);
   for (int i = 0; i < 64; i++)
   {
      if (gravado[i] == '|')
      {
         contador = i;
         break;
      }
      nome[0][i] = gravado[i];
   }
   for (int i = 0; i < contador; i++)
   {

      if (nome[0][i] == b.nome[i])
      {
         resultado++;
      }
   }
   printf("%d", resultado);
   if (resultado == contador)
   {
      return true;
   }

   return false;
}

int tamanhocpf(String cpf)
{
   int tamanhocpf = 0;
   for (int i = 0; i < 20; i++)
   {
      if (cpf[i])
      {
         tamanhocpf++;
      }
      else
      {
         break;
      }
   }
   return tamanhocpf;
}

int lerCliente(String cpf)
{
   String lista[100], listaCPF[100];
   int contador = 0, resultado = 0, cont2 = 0, tamcpf = 0;
   bool estaNalista;

   zeraString(lista[0]);

   FILE *le = fopen("banco/clientes/clientes.txt", "r");

   while (fgets(lista[contador], 81, le))
   {
      contador++;
   }
   fclose(le);
   contador = 0;

   tamcpf = tamanhocpf(cpf);
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
            if ((contador == 1))
            {
               if ((cpf[cont2] == lista[j][i]))
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
      if (cont2 == tamcpf)
      {
      return mostrarCliente(lista[j],j);
      }
      cont2 = 0;
      contador = 0;
   }
}

void gravarCliente(Cliente a)
{
   FILE *escreve = fopen("banco/clientes/clientes.txt", "a");
   if (!escreve)
   {
      printf("erro ao ler arquivo");
   }
   fprintf(escreve, "%s|%s|%s|%s|%s|%s|%s\n", a.nome, a.cpf, a.rg, a.nacionalidade, a.cnh, a.nascimento, a.validadeCNH);
   fclose(escreve);
   printf("Cadastrado com sucesso\n");
   getchar();
   fflush(stdin);  
}
