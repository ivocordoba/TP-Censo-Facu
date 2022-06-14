#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
using namespace std;

int cantidadItemsIndividuo = 11;
int cantidadItemsHogar = 12;
int EDAD = CH6;
int GENERO = CH4;
int INGRESOS_TOT = p47T;
int LUGAR_TRABAJO = PP04G;
int TENENCIA = II7;
int HABITACIONES = IV2;
int DORMITORIOS = II2;
int TRABAJA_HOGAR = II3;

bool esMatriz(vector<vector<dato>> mat){
    for(int i = 0; i < mat.size()-1; i++){
        if(mat[i].size() != mat[i+1].size()){
            return false;
        }
    }
    return true;
}

bool noEsVacia(vector<vector<dato>> mat){
    return (mat.size() > 0);
}

bool cantidadCorrectaDeColumnasI(eph_h ti){
    for(int i = 0; i < ti.size(); i++){
        if(ti[i].size() != cantidadItemsIndividuo){
            return false;
        }
    }
    return true;
}

bool cantidadCorrectaDeColumnasH(eph_h th){
    for(int i = 0; i < th.size(); i++){
        if(th[i].size() != cantidadItemsHogar){
            return false;
        }
    }
    return true;
}

bool hayHogarConCodigo(eph_h th, int c){
    for(int i = 0; i < th.size(); i++){
        if(th[i][HOGCODUSU] == c){
            return true;
        }
    }
    return false;
}

bool hayIndividuosSinHogar(eph_i ti, eph_h th){
    for(int i = 0; i < ti.size(); i++){
        if(!hayHogarConCodigo(th,ti[i][INDCODUSU])){
            return true;
        }
    }
    return false;
}

bool hayIndividuoConCodigo(eph_i ti, int c){
    for(int i = 0; i < ti.size(); i++){
        if(ti[i][INDCODUSU] == c){
            return true;
        }
    }
    return false;
}

bool hayHogaresSinIndividuos(eph_i ti, eph_h th){
    for(int i = 0; i < th.size(); i++){
        if(!hayIndividuoConCodigo(ti, th[i][HOGCODUSU])){
            return true;
        }
    }
    return false;
}

bool mismoCodusuYComponente(individuo i1, individuo i2){
    if(i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE] == i2[COMPONENTE]){
        return true;
    }else{
        return false;
    }
}

bool hayRepetidosI(eph_i ti){
    for(int i = 0; i < ti.size()-1; i++){
        if(mismoCodusuYComponente(ti[i], ti[i+1])){
            return true;
        }
    }
    return false;
}

bool hayRepetidosH(eph_h th){
    for(int i = 0; i < th.size()-1; i++){
        for (int j = 0; j < th.size(); ++j) {
            if (i != j && th[i][HOGCODUSU] == th[j][HOGCODUSU]) {
                return true;
            }
        }
    }
    return false;
}

bool mismoAnioYTrimestre(eph_i ti, eph_h th){
    for(int i = 0; i < th.size()-1; i++){
        if((th[i][HOGANIO] != th[i+1][HOGANIO] || th[i][HOGTRIMESTRE] != th[i+1][HOGTRIMESTRE])){
            return false;
        }
    }
    int anioHogar = th[0][HOGANIO];
    for(int i = 0; i < ti.size()-1; i++){
        if((ti[i][INDANIO] != ti[i+1][INDANIO] || ti[i][INDTRIMESTRE] != ti[i+1][INDTRIMESTRE] || ti[i][INDANIO] != anioHogar)){
            return false;
        }
    }
    return true;
}

bool esSuHogar(hogar h, individuo i){
    return (h[HOGCODUSU] == i[INDCODUSU]);
}

int cantHabitantes(hogar h, eph_i ti){
    int acc = 0;
    for(int i = 0; i < ti.size(); i++){
        if(esSuHogar(h, ti[i])){
            acc += 1;
        }
    }
    return acc;
}

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti){
    for(int i = 0; i < th.size(); i++){
        if(cantHabitantes(th[i], ti) >= 21){
            return false;
        }
    }
    return true;
}

bool cantidadValidaDormitorios(eph_h th){
    for(int i = 0; i < th.size(); i++){
        if(th[i][HABITACIONES] < th[i][DORMITORIOS]){
            return false;
        }
    }
    return true;
}

bool individuoValido(individuo i){
    if(i[INDCODUSU] > 0 &&
    i[COMPONENTE] > 0 &&
    (0 < i[INDTRIMESTRE] && i[INDTRIMESTRE] <= 4) &&
    (0 < i[GENERO] && i[GENERO] <= 2) &&
    i[EDAD] >= 0 &&
    (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1) &&
    (-1 <= i[ESTADO] && i[ESTADO] <= 1) &&
    (0 <= i[CAT_OCUP] && i[CAT_OCUP] <= 4) &&
    (i[INGRESOS_TOT] >= 0 || i[INGRESOS_TOT] == -1) &&
    (0 <= i[LUGAR_TRABAJO] && i[LUGAR_TRABAJO] <= 10)
    ){
        return true;
    }else{
        return false;
    }
}

