package OOP;


class Q1 {

    public static void main(String[] args) {
        Double[] num = {1.0, 2.0, 3.0, 4.0}; 
        double sum = 0; 

        for (int i = 0 ; i < num.length ; i++) {
            sum += num[i]; 
        }

        double avg = sum / num.length; 
        System.out.println("Average is " + avg);

    }

}