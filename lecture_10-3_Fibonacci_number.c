#include <stdio.h>


int fibonacci(int n) {
    int ans;
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    else {
        ans = fibonacci(n-1) + fibonacci(n-2);
        return ans;
    }
    return 0;
}


int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d\n", fibonacci(n));
  return 0;
}
