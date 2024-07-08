#include "wav_bmp.h"
#include <stdio.h>
#include <stdlib.h>

//��wav
void wav_read(wav *obj,const char *file)
{
	FILE *af = fopen(file,"rb");
	fread((char *)obj,sizeof(char),44,af);
	obj->data = malloc(obj->SubChunk2Size);
	fread((char *)obj->data,sizeof(char),obj->SubChunk2Size,af);
	fclose(af);
}

//дwav
void wav_write(wav *obj,const char *file)
{
	FILE *af = fopen(file,"wb");
	fwrite((char *)obj,sizeof(char),44,af);
	fwrite((char *)obj->data,sizeof(char),obj->SubChunk2Size,af);
	free(obj->data);
	fclose(af);
}


//��bmp
void bmp_read(bmp *obj,const char *file)
{
	FILE *af = fopen(file,"rb");
	fread((char *)obj,sizeof(char),54,af);
	obj->data = malloc(obj->biSizeImage);
	fread((char *)obj->data,sizeof(char),obj->biSizeImage,af);
	fclose(af);
}



//дbmp
void bmp_write(bmp *obj,const char *file)
{
	FILE *af = fopen(file,"wb");
	fwrite((char *)obj,sizeof(char),54,af);
	fwrite((char *)obj->data,sizeof(char),obj->biSizeImage,af);
	free(obj->data);
	fclose(af);
}



