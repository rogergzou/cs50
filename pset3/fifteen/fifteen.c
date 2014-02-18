/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;
int totalNum;
int currentI;
int currentJ;
int tileI;
int tileJ;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    totalNum = d * d;
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    // initializes the board at the very beginning
    

    int daNum = totalNum - 1;
    bool even = true;
    if (d % 2)
    {
        even = false;
    }
    // implement with 1, 2 not switched
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (even && daNum < 3 && daNum > 0)
            {
                board[i][j] = (daNum % 2) + 1;
                daNum -= 1;
            }
            else if (daNum)
            {
                board[i][j] = daNum;
                daNum -= 1;
            }
            
            /*
            else if (daNum == 0)
            {
                board[i][j] = "_";
           
            } */
        }
    }

    

}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] != 0)
            {
                printf("%4d", board[i][j]);
            }
            else
            {
                printf("   _");
            }
        }
        printf("\n");
    
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    bool foundIt = false;
    for (int i = 0; i < d; i++)
    {
        // if(search(tile, board[i][], d))
        for (int j = 0; j < d; j++)
        {
            // if (!(board[i][j] < totalNum && board[i][j] > 0))
            if (board[i][j] == 0)
            {
                // found the "_" character
                currentI = i;
                currentJ = j;
            }
            else if (board[i][j] == tile)
            {
                foundIt = true;
                tileI = i;
                tileJ = j;
            }
        }
        
    }
    if (foundIt)
    {
        int buffer;
        int theIs = abs(currentI - tileI);
        int theJs = abs(currentJ - tileJ);
        if ((theIs + theJs) == 1)
        {
            // checks if tiles are next to each other
            // must be same row 1 diff column or same column 1 diff row
            buffer = board[currentI][currentJ];
            board[currentI][currentJ] = tile;
            board[tileI][tileJ] = buffer;
            return true;
        }
        else
        {
            printf("wtf did you do\n");
            return false;
        }
        
        
        
    }
    else
    {
        printf("Not found\n");
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
 

bool won(void)
{
    int numChecker = 1;
    if (!(currentI == d - 1 && currentJ == d - 1))
    {
        return false;
    }
    else
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (numChecker == totalNum - 1)
                {
                    // skips comparison of "_" b/c others in place
                    printf("You win\n");
                    return true;
                    break;
                }
                else if (board[i][j] == numChecker)
                {
                    numChecker += 1;
                }
            }
        }
    }
    
    if (numChecker == totalNum - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
    fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
