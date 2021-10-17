#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/simple-bank-system/
 * */

class Bank {
public:
    vector<long long> balance;
    int n;

    Bank(vector<long long> &balance) {
        this->balance = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > n) return false;
        if (account2 < 1 || account2 > n) return false;
        account1--, account2--;
        if (balance[account1] < money) return false;
        balance[account1] -= money;
        balance[account2] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account < 1 || account > n) return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account < 1 || account > n) return false;
        if (balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
};
