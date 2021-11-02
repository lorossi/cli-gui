#include "terminal.h"
#include <time.h>   // for random init
#include <stdlib.h> // for random values
#include <stdio.h>  // for I/O operations

// #define TESTS
#define DIALOG

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)     \
  (byte & 0x80 ? '1' : '0'),     \
      (byte & 0x40 ? '1' : '0'), \
      (byte & 0x20 ? '1' : '0'), \
      (byte & 0x10 ? '1' : '0'), \
      (byte & 0x08 ? '1' : '0'), \
      (byte & 0x04 ? '1' : '0'), \
      (byte & 0x02 ? '1' : '0'), \
      (byte & 0x01 ? '1' : '0')

void test_windows()
{
  reset_styles();
  clear_terminal();

  Window *w_left = createWindow(1, 2);
  windowSetPadding(w_left, 1);
  windowAddLine(w_left, "LEFT");
  windowAddLine(w_left, "");
  windowAddLine(w_left, "TEXT");
  windowShow(w_left);

  Window *w_center = createWindow(20, 2);
  windowSetAlignment(w_center, 0);
  windowSetPadding(w_center, 2);
  windowAddLine(w_center, "CENTER");
  windowAddLine(w_center, "");
  windowAddLine(w_center, "TEXT");
  windowShow(w_center);

  Window *w_right = createWindow(40, 2);
  windowSetPadding(w_right, 1);
  windowSetAlignment(w_right, 1);
  windowAddLine(w_right, "RIGHT");
  windowAddLine(w_right, "");
  windowAddLine(w_right, "TEXT");
  windowShow(w_right);

  Window *w_wide = createWindow(10, 10);
  windowAddLine(w_wide, "VERY VERY VERY VERY VERY LONG WINDOW");
  windowAddLine(w_wide, "AND");
  windowAddLine(w_wide, "TEXT INSIDE");
  windowSetAlignment(w_wide, 0);
  windowSetSize(w_wide, 50, 5);
  windowSetAlignment(w_wide, 0);
  windowShow(w_wide);

  move_cursor_to_bottom();
  await_keypress("\nPress a button to continue");

  windowClear(w_wide);
  deleteWindow(w_wide);
  deleteWindow(w_left);
  deleteWindow(w_center);
  deleteWindow(w_right);

  return;
}

void test_colors()
{
  reset_styles();
  clear_terminal();

  /* test foreground colors */
  move_cursor_to(0, 0);
  set_fg(fg_BLACK);
  printf("Color: black");

  move_cursor_to(0, 1);
  set_fg(fg_RED);
  printf("Color: red");

  move_cursor_to(0, 2);
  set_fg(fg_GREEN);
  printf("Color: green");

  move_cursor_to(0, 3);
  set_fg(fg_YELLOW);
  printf("Color: yellow");

  move_cursor_to(0, 4);
  set_fg(fg_BLUE);
  printf("Color: blue");

  move_cursor_to(0, 5);
  set_fg(fg_MAGENTA);
  printf("Color: magenta");

  move_cursor_to(0, 6);
  set_fg(fg_CYAN);
  printf("Color: cyan");

  move_cursor_to(0, 7);
  set_fg(fg_WHITE);
  printf("Color: white");

  move_cursor_to(0, 8);
  set_fg(fg_DEFAULT);
  printf("Color: default");

  move_cursor_to(15, 0);
  set_fg(fg_BRIGHT_BLACK);
  printf("Color: bright black");

  move_cursor_to(15, 1);
  set_fg(fg_BRIGHT_RED);
  printf("Color: bright red");

  move_cursor_to(15, 2);
  set_fg(fg_BRIGHT_GREEN);
  printf("Color: bright green");

  move_cursor_to(15, 3);
  set_fg(fg_BRIGHT_YELLOW);
  printf("Color: bright yellow");

  move_cursor_to(15, 4);
  set_fg(fg_BRIGHT_BLUE);
  printf("Color: bright blue");

  move_cursor_to(15, 5);
  set_fg(fg_BRIGHT_MAGENTA);
  printf("Color: bright magenta");

  move_cursor_to(15, 6);
  set_fg(fg_BRIGHT_CYAN);
  printf("Color: bright cyan");

  move_cursor_to(15, 7);
  set_fg(fg_BRIGHT_WHITE);
  printf("Color: bright white");

  reset_fg();
  /* test background colors */
  move_cursor_to(0, 9);
  set_bg(bg_BLACK);
  printf("Color: black");

  move_cursor_to(0, 10);
  set_bg(bg_RED);
  printf("Color: red");

  move_cursor_to(0, 11);
  set_bg(bg_GREEN);
  printf("Color: green");

  move_cursor_to(0, 12);
  set_bg(bg_YELLOW);
  printf("Color: yellow");

  move_cursor_to(0, 13);
  set_bg(bg_BLUE);
  printf("Color: blue");

  move_cursor_to(0, 14);
  set_bg(bg_MAGENTA);
  printf("Color: magenta");

  move_cursor_to(0, 15);
  set_bg(bg_CYAN);
  printf("Color: cyan");

  move_cursor_to(0, 16);
  set_bg(bg_WHITE);
  printf("Color: white");

  move_cursor_to(0, 17);
  set_bg(bg_DEFAULT);
  printf("Color: default");

  move_cursor_to(15, 9);
  set_bg(bg_BRIGHT_BLACK);
  printf("Color: bright black");

  move_cursor_to(15, 10);
  set_bg(bg_BRIGHT_RED);
  printf("Color: bright red");

  move_cursor_to(15, 11);
  set_bg(bg_BRIGHT_GREEN);
  printf("Color: bright green");

  move_cursor_to(15, 12);
  set_bg(bg_BRIGHT_YELLOW);
  printf("Color: bright yellow");

  move_cursor_to(15, 13);
  set_bg(bg_BRIGHT_BLUE);
  printf("Color: bright blue");

  move_cursor_to(15, 14);
  set_bg(bg_BRIGHT_MAGENTA);
  printf("Color: bright magenta");

  move_cursor_to(15, 15);
  set_bg(bg_BRIGHT_CYAN);
  printf("Color: bright cyan");

  move_cursor_to(15, 16);
  set_bg(bg_BRIGHT_WHITE);
  printf("Color: bright white");

  printf("\n");

  reset_styles();
  return;
}

