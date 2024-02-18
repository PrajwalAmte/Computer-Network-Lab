#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define u long long int

void transmission(u *i, u *N, u *tf, u *tt) {
    while(*i <= *tf) {
        int z = 0;
        for (int k = *i; k < *i + *N && k <= *tf; k++) {
            printf("Sending Frame %d...\n", k);
            (*tt)++;
        }
        for (int k = *i; k < *i + *N && k <= *tf; k++) {
            int f = rand() % 2;
            if (!f) {
                printf("Acnowledgement for Frame %d...\n", k);
                z++;
            } else {
                printf("Timeout!! Frame Number: %d Not Receved\n", k);
                printf("Retransmitting Window...\n");
                break;
            }
        }
        printf("\n");
        *i = *i + z;
    }
}

int main() {
    u tf, N, tt = 0;
    srand(time(NULL));
    printf("Enter the Total number of frames: ");
    scanf("%lld", &tf);
    printf("Enter the Window Size: ");
    scanf("%lld", &N);

    u i = 1;
    transmission(&i, &N, &tf, &tt);
    printf("Total number of frames which were sent and resent are: %lld\n", tt);
    return 0;
}