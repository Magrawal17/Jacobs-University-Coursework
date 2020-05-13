#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

class PuzzleBoard
{
private:
    int **graph;
    int graphsize;
    int cuurentY;
    int currentX;

public:
    PuzzleBoard(int boardSize, int **fields = nullptr);
    bool makeMove(int direction);
    bool getResult();
    friend ostream &operator<<(ostream &os, PuzzleBoard const &m);
    int solve();
    ~PuzzleBoard();
};

PuzzleBoard::PuzzleBoard(int boardSize, int **fields)
{
    currentX = 0;
    cuurentY = 0;
    graphsize = boardSize * boardSize;

    graph = new int *[graphsize];
    for (int i = 0; i < graphsize; i++)
    {
        graph[i] = new int[graphsize];
    }
    
    srand(time(0));
    if (fields == NULL)
    {
        fields = new int *[boardSize];
        for (int i = 0; i < boardSize; i++)
        {
            fields[i] = new int[boardSize];
        }
    }

    cout<<"Your Maze looks like this"<<endl;
    for (int i = 0; i < boardSize; i++)
    {
    
        for (int j = 0; j < boardSize; j++)
        {
            fields[i][j] = (rand() % boardSize - 1) + 1;
            cout<<fields[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    for (int i = 0; i < graphsize; i++)
    {
        for (int j = 0; j < graphsize; j++)
        {
            graph[i][j] = 0;
        }
    }

    //Creating a type of Adjacency Matrix
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            int value = fields[i][j];
            if (i - value > 0)
            {
                int x = i * boardSize + j; //Wouldnt require a 2d matrix this way
                int y = (i - value) * boardSize + j;
                graph[x][y]= 1;
            }

            if (j - value > 0)
            {
                int x = i * boardSize + j;
                int y = i * boardSize + (j - value);
                graph[x][y] = 1;
            }

            if (i + value < boardSize)
            {
                int x = i * boardSize + j;
                int y = (i + value) * boardSize + j;
                graph[x][y] = 1;
            }

            if (j + value < boardSize)
            {
                int x = i * boardSize + j;
                int y = i * boardSize + (j + value);
                graph[x][y] = 1;
            }
        }
    }
}

PuzzleBoard::~PuzzleBoard()
{
    for (int i = 0; i < graphsize; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}

bool PuzzleBoard::getResult()
{
    if (solve()==-1)
    {
        cout<<"Not Solvable"<<endl;
        return false;
    }
    else
    {
        cout<<"Minimum Number of steps taken to solve the maze is  "<<solve()<<endl;
        return true;
    }
}

ostream &operator<<(ostream &os, PuzzleBoard const &m)
{
    for (int i = 0; i < m.graphsize; i++)
    {
        for (int j = 0; j < m.graphsize; j++)
        {
            os << m.graph[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int PuzzleBoard::solve()
{
    int dist[graphsize];
    for (int i = 0; i < graphsize; i++)
    {
        dist[i] = INF;
    }
    int start = 0;
    dist[start] = 0;

    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        for (int i = 0; i < graphsize; i++)
        {
            int weight = graph[node][i];
            if ((dist[i] > dist[node] + weight) && (weight != 0))
            {
                dist[i] = dist[node] + weight;
                pq.push(make_pair(dist[i], i));
            }
        }
    }

    if (dist[graphsize - 1] == INF)
    {
        return -1;
    }
    else
    {
        return dist[graphsize - 1];  
    }
}

bool PuzzleBoard::makeMove(int direction)
{
    int i = currentX;
    int j = cuurentY;
    int value = graph[i][j];
    if (direction == 0)
    {
        if (i - value > 0)
        {
            currentX = i - value;
            return true;
        }
    }
    else if (direction == 1)
    {
        if (j + value < graphsize)
        {
            cuurentY = j + value;
            return true;
        }
    }
    else if (direction == 2)
    {
        if (i + value < graphsize)
        {
            currentX = i + value;
            return true;
        }
    }
    else if (direction == 3)
    {
        if (j - value > 0)
        {
            cuurentY = j - value;
            return true;
        }
    }
    return false;
    
}

int main()
{
    int **fields = NULL;
    int n;
    cout << "Welcome to the Puzzle Game" << endl;
    cout<<"Enter the size"<<endl;
    cin >> n;
    PuzzleBoard puzzle(n, fields);
  
    cout<<"A type of Adjacency graph of the maze"<<endl;        
    cout << puzzle << endl;
    puzzle.getResult();
    return 0;
}