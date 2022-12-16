class Fib {
    public int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return fib(n - 2) + fib(n - 1);
    }
}

class test {

    public static void main(String args[]) {
        Fib f = new Fib(); 
        for (int i = 0; i < 100; i++) {
            System.out.println("fib " + i + ": " + f.fib(i));
        }

    }
}