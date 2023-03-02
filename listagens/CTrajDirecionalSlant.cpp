#include "CTrajDirecionalSlant.h"

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void CTrajDirecionalSlant::MdSlant(){           ///METODO QUE CALCULA O VETOR DA PROFUNDIDADE MEDIDA PARA A SECAO TANGENTE
    double A = parametroDirecional->kop + parametroDirecional->comp_build;
    int cont = 0;
    md_vetor_slant.push_back(A+(10/cos((parametroDirecional->angMax*M_PI)/180)));

    while ((md_vetor_slant[cont] + ((parametroDirecional->md_total - A)/10/cos((parametroDirecional->angMax*M_PI)/180)) <= parametroDirecional->md_total))
        {
            md_vetor_slant.push_back(md_vetor_slant[cont] + (parametroDirecional->md_total-A)/10/cos((parametroDirecional->angMax*M_PI)/180));
            cont++;
        }
    cont++;
    md_vetor_slant[cont]  = parametroDirecional->md_total; ///A PROFUNDIDADE MEDIDA FINAL FOI CALCULADA EM PARAMETROSDIRECIONAL
}

void CTrajDirecionalSlant::IncSlant(){          ///COMO ESTAMOS NA SECAO TANGENTE DO POCO, A INCLINACAO PERMANECE CONSTANTE
    inc_slant = parametroDirecional->angMax;    ///COM O VALOR DO ANGULO MAXIMO
    for (int i=0; i <= md_vetor_slant.size(); i++)
        {
            inclination_slant.push_back(inc_slant);
        }
}

void CTrajDirecionalSlant::TvdSlant(){          ///A PROFUNDIDADE VERTICAL FINAL E CALCULADA POR RELACOES TRIGONOMETRICAS
    int cont = 1;                               ///O VALOR FINAL TEM QUE BATER COM O TVD QUE O USUÁRIO ENTROU
    tvd_vetor_slant.push_back(parametroDirecional->prof_eob+10);

    for(cont; cont<= md_vetor_slant.size();cont++)
    {
        tvd_vetor_slant.push_back((md_vetor_slant[cont] - md_vetor_slant[0])*cos((parametroDirecional->angMax*M_PI)/180)+tvd_vetor_slant[0]);
    }
}

void CTrajDirecionalSlant::SaidaDadosSlant(){   ///METODO QUE JOGA PARA A TELA TODOS OS VETORES CALCULADOS
    MdSlant();
    IncSlant();
    TvdSlant();
}

