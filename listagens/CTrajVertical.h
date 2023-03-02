#ifndef CTRAJVERTICAL_H
#define CTRAJVERTICAL_H

#include <vector>

class CTrajVertical
{
public:

    double wellhead[2]; ///DADOS DE ENTRADA DA CLASSE
    double target[2];
    double tvd;

    double azm;         ///PARAMETROS CALCULADOS
    double A;
    double B;
    double C;
    int tamanho;

    std::vector<double> tvdVertical;    /// Vetor que recebe a profundidade vertical, ponto a ponto que será calculada
    std::vector<double> azimute;        /// Vetor que recebe o azimute, ponto a ponto que será calculado
    std::vector<double> mdVertical;     /// Vetor que recebe a profundidade medida, ponto a ponto que será calculada
    std::vector<double> incVertical;    /// Vetor que recebe a inclinação, constante em 0 na parte vertical


    void TVDVertical(); ///METODOS DA CLASSE
    void AZMVertical(); ///METODOS DA CLASSE
    void MDVertical();  ///METODOS DA CLASSE
    void INCVertical(); ///METODOS DA CLASSE

    void EntradaDadosVertical();
    void SaidaDadosVertical();

};

#endif /// CTRAJVERTICAL_H_INCLUDED