bool valoresEnRangoI(eph_i ti){
    for(int i = 0; i < ti.size(); i++){
        if(!individuoValido(ti[i])){
            return false;
        }
    }
    return true;
}

bool valorRegionValido(int r){
    return (r == 1 || (40 <= r && r <= 44));
}

bool hogarValido(hogar h){
    if(h[HOGCODUSU] > 0 &&
    (0 < h[HOGTRIMESTRE] && h[HOGTRIMESTRE] <= 4) &&
    (0 < h[TENENCIA] && h[TENENCIA] <= 3) &&
    valorRegionValido(h[REGION]) &&
    (h[MAS_500] == 0 || h[MAS_500] == 1) &&
    (0 < h[IV1] && h[IV1] <= 5) &&
    (h[HABITACIONES] > 0) &&
    (h[DORMITORIOS] >= 1) &&
    (h[TRABAJA_HOGAR] == 1 || h[TRABAJA_HOGAR] == 2)
    ){
        return true;
    }else{
        return false;
    }
}

bool valoresEnRangoH(eph_h th){
    for(int i = 0; i < th.size(); i++){
        if(!hogarValido(th[i])){
            return false;
        }
    }
    return true;
}

bool esValida(eph_h th, eph_i ti){
    return (noEsVacia(th) && noEsVacia(ti) && esMatriz(th) && esMatriz(ti)
    && cantidadCorrectaDeColumnasH(th) && cantidadCorrectaDeColumnasI(ti) &&
    !hayHogaresSinIndividuos(ti,th) && !hayIndividuosSinHogar(ti, th) &&
    !hayRepetidosH(th) && !hayRepetidosI(ti) && mismoAnioYTrimestre(ti, th) &&
    menosDe21MiembrosPorHogar(th, ti) && cantidadValidaDormitorios(th) &&
    valoresEnRangoI(ti) && valoresEnRangoH(th));
}

/////////////////////EJ2

bool esCasa(hogar h){
    return h[IV1] == 1;
}

int maximaCantidadHabitacionesEnLaRegion(eph_h th, int region){
    int maximo = 0;
    for(int i = 0; i < th.size(); i++){
        if(esCasa(th[i]) && th[i][REGION] == region){
            maximo = max(maximo, th[i][HABITACIONES]);
        }
    }
    return maximo;
}

int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones){
    int acc = 0;
    for(int i = 0; i < th.size(); i++){
        if(esCasa(th[i]) && th[i][REGION] == region && th[i][HABITACIONES] == habitaciones){
            acc += 1;
        }
    }
    return acc;
}

////////////////////EJ3

bool hogarConHacinamientoCritico(hogar h, eph_i ti){
    return (cantHabitantes(h, ti) > 3*h[DORMITORIOS]);
}

bool esHogarValido(hogar h, int region){
    return (esCasa(h) && h[REGION] == region && !h[MAS_500]);
}

int cantHogaresValidos(eph_h th, int region){
    int acc = 0;
    for(int i = 0; i < th.size(); i++){
        if(esHogarValido(th[i], region)){
            acc += 1;
        }
    }
    return acc;
}

int cantHogaresValidosConHC(eph_h th, eph_i ti, int region){
    int acc = 0;
    for(int i = 0; i < th.size(); i++){
        if(esHogarValido(th[i], region) && hogarConHacinamientoCritico(th[i], ti)){
            acc += 1;
        }
    }
    return acc;
}

double proporcionDeCasasConHc(eph_h th, eph_i ti, int region){
    if(cantHogaresValidos(th, region) > 0){
        return (float)cantHogaresValidosConHC(th, ti, region) / (float)cantHogaresValidos(th, region);
    }else{
        return 0;
    }
}

/////////////////////////////////////EJ4

bool esCasaODepartamento(hogar h){
    return (h[IV1] == 1 || h[IV1] == 2);
}

bool realizaSusTareasEnEsteHogar(individuo i){
    return (i[PP04G] == 6);
}

bool tieneEspaciosReservadosParaElTrabajo(hogar h){
    return (h[II3] == 1);
}

bool esDeCiudadGrande(individuo i, eph_h th){
    for (int j = 0; j < th.size(); ++j) {
        if (esSuHogar(th[j], i) && th[j][MAS_500]){
            return true;
        }
    }
    return false;
}

bool suHogarEsCasaODepartamento(individuo i, eph_h th){
    for (int j = 0; j < th.size(); ++j) {
        if (esSuHogar(th[j], i) && esCasaODepartamento(th[j])){
            return true;
        }
    }
    return false;
}

bool suHogarTieneEspaciosReservadosParaElTrabajo(individuo i, eph_h th){
    for (int j = 0; j < th.size(); ++j) {
        if (esSuHogar(th[j], i) && tieneEspaciosReservadosParaElTrabajo(th[j])){
            return true;
        }
    }
    return false;
}

bool trabaja(individuo i){
    return i[ESTADO] == 1;
}

bool individuoEnHogarValido(individuo i, eph_h th){
    return (esDeCiudadGrande(i, th) && suHogarEsCasaODepartamento(i, th));
}

