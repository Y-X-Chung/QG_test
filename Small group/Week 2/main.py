import numpy as np
from LinearRegression import LinearRegression
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LinearRegression,SGDRegressor
from sklearn.datasets import load_boston
from sklearn.metrics import mean_squared_error

# 获取数据
boston = load_boston()

# 划分数据集
x_train,x_test,y_train,y_test = train_test_split(boston.data,boston.target,random_state=8)

# 1> 创建一个转换器
transfer = StandardScaler()

# 2> 数据标准化
x_train = transfer.fit_transform(x_train)
x_test = transfer.transform(x_test)

# 模型训练
reg2 = LinearRegression()
reg2.fit(x_train, y_train)
print(reg2.coef_)
print(reg2.intercept_)

# 模型评估
y_predict = reg2.score(x_test, y_test)
print(y_predict)