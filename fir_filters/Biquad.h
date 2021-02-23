//Biquad filter class
//Created by Johnny Lopez (DevelopezAudio)
//Parent class initialized with BiquadParams structure that contains
//coefficients a0 a1 a2 b1 b2 c0 d0

//For easier access to arrays;
enum biquadCoeff{a0, a1, a2, b1, b2, c0, d0, numCoeffs};
enum { x_z1, x_z2, y_z1, y_z2};

typedef struct biquadParams{
    double a0 = 0.0;
    double a1 = 0.0;
    double a2 = 0.0;
    double b1 = 0.0;
    double b2 = 0.0;
    double c0 = 0.0;
    double d0 = 0.0;
} BiquadParams;

//Biquad base class
class Biquad {
    public:
        Biquad(BiquadParams inparams);
        ~Biquad();
    private:
        BiquadParams mbiquadParams;
    protected:
        double mstateArray[4] = {0};
        double mcoeffArray[7] = {1.0};
};

// kDirect implementation of biquad
class Biquad_kDirect : private Biquad
{
    public:
        Biquad_kDirect(Biquad inparams);
        ~Biquad_kDirect();
        void processBuffer(double* inbuf, double* outbuf, int numsamples);
    private:
};