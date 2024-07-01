class A():
    def __init__(self):
        print("-> A")
        super(A, self).__init__()
        print("<- A")

class B():
    def __init__(self):
        print("-> B")
        super(B, self).__init__()
        print("<- B")

class C(A, B):
    def __init__(self):
        print("-> C")
        super(C, self).__init__()
        print("<- C")


if __name__ == "__main__":
    objC = C()
