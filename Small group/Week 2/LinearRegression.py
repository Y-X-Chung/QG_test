import numpy as np
from SimpleLinearRegression import SimpleLinearRegression

class LinearRegression:

    def _init_(self):

        self.coef_ = None
        self.interception_ = None
        self._theta = None

    def fit(self, X_train, y_train):

        assert X_train.shape[0] == y_train.shape[0]

        x_0 = 1;
        X_0 = [x_0 for i in len(X_train)] 

        X_b = np.hstack([X_0.T, X_train])
        self._theat = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y_train);

        self.interception_ = self._theat[0]
        self.coef_ = self._theat[1:]

        return self

    def predict(self, X_predict):
        assert self.intercept_ is not None and self.coefficients_ is not None
        assert X_predict.shape[1] == len(self.coefficients_)

        x_0 = 1;
        X_0 = [x_0 for i in len(X_train)] 

        X_b = np.hstack([X_0.T, X_predict])
        return X_b.dot(self._theta)

    def score(self, X_test, y_test):

        y_predict = self.predict(X_test)
        return r2_score(y_test, y_predict)

    def _repr_(self):
        return "LinearRegression()"
