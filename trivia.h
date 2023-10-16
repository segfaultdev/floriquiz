#ifndef __TRIVIA_H__
#define __TRIVIA_H__

typedef struct trivia_t trivia_t;

struct trivia_t {
  enum {
    level_easy,
    level_medium,
    level_hard,
  } level;
  
  enum {
    answer_a,
    answer_b,
    answer_c,
    answer_d,
  } answer;
  
  const char *text, *options_long[4], *options_short[4];
};

extern const trivia_t trivia_set_a[], trivia_set_b[];

#endif
