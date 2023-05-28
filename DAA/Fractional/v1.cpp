#include<stdio.h>

void fractionalKnapsack(float pw[], float p[], float w[], int  n, int tW) {
    int i = n - 1; 
    float maxProfit = 0; 

    printf("Total Profit\t\tp\t\t\tw\t\t\tRemaining Weight\n");     
    while ( w[i] <  tW) {
        maxProfit += p[i]; 
        tW -= w[i]; 
        printf("%f\t\t%f\t\t%f\t\t%f-%f=%d\n", maxProfit, p[i], w[i], tW+w[i], w[i], tW);
        i--;  
    }
    maxProfit += pw[i] * tW; 
    printf("%f\t\t%f\t\t%f\t\t%d-%d=%d\n", maxProfit, p[i], w[i], tW, tW, 0);
    printf("Maximum Proft: %f\n\n", maxProfit); 
}


int main() {
    int n, tW; 
    
    printf("Enter number of items: "); 
    scanf("%d", &n);
    
    float w[n], p[n]; 
    float pw[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Profit #%d: ", i+1); 
        scanf("%f", &p[i]);

        printf("Enter Weight #%d: ", i+1); 
        scanf("%f", &w[i]);

        pw[i] = p[i] / w[i]; 
    }


    printf("Enter total weight of the Bag: "); 
    scanf("%d", &tW); 

    // Sort 
    for (int i =0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ( pw[j] > pw[i]) {
                float temp = pw[i]; 
                pw[i] = pw[j]; 
                pw[j] = temp; 

                temp = p[i]; 
                p[i] = p[j]; 
                p[j] = temp; 

                temp = w[i]; 
                w[i] = w[j]; 
                w[j] = temp; 

            }
        }
    }

    
    printf("p\t\t\tw\t\t\tp/w\n"); 
    for ( int i = 0; i < n; i++) {
        printf("%f\t\t%f\t\t%f\n", p[i], w[i], pw[i]); 
    }
    printf("\n");

    fractionalKnapsack(pw, p, w,n, tW); 

    
    

    return 0; 
}