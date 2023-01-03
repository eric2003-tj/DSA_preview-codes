void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
int getMinIndex(int *array,int len){
  int minpos = 0;
  for(int i = 0;i<len;i++){
    if(*(array+i) < *(array+minpos)){
        minpos = i;
    }
  }
  return minpos;
}
void selSort(int *array,int len){
  for(int i=0;i<=len-1;i++){
    int min = getMinIndex(array+i,len-1-i+1);
    swap(array+min+i,array+i);
  }
}
