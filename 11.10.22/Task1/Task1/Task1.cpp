/*
#pragma once

typedef unsigned __int16 WORD;
typedef unsigned __int32 DWORD;
typedef unsigned __int32 LONG;

struct BITMAPFILEHEADER{
	WORD bfType;
	DWORD bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits;
};

struct BITMAPINFOHEADER{
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
};
*/

#include <iostream>
#include <fstream>
#include "Header.h"

int main(int argc, char* argv[]){
	if (argc < 2) {
		std::cerr << "Something goes wrong" << std::endl;
	}

	BITMAPFILEHEADER filehdr;
	BITMAPINFOHEADER bmphdr;

	std::ifstream fsrc(argv[1], std::ios_base::binary);

	if (!fsrc.is_open()) {
		std::cout << "Ошибка чтения графического файла";
	}

	fsrc.read((char*)&filehdr, sizeof(BITMAPFILEHEADER));
	if (fsrc.fail()) {
		std::cout << "Ошибка чтения заголовка файла BMP";
	}

	//std::cout << filehdr << std::endl;

	fsrc.read((char*)&bmphdr, sizeof(BITMAPINFOHEADER));
	if (fsrc.fail()) {
		std::cout << "Ошибка чтения информационного заголовка файла BMP";
	}

	//std::cout << filehdr << std::endl;
	
	fsrc.close();
	return 0;
}
