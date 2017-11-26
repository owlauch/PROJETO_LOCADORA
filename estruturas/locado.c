
typedef struct {
   int id_cliente, id_Veiculo,seguro;
   String dataLocacao, dataDevolucao,placa; 
}Locado;

typedef struct{
    String placa,dataDevolucao;
    int abas,limp,dano,diasLocado,diasExtras,seguro;
    float valorDano,vDiaria,vLim,vCom;
}Devolucao;