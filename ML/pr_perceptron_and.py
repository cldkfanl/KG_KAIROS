import numpy as np

class Perceptron :
    def __init__(self, N, alpha) :
        self.W = np.random.randn(N+1)/np.sqrt(N)
        self.alpha = alpha
        print("퍼셉트론 클래스 생성")

    def step(self, x) :
        if x > 0 :
            return 1
        else :
            return 0
    def fit(self, X, y, epochs = 10) :
        x = np.c_[X, np.ones(X.shape[0])]
        for epoch in range(epochs) :
            for(x, target) in zip(X, y) :
                p = self.step(np.dot(x, self.W))

                if p != target :
                    error = p- target
                    self.W += -self.alpha * error * X

    def predict(self, X) :
        X = np.atleast_2(X)
        X = np.c_[X, np.ones[0]]
        p = self.step(np.dot(X, self.w))

        print(p)
        print('---------------')
        
per = Perceptron(2, 0.9)
X = np.array([[0,0], [0,1], [1,0], [1,1]])
Y = [[0], [0], [0], [1]]

per.fit(X, Y)

x = np.array([0,0])
per.predict(x)

x = np.array([0,1])
per.predict(x)

x = np.array([1,0])
per.predict(x)

x = np.array([1,1])
per.predict(x)