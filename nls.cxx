#include <cmath>
#include <iostream>

using namespace std;
void f(double* k, double* k1, double* k2, double* k3, double* y, const double eta, double* a, double dx){
  
  k[0] = y[1]+dx*a[0]*k1[1]+dx*a[1]*k2[1];
  k[1] = (eta - pow(y[0]+dx*a[0]*k1[0]+dx*a[1]*k2[0],2))*(y[0]+dx*a[0]*k1[0]+dx*a[1]*k2[0]);
  
}

int main(){
  const int N = 100000;
  double dx = 100.0/N;
  double eta = 0.4;
  double y[2];
  double k[2];
  double k1[2];
  double k2[2];
  double k3[2];
  double a[2];
  y[0] = 1E-5;
  y[1] = sqrt(eta)*y[0];
  
  cout << 0 << "\t" << y[0] << "\t" << y[1] << endl;
  
  for(int i=0; i<N; i++){
  
    a[0] = 0;
    a[1] = 0;
    f(k1, k1, k2, k3, y, eta, a, dx);
    a[0] = 0.5;
    a[1] = 0;
    f(k2, k1, k2, k3, y, eta, a, dx);
    a[0] = -1.0;
    a[1] = 2.0;
    f(k3, k1, k2, k3, y, eta, a, dx);
  
    y[0] = y[0] + dx/6 * (k1[0] + 4*k2[0] + k3[0]);
    y[1] = y[1] + dx/6 * (k1[1] + 4*k2[1] + k3[1]);
    
    cout << i*dx << "\t" << y[0] << "\t" << y[1] << endl;
    
  }
  
 return 0; 
}