bool trabajaEnSuVivienda(individuo i, eph_h th){
    return (realizaSusTareasEnEsteHogar(i) && suHogarTieneEspaciosReservadosParaElTrabajo(i, th));
}

int cantIndividuosQueTrabajan(eph_h th, eph_i ti){
    int acc = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if(trabaja(ti[i]) && individuoEnHogarValido(ti[i], th)){
            acc++;
        }
    }
    return acc;
}

int cantIndividuosTrabajandoEnSuVivienda(eph_h th, eph_i ti){
    int acc = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if(trabaja(ti[i]) && trabajaEnSuVivienda(ti[i], th) && individuoEnHogarValido(ti[i], th)){
            acc++;
        }
    }
    return acc;
}

float proporcionTeleworking(eph_h th, eph_i ti){
    if (cantIndividuosQueTrabajan(th, ti) > 0){
        return ((float)cantIndividuosTrabajandoEnSuVivienda(th, ti) / (float)cantIndividuosQueTrabajan(th, ti));
    }
    return 0;
}

/////////////////EJ5

bool tieneCasaPropia(hogar h){
    return (h[II7] == 1);
}

bool tieneCasaChica(hogar h, eph_i ti){
    return (cantHabitantes(h, ti) - 2 > h[II2]);
}

/////////////////EJ7

void swap(vector<vector<int>>& a, int b, int c){
    vector<int> k = a[b];
    a[b] = a[c];
    a[c] = k;
    return;
}

void ordenarPorRegionYCodusu(eph_h& th){
    for(int i = 0; i < th.size(); i++){
        while( i > 0 && ((th[i][REGION] < th[i-1][REGION]) || (th[i][REGION] == th[i-1][REGION] && th[i][HOGCODUSU] < th[i-1][HOGCODUSU]))){
            swap(th, i, i-1);
            i--;
        }
    }
}

int hogarCorrespondiente(eph_h th, individuo i){
    for (int j = 0; j < th.size(); j++) {
        if (th[j][HOGCODUSU] == i[INDCODUSU]){
            return j;
        }
    }
}

void ordenarPorCodusuYComponente(eph_i& ti, const eph_h& th){
    for(int i = 0; i < ti.size(); i++){
        while( i > 0 && ((hogarCorrespondiente(th, ti[i]) < hogarCorrespondiente(th, ti[i-1])) ||
        (hogarCorrespondiente(th, ti[i]) == hogarCorrespondiente(th, ti[i-1]) &&
        ti[i][COMPONENTE] < ti[i-1][COMPONENTE]))){
            swap(ti, i, i-1);
            i--;
        }
    }
}

//////////////////////EJ8

int ingresosPorHogar(hogar h, eph_i ti){
    int ingresos = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (h[HOGCODUSU] == ti[i][INDCODUSU]){
            if (ti[i][INGRESOS_TOT] != -1) {
                ingresos += ti[i][INGRESOS_TOT];
            }
        }
    }
    return ingresos;
}

int difIngresosHogares(hogar h1, hogar h2, eph_i ti){
    return abs(ingresosPorHogar(h1, ti)- ingresosPorHogar(h2, ti));
}

void ordenarPorIngresos(eph_h& th, const eph_i& ti) {
    for (int i = 0; i < th.size(); i++) {
        while (i > 0 && (ingresosPorHogar(th[i], ti) < ingresosPorHogar(th[i - 1], ti))){
            swap(th, i, i - 1);
            i--;
        }
    }
}

/////////////////////EJ10

int distanciaAlCentro(pair<int,int> centro, int latitud, int longitud){ return sqrt(pow(centro.first-latitud, 2) + pow(centro.second-longitud, 2));}

int cantidadDeHogaresEnAnillo(const eph_h& th,int distDesde, int distHasta, pair<int,int> centro){
    int acc = 0;
    for(int i = 0; i < th.size(); i++){
        if(distanciaAlCentro(centro, th[i][HOGLATITUD], th[i][HOGLONGITUD]) > distDesde &&
        distanciaAlCentro(centro, th[i][HOGLATITUD], th[i][HOGLONGITUD]) <= distHasta){
            acc += 1;
        }
    }
    return acc;
}

////////EJ11

void quitarCasasTH(vector<vector<int>> ind, eph_h& th, pair<eph_h, eph_i>& result){
    for(int i = 0; i < ind.size(); i++){
        for(int j = 0; j < th.size(); j++){
            if(ind[i][INDCODUSU] == th[j][HOGCODUSU]){
                result.first.push_back(th[j]);
                th.erase(th.begin()+j);
            }
        }
    }
}

void quitarIndividuosTI(vector<vector<int>> ind, eph_i& ti, pair<eph_h, eph_i>& result){
    for(int i = 0; i < ind.size(); i++){
        result.second.push_back(ind[i]);
        for(int k = 0; k < ti.size(); k++){
            if(ti[k][INDCODUSU] == ind[i][INDCODUSU] && ti[k][COMPONENTE] == ind[i][COMPONENTE]){
                ti.erase(ti.begin()+k);
            }
        }
    }
}
