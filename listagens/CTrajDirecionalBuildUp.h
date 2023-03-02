#ifndef CTRAJDIRECIONALBUILDUP_H
#define CTRAJDIRECIONALBUILDUP_H

#include "CParametrosDirecional.h" ///ESSA CLASSE CRIA A TRAJETORIA DA SECAO DE GANHO DE ANGULO, PARA ISSO PRECISAMOS
#include <vector>                  ///UTILIZAR OS PARAMETROS DIRECIONAIS CALCULADOS NA CLASSE "CPARAMETROSDIRECIONAL"

class CTrajDirecionalBuildUp{
    public:

       double kop;  ///AQUI CHAMAMOS OS PARAMETROS CALCULADOS NA OUTRA CLASSE QUE SERAO UTILIZADOS NO CALCULO DOS VETORES
       double bur;
       double r;
       double angMax;
       double comp_build;
       double md_total;
       double tvd;
       int tamanho1;

       std::vector<double> tvd_vetor;   ///VETORES QUE SERAO CRIADOS NESSA CLASSE PARA REPRESENTAR A TRAJETORIA DE GANHO DE ANGULO
       std::vector<double> inclination;
       std::vector<double> md_vetor;

        CParametrosDirecional* parametroDirecional;     ///CONSTRUTOR CHAMANDO POR PONTEIRO OS OBJETOS CRIADOS
        CTrajDirecionalBuildUp (CParametrosDirecional* _parametroDirecional) : parametroDirecional(_parametroDirecional) {};

        void MdBuild();     ///METODOS DA CLASSE
        void IncBuild();
        void TvdBuild();
        void SaidaDadosBuild();
};

#endif ///CTRAJDIRECIONALBUILDUP_H

