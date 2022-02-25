#include <bits/stdc++.h>


using namespace std;

class SnapshotArray {
private:
    vector<unordered_map<int, int>> matrix;
    int curSnapId = 0;
public:
    SnapshotArray(int length) {
        matrix.resize(length);
        for (int i = 0; i < length; ++i)
            matrix[i][curSnapId] = 0;
    }

    void set(int index, int val) {
        matrix[index][curSnapId] = val;
    }

    int snap() {
        return curSnapId++;
    }

    int get(int index, int snap_id) {
        while (matrix[index].find(snap_id) == matrix[index].end())
            snap_id--;
        return matrix[index][snap_id];
    }
};
