#include "CTrajVertical.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

void CTrajVertical::EntradaDadosVertical(){ /// METODO QUE RECEBE OS DADOS NECESSARIOS PARA OS CALCULOS DO AZIMUTE E TVD
        cout<< "Entre com a coordenada x da cabeca do poco, em UTM: ";
        cin>> wellhead[0];
        cout<< "Entre com a coordenada y da cabeca do poco, em UTM: ";
        cin>>  wellhead[1];

        cout<< "Entre com as coordenada x do alvo geologico, em UTM: ";
        cin>> target[0];
        cout<< "Entre com as coordenada y do alvo geologico, em UTM: ";
        cin>>  target[1];

        cout<< "Entre com a profundidade final vertical (TVD), em metros: ";
        cin>> tvd;
}

void CTrajVertical::TVDVertical(){

    tamanho = tvd/10;
    if ((tvd - (tamanho*10))!= 0.0)     /// LOGICA PARA EVITAR PASSO DE TEMPO SEM SER INTEIRO
    {
        tamanho = tamanho + 1;
    }

    tamanho = tamanho + 1;

    double salto_tvd = tvd/(tamanho-1);

    for (int i=0; i < tamanho; i++)     /// CRIACAO DO VETOR TVD, DIVIDINDO O TVD TOTAL, PELO ESPAÇO EM (m) QUE QUEREMOS
    {
        tvdVertical.push_back(i*salto_tvd);
    }
}

void CTrajVertical::AZMVertical(){ ///CALCULO DO PARAMETRO AZIMUTE DE ACORDO COM A POSICAO DA SONDA E DO ALVO

    this->A = target[1] - wellhead[1];
    B = target[0] - wellhead[0];
    C = A/B;
    azm = atan(C) * (180/M_PI);

    for (int i = 0; i < tamanho; i++)  /// PREENCHENDO O VETOR
    {
        azimute.push_back(azm);
    }
}

void CTrajVertical::MDVertical(){   /// COMO O POÇO E VERTICAL, O MD E IGUAL QUE O TVD
     mdVertical = tvdVertical;
}

void CTrajVertical::INCVertical(){ /// COMO O POÇO E VERTICAL, NÃO TEM INCLINAÇÃO. ASSIM, O VETOR E PREENCHIDO COM ZEROS
    for (int i=0; i < tamanho; i++)
    {
       incVertical.push_back(0.00);
    }
}

void CTrajVertical::SaidaDadosVertical(){

    TVDVertical();  /// CHAMANDO TODOS OS METODOS
    AZMVertical();
    MDVertical();
    INCVertical();

    cout << endl;
    cout << "======================================================================================="<<endl;
    cout.width(10); /// CONFIGURANDO A SAIDA E FAZENDO O CABEÇALHO
    cout << " MD (m) \t" << "   TVD (m) \t" << "    INC (°) \t" << "   AZM (°) \t" <<  endl;

    for (int i=0; i < tamanho; i++)                             ///GERANDO A SAIDA DE UMA FORMA ORGANIZADA
    {
        cout << setiosflags (ios::fixed) << setprecision(2);    /// PRECISAO DE DUAS CASAS DECIMAIS
        cout.width(8);
        cout << mdVertical[i] << right << "\t";                 /// ALINHAMENTO A DIREITA COM TABULACAO

        cout.width(8);
        cout << tvdVertical[i] << right << "\t";

        cout.width(4);
        cout << incVertical[i] << right << "\t";

        cout.width(4);
        cout << azimute[i] << right << endl;
    }

    fstream fout2;      ///ARQUIVO COM A TABELA DOS RESULTADOS FINAIS DO PROGRAMA
    fout2.open("trajetoriaVertical.txt", ios::app);
    fout2 << setw(50) << " Vetores das trajetorias calculados" << endl;
    fout2 << setiosflags (ios::fixed) << setprecision(2);
    fout2 << setw(12) << "MD (m)\t" << setw(12) << "TVD (m) \t" << setw(12) << "INC (°) \t" << setw(10) << "AZM (°) \t" << endl;
    for (int i = 0; i<tvdVertical.size(); i++){
        fout2 << setw(10) << mdVertical[i] << '\t' << setw(10) << tvdVertical[i] << '\t' << setw(10) << incVertical[i] << '\t' << setw(10) << azimute[i] << '\t'  << setw(10) << endl;
    }
}

