void menuPrincipal();
int lerCliente();
void ajusteMultas();

int registrarlocacao()
{
    int opSelecao = 0;
    String cpf = {0};
    Locado locado;
    do
    {
        printf("Selecao de Veiculo\n");
        printf("1 - Todos os Veiculos\n");
        printf("2 - Por Categoria\n");
        scanf("%d", &opSelecao);
        fflush(stdin);
        if (opSelecao < 0 || opSelecao > 2)
        {
            printf("Opcao inexistente \n");
            getchar();
            fflush(stdin);
            system("cls");
        }
    } while (opSelecao < 0 || opSelecao > 2);
    switch (opSelecao)
    {
    case 1:
        leiaTodosVeiculos(locado.placa);
        break;
    case 2:
        do
        {
            system("cls");
            printf("Selecione a Categoria \n");
            printf("1 - selecao economica \n");
            printf("2 - selecao intermediaria \n");
            printf("3 - selecao luxo \n");
            scanf("%d", &opSelecao);
            fflush(stdin);
            if (opSelecao < 0 || opSelecao > 3)
            {
                printf("Opcao inexistente \n");
                getchar();
                fflush(stdin);
            }
        } while (opSelecao < 0 || opSelecao > 3);
        leiaCategoria(opSelecao, locado.placa);
        break;
    }
    while (!locado.id_cliente)
    {
        printf("CPF do cliente \n");
        gets(cpf);
        fflush(stdin);
        locado.id_cliente = lerCliente(cpf);
        if (!locado.id_cliente)
        {
            printf("cliente não cadastrado ou cpf invalido \n");
            getchar();
            fflush(stdin);
        }
    }
    printf("Data de Locacao\n");
    gets(locado.dataLocacao);
    fflush(stdin);
    printf("Data de Devolucao\n");
    gets(locado.dataDevolucao);
    fflush(stdin);
    printf("Seguro \n 1-sim \n 2-nao\n");
    fflush(stdin);
    scanf("%d", &locado.seguro);
    fflush(stdin);
    if (buscaPlaca(locado.placa))
    {
        gravarlocacao(locado);
    }
    else
    {
        printf("Veiculo ja alocado!\n");
        system("pause");
    }
    menuPrincipal();
}
void registrardevolucao()
{
    Devolucao devo[1];
    int id;
    printf("Qual a Placa do Veiculo:\n");
    gets(devo[0].placa);
    fflush(stdin);
    printf("data De entrega do Veiculo:\n");
    gets(devo[0].dataDevolucao);
    fflush(stdin);
    lerPlaca(devo);
    printf("o carro foi abastecido?\n 1-sim \n 2-nao\n");
    scanf("%d", &devo[0].abas);
    fflush(stdin);
    printf("o carro esta limpo? \n 1-sim \n 2-nao\n");
    scanf("%d", &devo[0].limp);
    fflush(stdin);
    if (devo[0].seguro == 0)
    {
        printf("houve Danos ao veiculo? \n 1-sim \n 2-nao\n");
        scanf("%d", &devo[0].dano);
        fflush(stdin);
        if (devo[0].dano == 1)
        {
            printf("qual foi o valor do dano:\n");
            scanf("%f", &devo[0].valorDano);
            fflush(stdin);
            devo[0].valorDano *= 1.15;
        }
    }
    ajusteMultas(devo);
    if (devo[0].seguro == 1)
    {
        devo[0].valorDano=0;
        devo[0].vDiaria *= 1.10;
    }
    printf("%.2f\n", devo[0].vDiaria);
    printf("%d\n", devo[0].diasLocado);
    printf("%d \n", devo[0].diasExtras);

    printf("Diarias normais total RS:%.2f\n", (devo[0].vDiaria * devo[0].diasLocado));
    printf("Diarias extra total RS:%.2f\n", ((devo[0].vDiaria * 2) * devo[0].diasExtras));
    printf("total Diarias RS:%.2f\n", ((devo[0].vDiaria * 2) * devo[0].diasExtras) + (devo[0].vDiaria * devo[0].diasLocado));
    printf("total Geral RS:%.2f\n", devo[0].valorDano + devo[0].vLim + devo[0].vCom + ((devo[0].vDiaria * 2) * devo[0].diasExtras) + (devo[0].vDiaria * devo[0].diasLocado));
    getchar();
    system("pause");
    menuPrincipal();
}
void ajusteMultas(Devolucao d[1])
{
    if (d[0].abas == 2)
    {
        d[0].vCom = 500;
    }
    if (d[0].limp == 2)
    {
        d[0].vLim = 100;
    }
}

int buscarlocacao()
{
}

int mostrarlocacao()
{
}

int apagarlocacao()
{
}

int editarlocacao()
{
}

int selecionarOL()
{
    int i = 0;
    printf("Gestor de locacoes - Gerenciador de Locacoes\n");
    printf("Selecione uma Opcao:\n");
    printf("1 - registrar locacao\n");
    printf("2 - Devolucao\n");
    printf("6 - Menu Principal \n");
    scanf("%d", &i);
    fflush(stdin);
    return i;
}

void gerenciadorLocacoes()
{
    int selecionado;
    selecionado = selecionarOL();
    switch (selecionado)
    {
    case 1:
        system("cls");
        registrarlocacao();
        gerenciadorLocacoes();
        break;
    case 2:
        system("cls");
        registrardevolucao();
        gerenciadorLocacoes();
        break;
    case 3:
        system("cls");
        gerenciadorLocacoes();
        break;
    case 4:
        system("cls");
        // apagarlocacao();
        gerenciadorLocacoes();
        break;
    case 5:
        system("cls");
        // editarlocacao();
        gerenciadorLocacoes();
        break;
    case 6:
        system("cls");
        menuPrincipal();
        break;
    default:
        printf("Opcao Invalida - tente novamente");
        getchar();
        system("cls");
        gerenciadorLocacoes();
        break;
    }
};