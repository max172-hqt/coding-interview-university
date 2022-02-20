from hashmap_base import HashMapBase


class ProbeHashMap(HashMapBase):
    _AVAIL = object()

    def _is_available(self, j):
        return self._table[j] is None or self._table[j] is ProbeHashMap._AVAIL

    def _find_slot(self, j, k):
        """
        Search for key k in bucket j

        Return (success, index) tuple described as follow
        if a match was found, success is True and index denotes its location
        if no match found, success is False and index denotes the next
        available slot
        """
        first_avail = None

        while True:
            if self._is_available(j):
                if first_avail is None:
                    first_avail = j
                # only stop when there is a slot that's actually empty
                # not slot that was recently deleted
                if self._table[j] is None:
                    return False, first_avail
            else:
                if k == self._table[j]._key:
                    return True, j
            j = (j + 1) % len(self._table)

    def _bucket_getitem(self, j, k):
        found, index = self._find_slot(j, k)
        if not found:
            raise KeyError('Key Error: ' + repr(k))
        return self._table[index]._value

    def _bucket_setitem(self, j, k, v):
        found, index = self._find_slot(j, k)
        if not found:
            self._table[index] = self._Item(k, v)
            self._n += 1
        else:
            self._table[index]._value = v

    def _bucket_delitem(self, j, k):
        found, index = self._find_slot(j, k)
        if not found:
            raise KeyError('Key Error: ' + repr(k))
        self._table[index] = ProbeHashMap._AVAIL

    def __iter__(self):
        for j in range(len(self._table)):
            if not self._is_available(j):
                yield self._table[j]._key


def main():
    hm = ProbeHashMap()
    hm['a'] = 1
    hm['b'] = 2
    hm['a'] = 2
    hm['c'] = 3
    hm['d'] = 4
    hm['e'] = 5
    hm['f'] = 6
    assert len(hm) == 6
    del hm['f']
    assert len(hm) == 5

    for key in hm:
        print(hm[key])


if __name__ == "__main__":
    main()
