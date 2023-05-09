// Write a program in java to implement multiple inheritance using interface.

interface A {
    void display();
}

interface B {
    void print();
}

class C implements A, B {
    public void display() {
        System.out.println("Display");
    }

    public void print() {
        System.out.println("Print");
    }
}

public class q3 {
    public static void main(String[] args) {
        C obj = new C();
        obj.display();
        obj.print();
    }
}