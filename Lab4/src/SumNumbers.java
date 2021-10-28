public class SumNumbers implements Runnable {
    private int n;
    private Sum mySum;

    public SumNumbers(int n, Sum sumObject) {
        this.n = n;
        mySum = sumObject;
    }

    public void run() {
        System.out.println(Thread.currentThread().getName() + " is computing....");
        int total = 0;
        for (int i = 0; i <= n; i++) {
            total += i;
            try {
                Thread.currentThread().sleep(1);
            } catch (InterruptedException ie) {
                System.out.println("Whoops!");
            }
        }
        System.out.println(Thread.currentThread().getName() + " is done!!");
        mySum.set(total);
    }
}
