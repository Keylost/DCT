#include <stdio.h>
#include <math.h>
#include <stdint.h>

const double inv16 = 1.0 / 16.0;
double cosine[8*8];

void dct_8x8(uint8_t *src, int16_t *dst, size_t srcStride, size_t dstStride);
double alpha(int i);

int main()
{
	for (int i = 0; i < 8; i++)
	{
		 for (int j = 0; j < 8; j++)
		 {
			 cosine[j*8+i] = cos(3.1415 * j * (2.0 * i + 1) * inv16);
		 }
	}
	
	uint8_t src[8*8];
	int16_t dst[8*8];
	
	for(int i=0;i<64;i++) src[i] = 99;
	
	dct_8x8(src, dst, 8, 8);
	
	for(int i=0;i<64;i++)
	{
		printf("%d ", dst[i]);
	}
	printf("\n");
	
	return 0;
}

void dct_8x8(uint8_t *src, int16_t *dst, size_t srcStride, size_t dstStride)
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			dst[y * 8 + x] = 0;
			double tmp = 0;
			for (int u = 0; u < 8; u++)
				for (int v = 0; v < 8; v++)
					tmp += alpha(u) * alpha(v) * src[u*8+v] * cos((2*u+1) //cosine[u*8+x] * cosine[v*8+y];
			dst[y * 8 + x] = (int16_t)tmp;
		}
	}
	
	return;
}

double alpha(int i)
{
    if (i == 0)
        return 0.353553391; //sqrt(1/8)
    return 0.5;
}

//void inv;
