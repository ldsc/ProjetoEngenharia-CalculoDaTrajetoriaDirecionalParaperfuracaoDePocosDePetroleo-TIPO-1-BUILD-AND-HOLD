#include "CTrajDirecional.h"

#include <iostream>
#include <fstream>  ///CRIAMOS ARQUIVOS EXTEMOS PARA SALVAR OS RESULTADOS E PARA CRIAR OS GRAFICOS
#include <cmath>
#include <vector>
#include <iterator> ///UTILIZAMOS PARA CONCATENAR OS VETORES
#include <iomanip>

using namespace std;

void CTrajDirecional::CriarVetorCompleto(){

    for(int i = 0; i < trajdir->tvdVertical.size(); i++)    ///VETOR TVD
        {
            TVD.push_back(trajdir->tvdVertical[i]);
        }

    for(int i = 0; i < buildup->tvd_vetor.size(); i++)
        {
            TVD.push_back(buildup->tvd_vetor[i]);
        }
    for(int i = 0; i < slant->tvd_vetor_slant.size(); i++)
        {
            TVD.push_back(slant->tvd_vetor_slant[i]);
        }

    for(int i = 0; i < trajdir->mdVertical.size(); i++)     ///VETOR MD
        {
            MD.push_back(trajdir->mdVertical[i]);
        }

    for(int i = 0; i < buildup->md_vetor.size(); i++)
        {
            MD.push_back(buildup->md_vetor[i]);
        }
    for(int i = 0; i <= slant->md_vetor_slant.size(); i++)
        {
            MD.push_back(slant->md_vetor_slant[i]);
        }

    for(int i = 0; i < trajdir->incVertical.size(); i++)    ///VETOR INC
        {
            INC.push_back(trajdir->incVertical[i]);
        }

    for(int i = 0; i < buildup->inclination.size(); i++)
        {
            INC.push_back(buildup->inclination[i]);
        }
    for(int i = 0; i < slant->inclination_slant.size(); i++)
        {
            INC.push_back(slant->inclination_slant[i]);
        }

    for(int i = 0; i < TVD.size(); i++)     ///VETOR AZM
        {
            AZM.push_back(trajdir->azm);
        }

    cout << endl;
    cout << "======================================================================================="<<endl;

    cout.width(10); ///AQUI JOGAMOS O RESULTADO NA TELA EM COLUNAS
    cout << "MD (m) \t" << "     TVD (m) \t" << "   INC (°) \t" << "  AZM (°) \t" <<  endl;

    for (int i=0; i < TVD.size(); i++)
    {
        cout << setiosflags (ios::fixed) << setprecision(2);
        cout.width(8);
        cout << MD[i] << right << "\t";

        cout.width(8);
        cout << TVD[i] << right << "\t";

        cout.width(6);
        cout << INC[i] << right << "\t";

        cout.width(6);
        cout << AZM[i] << right << endl;
    }
}

void CTrajDirecional::SaidaDados(){

    fstream fout;   ///ARQUIVO COM A TABELA DOS RESULTADOS FINAIS DO PROGRAMA
    fout.open("trajetoriaDirecional.txt", ios::app);
    fout << setw(50) << " Vetores das trajetorias calculados" << endl;
    fout << setiosflags (ios::fixed) << setprecision(2);
    fout << setw(12) << "MD (m) \t" << setw(12) << "TVD (m) \t" << setw(12) << "INC (°) \t" << setw(10) << "AZM (°)  \t" << endl;
    for (int i = 0; i<TVD.size(); i++){
        fout << setw(10) << MD[i] << '\t' << setw(10) << TVD[i] << '\t' << setw(10) << INC[i] << '\t' << setw(10) << AZM[i] << '\t'  << setw(10) << endl;
    }
}
