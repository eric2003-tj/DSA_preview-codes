int bisearch(int *array,int data,int len){
  int begin = 0;
  int end = len-1;
  int mid = (begin+end)/2;
  while(begin>=0 && end<=len-1 && end >= begin){
    mid = (begin+end)/2;
    if(array[mid] == data){
        return mid;
    }else if(array[mid]>data){
        end = mid-1;
    }else{
        begin = mid+1;
    }
  }
  return -1;
}
