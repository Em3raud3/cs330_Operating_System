# ! Ran on Python 3.8.10

class Machine:
    def __init__(self):
        self.Q = []
        self.Σ = []
        self.δ = {}  # we initialize � here
        self.q0 = ""
        self.qf = []

    def description(self):
        print(f"M = <Q, Σ, δ, {self.q0}, {self.qf} >")
        print(f"Q = {self.Q}")
        print(f"Σ = {self.Σ}")
        print(f"δ = {self.δ}")
        print(f"qo = {self.q0}")
        print(f"qf = {self.qf}")

    def addArrow(self, q1, symbol, q2):
        arrow = (q1, symbol)
        self.δ[arrow] = q2

    def removeArrow(self, q1, symbol, q2):
        arrow = (q1, symbol)
        del self.δ[arrow]



if __name__ == "__main__":
    main()
