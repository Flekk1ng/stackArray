import random


class car:
    def __init__(self):
        self.manufacturer = random.choice(['Audi', 'BMW', 'Ford', 'Honda', 'Hyundai'])
        self.model = random.randrange(1, 10)
        self.price = random.randrange(1500, 100000, 100)
        self.color = random.choice(['red', 'black', 'green', 'yellow', 'blue', 'purple'])
        self.max_speed = random.randrange(100, 280)


class stack:
    def __init__(self):
        self.stackArray = [0 for i in range(0, 20)]
        self.length = len(self.stackArray)

    def randstack(self):
        for i in range(0, 3):
            item = car()
            self.stackArray[i] = item

    def push(self, item):
        for i in range(self.length - 1, -1, -1):
            if not isinstance(self.stackArray[i], car):
                continue
            self.stackArray[i + 1] = self.stackArray[i]
        self.stackArray[0] = item

    def pop(self):
        popItem = self.stackArray[0]
        self.stackArray[0] = 0
        for i in range(0, self.length):
            if not isinstance(self.stackArray[i], car):
                continue
            self.stackArray[i - 1] = self.stackArray[i]
            if isinstance(self.stackArray[i], car) and not isinstance(self.stackArray[i + 1], car):
                self.stackArray[i] = 0
        return popItem

    def isEmpty(self):
        for i in range(0, self.length):
            if isinstance(self.stackArray[i], car):
                return False
        return True

    def printStack(self):
        for i in range(0, self.length):
            if isinstance(self.stackArray[i], car):
                print(f'manufacturer: {self.stackArray[i].manufacturer}, model: {self.stackArray[i].model}, price: {self.stackArray[i].price}, color: {self.stackArray[i].color}, maximum speed: {self.stackArray[i].max_speed}')


def main():
    s = stack()
    s.randstack()
    s.printStack()

    while not s.isEmpty():
        print('\n')
        item = s.pop()
        print(f'pop item: manufacturer: {item.manufacturer}, model: {item.model}, price: {item.price}, color: {item.color}, maximum speed: {item.max_speed}')
        s.printStack()


if __name__ == '__main__':
    main()