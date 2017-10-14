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
   int contador=0,resultado=0;

   zeraString(gravado);

   FILE *le = fopen("banco/clientes/clientes.txt", "r");

   fgets(gravado, 64, le);
   fclose(le);
   puts(gravado);
   for (int i = 0; i < 64; i++)
   {
      if (gravado[i] == '|')
      {
         contador=i;
         break;
      }
      nome[0][i] = gravado[i];
   }
   for(int i = 0; i < contador; i++)
   {
      
      if(nome[0][i]==b.nome[i]){
         resultado++;
      }
   }
   printf("%d",resultado);
   if(resultado==contador){
      return true;
   }

   return false;
}

void gravarCliente(Cliente a)
{
   // if (vExiste(a))
   // {
   //    printf("ja esta cadastrado");
   // }
   // else
   // {
      FILE *escreve = fopen("banco/clientes/clientes.txt", "a");
      if (!escreve)
      {
         printf("erro ao ler arquivo");
      }
      fprintf(escreve, "%s|%s|%s|%s|%s|%s|%s\n", a.nome, a.rg, a.cpf, a.nacionalidade, a.cnh, a.nascimento, a.validadeCNH);
      fclose(escreve);
      printf("Cadastrado com sucesso");
   // }
}
