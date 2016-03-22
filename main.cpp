/*
 * algo_tp_2/main.cpp
 *
 *   Created on: Mar 22, 2016
 *       Author: Dmitry Ermachenkov
 *      License: free-to-use if you refernce me
 *  Description: ​Вычислить площадь выпуклого n­угольника, заданного координатами своих вершин. Вначале вводится
 количество вершин, затем последовательно целочисленные координаты всех вершин в порядке обхода
 против часовой стрелки. n < 1000, координаты < 10000.
 Указание. Для вычисления площади n­угольника можно посчитать сумму ориентированных площадей
 трапеций под каждой стороной многоугольника.
 */

#include <iostream>

using std::cout;
using std::cin;

double orientedSquare(double x1, double y1, double x2, double y2);
double squarePolygon(int pointQuantity);

int main(void) {
  int pointQuantity = 0;
  cin >> pointQuantity;
  cout << squarePolygon(pointQuantity);
  return 0;
}

double squarePolygon(int pointQuantity) {
  double x1,y1,x2,y2,integralSquare = 0;
  cin >> x1 >> y1;
  for (int i = 1; i < pointQuantity; ++i) {
    cin >> x2 >> y2;
    integralSquare += orientedSquare(x1,y1,x2,y2);
    x1 = x2;
    y1 = y2;
  }
  return integralSquare;
}

double orientedSquare(double x1, double y1, double x2, double y2) {
  return 0.5*(x2-x1)*(y1+y2);
}
