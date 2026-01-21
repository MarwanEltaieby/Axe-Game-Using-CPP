#include "raylib.h"

int main()
{
    // Canvas Window Attributes
    int width = 1080;
    int length = 720;
    InitWindow(width, length, "My Game");

    // Circle Variables
    // Circle Attributes
    float circle_radius = 25;
    Color circle_color = BLUE;
    int cicle_movement_speed = 5;
    // Circle Coordinates
    int circle_x = width / 4;
    int circle_y = length / 2; 
    // Circle Edges
    int l_circle_x = circle_x - circle_radius;
    int r_circle_x = circle_x + circle_radius;
    int u_circle_y = circle_y - circle_radius;
    int b_circle_y = circle_y + circle_radius;

    // Rectangle Variables
    // Rectangle Attributes
    int rectangle_height = 50;
    int rectangle_width = 50;
    Color rectangle_color = RED;
    int rectangle_movement_speed = 15;
    // Rectangle Coordinates
    int rectangle_x = (width / 2) - (rectangle_width / 2) + (width / 4);
    int rectangle_y = length / 2 - (rectangle_height / 2);
    //Rectangle Edges
    int l_rectangle_x = rectangle_x;
    int r_rectangle_x = rectangle_x + rectangle_width;
    int u_rectangle_y = rectangle_y;
    int b_rectangle_y = rectangle_y + rectangle_height;
    
    
    bool collision_with_axe = 
                        (b_rectangle_y >= u_circle_y) 
                        && (u_rectangle_y <= b_circle_y) 
                        && (l_rectangle_x <= r_circle_x) 
                        && (r_rectangle_x >= l_circle_x);
    SetTargetFPS(60); 
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game Logic Begins

        // Rectangle Logic
        if (collision_with_axe)
        {
            DrawText("Game Over!", width / 2, length / 2, 32, RED);
        }
        else
        {
            // Update Circle Edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            // Update Rectangle Edges
            l_rectangle_x = rectangle_x;
            r_rectangle_x = rectangle_x + rectangle_width;
            u_rectangle_y = rectangle_y;
            b_rectangle_y = rectangle_y + rectangle_height;

            // Update collision_with_axe
            collision_with_axe = 
                        (b_rectangle_y >= u_circle_y) 
                        && (u_rectangle_y <= b_circle_y) 
                        && (l_rectangle_x <= r_circle_x) 
                        && (r_rectangle_x >= l_circle_x);

            DrawRectangle(rectangle_x, rectangle_y, rectangle_width, rectangle_height, rectangle_color);
            rectangle_y += rectangle_movement_speed;
            if((rectangle_y + rectangle_height) >= length || rectangle_y <= 0)
            {
                rectangle_movement_speed = -rectangle_movement_speed;
            }

            // Circle Logic
            DrawCircle(circle_x, circle_y,circle_radius,circle_color);

            if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && (circle_x < width - circle_radius))
            {
                circle_x += cicle_movement_speed;
            }

            if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && (circle_x > 0 + circle_radius))
            {
                circle_x -= cicle_movement_speed;
            }

            if((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && (circle_y < length - circle_radius))
            {
                circle_y += cicle_movement_speed;
            }

            if((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && (circle_y > 0 + circle_radius))
            {
                circle_y -= cicle_movement_speed;
            }
        }
        // Game logic Ends
        EndDrawing();
    }
}