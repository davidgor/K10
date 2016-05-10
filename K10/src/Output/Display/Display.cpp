/*
 * Display.cpp
 *
 *  Created on: 26-dec.-2015
 *      Author: david12
 */

#define DEV_FB "/dev"
#define FB_DEV_NAME "fb0"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <time.h>
#include <poll.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

#include <linux/input.h>
#include <linux/fb.h>

#include "Display.h"


int fbfd = 0;
int ret = 0;

struct pollfd evpoll;

struct fb_t {									// maak framebuffer aan
	uint16_t pixel[8][8];						// maak een scherm van 8X8 aan
};

struct fb_t *fb;								//maak merker aan waar framebuffer word opgeslagen

void SetStartupScreen(){						//Zet pixels op groen voor K
	fb->pixel[1][6]=0x0F0F;
	fb->pixel[1][5]=0x0F0F;
	fb->pixel[1][4]=0x0F0F;
	fb->pixel[1][3]=0x0F0F;
	fb->pixel[1][2]=0x0F0F;
	fb->pixel[2][5]=0x0F0F;
	fb->pixel[2][4]=0x0F0F;
	fb->pixel[3][3]=0x0F0F;
	fb->pixel[3][6]=0x0F0F;
	fb->pixel[3][2]=0x0F0F;

	fb->pixel[5][6]=0xF00F;						//Zet pixels op groen voor 9
	fb->pixel[5][5]=0xF00F;
	fb->pixel[5][4]=0xF00F;
	fb->pixel[5][2]=0xF00F;
	fb->pixel[6][6]=0xF00F;
	fb->pixel[6][4]=0xF00F;
	fb->pixel[6][2]=0xF00F;
	fb->pixel[7][6]=0xF00F;
	fb->pixel[7][5]=0xF00F;
	fb->pixel[7][4]=0xF00F;
	fb->pixel[7][3]=0xF00F;
	fb->pixel[7][2]=0xF00F;


	fb->pixel[0][0]=0x00FF;						//start laad balk
}

fb_t* CreateMMap(int fbfd){
	return static_cast<fb_t*>(mmap(0, 128, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0));
}

static int is_framebuffer_device(const struct dirent *dir)
{
	return strncmp(FB_DEV_NAME, dir->d_name,
		       strlen(FB_DEV_NAME)-1) == 0;
}

static int open_fbdev(const char *dev_name)
{
	struct dirent **namelist;
	int i, ndev;
	int fd = -1;
	struct fb_fix_screeninfo fix_info;

	ndev = scandir(DEV_FB, &namelist, is_framebuffer_device, versionsort);
	if (ndev <= 0)
		return ndev;

	for (i = 0; i < ndev; i++)
	{
		char fname[64];
		char name[256];

		snprintf(fname, sizeof(fname),
			 "%s/%s", DEV_FB, namelist[i]->d_name);
		fd = open(fname, O_RDWR);
		if (fd < 0)
			continue;
		ioctl(fd, FBIOGET_FSCREENINFO, &fix_info);
		if (strcmp(dev_name, fix_info.id) == 0)
			break;
		close(fd);
		fd = -1;
	}
	for (i = 0; i < ndev; i++)
		free(namelist[i]);

	return fd;
}


Display::Display(Loger* log) {
	fbfd = 0;

	srand(time(NULL));

	fbfd = open_fbdev("RPi-Sense FB");
	if (fbfd <= 0) {
		ret = fbfd;
		printf("Error: cannot open framebuffer device.\n");
		goto err_ev;

	}

	fb = CreateMMap(fbfd);
	if (!fb) {
		ret = EXIT_FAILURE;
		printf("Failed to mmap.\n");
		goto err_fb;
	}
	memset(fb, 0, 128);

	SetStartupScreen();										// show startupscreen

	err_fb:
		close(fbfd);
	err_ev:
		close(evpoll.fd);
		return;
}

void Display::SetPixel(int x,int y,uint16_t collor){
	fb->pixel[x][y]=collor;
}

void Display::SetHome(){
	memset(fb,0,128);
	SetPixel(2,1,0xF00F);
	SetPixel(3,1,0xF00F);
	SetPixel(4,1,0xF00F);
	SetPixel(5,1,0xF00F);
	SetPixel(2,2,0xF00F);
	SetPixel(5,2,0xF00F);
	SetPixel(2,3,0xF00F);
	SetPixel(5,3,0xF00F);
	SetPixel(2,4,0xF00F);
	SetPixel(5,4,0xF00F);
	SetPixel(2,5,0xF00F);
	SetPixel(5,5,0xF00F);
}

void Display::SetStop(){
	memset(fb,0,128);
	SetPixel(0,0,0xF00F);
	SetPixel(1,1,0xF00F);
	SetPixel(2,2,0xF00F);
	SetPixel(3,3,0xF00F);
	SetPixel(4,4,0xF00F);
	SetPixel(5,5,0xF00F);
	SetPixel(6,6,0xF00F);
	SetPixel(7,7,0xF00F);//  STOP icoon

	SetPixel(0,7,0xF00F);//  #      #
	SetPixel(1,6,0xF00F);//   #    #
	SetPixel(2,5,0xF00F);//    #  #
	SetPixel(3,4,0xF00F);//     ##
	SetPixel(4,3,0xF00F);//     ##
	SetPixel(5,2,0xF00F);//    #  #
	SetPixel(6,1,0xF00F);//   #    #
	SetPixel(7,0,0xF00F);//  #      #
}

void Display::SetTerug(){
	memset(fb,0,128);
	SetPixel(3,0,0x0B0F);
	SetPixel(4,0,0x0B0F);
	SetPixel(2,1,0x0B0F);
	SetPixel(3,1,0x0B0F);
	SetPixel(4,1,0x0B0F);
	SetPixel(5,1,0x0B0F);// Terug icoon
	SetPixel(1,2,0x0B0F);
	SetPixel(2,2,0x0B0F);//
	SetPixel(3,2,0x0B0F);//    #
	SetPixel(4,2,0x0B0F);//   ##
	SetPixel(5,2,0x0B0F);//  ########
	SetPixel(6,2,0x0B0F);//  ########
	SetPixel(3,3,0x0B0F);//   ##
	SetPixel(4,3,0x0B0F);//    #
	SetPixel(3,4,0x0B0F);//
	SetPixel(4,4,0x0B0F);
	SetPixel(3,5,0x0B0F);
	SetPixel(4,5,0x0B0F);
	SetPixel(3,6,0x0B0F);
	SetPixel(4,6,0x0B0F);
	SetPixel(3,7,0x0B0F);
	SetPixel(4,7,0x0B0F);
}

void Display::green(){
	for(int a=0;a!=8;a++)
		for(int b=0;b!=8;b++)
			SetPixel(a,b,0x0F0F);
}

void Display::red(){
	for(int a=0;a!=8;a++)
		for(int b=0;b!=8;b++)
			SetPixel(a,b,0xF00F);
}

void Display::Clear(){
	memset(fb,0,128);
}

Display::~Display() {
	memset(fb, 0, 128);										// cleare display
	delete fb;												// stop framebuffer

}

