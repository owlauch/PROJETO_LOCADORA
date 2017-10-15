void gravaeconomica(float valor, Veiculo a);
void gravaeluxo(float valor, Veiculo a);
void gravaeinter(float valor, Veiculo a);
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
   printf("Cadastrado com sucesso");
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