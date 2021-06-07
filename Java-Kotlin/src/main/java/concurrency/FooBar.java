package concurrency;

/**
 * https://leetcode.com/problems/print-foobar-alternately/
 **/

class FooBar {
    private int n;
    private boolean isRunFoo = true;

    public FooBar(int n) {
        this.n = n;
    }

    public synchronized void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (!isRunFoo) wait();
            printFoo.run();
            isRunFoo = false;
            notifyAll();
        }
    }

    public synchronized void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (isRunFoo) wait();
            printBar.run();
            isRunFoo = true;
            notifyAll();
        }
    }
}