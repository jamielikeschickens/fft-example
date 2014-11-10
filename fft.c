#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>

complex float *splitArray(complex float *array, int offset, int size);
void fft(complex float *dataBuffer, int size);

int main(int argc, char *argv[]) {
	complex float *dataBuffer = (complex float *)malloc(4 * sizeof(complex float));
	
	dataBuffer[0] = 1.0 + 0 * I;
	dataBuffer[1] = 0.0 + 0 * I;
	dataBuffer[2] = 1.0 + 0 * I;
	dataBuffer[3] = 0.0 + 0 * I;

	fft(dataBuffer, 4);

	for (int i=0; i < 4; ++i) {
		complex float c = dataBuffer[i];		
		printf("(%f, %f\n)", crealf(c), cimagf(c));	
	}
}

void fft(complex float *dataBuffer, int size) {
	if (size != 1) {
		complex float *even = splitArray(dataBuffer, 0, size/2); // Even indices x0, x2, x4...
		complex float *odd = splitArray(dataBuffer, 1, size/2); // Odd indices x1, x3, x5...

		fft(even, size/2); // Even
		fft(odd, size/2); // Odd

		for (int k=0; k < size/2; ++k) {
			complex float t = even[k];
			dataBuffer[k] = t + cexp(-2 * M_PI * I * k/size) * odd[k];
			dataBuffer[k+(size/2)] = t - cexp(-2 * M_PI * I * k/size) * odd[k];
		}

		// Free memory allocated by even and odd splitArray calls
		free(even);
		free(odd);
	}
}
			
complex float *splitArray(complex float *array, int offset, int size) {
    complex float *newArray = malloc(size * sizeof(complex float));
    int count = offset;
    for (int i=0; i < size; ++i) {
	        newArray[i] = array[count];
	        count += 2;
	    }
    return newArray;
}
