#include <stdio.h>
#include <math.h>

int main(void){
    double R, H, L, V;
    printf("R L H: ");
    // %d ->int %f->float %lf->double %c ->char %s -> string
    scanf("%lf %lf %lf", &R, &L, &H);
    V = (acos((R - H) / R) * R * R - (R - H)* sqrt(2*R*H - H*H)) * L;
    printf("Volume = %.2lf m^3\n", V);
    return 0;
}
