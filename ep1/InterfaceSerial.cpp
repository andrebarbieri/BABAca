#include "InterfaceSerial.h"
void InterfaceSerial::inicializar(string porta) {
 nomes[0] = "T1";
 nomes[1] = "T2";
 nomes[2] = "T3";
 nomes[3] = "T4";
 nomes[4] = "T5";
}
double InterfaceSerial::getValor(string canal) {
 double valoresT1[] = {10, -27, 30, 40, 23, 0.012, 345, 23, -12, -0.002, 12 ,3};
 double valoresT2[] = {10, 0.00001, 0.6, 25, 23, -0.002,5,1,2};
 if (canal == "T1") return valoresT1[numeroDeChamadas];
 return valoresT2[numeroDeChamadas];
}
bool InterfaceSerial::atualizar() {
 numeroDeChamadas++;
 return true;
}
string* InterfaceSerial::getNomeDosCanais() {
 return nomes;
}
int InterfaceSerial::getQuantidadeDeCanais() {
 return 6;
}
