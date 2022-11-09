#include <bits/stdc++.h>

using namespace std;

class StockSpanner {
    stack<pair<int, int>> stack;
    int curDay = 0;
public:
    StockSpanner() {
        stack.push({INT_MAX, -1});
    }

    int next(int price) {
        int topPrice = stack.top().first, day = stack.top().second, span;
        if (topPrice > price) {
            stack.push({price, curDay});
            span = curDay - day;
        } else {
            while (!stack.empty() && stack.top().first <= price) stack.pop();
            span = curDay - stack.top().second;
            stack.push({price, curDay});
        }
        curDay++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */