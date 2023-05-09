#include<stdio.h>

void ZeroOneKnapsack(float p[], float w[], int  n, int max) {
    float maxProfit = 0; 
    float totalWeight = 0; 

    for ( int i = n - 1; i >= 0; i--) {
        if ( w[i] <= max) {
            maxProfit += p[i]; 
            totalWeight += w[i]; 
            max -= w[i]; 
        }
    }

    printf("Total Profit: %f\n", maxProfit); 
    printf("Total Weight: %f\n", totalWeight); 

}


int main() {
    int n, tW; 
    
    printf("Enter number of items: "); 
    scanf("%d", &n);
    
    float w[n], p[n]; 
    for (int i = 0; i < n; i++) {
        printf("Enter Profit #%d: ", i+1); 
        scanf("%f", &p[i]);

        printf("Enter Weight #%d: ", i+1); 
        scanf("%f", &w[i]);
    }


    printf("Enter total weight of the Bag: "); 
    scanf("%d", &tW); 

    // Sort 
    for (int i =0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ( p[j] > p[i]) {
                float temp = p[i]; 
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
        printf("%f\t\t%f\t\t\n", p[i], w[i]); 
    }
    printf("\n");

    ZeroOneKnapsack(p, w,n, tW); 

    
    

    return 0; 
}