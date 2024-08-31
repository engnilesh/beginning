#include<reg51.h>

#include<stdio.h>

#include <intrins.h>

#define lcd P3
sbit SOUND_A = P1 ^ 0;
sbit SOUND_B = P1 ^ 1;
sbit SOUND_C = P1 ^ 2;
sbit SOUND_D = P1 ^ 3;
sbit rs = P0 ^ 0; //register select
sbit rw = P0 ^ 1; //RW
sbit en = P0 ^ 2; //enable
void lcd_init();
void cmd(unsigned char);
void dat(unsigned char);
void lcd_string(char * s);
void delay();
void main() {
    P1 = 0xff;
    P2 = 0x00;
    lcd_init();
    lcd_string("ROTATING CAMERA");
    do {
      if (SOUND_A == 0) {
        cmd(0xc0);
        lcd_string("Speaker 1"); // 0° position
        P2 = 0x05; //1100
      } else if (SOUND_B == 0) {
        cmd(0xc0);
        lcd_string("Speaker 2");
        // 90° position
        P2 = 0x14;
        // 0110
      } else if (SOUND_C == 0) {
        cmd(0xc0);
        lcd
        _string("Speaker 3"); // 180° position
        P2 = 0x50;
        // 1100
      } else if (SOUND_D == 0) {
        cmd(0xc0);
        lcd_string("Speaker 4"); // 270° position
        P2 = 0x81;
        // 1001
      } else {
          cmd(0xc0);
          lcd_string(" "); // Motor at the same position
            P2 = 0x00;
        }
       } while (1);
    }
      void lcd_init() {
        cmd(0x38);
        cmd(0x0e);
        cmd(0x06);
        cmd(0x01);
        cmd(0x80);
      }
      void cmd(unsigned char a) {
        lcd = a;
        rs = 0;
        rw = 0;
        en = 1;
        delay();
        en = 0;
      }
      void dat(unsigned char b) {
        lcd = b;
        rs = 1;
        rw = 0;
        en = 1;
        delay();
        en = 0;
      }
      void lcd_string(char * s) {
        while ( * s) {
          dat( * s++);
        }
      }
      void delay() {
        unsigned int i;
        for (i = 0; i < 20000; i++);
      }
