#include "s21_SmartCalc.h"

StackN* createListN() {
  StackN* newSteckN = (StackN*)malloc(sizeof(StackN));
  if (newSteckN == NULL) return NULL;
  newSteckN->head = NULL;
  return newSteckN;
}

void pushVal(StackN* newSteckN, long double val) {
  NodeN* newNode = (NodeN*)malloc(sizeof(NodeN));
  newNode->value = val;
  newNode->nextPtr =
      newSteckN
          ->head;  // Устанавливаем указатель на следующий элемент в новом узле

  newSteckN->head = newNode;  // Обновляем указатель на вершину стека
}

long double popVal(StackN* newSteckN) {
  if (newSteckN->head == NULL)  // Проверяем, не пуст ли стек
    return 0;

  long double value =
      newSteckN->head->value;  // Получаем значение вершины стека
  NodeN* temp = newSteckN->head;  // Удаляем вершину стека
  newSteckN->head = newSteckN->head->nextPtr;
  free(temp);
  return value;
}

bool isEmptyVal(StackN* newSteckN) { return (newSteckN->head == NULL); }

StackO* createListO() {
  StackO* newSteckO = (StackO*)malloc(sizeof(StackO));
  if (newSteckO == NULL) return NULL;
  newSteckO->head = NULL;
  return newSteckO;
}

void pushOper(StackO* newSteckO, char ch) {
  NodeO* newNode = (NodeO*)malloc(sizeof(NodeO));
  newNode->calc_oper = ch;
  newNode->nextPtr =
      newSteckO
          ->head;  // Устанавливаем указатель на следующий элемент в новом узле
  newSteckO->head = newNode;  // Обновляем указатель на вершину стека
}

char popOper(StackO* newSteckO) {
  if (newSteckO->head == NULL) {  // Проверяем, не пуст ли стек

    return 0;
  }
  char ch = newSteckO->head->calc_oper;  // Получаем значение вершины стека
  NodeO* temp = newSteckO->head;  // Удаляем вершину стека
  newSteckO->head = newSteckO->head->nextPtr;
  free(temp);
  return ch;
}

bool isEmptyOper(StackO* newSteckO) { return (newSteckO->head == NULL); }

char peekOper(StackO* newSteckO) {
  // Проверяем, не пуст ли стек
  if (newSteckO->head == NULL) {
    return 0;
  }
  return newSteckO->head->calc_oper;
}

// long double peekVal(StackN* newSteckN) {
//   // Проверяем, не пуст ли стек
//   if (newSteckN->head == NULL) {
//     return 0;
//   }
//   return newSteckN->head->value;
// }

void clearStack(StackN* newSteckN, StackO* newSteckO) {
  while (newSteckN->head != NULL) {  // пока стек не пуст
    NodeN* temp = newSteckN->head;  // сохраняем указатель на верхний узел
    newSteckN->head =
        newSteckN->head
            ->nextPtr;  // верхний узел теперь указывает на следующий узел
    free(temp);  // освобождаем память верхнего узла
  }
  while (newSteckO->head != NULL) {  // пока стек не пуст
    NodeO* temp = newSteckO->head;  // сохраняем указатель на верхний узел
    newSteckO->head =
        newSteckO->head
            ->nextPtr;  // верхний узел теперь указывает на следующий узел
    free(temp);  // освобождаем память верхнего узла
  }
  free(newSteckN);
  free(newSteckO);
}