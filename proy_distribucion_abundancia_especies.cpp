#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

#define _USE_MATH_DEFINES
using namespace std;

const double Gc = 100;  //Número de gremios

struct gremio{
  int id = 0;
  int S = 0;
  int N = 0;
  double prob_prior = 0.0;
  double P_SN = 0.0;
};

void inicializar_gremios (vector<gremio> & gremios);
void probabilidad_prior (vector<gremio> gremios);
double multiplicador_alpha (vector<gremio> gremios);
double multiplicador_beta (vector<gremio> gremios);
double multiplicador_gamma (vector<gremio> gremios);
double funcion_de_particion (vector<gremio> gremios);

int main ()
{
  
}

void inicializar_gremios (vector<gremio> & gremios)
{
  
}

double funcion_de_particion (vector<gremio> gremios, vector<double> multiplicadores)
{
  double Z = 0.0;

  double alpha = multiplicadores[0];
  double beta = multiplicadores[1];
  double gamma = multiplicadores[2];
  
  for (int ii=0; ii<Gc; ii++)
    {
      double expon = -beta*gremios[ii].N - gamma*gremios[ii].S;
      Z += gremios[ii].prob_prior*exp(expon);
    }

  return Z;
}

double multiplicador_alpha (vector<gremio> gremios)
{
  double alpha = 0.0;
  double Z = funcion_de_particion(gremios);
  double frac = Gc;
}

double 
