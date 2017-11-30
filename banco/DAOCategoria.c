int gravaCategoria(Categoria cat)
{
    FILE *escreve = fopen("banco/categoria/Categoria.txt", "a");
    if (!escreve)
    {
        printf("erro ao ler arquivo");
    }
    fprintf(escreve, "%s|%s\n", cat.nome, cat.valor);
    fclose(escreve);
    printf("Cadastrado com sucesso\n");
    getchar();
    fflush(stdin);
    system("cls");
}
int leCategoria()
{
}
int editaValores()
{
}
void limpaString(String n, String v)
{
    for (int i = 0; i < 64; i++)
    {
        n[i] = 0;
        v[i] = 0;
    }
}
int verificaVazio(String n)
{
    for (int i = 0; i < 64; i++)
    {

        if (strlen(n))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void CopiaString(Categoria j[1], String n)
{

    for (int i = 0; i < 64; i++)
    {
        if ((n[i] != ' ') && n[i] && n[i] != 0)
        {
            j[0].nome[i] = n[i];
        }
    }
    puts(j[0].nome);
    system("pause");
}
void escolhaCategoria(Veiculo v[1])
{

    String lista[100], listaCPF[100], valor = {0}, nome = {0};
    int contador = 0, cont1 = 0, cont2 = 0, escolhido = 0;

    bool estaNalista;
    Categoria categoria[50];

    zeraString(lista[0]);

    FILE *le = fopen("banco/categoria/Categoria.txt", "r");

    while (fgets(lista[contador], 81, le))
    {
        contador++;
    }
    fclose(le);
    contador = 0;
    printf("Escolha uma das categorias:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            if (lista[i][j] == '|')
            {
                contador++;
            }
            if (lista[i][j] != '|' && contador == 0 && lista[i][j] != ' ' && lista[i][j])
            {
                nome[cont1] = lista[i][j];
                cont1++;
            }
            if (lista[i][j] != '|' && contador == 1 && lista[i][j] != '\n' && lista[i][j] != ' ' && lista[i][j])
            {
                valor[cont2] = lista[i][j];
                cont2++;
            }
            else
            {
                valor[cont2] = ' ';
            }
        }
        contador = 0;
        cont1 = 0;
        cont2 = 0;
        // CopiaString(categoria, nome);
        strncpy(categoria[i].nome, nome, 64);
        strncpy(categoria[i].valor, valor, 64);
        if (verificaVazio(nome))
        {
            printf("%i - %s\n", i + 1, categoria[i].nome);
        }
        limpaString(nome, valor);
    }
    printf("\n");
    scanf("%d", &escolhido);
    fflush(stdin);
    strncpy(v[0].categoria, categoria[escolhido - 1].nome, 64);
    strncpy(v[0].valor, categoria[escolhido - 1].valor, 64);
}