void test_textmodes()
{
  reset_styles();
  clear_terminal();

  set_textmode(text_BOLD);
  printf("BOLD TEXT\n");
  reset_textmode();

  set_textmode(text_FAINT);
  printf("FAINT TEXT\n");
  reset_textmode();

  set_textmode(text_ITALIC);
  printf("ITALIC TEXT\n");
  reset_textmode();

  set_textmode(text_UNDERLINE);
  printf("UNDERLINE TEXT\n");
  reset_textmode();

  set_textmode(text_BLINKING);
  printf("BLINKING TEXT\n");
  reset_textmode();

  set_textmode(text_REVERSE);
  printf("REVERSE TEXT\n");
  reset_textmode();

  set_textmode(text_HIDDEN);
  printf("HIDDEN TEXT");
  reset_textmode();
  printf(" (hidden) \n");

  set_textmode(text_STRIKETHROUGH);
  printf("STRIKETHROUGH TEXT\n");
  reset_textmode();

  reset_styles();
  return;
}

void test_mixed()
{
  reset_styles();
  clear_terminal();
  move_cursor_to(0, 0);

  reset_styles();
  set_styles(3, text_BOLD, fg_RED, bg_BRIGHT_WHITE);
  printf("Italic, red on bright white\n");

  reset_styles();
  set_styles(4, text_FAINT, text_ITALIC, fg_YELLOW, bg_BRIGHT_CYAN);
  printf("Faint italic, yellow on bright cyan\n");

  reset_styles();
  set_styles(4, fg_BRIGHT_YELLOW, bg_BRIGHT_GREEN, text_BLINKING, text_UNDERLINE);
  printf("Blinking underlined, bright yellow on bright green\n");

  reset_styles();
  set_styles(5, fg_BRIGHT_GREEN, bg_BRIGHT_BLUE, text_UNDERLINE, text_BOLD, text_STRIKETHROUGH);
  printf("Bold, underlined, strikethrough, bright green on bright blue\n");

  reset_styles();
}

