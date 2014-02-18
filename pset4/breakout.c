//
// breakout.c
//
// Computer Science 50
// Problem Set 4
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

#define BLOCK_WIDTH 36
#define BLOCK_HEIGHT 10
#define W_PADDING 2
#define H_PADDING 1
#define PADDLE_WIDTH 40
#define PADDLE_HEIGHT 4
#define BOTTOM_BUFFER 50

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

GRect brickz[ROWS][COLS];

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(int argc, string argv[])
{
    bool god = false;
    if (argc == 2 && (strcmp(argv[1], "GOD") == 0))
    {
        god = true;
    } 
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // velocity of ball
    double x_velocity = 2 * (drand48() + 1);
    double y_velocity = 2 * (drand48() + 1);
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // regular non god mode play
        if (!god)
        {
            GEvent event = getNextEvent(MOUSE_EVENT);

            // if we heard one
            if (event != NULL)
            {
                // if the event was movement
                if (getEventType(event) == MOUSE_MOVED)
                {
                    // ensure paddle follows the x of the mouse
                    double x = getX(event) - getWidth(paddle) / 2;
                    double y = getY(paddle);
                    setLocation(paddle, x, y);
                }
            }
        }
        // god mode, set as X of ball
        else if (god)
        {
            double x = getX(ball);
            double y = getY(paddle);
            setLocation(paddle, x, y);
                
        }
        
        
        // Ball moves
        // move circle along x-axis
        move(ball, x_velocity, y_velocity);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            x_velocity *= -1;
        }

        // bounce off left edge of window
        else if (getX(ball) <= 0)
        {
            x_velocity *= -1;
        }
        
        
        if (getY(ball) + getHeight(ball) >= getHeight(window))
        {
            
            lives -= 1;
            points -= 1;
            removeGWindow(window, ball);
            ball = initBall(window);
            waitForClick();
        }

        // bounce off top edge of window
        
        
        else if (getY(ball) < 0)
        {
            y_velocity *= -1;
            
        }
        // goes off bottom edge of window
        
        
        
        GObject object = detectCollision(window, ball);
            // sees if any collisions
        if (object != NULL)
        {
            // avoids segmentation errors
            const char *daType = getType(object);
            int daMatch = strcmp(daType, "GRect");
            // if hit paddle, bounce
            if (object == paddle)
            {
                y_velocity *= -1;
            
            }
            else if (daMatch == 0)
            {
                // ran into the bricks
                for (int i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < COLS; j++)
                    {
                        if (object == brickz[i][j])
                        {
                            /** leftover code
                            int daWidth = getWidth(brickz[i][j]);
                            int daX = getX(brickz[i][j]);
                            int daHeight = getHeight(brickz[i][j]);
                            int daY = getY(brickz[i][j]);
                            int collisionX = getX(ball) + RADIUS / 2;
                        //if (collisionX >= daX && collisionX <= daX + daWidth)
                        //{
                            //if (getY(ball) == daY + daHeight)
                            //{
                            */
                            y_velocity *= -1;
                            bricks -= 1;
                            points += 50 / (i + 1) + 30 / (bricks + 1);
                            removeGWindow(window,  brickz[i][j]);
                            // changes direction, subtracts bricks by 1
                            // increases points depending on row of brick
                            // and depending on how many bricks left
                            // removes away the bricks
                          // }
                        // }
                        }
                    }
                }
                // y_velocity *= -1;
            
            }
            /*
            else if (strcmp(getType(object), "GLabel") == 0)
            {
                // do nothing
            }
            */
        }    
        /*
        char s[8];
        sprintf(s, "%i", points);
        setLabel(label, s);
        */
        updateScoreboard(window, label, points);
        // updates scoreboard
        // linger before moving again
        pause(10);
    }
    /** useless leftover code
    string overmessage = "Game Over. Click to Close";
    char g[100];
    sprintf(g, "%s", overmessage);
    setLabel(label, g);
    */
    // wait for click before exiting
    waitForClick();
    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    string colors;
    for (int i = 0; i < ROWS; i++)
    {
        
        switch (i)
        {
            case 0 :
                colors = "ORANGE";
                break;
            case 1 :
                colors = "ORANGE";
                break;
            case 2 :
                colors = "YELLOW";
                break;
            case 3 :
                colors = "YELLOW";
                break;
            case 4 :
                colors = "GREEN";
                break;
            default :
                colors = "BLACK";
                break;
        }
        // sets different colors for each row
        
        
        
        for (int j = 0; j < COLS; j++)
        {
            int x = (BLOCK_WIDTH + 2 * W_PADDING) * j + W_PADDING;
            int y = (BLOCK_HEIGHT + 2 * H_PADDING) * i + H_PADDING;
            brickz[i][j] = newGRect(x, y, BLOCK_WIDTH, BLOCK_HEIGHT);
            // creates a new brick with location x, y
            setColor(brickz[i][j], colors);
            setFilled(brickz[i][j], true);
            // adds color to each brick
            add(window, brickz[i][j]);
            // adds brick to window
        }
    
    }
    
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    int x = WIDTH / 2 - RADIUS;
    int y = HEIGHT / 2 - RADIUS;
    GOval daBall = newGOval(x, y, RADIUS * 2, RADIUS * 2);
    setColor(daBall, "BLACK");
    setFilled(daBall, true);
    
    if (daBall)
    {
        add(window, daBall);
        return daBall;
    }
    else
    {
        return NULL;
    }
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    double padWid = WIDTH / 2 - PADDLE_WIDTH / 2;
    double padHei = HEIGHT - PADDLE_HEIGHT - BOTTOM_BUFFER;
    GRect daPad;
    daPad = newGRect(padWid, padHei, PADDLE_WIDTH, PADDLE_HEIGHT);
    // setActionCommand(daPad, "move");
    setColor(daPad, "BLACK");
    setFilled(daPad, true);
    if (daPad)
    {
        add(window, daPad);
        
        return daPad;
    }
    else
    {
        printf("This is the error");
        return NULL;
    }
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-36");
    add(window, label);
    double x = (getWidth(window) / 2) - getWidth(label) / 2;
    double y = (getHeight(window) / 2) - getHeight(label) / 2;
    setLocation(label, x, y);
    if (label)
    {
        return label;
    }
    else
    {
        return NULL;
    }
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
