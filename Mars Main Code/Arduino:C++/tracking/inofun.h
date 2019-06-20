#ifndef _INOFUN_H
#define _INOFUN_H


struct tuple{
  double x;
  double y;
};

struct data{
  double x;
  double y;
  int height;
  int width;
};

double distance(struct tuple v);
struct tuple mapValues(struct data d);
int start();
struct tuple unitvector(struct tuple v);
struct data parcedata(String raw_data);
void simple_move(struct tuple v);

#endif

