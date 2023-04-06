#include <iostream>
using namespace std;

void fknapscak(int p[], int w[],int n, int tW) {
    double pwratio[n]; 
    for (int i = 0; i < n; i++) {
        pwratio[i] = (double)p[i]/ (double)w[i]; 
    }
    // Sorting by p/w ratio
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (pwratio[i] < pwratio[j]) {
                int temp = pwratio[i]; 
                pwratio[i] = pwratio[j]; 
                pwratio[j] = temp; 

                temp = p[i]; 
                p[i] = p[j]; 
                p[j] = temp;

                temp = w[i]; 
                w[i] = w[j]; 
                w[j] = temp; 
            }
        }
    }
    // printing
    // for (int i = 0; i < n; i++) {
    //     cout << "P: "<< p[i] << " W: "<< w[i] << " P/W: "<< pwratio[i] << "\n"; 
    // } 

    double maxProfit = 0; 

    for (int i = 0; i < n; i++) {
        if (w[i] <= tW) {
            maxProfit += p[i]; 
            tW -= w[i]; 
        } else {
            maxProfit += pwratio[i] * tW; 
            break;   
        }
    }

    cout << "Max Profit: "  << maxProfit << "\n";  
}


int main() {
    int p[] = { 60,  100,  120 };
    int w[] = {  10 ,  20 , 30 };
    fknapscak(p,w, 3, 50); 
    return 0;
}