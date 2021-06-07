package concurrency;

import java.util.function.IntConsumer;

/**
 * https://leetcode.com/problems/print-zero-even-odd/
 **/

class ZeroEvenOdd {
    private int n;
    private int turn = 0;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        synchronized (this) {
            for (int i = 1; i <= n; i++) {
                while (turn != 0) wait();
                printNumber.accept(0);
                turn = i % 2 == 0 ? 2 : 1;
                notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        synchronized (this) {
            for (int i = 2; i <= n; i += 2) {
                while (turn != 2) wait();
                printNumber.accept(i);
                turn = 0;
                notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        synchronized (this) {
            for (int i = 1; i <= n; i += 2) {
                while (turn != 1) wait();
                printNumber.accept(i);
                turn = 0;
                notifyAll();
            }
        }
    }

    public static void main(String[] args) {
        IntConsumer consumer1 = System.out::print;
        IntConsumer consumer2 = System.out::print;
        IntConsumer consumer3 = System.out::print;
        ZeroEvenOdd zeroEvenOdd = new ZeroEvenOdd(5);
        new Thread(() -> {
            try {
                zeroEvenOdd.zero(consumer1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();
        new Thread(() -> {
            try {
                zeroEvenOdd.even(consumer2);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();
        new Thread(() -> {
            try {
                zeroEvenOdd.odd(consumer3);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();

    }
}
