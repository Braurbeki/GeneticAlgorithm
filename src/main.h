#pragma once


#define DLL_EXPORT __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

double DLL_EXPORT genetic(char* extremum);

void sort(double *x, double *y);
void crossover(double *x, double eps, double x0, double x1);
double inversion(double x, double eps);
double mutation(double x0, double x1);
#ifdef __cplusplus
}
#endif