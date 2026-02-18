#include <allegro5/allegro.h> //allegro is a graphics library for C/C++
#include <allegro5/allegro_primitives.h> //sub library that draws simple shapes


int main() //starting pt of all C programs
{
    al_init(); //sets up allegro
    al_init_primitives_addon(); //sets up sub library

    ALLEGRO_DISPLAY* display = al_create_display(800, 600); //makes the game screen

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue(); //sets up event queue
    al_register_event_source(queue, al_get_display_event_source(display)); //sets up ability to close window

    srand(time(NULL)); //seed our random number generator

    //set up two arrays (arrays are like python lists). one holds star x positions, the other y positions.
    int x[150]; 
    int y[150];

    for (int i = 0; i < 150; i++) //loop to create a bunch of random numbers
    {
        x[i] = rand() % 800; //random number between 0-799
        y[i] = rand() % 600; //random number between 0-599
    }

    bool running = true;

    while (running) //OMG GAME LOOP!!#########################################################
    {
        //INPUT SECTION------------------------------------------------------------------------
        ALLEGRO_EVENT ev; //create event queue
        while (al_get_next_event(queue, &ev))
        {
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                running = false;

            //if this was a real game we'd have other stuff here like keyboard input
        }


        //GRAPHICS SECTION---------------------------------------------------------------------
        // Background
        al_clear_to_color(al_map_rgb(10, 10, 30));

        // draw small stars
        for (int i = 0; i < 150; i++)
        {
            al_draw_filled_circle(x[i], y[i], 2, al_map_rgb(255, 255, 255));
        }

        // Planet
        al_draw_filled_circle(600, 400, 100, al_map_rgb(40, 120, 200));
        al_draw_filled_circle(560, 360, 20, al_map_rgb(30, 100, 180));
        al_draw_filled_circle(630, 380, 15, al_map_rgb(25, 90, 170));
        al_draw_filled_circle(580, 430, 18, al_map_rgb(35, 105, 185));
        al_draw_filled_circle(640, 450, 12, al_map_rgb(20, 80, 160));
        al_draw_filled_circle(600, 395, 10, al_map_rgb(30, 95, 175));

        // Moon
        al_draw_filled_circle(120, 100, 50, al_map_rgb(180, 180, 180));
        al_draw_filled_circle(100, 90, 10, al_map_rgb(150, 150, 150));
        al_draw_filled_circle(135, 115, 8, al_map_rgb(150, 150, 150));
        al_draw_filled_circle(125, 80, 6, al_map_rgb(150, 150, 150));

        // Star
        al_draw_filled_triangle(400, 100, 430, 160, 370, 160, al_map_rgb(255, 220, 50));
        al_draw_filled_triangle(400, 180, 430, 120, 370, 120, al_map_rgb(255, 220, 50));

        // UFO
        al_draw_filled_ellipse(300, 250, 60, 20, al_map_rgb(120, 120, 120));
        al_draw_filled_ellipse(300, 230, 30, 20, al_map_rgb(100, 200, 255));
        al_draw_filled_circle(260, 250, 4, al_map_rgb(255, 50, 50));
        al_draw_filled_circle(280, 255, 4, al_map_rgb(255, 200, 50));
        al_draw_filled_circle(300, 258, 4, al_map_rgb(50, 255, 50));
        al_draw_filled_circle(320, 255, 4, al_map_rgb(255, 200, 50));
        al_draw_filled_circle(340, 250, 4, al_map_rgb(255, 50, 50));

        // Rocket
        al_draw_filled_rectangle(100, 350, 140, 450, al_map_rgb(200, 200, 200));
        al_draw_filled_triangle(100, 350, 140, 350, 120, 320, al_map_rgb(220, 0, 0));
        al_draw_filled_triangle(100, 430, 80, 460, 100, 450, al_map_rgb(180, 0, 0));
        al_draw_filled_triangle(140, 430, 160, 460, 140, 450, al_map_rgb(180, 0, 0));
        al_draw_filled_circle(120, 390, 12, al_map_rgb(100, 200, 255));
        al_draw_filled_triangle(110, 450, 130, 450, 120, 500, al_map_rgb(255, 120, 0));

        al_flip_display();
    }

    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}
