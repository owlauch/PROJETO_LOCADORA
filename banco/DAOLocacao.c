void gravarlocacao(Locado a)
{
   FILE *escreve = fopen("banco/locacoes/locacoes.txt", "a");
   if (!escreve)
   {
      printf("erro ao ler arquivo");
   }
   fprintf(escreve, "%d|%d|%d|%s|%s\n", a.id_cliente,a.id_cliente,a.diaslocado,a.dataLocacao,a.dataDevolucao);
   fclose(escreve);
   printf("Cadastrado com sucesso");
   getchar();
   fflush(stdin);
}