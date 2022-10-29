#include "game-lib.h"
#include <stdlib.h>
#include <time.h>

#include "fnaf_test_png.h"
#include "Roboto_ttf.h"

std::vector<Rectangle> rectangles;
int tamanho = rand()%150+40;
u32 cores[] = {0xffff00ff, 0xff0fffff, 0xfafe12ff, 0xffff00ff, 0xff3f22ff, 0x131313ff, 0xff13ffff, 0xff00aaff, 0xffaa00ff, 0xff0000ff, 0x00ff00ff, 0xff00ffff};
void generate(){

    srand(time(NULL));
    for (int j = 0; j< 12; j++){
        tamanho = rand()%150+40;
        for(int i =0; i<640/tamanho; i++){
            if(i > 0){
                rectangles.push_back(Rectangle((tamanho*i)+(i*5), 1+(22*j), 20, tamanho, cores[j], true));
            }
            else{
                rectangles.push_back(Rectangle(1, 1+(22*j), 20, tamanho, cores[j], true));
            }

        }
    }
}

int main(){
    Game game;
    game.init();

    Text fonte(Roboto_ttf, Roboto_ttf_size);



    int nivel = 0;

    Rectangle player((640/2)-60, 450, 10, 60, 0xffffffff, true);
    Rectangle ball((640/2)-35, 435, 10, 10, COLOR_WHITE, true);
    bool ball_launched = false;
    int vel_x = 7, vel_y = 7;

    while(1){
        game.update_wiimote();

        if(game.wiimote_pressed(WPAD_BUTTON_HOME)) break;
        if(game.wiimote_hold(WPAD_BUTTON_LEFT)){
            player.move(-10, 0);
            if(!ball_launched)
                ball.move(-10, 0);
        }
        if(game.wiimote_hold(WPAD_BUTTON_RIGHT)){
            player.move(10, 0);
            if(!ball_launched)
                ball.move(10, 0);
        }
        
        if(game.wiimote_pressed(WPAD_BUTTON_A))
            ball_launched = true;

        for(int i  = 0; i<rectangles.size(); i++){
            rectangles[i].render();
            if(rectangles[i].is_colliding(ball)){
                vel_y*=-1;
                rectangles.erase(rectangles.begin()+i);
            }
        }

        if(ball.get_pos().x > 640 or ball.get_pos().x<0){
            vel_x *= -1;
        }
        if(ball.get_pos().y<0 or ball.is_colliding(player)){
            vel_y *= -1;
        }
        if(ball.get_pos().y>480){
            ball_launched = false;
            ball.set_pos(player.get_pos().x+25, 435);
        }

        if(ball_launched){
            ball.move(vel_x, vel_y);
        }

        if(rectangles.size()<=0)
            generate();

        fonte.print(std::to_string(tamanho).c_str());
        player.render();
        ball.render();


        GRRLIB_Render();
    }
}