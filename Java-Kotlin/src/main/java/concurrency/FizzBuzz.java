package concurrency;

import java.util.function.IntConsumer;

/**
 * https://leetcode.com/problems/fizz-buzz-multithreaded/
 **/

class FizzBuzz {
    private int n;
    private int currNumber = 1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        synchronized (this) {
            while (currNumber <= n) {
                if (currNumber % 3 != 0 || currNumber % 5 == 0) {
                    wait();
                    continue;
                }
                printFizz.run();
                currNumber++;
                notifyAll();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        synchronized (this) {
            while (currNumber <= n) {
                if (currNumber % 3 == 0 || currNumber % 5 != 0) {
                    wait();
                    continue;
                }
                printBuzz.run();
                currNumber++;
                notifyAll();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        synchronized (this) {
            while (currNumber <= n) {
                if (currNumber % 3 != 0 || currNumber % 5 != 0) {
                    wait();
                    continue;
                }
                printFizzBuzz.run();
                currNumber++;
                notifyAll();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        synchronized (this) {
            while (currNumber <= n) {
                if (currNumber % 3 == 0 || currNumber % 5 == 0) {
                    wait();
                    continue;
                }
                printNumber.accept(currNumber);
                currNumber++;
                notifyAll();
            }
        }
    }
}