void test_RGB()
{
  const int inc = 2;

  reset_styles();
  clear_terminal();
  move_cursor_to(0, 0);

  set_fg(fg_RED);
  printf("RED:   ");

  for (int r = 255; r >= 0; r -= inc)
  {
    RGB color = createRGBcolor(r, 0, 0);
    set_fg_RGB(color);
    printf("@");
  }

  printf("\n");

  set_fg(fg_GREEN);
  printf("GREEN: ");

  for (int g = 255; g >= 0; g -= inc)
  {
    RGB color = createRGBcolor(0, g, 0);
    set_fg_RGB(color);
    printf("@");
  }

  printf("\n");

  set_fg(fg_BLUE);
  printf("BLUE:  ");

  for (int b = 255; b >= 0; b -= inc)
  {
    RGB color = createRGBcolor(0, 0, b);
    set_fg_RGB(color);
    printf("@");
  }

  printf("\n\n");
  reset_styles();

  reset_bg();
  set_fg(fg_RED);
  printf("RED:   ");

  for (int r = 255; r >= 0; r -= inc)
  {
    RGB color = createRGBcolor(r, 0, 0);
    set_bg_RGB(color);
    printf(" ");
  }

  printf("\n");

  reset_bg();
  set_fg(fg_GREEN);
  printf("GREEN: ");

  for (int g = 255; g >= 0; g -= inc)
  {
    RGB color = createRGBcolor(0, g, 0);
    set_bg_RGB(color);
    printf(" ");
  }

  printf("\n");

  reset_bg();
  set_fg(fg_BLUE);
  printf("BLUE:  ");

  for (int b = 255; b >= 0; b -= inc)
  {
    RGB color = createRGBcolor(0, 0, b);
    set_bg_RGB(color);
    printf(" ");
  }

  printf("\n");

  reset_styles();
}

void test_HSL()
{
  clear_terminal();
  move_cursor_to(0, 0);
  reset_styles();

  const int inc = 6;
  int x, y;

  x = 0;
  y = 0;
  for (int h = 0; h < 360; h += inc)
  {
    for (int s = 99; s >= 0; s -= inc)
    {
      HSL color = createHSLcolor(h, s, 50);

      move_cursor_to(x, y);
      set_fg_HSL(color);
      printf("@");

      y++;
    }

    x++;
    y = 0;
  }

  reset_styles();

  x = 0;
  y = 0;
  for (int h = 0; h < 360; h += inc)
  {
    for (int s = 100; s >= 0; s -= inc)
    {
      HSL color = createHSLcolor(h, s, 50);

      move_cursor_to(x, y + 100 / inc + 2);
      set_bg_HSL(color);
      printf(" ");

      y++;
    }

    x++;
    y = 0;
  }

  printf("\n\n");
  reset_styles();
}

void test_hue()
{
  clear_terminal();
  move_cursor_to(0, 0);
  reset_styles();

  const int inc = 3;
  int x = 0;

  for (int h = 0; h < 360; h += inc)
  {
    RGB color = HUEtoRGB(h);
    reset_bg();
    move_cursor_to(x, 0);
    set_fg_RGB(color);
    printf("@");

    move_cursor_to(x, 1);
    set_bg_RGB(color);
    printf(" ");
    x++;
  }

  reset_styles();
}

void starry_night()
{
  RGB sky_color = createRGBcolor(25, 25, 112);
  RGB star_color = createRGBcolor(255, 205, 60);
  Rectangle size = get_terminal_size();

  reset_styles();
  set_bg_RGB(sky_color);
  set_fg_RGB(star_color);
  set_textmode(text_BOLD);
  set_textmode(text_BLINKING);

  clear_terminal();

  srand(time(NULL));
  for (int i = 0; i < 25; i++)
  {
    int x = rand() % size.width;
    int y = rand() % size.height;
    move_cursor_to(x, y);
    printf("*");
  }

  move_cursor_to_bottom();
  reset_styles();
}

void dialog()
{
  clear_terminal();

  Dialog *d = createDialog(8, 4);
  dialogSetPadding(d, 4);
  dialogSetText(d, "Previous session found. Continue?", 1);
  dialogSetButtons(d, "  AYE  ", "  NAY  ");
  dialogShow(d);
  dialogWaitResponse(d);
  dialogClear(d);
  deleteDialog(d);
  move_cursor_to(0, 0);
}

void special_keypress()
{
  char special;

  while (1)
  {
    special = poll_special_keypress();
    if (special & 0b10000000) // backspace
      break;
    else if (special)
      printf(BYTE_TO_BINARY_PATTERN "\n", BYTE_TO_BINARY(special));
  }
}

int main()
{

  enter_raw_mode();
  hide_cursor();
  clear_terminal();

  // test_windows();
  // await_keypress("\nPress a button to continue");

  // test_colors();
  // await_keypress("\nPress a button to continue");

  // test_textmodes();
  // await_keypress("\nPress a button to continue");

  // test_mixed();
  // await_keypress("\nPress a button to continue");

  // test_RGB();
  // await_keypress("\nPress a button to continue");

  test_HSL();
  await_keypress("\nPress a button to continue");

  // test_hue();
  // await_keypress("\nPress a button to continue");

  // starry_night();
  // await_keypress("\nPress a button to continue");

  // dialog();
  // await_keypress("\nPress a button to continue");

  show_cursor();
  exit_raw_mode();
  clear_terminal();

  return 0;
}