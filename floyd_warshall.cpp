// Floyd-Warshall Algorithm in C++

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// defining the number of vertices
#define nV 5

#define INF 999

void printMatrix(int matrix[][nV]);

int d_matrix[nV][nV];

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV])
{
    int matrix[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    // Adding vertices individually
    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            d_matrix[i][j] = matrix[i][j];
    printMatrix(d_matrix);
}

void printMatrix(int matrix[][nV])
{
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph2[nV][nV] = {
        {0, 4, 1, 5, 10},
        {4, 0, 10, INF, 3},
        {INF, 10, 0, 3, INF},
        {5, INF, 3, 0, 10},
        {1, 3, INF, 10, 0}};

    floydWarshall(graph2);
    vector<int> list = {5, 3, 2};
    vector<int> path = {};
    int min = INF;
    int minIndex = 1;
    int next = 0;
    int ut = 0;
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (d_matrix[next][j] != 0 && count(list.begin(), list.end(), j + 1) && !count(path.begin(), path.end(), j + 1) && d_matrix[next][j] < min)
            {
                min = d_matrix[next][j];
                minIndex = j;
            }
        }
        ut += min;
        min = INF;
        next = minIndex;
        path.push_back(minIndex + 1);
    }

    cout << ut << endl;

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << endl;
    }
}