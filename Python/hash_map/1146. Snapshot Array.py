class SnapshotArray:

    def __init__(self, length: int):
        self.cur_snap_id = 0
        self.matrix = [{} for _ in range(length)]

        for i in range(length):
            self.matrix[i][0] = 0

    def set(self, index: int, val: int) -> None:
        self.matrix[index][self.cur_snap_id] = val

    def snap(self) -> int:
        self.cur_snap_id += 1
        return self.cur_snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        while snap_id not in self.matrix[index]:
            snap_id -= 1
        return self.matrix[index][snap_id]
