void gravaeconomica(float valor, Veiculo a);
void gravaeluxo(float valor, Veiculo a);
void gravaeinter(float valor, Veiculo a);
float verificaValor(); 
int mostrarTodosVeiculos();

void gravarVeiculo(Veiculo a, int i)
{
   float valor;
   switch (i)
   {
   case 1:
      valor = 89.90;
      gravaeconomica(valor, a);
      break;
   case 2:
      valor = 174.90;
      gravaeinter(valor, a);
      break;
   case 3:
      valor = 289.90;
      gravaeluxo(valor, a);
      break;
   default:
      break;
   }
   FILE *escreve = fopen("banco/veiculos/veiculos.txt", "a");
   if (!escreve)
   {
      printf("erro ao ler arquivo");
   }
   fprintf(escreve, "%s|%s|%s|%s|%s|%s|%s|%s|%f\n", a.placa, a.renavam, a.marca, a.modelo, a.cor, a.categoria, a.anoVeiculo, a.combustivel, valor);
   fclose(escreve);
   printf("Cadastrado com sucesso\n");
   getchar();
   fflush(stdin);
}
void gravaeluxo(float valor, Veiculo a)
{
   FILE *escreve = fopen("banco/veiculos/luxo.txt", "a");
   if (!escreve)
   {
      printf("erro ao ler arquivo");
   }
   fprintf(escreve, "%s|%s|%s|%s|%s|%s|%s|luxo|%f\n", a.placa, a.renavam, a.marca, a.modelo, a.cor, a.anoVeiculo, a.combustivel, valor);
   fclose(escreve);
}
void gravaeinter(float valor, Veiculo a)
{
   FILE *escreve = fopen("banco/veiculos/intermediaria.txt", "a");
   if (!escreve)
   {
      printf("erro ao ler arquivo");
   }
   fprintf(escreve, "%s|%s|%s|%s|%s|%s|%s|intermediaria|%f\n", a.placa, a.renavam, a.marca, a.modelo, a.cor, a.anoVeiculo, a.combustivel, valor);
   fclose(escreve);
}
void gravaeconomica(float valor, Veiculo a)
{
   FILE *escreve = fopen("banco/veiculos/economica.txt", "a");
   if (!escreve)
   {
      printf("erro ao ler arquivo");
   }
   fprintf(escreve, "%s|%s|%s|%s|%s|%s|%s|economica|%f\n", a.placa, a.renavam, a.marca, a.modelo, a.cor, a.anoVeiculo, a.combustivel, valor);
   fclose(escreve);
}

int leiaTodosVeiculos()
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
   return mostrarTodosVeiculos(lista);
}
int leiaCategoria(int selecionado)
{
   String lista[100], listaCPF[100];
   int contador = 0, resultado = 0, cont2 = 0, tamcpf = 0;
   bool estaNalista;

   if (selecionado == 1)
   {
      FILE *le = fopen("banco/veiculos/economica.txt", "r");
      while (fgets(lista[contador], 100, le))
      {
         contador++;
      }
      fclose(le);
      return mostrarTodosVeiculos(lista);
   }
   if (selecionado == 2)
   {
      FILE *le = fopen("banco/veiculos/intermediaria.txt", "r");
      while (fgets(lista[contador], 100, le))
      {
         contador++;
      }
      fclose(le);
      return mostrarTodosVeiculos(lista);
   }
   if (selecionado == 3)
   {
      FILE *le = fopen("banco/veiculos/luxo.txt", "r");
      while (fgets(lista[contador], 100, le))
      {
         contador++;
      }
      fclose(le);
      return mostrarTodosVeiculos(lista);
   }
}

int lerPlaca(String placa)
{
   String lista[100], listaPlaca[100];
   int contador = 0, resultado = 0, cont2[2] = {0, 0}, tamplaca = 0,dias=0;
   float valor = 0;
   bool estaNalista;

   zeraString(lista[0]);

   FILE *le = fopen("banco/veiculos/veiculos.txt", "r");

   while (fgets(lista[contador], 81, le))
   {
      contador++;
   }
   fclose(le);
   contador = 0;

   tamplaca = tamanhocpf(placa);
   for (int j = 0; j < 100; j++)
   {
      for (int i = 0; i < 64; i++)
      {
            if (lista[j][i] == '|')
            {
               i++;
               contador++;
            }
            if ((contador == 0))
            {
               if ((placa[cont2[0]] == lista[j][i]))
               {
                  cont2[0]++;
               }
            }
      }
      if (cont2[0] == tamplaca)
      {
         valor = verificaValor(lista[j]);
         dias = verificadia(j,valor);
         if(dias==-1){
            printf("Não foi locado ou não existe o veiculo");
            getchar();
            fflush(stdin);
         }
         // return mostrarCliente(lista[j],j);
      }
      cont2[0] = 0;
      cont2[1] = 0;
      contador = 0;
   }
}

float verificaValor(String lista){
   int contador=0, cont=0;
   float valor=0;
   for(int i = 0; lista[i]; i++)
   {
      if (lista[i] == '|')
      {
         i++;
         contador++;
      }
      if ((contador==5) &&(cont==0) )
      {
         switch (lista[i])
         {
         case 'e':
            valor = 89.90;
            break;
         case 'i':
            valor = 174.90;
            break;
         case 'l':
            valor = 289.90;
            break;
         }
         cont++;
      }
   }
   return valor;
}
