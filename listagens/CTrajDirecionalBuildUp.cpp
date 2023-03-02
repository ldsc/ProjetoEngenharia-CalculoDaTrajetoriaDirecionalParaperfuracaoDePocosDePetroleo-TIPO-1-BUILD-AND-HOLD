#include "CTrajDirecionalBuildUp.h"

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void CTrajDirecionalBuildUp::IncBuild(){             ///CRIACAO DO METODO QUE CALCULA O VETOR DE INCLINACOES

    inclination.push_back(0);                       ///PRIMEIRO VALOR DO VETOR E 0, PORQUE E INCLINAÇÃO IGUAL A 0
    int cont = 0;                                   ///CRIAMOS UM CONTATOR E INICIAMOS ELE COM O VALOR 0

    while ((inclination[cont]+parametroDirecional->bur) <= parametroDirecional->angMax) ///LOGICA DA CRIACAO DESTE VETOR
        {                                                                               ///A CADA PASSO DO CONTADOR A INCLINACAO
            inclination.push_back(inclination[cont] + parametroDirecional->bur);        ///MUDA COM BUR, ATE O ANGULO MAXIMO
            cont++;
        }
    cont++;
    inclination[cont] = parametroDirecional->angMax;    ///ULTIMO VALOR DO NOSSO VETOR TEM QUE SER O ANGULO MAXIMO
}

void CTrajDirecionalBuildUp::TvdBuild(){                ///A PROFUNDIDADE VERTICAL E CALCULADA UTILIZANDO O RAIO DE CURVATURA
                                                        ///SÃO RELAÇÕES TRIGONOMÉTRICAS PARA ENCONTRAR A PARTE VERTICAL

    tvd_vetor.push_back(parametroDirecional->kop+10);   ///PARA NAO SOBREPOR VALORES, INICIAMOS ESTE VETOR 10M DEPOIS DO
    int cont = 0;                                       ///FINAL DO VETOR TVD DA PARTE VERTICAL

    while ((inclination[cont]+parametroDirecional->bur) <= parametroDirecional->angMax)
        {
            tvd_vetor.push_back(parametroDirecional->kop + (parametroDirecional->r * sin((inclination[cont+1]*M_PI)/180)));
            cont++;
        }
    cont++;
    tvd_vetor[cont] = parametroDirecional->kop + (parametroDirecional->r * sin((parametroDirecional->angMax*M_PI)/180));
}

void CTrajDirecionalBuildUp::MdBuild(){             ///COMO NA SECAO DE GANHO DE ANGULO O NOSSO POÇO SAI DA VERTICAL,
                                                    ///PRECISAMOS CALCULAR A PROFUNDIDADE MEDIDA DELE, PARA SABER EXATAMENTE
                                                    ///A PROFUNDIDADE PERCORRIDA PELO POÇO

    double A = parametroDirecional->kop + parametroDirecional->comp_build; ///SOMANDO A PROF. DE KOP COM O COMPRIMENTO
    int cont = 0;                                                          ///DA SEÇÃO DE GANHO, OBTEMOS O MD ATE O FINAL
                                                                           ///DA FASE

    md_vetor.push_back(parametroDirecional->kop+(10/cos((parametroDirecional->angMax*M_PI)/180)));  ///PARA NÃO SOBREPOR, AUMENTAMOS 10m, PORÉM COMO E INCLINADO, UTILIZAMOS O COSENO PARA AUMENTAR ESTE PASSO DE PROF.

    while ((md_vetor[cont] + (parametroDirecional->comp_build/inclination.size())) <= A)        ///AQUI UTILIZAMOS O NUMERO DE CASAS DO VETOR INCLINAÇÃO PARA LIMITAR ESSE VETOR, POIS TODOS VETORES PRECISAM ESTAR
                                                                                                ///NA MESMA PROFUNDIDADE E TER O VETOR DO MESMO TAMANHO
        {
            md_vetor.push_back(md_vetor[cont] + (parametroDirecional->comp_build/inclination.size()));
            cont++;
        }
    cont++;
    md_vetor[cont] = A; ///GARANTIA QUE O ULTIMO VALOR DO VETOR E O MD FINAL DESTA FASE
}

void CTrajDirecionalBuildUp::SaidaDadosBuild(){     ///EXIBE NO CONSOLE OS RESULTADOS

    IncBuild();     ///APOS PREENCHER TODOS OS VETORES JOGAMOS NA TELA PARA CONFERIR OS RESULTADOS
    TvdBuild();
    MdBuild();

}

