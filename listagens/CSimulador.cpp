#include "CSimulador.h"

#include <iostream>
#include <iomanip>
using namespace std;

void CSimulador::Simular(){
    ///CABEÇALHO DO NOSSO PROGRAMA
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "          Universidade Estadual do Norte Fluminense Darcy Ribeiro               " << endl;
    cout << "            Laboratorio de Engenharia e Exploracao de Petroleo                  " << endl;
    cout << "         SIMULADOR PARA CALCULO DA TRAJETORIA DE POCOS DE PETROLEO              " << endl;
    cout << "  Desenvolvido por: Antonio Jose dos Reis Neto e Tatiana Vitorio Isidorio       " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    cout << "Entre com a letra V para poco vertical e D para direcional: "; ///AQUI O USUÁRIO ESCOLHE O TIPO DO POÇO
    cin  >> tipo;

    while (tipo != 'V' && tipo != 'v' && tipo != 'D' && tipo != 'd') ///MENSAGEM DE ERRO CASO O USUARIO DIGITAR ALGO NAO
        {                                                            ///ESPERADO
            cout<< "Opcao invalida." << endl;
            cout<< "Entre com V para poco vertical e D para direcional: ";
            cin>> tipo;
        }

    if (tipo == 'V' || tipo == 'v') ///CASO O USUARIO ESCOLHA V PARA POÇO VERTICAL, ENTRAMOS NESSA ROTINA
        {
            trajvert->EntradaDadosVertical(); ///entra atributos independentes e calcula atributos dependentes
            trajvert->SaidaDadosVertical();

            plotar4 << "set term png\n";    /// NESTA PARTE DO NOSSO CODIGO GERAMOS OS GRAFICOS NECESSARIOS PARA ANALISE DOS RESULTADOS
            plotar4 << "set out \"MDxINC_Vertical.png\"\n";
            plotar4.XRange(-5,90);                    plotar4.XLabel("Inclinação");
            plotar4.YRange(trajvert->tvd, 0);         plotar4.YLabel("Profundidade Medida");
            plotar4.Style("lines");
            plotar4.Title("MD x INC");
            plotar4.Grid(1);
            plotar4.plotfile_xy("trajetoriaVertical.txt", 3,1);
        }
    else    ///SE ESCOLHER UM POÇO DIRECIONAL, ENTRAMOS NESSA ROTINA
        {
            trajdir->EntradaDadosDirecional(); ///entra atributos independentes e calcula atributos dependentes
            trajdir->SaidaDadosDirecional();
            buildup->SaidaDadosBuild();
            slant->SaidaDadosSlant();
            direcional->CriarVetorCompleto();
            direcional->SaidaDados();

            plotar1 << "set term png\n";    ///NESTA PARTE DO NOSSO CODIGO GERAMOS OS GRÁFICOS NECESSÁRIOS PARA ANALISE DOS RESULTADOS
            plotar1 << "set out \"MDxTVD.png\"\n";
            plotar1.XRange(0,trajdir->tvd);         plotar1.XLabel("Profundidade Vertical");
            plotar1.YRange(trajdir->md_total, 0);   plotar1.YLabel("Profundidade Medida");
            plotar1.Style("lines");
            plotar1.Title("MD x TVD");
            plotar1.Grid(1);
            plotar1.plotfile_xy("trajetoriaDirecional.txt", 2,1);

            plotar2 << "set term png\n";
            plotar2 << "set out \"MDxINC.png\"\n";
            plotar2.XRange(-5,90);                    plotar2.XLabel("Inclinação");
            plotar2.YRange(trajdir->md_total,0);      plotar2.YLabel("Profundidade Medida");
            plotar2.Style("lines");
            plotar2.Title("MD x INC");
            plotar2.Grid(1);
            plotar2.plotfile_xy("trajetoriaDirecional.txt", 3,1);

            plotar3 << "set term png\n";
            plotar3 << "set out \"MDxAZM.png\"\n";
            plotar3.XRange(0,360);                  plotar3.XLabel("Azimute");
            plotar3.YRange(trajdir->md_total, 0);   plotar3.YLabel("Profundidade Medida");
            plotar3.Style("lines");
            plotar3.Title("MD x AZM");
            plotar3.Grid(1);
            plotar3.plotfile_xy("trajetoriaDirecional.txt", 4,1);

        }
}
