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
  double P_SN = 0.0;
};

void inicializar_gremios (vector<gremio> & gremios);
void probabilidad_prior (vector<gremio> gremios);
void multiplicadores (vector<gremio> gremios, double & alfa, double & beta, double & gamma, double & Z);
double funcion_de_particion (vector<gremio> gremios, double beta, double gamma);
double prior (vector<gremio> gremios, int S, int N);
double probabilidad_PNS_teorico (int S, int N, double beta, double gamma, double prior, double Z);


int main ()
{
  
}

void inicializar_gremios (vector<gremio> & gremios)
{
    for (int ii=0; ii<Gc; ii++)
    {
      gremios[ii].id = ii+1;
      //genera numeros distribuidos uniformemente
      std::mt19937 gen(ii);
      std::uniform_real_distribution<int> disS(0, 2500); //Rango de valores para especies
      std::uniform_real_distribution<int> disN(0, 100000); //Rango para valores de individuos
      gremios[ii].S = disS(gen);
      gremios[ii].N = disN(gen);
      gremios[ii].prob_prior = 1.0; // Se usa un prior igual a 1 por el momento
    }
}

void multiplicadores (vector<gremio> gremios, double & alfa, double & beta, double & gamma, double & Z);
{
  double meanN = 0.0; //Igual a la temperatura ecologica
  double meanS = 0.0;
  
  for (int ii = 0; ii<Gc; ii++)
    {
      meanN += gremios[ii].N/Gc; //<N>
      meanS += gremios[ii].S;
    }

  meanS = meanS/Gc; //<S>
  
  beta = 1.0/meanT; //beta = 1/T con T = Npromedio

  gamma = 0;

  Z = funcion_de_particion(gremios, beta, gamma);

  alfa = -ln(Gc/Z);
}

double funcion_de_particion (vector<gremio> gremios, double beta, double gamma)
{
  double Z = 0.0;
 
  for (int ii=0; ii<Gc; ii++)
    {
      for (int jj=0; jj<Gc; jj++)
	{
	  int N = gremios[ii].N;
	  int S = gremios[jj].S;

	  double prob_prior = prior (gremios, S, N);
	  
	  double expon = -1.0*beta*N - gamma*S;
	  
	  Z += prob_prior*exp(expon);
	}
    }
  
  return Z;
}

double prior (vector<gremio> gremios, int S, int N)
{
  double prob_prior = 1.0;
  return prob_prior;
}

double probabilidad_PNS_teorico (int S, int N, double beta, double gamma, double prior, double Z)
{
  double PNS = 0.0;

  PNS = prior*exp(-1.0*beta*N-gamma*S)/Z;

  return PNS;
}
