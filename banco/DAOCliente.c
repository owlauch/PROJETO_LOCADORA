#include <stdio.h>

int main(int argc, char const *argv[])
{
   FILE *saida;
   FILE *entrada;

   saida = fopen("clientes/teste.txt", "a");
   entrada = fopen("clientes/teste.txt","r");
   fscanf(entrada,);
   fclose(entrada);
   fclose(saida);
   return 0;
}
