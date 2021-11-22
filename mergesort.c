#include <stdio.h>
#include <stdlib.h>


void merge(int a[], int sz1, int sz2);



void merge_sort(int arr[], int n){
  // your code here
  /*10
58 93 23 56 129 47 64 93 27 69*/
  for(int i = 1; i < n/2 ; i *= 2){ // 我的ｉ是最小單位的長度 就是它拿來merge的兩個陣列各自的長度 這個可以 ok
    for(int j = 0; j < n - i; j += i){ // j是從陣列的哪裡開始提取他的值 比方說我要arr[2] arr[3] 那我的 j就是2 i就是1 (剛剛打錯)豪 先繼續吧QQ
      int *a = (int*) malloc (2 *sizeof(int)); //欸我解釋一下 看你有什麼問題 豪 QAQ不行 我剛看你游標在上面 那邊行嗎
      if(2 * i + j > n){ //這個是我怕爆掉所以設的 現別管他 豪
        break;
      }//哈囉 嗨
      else{
        for(int k = 0; k < 2*i; k++){ //這邊是我開始提取陣列 換個說法好了 arr[j]到 arr[j + i - 1] 和 arr[j + i] 到 arr[j + 2*i -1]都丟到 a
          a[k] = arr[j+k]; //所以如果我要 arr[0]到 arr[1] 和 arr[2] 到 arr[3] 就用 j = 0; i = 2; 喔好
        }//為什麼都是i阿? m 因為原本的陣列就是要你找他的兩個size 然後把兩個陣列merge了  這兩個陣列長度都是 i 只是我把它裝在同一個而已 可以理解ㄌ
         merge(a, i, i); //這邊就是把剛剛提曲的陣列丟到 merge mergesort 的概念就是反覆做這個動作 沒跟你要什麼?? 從哪裡排 比方說j = 0
        for(int k = 0; k < 2* i; k++)//好 至於為什麼不傳原本的陣列 因為沒辦法 我們要排後面的值的時候會有問題 畢竟他只給 size1跟size2
          arr[j+k] = a[k]; //這邊就是把原本傳過去的陣列貼回來 畢竟我們傳的不是原本的陣列 他不會改到我們的值
        free(a); //比方說j = 0的時候可以直接排 但是 j = 1不行 因為你沒辦法叫他從 j=1 開始 他的（我的）函數設計就是這樣爛 好哈
      }

  }//居然嗎 對呀 貴班同學的行為 那你還有不
  merge(arr,n/2,n-n/2); //記得上面的if嗎？ if 是我怕爆掉放的 這邊就是最後再把他排一次 （雖然只放這行其實也可以排得好

}

int main(){
   int *a,  size

   //  input
   scanf("%d", &size);
   a = (int*) malloc(sizeof(int)*size);
   for(int i=0; i< size; i++){
      scanf("%d", a+i);
   }


   //  sort
   merge_sort(a, size);

   //  output
   for(int i=0; i< size-1; i++)
      printf("%d ", a[i]);

   printf("%d\n", a[size-1]);

   free(a);
   return 0;
}



void merge(int a[], int size1, int size2){
  /* your lab 6-2 code
   * Don't use any other merge function !!!
   */
  for(int i = 0; i < size1+size2; i++){
    for(int j= 0; j< i; j++){
      if(a[i] < a[j]){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}
