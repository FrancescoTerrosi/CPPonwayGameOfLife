#include <GL/glut.h>
#include <iostream>
#include "boardgui.h"
#include "../game/game.h"

float X_COORDINATE = 0;
float Y_COORDINATE = 0;
int MOUSE_CLICKS = 0;
bool GAME_OVER = false;

int POPULATION;
int BORDER_LENGTH;
int BOARD_SIZE;

int* BOARD;

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    float x_border = 1.0-(1.0/width);
    float y_border = 1.0-(1.0/height);
    float x_center = 0+(1.0/width);
    float y_center = 0-(1.0/height);

    float grid_unit = 2.0/(float)BORDER_LENGTH;
    int current_element = 0;
    float current_x = 0;
    float current_y = 0;

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        //LEFT BORDER
        glVertex2f(-x_border,y_border);
        glVertex2f(-x_border,-y_border);

        //BOTTOM BORDER
        glVertex2f(-x_border,-y_border);
        glVertex2f(x_border,-y_border);

        //RIGHT BORDER
        glVertex2f(x_border,-y_border);
        glVertex2f(x_border,y_border);

        //TOP BORDER
        glVertex2f(x_border,y_border);
        glVertex2f(-x_border,y_border);

        float w_step = 2.0/(float)BORDER_LENGTH;
        float current_col = -1.0+w_step;
        while (current_col < x_border) {
            glVertex2f(current_col, 1);
            glVertex2f(current_col, -1);
            current_col += w_step;
        }

        float h_step = 2.0/(float)BORDER_LENGTH;
        float current_row = -1.0+h_step;
        while (current_row < y_border) {
            glVertex2f(1, current_row);
            glVertex2f(-1, current_row);
            current_row += h_step;
        }

    glEnd();


    //TOP LEFT CELL
    current_x = -x_border;
    current_y = y_border;

    glBegin(GL_TRIANGLES);
        while (current_element < BOARD_SIZE) {
            if (BOARD[current_element] == 1) {
                glVertex2f(current_x, current_y);
                glVertex2f(current_x, current_y-h_step);
                glVertex2f(current_x+w_step, current_y);

                glVertex2f(current_x, current_y-h_step);
                glVertex2f(current_x+w_step, current_y-h_step);
                glVertex2f(current_x+w_step, current_y);
            }
            current_x += w_step;
            if (current_x >= x_border) {
                current_x = -x_border;
                current_y -= h_step;
            }
            current_element++;
        }

    glEnd();

    glFlush();          //Finish rendering
}

void Reshape(int w, int h)
{
    if (h == 0 || w == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,w,h);  //Use the whole window for rendering
    //glViewport(w/4.0, h/5.0, w*0.5, h*0.6);  //Use the whole window for rendering
}

void GameLoop(int value)
{
    handleLoop(BOARD, BOARD_SIZE, BORDER_LENGTH);
    GAME_OVER = checkGameOver(BOARD, BOARD_SIZE);
    glutPostRedisplay();
    glutTimerFunc(value, GameLoop, value);
}

void MouseClick(int button, int state, int x, int y)
{
    if (button == 2) {
        MOUSE_CLICKS = 0;
    }
    else if (button == 0 && state == 0 && (GAME_OVER || MOUSE_CLICKS == 2)) {
        srand(time(0));
        for (int i = 0; i < BOARD_SIZE; i++) {
            BOARD[i] = rand()%2;
        }
        MOUSE_CLICKS = 0;
    } else if (button == 0 && state == 0) {
        MOUSE_CLICKS++;
    }
}

void initGame (int argc, char **argv, int population, int timestep)
{
    POPULATION = population;
    BORDER_LENGTH = population;
    BOARD_SIZE = BORDER_LENGTH*BORDER_LENGTH;
    BOARD = new int[BOARD_SIZE];
    timestep = timestep == 0 ? 500 : timestep;

    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    glutInitWindowPosition(0, 0);

    //Create a window with rendering context and everything else we need
    glutCreateWindow("Conway");
    glClearColor(255.0,255.0,255.0,0.0);

    //Assign the two used Msg-routines
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutTimerFunc(0, GameLoop, timestep);
    glutMouseFunc(MouseClick);

    srand(time(0));
    for (int i = 0; i < BOARD_SIZE; i++) {
        BOARD[i] = rand()%2;
    }

    //Let GLUT get the msgs
    glutMainLoop();
}

