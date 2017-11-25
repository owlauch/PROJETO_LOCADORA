
bool validaTamanho(String string, int tamanho, bool minimo){

	// if((!minimo && size == tamanho) || (minimo &&  size >= tamanho))
	// 	return true;

	return false;
}

bool caractereNumerico(char c){
	switch(c){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return true;
		default:
		return false;
	}
}

bool stringNumericaInt(String string){
	int i, size = strlen(string);
	if(size == 0){
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if(!caractereNumerico(string[i]))
			return false;
	}
	return true;
}

bool stringNumericaFloat(String string){
	int i, size = strlen(string), ponto = 0;
	if(size == 0){
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if(string[i] != '.' && !caractereNumerico(string[i])){
			return false;
		}else if(string[i] == '.' && (i == 0 || i == size-1)){
			return false;
		}else if(string[i] == '.'){
			ponto++;
		}
	}
	if(ponto > 1){
		return false;
	}
	return true;
}

int stringToInt(String string){

	if(stringNumericaInt(string)){
		int valor = atoi(string);
		return valor;
	}else{
		return -1;
	}

}

int stringToFloat(String string){

	if(stringNumericaFloat(string)){
		float valor = atof(string);
		return valor;
	}else{
		return -1;
	}

}

bool validaData(String data){
	if(!validaTamanho(data, 10, false))
		return false;		

	if(data[2] != '/' || data[5] != '/')
		return false;

	if(!caractereNumerico(data[0]) || !caractereNumerico(data[1]) ||
		!caractereNumerico(data[3]) || !caractereNumerico(data[4]) ||
		!caractereNumerico(data[6]) || !caractereNumerico(data[7]) ||
		!caractereNumerico(data[8]) || !caractereNumerico(data[9]))
		return false;

	String diaS;
	diaS[0] = data[0];
	diaS[1] = data[1];
	diaS[2] = '\0';

	String mesS;
	mesS[0] = data[3];
	mesS[1] = data[4];
	mesS[2] = '\0';

	String anoS;
	anoS[0] = data[6];
	anoS[1] = data[7];
	anoS[2] = data[8];
	anoS[3] = data[9];
	anoS[4] = '\0';

	int dia, mes, ano;
	dia = stringToInt(diaS);
	mes = stringToInt(mesS);
	ano = stringToInt(anoS);

	if(ano < 1900)
		return false;

	if(dia < 1)
		return false;

	int limite2 = 28;

	switch(mes){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(dia > 31)
				return false;
		break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(dia > 30)
				return false;
		break;
		case 2:
			if(ano%4 == 0)
				limite2++;

			if(dia > limite2)
				return false;
		break;
		default:
			return false;
	}

	return true;
}

int diasData(int dia, int mes, int ano){

	int dias = 0;

	dias += ano * 365;

	for (int i = 1; i <= mes; ++i)
	{
		int limite2 = 28;
		switch(i){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				dias += 31;
			break;
			case 4:
			case 6:
			case 9:
			case 11:
				dias += 30;
			break;
			case 2:
				if(ano%4 == 0)
					limite2++;

				dias += limite2;
			break;
		}
	}

	dias += dia;

	return dias;

}

int diferencaDatas(String dataInicial, String dataFinal){
	String diaS, mesS, anoS;
	int diaInicial, mesInicial, anoInicial;
	int diaFinal, mesFinal, anoFinal;
	
	diaS[0] = dataInicial[0];
	diaS[1] = dataInicial[1];
	diaS[2] = '\0';
	mesS[0] = dataInicial[3];
	mesS[1] = dataInicial[4];
	mesS[2] = '\0';
	anoS[0] = dataInicial[6];
	anoS[1] = dataInicial[7];
	anoS[2] = dataInicial[8];
	anoS[3] = dataInicial[9];
	anoS[4] = '\0';
	diaInicial = stringToInt(diaS);
	mesInicial = stringToInt(mesS);
	anoInicial = stringToInt(anoS);

	diaS[0] = dataFinal[0];
	diaS[1] = dataFinal[1];
	diaS[2] = '\0';
	mesS[0] = dataFinal[3];
	mesS[1] = dataFinal[4];
	mesS[2] = '\0';
	anoS[0] = dataFinal[6];
	anoS[1] = dataFinal[7];
	anoS[2] = dataFinal[8];
	anoS[3] = dataFinal[9];
	anoS[4] = '\0';
	diaFinal = stringToInt(diaS);
	mesFinal = stringToInt(mesS);
	anoFinal = stringToInt(anoS);

	int diasAnoInicial = diasData(diaInicial, mesInicial, anoInicial);
	int diasAnoFinal = diasData(diaFinal, mesFinal, anoFinal);

	int diferenca = diasAnoFinal - diasAnoInicial;

	return diferenca;
}

