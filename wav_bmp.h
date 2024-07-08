#ifndef __WAV_BMP_H
#define __WAV_BMP_H

#ifdef __cplusplus
extern "C"{
#endif /*__cplusplus*/

#include <stdint.h>

#pragma pack(1)
//wav audio
typedef struct
{
	//the RIFF chunk descriptor
	char chunkID[4];
	uint32_t chunkSize;
	char format[4];

	//the FMT sub-chunk
	char SubChunk1ID[4];
	uint32_t SubChunk1Size;
	uint16_t AudioFormat;
	uint16_t NumChannels;
	uint32_t SampleRate;
	uint32_t ByteRate;
	uint16_t BlockAlign;
	uint16_t BitsPerSample;

	//the DATA sub-chunk
	char SubChunk2ID[4];
	uint32_t SubChunk2Size;
	void *data;
}wav;

//bmp graph
typedef struct 
{
	//bitmap file header(14Byte)
	char bfType[2];
	uint32_t bfSize;
	uint16_t bfReserved1;
	uint16_t bfReserved2;
	uint32_t bfOffBits;

	//bitmap info header(40Byte)
	uint32_t biSize;
	uint32_t biWidth;
	uint32_t biHeight;
	uint16_t biPlanes;
	uint16_t biBitCount;
	uint32_t biCompression;
	uint32_t biSizeImage;
	uint32_t biXpelsPerMeter;
	uint32_t biYPelsPerMeter;
	uint32_t biClrUsed;
	uint32_t biClrImportant;

	//color table(depednt on biBitCount)
	//uint8_t rgbBlue;
	//uint8_t rgbGreen;
	//uint8_t rgbRed;
	//uint8_t rgbReserved;

	//pixel array
	void *data;
}bmp;
#pragma pack()

void wav_read(wav *obj,const char *file);
void wav_write(wav *obj,const char *file);
void bmp_read(bmp *obj,const char *file);
void bmp_write(bmp *obj,const char *file);

#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*__WAV_BMP_H*/



