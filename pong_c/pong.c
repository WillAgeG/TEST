#include <math.h>
#include <stdio.h>
#include <string.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/XKBlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>

#define mapWidth 80
#define mapHeight 25
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846

typedef struct { //Тип Ракетка 1
  int x, y, w;
} Tracket;

typedef struct { //Тип Ракетка 2
  int x, y, w;
} Tracket2;

typedef struct { //Тип Шарик 1
  float x, y;
  int ix, iy;
  float alpha;
  float speed;
} TBall;

char map[mapHeight][mapWidth + 1]; // Типы
Tracket racket;
Tracket2 racket2;
TBall ball;
int Counter = 0;
int Counter2 = 0;

void initRacket() { //Инициалзация расположения ракеток
  racket.w = 3;                          //Размер ракетки
  racket.x = mapWidth - 3;               //Отступ от края
  racket.y = (mapHeight - racket.w) / 2; //Отступ от края по оси y

  racket2.w = 3; //Размер ракетки
  racket2.x = 2; //Отступ от края по оси x
  racket2.y = (mapHeight - racket.w) / 2; //Отступ от края по оси y
}

void putRacket() { //Графика ракетки
  for (int i = racket.y; i < racket.y + racket.w; i++)
    map[i][racket.x] = '|';

  for (int i = racket2.y; i < racket2.y + racket2.w; i++)
    map[i][racket2.x] = '|';
}

void ClearMap() {                    // Инициализация карты
  for (int i = 0; i < mapWidth; i++) //Начало #######
    map[0][i] = '#';
  map[0][mapWidth] = '\0';
  strncpy(map[1], map[0], mapWidth + 1);

  for (int i = 1; i < mapWidth - 1; i++) //Создание пустого поля от #
    if (i == 1)
      map[1][i] = '=';
    else if (i == (mapWidth - 2))
      map[1][i] = '$';
    else if (i == (mapWidth / 2))
      map[1][i] = '!';
    else
      map[1][i] = ' ';

  for (int i = 2; i < mapHeight - 1; i++) // Создание боков #
    strncpy(map[i], map[1], mapWidth + 1);

  for (int i = 0; i < mapWidth; i++) //Конец ########
    map[mapHeight - 1][i] = '#';
  map[mapHeight][mapWidth] = '\0';
}

void ShowMap() { //Графика карты
  for (int j = 0; j < mapHeight; j++) {
    printf("%s", map[j]);
    if (j == 3)
      printf("   -PLAYER 1-  %i points  ", Counter);
    if (j == 4)
      printf("   -PLAYER 2-  %i points  ", Counter2);
    if (j < mapHeight - 1)
      printf("\n");
  }
}

void moveRacket(int y) { //Система движения ракетки 1
  racket.y = y;
  if (racket.y < 1)
    racket.y = 1;
  if (racket.y + racket.w >= mapHeight)
    racket.y = mapHeight - 1 - racket.w;
}

void moveRacket2(int y) { //Система движения ракетки 2
  racket2.y = y;
  if (racket2.y < 1)
    racket2.y = 1;
  if (racket2.y + racket2.w >= mapHeight)
    racket2.y = mapHeight - 1 - racket2.w;
}

void putBall() { map[ball.iy][ball.ix] = '*'; }

void moveBall(float x, float y) { //Система движения ракетки
  ball.x = x;
  ball.y = y;
  ball.ix = (int)round(ball.x);
  ball.iy = (int)round(ball.y);
}

void initBall() { // Инициализация шарика
  ball.x = mapWidth / 2; // x координаты шарика в начале раунда
  ball.y = mapHeight / 2; // y координаты шарика в начале раунда
  ball.alpha = -1;  //Угол шарика
  ball.speed = 0.8; //Скорость шарика При=1 это хардкор При=0.8 - это нормально
                    //При=0.5 - это легко
}

