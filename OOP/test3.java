import java.util.Scanner;

public class test3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int n = sc.nextInt(); 
        
        int temp = n;
        int sum = 0; 
        int digits = String.valueOf(n).length();
        while (temp > 0) {
            int r = temp % 10; 
            sum += Math.pow(r, digits); 
            temp = temp / 10; 
        }

        if ( sum == n) {
            System.out.println("true");
        }



    }
}
