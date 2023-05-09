// Write a program in java to find volume of a box using constructor overloading.

class Box {
    int length, breadth, height;

    Box(int length, int breadth, int height) {
        this.length = length;
        this.breadth = breadth;
        this.height = height;
    }

    Box(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
        this.height = 1;
    }

    Box(int length) {
        this.length = length;
        this.breadth = 1;
        this.height = 1;
    }

    Box() {
        this.length = 1;
        this.breadth = 1;
        this.height = 1;
    }

    void display() {
        System.out.println("Volume: " + (length * breadth * height));
    }
}

class q2 {
    public static void main(String[] args) {
        Box obj1 = new Box(10, 20, 30);
        Box obj2 = new Box(10, 20);
        Box obj3 = new Box(10);
        Box obj4 = new Box();

        obj1.display();
        obj2.display();
        obj3.display();
        obj4.display();
    }
}