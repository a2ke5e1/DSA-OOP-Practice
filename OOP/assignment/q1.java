//  1. Write a program in java to find sum and average of three numbers using super keyword.

class Numbers {
    int a, b, c;
    Numbers(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

class SumAverage extends Numbers {
    SumAverage(int a, int b, int c) {
        super(a, b, c);
    }

    void display() {
        System.out.println("Sum: " + (a + b + c));
        System.out.println("Average: " + (a + b + c) / 3);
    }
}

public class q1 {
    public static void main(String[] args) {
        SumAverage obj = new SumAverage(10, 20, 30);
        obj.display();
    }
}
