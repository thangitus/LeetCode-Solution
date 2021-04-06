#include <bits/stdc++.h>

using namespace std;

/*
 * https://leetcode.com/problems/minimum-operations-to-make-array-equal/
 * Ý tưởng:
 *          Chuyển toàn bộ các phần tử của mảng về giá trị trung bình target=sum(arr)/n, sử dụng công thức cấp số cộng để tính
 *          Tiếp tục sử dụng cấp số cộng để tính chi phí chuyển với:
 *              a1 là phần tử gần với target nhất, nếu target chẵn thì phần tử gần nó nhất sẽ cần 1 chi phí, nếu target lẻ thì sẽ cần 2 chi phí
 *              an là phần tử xa với target nhất (arr[0]=1) nên sẽ tốn target-arr[0]=target-1
 *              n = target/2 là số phần tử cần đổi. Vì thực hiện 1 chi phí là đổi đc 2 phần tử nên chia 2
 * */


class Solution {
public:
    int minOperations(int n) {
        int a1, an, sn, target;
        a1 = 1, an = (n - 1) * 2 + 1;
        sn = (a1 + an) * n / 2;
        target = sn / n;

        if (target % 2)
            a1 = 2;
        else a1 = 1;
        an = target - 1;
        n = target / 2;
        return (a1 + an) * n / 2;
    }
};