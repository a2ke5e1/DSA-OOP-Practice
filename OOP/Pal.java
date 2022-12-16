import java.util.Scanner;

class Paldrome {
    public boolean isPaldrome(String s) {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();  
        return s.equals(sb.toString()); 
    }
}

public class Pal {
    public static void main(String args[]) {
        Paldrome p = new Paldrome(); 
        Scanner sc = new Scanner(System.in); 
        System.out.println(p.isPaldrome(sc.nextLine()));
    }
}
