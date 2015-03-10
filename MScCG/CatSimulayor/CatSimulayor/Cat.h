/// This is the coded provided by Andy Thomason for the cat_simulator


#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

struct a_cat {
  float x;
  float y;
  float vx;
  float vy;
};

std::ostream &operator <<(std::ostream &os, a_cat &cat) {
  os << "[x=";
  os.width(10); os << cat.x << ", y=";
  os.width(10); os << cat.y << ", vx=";
  os.width(10); os << cat.vx << ", vy=";
  os.width(10); os << cat.vy << "]";
  return os;
}

#endif