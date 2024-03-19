import numpy as np
from keras.models import Sequential
from keras.layers import Dense
from keras.optimizers import SGD

#데이터
X = np.array([1,2,3,4,5,6,7,8,9,10])
Y = np.array([2,4,6,8,10,12,14,16,18,20])

#모델 구축
model = Sequential()
model.add(Dense(1,input_shape=(1,),activation='linear' ))

#옵티마이저 및 손실 함수 설정
optimizer = SGD(learning_rate=0.01) # 학습률 : 0.01
model.compile(optimizer,loss='mean_squared_error') # MSE

#모델 학습
model.fit(X,Y,epochs=100000)

#학습된 모델을 사용하여 예측
predictions = model.predict(X)

#결과 출력
for i in range(len(X)) : 
    print('실제 값 : ',Y[i] , '예측 값 : ',predictions[i][0])