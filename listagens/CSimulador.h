#ifndef CSIMULADOR_H
#define CSIMULADOR_H

#include "CTrajVertical.h"              ///O SIMULADOR REUNIE TODAS AS CLASSES E ACESSA TODAS PARA CHAMAR OS RESULTADOS
#include "CParametrosDirecional.h"
#include "CTrajDirecionalBuildUp.h"
#include "CTrajDirecionalSlant.h"
#include "CTrajDirecional.h"
#include "CGnuplot.h"


class CSimulador
{
    public:

        CSimulador() {     ///CONSTRUTOR DO SIMULADOR E DOS OBJETOS
        trajvert    = new CTrajVertical;
        trajdir     = new CParametrosDirecional;
        buildup     = new CTrajDirecionalBuildUp(trajdir);
        slant       = new CTrajDirecionalSlant(trajdir);
        direcional  = new CTrajDirecional(trajdir,buildup,slant);
        };

        virtual ~CSimulador() {     ///DESTRUTOR DE TODOS OS OBJETOS JUNTO COM A CLASSE
            delete trajvert;
            delete trajdir;
            delete buildup;
            delete slant;
            delete direcional;
        };

        void Simular(); ///METODO DA CLASSE

        char tipo;  ///VARIAVEL UTILIZADA PARA DETERMINAR O TIPO DO POÇO

        CGnuplot plotar4;   ///OBJETOS UTILIZADOS PARA CRIAR OS TRES GRAFICOS
        CGnuplot plotar1;
        CGnuplot plotar2;
        CGnuplot plotar3;

        CTrajVertical*          trajvert;   /// PONTEIROS CRIADOS QUE APONTAM PARA OS OBJETOS DAS CLASSES
        CParametrosDirecional*  trajdir;
        CTrajDirecionalBuildUp* buildup;
        CTrajDirecionalSlant*   slant;
        CTrajDirecional*        direcional;
};

#endif  ///CSIMULADOR_H
