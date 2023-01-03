void insertOrderedArray(int *array,int data,int tail){
  int ticker = 1;
  for(int i = tail;i >= 0;i--){
    if(data < array[i]){
        array[i+1] = array[i];
    }else{
        array[i+1] = data;
        ticker = 0;
        break;
    }
  }
  if(ticker == 1){
        array[0] = data;
  }
}