void autoMoveBall() { //Система автоматизированного движения шарика
  if (ball.alpha < 0) //Оптимизация памяти
    ball.alpha += M_PI * 2;
  if (ball.alpha > M_PI * 2)
    ball.alpha -= M_PI * 2;

  TBall bl = ball;
  moveBall(ball.x + cos(ball.alpha) * ball.speed, //Движение шарика
           ball.y + sin(ball.alpha) * ball.speed);

  if (map[ball.iy][ball.ix] ==
      '=') { //При столкновении счетчик Player 1 увеличивается на 1 и шарик
             //снова появляется по середине
    Counter++;
    moveBall(racket.x - 37, racket.y + 1);
  }

  if (map[ball.iy][ball.ix] ==
      '$') { //При столкновении счетчик Player 2 увеличивается на 1 и шарик
             //снова появляется по середине
    Counter2++;
    moveBall(racket.x - 37, racket.y + 1);
  }

  if ((map[ball.iy][ball.ix] == '#') ||
      (map[ball.iy][ball.ix] == '|')) { //Когда шарик врезается в стену, он
                                        //отскакивает (Заданная физика шарика)
    if ((ball.ix != bl.ix) && (ball.iy != bl.iy)) {
      if (map[bl.iy][ball.ix] == map[ball.iy][bl.ix])
        bl.alpha = bl.alpha + M_PI;
      else {
        if (map[bl.iy][ball.ix] == '#')
          bl.alpha = (2 * M_PI - bl.alpha) + M_PI;
        else
          bl.alpha = (2 * M_PI - bl.alpha);
      }
    } else if (ball.iy == bl.iy)
      bl.alpha = (2 * M_PI - bl.alpha) + M_PI;
    else
      bl.alpha = (2 * M_PI - bl.alpha);

    ball = bl;
    autoMoveBall();
  }
}

int main() { //Основная программа
  nodelay(stdscr, TRUE);
  char c;
  initRacket();
  initBall();
  int run = 1;

  do {
    printf("\n"); //Костыль

    ClearMap();
    putRacket();
    putBall();
    ShowMap();

    if (ball.iy > mapHeight || ball.ix > mapWidth) { // Рестарт шарика
      run = 0;
    }

    c = getch();
    if (c == ' ') {
      autoMoveBall();
    }

    if (run)
      autoMoveBall();

    if (c == 'K') // Управление ракеткой 2
      moveRacket(racket.y - 1);
    if (c == 'M')
      moveRacket(racket.y + 1);

    if (c == 'A') // Управление ракеткой 1
      moveRacket2(racket2.y - 1);
    if (c == 'Z')
      moveRacket2(racket2.y + 1);
    if (c == 'W') // Запуск шарика (Выключено)
      run = 1;
    if (!run)
      moveBall(racket.x - 37, racket.y + 1);

    if (Counter >= 21) // Победа при достижении 21 очка
      c = 'q';
    if (Counter2 >= 21)
      c = 'q';
    sleep(1);
  } while (c != 'q');
  initscr();
  nodelay(stdscr, FALSE);

  if (Counter >= 21) // ПОЗДРАВЛЕНИЕ ВЫИГРАВШЕГО!!!
    printf("PLAYER 1 Winner Winner Chicken Dinner!!\n");
  else
    printf("PLAYER 2 Winner Winner Chicken Dinner!!\n");

  printf("            ,~.                                         \n");
  printf("           ,-'__ `-,                                    \n");
  printf("          (,-'  `. )              ,')                   \n");
  printf("         ,( a )   `-.__         ,',')~,                 \n");
  printf("        <=.) (         `-.__,==' ' ' ')                 \n");
  printf("          (   )                      /                  \n");
  printf("           `-'|   ,                    )                \n");
  printf("               |  |        `~.        /                 \n");
  printf("               |   `._        |      /                  \n");
  printf("                |     `._____,'    ,'                   \n");
  printf("                 `-.             ,'                     \n");
  printf("                    `-._      _,'                       \n");
  printf("                        `"
         ""
         "                           \n");

  return 0;
}
