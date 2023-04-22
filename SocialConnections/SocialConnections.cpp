#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "rus");

    Graph g;

    g.addVertex(0, "Настя");
    g.addVertex(1, "Ваня");
    g.addVertex(2, "Олег");
    g.addVertex(3, "Катя");
    g.addVertex(4, "Стас");
    g.addVertex(5, "Игорь");
    g.addVertex(6, "Никита");
    g.addVertex(7, "Саня");
    g.addVertex(8, "Женя");
    g.addVertex(9, "Алекс");

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(2, 8, 1);
    g.addEdge(3, 6, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(4, 9, 1);

    g.findMinDistancesFloyd();
    //g.findMinDistancesFloyd(7);
}