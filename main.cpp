#include <iostream>
#include "wav_bmp.h"

using namespace std;


//жиди
ostream &operator<<(ostream &co,wav &in)
{
	co << "chunkID:" << in.chunkID[0] << in.chunkID[1] << in.chunkID[2] << in.chunkID[3] << endl;
	co << "chunkSize:" << in.chunkSize << endl;
	co << "chunkID:" << in.format[0] << in.format[1] << in.format[2] << in.format[3] << endl;
	co << "SubChunk1ID:" << in.SubChunk1ID[0] << in.SubChunk1ID[1] << in.SubChunk1ID[2] << in.SubChunk1ID[3] << endl;
	co << "SubChunk1Size:" << in.SubChunk1Size << endl;
	co << "AudioFormat(1=pcm):" << in.AudioFormat << endl;
	co << "NumChannels:" << in.NumChannels << endl;
	co << "SampleRate:" << in.SampleRate << endl;
	co << "ByteRate:" << in.ByteRate << endl;
	co << "BlockAlign:" << in.BlockAlign << endl;
	co << "BitsPerSample:" << in.BitsPerSample << endl;
	return co;
}

//жиди
ostream &operator<<(ostream &co,bmp &in)
{
	co << "bfType:" << in.bfType[0] << in.bfType[1] << endl;
	co << "bfSize:" << in.bfSize << endl;
	co << "bfOffBits:" << in.bfOffBits << endl;
	co << "biSize:" << in.biSize << endl;
	co << "biWidth:" << in.biWidth << endl;
	co << "biHeight:" << in.biHeight << endl;
	co << "biPlanes:" << in.biPlanes << endl;
	co << "biBitCount:" << in.biBitCount << endl;
	co << "biCompression:" << in.biCompression << endl;
	co << "biSizeImage:" << in.biSizeImage << endl;
	co << "biXpelsPerMeter:" << in.biXpelsPerMeter << endl;
	co << "biYPelsPerMeter:" << in.biYPelsPerMeter << endl;
	co << "biClrUsed:" << in.biClrUsed << endl;
	co << "biClrImportant:" << in.biClrImportant << endl;
	return co;
}

int main(int argc,char *argv[])
{
#if 1
	wav x;
	wav_read(&x,"audio.wav");
	cout << x;
	char *p = (char *)x.data;
	for(int i = x.ByteRate*3;i < x.ByteRate*6;i++)p[i] = 0;
	wav_write(&x,"out.wav");
#else
	bmp x;
	bmp_read(&x,"pic.bmp");
	cout << x;
	char *p = (char *)x.data;
	for(int i = x.biSizeImage/4;i < x.biSizeImage/2;i++)p[i] = 127;
	bmp_write(&x,"out.bmp");
#endif
	system("pause");
	return 0;
}




