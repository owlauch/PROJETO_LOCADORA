void gravarVeiculo(Veiculo a)
{
   // if (vExiste(a))
   // {
   //    printf("ja esta cadastrado");
   // }
   // else
   // {
      FILE *escreve = fopen("banco/veiculos/veiculos.txt", "a");
      if (!escreve)
      {
         printf("erro ao ler arquivo");
      }
      fprintf(escreve, "%s|%s|%s|%s|%s|%s|%s|%s|%f\n",a.placa, a.renavam, a.marca, a.modelo, a.cor, a.categoria,a.anoVeiculo,a.combustivel, a.valor );
      fclose(escreve);
      printf("Cadastrado com sucesso");
   // }
}