#pragma once
#define SIZE 10
#define VERYBIGINT 1000000000 // ����� ������� �����

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class Graph {
public:
    struct Node { // ��������� ����
        Node(int _numVertex, string _name) : numVertex(_numVertex), name(_name) { };
        int numVertex; // ����� �������
        string name; // �����, � ����� ������ ���
    };

    Graph();
    // ���������� �������
    void addVertex(int vnumber, string name);
    // ���������� �����
    void addEdge(int v1, int v2, int weight);
    // �������� �������
    void delVertex(int vnumber);
    // �������� �����
    void delEdge(int v1, int v2);

    // �������� ������-��������
    // vnumder - ��������� �� ���������� ������� ����� ��� ������ �������, � ������ ���� ��� �� ������� ����� ������� ������ ������� ������!
    void findMinDistancesFloyd(int vnumder = -1);
    void degreeOfSocialConnection(int vnumber, int** weights);

private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);

    int matrix[SIZE][SIZE]; // ������� ��������� // ������� ���������

    vector<Node> vertexes; // ��������� ������
};