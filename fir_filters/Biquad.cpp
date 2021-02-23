#include "Biquad.h"

Biquad::Biquad(BiquadParams inparams)
{
    mcoeffArray[a0] = inparams.a0; mcoeffArray[a1] = inparams.a1;
    mcoeffArray[a1] = inparams.b1; mcoeffArray[b2] = inparams.b2;
    mcoeffArray[c0] = inparams.c0; mcoeffArray[d0] = inparams.d0;
}

Biquad::~Biquad()
{
}

Biquad_kDirect::Biquad_kDirect(Biquad inparams):
    Biquad{inparams}
{
}

Biquad_kDirect::~Biquad_kDirect()
{
}

void Biquad_kDirect::processBuffer(double* inbuf, double* outbuf, int numsamples)
{
    for(int i=0; i < numsamples; i++)
    {
        outbuf[i] = inbuf[i] * mcoeffArray[a0] + 
            mcoeffArray[a1] * mstateArray[x_z1] +
            mcoeffArray[a2] * mstateArray[x_z2] +
            mcoeffArray[b1] * mstateArray[y_z1] +
            mcoeffArray[b2] * mstateArray[y_z2];

            mstateArray[x_z2] = mstateArray[x_z1];
            mstateArray[x_z1] = inbuf[i];

            mstateArray[y_z2] = mstateArray[y_z1];
            mstateArray[y_z1] = outbuf[i];
    }
}