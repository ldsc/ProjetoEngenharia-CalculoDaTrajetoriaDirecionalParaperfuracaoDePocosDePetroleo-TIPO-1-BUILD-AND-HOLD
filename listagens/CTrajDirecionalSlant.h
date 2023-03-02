#ifndef CTRAJDIRECIONALSLANT_H
#define CTRAJDIRECIONALSLANT_H

#include "CTrajVertical.h"
#include "CParametrosDirecional.h"
#include <vector>

class CTrajDirecionalSlant {
public:

    double kop;         ///TAMBEM UTILIZAMOS OS PARAMETROS CALCULADOS NA CLASSE "CPARAMETROSDIRECIONAL"
    double angMax;
    double comp_build;
    double md_total;
    double prof_eob;
    double tvd;
    double inc_slant;

    std::vector<double> tvd_vetor_slant;        ///VETORES QUE SAO CRIADOS NESSA CLASSE
    std::vector<double> inclination_slant;
    std::vector<double> md_vetor_slant;

    CParametrosDirecional* parametroDirecional;     ///CONSTRUTOR RECEBENDO POR PONTEIRO AS INFORMACOES DA CLASSE "CPARAMETROSDIRECIONAL"
    CTrajDirecionalSlant (CParametrosDirecional* _parametroDirecional) : parametroDirecional(_parametroDirecional) {};

    void MdSlant();     ///METODOS DA CLASE
    void IncSlant();
    void TvdSlant();
    void SaidaDadosSlant();

};

#endif /// CTRAJDIRECIONALSLANT_H_INCLUDED

