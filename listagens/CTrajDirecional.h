#ifndef CTRAJDIRECIONAL_H_INCLUDED
#define CTRAJDIRECIONAL_H_INCLUDED

#include "CParametrosDirecional.h"      ///CLASSE CRIADA PARA CONCATENAR TODOS OS VETORES CRIADOS E MOSTRAR O RESULTADO DE TODA A TRAJETÓRIA DO POÇO
#include "CTrajDirecionalBuildUp.h"     ///PARA ISSO PRECISAMOS INCLUIR TODAS AS CLASSES
#include "CTrajDirecionalSlant.h"

class CTrajDirecional
{
public:

    std::vector<double> azimute;            ///VETORES DA SECAO VERTICAL
    std::vector<double> tvdVertical;
    std::vector<double> mdVertical;

    std::vector<double> tvd_vetor;          ///VETORES DA SECAO BUILD (GANHO DE ANGULO)
    std::vector<double> inclination;
    std::vector<double> md_vetor;

    std::vector<double> tvd_vetor_slant;    ///VETORES DA SECAO SLANT (TANGENTE)
    std::vector<double> inclination_slant;
    std::vector<double> md_vetor_slant;

    std::vector<double> AZM;                ///VETORES CONCATENADOS, EXIBINDO OS RESULTADOS DA TRAJETÓRIA COMPLETA DO POÇO
    std::vector<double> INC;
    std::vector<double> TVD;
    std::vector<double> MD;

    void CriarVetorCompleto();              ///METODOS DA CLASSE
    void SaidaDados();

    CParametrosDirecional* trajdir;         ///OBJETOS CRIADOS PARA UTILIZAR OS VETORES DAS OUTRAS CLASSES
    CTrajDirecionalBuildUp* buildup;
    CTrajDirecionalSlant* slant;
    CTrajDirecional(CParametrosDirecional* _trajdir, CTrajDirecionalBuildUp* _buildup,CTrajDirecionalSlant* _slant) : trajdir(_trajdir), buildup(_buildup), slant(_slant) {};

};
#endif ///CTRAJDIRECIONAL_H_INCLUDED
