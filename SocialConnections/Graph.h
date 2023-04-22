#pragma once
#define SIZE 10
#define VERYBIGINT 1000000000 // очень большое число

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class Graph {
public:
    struct Node { // структура узла
        Node(int _numVertex, string _name) : numVertex(_numVertex), name(_name) { };
        int numVertex; // номер вершины
        string name; // Даные, в нашем случае Имя
    };

    Graph();
    // добавление вершины
    void addVertex(int vnumber, string name);
    // добавление ребра
    void addEdge(int v1, int v2, int weight);
    // удаление вершины
    void delVertex(int vnumber);
    // удаление ребра
    void delEdge(int v1, int v2);

    // Алгоритм Флойда-Уоршелла
    // vnumder - указывает на конкретную вершину графа для вывода примера, в случае если она не указана будет выведен первый элемент граффа!
    void findMinDistancesFloyd(int vnumder = -1);
    void degreeOfSocialConnection(int vnumber, int** weights);

private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);

    int matrix[SIZE][SIZE]; // матрица смежности // матрица смежности

    vector<Node> vertexes; // хранилище вершин
};