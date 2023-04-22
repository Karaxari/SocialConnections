#include "Graph.h"

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
}
// добавление вершины
void Graph::addVertex(int vnumber, string name)
{
    Node node(vnumber, name);
    vertexes.push_back(node);
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// проверка существования вершины
bool Graph::vertexExists(int v)
{
    for (int i = 0; i < vertexes.size(); i++)
        if (vertexes[i].numVertex == v)
            return true;
    return false;
}

void Graph::delVertex(int vnumber)
{
    // обнуляем столбец и строку матрицы
    for (int i = 0; i < vertexes.size(); i++)
    {
        matrix[i][vnumber] = 0;
        matrix[vnumber][i] = 0;
    }
    // удаляем вершину из списка вершин
    int foundIndex = -1;
    for (int i = 0; i < vertexes.size(); i++)
    {
        if (vertexes[i].numVertex == vnumber)
            vertexes.erase(vertexes.begin() + i);
    }
}

void Graph::delEdge(int v1, int v2)
{
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

void Graph::findMinDistancesFloyd(int vnumder)
{
    int size = vertexes.size();
    int** weights = new int* [size]; // матрица путей
    for (int i = 0; i < size; i++)
        weights[i] = new int[size];

    // инициализаци матрицы
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // путь до самой себя равен 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                }
                else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }

    for (int k = 0; k < size; k++) // итерации по k
    {
        int ck = vertexes[k].numVertex; // возьмем номер вершины
        for (int i = 0; i < size; i++)
        {
            if (i == k)
                continue;
            int ci = vertexes[i].numVertex;
            for (int j = 0; j < size; j++)
            {
                if (j == k)
                    continue;
                int cj = vertexes[j].numVertex;
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет мматрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    std::cout << "  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << "\t" << "V" << i;
    }
    std::cout << '\n';

    for (int i = 0; i < size; i++)
    {
        std::cout << "V" << i;
        for (int j = 0; j < size; j++) {
            std::cout << "\t" << weights[i][j];
        }
        std::cout << '\n';
    }

    if (vnumder > -1 && vnumder < size)
        degreeOfSocialConnection(vnumder, weights);
    else
        degreeOfSocialConnection(0, weights);

    srand(time(0));
    degreeOfSocialConnection((1 + rand() % (size - 1)), weights);

    for (int i = 0; i < size; i++) {
        delete[] weights[i];
    }
    delete[] weights;
}

void Graph::degreeOfSocialConnection(int vnumber, int** weights)
{
    std::cout << "\nСтеперь соцальной связи V" << vertexes[vnumber].numVertex << " - " << vertexes[vnumber].name << " : \n";
    int max = 0;
    for (int i = 0; i < vertexes.size(); i++) {
        if (weights[vnumber][i] > max)
            max = weights[vnumber][i];
    }

    for (int i = 1; i <= max; i++) {
        std::cout << "Круг общения " << i << ": ";
        for (int k = 0; k < vertexes.size(); k++) {
            if (i == weights[vnumber][k]) {
                std::cout << "V" << vertexes[k].numVertex << "-" << vertexes[k].name << ", ";
            }
        }
        std::cout << '\n';
    }
}