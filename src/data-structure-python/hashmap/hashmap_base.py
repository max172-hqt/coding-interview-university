from random import randrange
from map_base import MapBase


class HashMapBase(MapBase):
    def __init__(self, cap=2, p=109345121):
        self._table = [None] * cap 
        self._n = 0
        self._cap = cap 
        self._prime = p
        self._scale = 1 + randrange(p - 1) # a: from 1 to p-1
        self._shift = randrange(p)         # b: from 0 to p-1

    def __len__(self):
        return self._n

    def __getitem__(self, k):
        j = self._hash_function(k)
        return self._bucket_getitem(j, k)

    def __setitem__(self, k, v):
        j = self._hash_function(k)
        self._bucket_setitem(j, k, v)
        # if self._n > len(self._table) // 2:
        #     self.resize(len(self._table) * 2 - 1) # -1 for prime

    def __delitem__(self, k):
        j = self._hash_function(k)
        self._bucket_delitem(j, k)
        self._n -= 1

    def load_factor(self):
        return self._n / self._N

    def resize(self, c):
        old = list(self.items())
        self._n = 0
        self._table = [None] * c
        for k, v in old:
            self[k] = v

    def _hash_function(self, k):
        return (hash(k) * self._scale + self._shift) % self._prime % len(self._table)

    def _bucket_getitem(self, j, k):
        """Get item with key k in bucket j"""
        raise NotImplemented()

    def _bucket_setitem(self, j, k, v):
        """Set item in bucket j"""
        raise NotImplemented()

    def _bucket_delitem(self, j, k):
        """ Delete item with key k in bucket j"""
        raise NotImplemented()

    def __iter__(self):
        raise NotImplemented()
