# FFT Example

This is a small program in C that demonstrates the FFT algorithm. It's been taken from my iOS application Instrument Tuner.
This implementation was written about 2 years ago and as you can probably tell it's not very efficient. The Cooley-Tukey FFT can be performed in place but this implementation doesn't for sake of readability.

The example program runs a test on the input (1, 0, 1, 0) and should output (2.0, 0.0), (0.0, 0.0), (2.0, 0.0), (0.0, 0.0)
The first member of the tuple being the real part of the number and second member of the tuple being the imaginary part.
