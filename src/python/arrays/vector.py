class Vector:
    """
    Mutable array with automatic sizing
    """

    INIT_CAPACITY = 2

    def __init__(self):
        self._arr = [None] * self.INIT_CAPACITY
        self._size = 0
        self._capacity = self.INIT_CAPACITY

    def capacity(self):
        """Number of items it can hold"""
        return self._capacity

    def is_empty(self):
        """Check if the vector is empty"""
        return self._size == 0

    def __getitem__(self, index):
        """Return item at given index, blows up if index out of bounds"""
        if index < 0 or index >= len(self):
            raise IndexError('index out of bound')
        return self._arr[index]

    def __str__(self):
        """String representation of vector"""
        return '<' + str(self._arr[:len(self)])[1:-1] + '>'

    def __len__(self):
        """Number of items"""
        return self._size

    def _resize(self, new_capacity):
        """Resize the capacity"""
        self._capacity = new_capacity
        temp_arr = [None] * self.capacity()
        for i in range(len(self)):
            temp_arr[i] = self[i]
        self._arr = temp_arr
        
    def push(self, item):
        """Push the item to the end of vector"""
        if len(self) == self.capacity():
            self._resize(self.capacity() * 2)
        self._arr[self._size] = item
        self._size += 1

    def pop(self):
        """ Remove from the end, return the value """
        if len(self) == 0:
            raise Exception('Cannot pop from empty list')
        item = self[len(self) - 1]
        self._size -= 1
        return item

    def insert(self, index, item):
        """Insert at index, shift index's value and all trailing items to the right"""
        if index >= len(self):
            raise IndexError('out of bound index')
        if len(self) == self.capacity():
            self._resize(self.capacity() * 2)
        for j in range(len(self)-1, index-1, -1):
            self._arr[j+1] = self._arr[j]
        self._arr[index] = item
        self._size += 1

    def prepend(self, item):
        """Insert at index 0"""
        self.insert(0, item)

    def delete(self, index):
        """Delete item at given index, shift all trailing items to the left"""
        if index >= len(self):
            raise IndexError('out of bound index')
        for j in range(index, len(self)-1):
            self._arr[j] = self._arr[j+1]
        self._size -= 1
        if len(self) <= self.capacity() / 4 and self.capacity() >= self.INIT_CAPACITY * 2:
            self._resize(int(self.capacity() / 2))
        print(self._arr)

    def remove(self, item):
        """Look for value and remove all index holding it"""
        j = 0
        while j < len(self):
            try:
                if self[j] == item:
                    self.delete(j)
                else:
                    j += 1
            except IndexError:
                break

    def find(self, item):
        for j in range(len(self)):
            if self._arr[j] == item:
                return j
        return -1


def main():
    a = Vector()
    print('capacity:', a.capacity(), 'size', len(a))
    a.push(1)
    a.push(2)
    a.delete(1)
    print(a)


if __name__ == "__main__":
    main()
