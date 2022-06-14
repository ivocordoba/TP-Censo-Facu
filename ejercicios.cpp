#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
///// Implementacion Problema 1 /////
bool esEncuestaValida ( eph_h th, eph_i ti ) {
    return esValida(th,ti);
}

///// Implementacion Problema 2 /////
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
    vector<int> histograma;
    for(int i = 0; i < maximaCantidadHabitacionesEnLaRegion(th, region); i++){
        histograma.push_back(cantHogaresCasaConNHabitaciones(th, region, i+1));
    }
    return histograma;
}

///// Implementacion Problema 3 /////
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {
    vector<int> regiones = {1,40,41,42,43,44};
    vector<pair<int, float>> resultado;
    for(int i = 0; i < 6; i++){
        pair<int, float> res;
        res.first = regiones[i];
        res.second = proporcionDeCasasConHc(th, ti, regiones[i]);
        resultado.push_back(res);
    }
    return resultado;
}

///// Implementacion Problema 4 /////
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    return proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i);
}

///// Implementacion Problema 5 /////
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
    int costo = 0;
    for (int i = 0; i < th.size(); ++i) {
        if (tieneCasaPropia(th[i]) && tieneCasaChica(th[i], ti)){
            costo+=monto;
        }
    }
    return costo;
}

///// Implementacion Problema 6 /////
join_hi generarJoin( eph_h th, eph_i ti ){
    join_hi junta;
    for(int i = 0; i < ti.size(); i++){
        for (int j = 0; j < th.size(); ++j) {
            if (esSuHogar(th[j], ti[i])) {
                par_hi temp;
                temp.first = th[j];
                temp.second = ti[i];
                junta.push_back(temp);
            }
        }
    }
    return junta;
}


///// Implementacion Problema 7 /////
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
    ordenarPorRegionYCodusu(th);
    ordenarPorCodusuYComponente(ti, th);
    return;
}

///// Implementacion Problema 8 /////
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    ordenarPorIngresos(th, ti);
    vector<vector<int>> res;
    for (int i = 0; i < th.size(); ++i) {
        for (int j = i+1; j < th.size(); ++j) {
            vector<vector<int>> temp;
            temp.push_back(th[i]);
            temp.push_back(th[j]);
            int diferencia = difIngresosHogares(temp[0], temp[1], ti);
            if (diferencia != 0) {
                for (int k = j + 1; k < th.size(); ++k) {
                    if (diferencia == difIngresosHogares(temp[temp.size() - 1], th[k], ti)) {
                        temp.push_back(th[k]);
                    } else if (diferencia < difIngresosHogares(temp[temp.size() - 1], th[k], ti)) {
                        break;
                    }
                }
            }
            if (temp.size() > res.size()){
                res = temp;
            }
        }
    }
    if (res.size() < 3){
        return {};
    }
    return res;
}

///// Implementacion Problema 9 /////
void corregirRegion( eph_h & th, eph_i ti ) {
    for(int i = 0; i < th.size(); i++){
        if(th[i][REGION] == 1){
            th[i][REGION] = 43;
        }
    }
    return;
}

///// Implementacion Problema 10 /////
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
    vector<int> result;
    result.push_back(cantidadDeHogaresEnAnillo(th, 0, distancias[0], centro));
    for(int i = 1; i < distancias.size(); i++){
        result.push_back(cantidadDeHogaresEnAnillo(th, distancias[i-1], distancias[i], centro));
    }
    return result;
}

///// Implementacion Problema 11 /////
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, int > >  busqueda ){
    vector<vector<int>> prob;
    for(int i = 0; i < ti.size(); i++){
        if(ti[i][busqueda[0].first] == busqueda[0].second){
            int t = 1;
            while(t < busqueda.size()){
                if(ti[i][busqueda[t].first] != busqueda[t].second){
                    t = -1;
                    break;
                }
                t+=1;
            }
            if(t != -1){
                prob.push_back(ti[i]);
            }
        }
    }
    pair<eph_h, eph_i> result;
    quitarCasasTH(prob, th, result);
    quitarIndividuosTI(prob, ti, result);
    return result;
}
