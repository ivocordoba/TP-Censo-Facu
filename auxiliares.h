#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"
bool esMatriz(vector<vector<dato>> mat);

// modificamos el if
bool noEsVacia(vector<vector<dato>> mat);

bool cantidadCorrectaDeColumnasI(eph_h ti);

bool cantidadCorrectaDeColumnasH(eph_h th);

bool hayHogarConCodigo(eph_h th, int c);

bool hayIndividuosSinHogar(eph_i ti, eph_h th);

bool hayIndividuoConCodigo(eph_i ti, int c);

bool hayHogaresSinIndividuos(eph_i ti, eph_h th);

bool mismoCodusuYComponente(individuo i1, individuo i2);

bool hayRepetidosI(eph_i ti);

// Corregido, agregamos un ciclo
bool hayRepetidosH(eph_h th);
bool mismoAnioYTrimestre(eph_i ti, eph_h th);

bool esSuHogar(hogar h, individuo i);

int cantHabitantes(hogar h, eph_i ti);

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti);

bool cantidadValidaDormitorios(eph_h th);

// Agregamos los que eran combinaciones de dos comparaciones
bool individuoValido(individuo i);

bool valoresEnRangoI(eph_i ti);

bool valorRegionValido(int r);

bool hogarValido(hogar h);

bool valoresEnRangoH(eph_h th);

bool esValida(eph_h th, eph_i ti);
/////////////////////EJ2

bool esCasa(hogar h);

int maximaCantidadHabitacionesEnLaRegion(eph_h th, int region);

int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones);
////////////////////EJ3

bool hogarConHacinamientoCritico(hogar h, eph_i ti);

bool esHogarValido(hogar h, int region);

int cantHogaresValidos(eph_h th, int region);

int cantHogaresValidosConHC(eph_h th, eph_i ti, int region);

double proporcionDeCasasConHc(eph_h th, eph_i ti, int region);

/////////////////////////////////////EJ4

bool esCasaODepartamento(hogar h);

bool realizaSusTareasEnEsteHogar(individuo i);

bool tieneEspaciosReservadosParaElTrabajo(hogar h);

bool esDeCiudadGrande(individuo i, eph_h th);

bool suHogarEsCasaODepartamento(individuo i, eph_h th);

bool suHogarTieneEspaciosReservadosParaElTrabajo(individuo i, eph_h th);

bool trabaja(individuo i);

bool individuoEnHogarValido(individuo i, eph_h th);

bool trabajaEnSuVivienda(individuo i, eph_h th);

int cantIndividuosQueTrabajan(eph_h th, eph_i ti);

int cantIndividuosTrabajandoEnSuVivienda(eph_h th, eph_i ti);

float proporcionTeleworking(eph_h th, eph_i ti);
/////////////////EJ5

bool tieneCasaPropia(hogar h);
bool tieneCasaChica(hogar h, eph_i ti);
/////////////////EJ7

void swap(vector<vector<int>>& a, int b, int c);
void ordenarPorRegionYCodusu(eph_h& th);

int hogarCorrespondiente(eph_h th, individuo i);

void ordenarPorCodusuYComponente(eph_i& ti, const eph_h& th);

//////////////////////EJ8

int ingresosPorHogar(hogar h, eph_i ti);

int difIngresosHogares(hogar h1, hogar h2, eph_i ti);

void ordenarPorIngresos(eph_h& th, const eph_i& ti);

////////EJ10

void quitarCasasTH(vector<vector<int>> ind, eph_h& th, pair<eph_h, eph_i>& result);

void quitarIndividuosTI(vector<vector<int>> ind, eph_i& ti, pair<eph_h, eph_i>& result);

/////////////////////EJ11

int distanciaAlCentro(pair<int,int> centro, int latitud, int longitud);

int cantidadDeHogaresEnAnillo(const eph_h& th,int distDesde, int distHasta, pair<int,int> centro);



#endif //SOLUCION_AUXILIARES_H

