#include "CParametrosDirecional.h"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

void CParametrosDirecional::EntradaDadosDirecional(){   /// METODO QUE PEDE TODOS OS DADOS DE ENTRADA NECESSARIOS

        cout << "Entre com a coordenada x da cabeca do poco, em UTM: ";
        cin  >> wellhead[0];
        cout << "Entre com a coordenada y da cabeca do poco, em UTM: ";
        cin  >>  wellhead[1];

        cout << "Entre com as coordenada x do alvo geologico, em UTM: ";
        cin  >> target[0];
        cout << "Entre com as coordenada y do alvo geologico, em UTM: ";
        cin  >>  target[1];

        do {
            cout << "Entre com a profundidade final vertical (TVD), em metros: ";
            cin  >> tvd;

            cout << "## Lembre que KOP precisa ser menor que TVD. ##" << endl;
            cout << "Entre com a profundidade inicial da secao de ganho de angulo (KOP), em metros: ";
            cin  >> kop;

        } while (kop > tvd);

        cout<< "Entre com a taxa de ganho de angulo (BUR), em graus/30m: ";
        cin>> bur;
}

void CParametrosDirecional::TVDVertical(){      /// CALCULO VERTICAL

    tamanho = kop/10;
    if ((kop - (tamanho*10))!= 0.0)
    {
        tamanho = tamanho + 1;
    }

    tamanho = tamanho + 1;

    double salto_kop = kop/(tamanho-1);

    for (int i=0; i < tamanho; i++)
    {
        tvdVertical.push_back(i*salto_kop);
    }
}

void CParametrosDirecional::AZMVertical(){      /// CALCULO VERTICAL

    this->A = target[1] - wellhead[1];
    B = target[0] - wellhead[0];
    C = A/B;
    azm = atan(C) * (180/M_PI);

    for (int i = 0; i < tamanho; i++)
    {
        azimute.push_back(azm);
    }
}

void CParametrosDirecional::MDVertical(){       /// CALCULO VERTICAL
     mdVertical = tvdVertical;
}

void CParametrosDirecional::INCVertical(){      /// CALCULO VERTICAL
     for (int i=0; i < tamanho; i++)
    {
       incVertical.push_back(0.00);
    }
}

void CParametrosDirecional::RaioCurvatura(){    ///PARAMETRO QUE CALCULA O RAIO DA CURVATURA GERADO PELA INCLINACAO DO POCO
    cout << endl;
    cout.width(85);
    cout << "======================================================================================";
    cout << endl;

    r = (180./M_PI)*(30./bur);

    cout.width(30);
    cout << left << "Raio de curvatura (m) ";
    cout << r << right << endl;
}

void CParametrosDirecional::AfastamentoAlvo(){  /// O AFASTAMENTO E CALCULADO A PARTIR DAS COORDENADAS DA SONDA E DO ALVO
    double A;
    double B;

    A = target[0] - wellhead[0];
    B = target[1] - wellhead[1];
    afast_alvo = pow((pow(A,2)+ pow(B,2)),0.5);

    cout.width(30);
    cout << left << "Afastamento (m) ";
    cout << afast_alvo << right << endl;

}

void CParametrosDirecional::AnguloMaximo(){     /// O ANGULO MAXIMO REPRESENTA A MAXIMA INCLINACAO QUE O POÇO IRA ALCANCAR

    double C;   /// VARIAVEIS LOCAIS CRIADAS PARA FACILITAR OS CALCULOS DESTE METODO
    double D;
    double E;
    double F;
    double G;
    double H;
    double I;
    double J;
    double L;

    C = r - afast_alvo; /// O CALCULO DO ANGULO MAXIMO SAI POR RELACOES TRIGONOMETRICAS
    D = tvd - kop;
    E = C/D;
    F = atan(E);
    G = (F*180)/M_PI;

    cout.width(30);
    cout << left << "Tal (°)";
    cout << G << right <<endl;

    H = pow((pow(C,2)+ pow(D,2)),0.5);
    I = r/H;
    J = asin(I);
    L = (J*180)/M_PI;

    cout.width(30);
    cout << left << "Omega (°) ";
    cout << L << right <<endl;

    angMax = L - G;

    cout.width(30);
    cout << left << "Angulo maximo (°) ";
    cout << angMax << right <<endl;
}

void CParametrosDirecional::AfastamentoEob(){   /// ESTE METODO CALCULA O AFASTAMENTO HORIZONTAL NO FINAL DA SECAO DE GANHO DE ANGULO
    K = (angMax*M_PI)/180;
    afast_eob = r*(1- cos(K));

    cout.width(30);
    cout << left << "Afastamento (EOB) (m) ";
    cout << afast_eob << right <<endl;
}

void CParametrosDirecional::ProfEob(){          /// PROFUNDIDADE VERTICAL NO FINAL DA SECAO DE GANHO DE ANGULO
    prof_eob = (kop + r*sin(K));

    cout.width(30);
    cout << left << "Profundidade (EOB) (m) ";
    cout << prof_eob << right <<endl;
}

void CParametrosDirecional::CompBuild(){        /// ESTE METODO E RESPONSAVEL POR CALCULAR O COMPRIMENTO DO ARCO GERADO NA SECAO DE GANHO DE ANGULO
    comp_build = (30*angMax)/bur;

    cout.width(30);
    cout << left << "Comprimento da secao build (m) ";
    cout << comp_build << right <<endl;
}

void CParametrosDirecional::CompSlant(){        /// COMPRIMENTO DA SECAO TANGENTE DO POÇO APOS O FINAL DA SECAO DE GANHO DE ANGULO ATE O ALVO
    comp_slant = (tvd-prof_eob)/cos(K);

    cout.width(30);
    cout << left << "Comprimento da secao slant (m) ";
    cout << right << comp_slant <<endl;
}

void CParametrosDirecional::MD(){               /// METODO RESPONSAVEL POR CALCULAR A PROFUNDIDADE MEDIDA TOTAL DO POCO
    md_total = kop + comp_build + comp_slant;

    cout.width(30);
    cout << left << "MD Final (m) ";
    cout << md_total << right <<endl;
}

void CParametrosDirecional::SaidaDadosDirecional(){

    RaioCurvatura();    /// APOS REALIZAR TODOS OS CALCULOS, ESTE METODO JOGA OS RESULTADOS NA TELA
    AfastamentoAlvo();
    AnguloMaximo();
    AfastamentoEob();
    ProfEob();
    CompBuild();
    CompSlant();
    MD();
    TVDVertical();
    AZMVertical();
    MDVertical();
    INCVertical();
}
