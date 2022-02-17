from map_base import MapBase


class UnsortedTableMap(MapBase):
    """
    Storing key-value pairs in an arbitrary order in a Python list   
    """
    def __init__(self):
        self._table = []

    def __getitem__(self, k):
        """ O(n) """
        for item in self._table:
            if item._key == k:
                return item._value
        raise KeyError('Key Error: ' + repr(k))

    def __setitem__(self, k, v):
        """ O(n) """
        for item in self._table:
            if item._key == k:
                item._value = v
                return
        self._table.append(self._Item(k, v))

    def __delitem__(self, k):
        """ O(n) """
        for j in range(len(self._table)):
            if self._table[j]._key == k:
                self._table.pop(j)
                return
        raise KeyError('Key Error: ' + repr(k))

    def __len__(self):
        return len(self._table)

    def __iter__(self):
        for item in self._table:
            yield item._key


if __name__ == '__main__':
    map = UnsortedTableMap()
    map['nice'] = 1
    map['great'] = 2
    del map['great']
    print(len(map))

    for key in map:
        print(map[key])
