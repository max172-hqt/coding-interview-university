class Node:
    """Node in a LinkedList"""
    def __init__(self, key):
        self.key = key
        self.next = None


class LinkedList:
    """
        Implement LinkedList data structure
        without tail pointer
    """
    def __init__(self):
        self.head = None

    def push_front(self, value):
        """Add an item at the front of the list"""
        newNode = Node(value)
        if self.head is None:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode

    def pop_front(self):
        """Remove front item and return its value"""
        if self.head is None:
            print('The list is empty')
        else:
            curr = self.head
            self.head = self.head.next
            return curr.key

    def push_back(self, value):
        """Add an item at the end"""
        newNode = Node(value)
        if self.head is None:
            self.head = newNode
        else:
            curr = self.head
            while curr.next:
                curr = curr.next
            curr.next = newNode

    def pop_back(self):
        """Remove end item and return its value"""
        if self.head is None:
            print('The list is empty')
        elif self.head.next is None:
            temp = self.head
            self.head = None
            return temp.key
        else:
            curr = self.head
            while curr.next.next:
                curr = curr.next
            res = curr.next
            curr.next = None
            return res.key

    def front(self):
        """Get value of front item"""
        if self.head is None:
            return None
        return self.head.key

    def back(self):
        """Get value of back item"""
        if self.head is None:
            return None
        curr = self.head
        while curr.next:
            # Loop until curr.next is None, curr would be the last element
            curr = curr.next
        return curr.key

    def value_at(self, index):
        """Return the value at the nth item"""
        if self.head is None:
            return None
        curr = self.head
        while index > 0 and curr.next:
            curr = curr.next
            index -= 1
        if index > 0:
            print('index out of bounds')
        else:
            return curr.key

    def size(self):
        """Return size of the list"""
        count = 0
        curr = self.head
        while curr:
            curr = curr.next
            count += 1
        return count

    def empty(self):
        """Return true if empty"""
        return self.size() == 0

    def insert(self, index, value):
        if index == 0:
            self.push_front(value)
            return

        # 1 -> 2 -> 3 -> 4
        curr = self.head
        prev = None
        while index > 0 and curr.next:
            prev = curr
            curr = curr.next 
            index -= 1

        newNode = Node(value)
        if index > 0:  # index out of range
            curr.next = newNode
        else:
            # insert before curr
            prev.next = newNode
            newNode.next = curr

    def __len__(self):
        return self.size()

    def __str__(self):
        curr = self.head
        res = ''
        while curr:
            res += str(curr.key) + ' -> '
            curr = curr.next
        res += 'None'
        return res


def main():
    ll = LinkedList()
    assert ll.empty()
    assert ll.size() == 0
    assert ll.front() is None
    assert ll.back() is None

    ll.push_front(4)
    ll.push_front(5)
    ll.push_front(6)
    assert ll.size() == 3
    assert not ll.empty()
    assert str(ll) == '6 -> 5 -> 4 -> None'
    assert ll.front() == 6
    assert ll.back() == 4
    assert ll.pop_front() == 6
    assert str(ll) == '5 -> 4 -> None'

    ll.push_back(1)
    assert str(ll) == '5 -> 4 -> 1 -> None'
    assert ll.front() == 5
    assert ll.value_at(2) == 1

    ll = LinkedList()
    ll.push_back(1)
    assert str(ll) == '1 -> None'
    assert ll.pop_front() == 1

    # Test pop back
    ll = LinkedList()
    ll.push_front(1)
    assert ll.pop_back() == 1
    assert ll.pop_back() == None
    assert str(ll) == 'None'
    assert ll.value_at(0) == None

    ll.push_front(4)
    ll.push_front(5)
    ll.push_front(6)
    assert ll.pop_back() == 4
    assert str(ll) == '6 -> 5 -> None'

    assert ll.value_at(0) == 6
    assert ll.value_at(1) == 5
    assert ll.value_at(2) == None

    # Test insert
    ll = LinkedList()
    ll.insert(0, 0)
    assert str(ll) == '0 -> None'

    ll = LinkedList()
    ll.push_front(0)
    ll.push_front(1)
    ll.push_front(2)
    ll.push_front(3)
    ll.insert(0, 4)
    assert str(ll) == '4 -> 3 -> 2 -> 1 -> 0 -> None'
    ll.insert(1, 5)
    assert str(ll) == '4 -> 5 -> 3 -> 2 -> 1 -> 0 -> None', str(ll)
    ll.insert(10, 5)
    assert str(ll) == '4 -> 5 -> 3 -> 2 -> 1 -> 0 -> 5 -> None', str(ll)
    ll.insert(6, 6)
    assert str(ll) == '4 -> 5 -> 3 -> 2 -> 1 -> 0 -> 6 -> 5 -> None', str(ll)
    ll.insert(3, 6)
    assert str(ll) == '4 -> 5 -> 3 -> 6 -> 2 -> 1 -> 0 -> 6 -> 5 -> None', str(ll)


if __name__ == '__main__':
    main()

