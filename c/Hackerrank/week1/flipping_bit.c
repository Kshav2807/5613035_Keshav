#include<stdio.h>
unsigned int flipBit(unsigned int num){
    return num ^ 0xFFFFFFFF;
}
int main(){
    int queries;
    scanf("%d", &queries);

  for (int i = 0; i < queries; ++i) {
        unsigned int n;
        scanf("%u", &n);  
        printf("%u\n", flipBit(n));   
}
return 0;
}