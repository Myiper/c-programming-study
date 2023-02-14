#include <stdio.h>
#include <math.h>
int main(){
    int n;
    printf("How many students?\n");
    scanf("%d", &n);
    int arr[n];
    int i;
    int toplam = 0;
    double kare;
    for (int i = 1; i <= n; i++) {
        printf("Grade %d: \n", i);
        int not;
        scanf("%d", &not);
        toplam += not;
        
        arr[i-1] = not;
    } 
    float arit = toplam/ (float) n;
    for(int j = 0; j < n; j++){
        kare += (arr[j] - arit) * (arr[j] - arit);
    }
    double sonuc = sqrt(kare/(n-1));

    printf("Arithmetic Mean: %f\n", arit);
    printf("Standard Eviation: %f\n", sonuc);
    return 0;
}