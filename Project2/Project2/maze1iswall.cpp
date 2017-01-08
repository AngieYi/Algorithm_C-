#include <Queue>
#include <Iostream>
using namespace std;

//#define ROW 9
//#define COL 10

#define ROW 3
#define COL 3

struct Point
{
	int x;
	int y;
};

struct queueNode
{
	Point pt;  
	int dist;
};

bool isValid(int row, int col)
{
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}


int BFS(int mat[][COL], Point src, Point dest)
{
	if (mat[src.x][src.y] || mat[dest.x][dest.y])
		return -1;							// if src or dest is wall,then return -1

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited); // set all visited array value default to false
	visited[src.x][src.y] = true;			// source is visited

	queue<queueNode> q;						// define a queue, each element is a struct
	queueNode sNode = { src, 0 };			// source node 
	q.push(sNode);							// push source node to queue

	int rowNum[] = { -1, 0, 0, 1 };			// up,left,right,down
	int colNum[] = { 0, -1, 1, 0 };

	while (!q.empty())
	{
		queueNode curr = q.front();			// current is always the first element in the queue
		
		Point pt = curr.pt;					// if curr point is the destination then return distance
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;

		q.pop();							// pop current point and push all its adj node into queue

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];

			if (isValid(row, col) && !mat[row][col] && !visited[row][col]) // if within maze, value is 0, not been visited
			{
				visited[row][col] = true;
				queueNode AdjNode = { { row, col }, curr.dist + 1 };
				q.push(AdjNode);	// set to be visited and push into queue
			}
		}
	}

	return -1;		// if could not escape,return -1
}

int main()
{
	/*
	int mat[ROW][COL] =
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	};
	*/

	int mat[ROW][COL] =
	{
		{ 0, 1, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 0 },
	};

	Point source = { 0, 0 };
	Point dest = { 1, 2 };

	int dist = BFS(mat, source, dest);

	if (dist != -1)
		cout << "Shortest Path is " << dist;
	else
		cout << "Shortest Path doesn't exist";

	return 0;
}