C_swap(&x,&y);
void c_swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
cpp_swap(x,y); //just like nickname
void cpp_swap(int &x,int &y){
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}
