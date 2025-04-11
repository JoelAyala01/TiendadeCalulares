#define MAXIMO 100

void menu();
void registrarCelular(int cant, int ID[MAXIMO], char marca[MAXIMO][20], float GB[MAXIMO], float RAM[MAXIMO], float precio[MAXIMO]);
void consultarInventario(int cant, int ID[MAXIMO], char marca[MAXIMO][20], float GB[MAXIMO], float RAM[MAXIMO], float precio[MAXIMO], char vendido[MAXIMO]);
void venderCelular(int cant, int ID[MAXIMO], char marca[MAXIMO][20], float GB[MAXIMO], float RAM[MAXIMO], float precio[MAXIMO], char vendido[MAXIMO], float ventasPorMarca[MAXIMO]);
