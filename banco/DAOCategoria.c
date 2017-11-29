int gravaCategoria(Categoria cat){
    FILE *escreve = fopen("banco/categoria/Categoria.txt", "a");
   if (!escreve)
   {
      printf("erro ao ler arquivo");
   }
   fprintf(escreve,"%s|%.2f\n",cat.nome,cat.valor);
   fclose(escreve);
   printf("Cadastrado com sucesso\n");
   getchar();
   fflush(stdin);  
}
int leCategoria(){

}
int editaValores(){

}
void escolhaCategoria(){
    
   String lista[100], listaCPF[100], valor={0},nome={0};
   int contador = 0, resultado = 0, cont2 = 0, tamcpf = 0;
   
   bool estaNalista;
   Categoria categoria[50];

   zeraString(lista[0]);

   FILE *le = fopen("banco/categoria/Categoria.txt", "r");

   while (fgets(lista[contador], 81, le))
   {
      contador++;
   }
   fclose(le);
   contador=0;
   for (int i =0; i<50; i++){
       for(int j=0; j<200;j++){
           if(lista[i][j]!='|'&& contador==0){
               strcat(nome,lista[i][j]);
           }
           if(lista[i][j]!='|'&& contador==1 && lista[i][j]!='\n'){
               strcat(valor,lista[i][j]);
           }
           if(lista[i][j]=='|'){
               contador++;
           }
           printf("%c",lista[i][j]);
       }
       categoria[i].valor=atof(valor);
   }
   puts(categoria[0].nome);
//    puts(categoria[0].valor);
   system("pause");
}