/* C Structure */
typedef struct{
  double real;
  double img;
}Complex;
Complex multiply(Complex a,Complex b){
  Complex result;
  result.real = a.real*b.real - a.img*b.img;
  result.img = a.real*b.img + b.real*a.img;
  return result;
}

/* C++ class */
class Complex{
  public:
    double real;
    double img;
    void multiplyby(Complex another){...}
}
