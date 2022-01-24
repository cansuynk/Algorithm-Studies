/******************************************************************************
Backtracking Algorithms
Problem is solved an incremental way
Problem is solved recursively by trying to build a solution incrementally
Time Complexity: O(m^V). 
Space Complexity: O(V). 
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

#define V 5
#define M 4
#define N 4
#define S 9

void print_ham(int path[])
{

    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
 
    cout << path[0] << " ";
    cout << endl;
}

bool isSafe(int v, bool graph[V][V], int path[], int size)
{
    
    //check if previous vertex is adjacent of current vertex
    if (graph [path[size - 1]][v] == 0)
        return false;
    
    //check if the vertex has already been included.
    for (int i = 0; i < size; i++)
        if (path[i] == v)
            return false;
 
    return true;
}

//Hamiltonian Cycle 
/*in an undirected graph is a path that visits each vertex exactly once. 
Hamiltonian Path from the last vertex to the first vertex of the Hamiltonian Path*/
bool hamCycleRec(bool graph[V][V], int path[], int size)
{

    if (size == V)   //if reaches to last vertex
    {

        if (graph[path[size - 1]][path[0]] == 1) //if there is an edge between vertices
            return true;
        else
            return false;
    }
 
    for (int v = 1; v < V; v++)  //traverse all vertices
    {
        if (isSafe(v, graph, path, size))
        {
            path[size] = v;
 
            if (hamCycleRec (graph, path, size + 1) == true)
                return true;
                
            path[size] = -1;
        }
    }
 
    return false;
}

bool hamCycle(bool graph[V][V])
{
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
 
    path[0] = 0;
    if (hamCycleRec(graph, path, 1) == false )
    {
        cout << "Solution does not exist." << endl;
        return false;
    }
 
    print_ham(path);
    return true;
}

//m Coloring Problem
//There is a total O(m^V) combination of colors. So the time complexity is O(m^V).
void print_m(int color[])
{
    for (int i = 0; i < M; i++)
        cout << color[i] <<" ";
    cout << "\n";
}

bool isSafe_m(bool graph[M][M], int color[])
{
    // check for every edge
    for (int i = 0; i < M; i++)
        for (int j = i + 1; j < M; j++)
            //if they are adjacent and their colors are same
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}
 

bool graphColoring(bool graph[M][M], int m, int i, int color[M])
{
    // if current index reached end
    if (i == M) {
       
        // if coloring is safe
        if (isSafe_m(graph, color)) {
            print_m(color);
            return true;
        }
        return false;
    }
 
    // Assign each color from 1 to m
    for (int j = 1; j <= m; j++) { //number of colors
        color[i] = j;
 
        if (graphColoring(graph, m, i + 1, color))
            return true;
 
        color[i] = 0;
    }
 
    return false;
}

bool m_coloring(bool graph[M][M], int m){

    int color[M];
    for (int i = 0; i < M; i++)
        color[i] = 0;
 
    if (!graphColoring(graph, m, 0, color))
        cout << "Solution does not exist" <<endl;
        return false;
        
    print_m(color);
    return true;
    
}

//N Queen Problem
void print_n(int board[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}


bool isSafe_n(int board[N][N], int row, int col){
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i]) //if filled
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col){
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe_n(board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;
                
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

bool solveNQ(){
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }

    print_n(board);
    return true;
}

//rat in a maze
void print_r(int sol[N][N]){
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}
 

bool isSafe_r(int maze[N][N], int x, int y){
    
    // if outside maze and there is a way(no obstacles)
    if ( x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
 
    return false;
}

bool solveMazeUtil( int maze[N][N], int x, int y, int sol[N][N]){
    // if reaches the target
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
 
    // Check if maze[x][y] is valid
    if (isSafe_r(maze, x, y) == true) {
        
        if (sol[x][y] == 1)
            return false;
       
        sol[x][y] = 1;
 
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;
 
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;
       
        sol[x][y] = 0;
        return false;
    }
 
    return false;
}
bool solveMaze(int maze[N][N]){
    
    int sol[N][N] = {{ 0, 0, 0, 0},
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 }};
 
    if (solveMazeUtil(maze, 0, 0, sol) == false) {
        cout << "Solution doesn't exist" <<endl;
        return false;
    }
 
    print_r(sol);
    return true;
}

//permutate string
vector<string>ans;
void permute(string a, int l, int r){
    if (l == r)
        ans.push_back(a);
    else{
        // Permutations made
        for (int i = l; i <= r; i++){
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);  //backtrack
        }
    }
}

void permutate_str(string a){
    
    permute(a, 0, a.size()-1);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] <<endl;
    }
    cout << endl;
}

//fill sudoku
void print_s(int arr[S][S]){
    for (int i = 0; i < S; i++)    {
        for (int j = 0; j < S; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
 
bool isSafe(int grid[S][S], int row, int col, int num){
     
    // Check if same num in similar row
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
 
    // Check if find same num in similar column
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
 
    // Check if find the same num in inner 3*3 matrix,
    int startRow = row - row % 3;
    int startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;
 
    return true;
}
 
bool solveSudoku(int grid[S][S], int row, int col){

    if (row == S - 1 && col == S)
        return true;
 
    // Check if column value becomes 9 ,
    // move to next row and
    //  column start from 0
    if (col == S) {
        row++;
        col = 0;
    }
   
    // check if the grid already contains value >0, go next column
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);
 
    for (int num = 1; num <= S; num++){
        
        if (isSafe(grid, row, col, num)){
             
            grid[row][col] = num;
            
            if (solveSudoku(grid, row, col + 1))
                return true;
        }

        grid[row][col] = 0;
    }
    return false;
}

void sudoku(int grid[S][S]){
    if (solveSudoku(grid, 0, 0))
        print_s(grid);
    else
        cout << "no solution  exists" << endl;
}
 
int main(){
    
    //hamiltonian cycle
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
     
    
    hamCycle(graph1);
    
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
 

    hamCycle(graph2);
    
    
    //m_coloring
    bool graph3[M][M] = {{ 0, 1, 1, 1 },
                         { 1, 0, 1, 0 },
                         { 1, 1, 0, 1 },
                         { 1, 0, 1, 0 }};
                         
    int m = 3; // Number of colors
    
    m_coloring(graph3, m);
    
    //n_queen
    solveNQ();
    
    //rat in a maze
    int maze[N][N] = {{ 1, 0, 0, 0 },
                      { 1, 1, 0, 1 },
                      { 0, 1, 0, 0 },
                      { 1, 1, 1, 1 }};
 
    solveMaze(maze);
    
    
    //permute string
    string str = "ABC";
    permutate_str(str);
    
    
    //fill sudoku
    // 0 means unassigned cells
    int grid[S][S] = {{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                      { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                      { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                      { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                      { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                      { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                      { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                      { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                      { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};
                     
    sudoku(grid);
    
    
    return 0;
}
