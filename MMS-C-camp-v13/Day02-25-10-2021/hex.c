#include <stdio.h>
#include <math.h>

int main(void){
    double R, H, L, V;
    printf("Enter radius: ");
    scanf("%lf", &R);
    printf("Enter height: ");
    scanf("%lf", &H);
    printf("Enter lenght: ");
    scanf("%lf", &L);
    V = (acos((R - H) / R) * R * R - (R - H)* sqrt(2*R*H - H*H)) * L;
    printf("Volume = %.2lf\n", V);
    return 0;
}
