//Biquad filter class
//Created by Johnny Lopez (DevelopezAudio)
//Parent class initialized with BiquadParams structure that contains
//coefficients a0 a1 a2 b1 b2 c0 d0

typedef struct biquadParams{
    double a0 = 0.0;
    double a1 = 0.0;
    double a2 = 0.0;
    double b1 = 0.0;
    double b2 = 0.0;
    double c0 = 0.0;
    double d0 = 0.0;
} BiquadParams;

class Biquad {
    public:
        Biquad(BiquadParams inparams)
        {
            mcoeffArray[a0] = inparams.a0; mcoeffArray[a1] = inparams.a1;
            mcoeffArray[a1] = inparams.b1; mcoeffArray[b2] = inparams.b2;
            mcoeffArray[c0] = inparams.c0; mcoeffArray[d0] = inparams.d0;
        }
        ~Biquad(){
        }
    private:
        BiquadParams mbiquadParams;
        enum biquadCoeff{a0, a1, a2, b1, b2, c0, d0, numCoeffs};
        enum { x_z1, x_z2, y_z1, y_z2};
        double mstateArray[4] = {0};
        double mcoeffArray[7] = {1.0};
};