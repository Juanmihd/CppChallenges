/// Juanmi Huertas Delgado, 2015
/// Small lab session exercise to simulate the throwing of a cat in the air

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include "Cat.h"


//This function will update the next position of the cat taking into account
//it's current velocity 
void update_cat(a_cat &cat, float incr_time){
  if (cat.y > 0){//if it's on the floor it cannot move
    //update position
    cat.x += cat.vx*incr_time;
    cat.y += cat.vy*incr_time;
    if (cat.y < 0) cat.y = 0;
    //update velocty
    cat.vx -= cat.y*incr_time; //wind velocity
    cat.vy -= 9.8f*incr_time;
  }
}

float rand_FloatRange(float a, float b)
{
  return ((b - a)*((float)rand() / RAND_MAX)) + a;
}

void input_speed_elevation(a_cat &cat, float speed, float elevation){
  elevation *= 3.1416f / 180;
  cat.vx = speed * cos(elevation);
  cat.vy = speed * sin(elevation);
}


int main(int argc, char** argv){
  //Run simulation

  int num_attempts = 10000;
  srand(time(NULL));
  while (num_attempts != 0){
    float speed, elevation;
    a_cat cat1;
    cat1.x = 1;
    cat1.y = 1;
    bool stop = false;
    speed = rand_FloatRange(10, 100);
    elevation = rand_FloatRange(10,85);
    input_speed_elevation(cat1, speed, elevation);
    while (!stop){
      update_cat(cat1,0.005f);
      //It will stop if it touch the floor or the branch, of if it went too far from the branch
      stop = (cat1.vy <= 0);
    }
    if (cat1.x >= 10.9f && cat1.x <= 11.1f && cat1.y >= 10.60f)
      std::cout << "Reached branch" << cat1 
                << " with initial speed " << speed 
                << " and initial elevation " << elevation << ".\n";

    --num_attempts;
  }
}