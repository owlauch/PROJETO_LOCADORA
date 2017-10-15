#include "..\banco\DAOConteiner.c"
#include "gerenciaCliente.c"
#include "gerenciaVeiculo.c"
#include "gerenciaLocacao.c"

int selecionar(){
   int i=0;
   printf("Gestor de locacoes - Menu Principal\n");
   printf("Selecione uma Opcao:\n");
   printf("1 - Gerenciar Clientes\n");
   printf("2 - Gerenciar Veiculos\n");
   printf("3 - Gerenciar Locacoes\n");
   printf("4 - Sair do gerenciador\n");
   scanf("%d",&i);
   fflush(stdin);
   return i;
}

void menuPrincipal(){
   system("cls");
   int selecionado;
   selecionado = selecionar();
   switch (selecionado)
   {
   case 1:
      system("cls");
      gerenciadorClientes();
      break;
      case 2:
      system("cls");
      gerenciadorVeiculos();
      break;
      case 3:
      system("cls");
      gerenciadorLocacoes();
      break;
      case 4:
      system("cls");
      system("exit");
      break;
   default:
      printf("Opcao Invalida - tente novamente");
      getchar();
      system("cls");
      menuPrincipal();
      break;
   }
}
