class MathX {
    public int fact(int n) {
        if ( n <= 1 ) {
            return 1; 
        }
        return n * fact(n-1); 
    }
}


public class test2 {
    public static void main(String[] args) {
        for (int i = 0; i < 15; i++) {
            MathX mathX = new MathX();
            int n = mathX.fact(i);  
            System.out.println(n);
        }      
    }
}
