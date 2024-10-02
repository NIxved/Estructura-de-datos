/****************************************
Autor: David Leon, 
Juan sebastian mendez, 
Sebastian Almanza Galvis, 
Juan Manuel López Vargas.
Materia: Estructura de Datos
Tema: Laboratorio TAD
****************************************/


#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>


class Vehiculo {
private:
    std::string placa;
    int tipo;

public:
    Vehiculo(std::string placa, int tipo) : placa(placa), tipo(tipo) {}

    std::string ObtenerPlaca() const {
        return placa;
    }

    int ObtenerTipo() const {
        return tipo;
    }
};


class Caseta {
private:
    std::queue<Vehiculo> cola;
    float totalRecaudado;
    std::map<int, float> recaudacionPorTipo;

public:
    Caseta() : totalRecaudado(0.0) {}

    void AgregarVehiculo(const Vehiculo &vehiculo) {
        cola.push(vehiculo);
    }

    float CobrarPeaje(float tarifa, const Vehiculo &vehiculo) {
        if (!cola.empty()) {
            cola.pop();
            totalRecaudado += tarifa;
            recaudacionPorTipo[vehiculo.ObtenerTipo()] += tarifa;
            return tarifa;
        }
        return 0.0; // Esto pasa cuando no hay vehículo en la caseta
    }

    Vehiculo ObtenerFrenteCola() const {
        if (!cola.empty()) {
            return cola.front();
        }
        throw std::runtime_error("La cola está vacía");
    }

    float RealizarArqueo() {
        float recaudado = totalRecaudado;
        totalRecaudado = 0.0;
        recaudacionPorTipo.clear();
        return recaudado;
    }

    int ObtenerTamanioCola() const {
        return cola.size();
    }

    float ObtenerRecaudacionPorTipo(int tipo) const {
        if (recaudacionPorTipo.find(tipo) != recaudacionPorTipo.end()) {
            return recaudacionPorTipo.at(tipo);
        }
        return 0.0;
    }
};



class PuntoDeCobro {
private:
    std::vector<Caseta> casetas;
    std::map<int, float> tarifas;

public:
    PuntoDeCobro(int numCasetas, const std::map<int, float> &tarifas)
        : casetas(numCasetas), tarifas(tarifas) {}

    void AgregarVehiculo(const Vehiculo &vehiculo) {
        int indiceMenorCola = 0;
        for (size_t i = 1; i < casetas.size(); ++i) {
            if (casetas[i].ObtenerTamanioCola() < casetas[indiceMenorCola].ObtenerTamanioCola()) {
                indiceMenorCola = i;
            }
        }
        casetas[indiceMenorCola].AgregarVehiculo(vehiculo);
    }

    void CobrarPeaje(int indiceCaseta) {
    if (indiceCaseta >= 0 && indiceCaseta < casetas.size()) {
        if (casetas[indiceCaseta].ObtenerTamanioCola() > 0) {
            Vehiculo vehiculo = casetas[indiceCaseta].ObtenerFrenteCola();
            float tarifa = tarifas[vehiculo.ObtenerTipo()];
            casetas[indiceCaseta].CobrarPeaje(tarifa, vehiculo);
            std::cout << "Se ha cobrado " << tarifa << " al vehiculo con placa " << vehiculo.ObtenerPlaca() << std::endl;
        }
    }
}

    float RealizarArqueoTotal() {
        float total = 0.0;
        for (Caseta &caseta : casetas) {
            total += caseta.RealizarArqueo();
        }
        return total;
    }

    float ObtenerRecaudacionPorTipo(int tipo) const {
        float total = 0.0;
        for (const Caseta &caseta : casetas) {
            total += caseta.ObtenerRecaudacionPorTipo(tipo);
        }
        return total;
    }
};

int main() {
   
    std::map<int, float> tarifas = {
        {1, 5000.0}, // Carro
        {2, 10000.0}, // Camión
        {3, 2000.0}, 
    };

    // Crea un punto de cobro con 3 casetas
    PuntoDeCobro puntoDeCobro(3, tarifas);

    // Simula la llegada de vehículos
    Vehiculo vehiculo1("ABC123", 1);
    Vehiculo vehiculo2("XYZ987", 2);
    Vehiculo vehiculo3("DEF456", 3);

    puntoDeCobro.AgregarVehiculo(vehiculo1);
    puntoDeCobro.AgregarVehiculo(vehiculo2);
    puntoDeCobro.AgregarVehiculo(vehiculo3);

    // Cobro de peaje en la caseta 0
    puntoDeCobro.CobrarPeaje(0);

    // Realiza el arqueo total
    float totalRecaudado = puntoDeCobro.RealizarArqueoTotal();
    std::cout << "Total recaudado en todas las casetas: " << totalRecaudado << std::endl;

    return 0;
}
