#include <stdio.h>
int main(){
  int n[31], i = 0, j = 1;
  int count[10] = {0};
  int sequence[10] = {-1};
  scanf("%d",&n[i]);
  while(n[i] != -1){
    if(count[n[i]] == 0){
      sequence[j] = n[i];
      j++;
    }
    count[n[i]]++;
    i++;
    scanf("%d",&n[i]);
  }
  int max = 0;
  int ans = 0;
  for(int k = 1; k < 10; k++){
    if(count[k] > max){
      max = count[k];
      ans = k;
    }
  }
  for(int k = 1; k < 10; k++){
    if(count[sequence[k]] == max)
      printf("%d ",sequence[k]);
  }
  printf("appeared %d time(s)\n",count[ans]);
}
