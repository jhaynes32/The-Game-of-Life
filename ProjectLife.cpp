#include<iostream>

using namespace std;

// function prototypes
void initializeBoard(int board[][10], int n);
int evolve(int board[][10], int n, int row, int col);
void printGeneration(int board[][10], int n);
void copy_board(int board[][10], int new_board[10][10], int n);

int main(){

    int n = 10, row, col, change, num_alive;
    int num_gen;
    int board[10][10], copy[10][10]; //declare 10X10 integer arrays
    
    initializeBoard(board, n);  //

    do{

        cout << "Enter row and columns with one space in between. Use -1 and -1 to end: ";
        cin >> row >> col;

        if(row >= 0 && row < n && col >= 0 && col < n)

                board[row][col] = 1;

    }while(row != -1 && col != -1); 

    cout << "Enter the number of generations: ";
    cin >> num_gen;

    cout <<"Begin Board: " << endl;
    printGeneration(board, n);

    for(int i = 0; i < num_gen; i++){

        change = 0, num_alive = 0;

        for(int row = 0; row < n; row++){

            for(int col = 0; col < n; col++){

                int neighbors = evolve(board, n, row, col);

                if(board[row][col] == 1){

                    if(neighbors < 2 || neighbors > 3){
                     
                        copy[row][col] = 0;
                    }
                    else{
                        copy[row][col] = 1;
                    }

                }else{

                    if (neighbors == 3){

                        copy[row][col] = 1;
                    }
                    else{

                        copy[row][col] = 0;
                    }
                }
                if(board[row][col] != copy[row][col]){

                    change++;
                } 
                if(copy[row][col] == 1){

                    num_alive++;
                }
            }
        }
        copy_board(copy, board, n);
        cout << "\nGeneration: " <<(i + 1) << endl;

        printGeneration(board, n);
        if(change == 0 || num_alive == 0){
        break;
        }
    }
    return 0;
}


// initialize board matrix to zero
void initializeBoard(int board[][10], int n){

    for(int i = 0; i < n; i++){

        {
            for(int j = 0; j < n; j++){

                board[i][j] = 0;
            }
        }
    }
}


int evolve(int grid[][10], int n, int row, int col){

    if(row == 0){
        
        if(col == 0){

            return(grid[row][col + 1] + grid[row + 1][col + 1]);
        }
        else if(col == n - 1){

            return(grid[row][col - 1] + grid[row + 1][col - 1] + grid[row + 1][col]);
        }
        else
            return(grid[row][col - 1] + grid[row + 1][col - 1] + grid[row + 1][col] + grid[row + 1][col + 1] + grid[row][col + 1]);
    
    }else if(row == n - 1){

        if(col == 0){
            
            return(grid[row][col + 1] + grid[row - 1][col] + grid[row - 1][col + 1]);

        }
        else if(col == n - 1){

            return(grid[row][col - 1] + grid[row - 1][col - 1] + grid[row - 1][col]);

        }
        else{

            return(grid[row][col - 1] + grid[row - 1][col - 1] + grid[row - 1][col] + grid[row - 1][col + 1] + grid[row][col + 1]);
        }

    }else if(col == 0){

        return(grid[row - 1][col] + grid[row - 1][col + 1] + grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 1][col]);
    
    }else if(col == n-1){

        return(grid[row - 1][col] + grid[row - 1][col - 1] + grid[row][col - 1] + grid[row + 1][col - 1] + grid[row + 1][col]);
    
    }else{

        return(grid[row - 1][col - 1] + grid[row - 1][col] + grid[row - 1][col + 1] + grid[row][col - 1] + grid[row][col + 1] + grid[row + 1][col - 1] + grid[row + 1][col] + grid[row + 1][col + 1]);
    }  

}

void printGeneration(int board[][10], int n){

    for( int i = 0; i < n; i++){

        cout << endl;

        for(int j = 0; j < n; j++){

            if(board[i][j] == 1){

                cout << "X ";
            }
            else{

                cout << "- ";
            }
        }
    }
}

void copy_board(int board[][10], int new_board[][10], int n){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            new_board[i][j] = board[i][j];
        }
    }
}


/*
Output:

Enter row and column with one space in between. Use -1 and -1 to end: 1 1 
Enter row and column with one space in between. Use -1 and -1 to end: 2 2
Enter row and column with one space in between. Use -1 and -1 to end: 3 3
Enter row and column with one space in between. Use -1 and -1 to end: 4 4
Enter row and column with one space in between. Use -1 and -1 to end: 5 5
Enter row and column with one space in between. Use -1 and -1 to end: 6 6
Enter row and column with one space in between. Use -1 and -1 to end: 7 7
Enter row and column with one space in between. Use -1 and -1 to end: 8 8
Enter row and column with one space in between. Use -1 and -1 to end: 1 8
Enter row and column with one space in between. Use -1 and -1 to end: 2 7
Enter row and column with one space in between. Use -1 and -1 to end: 3 6
Enter row and column with one space in between. Use -1 and -1 to end: 4 5
Enter row and column with one space in between. Use -1 and -1 to end: 5 4
Enter row and column with one space in between. Use -1 and -1 to end: 6 3
Enter row and column with one space in between. Use -1 and -1 to end: 7 2
Enter row and column with one space in between. Use -1 and -1 to end: 8 1
Enter row and column with one space in between. Use -1 and -1 to end: -1 -1
Enter the number of generations: 10
Begin Board: 

- - - - - - - - - - 
- X - - - - - - X - 
- - X - - - - X - - 
- - - X - - X - - - 
- - - - X X - - - - 
- - - - X X - - - - 
- - - X - - X - - - 
- - X - - - - X - - 
- X - - - - - - X - 
- - - - - - - - - - 
Generation: 1

- - - - - - - - - - 
- - - - - - - - - - 
- - X - - - - X - - 
- - - X X X X - - - 
- - - X - - X - - - 
- - - X - - X - - - 
- - - X X X X - - - 
- - X - - - - X - - 
- - - - - - - - - - 
- - - - - - - - - - 
Generation: 2

- - - - - - - - - - 
- - - - - - - - - - 
- - - X X X X - - - 
- - X X X X X X - - 
- - X X - - X X - - 
- - X X - - X X - - 
- - X X X X X X - - 
- - - X X X X - - - 
- - - - - - - - - - 
- - - - - - - - - - 
Generation: 3

- - - - - - - - - - 
- - - - X X - - - - 
- - X - - - - X - - 
- - - - - - - - - - 
- X - - - - - - X - 
- X - - - - - - X - 
- - - - - - - - - - 
- - X - - - - X - - 
- - - - X X - - - - 
- - - - - - - - - - 
Generation: 4

*/ 
