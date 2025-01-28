#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node **adjLists;
    int *visited;
};

struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    if (!graph->adjLists[src] || graph->adjLists[src]->vertex > dest)
    {
        newNode->next = graph->adjLists[src];
        graph->adjLists[src] = newNode;
    }
    else
    {
        struct Node *temp = graph->adjLists[src];
        while (temp->next && temp->next->vertex < dest)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    newNode = createNode(src);
    if (!graph->adjLists[dest] || graph->adjLists[dest]->vertex > src)
    {
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
    else
    {
        struct Node *temp = graph->adjLists[dest];
        while (temp->next && temp->next->vertex < src)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void bfs(struct Graph *graph, int startVertex)
{
    int queue[100], front = 0, rear = 0;

    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex])
            {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void dfs(struct Graph *graph, int vertex)
{
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->adjLists[vertex];
    while (temp)
    {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex])
        {
            dfs(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int vertices, edges, src, dest, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source and destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);

    for (int i = 0; i < vertices; i++)
    {
        graph->visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(graph, startVertex);
    printf("\n");

    return 0;
}
