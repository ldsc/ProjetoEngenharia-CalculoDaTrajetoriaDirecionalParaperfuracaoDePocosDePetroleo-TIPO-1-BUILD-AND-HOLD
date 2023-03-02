#ifndef CPARAMETROSDIRECIONAL_H
#define CPARAMETROSDIRECIONAL_H

#include "CTrajVertical.h"

class CParametrosDirecional {
public:

    double kop; /// DECLARACAO DE TODOS OS ATRIBUTOS QUE SERAO UTILIZADOS
    double bur;
    double tvd;
    double wellhead[2];
    double target[2];
    double r;
    double afast_alvo;
    double angMax;
    double prof_eob;
    double afast_eob;
    double comp_build;
    double comp_slant;
    double K;
    double md_total;

    /// OCORRE A REPETICAO, POIS AO FINAL QUANDO E ESCOLHIDO POÇO DIRECIONAL, TAMBEM PRECISAMOS
    /// DA PARTE VERTICAL DO POÇO, E NA CLASSE VERTICAL, E CALCULADO APENAS QUANDO O USUARIO
    /// ESCOLHE QUE DESEJA UM POÇO TOTALMENTE VERTICAL

    double azm; ///PARAMETROS UTILIZADOS NOS CALCULOS DA SECAO VERTICAL
    double A;
    double B;
    double C;
    int tamanho;

    std::vector<double> tvdVertical;    ///VETORES VERTICAIS
    std::vector<double> azimute;
    std::vector<double> mdVertical;
    std::vector<double> incVertical;

    void TVDVertical(); ///METODOS VERTICAIS
    void AZMVertical();
    void MDVertical();
    void INCVertical();

    void RaioCurvatura();   ///METODOS DA CLASSE QUE CALCULAM OS PARÂMETROS DIRECIONAIS UTILIZADOS NAS TRAJETORIAS
    void AfastamentoAlvo();
    void AnguloMaximo();
    void AfastamentoEob();
    void ProfEob();
    void CompSlant();
    void CompBuild();
    void MD();

    void EntradaDadosDirecional();  /// METODO RECEBE TODOS OS DADOS
    void SaidaDadosDirecional();    /// METODO MOSTRA NO CONSOLE TODOS OS PARAMETROS CALCULADOS

};
#endif ///CPARAMETROSDIRECIONAL_H_INCLUDED
