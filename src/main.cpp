
#include <main.h>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

double mutation(double x0, double x1)
{
  const int NUM = 100000000;
  return fabs((double)((rand() * NUM) % (int)((x1 - x0)*NUM) + 1) / NUM) + x0;
}

double inversion(double x, double eps)
{
  static int sign = 0;
  sign++;
  sign %= 2;
  if (sign == 0) return x - eps;
  else return x + eps;
}

void crossover(double *x, double eps, double x0, double x1)
{
  int k = 99;
  for (int i = 0; i < 8; i++) 
    for (int j = i + 1; j < 8; j++) 
    {
      x[k] = (x[i] + x[j]) / 2;
      k--;
    }

  for (int i = 0; i < 8; i++) 
  {
    x[k] = inversion(x[i], eps); k--;
    x[k] = inversion(x[i], eps); k--;
  }
#if 0
    for (int i = 8; i < k; i++)
        x[i] = mutation(x0, x1); 
#endif
}

void sort(double *x, double *y) 
{
  for (int i = 0; i < 100; i++)
    for (int j = i + 1; j < 100; j++) 
      if (fabs(y[j]) < fabs(y[i])) {
        swap(y[i], y[j]);
        swap(x[i], x[j]);
      }
}

double DLL_EXPORT genetic(char* extremum)
{
  double x0 = 0.00012, x1 = 1.0, eps = 0.000001;
  double* population = new double[100];
  double* f = new double[100];
  int counter = 0;
  auto foo = [](double x){ return -5 * cos(10 * x) * sin(3 * x) / pow(x, 1/2); } ;
  for (int i = 0; i < 100; i++)
  {
    population[i] = mutation(x0, x1);
    f[i] = foo(population[i]);
  }

  sort(population, f);
  do {
    counter++;
    crossover(population, eps, x0, x1);
    for (int i = 0; i < 100; i++) 
      f[i] = foo(population[i]);
    sort(population, f);
  } while (fabs(f[0]) < eps && counter < 20000);

  double res = population[99];
  delete[] population;
  delete[] f;
  return res;
}