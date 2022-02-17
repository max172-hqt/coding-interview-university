from hashmap_base import HashMapBase

class ChainHashMap(HashMapBase):
    class Node:
        def __init__(self, item):
            self.item = item
            self.next = None

    def _bucket_setitem(self, j, k, v):
        n = self.Node(self._Item(k, v))
        if self._table[j] is None:
            self._table[j] = n
            self._n += 1
        else:
            curr = self._table[j]
            while curr:
                if curr.item._key == k:
                    curr.item._value = v
                    break
                curr = curr.next
            if curr is None:
                n.next = self._table[j]
                self._table[j] = n
                self._n += 1

    def _bucket_getitem(self, j, k):
        """Get item with key k in bucket j"""
        if self._table[j] is None:
            raise KeyError('Key Error: ' + repr(k))
        curr = self._table[j]
        while curr: 
            if curr.item._key == k:
                return curr.item._value
            curr = curr.next

    def _bucket_delitem(self, j, k):
        """ Delete item with key k in bucket j"""
        if self._table[j] is None:
            raise KeyError('Key Error: ' + repr(k))

        prev = None
        curr = self._table[j]
        while curr.next:
            if curr.item._key == k:
                res = curr.item._value
                prev.next = curr.next
                return res
            prev = curr
            curr = curr.next

    def __iter__(self):
        for bucket in self._table:
            if bucket is not None:
                curr = bucket
                while curr:
                    yield curr.item._key
                    curr = curr.next

    def print_debug(self):
        print("----------")
        for i, bucket in enumerate(self._table):
            if bucket is not None:
                print(f'bucket {i}: ', end='')
                curr = bucket
                while curr:
                    print(f'( {curr.item._key} - {curr.item._value} ) -> ', end='')
                    curr = curr.next
                print('None')
        print("----------")

if __name__ == '__main__':
    hm = ChainHashMap()
    hm['a'] = 1
    hm['b'] = 2
    assert hm['a'] == 1
    assert hm['b'] == 2
    assert len(hm) == 2
    del hm['a']
    assert len(hm) == 1
    hm.print_debug()


    hm['a'] = 2
    assert hm['a'] == 2
    assert hm['b'] == 2
    hm['c'] = 2
    hm['d'] = 2
    hm['e'] = 2
    hm['e'] = 10 

    hm.print_debug()

    for key in hm:
        print(f"{key} {hm[key]}")

    hm = ChainHashMap()
    hm['a'] = 1
    assert len(hm) == 1
    hm['a'] = 2
    assert len(hm) == 1
    hm['b'] = 1
    assert len(hm) == 2
