/*
 *  Write an application with three threads & main thread such that all the threads are synchronized using synchronized method and ensure that main thread is the last thread to complete.
 *  In first time we evaulate table of 2, in second time we evaluate table of 3 and in third time we evaluate table of 4. 
 * while main thread will display the number 1 to 10.
*/

class Table
{
    synchronized void printTable(int n)
    {
        for(int i=1;i<=10;i++)
        {
            System.out.println(n + " * " + i + " = " + n*i);
            try
            {
                Thread.sleep(400);
            }
            catch(Exception e)
            {
                
            }
        }
    }
}

class Caller extends Thread
{
   Table t;
   int k;

    Caller(Table t, int k)
    {
         this.t = t;
         this.k = k;
    }

    public void run()
    {
        t.printTable(k);
    }

}

class test
{
    public static void main(String args[])
    {
        Table obj = new Table();
        Caller c1 = new Caller(obj, 2);
        Caller c2 = new Caller(obj, 3);
        Caller c3 = new Caller(obj, 4);
        c1.start();
        c2.start();
        c3.start();
        for(int i=1;i<=10;i++)
        {
            System.out.println("Main Thread : " + i);
            try
            {
                Thread.sleep(400);
            }
            catch(Exception e)
            {
            
            }
        }
    }
}



