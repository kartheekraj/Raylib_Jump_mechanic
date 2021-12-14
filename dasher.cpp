#include "raylib.h";

int main()
{
    //Window dimensions
    const int winWidth {512}; 
    const int winHeight {380};

    InitWindow(winWidth, winHeight,"Dapper Dasher!");

    //acceleration due to gravity (pixels/frame)/frame
    const int gravity{1};
    

    // rectangle dimentions
    const int rect_width{50};
    const int rect_height{80};

    // is the rectangle in the air?
    bool isInAir{};
    // jump velocity 
    const int jumpVel{-22};

    int posY{winWidth - rect_height};
    int velocity{0};

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        //perform ground check
        if(posY >= winHeight - rect_height)
        {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else 
        {
            // rectangle in in the air
            velocity += gravity;  
            isInAir = true;
        }
         // jump check   
         if(IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel; // use negative value to move character upwards
        }

        //update postion
        posY += velocity;

        DrawRectangle(winWidth/2, posY,rect_width,rect_height,BLUE);


        // stop drawing
        EndDrawing();       
    }
    CloseWindow();
    
}